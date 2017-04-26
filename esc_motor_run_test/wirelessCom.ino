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

#define WIFI_CMD_MODE_PIN (0);

#define WIFICOM (&Serial1)

void wifi_setup()
{
  pinMode(WIFI_CMD_MODE_PIN, OUTPUT);
  digitalWrite(WIFI_CMD_MODE_PIN, HIGH);

  WIFICOM.begin(115200);

  if (0==wifi_reset()) // no error
  {
    Log.Info(THIS"wifi restarted"CR);
  }
  else
  {
    Log.Error(THIS"wifi restart"CR);
  }


}

int wifi_reset()
{

  static char buffer[32];
  int ret = 0;
  digitalWrite(WIFI_CMD_MODE_PIN, LOW); // CMD mode
  WIFICOM.println("AT+RST");

  while (WIFICOM.available())
  {
    if (0 < readline(WIFICOM.read(), buffer, 32))
    {
      ret = ( NULL != strstr(buffer, "OK") );
    }
  }

  memset(buffer, 0, 32);

  delay(100); // use rtos delay

  while (WIFICOM.available())
  {
    if (0 < readline(WIFICOM.read(), buffer, 32))
    {
      ret &= ( NULL != strstr(buffer, "ready") );
    }
  }

  return (1 == ret ? 0 : -1);

}

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

