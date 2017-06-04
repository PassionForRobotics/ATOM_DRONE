var dgram = require('dgram');
var server = dgram.createSocket('udp4');

var REMOTE_PORT = 10000;
var REMOTE_IP = '192.168.4.4'; //'192.168.43.25';

var MY_FIXED_PORT = 20000;


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


server.on('listening', function () {
    var address = server.address();
    console.log('UDP Server listening on ' + address.address + ":" + address.port);
});

var conn_est = false;
var complete_msg = '';
var msTime = process.hrtime();
var _msTime = getMillis(msTime);;
var dTime = 0;//getMillis(_msTime);;
var dlTime = 0;
server.on('message', function (message, remote) {
    //console.log(remote.address + ':' + remote.port +' - ' + message);
	var str = message.toString();
	debugger;

	//if(str.includes("OK"))
	//	console.log('server :'+remote.address + ':' + remote.port +' - ' + (str.toString('hex')) +' - '+ ascii_to_hex(str) + '|'
	//+ str);
	//send();

	//console.log(complete_msg);
	//console.log(message);
	//if( false == conn_est )
	if(complete_msg.toString() == message.toString())
	{
		//send();
		//conn_est = true;
		//setInterval(printthroughput, timeinterval);
		//setTimeout(process.exit, 20000);
	}
	_msTime = getMillis(msTime);//[1]/1000000
	dTime = _msTime[0] * 1000 + _msTime[1] / 1000000;

	//ctrl + shift + U type 0394 and spacer for Δ

	console.log(getDateTime() +"::Δ" + (Math.round((dTime-dlTime)*1000)/1000)+' - '+ ascii_to_hex(message));

	dlTime = dTime;
	//}
//send();
	//process.exit();
});

server.bind(MY_FIXED_PORT);

const MESSAGE = new Buffer('02fffe00020000000f00000002ff0c010000000000000000000003', 'hex');

function send()
{
	server.send(MESSAGE, 0, MESSAGE.length, REMOTE_PORT, REMOTE_IP, function(err, bytes)
	{
        	if (err) throw err;
        });
}

//setInterval(send, 20);
