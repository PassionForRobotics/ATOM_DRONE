# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from atom_esp_listener/alldata.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import std_msgs.msg

class alldata(genpy.Message):
  _md5sum = "89b11db5299c2f38020d1ab5e96c3b97"
  _type = "atom_esp_listener/alldata"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """Header H
int16  mpuData_AcX
int16  mpuData_AcY
int16  mpuData_AcZ
uint32  mpuData_timestamp
int16  mpuData_Tmp
int16  mpuData_GyX
int16  mpuData_GyY
int16  mpuData_GyZ

int16  mpuRAW_AcX
int16  mpuRAW_AcY
int16  mpuRAW_AcZ
uint32  mpuRAW_timestamp
int16  mpuRAW_Tmp
int16  mpuRAW_GyX
int16  mpuRAW_GyY
int16  mpuRAW_GyZ

int16  pingheight

uint32  ppfb_timestamp
float64  ppfb_Input
float64  ppfb_Kd
float64  ppfb_Ki
float64  ppfb_Kp
float64  ppfb_Output
float64  ppfb_Setpoint

uint32  pplr_timestamp
float64  pplr_Input
float64  pplr_Kd
float64  pplr_Ki
float64  pplr_Kp
float64  pplr_Output
float64  pplr_Setpoint

uint32  ppud_timestamp
float64  ppud_Input
float64  ppud_Kd
float64  ppud_Ki
float64  ppud_Kp
float64  ppud_Output
float64  ppud_Setpoint

float32  yaw
float32  pitch
float32  roll

uint32  timestamp
int16  tune_type

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id
"""
  __slots__ = ['H','mpuData_AcX','mpuData_AcY','mpuData_AcZ','mpuData_timestamp','mpuData_Tmp','mpuData_GyX','mpuData_GyY','mpuData_GyZ','mpuRAW_AcX','mpuRAW_AcY','mpuRAW_AcZ','mpuRAW_timestamp','mpuRAW_Tmp','mpuRAW_GyX','mpuRAW_GyY','mpuRAW_GyZ','pingheight','ppfb_timestamp','ppfb_Input','ppfb_Kd','ppfb_Ki','ppfb_Kp','ppfb_Output','ppfb_Setpoint','pplr_timestamp','pplr_Input','pplr_Kd','pplr_Ki','pplr_Kp','pplr_Output','pplr_Setpoint','ppud_timestamp','ppud_Input','ppud_Kd','ppud_Ki','ppud_Kp','ppud_Output','ppud_Setpoint','yaw','pitch','roll','timestamp','tune_type']
  _slot_types = ['std_msgs/Header','int16','int16','int16','uint32','int16','int16','int16','int16','int16','int16','int16','uint32','int16','int16','int16','int16','int16','uint32','float64','float64','float64','float64','float64','float64','uint32','float64','float64','float64','float64','float64','float64','uint32','float64','float64','float64','float64','float64','float64','float32','float32','float32','uint32','int16']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       H,mpuData_AcX,mpuData_AcY,mpuData_AcZ,mpuData_timestamp,mpuData_Tmp,mpuData_GyX,mpuData_GyY,mpuData_GyZ,mpuRAW_AcX,mpuRAW_AcY,mpuRAW_AcZ,mpuRAW_timestamp,mpuRAW_Tmp,mpuRAW_GyX,mpuRAW_GyY,mpuRAW_GyZ,pingheight,ppfb_timestamp,ppfb_Input,ppfb_Kd,ppfb_Ki,ppfb_Kp,ppfb_Output,ppfb_Setpoint,pplr_timestamp,pplr_Input,pplr_Kd,pplr_Ki,pplr_Kp,pplr_Output,pplr_Setpoint,ppud_timestamp,ppud_Input,ppud_Kd,ppud_Ki,ppud_Kp,ppud_Output,ppud_Setpoint,yaw,pitch,roll,timestamp,tune_type

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(alldata, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.H is None:
        self.H = std_msgs.msg.Header()
      if self.mpuData_AcX is None:
        self.mpuData_AcX = 0
      if self.mpuData_AcY is None:
        self.mpuData_AcY = 0
      if self.mpuData_AcZ is None:
        self.mpuData_AcZ = 0
      if self.mpuData_timestamp is None:
        self.mpuData_timestamp = 0
      if self.mpuData_Tmp is None:
        self.mpuData_Tmp = 0
      if self.mpuData_GyX is None:
        self.mpuData_GyX = 0
      if self.mpuData_GyY is None:
        self.mpuData_GyY = 0
      if self.mpuData_GyZ is None:
        self.mpuData_GyZ = 0
      if self.mpuRAW_AcX is None:
        self.mpuRAW_AcX = 0
      if self.mpuRAW_AcY is None:
        self.mpuRAW_AcY = 0
      if self.mpuRAW_AcZ is None:
        self.mpuRAW_AcZ = 0
      if self.mpuRAW_timestamp is None:
        self.mpuRAW_timestamp = 0
      if self.mpuRAW_Tmp is None:
        self.mpuRAW_Tmp = 0
      if self.mpuRAW_GyX is None:
        self.mpuRAW_GyX = 0
      if self.mpuRAW_GyY is None:
        self.mpuRAW_GyY = 0
      if self.mpuRAW_GyZ is None:
        self.mpuRAW_GyZ = 0
      if self.pingheight is None:
        self.pingheight = 0
      if self.ppfb_timestamp is None:
        self.ppfb_timestamp = 0
      if self.ppfb_Input is None:
        self.ppfb_Input = 0.
      if self.ppfb_Kd is None:
        self.ppfb_Kd = 0.
      if self.ppfb_Ki is None:
        self.ppfb_Ki = 0.
      if self.ppfb_Kp is None:
        self.ppfb_Kp = 0.
      if self.ppfb_Output is None:
        self.ppfb_Output = 0.
      if self.ppfb_Setpoint is None:
        self.ppfb_Setpoint = 0.
      if self.pplr_timestamp is None:
        self.pplr_timestamp = 0
      if self.pplr_Input is None:
        self.pplr_Input = 0.
      if self.pplr_Kd is None:
        self.pplr_Kd = 0.
      if self.pplr_Ki is None:
        self.pplr_Ki = 0.
      if self.pplr_Kp is None:
        self.pplr_Kp = 0.
      if self.pplr_Output is None:
        self.pplr_Output = 0.
      if self.pplr_Setpoint is None:
        self.pplr_Setpoint = 0.
      if self.ppud_timestamp is None:
        self.ppud_timestamp = 0
      if self.ppud_Input is None:
        self.ppud_Input = 0.
      if self.ppud_Kd is None:
        self.ppud_Kd = 0.
      if self.ppud_Ki is None:
        self.ppud_Ki = 0.
      if self.ppud_Kp is None:
        self.ppud_Kp = 0.
      if self.ppud_Output is None:
        self.ppud_Output = 0.
      if self.ppud_Setpoint is None:
        self.ppud_Setpoint = 0.
      if self.yaw is None:
        self.yaw = 0.
      if self.pitch is None:
        self.pitch = 0.
      if self.roll is None:
        self.roll = 0.
      if self.timestamp is None:
        self.timestamp = 0
      if self.tune_type is None:
        self.tune_type = 0
    else:
      self.H = std_msgs.msg.Header()
      self.mpuData_AcX = 0
      self.mpuData_AcY = 0
      self.mpuData_AcZ = 0
      self.mpuData_timestamp = 0
      self.mpuData_Tmp = 0
      self.mpuData_GyX = 0
      self.mpuData_GyY = 0
      self.mpuData_GyZ = 0
      self.mpuRAW_AcX = 0
      self.mpuRAW_AcY = 0
      self.mpuRAW_AcZ = 0
      self.mpuRAW_timestamp = 0
      self.mpuRAW_Tmp = 0
      self.mpuRAW_GyX = 0
      self.mpuRAW_GyY = 0
      self.mpuRAW_GyZ = 0
      self.pingheight = 0
      self.ppfb_timestamp = 0
      self.ppfb_Input = 0.
      self.ppfb_Kd = 0.
      self.ppfb_Ki = 0.
      self.ppfb_Kp = 0.
      self.ppfb_Output = 0.
      self.ppfb_Setpoint = 0.
      self.pplr_timestamp = 0
      self.pplr_Input = 0.
      self.pplr_Kd = 0.
      self.pplr_Ki = 0.
      self.pplr_Kp = 0.
      self.pplr_Output = 0.
      self.pplr_Setpoint = 0.
      self.ppud_timestamp = 0
      self.ppud_Input = 0.
      self.ppud_Kd = 0.
      self.ppud_Ki = 0.
      self.ppud_Kp = 0.
      self.ppud_Output = 0.
      self.ppud_Setpoint = 0.
      self.yaw = 0.
      self.pitch = 0.
      self.roll = 0.
      self.timestamp = 0
      self.tune_type = 0

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
      buff.write(_get_struct_3I().pack(_x.H.seq, _x.H.stamp.secs, _x.H.stamp.nsecs))
      _x = self.H.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_3hI7hI5hI6dI6dI6d3fIh().pack(_x.mpuData_AcX, _x.mpuData_AcY, _x.mpuData_AcZ, _x.mpuData_timestamp, _x.mpuData_Tmp, _x.mpuData_GyX, _x.mpuData_GyY, _x.mpuData_GyZ, _x.mpuRAW_AcX, _x.mpuRAW_AcY, _x.mpuRAW_AcZ, _x.mpuRAW_timestamp, _x.mpuRAW_Tmp, _x.mpuRAW_GyX, _x.mpuRAW_GyY, _x.mpuRAW_GyZ, _x.pingheight, _x.ppfb_timestamp, _x.ppfb_Input, _x.ppfb_Kd, _x.ppfb_Ki, _x.ppfb_Kp, _x.ppfb_Output, _x.ppfb_Setpoint, _x.pplr_timestamp, _x.pplr_Input, _x.pplr_Kd, _x.pplr_Ki, _x.pplr_Kp, _x.pplr_Output, _x.pplr_Setpoint, _x.ppud_timestamp, _x.ppud_Input, _x.ppud_Kd, _x.ppud_Ki, _x.ppud_Kp, _x.ppud_Output, _x.ppud_Setpoint, _x.yaw, _x.pitch, _x.roll, _x.timestamp, _x.tune_type))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.H is None:
        self.H = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.H.seq, _x.H.stamp.secs, _x.H.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.H.frame_id = str[start:end].decode('utf-8')
      else:
        self.H.frame_id = str[start:end]
      _x = self
      start = end
      end += 212
      (_x.mpuData_AcX, _x.mpuData_AcY, _x.mpuData_AcZ, _x.mpuData_timestamp, _x.mpuData_Tmp, _x.mpuData_GyX, _x.mpuData_GyY, _x.mpuData_GyZ, _x.mpuRAW_AcX, _x.mpuRAW_AcY, _x.mpuRAW_AcZ, _x.mpuRAW_timestamp, _x.mpuRAW_Tmp, _x.mpuRAW_GyX, _x.mpuRAW_GyY, _x.mpuRAW_GyZ, _x.pingheight, _x.ppfb_timestamp, _x.ppfb_Input, _x.ppfb_Kd, _x.ppfb_Ki, _x.ppfb_Kp, _x.ppfb_Output, _x.ppfb_Setpoint, _x.pplr_timestamp, _x.pplr_Input, _x.pplr_Kd, _x.pplr_Ki, _x.pplr_Kp, _x.pplr_Output, _x.pplr_Setpoint, _x.ppud_timestamp, _x.ppud_Input, _x.ppud_Kd, _x.ppud_Ki, _x.ppud_Kp, _x.ppud_Output, _x.ppud_Setpoint, _x.yaw, _x.pitch, _x.roll, _x.timestamp, _x.tune_type,) = _get_struct_3hI7hI5hI6dI6dI6d3fIh().unpack(str[start:end])
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
      buff.write(_get_struct_3I().pack(_x.H.seq, _x.H.stamp.secs, _x.H.stamp.nsecs))
      _x = self.H.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_3hI7hI5hI6dI6dI6d3fIh().pack(_x.mpuData_AcX, _x.mpuData_AcY, _x.mpuData_AcZ, _x.mpuData_timestamp, _x.mpuData_Tmp, _x.mpuData_GyX, _x.mpuData_GyY, _x.mpuData_GyZ, _x.mpuRAW_AcX, _x.mpuRAW_AcY, _x.mpuRAW_AcZ, _x.mpuRAW_timestamp, _x.mpuRAW_Tmp, _x.mpuRAW_GyX, _x.mpuRAW_GyY, _x.mpuRAW_GyZ, _x.pingheight, _x.ppfb_timestamp, _x.ppfb_Input, _x.ppfb_Kd, _x.ppfb_Ki, _x.ppfb_Kp, _x.ppfb_Output, _x.ppfb_Setpoint, _x.pplr_timestamp, _x.pplr_Input, _x.pplr_Kd, _x.pplr_Ki, _x.pplr_Kp, _x.pplr_Output, _x.pplr_Setpoint, _x.ppud_timestamp, _x.ppud_Input, _x.ppud_Kd, _x.ppud_Ki, _x.ppud_Kp, _x.ppud_Output, _x.ppud_Setpoint, _x.yaw, _x.pitch, _x.roll, _x.timestamp, _x.tune_type))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.H is None:
        self.H = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.H.seq, _x.H.stamp.secs, _x.H.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.H.frame_id = str[start:end].decode('utf-8')
      else:
        self.H.frame_id = str[start:end]
      _x = self
      start = end
      end += 212
      (_x.mpuData_AcX, _x.mpuData_AcY, _x.mpuData_AcZ, _x.mpuData_timestamp, _x.mpuData_Tmp, _x.mpuData_GyX, _x.mpuData_GyY, _x.mpuData_GyZ, _x.mpuRAW_AcX, _x.mpuRAW_AcY, _x.mpuRAW_AcZ, _x.mpuRAW_timestamp, _x.mpuRAW_Tmp, _x.mpuRAW_GyX, _x.mpuRAW_GyY, _x.mpuRAW_GyZ, _x.pingheight, _x.ppfb_timestamp, _x.ppfb_Input, _x.ppfb_Kd, _x.ppfb_Ki, _x.ppfb_Kp, _x.ppfb_Output, _x.ppfb_Setpoint, _x.pplr_timestamp, _x.pplr_Input, _x.pplr_Kd, _x.pplr_Ki, _x.pplr_Kp, _x.pplr_Output, _x.pplr_Setpoint, _x.ppud_timestamp, _x.ppud_Input, _x.ppud_Kd, _x.ppud_Ki, _x.ppud_Kp, _x.ppud_Output, _x.ppud_Setpoint, _x.yaw, _x.pitch, _x.roll, _x.timestamp, _x.tune_type,) = _get_struct_3hI7hI5hI6dI6dI6d3fIh().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3hI7hI5hI6dI6dI6d3fIh = None
def _get_struct_3hI7hI5hI6dI6dI6d3fIh():
    global _struct_3hI7hI5hI6dI6dI6d3fIh
    if _struct_3hI7hI5hI6dI6dI6d3fIh is None:
        _struct_3hI7hI5hI6dI6dI6d3fIh = struct.Struct("<3hI7hI5hI6dI6dI6d3fIh")
    return _struct_3hI7hI5hI6dI6dI6d3fIh
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I