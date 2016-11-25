#include <Servo.h>



struct servoConstr
{
  byte pin_signal;
  byte pin_vcc;
  byte pin_gnd;
};
#define SERVO1 servoConstr{ 2,  3 ,  4}
#define SERVO2 servoConstr{ 5,  6 ,  7}
#define SERVO3 servoConstr{ 8,  9 , 10}
#define SERVO4 servoConstr{13, 12 , 11}


Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);
  Serial.println("HELLO");

  Serial.print(SERVO1.pin_signal); Serial.print("\t"); Serial.print(SERVO1.pin_vcc); Serial.print("\t"); Serial.println(SERVO1.pin_gnd);
  Serial.print(SERVO2.pin_signal); Serial.print("\t"); Serial.print(SERVO2.pin_vcc); Serial.print("\t"); Serial.println(SERVO2.pin_gnd);
  Serial.print(SERVO3.pin_signal); Serial.print("\t"); Serial.print(SERVO3.pin_vcc); Serial.print("\t"); Serial.println(SERVO3.pin_gnd);
  Serial.print(SERVO4.pin_signal); Serial.print("\t"); Serial.print(SERVO4.pin_vcc); Serial.print("\t"); Serial.println(SERVO4.pin_gnd);

  pinMode(SERVO1.pin_signal, HIGH);
  pinMode(SERVO2.pin_signal, HIGH);
  pinMode(SERVO3.pin_signal, HIGH);
  pinMode(SERVO4.pin_signal, HIGH);
  
  pinMode(SERVO1.pin_vcc, HIGH);
  pinMode(SERVO2.pin_vcc, HIGH);
  pinMode(SERVO3.pin_vcc, HIGH);
  pinMode(SERVO4.pin_vcc, HIGH);

  pinMode(SERVO1.pin_gnd, LOW);
  pinMode(SERVO2.pin_gnd, LOW);
  pinMode(SERVO3.pin_gnd, LOW);
  pinMode(SERVO4.pin_gnd, LOW);

  //myservo1.attach(SERVO1.pin_signal); 
  //myservo1.write(90);
  
  myservo4.attach(SERVO1.pin_signal); 
  myservo4.writeMicroseconds(1200);
  
  

}

int pos = 0;
void loop() {
  // put your main code here, to run repeatedly:
 //myservo4.writeMicroseconds(1500);
   for (pos = 50; pos <= 130; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo4.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 130; pos >= 50; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo4.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}







