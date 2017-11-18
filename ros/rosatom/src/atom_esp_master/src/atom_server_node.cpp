#include <ros/ros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "std_msgs/String.h"
#include <netinet/tcp.h>

#include <math.h>
#include <tf/transform_broadcaster.h>

#include <atom_esp_master/alldata.h>
atom_esp_master::alldata msg;

#include <atom_esp_joy/joydata.h>
atom_esp_joy::joydata joydata;

#include "sensor_msgs/Imu.h"
sensor_msgs::Imu imudata;
sensor_msgs::Imu imudatalast;


#include <signal.h>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>

#include <fcntl.h>

#include <pthread.h> // exit test

#include "/home/rahuldeo/ATOM/ATOM_DRONE/ESP8266_D1/src/data2.h"
debug_data all_data;
sGENERICSETPOINTS_t setpoints;


#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
(byte & 0x80 ? '1' : '0'), \
(byte & 0x40 ? '1' : '0'), \
(byte & 0x20 ? '1' : '0'), \
(byte & 0x10 ? '1' : '0'), \
(byte & 0x08 ? '1' : '0'), \
(byte & 0x04 ? '1' : '0'), \
(byte & 0x02 ? '1' : '0'), \
(byte & 0x01 ? '1' : '0')

#define SHORT_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
#define SHORT_TO_BINARY(byte)  \
(byte & 0x8000 ? '1' : '0'), \
(byte & 0x4000 ? '1' : '0'), \
(byte & 0x2000 ? '1' : '0'), \
(byte & 0x1000 ? '1' : '0'), \
(byte & 0x0800 ? '1' : '0'), \
(byte & 0x0400 ? '1' : '0'), \
(byte & 0x0200 ? '1' : '0'), \
(byte & 0x0100 ? '1' : '0'), \
(byte & 0x0080 ? '1' : '0'), \
(byte & 0x0040 ? '1' : '0'), \
(byte & 0x0020 ? '1' : '0'), \
(byte & 0x0010 ? '1' : '0'), \
(byte & 0x0008 ? '1' : '0'), \
(byte & 0x0004 ? '1' : '0'), \
(byte & 0x0002 ? '1' : '0'), \
(byte & 0x0001 ? '1' : '0')


// TODO: Anything to socket proper close
// It is not working ???
// May be ROS is using it??
void my_handler(int s){
  printf("Caught signal %d\n",s);
  exit(1);

}

void copy_joydata(sGENERICSETPOINTS_t *_data, const atom_esp_joy::joydata *_msg)
{

  _data->timestampsec = _msg->header.stamp.sec;
  _data->timestampnsec = _msg->header.stamp.nsec;

  _data->x		= _msg->X;
  _data->y		= _msg->Y;
  _data->z		= _msg->Z;
  _data->s		= _msg->S;
  _data->buttons	= _msg->buttons;

}

