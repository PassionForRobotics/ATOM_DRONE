#include <Logging.h>
#include "data.h"
#include <Servo.h>

#define GROUND_SYSTEM // or
//#define SKY_SYSTEM

#define LOGLEVEL LOG_LEVEL_VERBOSE //LOG_LEVEL_DEBUG


float yaw = 0.0f;


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
  ESC_init();
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

#if defined(SKY_SYSTEM)
  angle_val_raw_acc data = mpu_loop();
  yaw = data.data.z_angle;
#endif

  Log.Info(THIS"SYSTEM SETUP COMPLETE"CR);
  Log.Info(THIS"SYSTEM SETUP TIME: %d"CR, millis() - ts_START);

  //while (1);

}


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
  Log.Verbose(THIS"X: %d Y: %d Z: %d Yaw: %d, button_a: %d button_b: %d hat: %d"CR
              , gd.gd.gd.x, gd.gd.gd.y, gd.gd.gd.slider, gd.gd.gd.twist
              , gd.gd.gd.buttons_a, gd.gd.gd.buttons_b, gd.gd.gd.hat);

  steer_loop(gd);

#endif // SKY_SYSTEM MPU/Joystick
  delay(1);
}


