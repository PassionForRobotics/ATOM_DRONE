
#ifndef DATA_H
#define DATA_H

#include "Arduino.h"


#include <PID_v1.h>
#include <PID_AutoTune_v0.h>


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

typedef sMPUDATA_t sMPUDATA_t;

#define SIZE_OF_MPU_DATA (sizeof(sMPUDATA_t))

struct sMOTIONSETPOINTS_t
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

typedef sMOTIONSETPOINTS_t sMOTIONSETPOINTS_t;

#define SIZE_OF_MSETPOINTS_DATA (sizeof(sMOTIONSETPOINTS_t))


struct PID_Tune_Params_t
{
  //Define Variables we'll be connecting to
  double Setpoint, Input, Output;

  //Specify the links and initial tuning parameters
  double Kp, Ki, Kd;

};

typedef PID_Tune_Params_t PID_Tune_Params_t;

enum PID_TUNE_TYPE
{
  PID_TUNE_TYPE_NONE = 0,
  PID_TUNE_TYPE_LEFT_RIGHT,
  PID_TUNE_TYPE_FORE_BACK,
  PID_TUNE_TYPE_UP_DOWN,
  PID_TUNE_TYPE_TUNING_DONE,
  PID_TUNE_TYPE_MAX = 0xff
};

typedef PID_TUNE_TYPE PID_TUNE_TYPE;

struct ALL_DATA
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


struct PID_AutoTune_Params_t
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


  void AutoTunersInit(PID_Tune_Params_t *pidparams, PID_ATune *PID_ATune, PID *PID)
  {
    if(useSimulation)
    {
      for(byte i=0;i<50;i++)
      {
        theta[i]=outputStart;
      }
      modelTime = 0;
    }
    //Setup the pid
    //myPID.SetMode(AUTOMATIC);


    if(tuning)
    {
      tuning=false;
      changeAutoTune(pidparams, PID_ATune, PID);
      tuning=true;
    }

    serialTime = 0;

  }

  void AutoTuneHelper(boolean start, PID *pid)
  {
    if(start)
    ATuneModeRemember = pid->GetMode();
    else
    pid->SetMode(ATuneModeRemember);
  }

  void DoModel(PID_Tune_Params_t *pidparams)
  {
    //cycle the dead time
    for(byte i=0;i<49;i++)
    {
      theta[i] = theta[i+1];
    }
    //compute the input
    pidparams->Input = (kpmodel / taup) *(theta[0] - outputStart) + pidparams->Input*(1-1/taup) + ((float)random(-10,10))/100;

  }

  // AutoPID tune modeling
  //
  void changeAutoTune(PID_Tune_Params_t *pidparams, PID_ATune *PID_ATune, PID *PID)
  {
    if(!tuning)
    {
      //Set the output to the desired starting frequency.
      pidparams->Output=aTuneStartValue;
      PID_ATune->SetNoiseBand(aTuneNoise);
      PID_ATune->SetOutputStep(aTuneStep);
      PID_ATune->SetLookbackSec((int)aTuneLookBack);
      AutoTuneHelper(true, PID);
      tuning = true;
    }
    else
    { //cancel autotune
      PID_ATune->Cancel();
      tuning = false;
      AutoTuneHelper(false, PID);
    }
  }

  void pid_loop(debug_data * all_data, PID_Tune_Params_t *pidparams, PID_ATune *PID_ATune, PID *PID)
  {
    //PID

    unsigned long now = millis();

    if(!useSimulation)
    { //pull the input in from the real world
      pidparams->Input = all_data->mpuData.AcY+90.0; // degrees //analogRead(0);
    }

    if(tuning)
    {
      byte val = (PID_ATune->Runtime());
      if (val!=0)
      {
        tuning = false;
      }
      if(!tuning)
      { //we're done, set the tuning parameters
        pidparams->Kp = PID_ATune->GetKp();
        pidparams->Ki = PID_ATune->GetKp();
        pidparams->Kd = PID_ATune->GetKd();
        PID->SetTunings(pidparams->Kp,pidparams->Ki,pidparams->Kd);
        AutoTuneHelper(true, PID);//AutoTuneHelper(false);
      }
    }
    else
    {
      // pplr.Setpoint = x1-servo_offsets[2];
      // pplr.Input = mpudata->AcY+90.0; // degree
      // PIDlr.Compute();
      // x1 = pplr.Output+servo_offsets[2];
    }

    if(useSimulation)
    {
      theta[30]=pidparams->Output;
      if(now>=modelTime)
      {
        modelTime +=100;
        DoModel(pidparams);
      }
    }
    else
    {
      //analogWrite(0,output);
    }

    //send-receive with processing if it's time
    if(millis()>serialTime)
    {
      //SerialReceive();
      //SerialSend();
      serialTime+=500;
    }
  }

};

typedef PID_AutoTune_Params_t PID_AutoTune_Params_t;

#endif // DATA_H
