A directory of your_choice_name
cd dir
mkdir src
cd src
catkin_create_pkg <your_choice_package_name> std_msgs rospy roscpp
cd ../../
pwd
your_choice_name directory
... Update CMakeLists.txt and package.xml files
keep cpp, h files in src and include respectively
catkin_make
once build ...
roscore
source ./devel/setup.bash
check rospack depends1 <your_choice_package_name>
roswtf 
if warning is having topic and node names it is fine till here
rosrun <your_choice_package_name> <node_name>
 

