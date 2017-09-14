#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "data.h"
#include "config.h"

#include "/home/rahuldeo/ATOM/ATOM_DRONE/ESP8266_D1/src/data2.h"
//#include "/home/rahuldeo/ATOM/ATOM_DRONE/ESP8266_D1/src/data.h"

debug_data data;
sGENERICSETPOINTS_t setpoints;


WiFiClient client;

char* PID_TUNE_TYPE_str[]=
{
  "PID_TUNE_TYPE_NONE",
  "PID_TUNE_TYPE_LEFT_RIGHT",
  "PID_TUNE_TYPE_FORE_BACK",
  "PID_TUNE_TYPE_UP_DOWN",
  "PID_TUNE_TYPE_TUNING_DONE",
  "PID_TUNE_TYPE_MAX"
};


#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
(byte & 0x80 ? '1' : '0'), \
(byte & 0x40 ? '1' : '0'), \
(byte & 0x20 ? '1' : '0'), \
(byte & 0x10 ? '1' : '0'), \
(byte & 0x08 ? '1' : '0'), \
(byte & 0x04 ? '1' : '0'), \
(byte & 0x02 ? '1' : '0'), \
(byte & 0x01 ? '1' : '0')

#define SHORT_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
#define SHORT_TO_BINARY(byte)  \
(byte & 0x8000 ? '1' : '0'), \
(byte & 0x4000 ? '1' : '0'), \
(byte & 0x2000 ? '1' : '0'), \
(byte & 0x1000 ? '1' : '0'), \
(byte & 0x0800 ? '1' : '0'), \
(byte & 0x0400 ? '1' : '0'), \
(byte & 0x0200 ? '1' : '0'), \
(byte & 0x0100 ? '1' : '0'), \
(byte & 0x0080 ? '1' : '0'), \
(byte & 0x0040 ? '1' : '0'), \
(byte & 0x0020 ? '1' : '0'), \
(byte & 0x0010 ? '1' : '0'), \
(byte & 0x0008 ? '1' : '0'), \
(byte & 0x0004 ? '1' : '0'), \
(byte & 0x0002 ? '1' : '0'), \
(byte & 0x0001 ? '1' : '0')

//WiFiUDP Udp;

IPAddress serverip(192,168,1,4);
const uint16_t serverPort = 11511;//11411;


unsigned int localUdpPort = 10000;
char incomingPacket[SIZE_OF_ALL_DATA] = {0};

void printdata(const debug_data *_data);

// #include <pb_arduino.h>
// #include <pb_encode.h>
//
// pb_ostream_s pb_out = as_pb_ostream(Udp);

void printgmpts(sGENERICSETPOINTS_t *setpoints)
{
  //return;
  Serial.printf("[ INFO] [%d.%d]: Sub Joy: x:%d, y:%d, z:%d, s:%d, b: " SHORT_TO_BINARY_PATTERN ", PIDMODE: %s", setpoints->timestampsec, setpoints->timestampnsec
  , setpoints->x, setpoints->y, setpoints->z, setpoints->s, SHORT_TO_BINARY(setpoints->buttons), PID_TUNE_TYPE_str[setpoints->pid_tune_type]);
  Serial.println();

}

void connectserver()
{
  const int httpPort = serverPort;

  if (!client.connect(/*"localhost"*/serverip, httpPort))
  {

    static uint32_t lastServerDisconTime = 0;
    if(system_get_time()-lastServerDisconTime >=(5000*1000))
    {
       lastServerDisconTime = system_get_time();
       Serial.println("connection failed reconnecting .. ");
    }
    //ESP.restart();
    //return;
  }
  else
  {
    Serial.println("connection ESTABLISHED");
  }
}

