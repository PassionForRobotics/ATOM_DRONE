var hid = require('node-hid');
// var BitArray = require('node-bitarray');
// console.log(hid.devices());

var _ = require('c-struct');


var sMOTIONSETPOINTS_t = new _.Schema({
  //timestamp: _.type.uint32,
  x: _.type.uint8,
  y: _.type.uint8,
  hat: _.type.uint8,
  twist: _.type.uint8,
  buttons_a: _.type.uint8,
  slider: _.type.uint8,
  buttons_b: _.type.uint8
});

//let {struct, union, sizeOf} = 
//var struct = require("/home/rahuldeo/ATOM/ATOM_drone_robot_platform/atom_udp_server/node_modules/thing-unionstruct");

/*
typedef_sMOTIONSETPOINTS_t = [ 
  ["state", "struct", 
   [
    ["x", "u32", 10],
    ["y", "u32", 10],
    ["hat", "u32", 4],
    ["twist", "u32", 8],
    ["buttons_a", "u8"],
    ["slider", "u8"],
    ["buttons_b", "u8"]
   ]
  ]
];

typedef_sMOTIONSETPOINTS_t = struct([ 
    ["x", "u32", 10],
    ["y", "u32", 10],
    ["hat", "u32", 4],
    ["twist", "u32", 8],
    ["buttons_a", "u8"],
    ["slider", "u8"],
    ["buttons_b", "u8"]
]);
   */ 
 /*   union { //axes and hut switch
    uint32_t axes;
    struct {
      uint32_t x : 10;
      uint32_t y : 10;
      uint32_t hat : 4;
      uint32_t twist : 8;
    };
  };
  uint8_t buttons_a;
  uint8_t slider;
  uint8_t buttons_b;
    ["flags", "u32"],
    ["state", "struct", [
        ["type", "u32", 9],
        ["cache", "u32", 3],
        ["enabled", "u32", 1],
        ["visible", "u32", 1],
        ["selected", "u32", 1],
        ["locked", "u32", 1],
        ["scheduled", "i32", 18],
        ["tag", "u16"]]]
];*/

/*
typedef struct GamePadEventData
{
  union { //axes and hut switch
    uint32_t axes;
    struct {
      uint32_t x : 10;
      uint32_t y : 10;
      uint32_t hat : 4;
      uint32_t twist : 8;
    };
  };
  uint8_t buttons_a;
  uint8_t slider;
  uint8_t buttons_b;
}GamePadEventData;
*/
_.register('motionsetpoints', sMOTIONSETPOINTS_t);


// Logitech Extreme 3D Pro's vendorID and productID: 1133:49685 (i.e. 046d:c215)
var device = new hid.HID(1133, 49685);
// console.log(device);

var joybuf = 0;
var joycontrols=0;
device.on('data', function (buf) {

  var ch = buf.toString('hex').match(/.{1,2}/g).map(function (c) {
    return parseInt(c, 16);
  });
  
  joybuf = buf;

  var controls = {
    roll: ((ch[1] & 0x03) << 8) + ch[0],
    pitch: ((ch[2] & 0x0f) << 6) + ((ch[1] & 0xfc) >> 2),
    yaw: ch[3],
    view: (ch[2] & 0xf0) >> 4,
    throttle: -ch[5] + 255,
    buttons: [
      (ch[4] & 0x01) >> 0,
      (ch[4] & 0x02) >> 1,
      (ch[4] & 0x04) >> 2,
      (ch[4] & 0x08) >> 3,
      (ch[4] & 0x10) >> 4,
      (ch[4] & 0x20) >> 5,
      (ch[4] & 0x40) >> 6,
      (ch[4] & 0x80) >> 7,
      (ch[6] & 0x01) >> 0,
      (ch[6] & 0x02) >> 1,
      (ch[6] & 0x04) >> 2,
      (ch[6] & 0x08) >> 3
    ]
  };

  joycontrols = controls;
  // var bits = BitArray.fromBuffer(buf).toJSON().join('').match(/.{1,8}/g).join(' ');
  // console.log(bits, JSON.stringify(controls));
  //console.log(JSON.stringify(controls));
});

function print()
{
	var joydata = _.unpackSync('motionsetpoints', joybuf);
	//var joydata = union(typedef_sMOTIONSETPOINTS_t, joybuf.buffer);
	console.log(joydata);
	console.log(joybuf);
	console.log(JSON.stringify(joycontrols));
}

setInterval(print, 250);

