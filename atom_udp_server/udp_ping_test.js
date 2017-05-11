var LOCAL_PORT = 20000;
//var HOST = '127.0.0.1';

var REMOTE_PORT = 10000;
var REMOTE_IP = '192.168.4.4'; //'192.168.43.25';

const colors = {
 Reset: "\x1b[0m",
 Bright: "\x1b[1m",
 Dim: "\x1b[2m",
 Underscore: "\x1b[4m",
 Blink: "\x1b[5m",
 Reverse: "\x1b[7m",
 Hidden: "\x1b[8m",
 fg: {
  Black: "\x1b[30m",
  Red: "\x1b[31m",
  Green: "\x1b[32m",
  Yellow: "\x1b[33m",
  Blue: "\x1b[34m",
  Magenta: "\x1b[35m",
  Cyan: "\x1b[36m",
  White: "\x1b[37m",
  Crimson: "\x1b[38m" //القرمزي
 },
 bg: {
  Black: "\x1b[40m",
  Red: "\x1b[41m",
  Green: "\x1b[42m",
  Yellow: "\x1b[43m",
  Blue: "\x1b[44m",
  Magenta: "\x1b[45m",
  Cyan: "\x1b[46m",
  White: "\x1b[47m",
  Crimson: "\x1b[48m"
 }
};

var dgram = require('dgram');
var server = dgram.createSocket('udp4');

function ascii_to_hex(str)
{
    tempstr = '';
	
    for (a = 0; a < str.length; a = a + 1) 
	{
        tempstr = tempstr + ("00" + str[a].toString(16)).substr(-2) + ' ';
		//("00" + len.toString(16)).substr(-4)
    }
	
    return tempstr;
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

    return year + ":" + month + ":" + day + " " + hour + ":" + min + ":" + sec;

}

function isEven(n) {
    return n % 2 == 0;
}


const message = new Buffer('02FFFE0001000000', 'hex'); //0003480D0A

var min_value = 0;
var i = min_value;
var max_value = 0xffffffff; // error drop counter supports till 4byte data type
var counternumdig = max_value.toString(16).length;

if (!isEven(counternumdig)) {
    console.error('max_value can not fit in nibble');
    return;
}

const arr = new Uint8Array(counternumdig);
const zerostr = new Buffer(arr).fill('0')
console.log(zerostr + ':' + counternumdig + ':' + max_value);

function getVstr()
{
	return (zerostr + i.toString(16)).substr(-counternumdig);
}
 
function createpacket()
{
	var vstr = getVstr();// (zerostr + i.toString(16)).substr(-counternumdig);
	
	//vstr = "48484849";
    //console.log(':' + vstr + ':' + endian(vstr,0));
	//while(1);

    var len = vstr.length / 2; //+ 2; // for 0d0a
    var lenstr = ("0000" + len.toString(16)).substr(-4); // -4 is fixed here
    //console.log(lenstr + ':' + vstr);

    const buffer1 = new Buffer(lenstr, 'hex'); // 00 0a
	buffer1.swap16();
    const buffer1p5 = new Buffer("0000", 'hex'); // 00 00 the reserve part
    
	const buffer2 = new Buffer(vstr, 'hex'); // 00 00 00 00
	buffer2.swap32();
	//console.log(buffer2.swap32());//0).toString(16));
	//while(1);

    var buffer3 = Buffer.concat([message, buffer1]); // 02 ff fe 00 00 01 00 00+00 0a
	var buffer3p5 = Buffer.concat([buffer3, buffer1p5]); // the reserved part of it
    var buffer4 = Buffer.concat([buffer3p5, buffer2]); // +00 00 00 00
    //const buffer5 = new Buffer('0D0A', 'hex');       // 0D 0A
    var buffer6 = buffer4; //Buffer.concat([buffer4, buffer5]); // +0D 0A
    
    return buffer6;
}

server.on('listening', function () {
    var address = server.address();
    console.log('UDP Server listening on ' + address.address + ":" + address.port);
});

 
var last_rec_packet_len = 0;
var rec_packet_len = 0;

