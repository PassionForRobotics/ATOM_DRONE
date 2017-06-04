var _ = require('c-struct');


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

var REMOTE_PORT = 10000;
var REMOTE_IP = '192.168.1.2'; //'192.168.43.25';

var MY_FIXED_PORT = 20000;


server.on('listening', function () {
  var address = server.address();
  console.log('UDP Server listening on ' + address.address + ":" + address.port);
});

var msTime = process.hrtime();
var _msTime = getMillis(msTime);;
var dTime = 0;//getMillis(_msTime);;
var dlTime = 0;
var lastTimeStamp = 0;

server.on('message', function (message, remote) {

  _msTime = getMillis(msTime);//[1]/1000000
	dTime = _msTime[0] * 1000 + _msTime[1] / 1000000;


  var obj = _.unpackSync('mpudata', message);

  console.log(getDateTime() +"::Δ" + (Math.round((dTime-dlTime)*1000)/1000)+' - ');
  console.log(obj.timestamp-lastTimeStamp);

	dlTime = dTime;
  console.log(obj);
  lastTimeStamp = obj.timestamp;
  send();

});


const MESSAGE = new Buffer('02fffe00020000000f00000002ff0c010000000000000000000003', 'hex');

function send()
{
  server.send(MESSAGE, 0, MESSAGE.length, REMOTE_PORT, REMOTE_IP, function(err, bytes)
  {
    if (err) throw err;
  });
}

//setInterval(send, 20);


server.bind(MY_FIXED_PORT);

send();
