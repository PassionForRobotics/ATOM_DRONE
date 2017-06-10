
#include<Wire.h>
#include "data.h"

#ifdef ESP8266
extern "C" {
  #include "user_interface.h"
}
#endif

const int MPU_addr=0x68; // I2C address of the MPU-6050
static sMPUDATA_t baseMPUData;

void mpu_setup()
{
  Wire.begin();
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
float mpu_calc(sMPUDATA_t *_mpudata)
{
  static sMPUDATA_f_t lastmpudata;
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
  //  float accel_vector_length = sqrt(pow(accel_x,2) + pow(accel_y,2) + pow(accel_z,2));
  float accel_angle_y = atan(-1 * accel_x / sqrt(pow(accel_y, 2) + pow(accel_z, 2))) * RADIANS_TO_DEGREES;
  float accel_angle_x = atan(accel_y / sqrt(pow(accel_x, 2) + pow(accel_z, 2))) * RADIANS_TO_DEGREES;
  //float accel_angle_z = 0;

  // Compute the (filtered) gyro angles
  float dt = 0;

  if(true==firstDt)
  {
    dt = LOOP_TIME/1000.0; // second
    firstDt = false;
  }
  else
  {
    dt = (_mpudata->timestamp - lastmpudata.timestamp) / 1000.0; // second
  }

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

  float tau = 0.99; // second

  float alpha = tau/(tau+(dt));//0.923 ;//0.96-> 0.8 deg/sec gyro drift;
  lastmpudata.AcX = alpha * gyro_angle_x + (1.0 - alpha) * accel_angle_x;
  lastmpudata.AcY = alpha * gyro_angle_y + (1.0 - alpha) * accel_angle_y;
  lastmpudata.AcZ = gyro_angle_z;  //Accelerometer doesn't give z-angle

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
  //set_last_read_angle_data(t_now, angle_x, angle_y, angle_z, unfiltered_gyro_angle_x, unfiltered_gyro_angle_y, unfiltered_gyro_angle_z);


}
