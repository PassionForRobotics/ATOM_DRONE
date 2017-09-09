// Auto-generated. Do not edit!

// (in-package atom_esp_listener.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let mpudata = require('./mpudata.js');
let PID_Tune_Params = require('./PID_Tune_Params.js');
let Profiler_data = require('./Profiler_data.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class alldata {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.mpuRAW = null;
      this.pingheight = null;
      this.ppfb = null;
      this.pplr = null;
      this.ppud = null;
      this.yaw = null;
      this.pitch = null;
      this.roll = null;
      this.timestamp = null;
      this.tune_type = null;
      this.profiled_loop = null;
      this.profiled_mpu = null;
      this.profiled_wifi = null;
      this.profiled_steer = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('mpuRAW')) {
        this.mpuRAW = initObj.mpuRAW
      }
      else {
        this.mpuRAW = new mpudata();
      }
      if (initObj.hasOwnProperty('pingheight')) {
        this.pingheight = initObj.pingheight
      }
      else {
        this.pingheight = 0.0;
      }
      if (initObj.hasOwnProperty('ppfb')) {
        this.ppfb = initObj.ppfb
      }
      else {
        this.ppfb = new PID_Tune_Params();
      }
      if (initObj.hasOwnProperty('pplr')) {
        this.pplr = initObj.pplr
      }
      else {
        this.pplr = new PID_Tune_Params();
      }
      if (initObj.hasOwnProperty('ppud')) {
        this.ppud = initObj.ppud
      }
      else {
        this.ppud = new PID_Tune_Params();
      }
      if (initObj.hasOwnProperty('yaw')) {
        this.yaw = initObj.yaw
      }
      else {
        this.yaw = 0.0;
      }
      if (initObj.hasOwnProperty('pitch')) {
        this.pitch = initObj.pitch
      }
      else {
        this.pitch = 0.0;
      }
      if (initObj.hasOwnProperty('roll')) {
        this.roll = initObj.roll
      }
      else {
        this.roll = 0.0;
      }
      if (initObj.hasOwnProperty('timestamp')) {
        this.timestamp = initObj.timestamp
      }
      else {
        this.timestamp = 0;
      }
      if (initObj.hasOwnProperty('tune_type')) {
        this.tune_type = initObj.tune_type
      }
      else {
        this.tune_type = 0;
      }
      if (initObj.hasOwnProperty('profiled_loop')) {
        this.profiled_loop = initObj.profiled_loop
      }
      else {
        this.profiled_loop = new Profiler_data();
      }
      if (initObj.hasOwnProperty('profiled_mpu')) {
        this.profiled_mpu = initObj.profiled_mpu
      }
      else {
        this.profiled_mpu = new Profiler_data();
      }
      if (initObj.hasOwnProperty('profiled_wifi')) {
        this.profiled_wifi = initObj.profiled_wifi
      }
      else {
        this.profiled_wifi = new Profiler_data();
      }
      if (initObj.hasOwnProperty('profiled_steer')) {
        this.profiled_steer = initObj.profiled_steer
      }
      else {
        this.profiled_steer = new Profiler_data();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type alldata
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [mpuRAW]
    bufferOffset = mpudata.serialize(obj.mpuRAW, buffer, bufferOffset);
    // Serialize message field [pingheight]
    bufferOffset = _serializer.float32(obj.pingheight, buffer, bufferOffset);
    // Serialize message field [ppfb]
    bufferOffset = PID_Tune_Params.serialize(obj.ppfb, buffer, bufferOffset);
    // Serialize message field [pplr]
    bufferOffset = PID_Tune_Params.serialize(obj.pplr, buffer, bufferOffset);
    // Serialize message field [ppud]
    bufferOffset = PID_Tune_Params.serialize(obj.ppud, buffer, bufferOffset);
    // Serialize message field [yaw]
    bufferOffset = _serializer.float32(obj.yaw, buffer, bufferOffset);
    // Serialize message field [pitch]
    bufferOffset = _serializer.float32(obj.pitch, buffer, bufferOffset);
    // Serialize message field [roll]
    bufferOffset = _serializer.float32(obj.roll, buffer, bufferOffset);
    // Serialize message field [timestamp]
    bufferOffset = _serializer.uint32(obj.timestamp, buffer, bufferOffset);
    // Serialize message field [tune_type]
    bufferOffset = _serializer.uint16(obj.tune_type, buffer, bufferOffset);
    // Serialize message field [profiled_loop]
    bufferOffset = Profiler_data.serialize(obj.profiled_loop, buffer, bufferOffset);
    // Serialize message field [profiled_mpu]
    bufferOffset = Profiler_data.serialize(obj.profiled_mpu, buffer, bufferOffset);
    // Serialize message field [profiled_wifi]
    bufferOffset = Profiler_data.serialize(obj.profiled_wifi, buffer, bufferOffset);
    // Serialize message field [profiled_steer]
    bufferOffset = Profiler_data.serialize(obj.profiled_steer, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type alldata
    let len;
    let data = new alldata(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [mpuRAW]
    data.mpuRAW = mpudata.deserialize(buffer, bufferOffset);
    // Deserialize message field [pingheight]
    data.pingheight = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [ppfb]
    data.ppfb = PID_Tune_Params.deserialize(buffer, bufferOffset);
    // Deserialize message field [pplr]
    data.pplr = PID_Tune_Params.deserialize(buffer, bufferOffset);
    // Deserialize message field [ppud]
    data.ppud = PID_Tune_Params.deserialize(buffer, bufferOffset);
    // Deserialize message field [yaw]
    data.yaw = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [pitch]
    data.pitch = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [roll]
    data.roll = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [timestamp]
    data.timestamp = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [tune_type]
    data.tune_type = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [profiled_loop]
    data.profiled_loop = Profiler_data.deserialize(buffer, bufferOffset);
    // Deserialize message field [profiled_mpu]
    data.profiled_mpu = Profiler_data.deserialize(buffer, bufferOffset);
    // Deserialize message field [profiled_wifi]
    data.profiled_wifi = Profiler_data.deserialize(buffer, bufferOffset);
    // Deserialize message field [profiled_steer]
    data.profiled_steer = Profiler_data.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += mpudata.getMessageSize(object.mpuRAW);
    length += PID_Tune_Params.getMessageSize(object.ppfb);
    length += PID_Tune_Params.getMessageSize(object.pplr);
    length += PID_Tune_Params.getMessageSize(object.ppud);
    length += Profiler_data.getMessageSize(object.profiled_loop);
    length += Profiler_data.getMessageSize(object.profiled_mpu);
    length += Profiler_data.getMessageSize(object.profiled_wifi);
    length += Profiler_data.getMessageSize(object.profiled_steer);
    return length + 22;
  }

  static datatype() {
    // Returns string type for a message object
    return 'atom_esp_listener/alldata';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9f657d5dee01c22ca305fb4d2b9139bc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    #int16  mpuData_AcX
    #int16  mpuData_AcY
    #int16  mpuData_AcZ
    #uint32  mpuData_timestamp
    #int16  mpuData_Tmp
    #int16  mpuData_GyX
    #int16  mpuData_GyY
    #int16  mpuData_GyZ
    
    mpudata mpuRAW
    #int16  mpuRAW_AcX
    #int16  mpuRAW_AcY
    #int16  mpuRAW_AcZ
    #uint32  mpuRAW_timestamp
    #int16  mpuRAW_Tmp
    #int16  mpuRAW_GyX
    #int16  mpuRAW_GyY
    #int16  mpuRAW_GyZ
    
    float32  pingheight
    
    PID_Tune_Params ppfb
    #uint32  ppfb_timestamp
    #float64  ppfb_Input
    #float64  ppfb_Kd
    #float64  ppfb_Ki
    #float64  ppfb_Kp
    #float64  ppfb_Output
    #float64  ppfb_Setpoint
    
    PID_Tune_Params pplr
    #uint32  pplr_timestamp
    #float64  pplr_Input
    #float64  pplr_Kd
    #float64  pplr_Ki
    #float64  pplr_Kp
    #float64  pplr_Output
    #float64  pplr_Setpoint
    
    PID_Tune_Params ppud
    #uint32  ppud_timestamp
    #float64  ppud_Input
    #float64  ppud_Kd
    #float64  ppud_Ki
    #float64  ppud_Kp
    #float64  ppud_Output
    #float64  ppud_Setpoint
    
    float32  yaw
    float32  pitch
    float32  roll
    
    uint32  timestamp
    uint16  tune_type
    
    Profiler_data profiled_loop
    Profiler_data profiled_mpu
    Profiler_data profiled_wifi
    Profiler_data profiled_steer
    
    
    
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
    
    ================================================================================
    MSG: atom_esp_listener/mpudata
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
    MSG: atom_esp_listener/PID_Tune_Params
    Header header
    uint32  timestamp
    float64 Setpoint
    float64 Input
    float64 Output
    float64 Kd
    float64 Ki
    float64 Kp
    
    ================================================================================
    MSG: atom_esp_listener/Profiler_data
    Header  header
    uint32  timestamp
    uint16  averageIterationCount
    float32 averageTime # micros
    float32 averageTime2 # micros
    uint32  averageTick
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new alldata(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.mpuRAW !== undefined) {
      resolved.mpuRAW = mpudata.Resolve(msg.mpuRAW)
    }
    else {
      resolved.mpuRAW = new mpudata()
    }

    if (msg.pingheight !== undefined) {
      resolved.pingheight = msg.pingheight;
    }
    else {
      resolved.pingheight = 0.0
    }

    if (msg.ppfb !== undefined) {
      resolved.ppfb = PID_Tune_Params.Resolve(msg.ppfb)
    }
    else {
      resolved.ppfb = new PID_Tune_Params()
    }

    if (msg.pplr !== undefined) {
      resolved.pplr = PID_Tune_Params.Resolve(msg.pplr)
    }
    else {
      resolved.pplr = new PID_Tune_Params()
    }

    if (msg.ppud !== undefined) {
      resolved.ppud = PID_Tune_Params.Resolve(msg.ppud)
    }
    else {
      resolved.ppud = new PID_Tune_Params()
    }

    if (msg.yaw !== undefined) {
      resolved.yaw = msg.yaw;
    }
    else {
      resolved.yaw = 0.0
    }

    if (msg.pitch !== undefined) {
      resolved.pitch = msg.pitch;
    }
    else {
      resolved.pitch = 0.0
    }

    if (msg.roll !== undefined) {
      resolved.roll = msg.roll;
    }
    else {
      resolved.roll = 0.0
    }

    if (msg.timestamp !== undefined) {
      resolved.timestamp = msg.timestamp;
    }
    else {
      resolved.timestamp = 0
    }

    if (msg.tune_type !== undefined) {
      resolved.tune_type = msg.tune_type;
    }
    else {
      resolved.tune_type = 0
    }

    if (msg.profiled_loop !== undefined) {
      resolved.profiled_loop = Profiler_data.Resolve(msg.profiled_loop)
    }
    else {
      resolved.profiled_loop = new Profiler_data()
    }

    if (msg.profiled_mpu !== undefined) {
      resolved.profiled_mpu = Profiler_data.Resolve(msg.profiled_mpu)
    }
    else {
      resolved.profiled_mpu = new Profiler_data()
    }

    if (msg.profiled_wifi !== undefined) {
      resolved.profiled_wifi = Profiler_data.Resolve(msg.profiled_wifi)
    }
    else {
      resolved.profiled_wifi = new Profiler_data()
    }

    if (msg.profiled_steer !== undefined) {
      resolved.profiled_steer = Profiler_data.Resolve(msg.profiled_steer)
    }
    else {
      resolved.profiled_steer = new Profiler_data()
    }

    return resolved;
    }
};

module.exports = alldata;
