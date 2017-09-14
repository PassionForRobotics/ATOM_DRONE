#include "Arduino.h"
//#include "MPU6050.h"
#include "NewPingESP8266.h"
#include "Servo.h"
#include "helper_3dmath.h"

//#include <Math3D.h>

#ifdef ESP8266
extern "C" {
  #include "user_interface.h"
}
#endif

#include "profiler.h"



#include "data.h"
#include "config.h"



#define ENABLE_WIFI
#define ENABLE_STEER
#define ENABLE_MPU

#define LOOP_PROFILER_ON

#if defined(LOOP_PROFILER_ON)
//#define PRINT_LOOP_PROFILER_ON
#endif //LOOP_PROFILER_ON


#if defined(ENABLE_WIFI)
#define ENABLE_OTA_WIFI
#endif //ENABLE_WIFI

#if defined(ENABLE_MPU)

#define MPU_PROFILER_ON

#if defined(MPU_PROFILER_ON)
//#define PRINT_MPU_PROFILER_ON
#endif //MPU_PROFILER_ON

#endif //ENABLE_MPU

#if defined(ENABLE_WIFI)

#define WIFI_PROFILER_ON

#if defined(WIFI_PROFILER_ON)
//#define PRINT_WIFI_PROFILER_ON
#endif //WIFI_PROFILER_ON

#endif //ENABLE_WIFI


Profiler_data profiled_loop, profiled_mpu, profiled_wifi, profiled_steer;

Profiler wholeLoopProfiler;

#if defined(MPU_PROFILER_ON)
Profiler mpuLoopProfiler;
#endif //MPU_PROFILER_ON


#if defined(WIFI_PROFILER_ON)
Profiler wifiLoopProfiler;
#endif //WIFI_PROFILER_ON


void setup()
{

  delay(2000);
  Serial.begin(115200);

  uint16_t overheartick = wholeLoopProfiler.Calibrate();

  #if defined(MPU_PROFILER_ON)
  mpuLoopProfiler.SetOverHead(overheartick);
  #endif //MPU_PROFILER_ON

  #if defined(WIFI_PROFILER_ON)
  wifiLoopProfiler.SetOverHead(overheartick);
  #endif //WIFI_PROFILER_ON

  Serial.printf("Version %s\n", _VER_);
  Serial.printf("Build at %s %s\n", __DATE__, __TIME__);
  Serial.printf("size of mpudata %d\n", SIZE_OF_MPU_DATA);
  Serial.printf("size of all data %d\n", SIZE_OF_ALL_DATA);

  // ENABLE_MPU
  //

  #if defined(ENABLE_MPU)

  mpu_setup();

  #endif // ENABLE_MPU

  // ENABLE_WIFI
  //

  #if defined(ENABLE_WIFI)

  wifi_setup();

  #if defined(ENABLE_OTA_WIFI)
  setup_OTA();
  #endif // ENABLE_OTA_WIFI


  #endif //ENABLE_WIFI



  // ENABLE_STEER
  //

  #if defined(ENABLE_STEER)

  steer_setup();

  #endif // ENABLE_STEER


  Serial.printf("All setup.\n" );

}

uint32_t lastWIFITime = 0, lastLoopTime =0 , lastPrintTime = 0, lastPerfTime = 0;

sGENERICSETPOINTS_t msetpts;

//uint32_t cycle = 0;
//uint128_t cycleAvg = 0;


