#include <Logging.h>
#include "data.h"
#include "ESP8266.h"

//ESP8266 wifi(Serial1, 115200);

#define THIS "WIFI: "

#define TCP_BASED_CONN


//#define LOG_OUTPUT_DEBUG            (0)
//#define LOG_OUTPUT_DEBUG_PREFIX     (1)

//#define logDebug(arg)\
//    do {\
//        if (LOG_OUTPUT_DEBUG)\
//        {\
//            if (LOG_OUTPUT_DEBUG_PREFIX)\
//            {\
//                Serial.print("[LOG Debug: ");\
//                /*Serial.print((const char*)__FILE__);*/\
//                /*Serial.print(",");*/\
//                Serial.print((unsigned int)__LINE__);\
//                Serial.print(",");\
//                Serial.print((const char*)__FUNCTION__);\
//                Serial.print("] ");\
//            }\
//            Serial.println(arg);\
//        }\
//    } while(0)

ESP8266 ESP8266_setup()//HardwareSerial serial)
{

static const char * SSID = "HHH7351HHH";
static const char * PASSWORD = "hh1537hhh";

static const char * PEER_IP_ADDRESS = "192.168.1.5"; // SKY_SYSTEM address

  ESP8266 wifi(Serial1, 115200);

  Log.Info(THIS"setup begins"CR);

  //    delay(1000);
  //    Serial1.print("AT+RST/n/r");
  //    delay(1000);

  Serial1.flush();
  while (Serial1.available())
    Serial1.read();

  if (wifi.restart())
  {
    Log.Info(THIS"wifi restarted"CR);
  }
  else
  {
    Log.Error(THIS"wifi restart"CR);
  }

Serial.print("VERSION: ");  
Serial.println(wifi.getVersion());
//  Log.Info(THIS"FW Version: %s"CR, wifi.getVersion()); // Not showing up ????


  Serial1.flush();
  while (Serial1.available())
    Serial1.read();

  if (wifi.setOprToStationSoftAP()) {
    Log.Info(THIS"to station + softap ok"CR);
  } else {
    Log.Error(THIS"to station + softap err"CR);
  }


  Serial1.flush();
  while (Serial1.available())
    Serial1.read();

  //if (wifi.joinAP(SSID, PASSWORD)) {
  if (wifi.joinAP("HHH7351HHH", "hh1537hhh")) {
    Log.Info(THIS"Join AP success, IP: %s"CR, wifi.getLocalIP().c_str());
  } else {
    Log.Error(THIS"Join AP failure"CR);
  }

  Serial1.flush();
  while (Serial1.available())
    Serial1.read();

  //#if defined(GROUND_SYSTEM)
  if (wifi.enableMUX()) {
    Log.Info(THIS"multiple ok"CR);
  } else {
    Log.Error(THIS"multiple err"CR);
  }
  //#else
  //  if (wifi.disableMUX()) {
  //    Log.Info(THIS"multiple ok"CR);
  //  } else {
  //    Log.Error(THIS"multiple err"CR);
  //  }
  //#endif

  Serial1.flush();
  while (Serial1.available())
    Serial1.read();

#if defined(SKY_SYSTEM)
  if (wifi.startTCPServer(8090))
  {
    Log.Info(THIS"start tcp/udp server/connection ok"CR);
  } else {
    Log.Error(THIS"start tcp/udp server/connection err : Check IP/Power"CR);
  }


  Serial1.flush();
  while (Serial1.available())
    Serial1.read();

  if (wifi.setTCPServerTimeout(10)) {
    Log.Info(THIS"set tcp server timout 10 seconds"CR);
  } else {
    Log.Error(THIS"set tcp server timout err"CR);
  }
#else

#endif


#if defined(SKY_SYSTEM)
  // Connect to a wifi unit
  // The wifi unit must send something to it

  uint8_t buffer[128] = {0};
  uint8_t mux_id;

  uint32_t len = wifi.recv(&mux_id, buffer, sizeof(buffer), 1000000);

  if (len > 0)
  {
    Log.Verbose(THIS"Status:[ %s ]"CR, wifi.getIPStatus().c_str() );

    Log.Verbose(THIS"Received from: %d [ ",  mux_id );

    for (uint32_t i = 0; i < len; i++)
    {
      Log.Verbose("%c ", (char)buffer[i]);
    }
    Log.Verbose(" (ASCII: %s)]"CR, buffer);
  }

#else //  ulta GROUND_SYSTEM or #if defined(SKY_SYSTEM)
  int retry = 10;
recreate:

  Serial1.flush();
  if (wifi.createTCP(0, PEER_IP_ADDRESS, 8090))
  {
    Log.Info(THIS"start tcp/udp server/connection ok"CR);
    //    const GamePadEventData_Simple joydata = joystick_loop();
    //    txGamePadData tgd;
    //    tgd.gd.gd = joydata;
    //    ESP8266_loop_send_Joystick_data(wifi, tgd);
    //txGamePadData data;
    //ESP8266_loop_send_Joystick_data(data);
  } else {
    retry--;
    Log.Error(THIS"start tcp/udp server/connection err : Check IP/Power retry %d"CR, retry);

    if (0 < retry)
    {
      delay(100);
      goto recreate;
    }
  }
#endif // GROUND_SYSTEM

  Log.Info(THIS"setup ends"CR);

  return wifi;
}


