#include <Servo.h>


#define MAX_THROTTLE (1864)
#define MIN_THROTTLE (1064)
#define ZERO_THROTTLE (0)
#define TEST_THROTTLE (1100)
int throttle = TEST_THROTTLE;

#define INCREMENT (50)

// non working : Send A(1500) B(1064) then A(1500) : Stops in fraction of a second
// working : Send A(1500) B(1064) then D(1400)

// https://hobbyking.com/media/file/391175338X260742X34.pdf
Servo ESC;

void setup() {
  // put your setup code here, to run once:
  ESC.attach(9);
  Serial.begin(250000);
  Serial.println("Hello");
  //ESC.writeMicroseconds(1500);
  //delay(5000);
  //ESC.writeMicroseconds(0);
  //delay(100);
  //ESC.writeMicroseconds(1400);
  //delay(5000);
  //ESC.writeMicroseconds(0);
  Serial.println("Done");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    char inChar = (char)Serial.read();
    switch (inChar)
    {
      case 'A' :
        {
          ESC.writeMicroseconds(MAX_THROTTLE);
          Serial.println("MAX_Throttle");
        } break;
      case 'B' :
        {
          ESC.writeMicroseconds(MIN_THROTTLE);
          Serial.println("MIN_Throttle");
        } break;
      case 'C' :
        {
          ESC.writeMicroseconds(ZERO_THROTTLE);
          Serial.println("Zero_Throttle");
        } break;
      case 'D' :
        {
          ESC.writeMicroseconds(TEST_THROTTLE);
          Serial.println("Test_Throttle");
          throttle = TEST_THROTTLE;
        } break;
      case '+' :
        {
          throttle += INCREMENT;
          throttle = throttle < MAX_THROTTLE ? throttle : MAX_THROTTLE;
          ESC.writeMicroseconds(throttle);
          Serial.print("Throttle+ = ");
          Serial.println(throttle);
        } break;
      case '-' :
        {
          throttle -= INCREMENT;
          throttle = throttle > ZERO_THROTTLE ? throttle : ZERO_THROTTLE;
          ESC.writeMicroseconds(throttle);
          Serial.print("Throttle- = ");
          Serial.println(throttle);
        } break;

      default :
        {
          ESC.writeMicroseconds(0);
          Serial.println("Default_Throttle");
        } break;

    }
  }
}