void wifi_setup()
{
  int retrycount = 10;
  Serial.printf("Connecting to %s ", WIFISSID);
  WiFi.begin(WIFISSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    if((--retrycount) == 0)
    {
      Serial.print("retry count exceeds 10 restarting ...");
      ESP.restart();
    }
  }
  Serial.println(" connected  ... connecting to server ... ");

  wifi_set_sleep_type(NONE_SLEEP_T);//LIGHT_SLEEP_T);

  client.setTimeout(500);
  connectserver();
  client.setNoDelay(true);
  client.setTimeout(50);
  //Udp.begin(localUdpPort);
  Serial.printf("IP %s\n", WiFi.localIP().toString().c_str());//, localUdpPort);

}

boolean wifi_loop(debug_data *all_data, sGENERICSETPOINTS_t *setpoints)
{
  boolean packet_received = false;

  if(!client.connected())
  {
    client.stop();
    connectserver();
    return false;
  }

  all_data->tune_type = PID_TUNE_TYPE_FORE_BACK;
  all_data->ppud.Kd = 23.23;
  //printdata(all_data);


  client.write((uint8_t*)all_data, SIZE_OF_ALL_DATA);
  //Serial.print("check "); Serial.println(__LINE__);


  while(client.available()) // if(client.available()) is crashing ???
  {
    //Serial.print("check "); Serial.println(__LINE__);

    //size_t s = client.peekBytes((uint8_t *)&setpoints, size_t SIZE_OF_GMSETPOINTS_DATA);
    //Serial.print("check "); Serial.println(__LINE__);
    int nc = client.read((uint8_t *) setpoints, (size_t) SIZE_OF_GMSETPOINTS_DATA);
    //if(SIZE_OF_GMSETPOINTS_DATA == nc)
    {
      packet_received = true;
    }
    //Serial.print("check "); Serial.println(__LINE__);
    //printgmpts(setpoints);
  }

  // int packetSize = Udp.parsePacket();
  // if (packetSize)
  // {
  //   // receive incoming UDP packets
  //   //Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
  //   int len = Udp.read(incomingPacket, 255);
  //   //sMOTIONSETPOINTS_t msetpts;
  //   memcpy(msetpts, incomingPacket, SIZE_OF_MSETPOINTS_DATA);
  //
  //   if (len > 0)
  //   {
  //     incomingPacket[len] = 0;
  //     packet_received = true;
  //   }
  //
  //   // Serial.printf("UDP packet contents: %s ", incomingPacket);
  //   // Serial.printf
  //   // ("UDP packet ts:%d x:%d y:%d h:%d tw:%d sl:%d b:%d"
  //   // ,msetpts->timestamp
  //   // ,msetpts->x
  //   // ,msetpts->y
  //   // ,msetpts->hat
  //   // ,msetpts->twist
  //   // //,msetpts.buttons_a
  //   // ,msetpts->slider
  //   // ,msetpts->buttons);
  //   //
  //   // Serial.printf("from: %s", Udp.remoteIP().toString().c_str());
  //   // Serial.printf(" : %d\n", Udp.remotePort());
  //
  //   // send back a reply, to the IP address and port we got the packet from
  //   Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
  //   //pb_encode(&pb_out,
  //   //pb_print_write(&pb_out,(all_data), SIZE_OF_ALL_DATA);
  //   //Udp.write((byte*)(mpudata), SIZE_OF_MPU_DATA);
  //   //Udp.write((byte*)(all_data), SIZE_OF_MPU_DATA);
  //   Udp.endPacket();
  // }
  return packet_received;

}

