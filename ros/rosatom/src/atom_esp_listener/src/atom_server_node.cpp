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

#include <atom_esp_listener/alldata.h>
atom_esp_listener::alldata msg;

#include "atom_esp_joy/joydata.h"
atom_esp_joy::joydata joydata;

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


void copy_alldata(const debug_data *_data, atom_esp_listener::alldata *_msg)
{
  _msg->  mpuData_AcX         = _data->mpuData.AcX;
  _msg->  mpuData_AcY         = _data->mpuData.AcY;
  _msg->  mpuData_AcZ         = _data->mpuData.AcZ;
  _msg->  mpuData_timestamp   = _data->mpuData.timestamp;
  _msg->  mpuData_Tmp         = _data->mpuData.Tmp;
  _msg->  mpuData_GyX         = _data->mpuData.GyX;
  _msg->  mpuData_GyY         = _data->mpuData.GyY;
  _msg->  mpuData_GyZ         = _data->mpuData.GyZ;

  _msg->  mpuRAW_AcX          = _data->mpuRAW.AcX;
  _msg->  mpuRAW_AcY          = _data->mpuRAW.AcY;
  _msg->  mpuRAW_AcZ          = _data->mpuRAW.AcZ;
  _msg->  mpuRAW_timestamp    = _data->mpuRAW.timestamp;
  _msg->  mpuRAW_Tmp          = _data->mpuRAW.Tmp;
  _msg->  mpuRAW_GyX          = _data->mpuRAW.GyX;
  _msg->  mpuRAW_GyY          = _data->mpuRAW.GyY;
  _msg->  mpuRAW_GyZ          = _data->mpuRAW.GyZ;

  _msg->  pingheight          = _data->pingheight;

  _msg->  ppfb_timestamp      = _data->ppfb.timestamp;
  _msg->  ppfb_Input          = _data->ppfb.Input;
  _msg->  ppfb_Kd             = _data->ppfb.Kd;
  _msg->  ppfb_Ki             = _data->ppfb.Ki;
  _msg->  ppfb_Kp             = _data->ppfb.Kp;
  _msg->  ppfb_Output         = _data->ppfb.Output;
  _msg->  ppfb_Setpoint       = _data->ppfb.Setpoint;

  _msg->  pplr_timestamp      = _data->pplr.timestamp;
  _msg->  pplr_Input          = _data->pplr.Input;
  _msg->  pplr_Kd             = _data->pplr.Kd;
  _msg->  pplr_Ki             = _data->pplr.Ki;
  _msg->  pplr_Kp             = _data->pplr.Kp;
  _msg->  pplr_Output         = _data->pplr.Output;
  _msg->  pplr_Setpoint       = _data->pplr.Setpoint;

  _msg->  ppud_timestamp      = _data->ppud.timestamp;
  _msg->  ppud_Input          = _data->ppud.Input;
  _msg->  ppud_Kd             = _data->ppud.Kd;
  _msg->  ppud_Ki             = _data->ppud.Ki;
  _msg->  ppud_Kp             = _data->ppud.Kp;
  _msg->  ppud_Output         = _data->ppud.Output;
  _msg->  ppud_Setpoint       = _data->ppud.Setpoint;

  _msg->  yaw                 = _data->yaw;
  _msg->  pitch               = _data->pitch;
  _msg->  roll                = _data->roll;

  _msg->  timestamp           = _data->timestamp;
  _msg->  tune_type           = _data->tune_type;


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
  
  ROS_DEBUG_THROTTLE(30,  "d.mD.ts %d", _data->mpuData.timestamp);
  ROS_DEBUG_THROTTLE(30,  "d.mD.ax %d", _data->mpuData.AcX);
  ROS_DEBUG_THROTTLE(30,  "d.mD.ay %d", _data->mpuData.AcY);
  ROS_DEBUG_THROTTLE(30,  "d.mD.az %d", _data->mpuData.AcZ);
  ROS_DEBUG_THROTTLE(30,  "d.mD.Tmp %d", _data->mpuData.Tmp);
  ROS_DEBUG_THROTTLE(30,  "d.mD.gx %d", _data->mpuData.GyX);
  ROS_DEBUG_THROTTLE(30,  "d.mD.gy %d", _data->mpuData.GyY);
  ROS_DEBUG_THROTTLE(30,  "d.mD.gz %d", _data->mpuData.GyZ);

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
  ROS_DEBUG_THROTTLE(5, "d.ptt %d, d.ts %d, d.yaw %f, d.pitch %f, d.roll %f, d.mR.ts %d, d.mR.ax %d, d.mR.ay %d, d.mR.az %d, d.mR.Tmp %d, d.mR.gx %d, d.mR.gy %d, d.mR.gz %d, d.mD.ts %d, d.mD.ax %d, d.mD.ay %d, d.mD.az %d, d.mD.Tmp %d, d.mD.gx %d, d.mD.gy %d, d.mD.gz %d , d.pgh %f, d.pfb.ts %d, d.pfb.S %f, d.pfb.I %f, d.pfb.O %f, d.pfb.Kp %f, d.pfb.Ki %f, d.pfb.Kd %f, d.plr.ts %d, d.plr.S %f, d.plr.I %f, d.plr.O %f, d.plr.Kp %f, d.plr.Ki %f, d.plr.Kd %f, d.pud.ts %d, d.pud.I %f, d.pud.S %f, d.pud.O %f, d.pud.Kp %f, d.pud.Ki %f, d.pud.Kd %f", _data->tune_type, _data->timestamp, _data->yaw, _data->pitch, _data->roll, _data->mpuRAW.timestamp, _data->mpuRAW.AcX, _data->mpuRAW.AcY, _data->mpuRAW.AcZ, _data->mpuRAW.Tmp, _data->mpuRAW.GyX, _data->mpuRAW.GyY, _data->mpuRAW.GyZ, _data->mpuData.timestamp, _data->mpuData.AcX, _data->mpuData.AcY, _data->mpuData.AcZ, _data->mpuData.Tmp, _data->mpuData.GyX, _data->mpuData.GyY, _data->mpuData.GyZ, _data->pingheight, _data->ppfb.timestamp, _data->ppfb.Setpoint, _data->ppfb.Input, _data->ppfb.Output, _data->ppfb.Kp, _data->ppfb.Ki, _data->ppfb.Kd, _data->pplr.timestamp, _data->pplr.Setpoint, _data->pplr.Input, _data->pplr.Output, _data->pplr.Kp, _data->pplr.Ki, _data->pplr.Kd, _data->ppud.timestamp, _data->ppud.Input, _data->ppud.Setpoint, _data->ppud.Output, _data->ppud.Kp, _data->ppud.Ki, _data->ppud.Kd);
}

