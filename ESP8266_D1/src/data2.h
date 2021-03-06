

#ifndef DATA2_H
#define DATA2_H

struct sSmoothData_t
{
  int32_t X, Y, Z;
};

struct sMPUDATA_f_t
{
  uint32_t timestamp;
  float AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
};

struct sMPUDATA_t
{
  uint32_t timestamp;
  int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
#ifdef __cplusplus
//extern "C" {
//#endif
  sMPUDATA_t operator+=(sMPUDATA_t d)
  {
    timestamp += (uint32_t)d.timestamp;
    AcX += (int16_t)d.AcX;
    AcY += (int16_t)d.AcY;
    AcZ += (int16_t)d.AcZ;
    GyX += (int16_t)d.GyX;
    GyY += (int16_t)d.GyY;
    GyZ += (int16_t)d.GyZ;
    return *this;
  }

  sMPUDATA_t operator-=(sMPUDATA_t d)
  {
    timestamp -= (uint32_t)d.timestamp;
    AcX -= (int16_t)d.AcX;
    AcY -= (int16_t)d.AcY;
    AcZ -= (int16_t)d.AcZ;
    GyX -= (int16_t)d.GyX;
    GyY -= (int16_t)d.GyY;
    GyZ -= (int16_t)d.GyZ;
    return *this;
  }

  // Not tested
  // sMPUDATA_t operator+( sMPUDATA_t &rhs)
  // {
  //   sMPUDATA_t lhs = *this;
  //   lhs.timestamp += (uint32_t)rhs.timestamp;
  //   lhs.AcX += (int16_t)rhs.AcX;
  //   lhs.AcY += (int16_t)rhs.AcY;
  //   lhs.AcZ += (int16_t)rhs.AcZ;
  //   lhs.GyX += (int16_t)rhs.GyX;
  //   lhs.GyY += (int16_t)rhs.GyY;
  //   lhs.GyZ += (int16_t)rhs.GyZ;
  //
  //   return lhs;
  //   //  return a.team_name < b.team_name;
  // }
  //
  // sMPUDATA_t operator-(sMPUDATA_t &rhs)
  // {
  //   sMPUDATA_t lhs = *this;
  //   lhs.timestamp -= (uint32_t)rhs.timestamp;
  //   lhs.AcX -= (int16_t)rhs.AcX;
  //   lhs.AcY -= (int16_t)rhs.AcY;
  //   lhs.AcZ -= (int16_t)rhs.AcZ;
  //   lhs.GyX -= (int16_t)rhs.GyX;
  //   lhs.GyY -= (int16_t)rhs.GyY;
  //   lhs.GyZ -= (int16_t)rhs.GyZ;
  //
  //   return lhs;
  //   //  return a.team_name < b.team_name;
  // }

  sMPUDATA_t operator/(int d)
  {
    sMPUDATA_t lhs = *this;
    lhs.timestamp /= d;
    lhs.AcX /= d;
    lhs.AcY /= d;
    lhs.AcZ /= d;
    lhs.GyX /= d;
    lhs.GyY /= d;
    lhs.GyZ /= d;

    return lhs;
  }

  //unsigned char etx;
//#ifdef __cplusplus
//}
#endif
};

struct sMOTIONSETPOINTS_t
{
  uint32_t timestamp;
  uint16_t x;
  uint16_t y;
  uint8_t hat;
  uint8_t twist;
  //uint8_t buttons_a;
  uint8_t slider;
  uint16_t buttons;
};

#ifdef __cplusplus
enum PID_TUNE_TYPE : uint16_t // unsafe
#else
enum PID_TUNE_TYPE
#endif
{
  PID_TUNE_TYPE_INVALID = 0xff,
  PID_TUNE_TYPE_NONE = 0,
  PID_TUNE_TYPE_LEFT_RIGHT = 1 << 0,
  PID_TUNE_TYPE_FORE_BACK =  1 << 1,
  PID_TUNE_TYPE_UP_DOWN   =  1 << 2,
  PID_TUNE_TYPE_TUNING_DONE =  1 << 3,
  PID_TUNE_TYPE_MAX = 0xff
};