void printdata(const debug_data *_data)
{

  static uint32_t lastPrintAllDataTime = 0;
  if(system_get_time()-lastPrintAllDataTime >=(5000*1000))
  {
     lastPrintAllDataTime = system_get_time();

  }
  else
  {
    return;
  }

  // Serial.printf("d.mD.ax %d, ", _data->mpuData.AcX);
  // Serial.printf("d.mD.ay %d, ", _data->mpuData.AcY);
  // Serial.printf("d.mD.az %d, ", _data->mpuData.AcZ);
  // Serial.printf("d.mD.ts %d, ", _data->mpuData.timestamp);
  // Serial.printf("d.mD.Tmp %d, ", _data->mpuData.Tmp);
  // Serial.printf("d.mD.gx %d, ", _data->mpuData.GyX);
  // Serial.printf("d.mD.gy %d, ", _data->mpuData.GyY);
  // Serial.printf("d.mD.gz %d, ", _data->mpuData.GyZ);

  Serial.printf("d.mR.ax %d, ", _data->mpuRAW.AcX);
  Serial.printf("d.mR.ay %d, ", _data->mpuRAW.AcY);
  Serial.printf("d.mR.az %d, ", _data->mpuRAW.AcZ);
  Serial.printf("d.mR.ts %d, ", _data->mpuRAW.timestamp);
  Serial.printf("d.mR.Tmp %d, ", _data->mpuRAW.Tmp);
  Serial.printf("d.mR.gx %d, ", _data->mpuRAW.GyX);
  Serial.printf("d.mR.gy %d, ", _data->mpuRAW.GyY);
  Serial.printf("d.mR.gz %d, ", _data->mpuRAW.GyZ);

  Serial.printf("d.pgh ");
  Serial.print(_data->pingheight);
  Serial.printf(", ");

  Serial.printf("d.pidfb.I %d, ", (int)100* _data->ppfb.Input);
  Serial.printf("d.pidfb.Kd %d, ", (int)(100* _data->ppfb.Kd));
  Serial.printf("d.pidfb.Ki %d, ", (int)100* _data->ppfb.Ki);
  Serial.printf("d.pidfb.Kp %d, ", (int)100* _data->ppfb.Kp);
  Serial.printf("d.pidfb.O %d, ", (int)100* _data->ppfb.Output);
  Serial.printf("d.pidfb.S %d, ", (int)100* _data->ppfb.Setpoint);

  Serial.printf("d.pidlr.I %d, ", (int)100* _data->pplr.Input);
  Serial.printf("d.pidlr.Kd %d, ", (int)100* _data->pplr.Kd);
  Serial.printf("d.pidlr.Ki %d, ", (int)100* _data->pplr.Ki);
  Serial.printf("d.pidlr.Kp %d, ", (int)100* _data->pplr.Kp);
  Serial.printf("d.pidlr.O %d, ", (int)100* _data->pplr.Output);
  Serial.printf("d.pidlr.S %d, ", (int)100* _data->pplr.Setpoint);

  Serial.printf("d.pidud.I %d, ", (int)100* _data->ppud.Input);

  //Serial.printf("d.pidud.Kd %d, ", (int)100* _data->ppud.Kd);
  Serial.printf("d.pidud.Kd ");
  Serial.print(_data->ppud.Kd);
  Serial.printf(", ");

  Serial.printf("d.pidud.Ki %d, ", (int)100* _data->ppud.Ki);
  Serial.printf("d.pidud.Kp %d, ", (int)100* _data->ppud.Kp);
  Serial.printf("d.pidud.O %d, ", (int)100* _data->ppud.Output);
  Serial.printf("d.pidud.S %d, ", (int)100* _data->ppud.Setpoint);

  Serial.printf("d.yaw ");
  Serial.print(_data->yaw);
  Serial.printf(", ");
  //Serial.printf("d.yaw %d, ", (int)100* _data->yaw);
  Serial.printf("d.pitch ");
  Serial.print(_data->pitch);
  Serial.printf(", ");
  //Serial.printf("d.pitch %d, ", (int)100* _data->pitch);
  Serial.printf("d.roll ");
  Serial.print(_data->roll);
  Serial.printf(", ");
  //Serial.printf("d.roll %d, ", (int)100* _data->roll);

  Serial.printf("d.ts %d, ", _data->timestamp);
  Serial.printf("d.pidtt %d\n", _data->tune_type);
}
