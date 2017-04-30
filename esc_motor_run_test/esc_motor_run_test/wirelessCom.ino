#include <Arduino.h>

#include <Logging.h>
#include "data.h"

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define THIS "WIFI: " TOSTRING(__LINE__) ": "

#define SSID        "D_ATOM_1" //"HHH7351HHH"
#define PASSWORD    "D_ATOM_1"

//#define SSID        "HHH7501HHH"
//#define PASSWORD    "hh1057hhh"

#define PEER_IP_ADDRESS "192.168.4.1" // SKY_SYSTEM address
#define PEER_PORT (8090)
#define WIFI_CMD_MODE_PIN (0)
#define WIFICOM (&Serial1)


static char buffer[32];

/**
* [selectCommandMode To select pin to change between transparent or cmd mode]
* @param _cmdMode [description]
*/
void selectCommandMode(int _cmdMode)
{
  if(0==_cmdMode) // select transparent mode
  {
    digitalWrite(WIFI_CMD_MODE_PIN, HIGH); // CMD mode
    delay(150); // 100 requires but keeping 50 ms extra for co-operative tasking overheads in ESP8266 custom firmware.
  }
  else if(1==_cmdMode) // select transparent mode
  {
    digitalWrite(WIFI_CMD_MODE_PIN, LOW); // CMD mode
    delay(150); // 100 requires but keeping 50 ms extra for co-operative tasking overheads in ESP8266 custom firmware.
  }
  else
  {
    Log.Error(THIS"wifi invalid data mode"CR);
  }
}

/**
* [wifi_setup setup wifi]
* @param _mode [setup mode]
*/
void wifi_setup()//int _mode)
{
  pinMode(WIFI_CMD_MODE_PIN, OUTPUT);
  digitalWrite(WIFI_CMD_MODE_PIN, HIGH); // Switch to command mode

  WIFICOM->begin(115200);

  // AT+RST
  if (0 == wifi_reset()) // no error
  {
    Log.Info(THIS"wifi restarted"CR);
  }
  else
  {
    Log.Error(THIS"wifi restart"CR);
    Log.Info(THIS"Please reset the controller"CR);
  }

  //delay(200);

  // AT
  if (0 == wifi_check())
  {
    Log.Info(THIS"wifi functional"CR);
  }
  else
  {
    Log.Error(THIS"wifi check"CR);
    Log.Info(THIS"Please check for delay and/or implementation"CR);
  }

  // AT+START 0 / 1
  //
  #if (defined(SKY_SYSTEM) )

  if (0 == wifi_set_mode(0)) //
  {
    Log.Info(THIS"wifi mode set"CR);
  }
  else
  {
    Log.Error(THIS"wifi mode"CR);
    Log.Info(THIS"Please check for delay and/or implementation"CR);
  }

  // AT+SRIPP IP1.IP2.IP3.IP4 PORTT
  if (0 == wifi_set_remote_IP_PORT())
  {
    Log.Info(THIS"wifi remote ip port set"CR);
  }
  else
  {
    Log.Error(THIS"wifi remote ip port"CR);
    Log.Info(THIS"Please check for delay and/or implementation"CR);
  }

  #elif ( defined(GROUND_SYSTEM) )

  if (0 == wifi_set_mode(1)) //
  {
    Log.Info(THIS"wifi mode set"CR);
  }
  else
  {
    Log.Error(THIS"wifi mode"CR);
    Log.Info(THIS"Please check for delay and/or implementation"CR);
  }

  #else

  #error no system mode selected

  #endif



}


/**
* [wifi_loop_send_Joystick_data keep sending data]
* @param  data [txGamePadData type]
* @return      [whether wifi module forwarded the data]
*/
int wifi_loop_send_Joystick_data(txGamePadData * data)
{
  int ret = -1;
  //  uint8_t mux_id = 0;
  //
  data->gd.stx = 0x02;
  data->gd.header = 0xff;
  data->gd.data_len = (SIZE_OF_GPADDATA_STRUCT - 3);
  data->gd.data_type = 0x01;
  data->gd.res3 = 0x00;
  data->gd.etx = 0x03;

  WIFICOM->write(data->uc_data, SIZE_OF_GPADDATA_STRUCT);;

  while (WIFICOM->available())
  {
    if (0 < readline(WIFICOM->read(), buffer, 32))
    {
      ret = ( NULL != strstr(buffer, "+sent") );
      if(0!=ret)
      {
        // all fine
      }
    }
  }
  return (1 == ret ? 0 : -1);
}

