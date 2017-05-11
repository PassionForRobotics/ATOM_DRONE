var dgram = require('dgram');
var server = dgram.createSocket('udp4');

var REMOTE_PORT = 10000;
var REMOTE_IP = '192.168.4.4'; //'192.168.43.25';


const MESSAGE = new Buffer('02fffe00020000000f00000002ff0c010000000000000000000003', 'hex');

function send()
{
	server.send(MESSAGE, 0, MESSAGE.length, REMOTE_PORT, REMOTE_IP, function(err, bytes) 
	{
        	if (err) throw err; 
        });
}

setInterval(send, 20);
