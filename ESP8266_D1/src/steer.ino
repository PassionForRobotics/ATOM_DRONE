
#include <Servo.h>
#include "data.h"

#include <PID_v1.h>

PID_Tune_Params_t pplr =
{
  90.0, 90.0, 90.0,
  200.0, 30.0, 10.0
}; // pid_params_left_right

PID PIDlr(&pplr.Input, &pplr.Output, &pplr.Setpoint, pplr.Kp, pplr.Ki, pplr.Kd, DIRECT);

PID_Tune_Params_t ppfb =
{
  90.0, 90.0, 90.0,
  200.0, 30.0, 10.0
}; // pid_params_up_down

PID PIDfb(&ppfb.Input, &ppfb.Output, &ppfb.Setpoint, ppfb.Kp, ppfb.Ki, ppfb.Kd, DIRECT);

PID_Tune_Params_t ppud = // the initial points needs to be merged with ping data
{
  90.0, 90.0, 90.0,
  200.0, 30.0, 10.0
}; // pid_params_up_down

PID PIDud(&ppud.Input, &ppud.Output, &ppud.Setpoint, ppud.Kp, ppud.Ki, ppud.Kd, DIRECT);

// AutoPID Tune
#include <PID_AutoTune_v0.h>

PID_AutoTune_Params_t palr =
{
  2,
  1.5, 100,
  5,
  50, 1, 100,
  20,
  false,
  0,0,
  //set to false to connect to the real worl
  true,
  0
};

PID_ATune PID_ATune_LR(&pplr.Input, &pplr.Output);


PID_AutoTune_Params_t pafb =
{
  2,
  1.5, 100,
  5,
  50, 1, 100,
  20,
  false,
  0,0,
  //set to false to connect to the real worl
  true,
  0
};

PID_ATune PID_ATune_FB(&ppfb.Input, &ppfb.Output);


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


  PIDlr.SetOutputLimits(-45+90, 45+90); // Offsets are not taken into account for now
  PIDlr.SetMode(AUTOMATIC);

  palr.AutoTunersInit(&pplr, &PID_ATune_LR, &PIDlr);

  PIDfb.SetOutputLimits(-45+90, 45+90); // Offsets are not taken into account for now
  PIDfb.SetMode(AUTOMATIC);

  pafb.AutoTunersInit(&ppfb, &PID_ATune_FB, &PIDfb);

}

byte angle = 35;
uint32_t lastSteerLoopTime = 0;

void steer_loop(debug_data *all_data, sMOTIONSETPOINTS_t *msetpts)
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

  palr.pid_loop(all_data, &pplr, &PID_ATune_LR, &PIDlr);
  pafb.pid_loop(all_data, &ppfb, &PID_ATune_FB, &PIDfb);

  // Use
  //all_data->pplr.Output
  //all_data->ppfb.Output
  



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


  //all_data->ppfb
  all_data->pplr = pplr;
  all_data->ppfb = ppfb;
  all_data->ppud = ppud;
  //all_data->ppud

  //return pplr;
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

    b = b - 48; //ascii to int

    switch(b)
    {
      case PID_TUNE_TYPE_NONE:
      {
        if(palr.tuning)
          palr.changeAutoTune(&pplr, &PID_ATune_LR, &PIDlr);

        if(pafb.tuning)
          pafb.changeAutoTune(&ppfb, &PID_ATune_FB, &PIDfb);

          // if ... pafb, paud
      }break;

      case PID_TUNE_TYPE_LEFT_RIGHT:
      {
        //if((b=='1' && !palr.tuning) || (b!='1' && palr.tuning))
        palr.changeAutoTune(&pplr, &PID_ATune_LR, &PIDlr);
      }break;

      case PID_TUNE_TYPE_FORE_BACK:
      {
        palr.changeAutoTune(&pplr, &PID_ATune_LR, &PIDlr);
      }break;

      case PID_TUNE_TYPE_UP_DOWN:
      {

      }break;

      default:
      {
        Serial.printf("PID mode : Not implemented\n" );
      }
    }
  }
}