void copy_imudata(const debug_data *_data, sensor_msgs::Imu *_msg)
{
  
  const double sigma2_gyr_adis16375_d = 0;
  const double sigma2_acc_adis16375_d = 0;
  double roll, pitch, yaw;
  
  //imu_msg.header.stamp = _data->;
  //  _msg->  mpuRAW.timestamp    = _data->mpuRAW.timestamp
  //imu_msg.header.frame_id = ROS_IMU_FRAME_NAMES.at(static_cast<SensorId::SensorId>(imu_ptr->imu_id));
  _msg->orientation.x = 0.0;
  _msg->orientation.y = 0.0;
  _msg->orientation.z = 0.0;
  _msg->orientation.w = 1.0;
  _msg->orientation_covariance[0] = 99999.9;
  _msg->orientation_covariance[1] = 0.0;
  _msg->orientation_covariance[2] = 0.0;
  _msg->orientation_covariance[3] = 0.0;
  _msg->orientation_covariance[4] = 99999.9;
  _msg->orientation_covariance[5] = 0.0;
  _msg->orientation_covariance[6] = 0.0;
  _msg->orientation_covariance[7] = 0.0;
  _msg->orientation_covariance[8] = 99999.9;
  // --- Angular Velocity.
  _msg->angular_velocity.x = _data->mpuRAW.GyX;
  _msg->angular_velocity.y = _data->mpuRAW.GyY;
  _msg->angular_velocity.z = _data->mpuRAW.GyZ;
  _msg->angular_velocity_covariance[0] = sigma2_gyr_adis16375_d;
  _msg->angular_velocity_covariance[1] = 0.0;
  _msg->angular_velocity_covariance[2] = 0.0;
  _msg->angular_velocity_covariance[3] = 0.0;
  _msg->angular_velocity_covariance[4] = sigma2_gyr_adis16375_d;
  _msg->angular_velocity_covariance[5] = 0.0;
  _msg->angular_velocity_covariance[6] = 0.0;
  _msg->angular_velocity_covariance[7] = 0.0;
  _msg->angular_velocity_covariance[8] = sigma2_gyr_adis16375_d;
  // --- Linear Acceleration.
  _msg->linear_acceleration.x = _data->mpuRAW.AcX;
  _msg->linear_acceleration.y = _data->mpuRAW.AcY;
  _msg->linear_acceleration.z = _data->mpuRAW.AcZ;
  _msg->linear_acceleration_covariance[0] = sigma2_acc_adis16375_d;
  _msg->linear_acceleration_covariance[1] = 0.0;
  _msg->linear_acceleration_covariance[2] = 0.0;
  _msg->linear_acceleration_covariance[3] = 0.0;
  _msg->linear_acceleration_covariance[4] = sigma2_acc_adis16375_d;
  _msg->linear_acceleration_covariance[5] = 0.0;
  _msg->linear_acceleration_covariance[6] = 0.0;
  _msg->linear_acceleration_covariance[7] = 0.0;
  _msg->linear_acceleration_covariance[8] = sigma2_acc_adis16375_d;
  
  
   tf::Quaternion q;
   tf::quaternionMsgToTF(_msg->orientation, q);
   tf::Matrix3x3(q).getRPY(roll, pitch, yaw);
   
   ROS_DEBUG_THROTTLE(5, "RPY: %f %f %f",roll*180.0/M_PI, pitch*180.0/M_PI, yaw*180.0/M_PI);

  //_msg->
  //_msg->  mpuRAW.AcX          = _data->mpuRAW.AcX;
  //_msg->  mpuRAW.AcY          = _data->mpuRAW.AcY;
  //_msg->  mpuRAW.AcZ          = _data->mpuRAW.AcZ;
  //_msg->  mpuRAW.timestamp    = _data->mpuRAW.timestamp;
  //_msg->  mpuRAW.Tmp          = _data->mpuRAW.Tmp;
  //_data->mpuRAW.GyX;
  //_data->mpuRAW.GyY;
  //_data->mpuRAW.GyZ;
}
void copy_alldata(const debug_data *_data, atom_esp_master::alldata *_msg)
{
  /*_msg->  mpuData_AcX         = _data->mpuData.AcX;
  _msg->  mpuData_AcY         = _data->mpuData.AcY;
  _msg->  mpuData_AcZ         = _data->mpuData.AcZ;
  _msg->  mpuData_timestamp   = _data->mpuData.timestamp;
  _msg->  mpuData_Tmp         = _data->mpuData.Tmp;
  _msg->  mpuData_GyX         = _data->mpuData.GyX;
  _msg->  mpuData_GyY         = _data->mpuData.GyY;
  _msg->  mpuData_GyZ         = _data->mpuData.GyZ;*/

  _msg->  mpuRAW.AcX          = _data->mpuRAW.AcX;
  _msg->  mpuRAW.AcY          = _data->mpuRAW.AcY;
  _msg->  mpuRAW.AcZ          = _data->mpuRAW.AcZ;
  _msg->  mpuRAW.timestamp    = _data->mpuRAW.timestamp;
  _msg->  mpuRAW.Tmp          = _data->mpuRAW.Tmp;
  _msg->  mpuRAW.GyX          = _data->mpuRAW.GyX;
  _msg->  mpuRAW.GyY          = _data->mpuRAW.GyY;
  _msg->  mpuRAW.GyZ          = _data->mpuRAW.GyZ;

  _msg->  pingheight          = _data->pingheight;

  _msg->  ppfb.timestamp      = _data->ppfb.timestamp;
  _msg->  ppfb.Input          = _data->ppfb.Input;
  _msg->  ppfb.Kd             = _data->ppfb.Kd;
  _msg->  ppfb.Ki             = _data->ppfb.Ki;
  _msg->  ppfb.Kp             = _data->ppfb.Kp;
  _msg->  ppfb.Output         = _data->ppfb.Output;
  _msg->  ppfb.Setpoint       = _data->ppfb.Setpoint;

  _msg->  pplr.timestamp      = _data->pplr.timestamp;
  _msg->  pplr.Input          = _data->pplr.Input;
  _msg->  pplr.Kd             = _data->pplr.Kd;
  _msg->  pplr.Ki             = _data->pplr.Ki;
  _msg->  pplr.Kp             = _data->pplr.Kp;
  _msg->  pplr.Output         = _data->pplr.Output;
  _msg->  pplr.Setpoint       = _data->pplr.Setpoint;

  _msg->  ppud.timestamp      = _data->ppud.timestamp;
  _msg->  ppud.Input          = _data->ppud.Input;
  _msg->  ppud.Kd             = _data->ppud.Kd;
  _msg->  ppud.Ki             = _data->ppud.Ki;
  _msg->  ppud.Kp             = _data->ppud.Kp;
  _msg->  ppud.Output         = _data->ppud.Output;
  _msg->  ppud.Setpoint       = _data->ppud.Setpoint;

  _msg->  yaw                 = _data->yaw;
  _msg->  pitch               = _data->pitch;
  _msg->  roll                = _data->roll;

  _msg->  timestamp           = _data->timestamp;
  _msg->  tune_type           = _data->tune_type;
  
  _msg-> profiled_loop.timestamp = _data->profiled_loop.ts;
  _msg-> profiled_loop.averageIterationCount = _data->profiled_loop.averageIterationCount;
  _msg-> profiled_loop.averageTick = _data->profiled_loop.averageTick;
  _msg-> profiled_loop.averageTime = _data->profiled_loop.averageTime;
  _msg-> profiled_loop.averageTime2 = _data->profiled_loop.averageTime2;
  
  _msg-> profiled_mpu.timestamp = _data->profiled_mpu.ts;
  _msg-> profiled_mpu.averageIterationCount = _data->profiled_mpu.averageIterationCount;
  _msg-> profiled_mpu.averageTick = _data->profiled_mpu.averageTick;
  _msg-> profiled_mpu.averageTime = _data->profiled_mpu.averageTime;
  _msg-> profiled_mpu.averageTime2 = _data->profiled_mpu.averageTime2;
 
  _msg-> profiled_wifi.timestamp = _data->profiled_wifi.ts;
  _msg-> profiled_wifi.averageIterationCount = _data->profiled_wifi.averageIterationCount;
  _msg-> profiled_wifi.averageTick = _data->profiled_wifi.averageTick;
  _msg-> profiled_wifi.averageTime = _data->profiled_wifi.averageTime;
  _msg-> profiled_wifi.averageTime2 = _data->profiled_wifi.averageTime2;

  _msg-> profiled_steer.timestamp = _data->profiled_steer.ts;
  _msg-> profiled_steer.averageIterationCount = _data->profiled_steer.averageIterationCount;
  _msg-> profiled_steer.averageTick = _data->profiled_steer.averageTick;
  _msg-> profiled_steer.averageTime = _data->profiled_steer.averageTime;
  _msg-> profiled_steer.averageTime2 = _data->profiled_steer.averageTime2;
 
  
}

