
#ifndef DATA_H
#define DATA_H


// I know to much of cross refs
#include <hid.h>

//#ifndef uint32_t
//#define uint32_t (unsigned long)
//#endif

typedef struct pid_val
{
  double kp,ki,kd;
  double input, output, setpoint;
};

typedef struct true_angle_val_raw_acc
{

  unsigned char stx;
  unsigned char header;
  unsigned char data_len;
  unsigned char data_type;
  unsigned char res3;

  float x_angle;
  float y_angle;
  float z_angle;
  float x_unfiltered_acc;
  float y_unfiltered_acc;
  float z_unfiltered_acc;

  unsigned char etx;
};

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
};

typedef struct GamePadEventData_Simple
{
  uint16_t x;
  uint16_t y;
  uint8_t hat;
  uint8_t twist;
  uint8_t buttons_a;
  uint8_t slider;
  uint8_t buttons_b;
};


typedef struct GamePadData
{
  unsigned char stx;
  unsigned char header;
  unsigned char data_len;
  unsigned char data_type;
  unsigned char res3;
  GamePadEventData_Simple gd;
  unsigned char etx;
};

#define SIZE_OF_GPADDATA_STRUCT (sizeof(GamePadData)/sizeof(uint8_t))

typedef union txGamePadData
{

  GamePadData gd;
  unsigned char uc_data[SIZE_OF_GPADDATA_STRUCT];

};

#endif // DATA_H