#define LISTENER
using namespace std;

void chatterCallback(const atom_esp_listener::alldata msg)
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
//char* PORT = "11511";
int PORT = 11511;
//#define STDIN 00 0

int main (int argc, char** argv)
{
  struct sigaction sigIntHandler;

  sigIntHandler.sa_handler = my_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;

  sigaction(SIGINT, &sigIntHandler, NULL);

  ros::init(argc, argv, "atom_server_node");

  ROS_INFO("Starting up...");
  ros::NodeHandle nh;

  ros::Publisher server_pub = nh.advertise<atom_esp_listener::alldata>("atom_alldata", 1000);
  //ros::Subscriber server_sub = nh.subscribe("atom_drone_all_data", 1000, chatterCallback); // test sub
  ros::Rate loop_rate(10);

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

  //allow reuse of port
  int yes=1;
  if (setsockopt(sock,SOL_SOCKET, SO_REUSEADDR,&yes,sizeof(int)) == -1) {
    ROS_ERROR("[ESP]: setsockopt");
    //perror("setsockopt");
    exit(1);
  }
  else
  {
    ROS_DEBUG("[ESP]: setsockopt OK");
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
        //msg.header.stamp = ros::Time::now();
        // msg.H.frame_id = "?"
        //msg.header.seq = count++;
        ROS_DEBUG_THROTTLE(0.5, "[ESP]: DATA from ESP | %d | %f, %f, %f", all_data.timestamp, (float)all_data.yaw, (float)all_data.pitch, (float)all_data.roll );
        //printdata(&data);

        server_pub.publish(msg);
        //ROS_ERROR("?");
        // %Tag(SPINONCE)%
        ros::spinOnce();
        // %EndTag(SPINONCE)%

        // %Tag(RATE_SLEEP)%

	if(0 != setpoints.timestampsec)
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
        //ROS_DEBUG_THROTTLE(30, "LOOP %d", __LINE__);
        //loop_rate.sleep();
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

