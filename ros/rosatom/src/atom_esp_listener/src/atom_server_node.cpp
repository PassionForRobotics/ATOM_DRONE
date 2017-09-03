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
    
    _data->timestampsec = _msg->H.stamp.sec;
    _data->timestampnsec = _msg->H.stamp.nsec;
    
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
  ROS_INFO("d.mD.ax %d", _data->mpuData.AcX);
  ROS_INFO("d.mD.ay %d", _data->mpuData.AcY);
  ROS_INFO("d.mD.az %d", _data->mpuData.AcZ);
  ROS_INFO("d.mD.ts %d", _data->mpuData.timestamp);
  ROS_INFO("d.mD.Tmp %d", _data->mpuData.Tmp);
  ROS_INFO("d.mD.gx %d", _data->mpuData.GyX);
  ROS_INFO("d.mD.gy %d", _data->mpuData.GyY);
  ROS_INFO("d.mD.gz %d", _data->mpuData.GyZ);

  ROS_INFO("d.mR.ax %d", _data->mpuRAW.AcX);
  ROS_INFO("d.mR.ay %d", _data->mpuRAW.AcY);
  ROS_INFO("d.mR.az %d", _data->mpuRAW.AcZ);
  ROS_INFO("d.mR.ts %d", _data->mpuRAW.timestamp);
  ROS_INFO("d.mR.Tmp %d", _data->mpuRAW.Tmp);
  ROS_INFO("d.mR.gx %d", _data->mpuRAW.GyX);
  ROS_INFO("d.mR.gy %d", _data->mpuRAW.GyY);
  ROS_INFO("d.mR.gz %d", _data->mpuRAW.GyZ);

  ROS_INFO("d.pgh %f", _data->pingheight);

  ROS_INFO("d.pidfb.I %f", _data->ppfb.Input);
  ROS_INFO("d.pidfb.Kd %f", _data->ppfb.Kd);
  ROS_INFO("d.pidfb.Ki %f", _data->ppfb.Ki);
  ROS_INFO("d.pidfb.Kp %f", _data->ppfb.Kp);
  ROS_INFO("d.pidfb.O %f", _data->ppfb.Output);
  ROS_INFO("d.pidfb.S %f", _data->ppfb.Setpoint);

  ROS_INFO("d.pidlr.I %f", _data->pplr.Input);
  ROS_INFO("d.pidlr.Kd %f", _data->pplr.Kd);
  ROS_INFO("d.pidlr.Ki %f", _data->pplr.Ki);
  ROS_INFO("d.pidlr.Kp %f", _data->pplr.Kp);
  ROS_INFO("d.pidlr.O %f", _data->pplr.Output);
  ROS_INFO("d.pidlr.S %f", _data->pplr.Setpoint);

  ROS_INFO("d.pidud.I %f", _data->ppud.Input);
  ROS_INFO("d.pidud.Kd %f", _data->ppud.Kd);
  ROS_INFO("d.pidud.Ki %f", _data->ppud.Ki);
  ROS_INFO("d.pidud.Kp %f", _data->ppud.Kp);
  ROS_INFO("d.pidud.O %f", _data->ppud.Output);
  ROS_INFO("d.pidud.S %f", _data->ppud.Setpoint);

  ROS_INFO("d.yaw %f", _data->yaw);
  ROS_INFO("d.pitch %f", _data->pitch);
  ROS_INFO("d.roll %f", _data->roll);

  ROS_INFO("d.ts %d", _data->timestamp);
  ROS_INFO("d.pidtt %d", _data->tune_type);
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
   
   setpoints.timestampsec = msg.H.stamp.sec;
   setpoints.timestampnsec = msg.H.stamp.nsec;
   setpoints.x = msg.X;
   setpoints.y = msg.Y;
   setpoints.z = msg.Z;
   setpoints.s = msg.S; 
   setpoints.buttons = msg.buttons;
   
    ROS_DEBUG_THROTTLE(10, "Pub Joy: x:%d, y:%d, z:%d, s:%d, b:" SHORT_TO_BINARY_PATTERN, setpoints.x, setpoints.y, setpoints.z, setpoints.s, SHORT_TO_BINARY(setpoints.buttons) );
   
   
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
  ros::NodeHandle nh;

  ros::Publisher server_pub = nh.advertise<atom_esp_listener::alldata>("atom_alldata", 10);
  //ros::Subscriber server_sub = nh.subscribe("atom_drone_all_data", 1000, chatterCallback); // test sub
  ros::Subscriber joy_sub = nh.subscribe("atom_joydata", 10, joyCallback); // test sub
  
  ros::Rate loop_rate(10);
  
  char buffer[SIZE_OF_ALL_DATA+1];

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

    //get server info, put into servinfo
    /*if ((status = getaddrinfo("127.0.0.1", (const char *)PORT, &hints, &servinfo)) != 0) 
    {
        ROS_ERROR("getaddrinfo error: %s",  gai_strerror(status));
        //fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }
    else
    {
    	ROS_INFO("getaddrinfo OK");
    }*/
    ROS_WARN("getaddrinfo Bypassed");

    //make socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        ROS_ERROR("server socket failure %d", errno);
        //printf("\nserver socket failure %m", errno);
        exit(1);
    }
    else
    {
    	ROS_INFO("socket OK");
    }

    //allow reuse of port
    int yes=1;
    if (setsockopt(sock,SOL_SOCKET, SO_REUSEADDR,&yes,sizeof(int)) == -1) {   
        ROS_ERROR("setsockopt");
        //perror("setsockopt");
        exit(1);
    }
    else
    {
    	ROS_INFO("setsockopt OK");
    }
    
	
	  bzero( &servaddr, sizeof(servaddr));

	  servaddr.sin_family = AF_INET;
	  servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	  servaddr.sin_port = htons(PORT);

  if (bind(sock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
   ROS_ERROR_STREAM("ERROR on binding");
  else
  {
    ROS_INFO_STREAM("Bind OK");
  }
    //unlink and bind
    /*unlink("127.0.0.1");
    if(bind (sock, servaddr->ai_addr, servinfo->ai_addrlen) < 0) 
    {
        ROS_ERROR("Bind error %d", errno);
        exit(1);
    }
    else
    {
    	ROS_INFO("Bind OK");
    }*/

    //freeaddrinfo(servinfo);

    //listen
    if(listen(sock, 5) < 0) {
        ROS_ERROR("\nListen error %d", errno);
        exit(1);
    }
    else
    {
    	ROS_INFO("Listen OK");
    }
    their_addr_size = sizeof(their_addr);
    
    
    //accept
    relink: 
    new_sd = accept(sock, (struct sockaddr*)&their_addr, &their_addr_size);
    if( new_sd < 0) {
        ROS_ERROR("\nAccept error %d", errno);
        exit(1);
    }
    else
    {
    	ROS_INFO("Accept OK");
    }

    //set non blocking
    set_nonblock(new_sd);
    ROS_INFO("Successful Connection!");

    char in[SIZE_OF_ALL_DATA];
    char out[SIZE_OF_ALL_DATA];
    memset(&in, 0, SIZE_OF_ALL_DATA);
    memset(&out, 0, SIZE_OF_ALL_DATA);
    int numSent;
    int numRead;
    
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

            memset(&in, 0, SIZE_OF_ALL_DATA);

            numRead = recv(new_sd, in, SIZE_OF_ALL_DATA, 0);
            if(numRead <= 0) {
                ROS_ERROR("error in socket, probably closed by client, recovery attempt TODO");
                close(new_sd);
                goto relink;
                //break;
            }
            else if(in[0] != '\0')
            {
                //cout<<"\nClient: "<<in;
                memcpy((char*)&all_data, in, SIZE_OF_ALL_DATA);
      
	      copy_alldata(&all_data, &msg);
	      msg.H.stamp = ros::Time::now();
	      // msg.H.frame_id = "?"
	      msg.H.seq = count++;
	      ROS_DEBUG_THROTTLE(10, "DATA from ESP"); 
	      //printdata(&data);

	      server_pub.publish(msg);
	      //ROS_ERROR("?");
	      // %Tag(SPINONCE)%
	    ros::spinOnce();
	// %EndTag(SPINONCE)%

	// %Tag(RATE_SLEEP)%
	    
	      
	      int n = write(new_sd, &setpoints, SIZE_OF_GMSETPOINTS_DATA); // SEEMS OK: Thread safety could be an issue
      if (n < 0) 
      {
      ROS_ERROR("[ESP]: ERROR writing to socket, recovery attempt...");
      close(new_sd);
                goto relink;
	}
	loop_rate.sleep();      
            }

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

/*
int _main(int agrc, char** argv) {
    int status, sock, adrlen, new_sd;

    struct addrinfo hints;
    struct addrinfo *servinfo;  //will point to the results

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

    //get server info, put into servinfo
    if ((status = getaddrinfo("127.0.0.1", PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    //make socket
    sock = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sock < 0) {
        printf("\nserver socket failure %m", errno);
        exit(1);
    }

    //allow reuse of port
    int yes=1;
    if (setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    //unlink and bind
    unlink("127.0.0.1");
    if(bind (sock, servinfo->ai_addr, servinfo->ai_addrlen) < 0) {
        printf("\nBind error %m", errno);
        exit(1);
    }

    freeaddrinfo(servinfo);

    //listen
    if(listen(sock, 5) < 0) {
        printf("\nListen error %m", errno);
        exit(1);
    }
    their_addr_size = sizeof(their_addr);

    //accept
    new_sd = accept(sock, (struct sockaddr*)&their_addr, &their_addr_size);
    if( new_sd < 0) {
        printf("\nAccept error %m", errno);
        exit(1);
    }

    //set non blocking
    set_nonblock(new_sd);
    cout<<"\nSuccessful Connection!\n";

    char in[255];
    char out[255];
    memset(&in, 0, 255);
    memset(&out, 0, 255);
    int numSent;
    int numRead;

    while(1) {

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

            memset(&in, 0, 255);

            numRead = recv(new_sd, in, 255, 0);
            if(numRead <= 0) {
                printf("\nClosing socket");
                close(new_sd);
                break;
            }
            else if(in[0] != '\0')
                cout<<"\nClient: "<<in;

        }   //end if ready for read

        //if stdin is ready to be read
        if(FD_ISSET(STDIN_FILENO, &read_flags))
            fgets(out, 255, stdin);


        //socket ready for writing
        if(FD_ISSET(new_sd, &write_flags)) {
            //printf("\nSocket ready for write");
            FD_CLR(new_sd, &write_flags);
            send(new_sd, out, 255, 0);
            memset(&out, 0, 255);
        }   //end if
    }   //end while

   cout<<"\n\nExiting normally\n";
    return 0;
}*/
