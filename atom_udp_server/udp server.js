var LOCAL_PORT = 20000;
//var HOST = '127.0.0.1';

var REMOTE_PORT = 10000;
var REMOTE_IP = '192.168.43.25';

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

server.on('listening', function () {
    var address = server.address();
    console.log('UDP Server listening on ' + address.address + ":" + address.port);
});

var complete_msg = 'ERR: 0x0000';
server.on('message', function (message, remote) {

	if(complete_msg.toString() == message.toString())
    	{
    		send();
    	}
    	else
    	{
    		console.log( remote.size + ':' + remote.address + ':' + remote.port +' - ' + ascii_to_hex(message) + '  ' +message);
    	}

});

server.bind(LOCAL_PORT);//, HOST);


var packet_len = 0;
//MESSAGE = [0x02, 0xff, 0xfe, 0x00, 0x02, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x0d, 0x0a] 
const MESSAGE = new Buffer('02fffe00020000001B00000068656c6c6f68656c6c6f68656c6c6f68656c6c6f68656c6c6f0d0a', 'hex');
function send()
{
	server.send(MESSAGE, 0, MESSAGE.length, REMOTE_PORT, REMOTE_IP, 
	function(err, bytes) 
	{
        	if (err) throw err;
        	packet_len = packet_len + MESSAGE.length
        //console.log('UDP message sent to ' + HOST + ':' + PORT + ':' + buffer6.toString('hex') + ':' + (bytes - message.length /*-2*/ )); 
        });
        
	//sock.sendto( (MESSAGE), (REMOTE_IP, REMOTE_PORT));
}
 
//setInterval(send, 3000); 

var timeinterval = 1000;
var last_pacekt_len = 0;
function printthroughput()
{	
	if((packet_len-last_pacekt_len)!=0)
	{
		console.log(colors.Reset + getDateTime() + ' udp bandwidth ' 
		+(Math.round(((packet_len-last_pacekt_len)/timeinterval) * 1000) / 1000).toFixed(3)
		//+ ((packet_len-last_pacekt_len)/timeinterval).toString() 
		+ ' KBps |' + packet_len);
	}
	else
	{
		console.log(colors.bg.Red + getDateTime() + ' udp bandwidth ' 
		+(Math.round(((packet_len-last_pacekt_len)/timeinterval) * 1000) / 1000).toFixed(3)
		//+ ((packet_len-last_pacekt_len)/timeinterval).toString() 
		+ ' KBps |' + packet_len + colors.Reset);
	}
	last_pacekt_len = packet_len;
}

setInterval(printthroughput, timeinterval);
send();
