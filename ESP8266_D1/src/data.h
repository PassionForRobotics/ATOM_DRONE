
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

#endif // DATA_H
