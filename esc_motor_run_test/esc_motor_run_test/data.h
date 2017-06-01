
#ifndef DATA_H
#define DATA_H

#include "version.h"
#define VERSION (_VER_)

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

//#include "stdint.h" // for https://nodejs.org/api/addons.html
//typedef unsigned long uint32_t;
//typedef unsigned int uint16_t;
//typedef unsigned char uint8_t;
//typedef unsigned char byte; // https://nodejs.org/api/addons.html


//#define GROUND_SYSTEM // or
#define SKY_SYSTEM

#if (defined(GROUND_SYSTEM) && defined(SKY_SYSTEM) )
#error BOTH SYSTEM TYPE ACTIVE, ONLY ONE IS ALLOWED PER BUILD
#endif

//#define USE_DATA_UNION

#include "Arduino.h"

// I know to much of cross refs
#include "usbhid.h"

typedef enum datatype
{
  DATATYPE_DEFAULT = 0xFFFF,
  DATATYPE = DATATYPE_DEFAULT,
  DATATYPE_NONE = 0x00,
  DATATYPE_JOY,
  DATATYPE_MPU,
  DATATYPE_ERROR,
  DATATYPE_RESET,
  DATATYPE_MAX
} datatype;

typedef struct true_angle_val_raw_acc
{

  //unsigned char stx;
  //unsigned char header;
  //unsigned char data_len;
  //unsigned char data_type;
  //unsigned char res3;
  uint32_t timestamp;
  float x_angle;
  float y_angle;
  float z_angle;
  float x_unfiltered_acc;
  float y_unfiltered_acc;
  float z_unfiltered_acc;

  //unsigned char etx;
}true_angle_val_raw_acc;

#define SIZE_OF_MDATA_STRUCT (sizeof(true_angle_val_raw_acc))

typedef union angle_val_raw_acc
{
  true_angle_val_raw_acc data;
  unsigned char uc_data[SIZE_OF_MDATA_STRUCT];
} u_data;

// from le3dp_*.h
typedef struct GamePadEventData
{
  union { //axes and hut switch
    uint32_t axes;
    struct {
      uint32_t x : 10;
      uint32_t y : 10;
      uint32_t hat : 4;
      uint32_t twist : 8;
    };
  };
  uint8_t buttons_a;
  uint8_t slider;
  uint8_t buttons_b;
}GamePadEventData;

typedef struct GamePadEventData_Simple
{
  uint32_t timestamp;
  uint16_t x;
  uint16_t y;
  uint8_t hat;
  uint8_t twist;
  uint8_t buttons_a;
  uint8_t slider;
  uint8_t buttons_b;
}GamePadEventData_Simple;

#define SIZE_OF_JDATA_STRUCT (sizeof(GamePadEventData_Simple))

typedef struct GamePadData
{
  unsigned char stx;
  unsigned char header;
  unsigned char data_len;
  unsigned char data_type;
  unsigned char res3;
  unsigned char res4;
  GamePadEventData_Simple gd;
  uint32_t dummy[3];
  unsigned char etx;
}GamePadData;

#if defined(USE_DATA_UNION)

typedef union alldata
{
  GamePadEventData_Simple gd;
  angle_val_raw_acc mpu;
}alldata;

typedef struct GamePadORMPUData
{
  unsigned char stx;
  unsigned char header;
  unsigned char data_len;
  unsigned char data_type;
  unsigned char res3;
  alldata data;
  unsigned char etx;
}GamePadORMPUData;


#define SIZE_OF_GPADMDATA_STRUCT (sizeof(GamePadORMPUData)/sizeof(uint8_t))

#endif // defined(USE_DATA_UNION)

#define SIZE_OF_GPADDATA_STRUCT (sizeof(GamePadData)/sizeof(uint8_t))

typedef union txGamePadData
{

  GamePadData gd;
  unsigned char uc_data[SIZE_OF_GPADDATA_STRUCT];

}txGamePadData;

#if defined(USE_DATA_UNION)

typedef union txGamePadORMPUData
{

  GamePadORMPUData data;
  unsigned char uc_data[SIZE_OF_GPADMDATA_STRUCT];

}txGamePadORMPUData;

#endif // defined(USE_DATA_UNION)

// Following is the manual work, on each structure update these need to be updated
#define DEFAULT_MPU_DATA { .x_angle = 0.0, .y_angle = 0.0, .z_angle = 0.0, .x_unfiltered_acc=0.0, .y_unfiltered_acc=0.0, .z_unfiltered_acc=0.0  };
#define DEFAULT_JOY_DATA { .x=0, .y=0, .hat=0, .twist=0, .buttons_a=0, .slider=0, .buttons_b=0 };

// Below datatypes are just for reference