void loop()
{
  // static uint16_t cyCount = 0;
  // static uint32_t cycle = 0, lastCycle = 0;;//ESP.getCycleCount();
  // static uint32_t cycleSum = 0;//cycle;
  // uint32_t cycleDiff = 0;
  //
  // lastCycle = cycle;
  // cycle = ESP.getCycleCount();
  // //cycleSum += cycle;
  // cyCount++;
  //
  // cycleDiff = (cycle - lastCycle);

  //cycleSum += cycleDiff;

  //wholeLoopProfiler.Update();
  wholeLoopProfiler.Start(); // Can check if beyond loop anything is going on
  //Serial.printf("Cy: %d, %d, %d, %d \n", cycleDiff, cycleSum, cyCount, (cycleSum/cyCount));
  uint32_t profLoopTs = system_get_time();
  int _mpustatus=0;

  boolean data_received = false;

  #if defined(ENABLE_WIFI)

  #if defined(ENABLE_OTA_WIFI)

  // #if defined(WIFI_PROFILER_ON)
  // wifiLoopProfiler.Start();
  // #endif //WIFI_PROFILER_ON


  if(true == loop_OTA())
  return; // skip all activity // or try how this works with this

  // #if defined(WIFI_PROFILER_ON)
  // wifiLoopProfiler.Pause();
  // #endif //WIFI_PROFILER_ON

  #endif // ENABLE_OTA_WIFI

  #endif // ENABLE_WIFI


  //if(system_get_time()-lastLoopTime >=(LOOP_TIME))
  {
    lastLoopTime = system_get_time();
    // ENABLE_MPU
    //

    #if defined(ENABLE_MPU)

    sMPUDATA_t mpudata ;
    sSmoothData_t sdata;
    static debug_data debug_data;
    sMPUDATA_t rawmpudata;

    VectorFloat YPR;
    int isMpuDataValid = 0;
    uint32_t profMpuTs = system_get_time();

    #if defined(MPU_PROFILER_ON)
    mpuLoopProfiler.Start();
    #endif //MPU_PROFILER_ON

    isMpuDataValid = mpudmp_loop(&rawmpudata, &YPR, &_mpustatus);
    profMpuTs = system_get_time() - profMpuTs;

    //mpuLoopProfiler.Update();
    #if defined(MPU_PROFILER_ON)
    mpuLoopProfiler.Pause();
    #endif //MPU_PROFILER_ON

    //mpu_filter(&mpudata, &sdata);

    if(system_get_time()-lastWIFITime >=(10*1000))
    {
      lastWIFITime = system_get_time();

      debug_data.timestamp = millis();
      debug_data.yaw = YPR.x;
      debug_data.pitch = YPR.y;
      debug_data.roll = YPR.z;
      debug_data.pingheight = ping_loop();
      //debug_data.mpuData = mpudata;
      debug_data.mpuRAW = rawmpudata;
      //debug_data.pplr =


      // ENABLE_WIFI
      //


      #if defined(ENABLE_WIFI)

      uint32_t profWifiTs = 0;

      #if defined(WIFI_PROFILER_ON)
      wifiLoopProfiler.Start();

      profWifiTs = system_get_time();

      #endif //WIFI_PROFILER_ON

      //if(system_get_time()-lastLoopTime >=(LOOP_TIME))
      //{
      data_received = wifi_loop(&debug_data, &msetpts);

      debug_data.tune_type = msetpts.pid_tune_type;
      //}

      #if defined(WIFI_PROFILER_ON)
      profWifiTs = system_get_time() - profWifiTs;

      wifiLoopProfiler.Pause();
      #endif //WIFI_PROFILER_ON


      #endif // ENABLE_WIFI
    }
    //else
    //{
    //data_received = false;
    //}

    #if defined(ENABLE_STEER)

    //if(true == data_received)
    //{
    //  if( (msetpts.x != 0) && (msetpts.y != 0) )

    // Without this empty line esp is crashing ????
    Serial.print("");//check "); Serial.println(__LINE__); // Without this empty line esp is crashing ????
    steer_loop(&debug_data, &msetpts); // should be sent on next loop over wifi
    //}
    // Without this empty line esp is crashing ????
    Serial.print("");//check "); Serial.println(__LINE__) // Without this empty line esp is crashing ????;

    #endif  // ENABLE_STEER

    if(system_get_time()-lastPerfTime >=(100*1000)) // It must be a sec for profiling
    {
      lastPerfTime = system_get_time();

      wholeLoopProfiler.Pause();

      wholeLoopProfiler.CalculateAverageTicks();

      #if defined(MPU_PROFILER_ON)
      mpuLoopProfiler.CalculateAverageTicks();
      #endif //MPU_PROFILER_ON

      #if defined(WIFI_PROFILER_ON)
      wifiLoopProfiler.CalculateAverageTicks();
      #endif //WIFI_PROFILER_ON

      // #if defined(PRINT_LOOP_PROFILER_ON)
      // Serial.printf("L:%d,%d|[", wholeLoopProfiler.getLastIterationCount(), wholeLoopProfiler.getAverageTicks());// (cycleSum/cyCount));
      // Serial.print(wholeLoopProfiler.getAverageMicros());
      // Serial.printf(" ");
      // Serial.print(wholeLoopProfiler.getAverageMicros2());
      // Serial.printf(" %d]uS | ", system_get_time() - profLoopTs);
      // #endif // PRINT_LOOP_PROFILER_ON

      profiled_loop.ts = millis();
      profiled_loop.averageIterationCount = wholeLoopProfiler.getLastIterationCount();
      profiled_loop.averageTick = wholeLoopProfiler.getAverageTicks();
      profiled_loop.averageTime = wholeLoopProfiler.getAverageMicros();
      profiled_loop.averageTime2 = wholeLoopProfiler.getAverageMicros2();

      debug_data.profiled_loop = profiled_loop;

      #if defined(MPU_PROFILER_ON)
      // #if defined(PRINT_MPU_PROFILER_ON)
      // Serial.printf("M:%d,%d|[", mpuLoopProfiler.getLastIterationCount(), mpuLoopProfiler.getAverageTicks());// (cycleSum/cyCount));
      // Serial.print(mpuLoopProfiler.getAverageMicros());
      // Serial.printf(" ");
      // Serial.print(mpuLoopProfiler.getAverageMicros2());
      // Serial.printf(" %d]uS | ", profMpuTs);
      // #endif //PRINT_MPU_PROFILER_ON

      profiled_mpu.ts = millis();
      profiled_mpu.averageIterationCount = mpuLoopProfiler.getLastIterationCount();
      profiled_mpu.averageTick = mpuLoopProfiler.getAverageTicks();
      profiled_mpu.averageTime = mpuLoopProfiler.getAverageMicros();
      profiled_mpu.averageTime2 = mpuLoopProfiler.getAverageMicros2();

      debug_data.profiled_mpu = profiled_mpu;

      #endif //MPU_PROFILER_ON

      #if defined(WIFI_PROFILER_ON)
      // #if defined(PRINT_WIFI_PROFILER_ON)
      // Serial.printf("W:%d,%d|[", wifiLoopProfiler.getLastIterationCount(), wifiLoopProfiler.getAverageTicks());// (cycleSum/cyCount));
      // Serial.print(wifiLoopProfiler.getAverageMicros());
      // Serial.printf(" ");
      // Serial.print(wifiLoopProfiler.getAverageMicros2());
      // Serial.printf(" %d]uS | ", profWifiTs);
      //#endif //PRINT_WIFI_PROFILER_ON

      profiled_wifi.ts = millis();
      profiled_wifi.averageIterationCount = wifiLoopProfiler.getLastIterationCount();
      profiled_wifi.averageTick = wifiLoopProfiler.getAverageTicks();
      profiled_wifi.averageTime = wifiLoopProfiler.getAverageMicros();
      profiled_wifi.averageTime2 = wifiLoopProfiler.getAverageMicros2();

      debug_data.profiled_wifi = profiled_wifi;

      #endif //WIFI_PROFILER_ON
      //
      // Serial.printf("YPR|%d|%d|", system_get_time()/1000, isMpuDataValid);
      // Serial.print((YPR.x));
      // Serial.printf(" ");
      // Serial.print((YPR.y));
      // Serial.printf(" ");
      // Serial.print((YPR.z));
      // Serial.printf(" | 0x%X\n",_mpustatus);

      //wholeLoopProfiler.Pause();
      wholeLoopProfiler.ReinitCounters();

      #if defined(MPU_PROFILER_ON)
      mpuLoopProfiler.ReinitCounters();
      #endif //MPU_PROFILER_ON

      #if defined(WIFI_PROFILER_ON)
      wifiLoopProfiler.ReinitCounters();
      #endif //WIFI_PROFILER_ON
    }

    if(system_get_time()-lastPrintTime >=(1000*1000)) // It must be a sec for profiling
    {
      //Serial.print("RAW | "); printMPU(&rawmpudata);

      lastPrintTime = system_get_time();
      //if(data_received)
      //{
        //printgmpts(&msetpts);
        //printMPU(&debug_data.mpuRAW);
        //printMPU(&rawmpudata);

      //}
      //else
      //{
        //Serial.println("[ WARN] [.] Probable connection loss.");
      //}


      //Serial.print("PRO | "); Serial.printf("png %lu cms | %d ", ping_loop(), msetpts.hat) ; //Serial.printf("dt %d uS ", (int)(dt));
      //Serial.printf("| %d %d | %d %d %d\n", msetpts.x, msetpts.y, mpudata.AcX, mpudata.AcY, mpudata.AcZ);



      //Serial.printf("Cy: ");
      //Serial.print( (float)(cycleSum/cyCount) );

      //uint32_t cycleT = ESP.getCycleCount();
      // wholeLoopProfiler.Pause();
      //
      // wholeLoopProfiler.CalculateAverageTicks();
      //
      // #if defined(MPU_PROFILER_ON)
      // mpuLoopProfiler.CalculateAverageTicks();
      // #endif //MPU_PROFILER_ON
      //
      // #if defined(WIFI_PROFILER_ON)
      // wifiLoopProfiler.CalculateAverageTicks();
      // #endif //WIFI_PROFILER_ON

      #if defined(PRINT_LOOP_PROFILER_ON)
      Serial.printf("L:%d,%d|[", wholeLoopProfiler.getLastIterationCount(), wholeLoopProfiler.getAverageTicks());// (cycleSum/cyCount));
      Serial.print(wholeLoopProfiler.getAverageMicros());
      Serial.printf(" ");
      Serial.print(wholeLoopProfiler.getAverageMicros2());
      Serial.printf(" %d]uS | ", system_get_time() - profLoopTs);
      #endif // PRINT_LOOP_PROFILER_ON

      // profiled_loop.ts = millis();
      // profiled_loop.averageIterationCount = wholeLoopProfiler.getLastIterationCount();
      // profiled_loop.averageTick = wholeLoopProfiler.getAverageTicks();
      // profiled_loop.averageTime = wholeLoopProfiler.getAverageMicros();
      // profiled_loop.averageTime2 = wholeLoopProfiler.getAverageMicros2();
      //
      // debug_data.profiled_loop = profiled_loop;

      #if defined(MPU_PROFILER_ON)
      #if defined(PRINT_MPU_PROFILER_ON)
      Serial.printf("M:%d,%d|[", mpuLoopProfiler.getLastIterationCount(), mpuLoopProfiler.getAverageTicks());// (cycleSum/cyCount));
      Serial.print(mpuLoopProfiler.getAverageMicros());
      Serial.printf(" ");
      Serial.print(mpuLoopProfiler.getAverageMicros2());
      Serial.printf(" %d]uS | ", profMpuTs);
      #endif //PRINT_MPU_PROFILER_ON

      // profiled_mpu.ts = millis();
      // profiled_mpu.averageIterationCount = mpuLoopProfiler.getLastIterationCount();
      // profiled_mpu.averageTick = mpuLoopProfiler.getAverageTicks();
      // profiled_mpu.averageTime = mpuLoopProfiler.getAverageMicros();
      // profiled_mpu.averageTime2 = mpuLoopProfiler.getAverageMicros2();
      //
      // debug_data.profiled_mpu = profiled_mpu;

      #endif //MPU_PROFILER_ON

      #if defined(WIFI_PROFILER_ON)
      #if defined(PRINT_WIFI_PROFILER_ON)
      Serial.printf("W:%d,%d|[", wifiLoopProfiler.getLastIterationCount(), wifiLoopProfiler.getAverageTicks());// (cycleSum/cyCount));
      Serial.print(wifiLoopProfiler.getAverageMicros());
      Serial.printf(" ");
      Serial.print(wifiLoopProfiler.getAverageMicros2());
      Serial.printf(" %d]uS | ", profWifiTs);
      #endif //PRINT_WIFI_PROFILER_ON

      // profiled_wifi.ts = millis();
      // profiled_wifi.averageIterationCount = wifiLoopProfiler.getLastIterationCount();
      // profiled_wifi.averageTick = wifiLoopProfiler.getAverageTicks();
      // profiled_wifi.averageTime = wifiLoopProfiler.getAverageMicros();
      // profiled_wifi.averageTime2 = wifiLoopProfiler.getAverageMicros2();
      //
      // debug_data.profiled_wifi = profiled_wifi;

      #endif //WIFI_PROFILER_ON

      Serial.printf("YPR|%d|%d|", system_get_time()/1000, isMpuDataValid);
      Serial.print((YPR.x));
      Serial.printf(" ");
      Serial.print((YPR.y));
      Serial.printf(" ");
      Serial.print((YPR.z));
      Serial.printf(" | 0x%X\n",_mpustatus);

      //wholeLoopProfiler.Pause();
      // wholeLoopProfiler.ReinitCounters();
      //
      // #if defined(MPU_PROFILER_ON)
      // mpuLoopProfiler.ReinitCounters();
      // #endif //MPU_PROFILER_ON
      //
      // #if defined(WIFI_PROFILER_ON)
      // wifiLoopProfiler.ReinitCounters();
      // #endif //WIFI_PROFILER_ON
      //cycleSum = 0;
      //cyCount = 0;
      //Serial.printf("Pt; %d | ", ESP.getCycleCount()/cycleT);

      // Serial.print("PID | S:");
      // Serial.print(debug_data.pplr.Setpoint);
      // Serial.print(" I:");
      // Serial.print(debug_data.pplr.Input);
      // Serial.print(" O:");
      // Serial.println(debug_data.pplr.Output);
    }

    // Serial.print("AcX = "); Serial.print(mpudata.AcX);
    // Serial.print(" | AcY = "); Serial.print(mpudata.AcY);
    // Serial.print(" | AcZ = "); Serial.print(mpudata.AcZ);
    // Serial.print(" | Tmp = "); Serial.print(mpudata.Tmp/340.00+36.53); //equation for temperature in degrees C from datasheet
    // Serial.print(" | GyX = "); Serial.print(mpudata.GyX);
    // Serial.print(" | GyY = "); Serial.print(mpudata.GyY);
    // Serial.print(" | GyZ = "); Serial.println(mpudata.GyZ);

    #endif // ENABLE_MPU



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
