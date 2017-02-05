
#include "data.h"

#include <PID_v1.h>
#include <PID_AutoTune_v0.h>

// pid and autotune pid parameters

//double input = 80, output = 50, setpoint = 180;
double kp = 1.0, ki = 0.0, kd = 0;
//double kp = 0.44, ki = 1.0, kd = 0;
/*

  Steer: Auto Tuning done
  Steer:  kp 0.33 ki 0.01 kd 0.00

  Steer: Tuning done
  Steer:  kp 1.16 ki 0.03 kd 0.00

 * */
pid_val pid_x = {
  .kp = kp,
  .ki = ki,
  .kd = kd,
  .input = 90.0,
  .output = 90.0,
  .setpoint = 90.0
};
pid_val pid_y = {
  .kp = kp,
  .ki = ki,
  .kd = kd,
  .input = 90.0,
  .output = 90.0,
  .setpoint = 90.0
};

PID myPID_x(&pid_x.input, &pid_x.output, &pid_x.setpoint, pid_x.kp, pid_x.ki, pid_x.kd, DIRECT);

PID myPID_y(&pid_y.input, &pid_y.output, &pid_y.setpoint, pid_y.kp, pid_y.ki, pid_y.kd, DIRECT);


PID_ATune aTune_x(&pid_x.input, &pid_x.output);
PID_ATune aTune_y(&pid_y.input, &pid_y.output);


//



#define THIS "Steer: "

#define MAX_THROTTLE (1500) //(1864)
#define MIN_THROTTLE (1064)
#define ZERO_THROTTLE (0)
#define TEST_THROTTLE (1100)
int throttle = TEST_THROTTLE;

#define INCREMENT (50)

Servo servo[4];  // create servo object to control a servo
byte servoVal[4] = {90};
int pins[4] = {2, 3, 4, 5};
int i = 0;

// non working : Send A(1500) B(1064) then A(1500) : Stops in fraction of a second
// working : Send A(1500) B(1064) then D(1400)

// https://hobbyking.com/media/file/391175338X260742X34.pdf
Servo ESC;

void state_machine(char in);
boolean ESC_armed = false;

void ESC_init()
{
  ESC.attach(9);
}


// Mechanical mounting offsets
#define servo0Offset 1 //14 //0 // F 
#define servo1Offset 1  //3 //-10  // R
#define servo2Offset 0  // B
#define servo3Offset -8  // L

byte servoOffsets[] = {
  servo0Offset,
  servo1Offset,
  servo2Offset,
  servo3Offset
};

void servo_init()
{
  for (i = 0 ; i < 4 ; i++)
  {
    servo[i].attach(pins[i]);
    servo[i].write(90);//+servoOffsets[i]);
  }

  myPID_x.SetMode(AUTOMATIC);
  myPID_x.SetTunings(pid_x.kp, pid_x.ki, pid_x.kd);

  aTune_x.SetNoiseBand(2);
  aTune_x.SetOutputStep(50);
  aTune_x.SetLookbackSec(20);



  myPID_y.SetMode(AUTOMATIC);
  myPID_y.SetTunings(pid_y.kp, pid_y.ki, pid_y.kd);

  aTune_y.SetNoiseBand(2);
  aTune_y.SetOutputStep(50);
  aTune_y.SetLookbackSec(20);
  //  pid_y.kp = kp;
  //  pid_y.ki = ki;
  //  pid_y.kd = kp;
  //
  //  myPID_y.SetMode(AUTOMATIC);
  //  myPID_y.SetTunings(pid_y.kp, pid_y.ki, pid_y.kd);

}