#ifdef __cplusplus
enum POV : uint16_t
#else
enum POV
#endif
{
  POV_NONE = 0,                               /**< POV hat is not in use.              */
  POV_WEST = 1 << 0,                          /**< POV hat is facing left.             */
  POV_EAST = 1 << 1,                          /**< POV hat is facing right.            */
  POV_NORTH = 1 << 2,                         /**< POV hat is facing up.               */
  POV_SOUTH = 1 << 3,                         /**< POV hat is facing down.             */
  POV_NORTHWEST = POV_NORTH | POV_WEST,       /**< POV hat is facing up and left.      */
  POV_NORTHEAST = POV_NORTH | POV_EAST,       /**< POV hat is facing up and right.     */
  POV_SOUTHWEST = POV_SOUTH | POV_WEST,       /**< POV hat is facing south and left.   */
  POV_SOUTHEAST = POV_SOUTH | POV_EAST        /**< POV hat is facing south and right.  */
};

union eBUTTONS_t
{
struct //:: uint16_t
{
  uint16_t HAT:4;  // 13,14,15,16
  uint16_t B_01:1; // 01
  uint16_t B_02:1; // 02
  uint16_t B_03:1; // 03
  uint16_t B_04:1; // 04
  uint16_t B_05:1; // 05
  uint16_t B_06:1; // 06
  uint16_t B_07:1; // 08
  uint16_t B_08:1; // 07
  uint16_t B_09:1; // 09
  uint16_t B_10:1; // 10
  uint16_t B_11:1; // 11
  uint16_t B_12:1; // 12
};
uint16_t btns;
};

struct sGENERICSETPOINTS_t
{
  uint32_t timestampsec;
  uint32_t timestampnsec;
  int16_t x;
  int16_t y;
  int16_t z;
  int16_t s; //slider
  //union
  //{
  //  eBUTTONS_t ebuttons;
    int16_t buttons;
    enum PID_TUNE_TYPE pid_tune_type;
  ///};
};

struct PID_Tune_Params_t
{
  uint32_t timestamp;
  //Define Variables we'll be connecting to
  double Setpoint, Input, Output;

  //Specify the links and initial tuning parameters
  double Kp, Ki, Kd;

};

struct Profiler_data
{
  uint32_t ts;
  uint16_t averageIterationCount;
  float averageTime; // micros
  float averageTime2; // micros
  uint32_t averageTick;
};


typedef struct sMPUDATA_t sMPUDATA_t;
#define SIZE_OF_MPU_DATA (sizeof(sMPUDATA_t))

typedef struct sMOTIONSETPOINTS_t sMOTIONSETPOINTS_t;
#define SIZE_OF_MSETPOINTS_DATA (sizeof(sMOTIONSETPOINTS_t))

typedef struct sGENERICSETPOINTS_t sGENERICSETPOINTS_t;
#define SIZE_OF_GMSETPOINTS_DATA (sizeof(sGENERICSETPOINTS_t))

typedef struct PID_Tune_Params_t PID_Tune_Params_t;

typedef enum PID_TUNE_TYPE PID_TUNE_TYPE;

struct ALL_DATA
{
  enum PID_TUNE_TYPE tune_type;
  uint32_t timestamp;
  float yaw;
  float pitch;
  float roll;
  struct sMPUDATA_t mpuRAW;
  //sMPUDATA_t mpuData;
  float pingheight;
  struct PID_Tune_Params_t pplr;
  struct PID_Tune_Params_t ppfb;     //
  struct PID_Tune_Params_t ppud; // Yaw and Ping
  struct Profiler_data profiled_loop, profiled_mpu, profiled_wifi, profiled_steer;
  struct sGENERICSETPOINTS_t msetpts;
};

typedef struct ALL_DATA debug_data;
#define SIZE_OF_ALL_DATA (sizeof(ALL_DATA))


#endif // DATA2_H
