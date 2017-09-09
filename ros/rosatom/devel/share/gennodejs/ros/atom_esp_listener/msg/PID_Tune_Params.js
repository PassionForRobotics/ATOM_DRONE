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

class PID_Tune_Params {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.timestamp = null;
      this.Setpoint = null;
      this.Input = null;
      this.Output = null;
      this.Kd = null;
      this.Ki = null;
      this.Kp = null;
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
      if (initObj.hasOwnProperty('Setpoint')) {
        this.Setpoint = initObj.Setpoint
      }
      else {
        this.Setpoint = 0.0;
      }
      if (initObj.hasOwnProperty('Input')) {
        this.Input = initObj.Input
      }
      else {
        this.Input = 0.0;
      }
      if (initObj.hasOwnProperty('Output')) {
        this.Output = initObj.Output
      }
      else {
        this.Output = 0.0;
      }
      if (initObj.hasOwnProperty('Kd')) {
        this.Kd = initObj.Kd
      }
      else {
        this.Kd = 0.0;
      }
      if (initObj.hasOwnProperty('Ki')) {
        this.Ki = initObj.Ki
      }
      else {
        this.Ki = 0.0;
      }
      if (initObj.hasOwnProperty('Kp')) {
        this.Kp = initObj.Kp
      }
      else {
        this.Kp = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PID_Tune_Params
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [timestamp]
    bufferOffset = _serializer.uint32(obj.timestamp, buffer, bufferOffset);
    // Serialize message field [Setpoint]
    bufferOffset = _serializer.float64(obj.Setpoint, buffer, bufferOffset);
    // Serialize message field [Input]
    bufferOffset = _serializer.float64(obj.Input, buffer, bufferOffset);
    // Serialize message field [Output]
    bufferOffset = _serializer.float64(obj.Output, buffer, bufferOffset);
    // Serialize message field [Kd]
    bufferOffset = _serializer.float64(obj.Kd, buffer, bufferOffset);
    // Serialize message field [Ki]
    bufferOffset = _serializer.float64(obj.Ki, buffer, bufferOffset);
    // Serialize message field [Kp]
    bufferOffset = _serializer.float64(obj.Kp, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PID_Tune_Params
    let len;
    let data = new PID_Tune_Params(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [timestamp]
    data.timestamp = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [Setpoint]
    data.Setpoint = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Input]
    data.Input = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Output]
    data.Output = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Kd]
    data.Kd = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Ki]
    data.Ki = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Kp]
    data.Kp = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 52;
  }

  static datatype() {
    // Returns string type for a message object
    return 'atom_esp_listener/PID_Tune_Params';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a7b9a3a1c6b3d0aceef163325064bf57';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    uint32  timestamp
    float64 Setpoint
    float64 Input
    float64 Output
    float64 Kd
    float64 Ki
    float64 Kp
    
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
    const resolved = new PID_Tune_Params(null);
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

    if (msg.Setpoint !== undefined) {
      resolved.Setpoint = msg.Setpoint;
    }
    else {
      resolved.Setpoint = 0.0
    }

    if (msg.Input !== undefined) {
      resolved.Input = msg.Input;
    }
    else {
      resolved.Input = 0.0
    }

    if (msg.Output !== undefined) {
      resolved.Output = msg.Output;
    }
    else {
      resolved.Output = 0.0
    }

    if (msg.Kd !== undefined) {
      resolved.Kd = msg.Kd;
    }
    else {
      resolved.Kd = 0.0
    }

    if (msg.Ki !== undefined) {
      resolved.Ki = msg.Ki;
    }
    else {
      resolved.Ki = 0.0
    }

    if (msg.Kp !== undefined) {
      resolved.Kp = msg.Kp;
    }
    else {
      resolved.Kp = 0.0
    }

    return resolved;
    }
};

module.exports = PID_Tune_Params;
