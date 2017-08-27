var _ = require('c-struct');

var REMOTE_PORT = 10000;
var REMOTE_IP = '192.168.1.5'; //'192.168.43.25';

var MY_FIXED_PORT = 20000;

var UDP_PACKET_TIMEOUT  = 250;


// typedef struct sMPURATA_t
// {
//
//   //unsigned char stx;
//   //unsigned char header;
//   //unsigned char data_len;
//   //unsigned char data_type;
//   //unsigned char res3;
//   uint32_t timestamp;
//   int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
//
//   //unsigned char etx;
// }sMPURATA_t;

var sMPURATA_t = new _.Schema({
  timestamp: _.type.uint32,
  AcX: _.type.uint16,
  AcY: _.type.uint16,
  AcZ: _.type.uint16,
  Tmp: _.type.uint16,
  GyX: _.type.uint16,
  GyY: _.type.uint16,
  GyZ: _.type.uint16
});

function typecastmpudata(_mpudata)
{
  _mpudata.AcX = _mpudata.AcX<<16>>16;
  _mpudata.AcY = _mpudata.AcY<<16>>16;
  _mpudata.AcZ = _mpudata.AcZ<<16>>16;

  _mpudata.Tmp = _mpudata.Tmp<<16>>16;

  _mpudata.GyX = _mpudata.GyX<<16>>16;
  _mpudata.GyY = _mpudata.GyY<<16>>16;
  _mpudata.GyZ = _mpudata.GyZ<<16>>16;

  return _mpudata;

 }

 var hid = require('node-hid');
 // var BitArray = require('node-bitarray');
 // console.log(hid.devices());

 var sMOTIONSETPOINTS_t = new _.Schema({
  timestamp: _.type.uint32,
  x: _.type.uint16,
  y: _.type.uint16,
  hat: _.type.uint8,
  twist: _.type.uint8,
  //buttons_a: _.type.uint8,
  slider: _.type.uint8,
  //buttons_b: _.type.uint8,
  buttons: _.type.uint16
});

_.register('motionsetpoints', sMOTIONSETPOINTS_t);

var device = new hid.HID(1133, 49685);

var joycontrols = {
 x: 0,
 y: 0,
 hat: 0,
 twist: 0,
 slider: 0,
 buttons : 0
};

var motionsetpoints = _.packSync('motionsetpoints', {
  timestamp: 0,
  x: joycontrols.x,
  y: joycontrols.y,
  hat: joycontrols.hat,
  twist: joycontrols.twist,
  //buttons_a: joycontrols.buttons_a,
  slider: joycontrols.slider,
  //buttons_b: joycontrols.buttons_b,
  buttons: joycontrols.buttons
});


device.on('data', function (buf) {

  var ch = buf.toString('hex').match(/.{1,2}/g).map(function (c) {
    return parseInt(c, 16);
  });

  joycontrols = {
   x: ((ch[1] & 0x03) << 8) + ch[0],
   y: ((ch[2] & 0x0f) << 6) + ((ch[1] & 0xfc) >> 2),
   hat: (ch[2] & 0xf0) >> 4,
   twist: ch[3],
   slider: -ch[5] + 255,
   buttons : ((ch[4] & 0xff) << 8) +(ch[6] & 0x0f)
 };

//joycontrols = controls;

 motionsetpoints = _.packSync('motionsetpoints', {
   timestamp: 0,
   x: joycontrols.x,
   y: joycontrols.y,
   hat: joycontrols.hat,
   twist: joycontrols.twist,
   //buttons_a: joycontrols.buttons_a,
   slider: joycontrols.slider,
   //buttons_b: joycontrols.buttons_b,
   buttons: joycontrols.buttons
 });
  // var bits = BitArray.fromBuffer(buf).toJSON().join('').match(/.{1,8}/g).join(' ');
  // console.log(bits, JSON.stringify(controls));
  //console.log(JSON.stringify(controls));
});

// typedef struct sMOTIONSETPOINTS_t
// {
//   uint32_t timestamp;
//   uint16_t x;
//   uint16_t y;
//   uint8_t hat;
//   uint8_t twist;
//   uint8_t buttons_a;
//   uint8_t slider;
//   uint8_t buttons_b;
//
// }sMOTIONSETPOINTS_t;


// register to cache
_.register('mpudata', sMPURATA_t);


function getMillis(oldhrstart)
{
  var hrstart = process.hrtime(oldhrstart);


  return hrstart;
}

function getDateTime() {

  var date = new Date();

  var hour = date.getHours();
  hour = (hour < 10 ? "0" : "") + hour;

  var min  = date.getMinutes();
  min = (min < 10 ? "0" : "") + min;

  var sec  = date.getSeconds();
  sec = (sec < 10 ? "0" : "") + sec;

  var year = date.getFullYear();

  var month = date.getMonth() + 1;
  month = (month < 10 ? "0" : "") + month;

  var day  = date.getDate();
  day = (day < 10 ? "0" : "") + day;

  return year + ":" + month + ":" + day + " " + hour + ":" + min + ":" + sec ;//"::" + getMills(msT)[1]/1000000;

}


