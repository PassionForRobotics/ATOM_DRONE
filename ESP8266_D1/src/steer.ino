
#include <Servo.h>
#include "data.h"

#include <PID_v1.h>
PID_Tune_Params_t pplr =
{
  90.0, 90.0, 90.0,
  200.0, 30.0, 10.0
}; // pid_params_left_right

PID PIDlr(&pplr.Input, &pplr.Output, &pplr.Setpoint, pplr.Kp, pplr.Ki, pplr.Kd, DIRECT);

// AutoPID Tune
#include <PID_AutoTune_v0.h>

byte ATuneModeRemember=2;
//double input=80, output=50, setpoint=180;
//double kp=2,ki=0.5,kd=2;

double kpmodel=1.5, taup=100, theta[50];
double outputStart=5;
double aTuneStep=50, aTuneNoise=1, aTuneStartValue=100;
unsigned int aTuneLookBack=20;

boolean tuning = false;
unsigned long  modelTime, serialTime;

PID_ATune aTune(&pplr.Input, &pplr.Output);

//set to false to connect to the real world
boolean useSimulation = true;

///
///
///

Servo servo[4];  // create servo object to control a servo
int pins[4] = {D5, D6, D7, D8}; // D9 is LED
int i = 0;

// Servo mechanical offsets
const byte SERVO0_OFFSET = (7);
const byte SERVO1_OFFSET = (-1) ;//(4);
const byte SERVO2_OFFSET = (13);
const byte SERVO3_OFFSET = (-10) ;//(-5);

#define MAX_THROTTLE (2000) //(1864)
#define MIN_THROTTLE (1064)
#define ZERO_THROTTLE (0)

// twist limits
const byte SERVO_TWIST_ANGLE_LIMIT = (20);

byte servo_offsets[4] = {SERVO0_OFFSET, SERVO1_OFFSET, SERVO2_OFFSET, SERVO3_OFFSET};

Servo ESC; // D1 pin D12

#define Servo1_offset 1;

void steer_setup()
{
  randomSeed(analogRead(A0));

  ESC.attach(D0);
  ESC.write(90);

  for(i=0;i<4;i++)
  {
    servo[i].attach(pins[i]);  // attaches the servo on GIO2 to the servo object
    //servo[i].write(90+servo_offsets[i]);
  }

  byte x = map(512, 1023, 0, -45+90+servo_offsets[0], 45+90+servo_offsets[0]);
  //x += 90;
  byte y = map(512, 0, 1023, -45+90+servo_offsets[1], 45+90+servo_offsets[1]);

  byte x1 = map(512, 0, 1023, -45+90+servo_offsets[2], 45+90+servo_offsets[2]);

  byte y1 = map(512, 1023, 0, -45+90+servo_offsets[3], 45+90+servo_offsets[3]);

  servo[0].write(x);

  servo[1].write(y);

  servo[2].write(x1);

  servo[3].write(y1);


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
  PIDlr.SetOutputLimits(-45+90, 45+90); // Offsets are not taken into account for now
  PIDlr.SetMode(AUTOMATIC);

  if(tuning)
  {
    tuning=false;
    changeAutoTune();
    tuning=true;
  }

  serialTime = 0;
  //Serial.begin(9600);



}

byte angle = 35;
uint32_t lastSteerLoopTime = 0;