void steer_loop(const txGamePadData gd, const angle_val_raw_acc mpu)
{
  // XX,Y MAP FROM 0-1023 TO 60-120 DEGREES
  // SLIDER MAP FROM 255-0 TO 1024-1864
  // TWIST/YAW MAP FROM ? TO ?

#define SERVO0_MIN_LIMIT ( 45 + servo0Offset)
#define SERVO0_MAX_LIMIT ( 135 + servo0Offset)
#define SERVO1_MIN_LIMIT ( 45 + servo1Offset)
#define SERVO1_MAX_LIMIT ( 135 + servo1Offset)
#define SERVO2_MIN_LIMIT ( 45 + servo2Offset)
#define SERVO2_MAX_LIMIT ( 135 + servo2Offset)
#define SERVO3_MIN_LIMIT ( 45 + servo3Offset)
#define SERVO3_MAX_LIMIT ( 135 + servo3Offset)

#define MPU_ANGLE_X_OFFSET (90+3)
#define MPU_ANGLE_Y_OFFSET (90-2)


  servoVal[0] = map(gd.gd.gd.x, 0, 1023, SERVO0_MIN_LIMIT , SERVO0_MAX_LIMIT);
  servoVal[1] = map(gd.gd.gd.y, 0, 1023, SERVO1_MIN_LIMIT , SERVO1_MAX_LIMIT); // it could be opposite i.e. 120-60
  servoVal[2] = map(gd.gd.gd.x, 0, 1023, SERVO2_MIN_LIMIT , SERVO2_MAX_LIMIT);
  servoVal[3] = map(gd.gd.gd.y, 0, 1023, SERVO3_MIN_LIMIT , SERVO3_MAX_LIMIT);

  int yaw_twist = map(gd.gd.gd.twist, 0, 255, -30, 30);

  int thrust_compansation = map(gd.gd.gd.slider, 255, 0, 0, 10);



  // MPU default mech offset is to be checked
  //  byte pid_x_translate_setpoint =  servoVal[0] - servo0Offset;
  //  calc_pid_x(&pid_x_translate_setpoint, mpu.data.y_angle + MPU_ANGLE_X_OFFSET); // mounting is 90 degree rotated :P so x will be y here
  //  servoVal[0] = pid_x_translate_setpoint + servo0Offset;
  servoVal[2] = map(servoVal[0], SERVO0_MIN_LIMIT, SERVO0_MAX_LIMIT, SERVO2_MAX_LIMIT , SERVO2_MIN_LIMIT);

  //byte pid_y_translate_setpoint =  servoVal[1] - servo1Offset;
  //calc_pid_y(&pid_y_translate_setpoint, mpu.data.x_angle + MPU_ANGLE_Y_OFFSET); // mounting is 90 degree rotated :P so x will be y here
  //servoVal[1] = pid_y_translate_setpoint + servo1Offset;
  servoVal[3] = map(servoVal[1], SERVO1_MIN_LIMIT, SERVO1_MAX_LIMIT, SERVO3_MAX_LIMIT , SERVO3_MIN_LIMIT);

  servoVal[0] = servoVal[0] - yaw_twist;
  servoVal[2] = servoVal[2] - yaw_twist;

  servoVal[1] = servoVal[1] - yaw_twist;
  servoVal[3] = servoVal[3] - yaw_twist;

  //calc_pid_y(&servoVal[1], &servoVal[3], mpu.data.y_angle);

  //  servoVal[0] = servoVal[0] + servo0Offset ;// + yaw_twist; // + thrust_compansation
  //  servoVal[1] = servoVal[1] + servo1Offset ;// + yaw_twist; // + thrust_compansation
  //  servoVal[2] = servoVal[2] + servo2Offset ;// + yaw_twist; // + thrust_compansation
  //  servoVal[3] = servoVal[3] + servo3Offset ;// + yaw_twist; // + thrust_compansation

  servoVal[0] = constrain(servoVal[0], 30 , 150); // Absolute meachanical limit
  servoVal[1] = constrain(servoVal[1], 30 , 150); // Absolute meachanical limit
  servoVal[2] = constrain(servoVal[2], 30 , 150); // Absolute meachanical limit
  servoVal[3] = constrain(servoVal[3], 30 , 150); // Absolute meachanical limit

  // pid_loops


  // pid_x(byte, byte, float);

  int escval = 0;
  //  Serial.println();
  //  Serial.println(gd.gd.gd.buttons_a);
  //  Serial.println(gd.gd.gd.buttons_b);
  //  Serial.println();

  if (128 == gd.gd.gd.buttons_a)
  {
    //state_machine('A');
    //#define MAX_THROTTLE (2000) //(1864)
    escval = MAX_THROTTLE;
    ESC.writeMicroseconds(escval);
    ESC_armed = false;
    //    Serial.println();
    //    Serial.println();
    //    Serial.println("MAX");
    //    Serial.println();
    //    Serial.println();

  }

  if (1 == gd.gd.gd.buttons_b)
  {
    //state_machine('A');
    //#define MAX_THROTTLE (2000) //(1864)
    escval = ZERO_THROTTLE;
    ESC.writeMicroseconds(escval);
    ESC_armed = false;
    //    Serial.println();
    //    Serial.println();
    //    Serial.println("Zero");
    //    Serial.println();
    //    Serial.println();

  }

  // few buttons are not working ??
  if (2 == gd.gd.gd.buttons_b)
  {
    //state_machine('B');
    //#define MIN_THROTTLE (1064)
    escval = MIN_THROTTLE;
    ESC.writeMicroseconds(escval);
    ESC_armed = true;
    //    Serial.println();
    //    Serial.println();
    //    Serial.println("MIN");
    //    Serial.println();
    //    Serial.println();
  }


  if ( (true == ESC_armed) )
  {
    escval = map(gd.gd.gd.slider, 255, 0, MIN_THROTTLE, MAX_THROTTLE);
    ESC.writeMicroseconds(escval);
  }
  // check for ESC arming

  servo[0].write(servoVal[0]);
  servo[1].write(servoVal[1]);
  servo[2].write(servoVal[2]);
  servo[3].write(servoVal[3]);


  if (Serial.available())
  {
    char inChar = (char)Serial.read();

    static boolean state_p = false, state_i = false, state_d = false;
    switch (inChar)
    {
      case '+' :
        {
          if (state_p)
          {
            kp = kp + 1;
            kp = kp >= 0 ? kp : 1;

            pid_y.kp = kp;
          }
          else if (state_i)
          {
            ki = ki + 0.1;
            ki = ki >= 0 ? ki : 1;

            pid_y.ki = ki;
          }
          else if (state_d)
          {
            kd = kd + 1;
            kd = kd >= 0 ? kd : 1;

            pid_y.kd = kd;
          }
          else
          {

          }

          Serial.println();
          Serial.print("kp =");
          Serial.print(pid_y.kp);
          Serial.print(" ki =");
          Serial.print(pid_y.ki);
          Serial.print(" kd =");
          Serial.println(pid_y.kd);

          myPID_y.SetTunings(pid_y.kp, pid_y.ki, pid_y.kd);


          break;
        }

      case '-' :
        {
          if (state_p)
          {
            kp = kp - 1;
            kp = kp >= 0 ? kp : 1;

            pid_y.kp = kp;
          }
          else if (state_i)
          {
            ki = ki - 0.1;
            ki = ki >= 0 ? ki : 1;

            pid_y.ki = ki;
          }
          else if (state_d)
          {
            kd = kd - 1;
            kd = kd >= 0 ? kd : 1;

            pid_y.kd = kd;
          }
          else
          {

          }

          Serial.println();
          Serial.print("kp =");
          Serial.print(pid_y.kp);
          Serial.print(" ki =");
          Serial.print(pid_y.ki);
          Serial.print(" kd =");
          Serial.println(pid_y.kd);

          myPID_y.SetTunings(pid_y.kp, pid_y.ki, pid_y.kd);


          break;
        }

      case 'p' :
        {
          state_p = true;
          state_i = false;
          state_d = false;
          break;
        }

      case 'i' :
        {
          state_p = false;
          state_i = true;
          state_d = false;
          break;
        }

      case 'd' :
        {
          state_p = false;
          state_i = false;
          state_d = true;
          break;
        }

      default :
        {

        }
    }

    //state_machine(inChar);
  }



  //Action pending

  //#define SERIAL Serial
  //  SERIAL.print(data.x_angle, 2); SERIAL.print(",");
  //  SERIAL.print(data.y_angle, 2); SERIAL.print(",");
  //  SERIAL.print(data.z_angle, 2); SERIAL.print(",");
  //  SERIAL.print(data.x_unfiltered_acc, 2); SERIAL.print(",");
  //  SERIAL.print(data.y_unfiltered_acc, 2); SERIAL.print(",");
  //  SERIAL.println(data.z_unfiltered_acc, 2);

  //if (last_data.z_angle != data.z_angle)
  {
    float requireYaw = 0.0f;
    if ( abs(yaw - data.data.z_angle) > 10 )
    {
      requireYaw = yaw - data.data.z_angle;
      // SERIAL.print(data.data.z_angle, 2); SERIAL.print(",");
      // SERIAL.println(requireYaw, 2);
    }

    if (
      (abs(data.data.x_angle) < 30 )
      &&
      (abs(data.data.y_angle) < 30 )
    )
    {
      //      servo[0].write(90 - data.data.x_angle);
      //      servo[1].write(90 + data.data.y_angle);
      //      servo[2].write(90 + data.data.x_angle);
      //      servo[3].write(90 - data.data.y_angle);
    }

    last_data = data;
  }
}

