#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "data.h"
#include "config.h"


WiFiUDP Udp;

unsigned int localUdpPort = 10000;
char incomingPacket[255] = {0};

void wifi_setup()
{

  Serial.printf("Connecting to %s ", WIFISSID);
  WiFi.begin(WIFISSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);

}

boolean wifi_loop(sMPUDATA_t *mpudata, sMOTIONSETPOINTS_t *msetpts)
{
  boolean packet_received = false;
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    // receive incoming UDP packets
    //Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);
    //sMOTIONSETPOINTS_t msetpts;
    memcpy(msetpts, incomingPacket, SIZE_OF_MSETPOINTS_DATA);

    if (len > 0)
    {
      incomingPacket[len] = 0;
      packet_received = true;
    }

    // Serial.printf("UDP packet contents: %s ", incomingPacket);
    // Serial.printf
    // ("UDP packet ts:%d x:%d y:%d h:%d tw:%d sl:%d b:%d"
    // ,msetpts->timestamp
    // ,msetpts->x
    // ,msetpts->y
    // ,msetpts->hat
    // ,msetpts->twist
    // //,msetpts.buttons_a
    // ,msetpts->slider
    // ,msetpts->buttons);
    //
    // Serial.printf("from: %s", Udp.remoteIP().toString().c_str());
    // Serial.printf(" : %d\n", Udp.remotePort());

    // send back a reply, to the IP address and port we got the packet from
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write((byte*)(mpudata), SIZE_OF_MPU_DATA);
    Udp.endPacket();
  }
  return packet_received;

}
