
#include <Servo.h>
#include "data.h"

Servo servo[4];  // create servo object to control a servo
int pins[4] = {D8, D9, D10, D11}; // D9 is LED
int i = 0;

Servo ESC; // D1 pin D12


void steer_setup()
{
  randomSeed(analogRead(D0));

  ESC.attach(D12);
  ESC.write(90);

  for(i=0;i<4;i++)
  {
    servo[i].attach(pins[i]);  // attaches the servo on GIO2 to the servo object
    servo[i].write(90);
  }
}

byte angle = 35;
uint32_t lastSteerLoopTime = 0;

void steer_loop(sMPUDATA_t *mpudata, sMOTIONSETPOINTS_t *msetpts)
{
  byte a = random(90-45, 90+45);

  byte x = map(msetpts->x, 0, 512, -45, 45);

  if(system_get_time()-lastSteerLoopTime >=(STEER_LOOP_TIME))
  {
    lastSteerLoopTime = system_get_time();

    //for(i=0;i<4;i++)
    {
      //Serial.printf("rnd %d\n", angle);
      servo[0].write(x);//random(90-45, 90+45));
    }
    //ESC.write(angle);
  }

  //if(angle>=135)
  //angle = 0;

}
