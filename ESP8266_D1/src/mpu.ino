
#include<Wire.h>
#include "data.h"

#ifdef ESP8266
extern "C" {
  #include "user_interface.h"
}
#endif

#if defined(QUATERNION_BASED_CALC)
#include <MPU6050.h>
#include <Math3D.h>

MPU6050 MPU(400, 6, 3, 3); // update rate, filtering, gyro, accel

Quat AttitudeEstimateQuat;

Vec3 correction_Body, correction_World;
Vec3 Accel_Body, Accel_World;
Vec3 GyroVec;

const Vec3 VERTICAL = Vector(0.0f, 0.0f, 1.0f);  // vertical vector in the World frame

#endif // QUATERNION_BASED_CALC

const int MPU_addr=0x68; // I2C address of the MPU-6050
static sMPUDATA_t baseMPUData;

void mpu_setup()
{


  #if !defined(QUATERNION_BASED_CALC)

  Wire.begin();
  //Wire.setClock(400000UL);// set speed to 400k
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B); // PWR_MGMT_1 registerESP.wdtFeed()
  Wire.write(0); // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);


  // Get mpu offsets
  //
  //
  // //
  sMPUDATA_t _mpudata ;
  uint32_t lastTime =0;
  int duration = 0;
  const int nOfSampels = 10;
  for(int i = 0 ; i < nOfSampels ;)
  {
    ESP.wdtFeed();
    duration = system_get_time()-lastTime;
    if(duration >= (10000)) // 10 ms
    {
      i++;

      lastTime = system_get_time();
      mpu_loop(&_mpudata);

      baseMPUData -= baseMPUData / nOfSampels;
      //Serial.printf("avg- | "); printMPU(&baseMPUData);
      //Serial.printf("data | "); printMPU(&_mpudata);
      baseMPUData += _mpudata / nOfSampels;
      //Serial.printf("avg+ | "); printMPU(&baseMPUData);
    }
  }

  Serial.printf("Offsets | "); printMPU(&baseMPUData);

  #elif defined(QUATERNION_BASED_CALC)

  Wire.begin();
  Wire.setClock(400000UL);// set speed to 400k

  MPU.initialize();
  Serial.println(MPU.samplePeriod);
  MPU.accelZero();  // generate and store accel bias offsets
  MPU.gyroZero();	  // generate and store gyro bias offsets

  #endif //QUATERNION_BASED_CALC

}


void mpu_loop(sMPUDATA_t *mpudata)
{

  int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true); // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY=Wire.read()<<8|Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  mpudata->timestamp = system_get_time()/1000; // in ms
  mpudata->AcX = AcX;
  mpudata->AcY = AcY;
  mpudata->AcZ = AcZ;
  mpudata->Tmp = Tmp;
  mpudata->GyX = GyX;
  mpudata->GyY = GyY;
  mpudata->GyZ = GyZ;

}

void printMPU(sMPUDATA_t *mpudata)
{
  Serial.print("dTs = "); Serial.print(mpudata->timestamp);
  Serial.print(" | AcX = "); Serial.print(mpudata->AcX);
  Serial.print(" | AcY = "); Serial.print(mpudata->AcY);
  Serial.print(" | AcZ = "); Serial.print(mpudata->AcZ);
  Serial.print(" | Tmp = "); Serial.print(mpudata->Tmp/340.00+36.53); //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(mpudata->GyX);
  Serial.print(" | GyY = "); Serial.print(mpudata->GyY);
  Serial.print(" | GyZ = "); Serial.println(mpudata->GyZ);
}

// void mpu_calc()
// {
//
// }

