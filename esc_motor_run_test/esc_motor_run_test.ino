
#include "data.h"
#include <Servo.h>

Servo servo[4];  // create servo object to control a servo
int pins[4] = {2, 3, 4, 5};
int i = 0;

#define MAX_THROTTLE (2000) //(1864)
#define MIN_THROTTLE (1064)
#define ZERO_THROTTLE (0)
#define TEST_THROTTLE (1100)
int throttle = TEST_THROTTLE;

#define INCREMENT (50)

// non working : Send A(1500) B(1064) then A(1500) : Stops in fraction of a second
// working : Send A(1500) B(1064) then D(1400)

// https://hobbyking.com/media/file/391175338X260742X34.pdf
Servo ESC;

void servo_init()
{
  for (i = 0 ; i < 4 ; i++)
  {
    servo[i].attach(pins[i]);
    servo[i].write(90);
  }
}

void setup() {
  // put your setup code here, to run once:
  ESC.attach(9);
  Serial.begin(115200);
  Serial.println("Hello");
  //ESC.writeMicroseconds(1500);
  //delay(5000);
  //ESC.writeMicroseconds(0);
  //delay(100);
  //ESC.writeMicroseconds(1400);
  //delay(5000);
  //ESC.writeMicroseconds(0);
  Serial.println("Done");

  mpu_setup();
  servo_init();

  delay(100);


}

void state_machine(char in);

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    char inChar = (char)Serial.read();
    state_machine(inChar);
  }

  true_angle_val_raw_acc data = mpu_loop(); // Must update here too
#define SERIAL Serial
  SERIAL.print(data.x_angle, 2); SERIAL.print(",");
  SERIAL.print(data.y_angle, 2); SERIAL.print(",");
  SERIAL.print(data.z_angle, 2); SERIAL.print(",");
  SERIAL.print(data.x_unfiltered_acc, 2); SERIAL.print(",");
  SERIAL.print(data.y_unfiltered_acc, 2); SERIAL.print(",");
  SERIAL.println(data.z_unfiltered_acc, 2);

  if (
    (abs(data.x_angle) < 10 )
    &&
    (abs(data.y_angle) < 10 )
  )
  {
    servo[0].write(data.x_angle + 90);
    servo[1].write(data.y_angle + 90);
    servo[2].write(data.x_angle + 90);
    servo[3].write(data.y_angle + 90);
  }
  delay(10);
}

void state_machine(char inChar)
{

  switch (inChar)
  {
    case 'A' :
      {
        ESC.writeMicroseconds(MAX_THROTTLE);
        Serial.println(" MAX_Throttle");
      } break;
    case 'B' :
      {
        ESC.writeMicroseconds(MIN_THROTTLE);
        Serial.println(" MIN_Throttle");
      } break;
    case 'C' :
      {
        ESC.writeMicroseconds(ZERO_THROTTLE);
        Serial.println(" Zero_Throttle");
      } break;
    case 'D' :
      {
        ESC.writeMicroseconds(TEST_THROTTLE);
        Serial.println(" Test_Throttle");
        throttle = TEST_THROTTLE;
      } break;
    case '+' :
      {
        throttle += INCREMENT;
        throttle = throttle < MAX_THROTTLE ? throttle : MAX_THROTTLE;
        ESC.writeMicroseconds(throttle);
        Serial.print(" Throttle+ = ");
        Serial.println(throttle);
      } break;
    case '-' :
      {
        throttle -= INCREMENT;
        throttle = throttle > ZERO_THROTTLE ? throttle : ZERO_THROTTLE;
        ESC.writeMicroseconds(throttle);
        Serial.print(" Throttle- = ");
        Serial.println(throttle);
      } break;

    case 'S':
      {
        Serial.println("Running sequence ... ");
        state_machine('A');
        delay(400);
        state_machine('B');
        delay(200);
        state_machine('D');
        Serial.println("Ready for throttle...");
      } break;

    case 'R':
      {
        Serial.println("Auto Throttle ... ");

        int i = 0;
        for (i = 0; i < 20; i++)
        {
          state_machine('+');
          delay(300);
        }

        delay(5000);

        for ( i = 0; i < 20; i++)
        {
          state_machine('-');
          delay(100);
        }

        state_machine('C');
        Serial.println("Throttle disarmed...");
      } break;


    default :
      {
        ESC.writeMicroseconds(0);
        Serial.println(" Default_Throttle");
      } break;

  }
}

