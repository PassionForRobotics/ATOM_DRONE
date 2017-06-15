
#include <Servo.h>
#include "data.h"

Servo servo[4];  // create servo object to control a servo
int pins[4] = {D8, D9, D10, D11}; // D9 is LED
int i = 0;

// Servo mechanical offsets
#define SERVO0_OFFSET (7)
#define SERVO1_OFFSET (4)
#define SERVO2_OFFSET (6)
#define SERVO3_OFFSET (-5)

// twist limits
#define SERVO_TWIST_ANGLE_LIMIT (20)

byte servo_offsets[4] = {SERVO0_OFFSET, SERVO1_OFFSET, SERVO2_OFFSET, SERVO3_OFFSET};

Servo ESC; // D1 pin D12

#define Servo1_offset 1;

void steer_setup()
{
  randomSeed(analogRead(D0));

  ESC.attach(D12);
  ESC.write(90);

  for(i=0;i<4;i++)
  {
    servo[i].attach(pins[i]);  // attaches the servo on GIO2 to the servo object
    servo[i].write(90+servo_offsets[i]);
  }
}

byte angle = 35;
uint32_t lastSteerLoopTime = 0;

void steer_loop(sMPUDATA_t *mpudata, sMOTIONSETPOINTS_t *msetpts)
{


  byte a = random(90-45, 90+45);

  byte x = map(msetpts->x, 0, 1023, -45+90+servo_offsets[0], 45+90+servo_offsets[0]);
  //x += 90;
  byte y = map(msetpts->y, 0, 1023, -45+90+servo_offsets[1], 45+90+servo_offsets[1]);

  byte x1 = map(msetpts->x, 1023, 0, -45+90+servo_offsets[2], 45+90+servo_offsets[2]);

  byte y1 = map(msetpts->y, 1023, 0, -45+90+servo_offsets[3], 45+90+servo_offsets[3]);

  byte tw = map(msetpts->twist, 0, 255, -SERVO_TWIST_ANGLE_LIMIT, SERVO_TWIST_ANGLE_LIMIT);

  x += tw;
  x1 += tw;
  y += tw;
  y1 += tw;




  //y += 90;

  if(system_get_time()-lastSteerLoopTime >=(STEER_LOOP_TIME))
  {
    lastSteerLoopTime = system_get_time();


    // PID
    //
    // ///


    //for(i=0;i<4;i++)
    {
      //Serial.printf("rnd %d\n", angle);
      servo[0].write(x);//random(90-45, 90+45));byte x = map(msetpts->x, 0, 512, -45, 45);

      servo[1].write(y);

      servo[2].write(x1);

      servo[3].write(y1);
    }
    //ESC.write(angle);
  }

  //if(angle>=135)
  //angle = 0;

}
