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

// #include <pb_arduino.h>
// #include <pb_encode.h>
//
// pb_ostream_s pb_out = as_pb_ostream(Udp);

void printgmpts(sGENERICSETPOINTS_t *setpoints)
{
  //return;
  Serial.printf("[ INFO] [%d.%d]: Sub Joy: x:%d, y:%d, z:%d, s:%d b: " SHORT_TO_BINARY_PATTERN, setpoints->timestampsec, setpoints->timestampnsec
  , setpoints->x, setpoints->y, setpoints->z, setpoints->s, SHORT_TO_BINARY(setpoints->buttons));
  Serial.println();

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

  const int httpPort = serverPort;
  if (!client.connect(/*"localhost"*/serverip, httpPort)) {

    Serial.println("connection failed restart .. ");
    ESP.restart();
    return;
  }
  {
    Serial.println("connection ESTABLISHED");
  }

  //Udp.begin(localUdpPort);
  //Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);

}

boolean wifi_loop(debug_data *all_data, sGENERICSETPOINTS_t *setpoints)
{
  boolean packet_received = false;

  client.write((uint8_t*)&all_data, SIZE_OF_ALL_DATA);
  //Serial.print("check "); Serial.println(__LINE__);


  while(client.available()) // if(client.available()) is crashing ???
  {
    //Serial.print("check "); Serial.println(__LINE__);

    //size_t s = client.peekBytes((uint8_t *)&setpoints, size_t SIZE_OF_GMSETPOINTS_DATA);
    //Serial.print("check "); Serial.println(__LINE__);
    int nc = client.read((uint8_t *) setpoints, (size_t) SIZE_OF_GMSETPOINTS_DATA);
    if(SIZE_OF_GMSETPOINTS_DATA == nc)
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
