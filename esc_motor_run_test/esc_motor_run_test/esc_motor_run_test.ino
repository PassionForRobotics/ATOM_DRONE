
#include <PID_AutoTune_v0.h>

#include <PID_v1.h>

#include <Arduino.h>

#include <Arduino_FreeRTOS.h>
//#include <mpu_wrappers.h>
//#include <croutine.h>
//#include <FreeRTOSConfig.h>
//#include <portable.h>
//#include <StackMacros.h>
//#include <event_groups.h>
#include <queue.h>
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
//#include "ESP8266.h"

#define LOGLEVEL LOG_LEVEL_VERBOSE //LOG_LEVEL_DEBUG


float yaw = 0.0f;
//ESP8266 _wifi(Serial1);

//#define STRINGIFY(x) #x
//#define TOSTRING(x) STRINGIFY(x)
//#define AT __FILE__ ":" TOSTRING(__LINE__)

#if defined(GROUND_SYSTEM)
#define THIS "GND_SYS: MAIN: " TOSTRING(__LINE__) ": "
#elif defined(SKY_SYSTEM)
#define THIS "SKY_SYS: MAIN: " TOSTRING(__LINE__) ": "
#else
#define THIS "???_SYS: MAIN: " TOSTRING(__LINE__) ": "
#endif
// #if defined(SKY_SYSTEM)
// #else
// #define THIS "SKY_SYS: MAIN: " TOSTRING(__LINE__) ": "
//#endif
//#define MAIN "MAIN: "
//#define THIS "MAIN: " // __LINE__ ": "
//SoftwareSerial Serial1(10, 11); // RX, TX


#if ( defined(GROUND_SYSTEM) || defined(SKY_SYSTEM) )
void JoyStickTask( void *pvParameters);

TaskHandle_t WifiDataTaskHandler = NULL;

QueueHandle_t xWifiDataSendQ = NULL, xWifiDataReceiveQ = NULL; // What about MPU data

void WifiDataTask( void *pvParameters);
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

  Log.Init( LOGLEVEL , 230400L );
  Log.Info(THIS"HELLO WORLD"CR);
  Log.Error(THIS"LOGLEVEL - ERROR LEVEL - MSG CHECK"CR);
  Log.Warning(THIS"LOGLEVEL - WARNING LEVEL - MSG CHECK"CR);
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
  Log.Warning(THIS"BYPASSED ECS"CR);
  #endif

  #if defined(GROUND_SYSTEM)
  Log.Info(THIS"Setting up Joystick"CR);
  joystick_setup();
  Log.Info(THIS"DONE Joystick"CR);
  #else
  Log.Warning(THIS"BYPASSED Joystick"CR);
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
Log.Warning(THIS"BYPASSED MPU"CR);
#endif

