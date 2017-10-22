
#include <Arduino.h>
#include "data.h"

GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#ifdef ESP8266
extern "C" {
  #include "user_interface.h"
}
#endif
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)

class Profiler
{
private:
  uint16_t cpuMHz;
  uint16_t defaultStartOverhead;

public:
  Profiler()
  {

    ReinitCounters();
    Reset();

  }

  ~Profiler(){}

  void Reset()
  {
    if(isValidProfile)
    {
      Pause();
    }

    defaultStartOverhead = 0;
    defaultPauseOverhead = 0;

    //ReinitCounters();

  }

  void ReinitCounters()
  {
    if(isValidProfile)
    {
      Pause();
    }

    cyCount = 1 ;

    dt = 0;
    att = 0.0;
    tt = 0.0;

    cycle = ESP.getCycleCount(), lastCycle = ESP.getCycleCount();//ESP.getCycleCount();
    cycleSum = 0;//cycle;
    cycleDiff = 0;
    averageTick = 0;
    averageTime = 0; // micros
    lastIterationCount = 0;
    isValidProfile = 0;

    cpuMHz = ESP.getCpuFreqMHz();

  }

  void Start()
  {
    if(!isValidProfile)
    {
      isValidProfile = 1;
      ts = system_get_time();
      cycle = ESP.getCycleCount() - defaultStartOverhead;
      cycle = cycle < 0 ? 0 : cycle;
    }
    else
    {
      Update();
      ts = system_get_time();
      cycle = ESP.getCycleCount() - defaultStartOverhead;
      cycle = cycle < 0 ? 0 : cycle;
    }
  }

  void Continue()
  {
    Start();
  }

  void Pause()
  {
    Update();
    isValidProfile = 0;
  }


  // Can be called at every second
  // Or just before printing
  void CalculateAverageTicks()
  {
    //Serial.printf("Cnt %d\n", cyCount);
    if(cyCount==0)
    {
      return;
    }

    averageTick = (cycleSum/cyCount);
    att = tt / cyCount;

    //Serial.printf("Cnt %d\n", cyCount);
    averageTime = (float)(averageTick) / (float)cpuMHz; // 1 sec => 80MHz; 1micros => 80Hz

    lastIterationCount = cyCount;

  }

  float getAverageMicros()
  {
    return averageTime;
  }

  float getAverageMicros2()
  {
    return att;
  }

  uint32_t getAverageTicks()
  {
    return averageTick;
  }

  uint16_t getLastIterationCount()
  {
    return lastIterationCount;
  }

  void SetOverHead(uint16_t val)
  {
    defaultStartOverhead = val;
  }

  uint16_t Calibrate() // Should be static but ESP compiler is not allowing this and relevant
  {
    //int testCounter = cpuMHz*1000000;
    int overhead = 0;

    uint32_t usec = system_get_time();
    ESP.wdtDisable();

    Serial.printf("\nOverhead calibrating incorrectly if printing: \n");
    while(system_get_time() - usec < 1000000) // should take a second
    {
      //ESP.wdtFeed();
      Continue();

      //cyCount = cyCount < 1 ? 1 : cyCount;

      // Serial.printf("%d, %d, %d, "
      // , cyCount, cycleSum, cycleSum/cyCount);// (cycleSum/cyCount));
      // Serial.print((cycleSum/cyCount)/cpuMHz);
      // Serial.printf(" uS\n");
      //this->Pause();
    }

    Pause();

    ESP.wdtEnable(100);

    CalculateAverageTicks();

    overhead = getAverageTicks();

    Serial.printf("\nOverhead calibrated: count: %d, averageTick: %d | average_uS: "
    , getLastIterationCount(), getAverageTicks());// (cycleSum/cyCount));

    Serial.print(getAverageMicros());
    Serial.printf(" uS | ");

    Serial.print(getAverageMicros2());
    Serial.printf(" uS\n");

    ReinitCounters();

    defaultStartOverhead = overhead;

    return defaultStartOverhead;

  }


private:
  uint32_t ts;
  float dt, tt, att;
  int16_t cyCount;
  int64_t cycle, lastCycle;//ESP.getCycleCount();
  uint32_t cycleSum;//cycle;
  uint32_t cycleDiff;
  uint32_t averageTick;
  float averageTime; // micros
  uint16_t lastIterationCount;
  uint16_t isValidProfile;
  uint16_t defaultPauseOverhead;

  uint16_t Update(bool inc = true)
  {
    inc = inc;

    if(!isValidProfile)
    {
      return cyCount;
    }

    //  return;

    lastCycle = cycle;
    cycle = ESP.getCycleCount();
    //cycleSum += cycle;
    cyCount++;


    dt = system_get_time() - ts;

    cycleDiff = (cycle - lastCycle);


    tt += dt;

    cycleSum += cycleDiff;


    return cyCount;

    //Serial.printf("Profiler Cy: %d, %d, %d, %d \n", cycleDiff, cycleSum, cyCount, (cycleSum/cyCount));

  }

};
