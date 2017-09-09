// Generated by gencpp from file atom_esp_listener/mpudata.msg
// DO NOT EDIT!


#ifndef ATOM_ESP_LISTENER_MESSAGE_MPUDATA_H
#define ATOM_ESP_LISTENER_MESSAGE_MPUDATA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace atom_esp_listener
{
template <class ContainerAllocator>
struct mpudata_
{
  typedef mpudata_<ContainerAllocator> Type;

  mpudata_()
    : header()
    , timestamp(0)
    , AcX(0)
    , AcY(0)
    , AcZ(0)
    , Tmp(0)
    , GyX(0)
    , GyY(0)
    , GyZ(0)  {
    }
  mpudata_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , timestamp(0)
    , AcX(0)
    , AcY(0)
    , AcZ(0)
    , Tmp(0)
    , GyX(0)
    , GyY(0)
    , GyZ(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint32_t _timestamp_type;
  _timestamp_type timestamp;

   typedef int16_t _AcX_type;
  _AcX_type AcX;

   typedef int16_t _AcY_type;
  _AcY_type AcY;

   typedef int16_t _AcZ_type;
  _AcZ_type AcZ;

   typedef int16_t _Tmp_type;
  _Tmp_type Tmp;

   typedef int16_t _GyX_type;
  _GyX_type GyX;

   typedef int16_t _GyY_type;
  _GyY_type GyY;

   typedef int16_t _GyZ_type;
  _GyZ_type GyZ;




  typedef boost::shared_ptr< ::atom_esp_listener::mpudata_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::atom_esp_listener::mpudata_<ContainerAllocator> const> ConstPtr;

}; // struct mpudata_

typedef ::atom_esp_listener::mpudata_<std::allocator<void> > mpudata;

typedef boost::shared_ptr< ::atom_esp_listener::mpudata > mpudataPtr;
typedef boost::shared_ptr< ::atom_esp_listener::mpudata const> mpudataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::atom_esp_listener::mpudata_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::atom_esp_listener::mpudata_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace atom_esp_listener

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'atom_esp_listener': ['/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/src/atom_esp_listener/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::atom_esp_listener::mpudata_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::atom_esp_listener::mpudata_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::atom_esp_listener::mpudata_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::atom_esp_listener::mpudata_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::atom_esp_listener::mpudata_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::atom_esp_listener::mpudata_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::atom_esp_listener::mpudata_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2da27b00d8c3d05a9b15d685c8870e9d";
  }

  static const char* value(const ::atom_esp_listener::mpudata_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2da27b00d8c3d05aULL;
  static const uint64_t static_value2 = 0x9b15d685c8870e9dULL;
};

template<class ContainerAllocator>
struct DataType< ::atom_esp_listener::mpudata_<ContainerAllocator> >
{
  static const char* value()
  {
    return "atom_esp_listener/mpudata";
  }

  static const char* value(const ::atom_esp_listener::mpudata_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::atom_esp_listener::mpudata_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
uint32 timestamp\n\
int16  AcX\n\
int16  AcY\n\
int16  AcZ\n\
int16  Tmp\n\
int16  GyX\n\
int16  GyY\n\
int16  GyZ\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::atom_esp_listener::mpudata_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::atom_esp_listener::mpudata_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.timestamp);
      stream.next(m.AcX);
      stream.next(m.AcY);
      stream.next(m.AcZ);
      stream.next(m.Tmp);
      stream.next(m.GyX);
      stream.next(m.GyY);
      stream.next(m.GyZ);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct mpudata_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::atom_esp_listener::mpudata_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::atom_esp_listener::mpudata_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "timestamp: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.timestamp);
    s << indent << "AcX: ";
    Printer<int16_t>::stream(s, indent + "  ", v.AcX);
    s << indent << "AcY: ";
    Printer<int16_t>::stream(s, indent + "  ", v.AcY);
    s << indent << "AcZ: ";
    Printer<int16_t>::stream(s, indent + "  ", v.AcZ);
    s << indent << "Tmp: ";
    Printer<int16_t>::stream(s, indent + "  ", v.Tmp);
    s << indent << "GyX: ";
    Printer<int16_t>::stream(s, indent + "  ", v.GyX);
    s << indent << "GyY: ";
    Printer<int16_t>::stream(s, indent + "  ", v.GyY);
    s << indent << "GyZ: ";
    Printer<int16_t>::stream(s, indent + "  ", v.GyZ);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ATOM_ESP_LISTENER_MESSAGE_MPUDATA_H
