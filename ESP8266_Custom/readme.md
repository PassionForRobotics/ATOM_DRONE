
Data protocol:

'''

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

'''

Sending hello : from packetsender to ESP8266 which outputs it to serial port for further controller.
02 ff fe 00 02 00 00 00 07 00 00 00 68 65 6c 6c 6f 0d 0a
