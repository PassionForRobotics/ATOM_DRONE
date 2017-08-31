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

// TODO: Anything to socket proper close
// It is not working ???
// May be ROS is using it??
void my_handler(int s){
           printf("Caught signal %d\n",s);
           exit(1); 

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
   
  char buffer[255];
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
   
    if( (read_size = recv(accepted_socket_fd , buffer , 100 , 0)) > 0 )
    { 
      ss << buffer;
      message.data = ss.str();
      ROS_INFO("buff %s", buffer);
      server_pub.publish(message);
      
      ros::spinOnce();
      
       ss.str(std::string()); 
       bzero(buffer,256);
     
    }  
    else
    {
      ROS_INFO_STREAM("read err");
    }
     
  }
  
  return 0;
}
