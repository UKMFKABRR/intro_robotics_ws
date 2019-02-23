// Generated by gencpp from file reactive_robot/obstacle.msg
// DO NOT EDIT!


#ifndef REACTIVE_ROBOT_MESSAGE_OBSTACLE_H
#define REACTIVE_ROBOT_MESSAGE_OBSTACLE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace reactive_robot
{
template <class ContainerAllocator>
struct obstacle_
{
  typedef obstacle_<ContainerAllocator> Type;

  obstacle_()
    : state(0)
    , angle(0.0)
    , distance(0.0)  {
    }
  obstacle_(const ContainerAllocator& _alloc)
    : state(0)
    , angle(0.0)
    , distance(0.0)  {
  (void)_alloc;
    }



   typedef uint8_t _state_type;
  _state_type state;

   typedef float _angle_type;
  _angle_type angle;

   typedef float _distance_type;
  _distance_type distance;



  enum {
    EMPTY = 0u,
    SYMMETRIC = 1u,
    ASYMMETRIC = 2u,
  };


  typedef boost::shared_ptr< ::reactive_robot::obstacle_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::reactive_robot::obstacle_<ContainerAllocator> const> ConstPtr;

}; // struct obstacle_

typedef ::reactive_robot::obstacle_<std::allocator<void> > obstacle;

typedef boost::shared_ptr< ::reactive_robot::obstacle > obstaclePtr;
typedef boost::shared_ptr< ::reactive_robot::obstacle const> obstacleConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::reactive_robot::obstacle_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::reactive_robot::obstacle_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace reactive_robot

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'reactive_robot': ['/home/jkleiber/intro_robotics_ws/src/reactive_robot/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::reactive_robot::obstacle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::reactive_robot::obstacle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::reactive_robot::obstacle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::reactive_robot::obstacle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::reactive_robot::obstacle_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::reactive_robot::obstacle_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::reactive_robot::obstacle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9dd79e7d21afdca6e8253b4c331cb2ee";
  }

  static const char* value(const ::reactive_robot::obstacle_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9dd79e7d21afdca6ULL;
  static const uint64_t static_value2 = 0xe8253b4c331cb2eeULL;
};

template<class ContainerAllocator>
struct DataType< ::reactive_robot::obstacle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "reactive_robot/obstacle";
  }

  static const char* value(const ::reactive_robot::obstacle_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::reactive_robot::obstacle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 EMPTY = 0\n\
uint8 SYMMETRIC = 1\n\
uint8 ASYMMETRIC = 2\n\
uint8 state\n\
float32 angle\n\
float32 distance\n\
";
  }

  static const char* value(const ::reactive_robot::obstacle_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::reactive_robot::obstacle_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.state);
      stream.next(m.angle);
      stream.next(m.distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct obstacle_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::reactive_robot::obstacle_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::reactive_robot::obstacle_<ContainerAllocator>& v)
  {
    s << indent << "state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.state);
    s << indent << "angle: ";
    Printer<float>::stream(s, indent + "  ", v.angle);
    s << indent << "distance: ";
    Printer<float>::stream(s, indent + "  ", v.distance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // REACTIVE_ROBOT_MESSAGE_OBSTACLE_H
