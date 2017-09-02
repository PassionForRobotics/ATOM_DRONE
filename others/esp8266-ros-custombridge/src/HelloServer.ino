
#include <ESP8266WiFi.h>
//#include <ros.h>
//#include <std_msgs/String.h>

#include <PID_v1.h>
#include <PID_AutoTune_v0.h>

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


// ros::NodeHandle nh;
// // Make a chatter publisher
// std_msgs::String str_msg;
// ros::Publisher chatter("chatter", &str_msg);

//////////////////////
// WiFi Definitions //
//////////////////////
const char* ssid = "HHH7351HHH";
const char* password = "hh1537hhh";

IPAddress serverip(192,168,1,4);
const uint16_t serverPort = 11511;//11411;

// Be polite and say hello
//char hello[13] = "hello world!";

// void initROS()
// {//192.168.1.4
//
//   nh.getHardware()->setConnection(serverip, serverPort);
//   Serial.print("Initialization : ");
//   Serial.println(
//   nh.initNode()
//   );
//
//   // Another way to get IP
//   Serial.print("IP = ");
//   Serial.println(nh.getHardware()->getLocalIP());
//
//   // Start to be polite
//   nh.advertise(chatter);
//
// }

// void loopROS()
// {
//   if (nh.connected()) {
//     Serial.print("Connected ");
//     // Say hello
//     str_msg.data = hello;
//     int err = chatter.publish( &str_msg );
//     Serial.println(err);
//   } else {
//     Serial.println("Not Connected");
//   }
//   nh.spinOnce();
//   // Loop exproximativly at 1Hz
//   delay(500);
// }

void setup(void){
  //pinMode(led, OUTPUT);
  //digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // if (mdns.begin("esp8266", WiFi.localIP())) {
  //   Serial.println("MDNS responder started");
  // }

  // server.on("/", handleRoot);
  //
  // server.on("/inline", [](){
  //   server.send(200, "text/plain", "this works as well");
  // });
  //
  // server.onNotFound(handleNotFound);
  //
  // server.begin();
  // Serial.println("HTTP server started");

  // ros
  //
  //

  //initROS();
  //

 const int httpPort = serverPort;
 if (!client.connect(/*"localhost"*/serverip, httpPort)) {
   Serial.println("connection failed");
   return;
 }


 data.mpuData.AcX = 0;
 data.mpuData.AcY = 0;
 data.mpuData.AcZ = 0;
 data.mpuData.timestamp = 0;
 data.mpuData.Tmp = 0;
 data.mpuData.GyX = 0;
 data.mpuData.GyY = 0;
 data.mpuData.GyZ = 0;

 data.mpuRAW.AcX = 0;
 data.mpuRAW.AcY = 0;
 data.mpuRAW.AcZ = 0;
 data.mpuRAW.timestamp = 0;
 data.mpuRAW.Tmp = 0;
 data.mpuRAW.GyX = 0;
 data.mpuRAW.GyY = 0;
 data.mpuRAW.GyZ = 0;

 data.pingheight = 0;

 data.pitch = 0;

 data.ppfb.Input = 0;
 data.ppfb.Kd = 0;
 data.ppfb.Ki = 0;
 data.ppfb.Kp = 0;
 data.ppfb.Output = 0;
 data.ppfb.Setpoint = 0;

 data.pplr.Input = 0;
 data.pplr.Kd = 0;
 data.pplr.Ki = 0;
 data.pplr.Kp = 0;
 data.pplr.Output = 0;
 data.pplr.Setpoint = 0;

 data.ppud.Input = 0;
 data.ppud.Kd = 0;
 data.ppud.Ki = 0;
 data.ppud.Kp = 0;
 data.ppud.Output = 0;
 data.ppud.Setpoint = 0;

 data.yaw = 0;
 data.pitch = 0;
 data.roll = 0;

 data.timestamp = 0;
 data.tune_type = PID_TUNE_TYPE_NONE;

 //client.print("Test");


}


void datainc(debug_data *_data)
{
  static byte b = 1;
  _data->mpuData.AcX = b++;
  _data->mpuData.AcY = b++;
  _data->mpuData.AcZ = b++;
  _data->mpuData.timestamp = b++;
  _data->mpuData.Tmp = b++;
  _data->mpuData.GyX = b++;
  _data->mpuData.GyY = b++;
  _data->mpuData.GyZ = b++;

  _data->mpuRAW.AcX = b++;
  _data->mpuRAW.AcY = b++;
  _data->mpuRAW.AcZ = b++;
  _data->mpuRAW.timestamp = b++;
  _data->mpuRAW.Tmp = b++;
  _data->mpuRAW.GyX = b++;
  _data->mpuRAW.GyY = b++;
  _data->mpuRAW.GyZ = b++;

  _data->pingheight = b++;

  _data->pitch = b++;

  _data->ppfb.Input = b++;
  _data->ppfb.Kd = b++;
  _data->ppfb.Ki = b++;
  _data->ppfb.Kp = b++;
  _data->ppfb.Output = b++;
  _data->ppfb.Setpoint = b++;

  _data->pplr.Input = b++;
  _data->pplr.Kd = b++;
  _data->pplr.Ki = b++;
  _data->pplr.Kp = b++;
  _data->pplr.Output = b++;
  _data->pplr.Setpoint = b++;

  _data->ppud.Input = b++;
  _data->ppud.Kd = b++;
  _data->ppud.Ki = b++;
  _data->ppud.Kp = b++;
  _data->ppud.Output = b++;
  _data->ppud.Setpoint = b++;

  _data->yaw = b++;
  _data->pitch = b++;
  _data->roll = b++;

  _data->timestamp = b++;
  _data->tune_type = PID_TUNE_TYPE_NONE;
}


void printgmpts(sGENERICSETPOINTS_t *setpoints)
{
  Serial.printf("[ INFO] [%d.%d]: Sub Joy: x:%d, y:%d, z:%d, s:%d b: " SHORT_TO_BINARY_PATTERN, setpoints->timestampsec, setpoints->timestampnsec
  , setpoints->x, setpoints->y, setpoints->z, setpoints->s, SHORT_TO_BINARY(setpoints->buttons));
  Serial.println();

}

int cntr = 0;
void loop(void){
  //server.handleClient();
  //loopROS();
  //
  String txt = "Test"+String(cntr++);
  datainc(&data);
  client.write((uint8_t*)&data, SIZE_OF_ALL_DATA);

  // unsigned long timeout = millis();
  // while (client.available() == 0) {
  //   if (millis() - timeout > 5000) {
  //     Serial.println(">>> Client Timeout !");
  //     //client.stop();
  //     return;
  //   }
  // }

  // Read all the lines of the reply from server and print them to Serial
  if(client.available()){

    int line = client.read((uint8_t *) &setpoints, (size_t) SIZE_OF_GMSETPOINTS_DATA);
    printgmpts(&setpoints);
  }

  delay(10);
}