const txGamePadData ESP8266_loop_recv_joystick_data(ESP8266 _wifi)
{
  uint8_t buffer[SIZE_OF_GPADDATA_STRUCT] = {0};
  uint8_t mux_id = 0; // error prone
  txGamePadData gd;

  uint32_t len = _wifi.recv(/*&mux_id,*/ buffer, SIZE_OF_GPADDATA_STRUCT, 100);
  if (len > 0) {
    Log.Verbose(THIS"Status:[ %s ]"CR, _wifi.getIPStatus().c_str() );

    Log.Verbose(THIS"Received from: %d [ ",  mux_id );

    for (uint32_t i = 0; i < len; i++) {
      if (i < SIZE_OF_GPADDATA_STRUCT) // buffer safety
      {
        gd.uc_data[i] = buffer[i];
      }
      Log.Verbose("%c ", (char)buffer[i]);
    }
    Log.Verbose(" (ASCII: %s)]"CR, buffer);
  }

  return gd; // :P
}

const angle_val_raw_acc ESP8266_loop_recv_MPU_data(ESP8266 _wifi)
{
  uint8_t buffer[SIZE_OF_MDATA_STRUCT] = {0};
  uint8_t mux_id = 0; // error prone
  angle_val_raw_acc mdata;

  uint32_t len = _wifi.recv(/*&mux_id,*/ buffer, sizeof(buffer), 100);
  if (len > 0) {
    Log.Verbose(THIS"Status:[ %s ]"CR, _wifi.getIPStatus().c_str() );

    Log.Verbose(THIS"Received from: %d [ ",  mux_id );

    for (uint32_t i = 0; i < len; i++) {
      if (i < SIZE_OF_MDATA_STRUCT) // buffer safety
      {
        mdata.uc_data[i] = buffer[i];
      }
      Log.Verbose("%c ", (char)buffer[i]);
    }
    Log.Verbose("]"CR);
  }

  return mdata; // :P
}

//#error check from here run and check log
void ESP8266_loop_send_Joystick_data(ESP8266 _wifi, txGamePadData data)
{
  uint8_t buffer[SIZE_OF_GPADDATA_STRUCT] = {0};
  uint8_t mux_id = 0;

  data.gd.stx = 0x02;
  data.gd.header = 0xff;
  data.gd.data_len = (SIZE_OF_GPADDATA_STRUCT - 3);
  data.gd.data_type = 0x01;
  data.gd.res3 = 0x00;
  data.gd.etx = 0x03;

  if (_wifi.send(/*mux_id,*/0, data.uc_data, SIZE_OF_GPADDATA_STRUCT)) {
    Log.Info(THIS"send joystick data ok"CR);
  } else {
    Log.Error(THIS"send joystick data error"CR);
  }


  //  if (wifi.releaseTCP(0)) //mux_id
  //  {
  //    Log.Info(THIS"release tcp %d ok", mux_id);
  //  } else {
  //    Log.Error(THIS"release tcp %d err", mux_id);
  //  }

}


void ESP8266_loop_send_MPU_data(ESP8266 _wifi, angle_val_raw_acc data)
{

  uint8_t buffer[SIZE_OF_MDATA_STRUCT] = {0};
  uint8_t mux_id = 1;

  data.data.stx = 0x02;
  data.data.header = 0xff;
  data.data.data_len = (SIZE_OF_MDATA_STRUCT - 3);
  data.data.data_type = 0x02;
  data.data.res3 = 0x00;
  data.data.etx = 0x03;

  if (_wifi.send(/*mux_id,*/0, data.uc_data, SIZE_OF_MDATA_STRUCT)) {
    Log.Info(THIS"send MPU data ok"CR);
  } else {
    Log.Error(THIS"send MPU data error"CR);
  }

  //  if (wifi.releaseTCP(0)) //mux_id
  //  {
  //    Log.Info(THIS"release tcp %d ok", mux_id);
  //  } else {
  //    Log.Error(THIS"release tcp %d err", mux_id);
  //  }

  /*
    uint32_t len = wifi.recv(&mux_id, buffer, sizeof(buffer), 100);
    if (len > 0) {
      Serial.print("Status:[");
      Serial.print(wifi.getIPStatus().c_str());
      Serial.println("]");

      Serial.print("Received from :");
      Serial.print(mux_id);
      Serial.print("[");
      for (uint32_t i = 0; i < len; i++) {
        Serial.print((char)buffer[i]);
      }
      Serial.print("]\r\n");

      //        if(wifi.send(mux_id, buffer, len)) {
      //            Serial.print("send back ok\r\n");
      //        } else {
      //            Serial.print("send back err\r\n");
      //        }

      //        if (wifi.releaseTCP(mux_id)) {
      //            Serial.print("release tcp ");
      //            Serial.print(mux_id);
      //            Serial.println(" ok");
      //        } else {
      //            Serial.print("release tcp");
      //            Serial.print(mux_id);
      //            Serial.println(" err");
      //        }

      Serial.print("Status:[");
      Serial.print(wifi.getIPStatus().c_str());
      Serial.println("]");

    }*/
}