void printdata(const debug_data *_data)
{
/*
  ROS_DEBUG_THROTTLE(30,  "d.pidtt %d", _data->tune_type);
  ROS_DEBUG_THROTTLE(30,  "d.ts %d", _data->timestamp);
  ROS_DEBUG_THROTTLE(30,  "d.yaw %f", _data->yaw);
  ROS_DEBUG_THROTTLE(30,  "d.pitch %f", _data->pitch);
  ROS_DEBUG_THROTTLE(30,  "d.roll %f", _data->roll);
  
  ROS_DEBUG_THROTTLE(30,  "d.mR.ts %d", _data->mpuRAW.timestamp);
  ROS_DEBUG_THROTTLE(30,  "d.mR.ax %d", _data->mpuRAW.AcX);
  ROS_DEBUG_THROTTLE(30,  "d.mR.ay %d", _data->mpuRAW.AcY);
  ROS_DEBUG_THROTTLE(30,  "d.mR.az %d", _data->mpuRAW.AcZ);
  ROS_DEBUG_THROTTLE(30,  "d.mR.Tmp %d", _data->mpuRAW.Tmp);
  ROS_DEBUG_THROTTLE(30,  "d.mR.gx %d", _data->mpuRAW.GyX);
  ROS_DEBUG_THROTTLE(30,  "d.mR.gy %d", _data->mpuRAW.GyY);
  ROS_DEBUG_THROTTLE(30,  "d.mR.gz %d", _data->mpuRAW.GyZ);
  
  //ROS_DEBUG_THROTTLE(30,  "d.mD.ts %d", _data->mpuData.timestamp);
  //ROS_DEBUG_THROTTLE(30,  "d.mD.ax %d", _data->mpuData.AcX);
  //ROS_DEBUG_THROTTLE(30,  "d.mD.ay %d", _data->mpuData.AcY);
  //ROS_DEBUG_THROTTLE(30,  "d.mD.az %d", _data->mpuData.AcZ);
  //ROS_DEBUG_THROTTLE(30,  "d.mD.Tmp %d", _data->mpuData.Tmp);
  //ROS_DEBUG_THROTTLE(30,  "d.mD.gx %d", _data->mpuData.GyX);
  //ROS_DEBUG_THROTTLE(30,  "d.mD.gy %d", _data->mpuData.GyY);
  //ROS_DEBUG_THROTTLE(30,  "d.mD.gz %d", _data->mpuData.GyZ);

  ROS_DEBUG_THROTTLE(30,  "d.pgh %f", _data->pingheight);

  ROS_DEBUG_THROTTLE(30,  "d.pidfb.ts %f", _data->ppfb.timestamp);
  ROS_DEBUG_THROTTLE(30,  "d.pidfb.S %f", _data->ppfb.Setpoint);
  ROS_DEBUG_THROTTLE(30,  "d.pidfb.I %f", _data->ppfb.Input);
  ROS_DEBUG_THROTTLE(30,  "d.pidfb.O %f", _data->ppfb.Output);
  ROS_DEBUG_THROTTLE(30,  "d.pidfb.Kp %f", _data->ppfb.Kp);
  ROS_DEBUG_THROTTLE(30,  "d.pidfb.Ki %f", _data->ppfb.Ki);
  ROS_DEBUG_THROTTLE(30,  "d.pidfb.Kd %f", _data->ppfb.Kd);

  ROS_DEBUG_THROTTLE(30,  "d.pidlr.ts %f", _data->pplr.timestamp);
  ROS_DEBUG_THROTTLE(30,  "d.pidlr.S %f", _data->pplr.Setpoint);
  ROS_DEBUG_THROTTLE(30,  "d.pidlr.I %f", _data->pplr.Input);
  ROS_DEBUG_THROTTLE(30,  "d.pidlr.O %f", _data->pplr.Output);
  ROS_DEBUG_THROTTLE(30,  "d.pidlr.Kp %f", _data->pplr.Kp);
  ROS_DEBUG_THROTTLE(30,  "d.pidlr.Ki %f", _data->pplr.Ki);
  ROS_DEBUG_THROTTLE(30,  "d.pidlr.Kd %f", _data->pplr.Kd);

  ROS_DEBUG_THROTTLE(30,  "d.pidud.ts %f", _data->ppud.timestamp);
  ROS_DEBUG_THROTTLE(30,  "d.pidud.I %f", _data->ppud.Input);
  ROS_DEBUG_THROTTLE(30,  "d.pidud.S %f", _data->ppud.Setpoint);
  ROS_DEBUG_THROTTLE(30,  "d.pidud.O %f", _data->ppud.Output);
  ROS_DEBUG_THROTTLE(30,  "d.pidud.Kp %f", _data->ppud.Kp);
  ROS_DEBUG_THROTTLE(30,  "d.pidud.Ki %f", _data->ppud.Ki);
  ROS_DEBUG_THROTTLE(30,  "d.pidud.Kd %f", _data->ppud.Kd);
  */
  ROS_DEBUG_THROTTLE(5, "d.ptt %d, d.ts %d, d.yaw %f, d.pitch %f, d.roll %f, d.mR.ts %d, d.mR.ax %d, d.mR.ay %d, d.mR.az %d, d.mR.Tmp %d, d.mR.gx %d, d.mR.gy %d, d.mR.gz %d, d.pgh %f, d.pfb.ts %d, d.pfb.S %f, d.pfb.I %f, d.pfb.O %f, d.pfb.Kp %f, d.pfb.Ki %f, d.pfb.Kd %f, d.plr.ts %d, d.plr.S %f, d.plr.I %f, d.plr.O %f, d.plr.Kp %f, d.plr.Ki %f, d.plr.Kd %f, d.pud.ts %d, d.pud.I %f, d.pud.S %f, d.pud.O %f, d.pud.Kp %f, d.pud.Ki %f, d.pud.Kd %f", _data->tune_type, _data->timestamp, _data->yaw, _data->pitch, _data->roll, _data->mpuRAW.timestamp, _data->mpuRAW.AcX, _data->mpuRAW.AcY, _data->mpuRAW.AcZ, _data->mpuRAW.Tmp, _data->mpuRAW.GyX, _data->mpuRAW.GyY, _data->mpuRAW.GyZ,  _data->pingheight, _data->ppfb.timestamp, _data->ppfb.Setpoint, _data->ppfb.Input, _data->ppfb.Output, _data->ppfb.Kp, _data->ppfb.Ki, _data->ppfb.Kd, _data->pplr.timestamp, _data->pplr.Setpoint, _data->pplr.Input, _data->pplr.Output, _data->pplr.Kp, _data->pplr.Ki, _data->pplr.Kd, _data->ppud.timestamp, _data->ppud.Input, _data->ppud.Setpoint, _data->ppud.Output, _data->ppud.Kp, _data->ppud.Ki, _data->ppud.Kd);
}