typedef enum type1
{
  DATA_TYPE1_DEFAULT = 0xFFFF,
  DATA_TYPE1 = DATA_TYPE1_DEFAULT,
  DATA_TYPE1_NONE = 0x00,
  DATA_TYPE1_PING,
  DATA_TYPE1_SERIAL,
  DATA_TYPE1_GPIO,
  DATA_TYPE1_ERROR,
  DATA_TYPE1_RESET,
  DATA_TYPE1_MAX
} type1;

typedef enum type2_error
{
  DATA_TYPE2_ERROR_DEFAULT = 0xFFFF,
  DATA_TYPE2_ERROR = DATA_TYPE2_ERROR_DEFAULT,
  DATA_TYPE2_ERROR_0 = 0x0000, // No errors
  DATA_TYPE2_ERROR_1, // Serial number is invalid
  DATA_TYPE2_ERROR_2,
  DATA_TYPE2_ERROR_3,
  DATA_TYPE2_ERROR_4,
  DATA_TYPE2_ERROR_5,
  DATA_TYPE2_ERROR_6,
  DATA_TYPE2_ERROR_7,
  DATA_TYPE2_ERROR_MAX
} type2_error;

typedef enum type2_serial
{
  DATA_TYPE2_SERIAL_DEFAULT = 0xFFFF,
  DATA_TYPE2_SERIAL = DATA_TYPE2_SERIAL_DEFAULT,
  DATA_TYPE2_SERIAL_0 = 0x00,
  DATA_TYPE2_SERIAL_1,
  DATA_TYPE2_SERIAL_2,
  DATA_TYPE2_SERIAL_3,
  DATA_TYPE2_SERIAL_4,
  DATA_TYPE2_SERIAL_5,
  DATA_TYPE2_SERIAL_6,
  DATA_TYPE2_SERIAL_7,
  DATA_TYPE2_SERIAL_MAX
} type2_serial;

typedef enum type2_ping
{
  DATA_TYPE2_PING_DEFAULT = 0xFFFF, // Idle
  DATA_TYPE2_PING = DATA_TYPE2_PING_DEFAULT,
  DATA_TYPE2_PING_0 = 0x00, // RX-ack-TX with counter
  DATA_TYPE2_PING_1,        // RX, TX without counter and ack
  DATA_TYPE2_PING_2,
  DATA_TYPE2_PING_3,
  DATA_TYPE2_PING_4,
  DATA_TYPE2_PING_5,
  DATA_TYPE2_PING_6,
  DATA_TYPE2_PING_7,
  DATA_TYPE2_PING_MAX
} type2_ping;


typedef struct reliencenperformance
{
  type1 type;
  type2_ping type_ping;
  uint32_t payloadcheckcntr;
} reliencenperformance;

typedef struct Header
{
  struct // struct pad
  {
    byte header1;
    byte header2;
    byte header3;

    byte chk;
  };

  struct // struct pad
  {
    union
    {
      byte typeb1[2];
      unsigned short type1; // Serial, GPIO, CAN etc
    };

    union
    {
      byte typeb2[2];
      unsigned short type2; // Serial1, Serial2, GPIOA1, GPIOA2, CAN1, CAN2 etc
    };
  };

  struct // struct pad
  {
    union
    {
      byte lenb[2];
      unsigned short len;
    };

    union
    {
      byte resb[2];
      unsigned short res;
    };
  };
} Header; // header

#define DATA_HEADER_LEN sizeof(Header) // apart from payload
#define MAX_PAYLOAD_SIZE (256-DATA_HEADER_LEN)

typedef struct RecData
{
  Header header;
  union
  {
    char c_payload[MAX_PAYLOAD_SIZE]; // directly bypass it
    uint8_t payload[MAX_PAYLOAD_SIZE]; // directly bypass it
    uint32_t payloadcheckcntr;
  };
} recdata;


#define DATA_SIZE sizeof(RecData)

typedef union Data
{
  RecData data;
  union
  {
    unsigned char uc_buffer[DATA_SIZE];
    char c_buffer[DATA_SIZE];
    uint8_t  ui8_buffer[DATA_SIZE];
  };
} data;

// type2_serial can be generalized
// int DATA_validateHeader(Data * data, type1 t1, type2_serial t2)
// {
//   return data->data.header.header1 == 0x02 &&
//          data->data.header.header2 == 0xFF &&
//          data->data.header.header3 == 0xFE &&
//          data->data.header.type1 == t1 &&
//          data->data.header.type2 == t2;
//   // data.data.header.res = 0x00; // version
// }

// int DATA_validateHeader(Data * data, type1 t1, type2_ping t2)
// {
//   return data->data.header.header1 == 0x02 &&
//          data->data.header.header2 == 0xFF &&
//          data->data.header.header3 == 0xFE &&
//          data->data.header.type1 == t1 &&
//          data->data.header.type2 == t2;
//   // data.data.header.res = 0x00; // version
// }

//extern int DATA_validateHeader(Data * data, type1 t1, type2_serial t2);
//extern int DATA_validateHeader(Data * data, type1 t1, type2_ping t2);

#endif // DATA_H

//#endif // DATA_H
