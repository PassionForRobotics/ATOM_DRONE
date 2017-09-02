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
// %Tag(ROS_HEADER)%
#include "ros/ros.h"
// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%
#include "std_msgs/String.h"
#include "atom_esp_joy/joydata.h"
// %EndTag(MSG_HEADER)%


#include <iostream>
#include "atom_esp_joy/Extreme3DProService.hpp"
#include <chrono>

using JoystickLibrary::Extreme3DProService;
//using JoystickLibrary::Xbox360Service;
using JoystickLibrary::Extreme3DProButton;
using JoystickLibrary::POV;

Extreme3DProService& es = Extreme3DProService::GetInstance();


#include <sstream>

//#include "atom_esp_joy/JoyServiceRun.hpp"
//Extreme3DProServiceRun joyserrun(0);

atom_esp_joy::joydata joydata;

void LogitechAxes(int id)
{
    int x, y, z, slider;
    std::map<Extreme3DProButton, bool> buttons;
    POV pov;

    if (!es.GetX(id, x))
        x = 0;
    if (!es.GetY(id, y))
        y = 0;
    if (!es.GetZRot(id, z))
        z = 0;
    if (!es.GetSlider(id, slider))
        slider = 0;

    if( ! es.GetButtons(id, buttons))
    {

    }
    if( ! es.GetPOV(id, pov))
    {

    }


    std::cout << "X: " << x << " | Y: " << y << " | Z: " << z << " | Slider: " << slider << " ";//std::endl;
    std::cout << "| Buttons: [ ";

    for (auto pair : buttons)
        std::cout << static_cast<int>(pair.first) << ": " << pair.second << " | ";

    std::cout << " ] | POV: " << (int)pov << std::endl;

    // X: 0 | Y: 2 | Z: 0 | Slider: 0 | Buttons: [  288:0 289:0 290:0 291:0 292:0 293:0 295:0 296:0 297:0 298:0 299:0 ] POV: 0
}

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
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
// %Tag(INIT)%
  ros::init(argc, argv, "joy_node");
// %EndTag(INIT)%

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
// %Tag(NODEHANDLE)%
  ros::NodeHandle n;
// %EndTag(NODEHANDLE)%

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
// %Tag(PUBLISHER)%
  ros::Publisher joydata_pub = n.advertise<atom_esp_joy::joydata>("joydata", 1000);
// %EndTag(PUBLISHER)%

// %Tag(LOOP_RATE)%
  ros::Rate loop_rate(10);
// %EndTag(LOOP_RATE)%

    bool s = es.Initialize();
    std::cout << "Waiting for js plugin" << std::endl;
    while (es.GetNumberConnected() < 1);

   //joyserrun.Start();
  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
// %Tag(ROS_OK)%
  int count = 0;
  while (ros::ok())
  {
// %EndTag(ROS_OK)%
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
// %Tag(FILL_MESSAGE)%
    atom_esp_joy::joydata msg;
    int x, y, z, s, btns; // please check the type 16/32 bits
    //joyserrun.GetAbsoluteAxesAndBtns(&x, &y, &z, &s, &btns);
    auto& a = es.GetIDs();
        if (a.size() <= 0)
            continue;
        LogitechAxes(a[0]);
    //std::stringstream ss;
    //ss << "hello world " << count;
    msg = msg;
// %EndTag(FILL_MESSAGE)%

// %Tag(ROSCONSOLE)%
    //ROS_INFO("%s", msg.data.c_str());
// %EndTag(ROSCONSOLE)%

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
// %Tag(PUBLISH)%
    joydata_pub.publish(msg);
// %EndTag(PUBLISH)%

// %Tag(SPINONCE)%
    ros::spinOnce();
// %EndTag(SPINONCE)%

// %Tag(RATE_SLEEP)%
    loop_rate.sleep();
// %EndTag(RATE_SLEEP)%
    ++count;
  }


  return 0;
}
// %EndTag(FULLTEXT)%