void pid_loop(const txGamePadData gd, const angle_val_raw_acc mpu)
{

}

boolean tuning_x = false;
void calc_pid_x(byte *s0, float x)
{

  //static pid_val pid_x ;//= {0.0, 0.0, 0.0, 90.0, 90.0};

  //pid_x.kp = kp;
  //pid_x.ki = ki;
  //pid_x.kd = kd;
  pid_x.input = (double)(x);
  pid_x.output = (double)(*s0);
  pid_x.setpoint = (double)(*s0);

  //static PID myPID_x(pid_x.input, pid_x.output, (double*)s0, pid_x.kp, pid_x.ki, pid_x.kd, DIRECT);

  //myPID_x.SetMode(AUTOMATIC);

  if (tuning_x)
  {
    byte val = (aTune_x.Runtime());
    //Log.Verbose(THIS"Tuning val %d"CR, val);
    // units are same
    Log.Verbose(THIS);
    Serial.print(" Tuning inX ");
    Serial.print(pid_x.input);
    Serial.print(" outX ");
    Serial.print(pid_x.output);
    Serial.print(" set ");
    Serial.println(pid_x.setpoint);
    if (val != 0)
    {
      Log.Verbose(THIS"Tuning done for X"CR);
      tuning_x = false;
    }

    if (!tuning_x)
    {
      //we're done, set the tuning parameters
      kp = aTune_x.GetKp();
      ki = aTune_x.GetKi();
      kd = aTune_x.GetKd();

      pid_x.kp = kp;
      pid_x.ki = ki;
      pid_x.kd = kd;

      Log.Verbose(THIS);
      Serial.print(" X kp ");
      Serial.print(pid_x.kp);
      Serial.print(" ki ");
      Serial.print(pid_x.ki);
      Serial.print(" kd ");
      Serial.println(pid_x.kd);
      aTune_x.Cancel();
      myPID_x.SetTunings(pid_x.kp, pid_x.ki, pid_x.kd);

    }
  }
  else
  {
    myPID_x.Compute();

    //myPID_x.Compute();

    // units are same
    Log.Verbose(THIS);
    Serial.print(" inX ");
    Serial.print(pid_x.input);
    Serial.print(" outX ");
    Serial.print(pid_x.output);
    Serial.print(" set ");
    Serial.println(pid_x.setpoint);
  }

  *s0 = (byte)pid_x.output;
  //*s2 = pid_x.output;
}


