#include "Arduino.h"

#ifdef ESP8266
extern "C" {
  #include "user_interface.h"
}
#endif

#include "data.h"
#include "config.h"

#define ENABLE_WIFI
//#define ENABLE_STEER
#define ENABLE_MPU

#define LOOP_TIME (100) // ms

void setup()
{
  delay(1000);
  Serial.begin(115200);

  #if defined(ENABLE_STEER)
  steer_setup();
  #endif

  // ENABLE_MPU
  //

  #if defined(ENABLE_MPU)

  mpu_setup();

  #endif // ENABLE_MPU

  // ENABLE_WIFI
  //

  #if defined(ENABLE_WIFI)

  wifi_setup();

  #endif //ENABLE_WIFI


  // ENABLE_STEER
  //

  #if defined(ENABLE_STEER)

  steer_setup();

  #endif // ENABLE_STEER
}

uint32_t lastTime =0;

void loop()
{

  if(system_get_time()-lastTime >=(LOOP_TIME*1000))
  {
    lastTime = system_get_time();
    // ENABLE_MPU
    //

    #if defined(ENABLE_MPU)

    sMPURATA_t mpudata;
    mpu_loop(&mpudata);
    mpudata.timestamp = system_get_time()/1000;

    Serial.print("AcX = "); Serial.print(mpudata.AcX);
    Serial.print(" | AcY = "); Serial.print(mpudata.AcY);
    Serial.print(" | AcZ = "); Serial.print(mpudata.AcZ);
    Serial.print(" | Tmp = "); Serial.print(mpudata.Tmp/340.00+36.53); //equation for temperature in degrees C from datasheet
    Serial.print(" | GyX = "); Serial.print(mpudata.GyX);
    Serial.print(" | GyY = "); Serial.print(mpudata.GyY);
    Serial.print(" | GyZ = "); Serial.println(mpudata.GyZ);

    #endif // ENABLE_MPU

    // ENABLE_WIFI
    //

    #if defined(ENABLE_WIFI)

    wifi_loop(&mpudata);

    #endif // ENABLE_WIFI


    #if defined(ENABLE_STEER)

    steer_loop();

    #endif  // ENABLE_STEER


    //delay(250);
  }

}


// void mpu_calc(sMPURATA_t _mpudata)
// {
//   // Convert gyro values to degrees/sec
//   float FS_SEL = 131;
//   /*
//     float gyro_x = (accel_t_gyro.value.x_gyro - base_x_gyro)/FS_SEL;
//     float gyro_y = (accel_t_gyro.value.y_gyro - base_y_gyro)/FS_SEL;
//     float gyro_z = (accel_t_gyro.value.z_gyro - base_z_gyro)/FS_SEL;
//   */
//   float gyro_x = (accel_t_gyro.value.x_gyro - base_x_gyro) / FS_SEL;
//   float gyro_y = (accel_t_gyro.value.y_gyro - base_y_gyro) / FS_SEL;
//   float gyro_z = (accel_t_gyro.value.z_gyro - base_z_gyro) / FS_SEL;
//
//
//   // Get raw acceleration values
//   //float G_CONVERT = 16384;
//   float accel_x = accel_t_gyro.value.x_accel;
//   float accel_y = accel_t_gyro.value.y_accel;
//   float accel_z = accel_t_gyro.value.z_accel;
//
//   // Get angle values from accelerometer
//   float RADIANS_TO_DEGREES = 180 / 3.14159;
//   //  float accel_vector_length = sqrt(pow(accel_x,2) + pow(accel_y,2) + pow(accel_z,2));
//   float accel_angle_y = atan(-1 * accel_x / sqrt(pow(accel_y, 2) + pow(accel_z, 2))) * RADIANS_TO_DEGREES;
//   float accel_angle_x = atan(accel_y / sqrt(pow(accel_x, 2) + pow(accel_z, 2))) * RADIANS_TO_DEGREES;
//
//   float accel_angle_z = 0;
//
//   // Compute the (filtered) gyro angles
//   float dt = (t_now - get_last_time()) / 1000.0;
//   float gyro_angle_x = gyro_x * dt + get_last_x_angle();
//   float gyro_angle_y = gyro_y * dt + get_last_y_angle();
//   float gyro_angle_z = gyro_z * dt + get_last_z_angle();
//
//   // Compute the drifting gyro angles
//   float unfiltered_gyro_angle_x = gyro_x * dt + get_last_gyro_x_angle();
//   float unfiltered_gyro_angle_y = gyro_y * dt + get_last_gyro_y_angle();
//   float unfiltered_gyro_angle_z = gyro_z * dt + get_last_gyro_z_angle();
//
//   // Apply the complementary filter to figure out the change in angle - choice of alpha is
//   // estimated now.  Alpha depends on the sampling rate...
//   float alpha = 0.96;
//   float angle_x = alpha * gyro_angle_x + (1.0 - alpha) * accel_angle_x;
//   float angle_y = alpha * gyro_angle_y + (1.0 - alpha) * accel_angle_y;
//   float angle_z = gyro_angle_z;  //Accelerometer doesn't give z-angle
//
//   // Update the saved data with the latest values
//   set_last_read_angle_data(t_now, angle_x, angle_y, angle_z, unfiltered_gyro_angle_x, unfiltered_gyro_angle_y, unfiltered_gyro_angle_z);
//
//
// }
