


#include <NewPingESP8266.h>

#define TRIGGER_PIN  D4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     D3  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPingESP8266 sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPingESP8266 setup of pins and maximum distance.

unsigned long ping_loop() {
  // delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  // Serial.print("Ping: ");
  // Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  // Serial.println("cm");
  return sonar.ping_cm();
}