var complete_msg = 'ERR: 0x0000';
var incoming_msg = new Buffer('02fffe000100000004000000');
 //'02fffe00020000002d0000004f6c6c65314f6c6c65324f6c6c65334f6c6c65344f6c6c65354f6c6c65364f6c6c65374f6c6c65384f6c6c6539');//Olle1Olle2Olle3Olle4Olle5Olle6Olle7Olle8Olle9';
server.on('message', function (message, remote) {
var buf = Buffer.from(message, 'hex');

	if(complete_msg.toString() == message.toString())
    	{
    		send();
    	}
    	else if(buf.toString('hex').includes(incoming_msg.toString()))
    	{
    		//console.log( remote.size + ':' + remote.address + ':' + remote.port +' - ' + ascii_to_hex(message) + '  ' +buf + ' ' + incoming_msg);
    		rec_packet_len = rec_packet_len + remote.size;
    	}
    	else
    	{
    		//console.log( remote.size + ':' + remote.address + ':' + remote.port +' - ' + ascii_to_hex(message) + ' ' + message );
    		console.log('ERR | ' + remote.size + ':'  + ascii_to_hex(message));
    		i--;
    	}

});

server.bind(LOCAL_PORT);//, HOST);


var send_packet_len = 0;
//MESSAGE = [0x02, 0xff, 0xfe, 0x00, 0x02, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x0d, 0x0a] 
var MESSAGE = '' ;//new Buffer('02fffe00020000001B00000068656c6c6f68656c6c6f68656c6c6f68656c6c6f68656c6c6f0d0a', 'hex');
function send()
{
	var message = createpacket();
	MESSAGE = message;
	server.send(MESSAGE, 0, MESSAGE.length, REMOTE_PORT, REMOTE_IP, 
	function(err, bytes) 
	{
        	if (err) throw err;
        	//console.log(colors.Reset + ascii_to_hex(MESSAGE));
        	send_packet_len = send_packet_len + MESSAGE.length
		i++;
		if (i > max_value)
			i = min_value;	
        });
        
	//sock.sendto( (MESSAGE), (REMOTE_IP, REMOTE_PORT));
}
 
//setInterval(send, 3000); 

var timeinterval = 1000;
var last_send_packet_len = 0;
var totalDropCnt = 0;
function printthroughput()
{	
	if((send_packet_len-last_send_packet_len)!=0)
	{
		console.log(colors.Reset + getDateTime() + ' udp bandwidth ' 
		+(Math.round(((send_packet_len-last_send_packet_len)/timeinterval) * 1000) / 1000).toFixed(3)
		//+ ((send_packet_len-last_pacekt_len)/timeinterval).toString() 
		+ ' KBps |' + send_packet_len + ' | rec: ' 
		+ (Math.round(((rec_packet_len-last_rec_packet_len)/timeinterval) * 1000) / 1000).toFixed(3)
		+ ' KBps |' + rec_packet_len + '| dropcnt: '+ totalDropCnt);
		
	}
	else
	{
		totalDropCnt++
		console.log(colors.bg.Red + getDateTime() + ' udp bandwidth ' 
		+(Math.round(((send_packet_len-last_send_packet_len)/timeinterval) * 1000) / 1000).toFixed(3)
		//+ ((send_packet_len-last_pacekt_len)/timeinterval).toString() 
		+ ' KBps |' + send_packet_len + ' | rec: ' 
		+ (Math.round(((rec_packet_len-last_rec_packet_len)/timeinterval) * 1000) / 1000).toFixed(3)
		+ ' KBps |' + rec_packet_len  + colors.Reset);
		
		send();
	}
	last_send_packet_len = send_packet_len;
	last_rec_packet_len = rec_packet_len;
}

var SerialPort = require("serialport");
debugger;
var port = new SerialPort("/dev/ttyUSB0", {
  baudRate: 115200,
  parser: SerialPort.parsers.byteLength(4)
});

port.on('open', function() {
  /*port.write('main screen turn on', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message);
    }
    console.log('message written');
  });*/
});
 
// open errors will be emitted as an error event 
port.on('error', function(err) {
  console.log('Error: ', err.message);
});


port.on('data', function (data) {
	port.write(data, function () {
	    port.drain();
	  });
  //console.log('Data: ' + ascii_to_hex(data));
  //port.write(getVstr().toString('hex'));
  //port.write(data);
});


setInterval(printthroughput, timeinterval);
send();
