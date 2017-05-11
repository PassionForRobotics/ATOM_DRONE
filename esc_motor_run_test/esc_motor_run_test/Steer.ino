#include <Arduino.h>


#include "data.h"

#if defined(GROUND_SYSTEM)
#define THIS "GND_SYS: STEER: " TOSTRING(__LINE__) ": "
#elif defined(SKY_SYSTEM)
#else
#define THIS "SKY_SYS: STEER: " TOSTRING(__LINE__) ": ""
#endif

//#define THIS "Steer: "

#define MAX_THROTTLE (2000) //(1864)
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

void servo_init()
{
  for (i = 0 ; i < 4 ; i++)
  {
    servo[i].attach(pins[i]);
    servo[i].write(90);
  }
}

void steer_pid_loop(const txGamePadData gd, const angle_val_raw_acc mpu)
{
  // Not implemented
  // 
}

void steer_loop(const txGamePadData gd, const angle_val_raw_acc mpu)
{
  // XX,Y MAP FROM 0-1023 TO 60-120 DEGREES
  // SLIDER MAP FROM 255-0 TO 1024-1864
  // TWIST/YAW MAP FROM ? TO ?

#define servo1Offset 0 // F
#define servo2Offset -10  // R
#define servo3Offset 7  // B
#define servo4Offset 0  // L


  servoVal[0] = map(gd.gd.gd.x, 0, 1023, 60 , 120);
  servoVal[1] = map(gd.gd.gd.y, 0, 1023, 60 , 120); // it could be opposite i.e. 120-60
  servoVal[2] = map(gd.gd.gd.x, 0, 1023, 120, 60);
  servoVal[3] = map(gd.gd.gd.y, 0, 1023, 120, 60);

  int yaw_twist = map(gd.gd.gd.twist, 0, 255, -10, 10);

  int thrust_compansation = map(gd.gd.gd.slider, 255, 0, 0, 10);

  servoVal[0] = servoVal[0] + servo1Offset + yaw_twist; // + thrust_compansation
  servoVal[1] = servoVal[1] + servo2Offset + yaw_twist; // + thrust_compansation
  servoVal[2] = servoVal[2] + servo3Offset + yaw_twist; // + thrust_compansation
  servoVal[3] = servoVal[3] + servo4Offset + yaw_twist; // + thrust_compansation

  int escval = 0;

  if (128 == gd.gd.gd.buttons_a)
  {
    //state_machine('A');
    //#define MAX_THROTTLE (2000) //(1864)
    escval = MAX_THROTTLE;
    ESC.writeMicroseconds(escval);
    ESC_armed = false;

  }

  if (1 == gd.gd.gd.buttons_b)
  {
    //state_machine('A');
    //#define MAX_THROTTLE (2000) //(1864)
    escval = ZERO_THROTTLE;
    ESC.writeMicroseconds(escval);
    ESC_armed = false;

  }

  if (64 == gd.gd.gd.buttons_a)
  {
    //state_machine('B');
    //#define MIN_THROTTLE (1064)
    escval = MIN_THROTTLE;
    ESC.writeMicroseconds(escval);
    ESC_armed = true;
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
    if ( abs(yaw - _data.data.z_angle) > 10 )
    {
      requireYaw = yaw - _data.data.z_angle;
      // SERIAL.print(data.data.z_angle, 2); SERIAL.print(",");
      // SERIAL.println(requireYaw, 2);
    }

    if (
      (abs(_data.data.x_angle) < 30 )
      &&
      (abs(_data.data.y_angle) < 30 )
    )
    {
      //      servo[0].write(90 - data.data.x_angle);
      //      servo[1].write(90 + data.data.y_angle);
      //      servo[2].write(90 + data.data.x_angle);
      //      servo[3].write(90 - data.data.y_angle);
    }

    last_data = _data;
  }
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
