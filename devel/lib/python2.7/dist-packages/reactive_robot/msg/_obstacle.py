# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from reactive_robot/obstacle.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg

class obstacle(genpy.Message):
  _md5sum = "9def4b737c98a8f46cacc0980db0cf56"
  _type = "reactive_robot/obstacle"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """uint8 EMPTY = 0
uint8 SYMMETRIC = 1
uint8 ASYMMETRIC = 2
uint8 state
float32 angle
float32 distance
geometry_msgs/Twist drive
================================================================================
MSG: geometry_msgs/Twist
# This expresses velocity in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z"""
  # Pseudo-constants
  EMPTY = 0
  SYMMETRIC = 1
  ASYMMETRIC = 2

  __slots__ = ['state','angle','distance','drive']
  _slot_types = ['uint8','float32','float32','geometry_msgs/Twist']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       state,angle,distance,drive

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(obstacle, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.state is None:
        self.state = 0
      if self.angle is None:
        self.angle = 0.
      if self.distance is None:
        self.distance = 0.
      if self.drive is None:
        self.drive = geometry_msgs.msg.Twist()
    else:
      self.state = 0
      self.angle = 0.
      self.distance = 0.
      self.drive = geometry_msgs.msg.Twist()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_B2f6d().pack(_x.state, _x.angle, _x.distance, _x.drive.linear.x, _x.drive.linear.y, _x.drive.linear.z, _x.drive.angular.x, _x.drive.angular.y, _x.drive.angular.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.drive is None:
        self.drive = geometry_msgs.msg.Twist()
      end = 0
      _x = self
      start = end
      end += 57
      (_x.state, _x.angle, _x.distance, _x.drive.linear.x, _x.drive.linear.y, _x.drive.linear.z, _x.drive.angular.x, _x.drive.angular.y, _x.drive.angular.z,) = _get_struct_B2f6d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_B2f6d().pack(_x.state, _x.angle, _x.distance, _x.drive.linear.x, _x.drive.linear.y, _x.drive.linear.z, _x.drive.angular.x, _x.drive.angular.y, _x.drive.angular.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.drive is None:
        self.drive = geometry_msgs.msg.Twist()
      end = 0
      _x = self
      start = end
      end += 57
      (_x.state, _x.angle, _x.distance, _x.drive.linear.x, _x.drive.linear.y, _x.drive.linear.z, _x.drive.angular.x, _x.drive.angular.y, _x.drive.angular.z,) = _get_struct_B2f6d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_B2f6d = None
def _get_struct_B2f6d():
    global _struct_B2f6d
    if _struct_B2f6d is None:
        _struct_B2f6d = struct.Struct("<B2f6d")
    return _struct_B2f6d
