
#ifndef DATA_H
#define DATA_H


#if ((__GNUC__ * 100) + __GNUC_MINOR__) >= 402
#define GCC_DIAG_STR(s) #s
#define GCC_DIAG_JOINSTR(x,y) GCC_DIAG_STR(x ## y)
# define GCC_DIAG_DO_PRAGMA(x) _Pragma (#x)
# define GCC_DIAG_PRAGMA(x) GCC_DIAG_DO_PRAGMA(GCC diagnostic x)
# if ((__GNUC__ * 100) + __GNUC_MINOR__) >= 406
#  define GCC_DIAG_OFF(x) GCC_DIAG_PRAGMA(push) \
	GCC_DIAG_PRAGMA(ignored GCC_DIAG_JOINSTR(-W,x))
#  define GCC_DIAG_ON(x) GCC_DIAG_PRAGMA(pop)
# else
#  define GCC_DIAG_OFF(x) GCC_DIAG_PRAGMA(ignored GCC_DIAG_JOINSTR(-W,x))
#  define GCC_DIAG_ON(x)  GCC_DIAG_PRAGMA(warning GCC_DIAG_JOINSTR(-W,x))
# endif
#else
# define GCC_DIAG_OFF(x)
# define GCC_DIAG_ON(x)
#endif

//#include </home/rahuldeo/.platformio/lib/PID_ID2/PID_v1.h>
//#include </home/rahuldeo/.platformio/lib/PID-AutoTune_ID3/PID_AutoTune_v0.h>

#include "Arduino.h"

//#pragma GCC diagnostic push
// //#pragma GCC diagnostic warning "-Wsign-compare"
//#pragma GCC diagnostic ignored "-Wsign-compare"
// #pragma GCC diagnostic ignored "-Wunused-variable"
//#pragma GCC diagnostic ignored "-Wall"
//#pragma GCC diagnostic ignored "-Wsign-compare"
GCC_DIAG_OFF(unused-function)
//GCC_DIAG_OFF(parentheses)
//GCC_DIAG_OFF(unused-variable)
GCC_DIAG_OFF(sign-compare)

//#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Wpedantic"
//#pragma GCC diagnostic push


//# pragma GCC system_header
#   include <PID_v1.h>

# pragma GCC system_header
#   include <PID_AutoTune_v0.h>


GCC_DIAG_ON(sign-compare)
GCC_DIAG_ON(unused-function)
//GCC_DIAG_ON(parentheses)
//GCC_DIAG_ON(unused-variable)

//#pragma GCC diagnostic pop // ignored "-Wpedantic"
// #pragma GCC diagnostic pop //ignored "-Wsign-compare"
// #pragma GCC diagnostic pop //ignored "-Wunused-variable"
//#pragma GCC diagnostic pop //ignored "-Werror"
//#pragma GCC diagnostic pop

#include "data2.h"

#define STR(x) #x
#define XSTR(x) STR(x)

#define _VER_ XSTR(VER)

#define LOOP_TIME (400) // 400 uS// ms 126.58228ms
#define STEER_LOOP_TIME (10000) // 10ms (1000) // 1 ms
#define QUATERNION_BASED_CALC // euler or quat based

#define _DEGREES(x) (57.29578 * x)

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
      pidparams->Input = all_data->pitch+90.0; // degrees //analogRead(0);
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
