
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
#include <semphr.h>
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

// #define LOG_LEVEL_NOOUTPUT 0
// #define LOG_LEVEL_ERRORS 1
// #define LOG_LEVEL_WARNINGS 2
// #define LOG_LEVEL_INFOS 3
// #define LOG_LEVEL_DEBUG 4
// #define LOG_LEVEL_VERBOSE 5

#define LOGLEVEL LOG_LEVEL_DEBUG //LOG_LEVEL_INFOS //LOG_LEVEL_VERBOSE //LOG_LEVEL_DEBUG


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

// Create a Semaphore binary flag for the Serial Port. To ensure only single access.
SemaphoreHandle_t xSerialSemaphore;

#define TASK_LOOP_TIME (100)

void WifiDataTask( void *pvParameters);
#endif

void(* resetFunc) (void) = 0; // RESET AVR BASED Controllers only

void setup() {

  delay(100);
  unsigned long ts_START = millis();
  //  LOG_LEVEL_NOOUTPUT
  //  LOG_LEVEL_ERRORS
  //  LOG_LEVEL_INFOS
  //  LOG_LEVEL_DEBUG
  //  LOG_LEVEL_VERBOSE
  //  http://playground.arduino.cc/Code/Logging

  Log.Init( LOGLEVEL , 921600L );
  Log.Info(THIS"EMPTY"CR);
  Log.Info(THIS"EMPTY"CR);
  Log.Info(THIS"EMPTY"CR);
  Log.Info(THIS"HELLO WORLD"CR);
  Log.Error(THIS"LOGLEVEL - ERROR LEVEL - MSG CHECK"CR);
  Log.Warning(THIS"LOGLEVEL - WARNING LEVEL - MSG CHECK"CR);
  Log.Debug(THIS"LOGLEVEL - DEBUG LEVEL - MSG CHECK"CR);
  Log.Verbose(THIS"LOGLEVEL - VERBOSE LEVEL - MSG CHECK"CR);

  //  #error Open Telegram and check scifi note for wifi lib Checked not compiling will take it when free.

  #if defined(SKY_SYSTEM)
  Log.Info(THIS"SKY_SYSTEM VERISON %s"CR,VERSION);
  #endif

  #if defined(GROUND_SYSTEM)
  Log.Info(THIS"GROUND_SYSTEM VERISON %s"CR,VERSION);
  #endif

  Log.Info(THIS"TASK_LOOP_TIME %d"CR, TASK_LOOP_TIME);

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

// txGamePadData _gd;
// Serial.println("SIZE_OF_JDATA_STRUCT , DATATYPE_JOY");
// _gd.uc_data[0] = 0x02;
// _gd.uc_data[1] = 0xFF;
// _gd.uc_data[2] = SIZE_OF_JDATA_STRUCT;
// _gd.uc_data[3] = DATATYPE_JOY;
// _gd.uc_data[4] = 0;
// _gd.gd.etx = 0x03;
//
// Serial.print(__LINE__); // C/2 | 16 | 15
// Serial.print(" [3]: ");
// Serial.print((int)_gd.uc_data[2]);
// Serial.print(" |len: ");
// Serial.print(_gd.gd.data_len);
// Serial.print(" |mcro: ");
// Serial.println(SIZE_OF_JDATA_STRUCT);
//
// for(int i = 0 ; i < SIZE_OF_GPADDATA_STRUCT ; i++)
// {
//
//   Serial.print("[");
//   Serial.print(i);
//   Serial.print("] : ");
//   Serial.println((int)_gd.uc_data[i]);
//
// }
//
// txGamePadORMPUData gd;
//
// Serial.println("SIZE_OF_MDATA_STRUCT , DATATYPE_MPU");
//
// gd.uc_data[0] = 0x02;
// gd.uc_data[1] = 0xFF;
// gd.uc_data[2] = SIZE_OF_MDATA_STRUCT;
// gd.uc_data[3] = DATATYPE_MPU;
// gd.uc_data[4] = 0;
// gd.data.etx = 0x03;
//
// Serial.print(__LINE__); // C/2 | 16 | 15
// Serial.print(" [3]: ");
// Serial.print((int)gd.uc_data[2]);
// Serial.print(" |len: ");
// Serial.print(gd.data.data_len);
// Serial.print(" |mcro: ");
// Serial.println(SIZE_OF_MDATA_STRUCT);
//
// for(int i = 0 ; i < SIZE_OF_GPADMDATA_STRUCT ; i++)
// {
//
//   Serial.print("[");
//   Serial.print(i);
//   Serial.print("] : ");
//   Serial.println((int)gd.uc_data[i]);
//
// }
//
// ///////////////////////////
// Serial.println("SIZE_OF_MDATA_STRUCT , DATATYPE_JOY");
//
// gd.uc_data[0] = 0x02;
// gd.uc_data[1] = 0xFF;
// gd.uc_data[2] = SIZE_OF_JDATA_STRUCT;
// gd.uc_data[3] = DATATYPE_JOY;
// //gd.uc_data[2] = SIZE_OF_MDATA_STRUCT;
// //gd.uc_data[3] = DATATYPE_MPU;
// gd.uc_data[4] = 0;
// gd.data.etx = 0x03;
//
// Serial.print(__LINE__); // C/2 | 16 | 15
// Serial.print(" [3]: ");
// Serial.print((int)gd.uc_data[2]);
// Serial.print(" |len: ");
// Serial.print(gd.data.data_len);
// Serial.print(" |mcro: ");
// Serial.println(SIZE_OF_MDATA_STRUCT);
//
// for(int i = 0 ; i < SIZE_OF_GPADMDATA_STRUCT ; i++)
// {
//
//   Serial.print("[");
//   Serial.print(i);
//   Serial.print("] : ");
//   Serial.println((int)gd.uc_data[i]);
//
// }

//while(1);

delay(100);

if ( xSerialSemaphore == NULL )          // Check to see if the Serial Semaphore has not been created.
{
  xSerialSemaphore = xSemaphoreCreateMutex(); // mutex semaphore for Serial Port
  if ( ( xSerialSemaphore ) != NULL )
  xSemaphoreGive( ( xSerialSemaphore ) );  // make the Serial Port available
}

#if defined(SKY_SYSTEM)
angle_val_raw_acc data = mpu_loop();
yaw = data.data.z_angle;
#endif

BaseType_t xReturned;


#if ( defined(GROUND_SYSTEM) || defined(SKY_SYSTEM) )
xReturned = xTaskCreate(
  JoyStickTask
  ,  (const portCHAR *)"JoyStickTask"  // A name just for humans
  ,  (5 * 256) // This stack size can be checked & adjusted by reading the Stack Highwater
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

    #if defined(USE_DATA_UNION)

    xWifiDataSendQ = xQueueCreate( 10, sizeof( txGamePadORMPUData ) );
    xWifiDataReceiveQ = xQueueCreate( 10, sizeof( txGamePadORMPUData ) );

    #else

    xWifiDataSendQ = xQueueCreate( 10, sizeof( txGamePadData ) );
    xWifiDataReceiveQ = xQueueCreate( 10, sizeof( txGamePadData ) );

    #endif // defined(USE_DATA_UNION)

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
    TickType_t xLastWakeTime;

    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {
      Log.Verbose(THIS"Suspending"CR);

      if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  // make the Serial Port available
    }

    vTaskSuspend( NULL );

    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {
      Log.Verbose(THIS"Resumed"CR);

      if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  // make the Serial Port available
    }

    #if defined(USE_DATA_UNION)
    txGamePadORMPUData tgd;
    #else
    txGamePadData tgd;
    #endif

    int ret = -1;

    // memset(tgd.uc_data, 0, SIZE_OF_GPADDATA_STRUCT);
    //
    // ret = wifi_loop_send_Joystick_data(&tgd);
    // if(0==ret)
    // {
    //   // all fine
    //   ret = -1; // restore next work
    // }
    // else
    // {
    //   Log.Warning(THIS"test Joystick data sent failed"CR);
    // }

    for(;;)
    {
      xLastWakeTime = xTaskGetTickCount();

      #if defined(GROUND_SYSTEM)

      if( xWifiDataSendQ != 0 )
      {
        // Receive a message on the created queue.  Block for 10 ticks if a
        // message is not immediately available.
        if( xQueueReceive( xWifiDataSendQ, &( tgd ), ( TickType_t ) 10 ) )
        {
          if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
          {
            Log.Verbose(THIS"Data Sending"CR);

            if ( ( xSerialSemaphore ) != NULL )
            xSemaphoreGive( ( xSerialSemaphore ) );  // make the Serial Port available
          }

          // Send joy stick data

          ret = wifi_loop_send_Joystick_or_mpu_data(&tgd); // tested, works as expected

          // receive MPU data
          // ret = wifi_loop_recv_mpu_data(& ? ); //check

          if(0==ret)
          {
            // all fine
            ret = -1; // restore next work
          }
          else
          {
            if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
            {
              Log.Warning(THIS"Joystick data sent failed"CR);

              if ( ( xSerialSemaphore ) != NULL )
              xSemaphoreGive( ( xSerialSemaphore ) );  // make the Serial Port available
            }

          }
        }
      }

      #elif defined(SKY_SYSTEM)

      if( xWifiDataReceiveQ != 0 )
      {
        //if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
        //{

        ret = wifi_loop_recv_joystick_data(&tgd); //check

        //if ( ( xSerialSemaphore ) != NULL )
        //xSemaphoreGive( ( xSerialSemaphore ) );  // make the Serial Port available
        //}
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
          Log.Warning(THIS"Joystick data rec failed"CR);
        }
        //}
      }

      #else

      #endif

      Delay(TASK_LOOP_TIME, xLastWakeTime);

    }

  }

  void JoyStickTask( void *pvParameters __attribute__((unused))  )  // This is a Task.
  {

    TickType_t xLastWakeTime;

    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {

      #if ( defined(GROUND_SYSTEM) || defined(SKY_SYSTEM) )
      Log.Info(THIS"Setting up wifi"CR);
      if(-1==wifi_setup())
      {
        Log.Error(THIS"WIFI fault"CR);
        while(1)
        {
          loop();
        }
      }
      Log.Info(THIS"DONE WIFI"CR);

      Log.Reinit(LOG_LEVEL_INFOS);

      #else
      Log.Warning(THIS"BYPASSED WIFI"CR);
      Log.Error(THIS"WIFI is must for either type of the systems"CR);
      #endif

      if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  // make the Serial Port available
    }

    #if defined(GROUND_SYSTEM)

    #if defined(USE_DATA_UNION)
    txGamePadORMPUData tgd, dummy;
    #else
    txGamePadData tgd, dummy;
    #endif

    int ret = -1;

    // Not serial print is allowed further
    vTaskResume( WifiDataTaskHandler );
    //Log.Verbose(THIS"Resumming"CR);

    for (;;)
    {
      xLastWakeTime = xTaskGetTickCount();

      const GamePadEventData_Simple joydata = joystick_loop(); // work pointer wise

      #if defined(USE_DATA_UNION)
      tgd.data.data.mpu.data = DEFAULT_MPU_DATA;//{ .x_angle = 0.0, .y_angle = 0.0, .z_angle = 0.0, .x_unfiltered_acc=0.0, .y_unfiltered_acc=0.0, .z_unfiltered_acc=0.0  };
      tgd.data.data.gd = joydata;
      tgd.data.data_type = DATATYPE_JOY;
      tgd.data.data_len = SIZE_OF_MDATA_STRUCT;
      //tgd.data.
      #else
      tgd.gd.gd = joydata;
      tgd.gd.data_type = DATATYPE_JOY;
      tgd.gd.data_len = SIZE_OF_JDATA_STRUCT;
      #endif

      if( xWifiDataSendQ != 0 )
      {
        /* Send an unsigned long.  Wait for 10 ticks for space to become
        available if necessary. */
        UBaseType_t whetherSpaceAvailable = uxQueueSpacesAvailable( xWifiDataSendQ );

        if( (UBaseType_t)(0) == whetherSpaceAvailable)
        {
          //xQueueOverwrite( xQueue, &ulVarToSend );
          if( xQueueReceive( xWifiDataSendQ, &( dummy ), ( TickType_t ) 10 ) )
          {

          }

          if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
          {
            Log.Warning(THIS"xWDSQ full JOY %d"CR, whetherSpaceAvailable);
          }

          if ( ( xSerialSemaphore ) != NULL )
          xSemaphoreGive( ( xSerialSemaphore ) );  // make the Serial Port available

        }

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
      //   //02 ff fe 00 02 00 00 00 1e 00 00 00 02 ff 0c 01 00 fc 01 00 02 08 7f 00 ff 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 03
      // }
      //while(1);
      //const angle_val_raw_acc mdata = ESP8266_loop_recv_MPU_data();
      Delay(TASK_LOOP_TIME, xLastWakeTime);
    }

    //#endif // GROUND_SYSTEM MPU/Joystick

    #elif defined(SKY_SYSTEM)

    #if defined(USE_DATA_UNION)
    txGamePadORMPUData rgd, dummy;
    #else
    txGamePadData rgd, dummy;
    #endif

    angle_val_raw_acc data;

    int ret = -1;

    vTaskResume( WifiDataTaskHandler );

    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {
      Log.Verbose(THIS"Resumming"CR);

      if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  // make the Serial Port available
    }

    for (;;)
    {
      xLastWakeTime = xTaskGetTickCount();

      data = mpu_loop(); // Must update here too
      // ESP8266_loop_send_MPU_data(data);
      //Log.Verbose(THIS"X: %d Y: %d Z: %d Yaw: %d, button_a: %d button_b: %d hat: %d"CR
      //            , gd.gd.gd.x, gd.gd.gd.y, gd.gd.gd.slider, gd.gd.gd.twist
      //            , gd.gd.gd.buttons_a, gd.gd.gd.buttons_b, gd.gd.gd.hat);

      // #if defined(USE_DATA_UNION)
      // memset(((txGamePadORMPUData)rgd).uc_data, 0, SIZE_OF_GPADMDATA_STRUCT);
      // #else
      // memset(((txGamePadData)rgd).uc_data, 0, SIZE_OF_GPADDATA_STRUCT);
      // #endif

      if( xWifiDataReceiveQ != 0 )
      {
        // Receive a message on the created queue.  Block for 10 ticks if a
        // message is not immediately available.
        if( xQueueReceive( xWifiDataReceiveQ, &( rgd ), ( TickType_t ) 10 ) )
        {

          // Steer loop
          // A queue can be used
          #if defined(USE_DATA_UNION)
          steer_loop(((txGamePadORMPUData*)&rgd)); // Not tested for USE_DATA_UNION macro switch
          #else
          steer_loop(((txGamePadData*)&rgd)); // Not tested for USE_DATA_UNION macro switch
          #endif
        }
      }

      #if defined(USE_DATA_UNION)

      memset(rgd.uc_data, 0, SIZE_OF_GPADMDATA_STRUCT);

      rgd.data.data.gd = DEFAULT_JOY_DATA; // { .x=0, .y=0, .hat=0, .twist=0, .buttons_a=0, .slider=0, .buttons_b=0 };
      rgd.data.data.mpu = data;
      rgd.data.data_type = DATATYPE_MPU;
      rgd.data.data_len = SIZE_OF_MDATA_STRUCT;

      if( xWifiDataSendQ != 0 )
      {
        /* Send an unsigned long.  Wait for 10 ticks for space to become
        available if necessary. */
        UBaseType_t whetherSpaceAvailable = uxQueueSpacesAvailable( xWifiDataSendQ );

        if( (UBaseType_t)(0) == whetherSpaceAvailable)
        {
          //xQueueOverwrite( xQueue, &ulVarToSend );
          if( xQueueReceive( xWifiDataSendQ, &( dummy ), ( TickType_t ) 10 ) )
          {

          }

          if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
          {
            Log.Warning(THIS"xWDSQ full MPU %d"CR, whetherSpaceAvailable);
          }

          if ( ( xSerialSemaphore ) != NULL )
          xSemaphoreGive( ( xSerialSemaphore ) );  // make the Serial Port available

        }

        if( xQueueSend( xWifiDataSendQ, ( void * ) &rgd, ( TickType_t ) 10 ) != pdPASS )
        {
          /* Failed to post the message, even after 10 ticks. */
        }
        else
        {

        }
      }
      #endif // defined(USE_DATA_UNION)


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
      Delay(TASK_LOOP_TIME, xLastWakeTime);
    }
    #else

    // else
    Delay(100);

    #endif // SKY_SYSTEM MPU/Joystick
  }

  void loop() {
    //return;
    int loglevel = 0;
    if (Serial.available())
    // Test
    {
      char inChar = (char)Serial.read();
      switch(inChar)
      {
        case 'V':
        {
          loglevel = LOG_LEVEL_VERBOSE;
        }break;
        case 'D':
        {
          loglevel = LOG_LEVEL_DEBUG;
        }break;

        case 'I':
        {
          loglevel = LOG_LEVEL_INFOS;
        }break;
        case 'W':
        {
          loglevel = LOG_LEVEL_WARNINGS;
        }break;
        case 'E':
        {
          loglevel = LOG_LEVEL_ERRORS;
        }break;
        case 'R': //be Careful
        {
          Log.Warning(THIS"SYSTEM_RESET in 1000 ms"CR);
          Delay(1000);
          resetFunc();
        }
        default:{}
      }

      Log.Reinit(loglevel);
      //state_machine(inChar);
    }

    //delay(1);
  }
