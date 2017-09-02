// Auto-generated. Do not edit!

// (in-package atom_esp_joy.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class joydata {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.X = null;
      this.Y = null;
      this.Z = null;
      this.S = null;
      this.buttons = null;
    }
    else {
      if (initObj.hasOwnProperty('X')) {
        this.X = initObj.X
      }
      else {
        this.X = 0;
      }
      if (initObj.hasOwnProperty('Y')) {
        this.Y = initObj.Y
      }
      else {
        this.Y = 0;
      }
      if (initObj.hasOwnProperty('Z')) {
        this.Z = initObj.Z
      }
      else {
        this.Z = 0;
      }
      if (initObj.hasOwnProperty('S')) {
        this.S = initObj.S
      }
      else {
        this.S = 0;
      }
      if (initObj.hasOwnProperty('buttons')) {
        this.buttons = initObj.buttons
      }
      else {
        this.buttons = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type joydata
    // Serialize message field [X]
    bufferOffset = _serializer.int16(obj.X, buffer, bufferOffset);
    // Serialize message field [Y]
    bufferOffset = _serializer.int16(obj.Y, buffer, bufferOffset);
    // Serialize message field [Z]
    bufferOffset = _serializer.int16(obj.Z, buffer, bufferOffset);
    // Serialize message field [S]
    bufferOffset = _serializer.int16(obj.S, buffer, bufferOffset);
    // Serialize message field [buttons]
    bufferOffset = _serializer.uint16(obj.buttons, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type joydata
    let len;
    let data = new joydata(null);
    // Deserialize message field [X]
    data.X = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [Y]
    data.Y = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [Z]
    data.Z = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [S]
    data.S = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [buttons]
    data.buttons = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 10;
  }

  static datatype() {
    // Returns string type for a message object
    return 'atom_esp_joy/joydata';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9ea973d7e29e9a09bf4c38bea786a98f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 X
    int16 Y
    int16 Z
    int16 S
    uint16 buttons # F1,B2,3,4,5,6,7,8,9,10,11,12,H1,2,3,4
    # 0000 0
    # 0001 1
    # 0010 2
    # 0011 3
    # 0100 4
    # 0101 5
    # 0110 6
    # 0111 7
    # 1000 8
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new joydata(null);
    if (msg.X !== undefined) {
      resolved.X = msg.X;
    }
    else {
      resolved.X = 0
    }

    if (msg.Y !== undefined) {
      resolved.Y = msg.Y;
    }
    else {
      resolved.Y = 0
    }

    if (msg.Z !== undefined) {
      resolved.Z = msg.Z;
    }
    else {
      resolved.Z = 0
    }

    if (msg.S !== undefined) {
      resolved.S = msg.S;
    }
    else {
      resolved.S = 0
    }

    if (msg.buttons !== undefined) {
      resolved.buttons = msg.buttons;
    }
    else {
      resolved.buttons = 0
    }

    return resolved;
    }
};

module.exports = joydata;