/**
* [wifi_loop_recv_joystick_data keep recieving data]
* @param  gd [data to update]
* @return    [whether data was valid]
*/
int wifi_loop_recv_joystick_data(txGamePadData * gd)
{
  int ret = -1;
  int recvlen = 0;
  int i=0;

  do
  {
    recvlen = WIFICOM->available();

    if(0<recvlen)
    {

      ret &= recvlen == (SIZE_OF_GPADDATA_STRUCT - 3);

      Serial.readBytes(gd->uc_data, recvlen > SIZE_OF_GPADDATA_STRUCT ? SIZE_OF_GPADDATA_STRUCT : recvlen);

      // Validate

      ret &= gd->gd.stx == 0x02 &&
      gd->gd.header == 0xFF &&
      gd->gd.data_len == (SIZE_OF_GPADDATA_STRUCT - 3);
      gd->gd.data_type == 0x01 &&
      gd->gd.res3 == 0x00 &&
      gd->gd.etx == 0x03;

      for ( i = 0; i < recvlen; i++)
      {
        Log.Verbose("%c ", (char)gd->uc_data[i]);
      }
      Log.Verbose(" (ASCII: %s)]"CR, gd->uc_data);

      ret &= (recvlen == SIZE_OF_GPADDATA_STRUCT);
    }

  } while(recvlen);

  return (1 == ret ? 0 : -1);

}


/**
* [wifi_reset reset the wifi module]
* @return [confirm whether wifi module is reset]
*/
int wifi_reset()
{

  int ret = 0;
  selectCommandMode(1); //digitalWrite(WIFI_CMD_MODE_PIN, LOW); // CMD mode
  WIFICOM->println("AT+RST");

  while (WIFICOM->available())
  {
    if (0 < readline(WIFICOM->read(), buffer, 32))
    {
      ret = ( NULL != strstr(buffer, "OK") );
      if(0!=ret)
      {
        // getout of mode or else ESP8266 will go into bootloader mode.
        // within 100 ms
        // Here it is done instantly
        selectCommandMode(0); // digitalWrite(WIFI_CMD_MODE_PIN, HIGH); // CMD mode
        break;
      }
      else
      {
        Log.Error(THIS"wifi implementation %s %d"CR, __func__, __LINE__);
      }
    }
  }

  memset(buffer, 0, 32);

  delay(100); // For reset to take effect // use rtos delay
  selectCommandMode(1); // digitalWrite(WIFI_CMD_MODE_PIN, LOW); // CMD mode

  while (WIFICOM->available())
  {
    if (0 < readline(WIFICOM->read(), buffer, 32))
    {
      ret &= ( NULL != strstr(buffer, "Initialized") );
      break;
    }
  }

  selectCommandMode(0); //digitalWrite(WIFI_CMD_MODE_PIN, HIGH); // Back in transparent mode

  return (1 == ret ? 0 : -1);

}

/**
* [wifi_set_server_mode set server mode]
* @param  _mode [whether to set wifi module in ap or station mode]
* @return       [return whether expected mode is selected]
*/
int wifi_set_remote_IP_PORT()
{

  int ret = 0;

  selectCommandMode(1); // digitalWrite(WIFI_CMD_MODE_PIN, LOW); // Switch to command mode

  memset(buffer, 0, 32);
  sprintf(buffer, "AT+SRIPP %s %d", PEER_IP_ADDRESS, PEER_PORT); // check just filling up the buffer

  WIFICOM->println(buffer);

  memset(buffer, 0, 32);

  while (WIFICOM->available())
  {
    if (0 < readline(WIFICOM->read(), buffer, 32))
    {
      break;
      // This line will contain the IP1.IP2.IP3.IP4 PORTT/r/n ignore it for now
    }
  }

  memset(buffer, 0, 32);

  while (WIFICOM->available())
  {
    if (0 < readline(WIFICOM->read(), buffer, 32))
    {
      ret = ( NULL != strstr(buffer, "OK") );
      break;
    }
  }

  selectCommandMode(0); // digitalWrite(WIFI_CMD_MODE_PIN, HIGH); // Back in transparent mode

  return (1 == ret ? 0 : -1);
}