PID_Tune_Params_t steer_loop(sMPUDATA_t *mpudata, sMOTIONSETPOINTS_t *msetpts)
{


  //byte a = random(90-45, 90+45);

  // byte x = map(msetpts->x, 0, 1023, -45+90+servo_offsets[0], 45+90+servo_offsets[0]);
  // //x += 90;
  // byte y = map(msetpts->y, 0, 1023, -45+90+servo_offsets[1], 45+90+servo_offsets[1]);
  //
  // byte x1 = map(msetpts->x, 1023, 0, -45+90+servo_offsets[2], 45+90+servo_offsets[2]);
  //
  // byte y1 = map(msetpts->y, 1023, 0, -45+90+servo_offsets[3], 45+90+servo_offsets[3]);
  //
  // byte tw = map(msetpts->twist, 0, 255, -SERVO_TWIST_ANGLE_LIMIT, SERVO_TWIST_ANGLE_LIMIT);

  byte x = map(msetpts->x, 1023, 0, -45+90+servo_offsets[0], 45+90+servo_offsets[0]);
  //x += 90;
  byte y = map(msetpts->y, 0, 1023, -45+90+servo_offsets[1], 45+90+servo_offsets[1]);

  byte x1 = map(msetpts->x, 0, 1023, -45+90+servo_offsets[2], 45+90+servo_offsets[2]);

  byte y1 = map(msetpts->y, 1023, 0, -45+90+servo_offsets[3], 45+90+servo_offsets[3]);

  byte tw = map(msetpts->twist, 0, 255, -SERVO_TWIST_ANGLE_LIMIT, SERVO_TWIST_ANGLE_LIMIT);

  x += tw;
  x1 += tw;
  y += tw;
  y1 += tw;


  // PID
  //
  // ///

  //PID

  unsigned long now = millis();

  if(!useSimulation)
  { //pull the input in from the real world
    pplr.Input = mpudata->AcY+90.0; // degrees //analogRead(0);
  }

  if(tuning)
  {
    byte val = (aTune.Runtime());
    if (val!=0)
    {
      tuning = false;
    }
    if(!tuning)
    { //we're done, set the tuning parameters
      pplr.Kp = aTune.GetKp();
      pplr.Ki = aTune.GetKp();
      pplr.Kd = aTune.GetKd();
      PIDlr.SetTunings(pplr.Kp,pplr.Ki,pplr.Kd);
      AutoTuneHelper(false);
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
    theta[30]=pplr.Output;
    if(now>=modelTime)
    {
      modelTime +=100;
      DoModel();
    }
  }
  else
  {
     //analogWrite(0,output);
  }

  //send-receive with processing if it's time
  if(millis()>serialTime)
  {
    SerialReceive();
    SerialSend();
    serialTime+=500;
  }

  if(system_get_time()-lastSteerLoopTime >=(STEER_LOOP_TIME))
  {
    lastSteerLoopTime = system_get_time();


    //if(true == data_received)
    {
      if( (msetpts->x != 0) && (msetpts->y != 0) )
      //for(i=0;i<4;i++)
      {
        //Serial.printf("rnd %d\n", angle);
        servo[0].write(x);

        servo[1].write(y);

        servo[2].write(x1);

        servo[3].write(y1);
      }
      //ESC.write(angle);
    }


    int escval = 0;
    static bool ESC_armed = false;
    if(2 == msetpts->hat)
    {
      escval = MIN_THROTTLE;
      ESC.writeMicroseconds(escval);
      ESC_armed = true;
      //Serial.printf("%d\n", msetpts->hat);
    }

    if(4 == msetpts->hat&& false == ESC_armed)
    {
      escval = MAX_THROTTLE;
      ESC.writeMicroseconds(escval);
      ESC_armed = false;
      //Serial.printf("%d\n", msetpts->hat);
    }

    if(6 == msetpts->hat)
    {
      escval = ZERO_THROTTLE;
      ESC.writeMicroseconds(escval);
      ESC_armed = false;
      //Serial.printf("%d\n", msetpts->hat);
    }

    if ( (true == ESC_armed) )
    {
      escval = map(msetpts->slider
        , 0, 255
        , MIN_THROTTLE, MAX_THROTTLE);

        if(0==escval)
        {
          ESC_armed = false;
        }

        ESC.writeMicroseconds(escval);
      }



      //if(angle>=135)
      //angle = 0;

    }

    return pplr;
  }



// AutoPID tune modeling
//
void changeAutoTune()
{
 if(!tuning)
  {
    //Set the output to the desired starting frequency.
    pplr.Output=aTuneStartValue;
    aTune.SetNoiseBand(aTuneNoise);
    aTune.SetOutputStep(aTuneStep);
    aTune.SetLookbackSec((int)aTuneLookBack);
    AutoTuneHelper(true);
    tuning = true;
  }
  else
  { //cancel autotune
    aTune.Cancel();
    tuning = false;
    AutoTuneHelper(false);
  }
}

void AutoTuneHelper(boolean start)
{
  if(start)
    ATuneModeRemember = PIDlr.GetMode();
  else
    PIDlr.SetMode(ATuneModeRemember);
}


void SerialSend()
{
  // Serial.print("setpoint: ");Serial.print(pplr.Setpoint); Serial.print(" ");
  // Serial.print("input: ");Serial.print(pplr.Input); Serial.print(" ");
  // Serial.print("output: ");Serial.print(pplr.Output); Serial.print(" ");
  // if(tuning){
  //   Serial.println("tuning mode");
  // } else {
  //   Serial.print("kp: ");Serial.print(PIDlr.GetKp());Serial.print(" ");
  //   Serial.print("ki: ");Serial.print(PIDlr.GetKi());Serial.print(" ");
  //   Serial.print("kd: ");Serial.print(PIDlr.GetKd());Serial.println();
  // }
}

void SerialReceive()
{
  if(Serial.available())
  {
   char b = Serial.read();
   Serial.flush();
   if((b=='1' && !tuning) || (b!='1' && tuning))changeAutoTune();
  }
}

void DoModel()
{
  //cycle the dead time
  for(byte i=0;i<49;i++)
  {
    theta[i] = theta[i+1];
  }
  //compute the input
  pplr.Input = (kpmodel / taup) *(theta[0]-outputStart) + pplr.Input*(1-1/taup) + ((float)random(-10,10))/100;

}