var dgram = require('dgram');
var server = dgram.createSocket('udp4');


server.on('listening', function () {
  var address = server.address();
  console.log('UDP Server listening on ' + address.address + ":" + address.port);
});


var msTime = process.hrtime();
var _msTime = getMillis(msTime);
var dTime = 0;//getMillis(_msTime);;
var dlTime = 0;
var lastTimeStamp = 0;
var mpudata = _.unpackSync('mpudata', "message");
var dt = 0;
var rdt = 0;
var Tmp = 0;

server.on('message', function (message, remote) {

  _msTime = getMillis(msTime);//[1]/1000000
  dTime = _msTime[0] * 1000 + _msTime[1] / 1000000;


  mpudata = _.unpackSync('mpudata', message);
  mpudata = typecastmpudata(mpudata);
  var Temp = mpudata.Tmp;//<<16>>16; //uint to int
  Temp = (((Temp)/340.00)+36.53);
  Tmp = Temp;
  dt = mpudata.timestamp-lastTimeStamp;
  rdt = (Math.round((dTime-dlTime)*1000)/1000);
  if(1 == DOPRINT)
  {
    // console.log(getDateTime() +"::Δ" + (Math.round((dTime-dlTime)*1000)/1000)+' - '+(mpudata.timestamp-lastTimeStamp) + " | " + Math.round(Temp*100)/100+"°C"
    // + " | AcX: " + mpudata.AcX + "° | AcY: " + mpudata.AcY + "° | AcZ: ~" + mpudata.AcZ  + "°");

    //console.log(mpudata);
    send();
  }

  //DOPRINT = 0;
  dlTime = dTime;
  lastTimeStamp = mpudata.timestamp;


});


const MESSAGE = new Buffer('02fffe00020000000f00000002ff0c010000000000000000000003', 'hex');

var DOPRINT = 0;
var myWatchDog = setTimeout(function(){ udpDroppedTimedOut(); }, UDP_PACKET_TIMEOUT);; // whether UDP packet dropped

clearTimeout(myWatchDog);

function udpDroppedTimedOut()
{
  console.log(getDateTime()+" UDP PACKET DROPPED.");
  DOPRINT = 1;
  send();

}

var mspts_msTime = process.hrtime();
var _mspts_msTime = getMillis(mspts_msTime);;
//var motionsetpoints;

function send()
{
  //clearTimeout(myWatchDog);

  var _mspts_msTime = getMillis(mspts_msTime);//[1]/1000000
  mspts_dTime = _mspts_msTime[0] * 1000 + _mspts_msTime[1] / 1000000;

  motionsetpoints = _.packSync('motionsetpoints', {
    timestamp: dTime,
    x: joycontrols.x,
    y: joycontrols.y,
    hat: joycontrols.hat,
    twist: joycontrols.twist,
    //buttons_a: joycontrols.buttons_a,
    slider: joycontrols.slider,
    //buttons_b: joycontrols.buttons_b
    buttons: joycontrols.buttons
  });

  //var joydata = _.unpackSync('motionsetpoints', motionsetpoints);

  server.send(motionsetpoints, 0, motionsetpoints.length, REMOTE_PORT, REMOTE_IP, function(err, bytes)
  {
    if (err) throw err;
  });

  clearTimeout(myWatchDog);
  myWatchDog = setTimeout(function(){ udpDroppedTimedOut(); }, UDP_PACKET_TIMEOUT);
}



//setInterval(send, 20);


server.bind(MY_FIXED_PORT);

send();

function printit()
{
  if(1 == DOPRINT)
  {
    var joydata = _.unpackSync('motionsetpoints', motionsetpoints);
    console.log(getDateTime() +"::Δ" + rdt +' - '+ dt + " | "
    + Math.round(Tmp*100)/100+"°C"
    + " | AcX: " + mpudata.AcX
    + "° | AcY: " + mpudata.AcY
    + "° | AcZ: ~" + mpudata.AcZ  + "°"
    + " | x " + joydata.x
    + " | y " + joydata.y
    + " | z " + joydata.slider
    + " | yaw " + joydata.twist
    + " | hat " + joydata.hat
  );
  }
}

setInterval(printit, 100);

var objwebserver= require("./webserver.js");
//
objwebserver.start();
//
function update()
{
  var time = new Date();
  objwebserver.update(time);
  objwebserver.updateTmp(Math.round(Tmp*100)/100+"°C");
  var data = [dt ,mpudata.AcX, mpudata.AcY, mpudata.AcZ, mpudata.GyX, mpudata.GyY, mpudata.GyZ];
  objwebserver.updateAcGy(data);

}
setInterval(update, 125);


// var time = new Date();
// var jobid=10;
// objTest.jobScedule(time,jobid)
//
// console.log(time);
// console.log(jobid);
