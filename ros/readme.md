Getting started with ROS
-
1. A directory of your_choice_name
2. cd dir
3. mkdir src
4. cd src
5. catkin_create_pkg <your_choice_package_name> std_msgs rospy roscpp
6. cd ../../
7. pwd
8. your_choice_name directory
9. ... Update CMakeLists.txt and package.xml files
10. keep cpp, h files in src. include, msg and srv as per need
11. catkin_make
12. once build ...
13. roscore
14. source ./devel/setup.bash
15. check rospack depends1 <your_choice_package_name>
16. roswtf 
17. if warning is having topic and node names it is fine till here
18. rosrun <your_choice_package_name> <node_name>
 

