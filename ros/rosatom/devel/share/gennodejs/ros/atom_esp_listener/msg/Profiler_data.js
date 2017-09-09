// Auto-generated. Do not edit!

// (in-package atom_esp_listener.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Profiler_data {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.timestamp = null;
      this.averageIterationCount = null;
      this.averageTime = null;
      this.averageTime2 = null;
      this.averageTick = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('timestamp')) {
        this.timestamp = initObj.timestamp
      }
      else {
        this.timestamp = 0;
      }
      if (initObj.hasOwnProperty('averageIterationCount')) {
        this.averageIterationCount = initObj.averageIterationCount
      }
      else {
        this.averageIterationCount = 0;
      }
      if (initObj.hasOwnProperty('averageTime')) {
        this.averageTime = initObj.averageTime
      }
      else {
        this.averageTime = 0.0;
      }
      if (initObj.hasOwnProperty('averageTime2')) {
        this.averageTime2 = initObj.averageTime2
      }
      else {
        this.averageTime2 = 0.0;
      }
      if (initObj.hasOwnProperty('averageTick')) {
        this.averageTick = initObj.averageTick
      }
      else {
        this.averageTick = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Profiler_data
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [timestamp]
    bufferOffset = _serializer.uint32(obj.timestamp, buffer, bufferOffset);
    // Serialize message field [averageIterationCount]
    bufferOffset = _serializer.uint16(obj.averageIterationCount, buffer, bufferOffset);
    // Serialize message field [averageTime]
    bufferOffset = _serializer.float32(obj.averageTime, buffer, bufferOffset);
    // Serialize message field [averageTime2]
    bufferOffset = _serializer.float32(obj.averageTime2, buffer, bufferOffset);
    // Serialize message field [averageTick]
    bufferOffset = _serializer.uint32(obj.averageTick, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Profiler_data
    let len;
    let data = new Profiler_data(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [timestamp]
    data.timestamp = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [averageIterationCount]
    data.averageIterationCount = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [averageTime]
    data.averageTime = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [averageTime2]
    data.averageTime2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [averageTick]
    data.averageTick = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 18;
  }

  static datatype() {
    // Returns string type for a message object
    return 'atom_esp_listener/Profiler_data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c31fa7394a8f9d53d1de6f6692e65a32';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header  header
    uint32  timestamp
    uint16  averageIterationCount
    float32 averageTime # micros
    float32 averageTime2 # micros
    uint32  averageTick
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Profiler_data(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.timestamp !== undefined) {
      resolved.timestamp = msg.timestamp;
    }
    else {
      resolved.timestamp = 0
    }

    if (msg.averageIterationCount !== undefined) {
      resolved.averageIterationCount = msg.averageIterationCount;
    }
    else {
      resolved.averageIterationCount = 0
    }

    if (msg.averageTime !== undefined) {
      resolved.averageTime = msg.averageTime;
    }
    else {
      resolved.averageTime = 0.0
    }

    if (msg.averageTime2 !== undefined) {
      resolved.averageTime2 = msg.averageTime2;
    }
    else {
      resolved.averageTime2 = 0.0
    }

    if (msg.averageTick !== undefined) {
      resolved.averageTick = msg.averageTick;
    }
    else {
      resolved.averageTick = 0
    }

    return resolved;
    }
};

module.exports = Profiler_data;