#define LISTENER
using namespace std;

void chatterCallback(const atom_esp_master::alldata msg)
{
  //printdata(data);
  //ROS_INFO("I heard: [%s]", msg->data.c_str());
}

void joyCallback(const atom_esp_joy::joydata msg)
{

  //ROS_DEBUG_THROTTLE(10, "Sub Joy: x:%d, y:%d, z:%d, s:%d, b:" SHORT_TO_BINARY_PATTERN, msg.X, msg.Y, msg.Z, msg.S, SHORT_TO_BINARY(msg.buttons) );

  setpoints.timestampsec = msg.header.stamp.sec;
  setpoints.timestampnsec = msg.header.stamp.nsec;
  setpoints.x = msg.X;
  setpoints.y = msg.Y;
  setpoints.z = msg.Z;
  setpoints.s = msg.S;
  setpoints.buttons = msg.buttons;

  //ROS_DEBUG_THROTTLE(10, "Pub Joy: x:%d, y:%d, z:%d, s:%d, b:" SHORT_TO_BINARY_PATTERN, setpoints.x, setpoints.y, setpoints.z, setpoints.s, SHORT_TO_BINARY(setpoints.buttons) );


  //printdata(data);
  //ROS_INFO("I heard: [%s]", msg->data.c_str());
}