boolean firstDt = true;
Vec3 mpu_calc(sMPUDATA_t *_mpudata)
{
  static sMPUDATA_f_t lastmpudata;
  float dt = 0;

  if(true==firstDt)
  {
    dt = LOOP_TIME/1000.0/1000.0; // second
    firstDt = false;
  }
  else
  {
    dt = (system_get_time()/1000 - lastmpudata.timestamp) / 1000.0; // second
  }

  #if defined(QUATERNION_BASED_CALC)
  MPU.retrieve();	   // get data from the sensor
  MPU.timestamp = system_get_time()/1000;

  GyroVec  = Vector(MPU.gX, MPU.gY, MPU.gZ);	// move gyro data to vector structure
  Accel_Body = Vector(MPU.aX, MPU.aY, MPU.aZ);	// move accel data to vector structure

  Accel_World = Rotate(AttitudeEstimateQuat, Accel_Body); // rotate accel from body frame to world frame

  correction_World = CrossProd(Accel_World, VERTICAL); // cross product to determine error

  Vec3 correction_Body = Rotate(correction_World, AttitudeEstimateQuat); // rotate correction vector to body frame

  GyroVec = Sum(GyroVec, correction_Body);  // add correction vector to gyro data

  Quat incrementalRotation = Quaternion(GyroVec, MPU.samplePeriod);  // create incremental rotation quat

  AttitudeEstimateQuat = Mul(incrementalRotation, AttitudeEstimateQuat);  // quaternion integration (rotation composting through multiplication)

  Vec3 YPR = YawPitchRoll(AttitudeEstimateQuat);

  _mpudata->timestamp = MPU.timestamp;
  _mpudata->AcX = _DEGREES(-YPR.y) ; // not z
  _mpudata->AcY = _DEGREES(-YPR.z) ;
  _mpudata->AcZ = _DEGREES(-YPR.x) ;
  _mpudata->Tmp = MPU.tempRaw;//.temp_C();
  _mpudata->GyX = _DEGREES(GyroVec.x) ;
  _mpudata->GyY = _DEGREES(GyroVec.y) ;
  _mpudata->GyZ = _DEGREES(GyroVec.z);

  lastmpudata.timestamp = _mpudata->timestamp;

  return YPR;
  //lastmpudata = *_mpudata;

		// Serial.print("  Yaw:");   Serial.print(_DEGREES(-YPR.x), 2);
		// Serial.print("  Pitch:"); Serial.print(_DEGREES(-YPR.y), 2);
		// Serial.print("  Roll:");Serial.println(_DEGREES(-YPR.z), 2);

  #elif !defined(QUATERNION_BASED_CALC)
  // Convert gyro values to degrees/sec
  float FS_SEL = 131;

  float gyro_x = (_mpudata->GyX - baseMPUData.GyX) / FS_SEL;
  float gyro_y = (_mpudata->GyY - baseMPUData.GyY) / FS_SEL;
  float gyro_z = (_mpudata->GyZ - baseMPUData.GyZ) / FS_SEL;

  // Get raw acceleration values
  //float G_CONVERT = 16384;
  float accel_x = _mpudata->AcX;
  float accel_y = _mpudata->AcY;
  float accel_z = _mpudata->AcZ;

  // Get angle values from accelerometer
  float RADIANS_TO_DEGREES = 180 / 3.14159;

  float accel_vector_length = sqrt(pow(accel_x,2) + pow(accel_y,2) + pow(accel_z,2));
  float accel_angle_y = atan(-1 * accel_x / accel_vector_length) * RADIANS_TO_DEGREES;
  float accel_angle_x = atan(accel_y / accel_vector_length) * RADIANS_TO_DEGREES;
  float accel_angle_z = atan(accel_z / accel_vector_length) * RADIANS_TO_DEGREES;

  //float accel_angle_y = atan2((-1 * accel_x)*RADIANS_TO_DEGREES, (sqrt(pow(accel_y, 2) + pow(accel_z, 2))*RADIANS_TO_DEGREES));
  //float accel_angle_x = atan2(accel_y*RADIANS_TO_DEGREES , sqrt(pow(accel_x, 2) + pow(accel_z, 2))) * RADIANS_TO_DEGREES;

  // Compute the (filtered) gyro angles




  float gyro_angle_x = gyro_x * dt + lastmpudata.AcX; // filtered
  float gyro_angle_y = gyro_y * dt + lastmpudata.AcY;
  float gyro_angle_z = gyro_z * dt + lastmpudata.AcZ;

  // Compute the drifting gyro angles
  lastmpudata.GyX = gyro_x * dt + lastmpudata.GyX; // unfiltered
  lastmpudata.GyY = gyro_y * dt + lastmpudata.GyY;
  lastmpudata.GyZ = gyro_z * dt + lastmpudata.GyZ;

  // Apply the complementary filter to figure out the change in angle - choice of alpha is
  // estimated now.  Alpha depends on the sampling rate...

  // tau => alpha for gyro drift ~ 0.8 deg/sec
  // 0.75sec => 0.96-> 0.8 deg/sec gyro drift;
  // 1.2sec => very baseMPUData//

  float tau = 0.9; // second

  float alpha = tau/(tau+(dt));//0.923 ;//0.96-> 0.8 deg/sec gyro drift;
  lastmpudata.AcX = alpha * gyro_angle_x + (1.0 - alpha) * accel_angle_x;
  lastmpudata.AcY = alpha * gyro_angle_y + (1.0 - alpha) * accel_angle_y;
  lastmpudata.AcZ = alpha * gyro_angle_z + (1.0 - alpha) * accel_angle_z; //gyro_angle_z;  //Accelerometer doesn't give z-angle

  // Update the saved data with the latest values
  lastmpudata.timestamp = _mpudata->timestamp;
  _mpudata->AcX = lastmpudata.AcX; // filtered angles X
  _mpudata->AcY = lastmpudata.AcY; // filtered angles X
  _mpudata->AcZ = lastmpudata.AcZ; // filtered angles X
  _mpudata->Tmp = lastmpudata.Tmp; // Tmp
  _mpudata->GyX = lastmpudata.GyX; // unfiltered angles X
  _mpudata->GyY = lastmpudata.GyY; // unfiltered angles Y
  _mpudata->GyZ = lastmpudata.GyZ; // unfiltered angles Z

  return dt;

  #endif // QUATERNION_BASED_CALC


  //set_last_read_angle_data(t_now, angle_x, angle_y, angle_z, unfiltered_gyro_angle_x, unfiltered_gyro_angle_y, unfiltered_gyro_angle_z);


}