#if defined(SKY_SYSTEM)
Log.Info(THIS"Setting up Servos"CR);
servo_init();
Log.Info(THIS"DONE Servos"CR);
#else
Log.Warning(THIS"BYPASSED Servos"CR);
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
  ,  (4 * 256) // This stack size can be checked & adjusted by reading the Stack Highwater
  ,  NULL//(void*)(&_wifi)
  ,  1  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
  ,  NULL );

  xReturned &= xTaskCreate(
    WifiDataTask
    ,  (const portCHAR *)"WifiDataTask"  // A name just for humans
    ,  (4 * 256) // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL//(void*)(&_wifi)
    ,  1  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  &WifiDataTaskHandler );

    xWifiDataSendQ = xQueueCreate( 2, sizeof( txGamePadData ) );
    xWifiDataReceiveQ = xQueueCreate( 2, sizeof( txGamePadData ) );

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

  void WifiDataTask( void *pvParameters __attribute__((unused))  )  // This is a Task.
  {
    Log.Verbose(THIS"Suspending"CR);

    vTaskSuspend( NULL );

    Log.Verbose(THIS"Resumed"CR);

    txGamePadData tgd;
    int ret = -1;

    for(;;)
    {
      #if defined(GROUND_SYSTEM)

      if( xWifiDataSendQ != 0 )
      {
        // Receive a message on the created queue.  Block for 10 ticks if a
        // message is not immediately available.
        if( xQueueReceive( xWifiDataSendQ, &( tgd ), ( TickType_t ) 10 ) )
        {
          ret = wifi_loop_send_Joystick_data(&tgd);
          if(0==ret)
          {
            // all fine
            ret = -1; // restore next work
          }
          else
          {
            Log.Warning(THIS"Joystick data sent failed"CR);
          }
        }
      }

      #elif defined(SKY_SYSTEM)

      if( xWifiDataReceiveQ != 0 )
      {
        ret = wifi_loop_recv_joystick_data(&tgd); //check

        //if(0==ret)
        //if( xQueueSend( xWifiDataReceiveQ, ( void * ) &tgd, ( TickType_t ) 10 ) != pdPASS )
        //if( xQueueSend( xWifiDataReceiveQ, &( tgd ), ( TickType_t ) 10 ) )
        //{
        if(0==ret)
        {
          if( xQueueSend( xWifiDataReceiveQ, ( void * ) &tgd, ( TickType_t ) 10 ) != pdPASS )
          // all fine
          ret = -1; // restore next work
        }
        else
        {
          //Log.Warning(THIS"Joystick data rec failed"CR);
        }
        //}
      }

      #else

      #endif

      Delay(100);

    }

  }
  
  void JoyStickTask( void *pvParameters __attribute__((unused))  )  // This is a Task.
  {

    #if ( defined(GROUND_SYSTEM) || defined(SKY_SYSTEM) )
    Log.Info(THIS"Setting up wifi"CR);
    if(-1==wifi_setup())
    {
      Log.Error(THIS"WIFI fault"CR);
      while(1);
    }
    Log.Info(THIS"DONE WIFI"CR);

    #else
    Log.Warning(THIS"BYPASSED WIFI"CR);
    Log.Error(THIS"WIFI is must for either type of the systems"CR);
    #endif

    #if defined(GROUND_SYSTEM)
    txGamePadData tgd;
    int ret = -1;

    vTaskResume( WifiDataTaskHandler );
    Log.Verbose(THIS"Resumming"CR);

    for (;;)
    {
      const GamePadEventData_Simple joydata = joystick_loop(); // work pointer wise
      tgd.gd.gd = joydata;

      if( xWifiDataSendQ != 0 )
      {
        /* Send an unsigned long.  Wait for 10 ticks for space to become
        available if necessary. */
        if( xQueueSend( xWifiDataSendQ, ( void * ) &tgd, ( TickType_t ) 10 ) != pdPASS )
        {
          /* Failed to post the message, even after 10 ticks. */
        }
        else
        {

        }
      }

      // ret = wifi_loop_send_Joystick_data(&tgd);
      //
      // if(0!=ret)
      // {
      //   Log.Warning(THIS"Joystick data send failed"CR);
      // }
      // else
      // {
      //   Log.Verbose(THIS"Joystick data send attempted"CR);
      //   //02 FF FE 00 02 00 00 00 0F 00 00 00 02 FF 0C 01 00 00 00 00 00 00 00 00 00 00 03
      // }
      //while(1);
      //const angle_val_raw_acc mdata = ESP8266_loop_recv_MPU_data();
      Delay(100);
    }

    //#endif // GROUND_SYSTEM MPU/Joystick

    #elif defined(SKY_SYSTEM)

    angle_val_raw_acc data;
    txGamePadData gd;
    int ret = -1;

    vTaskResume( WifiDataTaskHandler );
    Log.Verbose(THIS"Resumming"CR);

    for (;;)
    {

      data = mpu_loop(); // Must update here too
      // ESP8266_loop_send_MPU_data(data);
      //Log.Verbose(THIS"X: %d Y: %d Z: %d Yaw: %d, button_a: %d button_b: %d hat: %d"CR
      //            , gd.gd.gd.x, gd.gd.gd.y, gd.gd.gd.slider, gd.gd.gd.twist
      //            , gd.gd.gd.buttons_a, gd.gd.gd.buttons_b, gd.gd.gd.hat);

      memset(gd.uc_data, 0, SIZE_OF_GPADDATA_STRUCT);

      if( xWifiDataReceiveQ != 0 )
      {
        // Receive a message on the created queue.  Block for 10 ticks if a
        // message is not immediately available.
        if( xQueueReceive( xWifiDataReceiveQ, &( gd ), ( TickType_t ) 10 ) )
        {
          // pcRxedMessage now points to the struct AMessage variable posted
          // by vATask.
        }
      }

      // ret = wifi_loop_recv_joystick_data(&gd); //check
      // Log.Verbose(THIS"Joystick data rec attempted"CR);
      //
      // if(0==ret) // all good
      // {
      //   #warning steer off
      //   while(1);
      //   //steer_loop(gd);
      // }
      // else
      // {
      //
      //   Log.Warning(THIS"Joystick data rec failed"CR);
      //
      // }
      //
      // Delay(10000);
      //while(1);
      Delay(100);
    }
    #else

    // else
    Delay(100);

    #endif // SKY_SYSTEM MPU/Joystick
  }

  void loop() {
    return;

    // Test
    if (Serial.available())
    {
      char inChar = (char)Serial.read();
      state_machine(inChar);
    }

    //delay(1);
  }