struct sockaddr name;
void *get_in_addr(struct sockaddr *sa);
void set_nonblock(int socket);
int setTCPNoDelay(int socks, int enabled);
//char* PORT = "11511";
int PORT = 11511;
//#define STDIN 00 0

const char* PID_TUNE_TYPE_str[]=
{
  "PID_TUNE_TYPE_NONE",
  "PID_TUNE_TYPE_LEFT_RIGHT",
  "PID_TUNE_TYPE_FORE_BACK",
  "PID_TUNE_TYPE_UP_DOWN",
  "PID_TUNE_TYPE_TUNING_DONE",
  "PID_TUNE_TYPE_MAX"
};

int main (int argc, char** argv)
{

  double dt_imu;
  struct sigaction sigIntHandler;

  sigIntHandler.sa_handler = my_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;

  sigaction(SIGINT, &sigIntHandler, NULL);

  ros::init(argc, argv, "atom_server_node");

  ROS_INFO("Starting up...");
  
  printf("%c]0;%s%c", '\033', "MASTER_ATOM_ESP", '\007');
  ros::NodeHandle nh;

  ros::Publisher server_pub_esp_all = nh.advertise<atom_esp_master::alldata>("atom_alldata", 1000);
  ros::Publisher server_pub_esp_imu = nh.advertise<sensor_msgs::Imu>("atom_imudata", 1000);
  
  /*ros::Publisher server_pub_esp_perf_loop = nh.advertise<atom_esp_master::Profiler_data>("atom_perf_loop", 100);
  ros::Publisher server_pub_esp_perf_mpu = nh.advertise<atom_esp_master::Profiler_data>("atom_perf_mpu", 100);
  ros::Publisher server_pub_esp_perf_wifi = nh.advertise<atom_esp_master::Profiler_data>("atom_perf_wifi", 100);
  ros::Publisher server_pub_esp_perf_steer = nh.advertise<atom_esp_master::Profiler_data>("atom_perf_steer", 100);*/
  
  //ros::Subscriber server_sub = nh.subscribe("atom_alldata", 1000, chatterCallback); // test sub
  ros::Rate loop_rate(1000);

  //char buffer[SIZE_OF_ALL_DATA+1];

  ROS_INFO("SIZE_OF_ALL_DATA %d", (int)SIZE_OF_ALL_DATA);

  int status, sock, adrlen, new_sd;

  struct addrinfo hints;
  //struct addrinfo *servinfo;  //will point to the results
  struct sockaddr_in servaddr, clientaddr;
  socklen_t clilen;

  //store the connecting address and size
  struct sockaddr_storage their_addr;
  socklen_t their_addr_size;

  fd_set read_flags,write_flags; // the flag sets to be used
  struct timeval waitd = {10, 0};          // the max wait time for an event
  int sel;                      // holds return value for select();


  //socket infoS
  memset(&hints, 0, sizeof hints); //make sure the struct is empty
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM; //tcp
  hints.ai_flags = AI_PASSIVE;     //use local-host address


  ROS_WARN("[ESP]: getaddrinfo Bypassed");

  //make socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    ROS_ERROR("[ESP]: server socket failure %d", errno);
    //printf("\nserver socket failure %m", errno);
    exit(1);
  }
  else
  {
    ROS_DEBUG("[ESP]: socket OK");
  }
  
  
  if(-1 == setTCPNoDelay(sock, 1))
  {
    ROS_ERROR("[ESP]: setsockopt TCP_NODELAY");
    //perror("setsockopt");
    exit(1);
  }
  else
  {
     ROS_DEBUG("[ESP]: setsockopt OK TCP_NODELAY");
  }

  //allow reuse of port
  int yes=1;
  if (setsockopt(sock,SOL_SOCKET, SO_REUSEADDR,&yes,sizeof(int)) == -1) 
  {
    ROS_ERROR("[ESP]: setsockopt SO_REUSEADDR");
    //perror("setsockopt");
    exit(1);
  }
  else
  {
    ROS_DEBUG("[ESP]: setsockopt OK SO_REUSEADDR");
  }


  bzero( &servaddr, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htons(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  if (bind(sock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
  ROS_ERROR("[ESP]: ERROR on binding");
  else
  {
    ROS_DEBUG("[ESP]: Bind OK");
  }


  //listen
  if(listen(sock, 5) < 0) {
    ROS_ERROR("[ESP]: Listen error %d", errno);
    exit(1);
  }
  else
  {
    ROS_DEBUG("[ESP]: Listen OK");
  }
  their_addr_size = sizeof(their_addr);


  //accept
  relink:
  ROS_INFO_STREAM("[ESP]: Waiting for connection ...");
  new_sd = accept(sock, (struct sockaddr*)&their_addr, &their_addr_size);
  if( new_sd < 0) {
    ROS_ERROR("[ESP]: Accept error %d", errno);
    exit(1);
  }
  else
  {
    ROS_DEBUG_STREAM("[ESP]: Accept OK");
  }

  //set non blocking
  set_nonblock(new_sd);
  ROS_INFO_STREAM("[ESP]: Successful Connection!");

  //char in[SIZE_OF_ALL_DATA];
  //char out[SIZE_OF_GMSETPOINTS_DATA];
  //memset(&in, 0, SIZE_OF_ALL_DATA);
  //memset(&out, 0, SIZE_OF_GMSETPOINTS_DATA);
  int numSent;
  int numRead;


  ros::Subscriber joy_sub = nh.subscribe("atom_joydata", 2000, joyCallback); // test sub

  //setpoints.timestampsec = 1;
  
  int32_t count = 0;
  while(ros::ok())
  {

    FD_ZERO(&read_flags);
    FD_ZERO(&write_flags);
    FD_SET(new_sd, &read_flags);
    FD_SET(new_sd, &write_flags);
    FD_SET(STDIN_FILENO, &read_flags);
    FD_SET(STDIN_FILENO, &write_flags);

    sel = select(new_sd+1, &read_flags, &write_flags, (fd_set*)0, &waitd);

    //if an error with select
    if(sel < 0)
    continue;

    //socket ready for reading
    if(FD_ISSET(new_sd, &read_flags)) {

      //clear set
      FD_CLR(new_sd, &read_flags);

      //memset(&in, 0, SIZE_OF_ALL_DATA);
      memset(&all_data, 0, SIZE_OF_ALL_DATA);
      //ROS_DEBUG_THROTTLE(30, "LOOP %d", __LINE__);
      numRead = recv(new_sd, (void*)&all_data, SIZE_OF_ALL_DATA, 0); // Can be made multithreaded to buffer it
      //ROS_DEBUG_THROTTLE(30, "LOOP %d , pidmode: %d", __LINE__, all_data.tune_type);
      
      if(numRead <= 0) {
        ROS_ERROR_STREAM("[ESP]: Error in socket, probably closed by client, recovery attempt ... ");
        ROS_ERROR_STREAM("[ESP]: ... [press CTRL+\\ to force exit]");
        close(new_sd);
        goto relink;
        //break;
      }
      else //if((((char*)(&all_data))[0] != '\0') || (SIZE_OF_ALL_DATA == numRead) )
      {
        //cout<<"\nClient: "<<in;
        //memcpy((char*)&all_data, in, SIZE_OF_ALL_DATA);
        printdata(&all_data);
	//ROS_DEBUG_THROTTLE(30, "LOOP %d", __LINE__);
        copy_alldata(&all_data, &msg);
        copy_imudata(&all_data, &imudata);
        //msg.header.stamp = ros::Time::now();
        // msg.H.frame_id = "?"
        //msg.header.seq = count++;
        
	//if(0 != setpoints.timestampsec)
	{
	    //ROS_DEBUG_THROTTLE(30, "LOOP %d", __LINE__);
            int n = write(new_sd, &setpoints, SIZE_OF_GMSETPOINTS_DATA); // SEEMS OK: Thread safety could be an issue
            if (n < 0)
            {
              ROS_ERROR_STREAM("[ESP]: ERROR writing to socket, recovery attempt... ");
              ROS_ERROR_STREAM("[ESP]: ... [press CTRL+\\ to force exit]"); 
              close(new_sd);
              goto relink;
            }
        }
        
        msg.header.stamp = ros::Time::now();
	
	dt_imu = msg.header.stamp.toSec() - imudatalast.header.stamp.toSec();
	
        ROS_DEBUG_THROTTLE(0.5, "[ESP]: DATA from ESP dtimu %f | %d | %f, %f, %f | %d, %d, %d, %d, %x | %x "/*%x %x %x | %x"*/, dt_imu, all_data.timestamp, (float)all_data.yaw, (float)all_data.pitch, (float)all_data.roll , setpoints.x, setpoints.y, setpoints.z, setpoints.s, setpoints.buttons
        /*, PID_TUNE_TYPE_LEFT_RIGHT == (msg.tune_type & PID_TUNE_TYPE_LEFT_RIGHT)
        ,  PID_TUNE_TYPE_FORE_BACK == (msg.tune_type & PID_TUNE_TYPE_FORE_BACK)
        , PID_TUNE_TYPE_LEFT_RIGHT
        , PID_TUNE_TYPE_FORE_BACK*/
        , msg.tune_type);
        //printdata(&data);
	 
        msg.profiled_loop.header = msg.header;
        msg.profiled_mpu.header = msg.header;
        msg.profiled_wifi.header = msg.header;
        msg.profiled_steer.header = msg.header;
        server_pub_esp_all.publish(msg);
        
        imudata.header = msg.header;
         
        // TODO: Correct following 
        // Data is corrupting so the temporary go ahead
        int allzero =
        all_data.mpuRAW.AcX || 
  	all_data.mpuRAW.AcY || 
  	all_data.mpuRAW.AcZ ||
  	all_data.mpuRAW.GyX ||
  	all_data.mpuRAW.GyY ||
  	all_data.mpuRAW.GyZ;
        
        if(0!=allzero)
        	server_pub_esp_imu.publish(imudata);
        //server_pub_esp_perf_loop.publish(msg.profiled_loop);
        //server_pub_esp_perf_mpu.publish(msg.profiled_mpu);
        //server_pub_esp_perf_wifi.publish(msg.profiled_wifi);
        //server_pub_esp_perf_steer.publish(msg.profiled_steer);
        
        imudatalast = imudata;
        
        //ROS_ERROR("?");
        // %Tag(SPINONCE)%
        ros::spinOnce();
        // %EndTag(SPINONCE)%
        
        static int pptlr_printed = 0;
        if(PID_TUNE_TYPE_LEFT_RIGHT == (msg.tune_type & PID_TUNE_TYPE_LEFT_RIGHT))
        { 
          ROS_INFO_COND(0 == pptlr_printed, "[ESP]: PID_TUNE STARTED for %s", PID_TUNE_TYPE_str[PID_TUNE_TYPE_LEFT_RIGHT]);       
          pptlr_printed = 1;
        }
        else 
        { 
         ROS_INFO_COND(1 == pptlr_printed,"[ESP]: PID_TUNE STOPPED for %s", PID_TUNE_TYPE_str[PID_TUNE_TYPE_LEFT_RIGHT]);
          pptlr_printed = 0;
        } 
        
        static int pptfb_printed = 0;
        if(PID_TUNE_TYPE_FORE_BACK == (msg.tune_type & PID_TUNE_TYPE_FORE_BACK))
        { 
          ROS_INFO_COND(0 == pptfb_printed, "[ESP]: PID_TUNE STARTED for %s", PID_TUNE_TYPE_str[PID_TUNE_TYPE_FORE_BACK]);       
          pptfb_printed = 1;
        }
        else 
        { 
         ROS_INFO_COND(1 == pptfb_printed,"[ESP]: PID_TUNE STOPPED for %s", PID_TUNE_TYPE_str[PID_TUNE_TYPE_FORE_BACK]);
          pptfb_printed = 0;
        } 
        
        // %Tag(RATE_SLEEP)%

        //ROS_DEBUG_THROTTLE(30, "LOOP %d", __LINE__);
        loop_rate.sleep();
      }
      //ROS_DEBUG_THROTTLE(30, "LOOP %d", __LINE__);

    }   //end if ready for read

    //if stdin is ready to be read
    //if(FD_ISSET(STDIN_FILENO, &read_flags))
    //    fgets(out, 255, stdin);


    //socket ready for writing
    /*if(FD_ISSET(new_sd, &write_flags)) {
    //printf("\nSocket ready for write");
    FD_CLR(new_sd, &write_flags);
    sGENERICSETPOINTS_t gmpts = setpoints;
    //copy_joydata(&gmpts, &setpoints);
    send(new_sd, &gmpts, SIZE_OF_GMSETPOINTS_DATA, 0);
    memset(&gmpts, 0, SIZE_OF_GMSETPOINTS_DATA);
  }   //end if
  */

}

ROS_WARN("EXIT");
pthread_exit(NULL);

return 0;
}

//struct sockaddr name;

void set_nonblock(int socket) {
  int flags;
  flags = fcntl(socket,F_GETFL,0);
  assert(flags != -1);
  fcntl(socket, F_SETFL, flags | O_NONBLOCK);
}

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa) {
  if (sa->sa_family == AF_INET)
  return &(((struct sockaddr_in*)sa)->sin_addr);

  return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int setTCPNoDelay(int socks, int enabled)
{

    int flag = (enabled ? 1 : 0);

    if(setsockopt(socks,IPPROTO_TCP,TCP_NODELAY,(char *)&flag,sizeof(flag)) == -1)
    {
         return -1;
    }

    return 0;
}
