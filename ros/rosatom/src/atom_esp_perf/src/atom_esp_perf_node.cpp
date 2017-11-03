/*
 * Copyright (C) 2008, Morgan Quigley and Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

// %Tag(FULLTEXT)%
#include "ros/ros.h"
#include "std_msgs/String.h"


// To include other data headers an empty .msg file needs to be there
#include <atom_esp_master/alldata.h>
atom_esp_master::alldata msg;

//#include "atom_esp_master/alldata.h"
//atom_esp_master::alldata msg;

#include "atom_esp_joy/joydata.h"
atom_esp_joy::joydata joydata;

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
// %Tag(CALLBACK)%
//void chatterCallback(const std_msgs::String::ConstPtr& msg)
//{
//  ROS_INFO("I heard: [%s]", msg->data.c_str());
//}

ros::Publisher *_server_pub_esp_perf_loop;
ros::Publisher *_server_pub_esp_perf_mpu;
ros::Publisher *_server_pub_esp_perf_wifi;
ros::Publisher *_server_pub_esp_perf_steer;

void chatterCallback(const atom_esp_master::alldata msg)
{
  
  //printdata(data);
  //ROS_INFO("I heard: [%s]", msg->data.c_str());
        
        // Akready done in listener
	//msg.profiled_loop.header = msg.header;
	//msg.profiled_mpu.header = msg.header;
	//msg.profiled_wifi.header = msg.header;
	//msg.profiled_steer.header = msg.header;

	_server_pub_esp_perf_loop->publish(msg.profiled_loop);
	_server_pub_esp_perf_mpu->publish(msg.profiled_mpu);
	_server_pub_esp_perf_wifi->publish(msg.profiled_wifi);
	_server_pub_esp_perf_steer->publish(msg.profiled_steer);

}
// %EndTag(CALLBACK)%

int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "atom_perf_node");
  
  printf("%c]0;%s%c", '\033', "PERF_ATOM_ESP", '\007');

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle nh;

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages
   * on a given topic.  This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing.  Messages are passed to a callback function, here
   * called chatterCallback.  subscribe() returns a Subscriber object that you
   * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
   * object go out of scope, this callback will automatically be unsubscribed from
   * this topic.
   *
   * The second parameter to the subscribe() function is the size of the message
   * queue.  If messages are arriving faster than they are being processed, this
   * is the number of messages that will be buffered up before beginning to throw
   * away the oldest ones.
   */
   
   ros::Publisher server_pub_esp_perf_loop = nh.advertise<atom_esp_master::Profiler_data>("atom_perf_loop", 100);
  ros::Publisher server_pub_esp_perf_mpu = nh.advertise<atom_esp_master::Profiler_data>("atom_perf_mpu", 100);
  ros::Publisher server_pub_esp_perf_wifi = nh.advertise<atom_esp_master::Profiler_data>("atom_perf_wifi", 100);
  ros::Publisher server_pub_esp_perf_steer = nh.advertise<atom_esp_master::Profiler_data>("atom_perf_steer", 100);
  
  _server_pub_esp_perf_loop = &server_pub_esp_perf_loop;
  _server_pub_esp_perf_mpu = &server_pub_esp_perf_mpu;
  _server_pub_esp_perf_wifi = &server_pub_esp_perf_wifi;
  _server_pub_esp_perf_steer= &server_pub_esp_perf_steer;

// %Tag(SUBSCRIBER)%
  ros::Subscriber sub = nh.subscribe("atom_alldata", 1000, chatterCallback);
// %EndTag(SUBSCRIBER)%

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
// %Tag(SPIN)%
  ros::spin();
// %EndTag(SPIN)%

  return 0;
}
// %EndTag(FULLTEXT)%