boolean tuning_y = false;
void calc_pid_y(byte *s1, float y)
{

  //static pid_val pid_x ;//= {0.0, 0.0, 0.0, 90.0, 90.0};

  //pid_x.kp = kp;
  //pid_x.ki = ki;
  //pid_x.kd = kd;
  pid_y.input = (double)(y);
  pid_y.output = (double)(*s1);
  pid_y.setpoint = (double)(*s1);

  //static PID myPID_x(pid_x.input, pid_x.output, (double*)s0, pid_x.kp, pid_x.ki, pid_x.kd, DIRECT);

  //myPID_x.SetMode(AUTOMATIC);

  if (tuning_y)
  {
    byte val = (aTune_x.Runtime());
    //Log.Verbose(THIS"Tuning val %d"CR, val);
    // units are same
    Log.Verbose(THIS);
    Serial.print(" Tuning inX ");
    Serial.print(pid_y.input);
    Serial.print(" outX ");
    Serial.print(pid_y.output);
    Serial.print(" set ");
    Serial.println(pid_y.setpoint);
    if (val != 0)
    {
      Log.Verbose(THIS"Tuning done for y"CR);
      tuning_y = false;
    }

    if (!tuning_y)
    {
      //we're done, set the tuning parameters
      kp = aTune_y.GetKp();
      ki = aTune_y.GetKi();
      kd = aTune_y.GetKd();

      pid_y.kp = kp;
      pid_y.ki = ki;
      pid_y.kd = kd;

      Log.Verbose(THIS);
      Serial.print(" Y kp ");
      Serial.print(pid_y.kp);
      Serial.print(" ki ");
      Serial.print(pid_y.ki);
      Serial.print(" kd ");
      Serial.println(pid_y.kd);
      aTune_y.Cancel();
      myPID_y.SetTunings(pid_y.kp, pid_y.ki, pid_y.kd);

    }
  }
  else
  {
    myPID_y.Compute();

    // units are same
    Log.Verbose(THIS);
    Serial.print(" inY ");
    Serial.print(pid_y.input);
    Serial.print(" outY ");
    Serial.print(pid_y.output);
    Serial.print(" set ");
    Serial.println(pid_y.setpoint);
  }

  *s1 = (byte)pid_y.output;
  //*s2 = pid_x.output;
}

