#include <Logging.h>
#include "data.h"
#include "ESP8266.h"

#define SSID        "HHH7351HHH"
#define PASSWORD    "hh1537hhh"

ESP8266 wifi(Serial1, 115200);

#define THIS "WIFI: "

void ESP8266_setup(void)
{
  Log.Info(THIS"setup begins"CR);

  //    delay(1000);
  //    Serial1.print("AT+RST/n/r");
  //    delay(1000);

  Log.Info(THIS"FW Version: %s"CR, wifi.getVersion().c_str()); // Not showing up ????


  if (wifi.setOprToStationSoftAP()) {
    Log.Info(THIS"to station + softap ok"CR);
  } else {
    Log.Error(THIS"to station + softap err"CR);
  }

  if (wifi.joinAP(SSID, PASSWORD)) {
    Log.Info(THIS"Join AP success, IP: %s"CR, wifi.getLocalIP().c_str());
  } else {
    Log.Error(THIS"Join AP failure"CR);
  }

  if (wifi.enableMUX()) {
    Log.Info(THIS"multiple ok"CR);
  } else {
    Log.Error(THIS"multiple err"CR);
  }

  if (wifi.startTCPServer(8090)) {
    Log.Info(THIS"start tcp server ok"CR);
  } else {
    Log.Error(THIS"start tcp server err"CR);
  }

  if (wifi.setTCPServerTimeout(10)) {
    Log.Info(THIS"set tcp server timout 10 seconds"CR);
  } else {
    Log.Error(THIS"set tcp server timout err"CR);
  }

  // Connect to a wifi unit

  Log.Error(THIS"It needs to connect here to a client/server IMP"CR);

  //

  Log.Info(THIS"setup ends"CR);
}

const GamePadEventData ESP8266_loop_recv_joystick_data()
{
  uint8_t buffer[128] = {0};
  uint8_t mux_id;
  txGamePadData gd;

  uint32_t len = wifi.recv(&mux_id, buffer, sizeof(buffer), 100);
  if (len > 0) {
    Log.Verbose(THIS"Status:[ %s ]", wifi.getIPStatus().c_str() );

    Log.Verbose(THIS"Received from: %d [ ",  mux_id );

    for (uint32_t i = 0; i < len; i++) {
      if (i < SIZE_OF_GPADDATA_STRUCT) // buffer safety
      {
        gd.uc_data[i] = buffer[i];
      }
      Log.Verbose("%c ", (char)buffer[i]);
    }
    Log.Verbose("]"CR);
  }

  return gd.gd.gd; // :P
}

const angle_val_raw_acc ESP8266_loop_recv_MPU_data()
{
  uint8_t buffer[SIZE_OF_MDATA_STRUCT] = {0};
  uint8_t mux_id;
  angle_val_raw_acc mdata;

  uint32_t len = wifi.recv(&mux_id, buffer, sizeof(buffer), 100);
  if (len > 0) {
    Log.Verbose(THIS"Status:[ %s ]", wifi.getIPStatus().c_str() );

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

void ESP8266_loop_send_Joystick_data(txGamePadData data)
{
  uint8_t buffer[SIZE_OF_GPADDATA_STRUCT] = {0};
  uint8_t mux_id;

  data.gd.stx = 0x02;
  data.gd.header = 0xff;
  data.gd.data_len = (SIZE_OF_GPADDATA_STRUCT - 3);
  data.gd.data_type = 0x01;
  data.gd.res3 = 0x00;
  data.gd.etx = 0x03;

  if (wifi.send(mux_id, data.uc_data, SIZE_OF_GPADDATA_STRUCT)) {
    Log.Info(THIS"send joystick data ok"CR);
  } else {
    Log.Error(THIS"send joystick data error"CR);
  }
}


void ESP8266_loop_send_MPU_data(angle_val_raw_acc data)
{

  uint8_t buffer[SIZE_OF_MDATA_STRUCT] = {0};
  uint8_t mux_id;

  data.data.stx = 0x02;
  data.data.header = 0xff;
  data.data.data_len = (SIZE_OF_MDATA_STRUCT - 3);
  data.data.data_type = 0x02;
  data.data.res3 = 0x00;
  data.data.etx = 0x03;

  if (wifi.send(mux_id, data.uc_data, SIZE_OF_MDATA_STRUCT)) {
    Log.Info(THIS"send MPU data ok"CR);
  } else {
    Log.Error(THIS"send MPU data error"CR);
  }

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

