#include <Arduino_FreeRTOS.h>
//#include <mpu_wrappers.h>
//#include <croutine.h>
//#include <FreeRTOSConfig.h>
//#include <portable.h>
//#include <StackMacros.h>
//#include <event_groups.h>
//#include <queue.h>
//#include <FreeRTOSVariant.h>
//#include <semphr.h>
//#include <projdefs.h>
//#include <list.h>/
//#include <portmacro.h>
//#include <timers.h>
//#include <task.h>

//#include <SoftwareSerial.h>

#include <Logging.h>
#include "data.h"
#include <Servo.h>
#include "ESP8266.h"

//#define GROUND_SYSTEM // or
#define SKY_SYSTEM

#define LOGLEVEL LOG_LEVEL_VERBOSE //LOG_LEVEL_DEBUG


float yaw = 0.0f;
//ESP8266 _wifi(Serial1);

#define THIS "MAIN: "
//SoftwareSerial Serial1(10, 11); // RX, TX


#if ( defined(GROUND_SYSTEM) || defined(SKY_SYSTEM) ) 
void JoyStickTask( void *pvParameters);
#endif

void setup() {

  delay(100);
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

  //  #error Open Telegram and check scifi note for wifi lib Checked not compiling will take it when free.

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

  //#if ( defined(GROUND_SYSTEM) || defined(SKY_SYSTEM) )
  //  Log.Info(THIS"Setting up wifi"CR);
  //  static ESP8266 _wifi = ESP8266_setup();
  //  Log.Info(THIS"DONE WIFI"CR);
  //#else
  //  Log.Info(THIS"BYPASSED WIFI"CR);
  //  Log.Error(THIS"WIFI is must for either type of the systems"CR);
  //#endif
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

  BaseType_t xReturned;


#if ( defined(GROUND_SYSTEM) || defined(SKY_SYSTEM) )
  xReturned = xTaskCreate(
                JoyStickTask
                ,  (const portCHAR *)"JoyStickTask"  // A name just for humans
                ,  (4 * 512) // This stack size can be checked & adjusted by reading the Stack Highwater
                ,  NULL//(void*)(&_wifi)
                ,  1  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
                ,  NULL );

  if (pdFALSE == xReturned)
  {
    Log.Error(THIS"xTaskCreate failed"CR);
  }
  else
  {
    Log.Info(THIS"xTaskCreated"CR);
  }

  //  xReturned = xTaskCreate(
  //                SerialRxTask
  //                ,  (const portCHAR *)"JoyStickTask"  // A name just for humans
  //                ,  (1 * 512) // This stack size can be checked & adjusted by reading the Stack Highwater
  //                ,  NULL //(void*)(&_wifi)
  //                ,  1  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
  //                ,  NULL );
  //
  //  if (pdFALSE == xReturned)
  //  {
  //    Log.Error(THIS"xTaskCreate failed"CR);
  //  }
  //  else
  //  {
  //    Log.Info(THIS"xTaskCreated"CR);
  //  }
#endif

  Log.Info(THIS"SYSTEM SETUP COMPLETE"CR);
  Log.Info(THIS"SYSTEM SETUP TIME: %d"CR, millis() - ts_START);

  //vTaskStartScheduler();
  //while (1);

}


angle_val_raw_acc last_data;

void SerialRxTask( void *pvParameters __attribute__((unused))  )  // This is a Task.
{
  for (;;)
  {
    serialEventRun();
  }
}

void JoyStickTask( void *pvParameters __attribute__((unused))  )  // This is a Task.
{
  //serialEventRun
  //ESP8266 *_wifi = static_cast<ESP8266 *>(pvParameters);
  //thing * p2 = static_cast<thing *>(pv);

  //Log.Verbose(THIS"wifi ptr 0x%u"CR, _wifi);

  //if( true == _wifi->kick() )
  //  {
  //    Log.Verbose(THIS"wifi alive"CR);
  //  }
  //  else
  //  {
  //    Log.Error(THIS"wifi dead"CR);
  //  }

  //ESP8266 _wifi = (ESP8266) (*wifi);

#if ( defined(GROUND_SYSTEM) || defined(SKY_SYSTEM) )
  Log.Info(THIS"Setting up wifi"CR);
  ESP8266 _wifi = ESP8266_setup();
  Log.Info(THIS"DONE WIFI"CR);
#else
  Log.Info(THIS"BYPASSED WIFI"CR);
  Log.Error(THIS"WIFI is must for either type of the systems"CR);
#endif

#if defined(GROUND_SYSTEM)



  for (;;)
  {
    const GamePadEventData_Simple joydata = joystick_loop();
    txGamePadData tgd;
    tgd.gd.gd = joydata;
    ESP8266_loop_send_Joystick_data(_wifi, tgd);
    //const angle_val_raw_acc mdata = ESP8266_loop_recv_MPU_data();
  }

#endif // GROUND_SYSTEM MPU/Joystick

#if defined(SKY_SYSTEM)

  angle_val_raw_acc data;

  for (;;)
  {
    const txGamePadData gd = ESP8266_loop_recv_joystick_data(_wifi); //check
    data = mpu_loop(); // Must update here too
    // ESP8266_loop_send_MPU_data(data);
    Log.Verbose(THIS"X: %d Y: %d Z: %d Yaw: %d, button_a: %d button_b: %d hat: %d"CR
                , gd.gd.gd.x, gd.gd.gd.y, gd.gd.gd.slider, gd.gd.gd.twist
                , gd.gd.gd.buttons_a, gd.gd.gd.buttons_b, gd.gd.gd.hat);

    steer_loop(gd);
  }

#endif // SKY_SYSTEM MPU/Joystick
}

void loop() {

  // Test
  if (Serial.available())
  {
    char inChar = (char)Serial.read();
    state_machine(inChar);
  }

  //delay(1);
}