void state_machine(char inChar)
{

  switch (inChar)
  {
    case 'A' :
      {
        ESC.writeMicroseconds(MAX_THROTTLE);
        Serial.println(" MAX_Throttle");
      } break;
    case 'B' :
      {
        ESC.writeMicroseconds(MIN_THROTTLE);
        Serial.println(" MIN_Throttle");
      } break;
    case 'C' :
      {
        ESC.writeMicroseconds(ZERO_THROTTLE);
        Serial.println(" Zero_Throttle");
      } break;
    case 'D' :
      {
        ESC.writeMicroseconds(TEST_THROTTLE);
        Serial.println(" Test_Throttle");
        throttle = TEST_THROTTLE;
      } break;
    case '+' :
      {
        throttle += INCREMENT;
        throttle = throttle < MAX_THROTTLE ? throttle : MAX_THROTTLE;
        ESC.writeMicroseconds(throttle);
        Serial.print(" Throttle+ = ");
        Serial.println(throttle);
      } break;
    case '-' :
      {
        throttle -= INCREMENT;
        throttle = throttle > ZERO_THROTTLE ? throttle : ZERO_THROTTLE;
        ESC.writeMicroseconds(throttle);
        Serial.print(" Throttle- = ");
        Serial.println(throttle);
      } break;

    case 'S':
      {
        Serial.println("Running sequence ... ");
        state_machine('A');
        delay(400);
        state_machine('B');
        delay(200);
        state_machine('D');
        Serial.println("Ready for throttle...");
      } break;

    case 'R':
      {
        Serial.println("Auto Throttle ... ");

        int i = 0;
        for (i = 0; i < 20; i++)
        {
          state_machine('+');
          delay(300);
        }

        delay(5000);

        for ( i = 0; i < 20; i++)
        {
          state_machine('-');
          delay(100);
        }

        state_machine('C');
        Serial.println("Throttle disarmed...");
      } break;

    case '~':
      {
        Log.Info(THIS"RESETTING the system\n\r\n\r\n\r"CR);
        delay(1000);
        asm volatile ("  jmp 0");
      } break;
    default :
      {
        ESC.writeMicroseconds(0);
        Serial.println(" Default_Throttle");
      } break;

  }
}

