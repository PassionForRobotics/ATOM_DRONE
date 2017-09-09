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

class mpudata {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.timestamp = null;
      this.AcX = null;
      this.AcY = null;
      this.AcZ = null;
      this.Tmp = null;
      this.GyX = null;
      this.GyY = null;
      this.GyZ = null;
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
      if (initObj.hasOwnProperty('AcX')) {
        this.AcX = initObj.AcX
      }
      else {
        this.AcX = 0;
      }
      if (initObj.hasOwnProperty('AcY')) {
        this.AcY = initObj.AcY
      }
      else {
        this.AcY = 0;
      }
      if (initObj.hasOwnProperty('AcZ')) {
        this.AcZ = initObj.AcZ
      }
      else {
        this.AcZ = 0;
      }
      if (initObj.hasOwnProperty('Tmp')) {
        this.Tmp = initObj.Tmp
      }
      else {
        this.Tmp = 0;
      }
      if (initObj.hasOwnProperty('GyX')) {
        this.GyX = initObj.GyX
      }
      else {
        this.GyX = 0;
      }
      if (initObj.hasOwnProperty('GyY')) {
        this.GyY = initObj.GyY
      }
      else {
        this.GyY = 0;
      }
      if (initObj.hasOwnProperty('GyZ')) {
        this.GyZ = initObj.GyZ
      }
      else {
        this.GyZ = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type mpudata
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [timestamp]
    bufferOffset = _serializer.uint32(obj.timestamp, buffer, bufferOffset);
    // Serialize message field [AcX]
    bufferOffset = _serializer.int16(obj.AcX, buffer, bufferOffset);
    // Serialize message field [AcY]
    bufferOffset = _serializer.int16(obj.AcY, buffer, bufferOffset);
    // Serialize message field [AcZ]
    bufferOffset = _serializer.int16(obj.AcZ, buffer, bufferOffset);
    // Serialize message field [Tmp]
    bufferOffset = _serializer.int16(obj.Tmp, buffer, bufferOffset);
    // Serialize message field [GyX]
    bufferOffset = _serializer.int16(obj.GyX, buffer, bufferOffset);
    // Serialize message field [GyY]
    bufferOffset = _serializer.int16(obj.GyY, buffer, bufferOffset);
    // Serialize message field [GyZ]
    bufferOffset = _serializer.int16(obj.GyZ, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type mpudata
    let len;
    let data = new mpudata(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [timestamp]
    data.timestamp = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [AcX]
    data.AcX = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [AcY]
    data.AcY = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [AcZ]
    data.AcZ = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [Tmp]
    data.Tmp = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [GyX]
    data.GyX = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [GyY]
    data.GyY = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [GyZ]
    data.GyZ = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 18;
  }

  static datatype() {
    // Returns string type for a message object
    return 'atom_esp_listener/mpudata';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2da27b00d8c3d05a9b15d685c8870e9d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    uint32 timestamp
    int16  AcX
    int16  AcY
    int16  AcZ
    int16  Tmp
    int16  GyX
    int16  GyY
    int16  GyZ
    
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
    const resolved = new mpudata(null);
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

    if (msg.AcX !== undefined) {
      resolved.AcX = msg.AcX;
    }
    else {
      resolved.AcX = 0
    }

    if (msg.AcY !== undefined) {
      resolved.AcY = msg.AcY;
    }
    else {
      resolved.AcY = 0
    }

    if (msg.AcZ !== undefined) {
      resolved.AcZ = msg.AcZ;
    }
    else {
      resolved.AcZ = 0
    }

    if (msg.Tmp !== undefined) {
      resolved.Tmp = msg.Tmp;
    }
    else {
      resolved.Tmp = 0
    }

    if (msg.GyX !== undefined) {
      resolved.GyX = msg.GyX;
    }
    else {
      resolved.GyX = 0
    }

    if (msg.GyY !== undefined) {
      resolved.GyY = msg.GyY;
    }
    else {
      resolved.GyY = 0
    }

    if (msg.GyZ !== undefined) {
      resolved.GyZ = msg.GyZ;
    }
    else {
      resolved.GyZ = 0
    }

    return resolved;
    }
};

module.exports = mpudata;
