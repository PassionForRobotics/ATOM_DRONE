
#ifndef DATA_H
#define DATA_H

#include "Arduino.h"


typedef struct sMPURATA_t
{

  //unsigned char stx;
  //unsigned char header;
  //unsigned char data_len;
  //unsigned char data_type;
  //unsigned char res3;
  uint32_t timestamp;
  int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

  //unsigned char etx;
}sMPURATA_t;

#define SIZE_OF_MPU_DATA (sizeof(sMPURATA_t))

typedef struct sMOTIONSETPOINTS_t
{
  uint32_t timestamp;
  uint16_t x;
  uint16_t y;
  uint8_t hat;
  uint8_t twist;
  uint8_t buttons_a;
  uint8_t slider;
  uint8_t buttons_b;

}sMOTIONSETPOINTS_t;

#define SIZE_OF_MSETPOINTS_DATA (sizeof(sMOTIONSETPOINTS_t))

#endif // DATA_H
