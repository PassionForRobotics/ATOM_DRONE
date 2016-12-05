#include <Logging.h>
#include "data.h"
#include <Servo.h>

//#define GROUND_SYSTEM // or
#define SKY_SYSTEM

#define LOGLEVEL LOG_LEVEL_VERBOSE //LOG_LEVEL_DEBUG

Servo servo[4];  // create servo object to control a servo
int pins[4] = {2, 3, 4, 5};
int i = 0;

#define MAX_THROTTLE (2000) //(1864)
#define MIN_THROTTLE (1064)
#define ZERO_THROTTLE (0)
#define TEST_THROTTLE (1100)
int throttle = TEST_THROTTLE;

#define INCREMENT (50)
float yaw = 0.0f;
// non working : Send A(1500) B(1064) then A(1500) : Stops in fraction of a second
// working : Send A(1500) B(1064) then D(1400)

// https://hobbyking.com/media/file/391175338X260742X34.pdf
Servo ESC;

void servo_init()
{
  for (i = 0 ; i < 4 ; i++)
  {
    servo[i].attach(pins[i]);
    servo[i].write(90);
  }
}

#define THIS "MAIN: "

void setup() {
  unsigned long ts_START = millis();
  //  LOG_LEVEL_NOOUTPUT
  //  LOG_LEVEL_ERRORS
  //  LOG_LEVEL_INFOS
  //  LOG_LEVEL_DEBUG
  //  LOG_LEVEL_VERBOSE
  //  http://playground.arduino.cc/Code/Logging

  Log.Init( LOGLEVEL , 115200L );
  Log.Info(THIS"HELLO WORLD"CR);
  Log.Error(THIS"LOGLEVEL - ERROR LEVEL - MSG CHECK"CR);
  Log.Debug(THIS"LOGLEVEL - DEBUG LEVEL - MSG CHECK"CR);
  Log.Verbose(THIS"LOGLEVEL - VERBOSE LEVEL - MSG CHECK"CR);

#if defined(SKY_SYSTEM)
  Log.Info(THIS"SKY_SYSTEM"CR);
#endif

#if defined(GROUND_SYSTEM)
  Log.Info(THIS"GROUND_SYSTEM"CR);
#endif

#if defined(SKY_SYSTEM)
  Log.Info(THIS"Setting up ECS"CR);
  ESC.attach(9);
  Log.Info(THIS"DONE ECS"CR);
#else
  Log.Info(THIS"BYPASSED ECS"CR);
#endif

#if defined(GROUND_SYSTEM)
  Log.Info(THIS"Setting up Joystick"CR);
  joystick_setup();
  Log.Info(THIS"DONE Joystick"CR);
#else
  Log.Info(THIS"BYPASSED Joystick"CR);
#endif
  /* // test
    while (1)
    {
      const GamePadEventData jdata = joystick_loop();
    }
  */

#if ( defined(GROUND_SYSTEM) || defined(SKY_SYSTEM) )
  Log.Info(THIS"Setting up wifi"CR);
  ESP8266_setup();
  Log.Info(THIS"DONE WIFI"CR);
#else
  Log.Info(THIS"BYPASSED WIFI"CR);
  Log.Error(THIS"WIFI is must for either type of the systems"CR);
#endif
  //while (1);

#if defined(SKY_SYSTEM)
  Log.Info(THIS"Setting up MPU"CR);
  mpu_setup();
  Log.Info(THIS"DONE MPU"CR);
#else
  Log.Info(THIS"BYPASSED MPU"CR);
#endif

#if defined(SKY_SYSTEM)
  Log.Info(THIS"Setting up Servos"CR);
  servo_init();
  Log.Info(THIS"DONE Servos"CR);
#else
  Log.Info(THIS"BYPASSED Servos"CR);
#endif

  delay(100);

  angle_val_raw_acc data = mpu_loop();
  yaw = data.data.z_angle;

  Log.Info(THIS"SYSTEM SETUP COMPLETE"CR);
  Log.Info(THIS"SYSTEM SETUP TIME: %d"CR, millis() - ts_START);

  //while (1);

}

void state_machine(char in);

angle_val_raw_acc last_data;
void loop() {


#if defined(GROUND_SYSTEM)
  const GamePadEventData_Simple joydata = joystick_loop();
  txGamePadData tgd;
  tgd.gd.gd = joydata;
  ESP8266_loop_send_Joystick_data(tgd);
  //const angle_val_raw_acc mdata = ESP8266_loop_recv_MPU_data();
#endif

  // Test
  if (Serial.available())
  {
    char inChar = (char)Serial.read();
    state_machine(inChar);
  }


#if defined(SKY_SYSTEM)
  const txGamePadData gd = ESP8266_loop_recv_joystick_data(); //check
  angle_val_raw_acc data = mpu_loop(); // Must update here too
  // ESP8266_loop_send_MPU_data(data);
  //Log.Verbose(THIS"X: %d Y: %d Z: %d Yaw: %d"CR, gd.x, gd.y, gd.slider, gd.twist); // 0 to 0d1023 0x03FF
  Log.Verbose(THIS"X: %d Y: %d"CR, gd.gd.gd.x, gd.gd.gd.y);

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
      servo[0].write(90 - data.data.x_angle);
      servo[1].write(90 + data.data.y_angle);
      servo[2].write(90 + data.data.x_angle);
      servo[3].write(90 - data.data.y_angle);
    }

    last_data = data;
  }

#endif // SKY_SYSTEM MPU/Joystick
  delay(10);
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

