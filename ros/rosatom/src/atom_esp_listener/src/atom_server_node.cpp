#include <ros/ros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
#include "std_msgs/String.h"

#include <signal.h>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>

#include "/home/rahuldeo/ATOM/ATOM_DRONE/ESP8266_D1/src/data2.h"
debug_data data;

// TODO: Anything to socket proper close
// It is not working ???
// May be ROS is using it??
void my_handler(int s){
           printf("Caught signal %d\n",s);
           exit(1); 

}

void printdata(debug_data *_data)
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

  ROS_INFO("d.pgh %d", _data->pingheight);
 
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

  ROS_INFO("d.yaw %d", _data->yaw);
  ROS_INFO("d.pitch %d", _data->pitch);
  ROS_INFO("d.roll %d", _data->roll);

  ROS_INFO("d.ts %d", _data->timestamp);
  ROS_INFO("d.pidtt %d", _data->tune_type);
}

#define LISTENER 
using namespace std;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}


int main (int argc, char** argv)
{ 
  struct sigaction sigIntHandler;

  sigIntHandler.sa_handler = my_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;

  sigaction(SIGINT, &sigIntHandler, NULL);
  
  ros::init(argc, argv, "atom_server_node");
  ros::NodeHandle nh;
 
  ros::Publisher server_pub = nh.advertise<std_msgs::String>("chatter", 1000); 
  ros::Subscriber server_sub = nh.subscribe("chatter", 1000, chatterCallback);
  
  std_msgs::String message;
  std::stringstream ss;
   
  char buffer[SIZE_OF_ALL_DATA+1];
  
  ROS_INFO("SIZE_OF_ALL_DATA %d", (int)SIZE_OF_ALL_DATA);
  
  int socket_fd, accepted_socket_fd;
  
  struct sockaddr_in servaddr;
 
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0)
  ROS_ERROR_STREAM("ERROR opening socket");
  else
  ROS_INFO_STREAM("Socket openned.");
  
  int enable = 1;
  if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
  ROS_ERROR_STREAM("setsockopt(SO_REUSEADDR) failed");
  else
  {
    ROS_INFO_STREAM("Socket set.");
  }
  
 // #include <sys/socket.h>
//int keepalive_enabled = 1;
//int keepalive_time = 2;
//int keepalive_count = 3;
//int keepalive_interval = 2;
//setsockopt(socket_fd, SOL_SOCKET, SO_KEEPALIVE, 1, 
//setsockopt(socket_fd, IPPROTO_TCP, TCP_KEEPIDLE, keepalive_time, sizeof keepalive_time);
//setsockopt(socket_fd, IPPROTO_TCP, TCP_KEEPCNT, keepalive_count, sizeof keepalive_count);
//setsockopt(socket_fd, IPPROTO_TCP, TCP_KEEPINTVL, keepalive_interval, sizeof keepalive_interval);
  
  bzero( &servaddr, sizeof(servaddr));
  
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htons(INADDR_ANY);
  servaddr.sin_port = htons(11511);
  
  if (bind(socket_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
   ROS_ERROR_STREAM("ERROR on binding");
  else
  {
    ROS_INFO_STREAM("Bound.");
  }     
  
  listen(socket_fd, 1);
  ROS_INFO_STREAM("listen..");
  
  // TODO : Non-blocked
   accepted_socket_fd = accept(socket_fd, (struct sockaddr*) NULL, NULL);
    if (accepted_socket_fd < 0)
    	ROS_ERROR_STREAM("ERROR on accept");
    else
    {
      ROS_INFO_STREAM("Connected");
    }
    
  while(ros::ok())
  {
    int read_size = 0;
    ROS_INFO_STREAM("loop"); 
   
    if( (read_size = recv(accepted_socket_fd , buffer , SIZE_OF_ALL_DATA , 0)) > 0 )
    { 
      ss << buffer;
      message.data = ss.str();
      
      memcpy((char*)&data, buffer, SIZE_OF_ALL_DATA);
      ROS_INFO("buff %s", buffer);
      printdata(&data);
      
      server_pub.publish(message);
      
      ros::spinOnce();
      
      ss.str(std::string()); 
      bzero(buffer,SIZE_OF_ALL_DATA);
     
    }  
    else
    {
      ROS_INFO_STREAM("read err");
    }
     
  }
  
  return 0;
}