/**
* [wifi_check send AT]
* @return [return 0 if all fine -1 otherwise]
*/
int wifi_check()
{
  int ret = 0;
  selectCommandMode(1); // digitalWrite(WIFI_CMD_MODE_PIN, LOW); // CMD mode
  WIFICOM->println("AT");

  while (WIFICOM->available())
  {
    if (0 < readline(WIFICOM->read(), buffer, 32))
    {
      ret = ( NULL != strstr(buffer, "OK") );
      break;
    }
  }

  selectCommandMode(0); // digitalWrite(WIFI_CMD_MODE_PIN, HIGH); // CMD mode

  return (1 == ret ? 0 : -1);

}

/**
* /**
* [wifi_set_mode to start the wifi module in ap or station mode]
* AT+START 0 AP mode
* AT+START 1 STA mdoe
* [wifi_set_mode description]
* @param  _mode [0 or 1]
* @return       [return 0 if all fine -1 otherwise]
*
* OK
* IP
* IP
* ready
*
*/
int wifi_set_mode(int _mode)
{
  int ret = 0;
  selectCommandMode(1); // digitalWrite(WIFI_CMD_MODE_PIN, LOW); // CMD mode
  memset(buffer, 0, 32);
  sprintf(buffer, "AT+START %d", _mode); // check just filling up the buffer

  WIFICOM->println(buffer);

  memset(buffer, 0, 32);

  while (WIFICOM->available())
  {
    if (0 < readline(WIFICOM->read(), buffer, 32))
    {
      ret = ( NULL != strstr(buffer, "OK") );
      break;
    }
  }

  memset(buffer, 0, 32);

  while (WIFICOM->available())
  {
    if (0 < readline(WIFICOM->read(), buffer, 32))
    {
      Log.Verbose(THIS"wifi implementation %s %d : %s"CR, __func__, __LINE__, buffer);
      break;
      // This line will contain the IP1.IP2.IP3.IP4/r/n ignore it for now
    }
    else
    {
      Log.Error(THIS"wifi implementation %s %d : %s"CR, __func__, __LINE__, buffer);
    }
  }

  memset(buffer, 0, 32);

  while (WIFICOM->available())
  {
    if (0 < readline(WIFICOM->read(), buffer, 32))
    {
      Log.Verbose(THIS"wifi implementation %s %d : %s"CR, __func__, __LINE__, buffer);
      break;
      // This line will contain the IP1.IP2.IP3.IP4/r/n ignore it for now
    }
    else
    {
      Log.Error(THIS"wifi implementation %s %d : %s"CR, __func__, __LINE__, buffer);
    }
  }

  memset(buffer, 0, 32);

  while (WIFICOM->available())
  {
    if (0 < readline(WIFICOM->read(), buffer, 32))
    {
      ret = ( NULL != strstr(buffer, "ready") );
      break;
    }
  }

  selectCommandMode(0); // digitalWrite(WIFI_CMD_MODE_PIN, HIGH); // CMD mode

  return (1 == ret ? 0 : -1);
}


/**
* [readline read till new line]
* @param  readch [the char read by serial.read()]
* @param  buffer [buffer for chars to save]
* @param  len    [max len out]
* @return        [return len read]
*/
inline int readline(int readch, char *buffer, int len)
{
  static int pos = 0;
  int rpos;

  if (readch > 0) {
    switch (readch) {
      case '\n': // Ignore new-lines
      break;
      case '\r': // Return on CR
      rpos = pos;
      pos = 0;  // Reset position index ready for next time
      return rpos;
      default:
      if (pos < len - 1) {
        buffer[pos++] = readch;
        buffer[pos] = 0;
      }
    }
  }
  // No end of line has been found, so return -1.
  return -1;
}
