
#ifndef DATA_H
#define DATA_H

#include "Arduino.h"

#define STR(x) #x
#define XSTR(x) STR(x)

#define _VER_ XSTR(VER)

#define LOOP_TIME (400) // 400 uS// ms 126.58228ms
#define STEER_LOOP_TIME (10000) // 10ms (1000) // 1 ms
#define QUATERNION_BASED_CALC // euler or quat based

#define _DEGREES(x) (57.29578 * x)

struct sSmoothData_t
{
  int32_t X, Y, Z;
};

struct sMPUDATA_f_t
{
  uint32_t timestamp;
  float AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
};

struct sMPUDATA_t
{
  uint32_t timestamp;
  int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

  sMPUDATA_t operator+=(sMPUDATA_t d)
  {
    timestamp += (uint32_t)d.timestamp;
    AcX += (int16_t)d.AcX;
    AcY += (int16_t)d.AcY;
    AcZ += (int16_t)d.AcZ;
    GyX += (int16_t)d.GyX;
    GyY += (int16_t)d.GyY;
    GyZ += (int16_t)d.GyZ;
    return *this;
  }

  sMPUDATA_t operator-=(sMPUDATA_t d)
  {
    timestamp -= (uint32_t)d.timestamp;
    AcX -= (int16_t)d.AcX;
    AcY -= (int16_t)d.AcY;
    AcZ -= (int16_t)d.AcZ;
    GyX -= (int16_t)d.GyX;
    GyY -= (int16_t)d.GyY;
    GyZ -= (int16_t)d.GyZ;
    return *this;
  }

  // Not tested
  // sMPUDATA_t operator+( sMPUDATA_t &rhs)
  // {
  //   sMPUDATA_t lhs = *this;
  //   lhs.timestamp += (uint32_t)rhs.timestamp;
  //   lhs.AcX += (int16_t)rhs.AcX;
  //   lhs.AcY += (int16_t)rhs.AcY;
  //   lhs.AcZ += (int16_t)rhs.AcZ;
  //   lhs.GyX += (int16_t)rhs.GyX;
  //   lhs.GyY += (int16_t)rhs.GyY;
  //   lhs.GyZ += (int16_t)rhs.GyZ;
  //
  //   return lhs;
  //   //  return a.team_name < b.team_name;
  // }
  //
  // sMPUDATA_t operator-(sMPUDATA_t &rhs)
  // {
  //   sMPUDATA_t lhs = *this;
  //   lhs.timestamp -= (uint32_t)rhs.timestamp;
  //   lhs.AcX -= (int16_t)rhs.AcX;
  //   lhs.AcY -= (int16_t)rhs.AcY;
  //   lhs.AcZ -= (int16_t)rhs.AcZ;
  //   lhs.GyX -= (int16_t)rhs.GyX;
  //   lhs.GyY -= (int16_t)rhs.GyY;
  //   lhs.GyZ -= (int16_t)rhs.GyZ;
  //
  //   return lhs;
  //   //  return a.team_name < b.team_name;
  // }

  sMPUDATA_t operator/(int d)
  {
    sMPUDATA_t lhs = *this;
    lhs.timestamp /= d;
    lhs.AcX /= d;
    lhs.AcY /= d;
    lhs.AcZ /= d;
    lhs.GyX /= d;
    lhs.GyY /= d;
    lhs.GyZ /= d;

    return lhs;
  }

  //unsigned char etx;
};

#define SIZE_OF_MPU_DATA (sizeof(sMPUDATA_t))

typedef struct sMOTIONSETPOINTS_t
{
  uint32_t timestamp;
  uint16_t x;
  uint16_t y;
  uint8_t hat;
  uint8_t twist;
  //uint8_t buttons_a;
  uint8_t slider;
  uint16_t buttons;

};

#define SIZE_OF_MSETPOINTS_DATA (sizeof(sMOTIONSETPOINTS_t))


typedef struct PID_Tune_Params_t
{
  //Define Variables we'll be connecting to
  double Setpoint, Input, Output;

  //Specify the links and initial tuning parameters
  double Kp, Ki, Kd;

};
//typedef PID_Tune_Params_t PID_Tune_Params_t;

typedef struct PID_AutoTune_Params_t
{
  byte ATuneModeRemember;

  double kpmodel, taup;
  double outputStart;
  double aTuneStep, aTuneNoise, aTuneStartValue;
  unsigned int aTuneLookBack;

  boolean tuning;
  unsigned long  modelTime, serialTime;

  //set to false to connect to the real world
  boolean useSimulation;

  double theta[50];
};

enum PID_TUNE_TYPE
{
  PID_TUNE_TYPE_NONE = 0,
  PID_TUNE_TYPE_LEFT_RIGHT,
  PID_TUNE_TYPE_FORE_BACK,
  PID_TUNE_TYPE_UP_DOWN,
  PID_TUNE_TYPE_TUNING_DONE,
  PID_TUNE_TYPE_MAX = 0xff
};

typedef struct ALL_DATA
{
  PID_TUNE_TYPE tune_type;
  uint32_t timestamp;
  int yaw;
  int pitch;
  int roll;
  sMPUDATA_t mpuRAW;
  sMPUDATA_t mpuData;
  int pingheight;
  PID_Tune_Params_t pplr;
  PID_Tune_Params_t ppfb;     //
  PID_Tune_Params_t ppud; // Yaw and Ping
};

typedef ALL_DATA debug_data;

#define SIZE_OF_ALL_DATA (sizeof(ALL_DATA))

#endif // DATA_H
