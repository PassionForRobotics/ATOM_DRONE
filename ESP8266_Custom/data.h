#ifndef DATA_H
#define DATA_H


#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define VER 0

#undef SMARTVER_HELPER_
#undef RESVER
#if VER < 10
#define SMARTVER_HELPER_(x) 0000 ## x
#elif VER < 100
#define SMARTVER_HELPER_(x) 000 ## x
#elif VER < 1000
#define SMARTVER_HELPER_(x) 00 ## x
#elif VER < 10000
#define SMARTVER_HELPER_(x) 0 ## x
#else
#define SMARTVER_HELPER_(x) x
#endif
#define RESVER(x) SMARTVER_HELPER_(x)

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
int DATA_validateHeader(Data * data, type1 t1, type2_serial t2)
{
  return data->data.header.header1 == 0x02 &&
         data->data.header.header2 == 0xFF &&
         data->data.header.header3 == 0xFE &&
         data->data.header.type1 == t1 &&
         data->data.header.type2 == t2;
  // data.data.header.res = 0x00; // version
}

extern int DATA_validateHeader(Data * data, type1 t1, type2_serial t2);

#endif // DATA_H
