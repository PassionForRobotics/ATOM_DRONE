// Auto-generated. Do not edit!

// (in-package atom_esp_listener.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class data {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.mpuData_AcX = null;
      this.mpuData_AcY = null;
      this.mpuData_AcZ = null;
      this.mpuData_timestamp = null;
      this.mpuData_Tmp = null;
      this.mpuData_GyX = null;
      this.mpuData_GyY = null;
      this.mpuData_GyZ = null;
      this.mpuRAW_AcX = null;
      this.mpuRAW_AcY = null;
      this.mpuRAW_AcZ = null;
      this.mpuRAW_timestamp = null;
      this.mpuRAW_Tmp = null;
      this.mpuRAW_GyX = null;
      this.mpuRAW_GyY = null;
      this.mpuRAW_GyZ = null;
      this.pingheight = null;
      this.ppfb_timestamp = null;
      this.ppfb_Input = null;
      this.ppfb_Kd = null;
      this.ppfb_Ki = null;
      this.ppfb_Kp = null;
      this.ppfb_Output = null;
      this.ppfb_Setpoint = null;
      this.pplr_timestamp = null;
      this.pplr_Input = null;
      this.pplr_Kd = null;
      this.pplr_Ki = null;
      this.pplr_Kp = null;
      this.pplr_Output = null;
      this.pplr_Setpoint = null;
      this.ppud_timestamp = null;
      this.ppud_Input = null;
      this.ppud_Kd = null;
      this.ppud_Ki = null;
      this.ppud_Kp = null;
      this.ppud_Output = null;
      this.ppud_Setpoint = null;
      this.yaw = null;
      this.pitch = null;
      this.roll = null;
      this.timestamp = null;
      this.tune_type = null;
    }
    else {
      if (initObj.hasOwnProperty('mpuData_AcX')) {
        this.mpuData_AcX = initObj.mpuData_AcX
      }
      else {
        this.mpuData_AcX = 0;
      }
      if (initObj.hasOwnProperty('mpuData_AcY')) {
        this.mpuData_AcY = initObj.mpuData_AcY
      }
      else {
        this.mpuData_AcY = 0;
      }
      if (initObj.hasOwnProperty('mpuData_AcZ')) {
        this.mpuData_AcZ = initObj.mpuData_AcZ
      }
      else {
        this.mpuData_AcZ = 0;
      }
      if (initObj.hasOwnProperty('mpuData_timestamp')) {
        this.mpuData_timestamp = initObj.mpuData_timestamp
      }
      else {
        this.mpuData_timestamp = 0;
      }
      if (initObj.hasOwnProperty('mpuData_Tmp')) {
        this.mpuData_Tmp = initObj.mpuData_Tmp
      }
      else {
        this.mpuData_Tmp = 0;
      }
      if (initObj.hasOwnProperty('mpuData_GyX')) {
        this.mpuData_GyX = initObj.mpuData_GyX
      }
      else {
        this.mpuData_GyX = 0;
      }
      if (initObj.hasOwnProperty('mpuData_GyY')) {
        this.mpuData_GyY = initObj.mpuData_GyY
      }
      else {
        this.mpuData_GyY = 0;
      }
      if (initObj.hasOwnProperty('mpuData_GyZ')) {
        this.mpuData_GyZ = initObj.mpuData_GyZ
      }
      else {
        this.mpuData_GyZ = 0;
      }
      if (initObj.hasOwnProperty('mpuRAW_AcX')) {
        this.mpuRAW_AcX = initObj.mpuRAW_AcX
      }
      else {
        this.mpuRAW_AcX = 0;
      }
      if (initObj.hasOwnProperty('mpuRAW_AcY')) {
        this.mpuRAW_AcY = initObj.mpuRAW_AcY
      }
      else {
        this.mpuRAW_AcY = 0;
      }
      if (initObj.hasOwnProperty('mpuRAW_AcZ')) {
        this.mpuRAW_AcZ = initObj.mpuRAW_AcZ
      }
      else {
        this.mpuRAW_AcZ = 0;
      }
      if (initObj.hasOwnProperty('mpuRAW_timestamp')) {
        this.mpuRAW_timestamp = initObj.mpuRAW_timestamp
      }
      else {
        this.mpuRAW_timestamp = 0;
      }
      if (initObj.hasOwnProperty('mpuRAW_Tmp')) {
        this.mpuRAW_Tmp = initObj.mpuRAW_Tmp
      }
      else {
        this.mpuRAW_Tmp = 0;
      }
      if (initObj.hasOwnProperty('mpuRAW_GyX')) {
        this.mpuRAW_GyX = initObj.mpuRAW_GyX
      }
      else {
        this.mpuRAW_GyX = 0;
      }
      if (initObj.hasOwnProperty('mpuRAW_GyY')) {
        this.mpuRAW_GyY = initObj.mpuRAW_GyY
      }
      else {
        this.mpuRAW_GyY = 0;
      }
      if (initObj.hasOwnProperty('mpuRAW_GyZ')) {
        this.mpuRAW_GyZ = initObj.mpuRAW_GyZ
      }
      else {
        this.mpuRAW_GyZ = 0;
      }
      if (initObj.hasOwnProperty('pingheight')) {
        this.pingheight = initObj.pingheight
      }
      else {
        this.pingheight = 0;
      }
      if (initObj.hasOwnProperty('ppfb_timestamp')) {
        this.ppfb_timestamp = initObj.ppfb_timestamp
      }
      else {
        this.ppfb_timestamp = 0;
      }
      if (initObj.hasOwnProperty('ppfb_Input')) {
        this.ppfb_Input = initObj.ppfb_Input
      }
      else {
        this.ppfb_Input = 0.0;
      }
      if (initObj.hasOwnProperty('ppfb_Kd')) {
        this.ppfb_Kd = initObj.ppfb_Kd
      }
      else {
        this.ppfb_Kd = 0.0;
      }
      if (initObj.hasOwnProperty('ppfb_Ki')) {
        this.ppfb_Ki = initObj.ppfb_Ki
      }
      else {
        this.ppfb_Ki = 0.0;
      }
      if (initObj.hasOwnProperty('ppfb_Kp')) {
        this.ppfb_Kp = initObj.ppfb_Kp
      }
      else {
        this.ppfb_Kp = 0.0;
      }
      if (initObj.hasOwnProperty('ppfb_Output')) {
        this.ppfb_Output = initObj.ppfb_Output
      }
      else {
        this.ppfb_Output = 0.0;
      }
      if (initObj.hasOwnProperty('ppfb_Setpoint')) {
        this.ppfb_Setpoint = initObj.ppfb_Setpoint
      }
      else {
        this.ppfb_Setpoint = 0.0;
      }
      if (initObj.hasOwnProperty('pplr_timestamp')) {
        this.pplr_timestamp = initObj.pplr_timestamp
      }
      else {
        this.pplr_timestamp = 0;
      }
      if (initObj.hasOwnProperty('pplr_Input')) {
        this.pplr_Input = initObj.pplr_Input
      }
      else {
        this.pplr_Input = 0.0;
      }
      if (initObj.hasOwnProperty('pplr_Kd')) {
        this.pplr_Kd = initObj.pplr_Kd
      }
      else {
        this.pplr_Kd = 0.0;
      }
      if (initObj.hasOwnProperty('pplr_Ki')) {
        this.pplr_Ki = initObj.pplr_Ki
      }
      else {
        this.pplr_Ki = 0.0;
      }
      if (initObj.hasOwnProperty('pplr_Kp')) {
        this.pplr_Kp = initObj.pplr_Kp
      }
      else {
        this.pplr_Kp = 0.0;
      }
      if (initObj.hasOwnProperty('pplr_Output')) {
        this.pplr_Output = initObj.pplr_Output
      }
      else {
        this.pplr_Output = 0.0;
      }
      if (initObj.hasOwnProperty('pplr_Setpoint')) {
        this.pplr_Setpoint = initObj.pplr_Setpoint
      }
      else {
        this.pplr_Setpoint = 0.0;
      }
      if (initObj.hasOwnProperty('ppud_timestamp')) {
        this.ppud_timestamp = initObj.ppud_timestamp
      }
      else {
        this.ppud_timestamp = 0;
      }
      if (initObj.hasOwnProperty('ppud_Input')) {
        this.ppud_Input = initObj.ppud_Input
      }
      else {
        this.ppud_Input = 0.0;
      }
      if (initObj.hasOwnProperty('ppud_Kd')) {
        this.ppud_Kd = initObj.ppud_Kd
      }
      else {
        this.ppud_Kd = 0.0;
      }
      if (initObj.hasOwnProperty('ppud_Ki')) {
        this.ppud_Ki = initObj.ppud_Ki
      }
      else {
        this.ppud_Ki = 0.0;
      }
      if (initObj.hasOwnProperty('ppud_Kp')) {
        this.ppud_Kp = initObj.ppud_Kp
      }
      else {
        this.ppud_Kp = 0.0;
      }
      if (initObj.hasOwnProperty('ppud_Output')) {
        this.ppud_Output = initObj.ppud_Output
      }
      else {
        this.ppud_Output = 0.0;
      }
      if (initObj.hasOwnProperty('ppud_Setpoint')) {
        this.ppud_Setpoint = initObj.ppud_Setpoint
      }
      else {
        this.ppud_Setpoint = 0.0;
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
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type data
    // Serialize message field [mpuData_AcX]
    bufferOffset = _serializer.int16(obj.mpuData_AcX, buffer, bufferOffset);
    // Serialize message field [mpuData_AcY]
    bufferOffset = _serializer.int16(obj.mpuData_AcY, buffer, bufferOffset);
    // Serialize message field [mpuData_AcZ]
    bufferOffset = _serializer.int16(obj.mpuData_AcZ, buffer, bufferOffset);
    // Serialize message field [mpuData_timestamp]
    bufferOffset = _serializer.uint32(obj.mpuData_timestamp, buffer, bufferOffset);
    // Serialize message field [mpuData_Tmp]
    bufferOffset = _serializer.int16(obj.mpuData_Tmp, buffer, bufferOffset);
    // Serialize message field [mpuData_GyX]
    bufferOffset = _serializer.int16(obj.mpuData_GyX, buffer, bufferOffset);
    // Serialize message field [mpuData_GyY]
    bufferOffset = _serializer.int16(obj.mpuData_GyY, buffer, bufferOffset);
    // Serialize message field [mpuData_GyZ]
    bufferOffset = _serializer.int16(obj.mpuData_GyZ, buffer, bufferOffset);
    // Serialize message field [mpuRAW_AcX]
    bufferOffset = _serializer.int16(obj.mpuRAW_AcX, buffer, bufferOffset);
    // Serialize message field [mpuRAW_AcY]
    bufferOffset = _serializer.int16(obj.mpuRAW_AcY, buffer, bufferOffset);
    // Serialize message field [mpuRAW_AcZ]
    bufferOffset = _serializer.int16(obj.mpuRAW_AcZ, buffer, bufferOffset);
    // Serialize message field [mpuRAW_timestamp]
    bufferOffset = _serializer.uint32(obj.mpuRAW_timestamp, buffer, bufferOffset);
    // Serialize message field [mpuRAW_Tmp]
    bufferOffset = _serializer.int16(obj.mpuRAW_Tmp, buffer, bufferOffset);
    // Serialize message field [mpuRAW_GyX]
    bufferOffset = _serializer.int16(obj.mpuRAW_GyX, buffer, bufferOffset);
    // Serialize message field [mpuRAW_GyY]
    bufferOffset = _serializer.int16(obj.mpuRAW_GyY, buffer, bufferOffset);
    // Serialize message field [mpuRAW_GyZ]
    bufferOffset = _serializer.int16(obj.mpuRAW_GyZ, buffer, bufferOffset);
    // Serialize message field [pingheight]
    bufferOffset = _serializer.int16(obj.pingheight, buffer, bufferOffset);
    // Serialize message field [ppfb_timestamp]
    bufferOffset = _serializer.uint32(obj.ppfb_timestamp, buffer, bufferOffset);
    // Serialize message field [ppfb_Input]
    bufferOffset = _serializer.float64(obj.ppfb_Input, buffer, bufferOffset);
    // Serialize message field [ppfb_Kd]
    bufferOffset = _serializer.float64(obj.ppfb_Kd, buffer, bufferOffset);
    // Serialize message field [ppfb_Ki]
    bufferOffset = _serializer.float64(obj.ppfb_Ki, buffer, bufferOffset);
    // Serialize message field [ppfb_Kp]
    bufferOffset = _serializer.float64(obj.ppfb_Kp, buffer, bufferOffset);
    // Serialize message field [ppfb_Output]
    bufferOffset = _serializer.float64(obj.ppfb_Output, buffer, bufferOffset);
    // Serialize message field [ppfb_Setpoint]
    bufferOffset = _serializer.float64(obj.ppfb_Setpoint, buffer, bufferOffset);
    // Serialize message field [pplr_timestamp]
    bufferOffset = _serializer.uint32(obj.pplr_timestamp, buffer, bufferOffset);
    // Serialize message field [pplr_Input]
    bufferOffset = _serializer.float64(obj.pplr_Input, buffer, bufferOffset);
    // Serialize message field [pplr_Kd]
    bufferOffset = _serializer.float64(obj.pplr_Kd, buffer, bufferOffset);
    // Serialize message field [pplr_Ki]
    bufferOffset = _serializer.float64(obj.pplr_Ki, buffer, bufferOffset);
    // Serialize message field [pplr_Kp]
    bufferOffset = _serializer.float64(obj.pplr_Kp, buffer, bufferOffset);
    // Serialize message field [pplr_Output]
    bufferOffset = _serializer.float64(obj.pplr_Output, buffer, bufferOffset);
    // Serialize message field [pplr_Setpoint]
    bufferOffset = _serializer.float64(obj.pplr_Setpoint, buffer, bufferOffset);
    // Serialize message field [ppud_timestamp]
    bufferOffset = _serializer.uint32(obj.ppud_timestamp, buffer, bufferOffset);
    // Serialize message field [ppud_Input]
    bufferOffset = _serializer.float64(obj.ppud_Input, buffer, bufferOffset);
    // Serialize message field [ppud_Kd]
    bufferOffset = _serializer.float64(obj.ppud_Kd, buffer, bufferOffset);
    // Serialize message field [ppud_Ki]
    bufferOffset = _serializer.float64(obj.ppud_Ki, buffer, bufferOffset);
    // Serialize message field [ppud_Kp]
    bufferOffset = _serializer.float64(obj.ppud_Kp, buffer, bufferOffset);
    // Serialize message field [ppud_Output]
    bufferOffset = _serializer.float64(obj.ppud_Output, buffer, bufferOffset);
    // Serialize message field [ppud_Setpoint]
    bufferOffset = _serializer.float64(obj.ppud_Setpoint, buffer, bufferOffset);
    // Serialize message field [yaw]
    bufferOffset = _serializer.float32(obj.yaw, buffer, bufferOffset);
    // Serialize message field [pitch]
    bufferOffset = _serializer.float32(obj.pitch, buffer, bufferOffset);
    // Serialize message field [roll]
    bufferOffset = _serializer.float32(obj.roll, buffer, bufferOffset);
    // Serialize message field [timestamp]
    bufferOffset = _serializer.uint32(obj.timestamp, buffer, bufferOffset);
    // Serialize message field [tune_type]
    bufferOffset = _serializer.int16(obj.tune_type, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type data
    let len;
    let data = new data(null);
    // Deserialize message field [mpuData_AcX]
    data.mpuData_AcX = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mpuData_AcY]
    data.mpuData_AcY = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mpuData_AcZ]
    data.mpuData_AcZ = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mpuData_timestamp]
    data.mpuData_timestamp = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [mpuData_Tmp]
    data.mpuData_Tmp = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mpuData_GyX]
    data.mpuData_GyX = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mpuData_GyY]
    data.mpuData_GyY = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mpuData_GyZ]
    data.mpuData_GyZ = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mpuRAW_AcX]
    data.mpuRAW_AcX = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mpuRAW_AcY]
    data.mpuRAW_AcY = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mpuRAW_AcZ]
    data.mpuRAW_AcZ = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mpuRAW_timestamp]
    data.mpuRAW_timestamp = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [mpuRAW_Tmp]
    data.mpuRAW_Tmp = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mpuRAW_GyX]
    data.mpuRAW_GyX = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mpuRAW_GyY]
    data.mpuRAW_GyY = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mpuRAW_GyZ]
    data.mpuRAW_GyZ = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [pingheight]
    data.pingheight = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [ppfb_timestamp]
    data.ppfb_timestamp = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [ppfb_Input]
    data.ppfb_Input = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ppfb_Kd]
    data.ppfb_Kd = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ppfb_Ki]
    data.ppfb_Ki = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ppfb_Kp]
    data.ppfb_Kp = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ppfb_Output]
    data.ppfb_Output = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ppfb_Setpoint]
    data.ppfb_Setpoint = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [pplr_timestamp]
    data.pplr_timestamp = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [pplr_Input]
    data.pplr_Input = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [pplr_Kd]
    data.pplr_Kd = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [pplr_Ki]
    data.pplr_Ki = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [pplr_Kp]
    data.pplr_Kp = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [pplr_Output]
    data.pplr_Output = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [pplr_Setpoint]
    data.pplr_Setpoint = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ppud_timestamp]
    data.ppud_timestamp = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [ppud_Input]
    data.ppud_Input = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ppud_Kd]
    data.ppud_Kd = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ppud_Ki]
    data.ppud_Ki = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ppud_Kp]
    data.ppud_Kp = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ppud_Output]
    data.ppud_Output = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ppud_Setpoint]
    data.ppud_Setpoint = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [yaw]
    data.yaw = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [pitch]
    data.pitch = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [roll]
    data.roll = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [timestamp]
    data.timestamp = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [tune_type]
    data.tune_type = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 212;
  }

  static datatype() {
    // Returns string type for a message object
    return 'atom_esp_listener/data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '468ea019e00a2e85450ca1ffc75e76ac';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new data(null);
    if (msg.mpuData_AcX !== undefined) {
      resolved.mpuData_AcX = msg.mpuData_AcX;
    }
    else {
      resolved.mpuData_AcX = 0
    }

    if (msg.mpuData_AcY !== undefined) {
      resolved.mpuData_AcY = msg.mpuData_AcY;
    }
    else {
      resolved.mpuData_AcY = 0
    }

    if (msg.mpuData_AcZ !== undefined) {
      resolved.mpuData_AcZ = msg.mpuData_AcZ;
    }
    else {
      resolved.mpuData_AcZ = 0
    }

    if (msg.mpuData_timestamp !== undefined) {
      resolved.mpuData_timestamp = msg.mpuData_timestamp;
    }
    else {
      resolved.mpuData_timestamp = 0
    }

    if (msg.mpuData_Tmp !== undefined) {
      resolved.mpuData_Tmp = msg.mpuData_Tmp;
    }
    else {
      resolved.mpuData_Tmp = 0
    }

    if (msg.mpuData_GyX !== undefined) {
      resolved.mpuData_GyX = msg.mpuData_GyX;
    }
    else {
      resolved.mpuData_GyX = 0
    }

    if (msg.mpuData_GyY !== undefined) {
      resolved.mpuData_GyY = msg.mpuData_GyY;
    }
    else {
      resolved.mpuData_GyY = 0
    }

    if (msg.mpuData_GyZ !== undefined) {
      resolved.mpuData_GyZ = msg.mpuData_GyZ;
    }
    else {
      resolved.mpuData_GyZ = 0
    }

    if (msg.mpuRAW_AcX !== undefined) {
      resolved.mpuRAW_AcX = msg.mpuRAW_AcX;
    }
    else {
      resolved.mpuRAW_AcX = 0
    }

    if (msg.mpuRAW_AcY !== undefined) {
      resolved.mpuRAW_AcY = msg.mpuRAW_AcY;
    }
    else {
      resolved.mpuRAW_AcY = 0
    }

    if (msg.mpuRAW_AcZ !== undefined) {
      resolved.mpuRAW_AcZ = msg.mpuRAW_AcZ;
    }
    else {
      resolved.mpuRAW_AcZ = 0
    }

    if (msg.mpuRAW_timestamp !== undefined) {
      resolved.mpuRAW_timestamp = msg.mpuRAW_timestamp;
    }
    else {
      resolved.mpuRAW_timestamp = 0
    }

    if (msg.mpuRAW_Tmp !== undefined) {
      resolved.mpuRAW_Tmp = msg.mpuRAW_Tmp;
    }
    else {
      resolved.mpuRAW_Tmp = 0
    }

    if (msg.mpuRAW_GyX !== undefined) {
      resolved.mpuRAW_GyX = msg.mpuRAW_GyX;
    }
    else {
      resolved.mpuRAW_GyX = 0
    }

    if (msg.mpuRAW_GyY !== undefined) {
      resolved.mpuRAW_GyY = msg.mpuRAW_GyY;
    }
    else {
      resolved.mpuRAW_GyY = 0
    }

    if (msg.mpuRAW_GyZ !== undefined) {
      resolved.mpuRAW_GyZ = msg.mpuRAW_GyZ;
    }
    else {
      resolved.mpuRAW_GyZ = 0
    }

    if (msg.pingheight !== undefined) {
      resolved.pingheight = msg.pingheight;
    }
    else {
      resolved.pingheight = 0
    }

    if (msg.ppfb_timestamp !== undefined) {
      resolved.ppfb_timestamp = msg.ppfb_timestamp;
    }
    else {
      resolved.ppfb_timestamp = 0
    }

    if (msg.ppfb_Input !== undefined) {
      resolved.ppfb_Input = msg.ppfb_Input;
    }
    else {
      resolved.ppfb_Input = 0.0
    }

    if (msg.ppfb_Kd !== undefined) {
      resolved.ppfb_Kd = msg.ppfb_Kd;
    }
    else {
      resolved.ppfb_Kd = 0.0
    }

    if (msg.ppfb_Ki !== undefined) {
      resolved.ppfb_Ki = msg.ppfb_Ki;
    }
    else {
      resolved.ppfb_Ki = 0.0
    }

    if (msg.ppfb_Kp !== undefined) {
      resolved.ppfb_Kp = msg.ppfb_Kp;
    }
    else {
      resolved.ppfb_Kp = 0.0
    }

    if (msg.ppfb_Output !== undefined) {
      resolved.ppfb_Output = msg.ppfb_Output;
    }
    else {
      resolved.ppfb_Output = 0.0
    }

    if (msg.ppfb_Setpoint !== undefined) {
      resolved.ppfb_Setpoint = msg.ppfb_Setpoint;
    }
    else {
      resolved.ppfb_Setpoint = 0.0
    }

    if (msg.pplr_timestamp !== undefined) {
      resolved.pplr_timestamp = msg.pplr_timestamp;
    }
    else {
      resolved.pplr_timestamp = 0
    }

    if (msg.pplr_Input !== undefined) {
      resolved.pplr_Input = msg.pplr_Input;
    }
    else {
      resolved.pplr_Input = 0.0
    }

    if (msg.pplr_Kd !== undefined) {
      resolved.pplr_Kd = msg.pplr_Kd;
    }
    else {
      resolved.pplr_Kd = 0.0
    }

    if (msg.pplr_Ki !== undefined) {
      resolved.pplr_Ki = msg.pplr_Ki;
    }
    else {
      resolved.pplr_Ki = 0.0
    }

    if (msg.pplr_Kp !== undefined) {
      resolved.pplr_Kp = msg.pplr_Kp;
    }
    else {
      resolved.pplr_Kp = 0.0
    }

    if (msg.pplr_Output !== undefined) {
      resolved.pplr_Output = msg.pplr_Output;
    }
    else {
      resolved.pplr_Output = 0.0
    }

    if (msg.pplr_Setpoint !== undefined) {
      resolved.pplr_Setpoint = msg.pplr_Setpoint;
    }
    else {
      resolved.pplr_Setpoint = 0.0
    }

    if (msg.ppud_timestamp !== undefined) {
      resolved.ppud_timestamp = msg.ppud_timestamp;
    }
    else {
      resolved.ppud_timestamp = 0
    }

    if (msg.ppud_Input !== undefined) {
      resolved.ppud_Input = msg.ppud_Input;
    }
    else {
      resolved.ppud_Input = 0.0
    }

    if (msg.ppud_Kd !== undefined) {
      resolved.ppud_Kd = msg.ppud_Kd;
    }
    else {
      resolved.ppud_Kd = 0.0
    }

    if (msg.ppud_Ki !== undefined) {
      resolved.ppud_Ki = msg.ppud_Ki;
    }
    else {
      resolved.ppud_Ki = 0.0
    }

    if (msg.ppud_Kp !== undefined) {
      resolved.ppud_Kp = msg.ppud_Kp;
    }
    else {
      resolved.ppud_Kp = 0.0
    }

    if (msg.ppud_Output !== undefined) {
      resolved.ppud_Output = msg.ppud_Output;
    }
    else {
      resolved.ppud_Output = 0.0
    }

    if (msg.ppud_Setpoint !== undefined) {
      resolved.ppud_Setpoint = msg.ppud_Setpoint;
    }
    else {
      resolved.ppud_Setpoint = 0.0
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

    return resolved;
    }
};

module.exports = data;
