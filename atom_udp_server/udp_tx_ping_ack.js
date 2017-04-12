//var REMOTE_FIXED_PORT = 12345;
//var REMOTE_FIXED_HOST = '10.5.1.2';

//var MY_FIXED_IP = '10.5.1.100'
var MY_FIXED_PORT = 20000

//var LOCAL_PORT = 20000;
//var HOST = '127.0.0.1';

var REMOTE_FIXED_PORT = 10000;
var REMOTE_FIXED_HOST = '192.168.4.4'; //'192.168.43.25';


var dgram = require('dgram');

//Function to convert ascii to hex
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

// '02FFFE0000020000' Serial0
// '02FFFE0000020002' Serial2
// '02FFFE0000020007' Serial7 debug serial
// '02FFFE0002000300 endianess change
const message = new Buffer('02FFFE0001000000', 'hex'); //0003480D0A
//const message = new Buffer('02FFFE00000100000003480D0A', 'hex'); //

//var message = Buffer.from([ 0x02, 0xFF, 0xFE, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 'H']);
//var message = new Buffer('\02\FF\FE\00\00\01\00\00\00\01H');

var client = dgram.createSocket('udp4');
var server = dgram.createSocket('udp4');

server.on('listening', function () {
    var address = server.address();
    console.log('UDP Server listening on ' + address.address + ":" + address.port);
});

function isEven(n) {
    return n % 2 == 0;
}

var min_value = 0;
var i = min_value;
var max_value = 0xffffffff; // error drop counter supports till 4byte data type
var counternumdig = max_value.toString(16).length;

if (!isEven(counternumdig)) {
    console.error('max_value can not fit in nibble');
    return;
}

var ack_rcvd = 0;
client.on('message', function (message, remote) {
    //console.log(remote.address + ':' + remote.port +' - ' + message);
	var str = message.toString();
	debugger;
//	if(!str.includes("OK"))
//		console.log(remote.address + ':' + remote.port +' - ' + ascii_to_hex(str) + '|'
//	+ str);
	//send();
	//process.exit();
});

var conn_est = false;
var complete_msg = '';
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
		send();
		//conn_est = true;
		//setInterval(printthroughput, timeinterval);
		//setTimeout(process.exit, 20000);
	}
	else
	{
		console.log('server :'+remote.address + ':' + remote.port +' - ' + (str.toString('hex'))
		+' - '+ ascii_to_hex(str));
	}
//send();
	//process.exit();
});

server.bind(MY_FIXED_PORT);

const arr = new Uint8Array(counternumdig);
const zerostr = new Buffer(arr).fill('0')
console.log(zerostr + ':' + counternumdig + ':' + max_value);

var packet_len = 0;
 
function send() {


    //var v = 0;
    var vstr = (zerostr + i.toString(16)).substr(-counternumdig);
	
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
	complete_msg = buffer6;
	//i++;
	//console.log(':' + buffer6.toString('hex'));
    // 00000000:8:4294967295
    // :00000000
    // 000a:00000000

    //h1 h2 h3 cr t1 t1 t2 t2 l  l  data
    //                               1  2  3  4  5 6
    //02 ff fe 00 00 01 00 00 00 06 00 00 00 6c 0d 0a
    //02 ff fe 00 00 01 00 00 00 04 00 01 0d 0a
    //02 ff fe 00 00 01 00 00 00 04 49 50 0d 0a
    

    
    client.send(buffer6, 0, buffer6.length, REMOTE_FIXED_PORT, REMOTE_FIXED_HOST, function(err, bytes) {
        if (err) throw err;
        //console.log('UDP message sent to ' + HOST + ':' + PORT + ':' + buffer6.toString('hex') + ':' + (bytes - message.length /*-2*/ ));
        packet_len = packet_len + buffer6.length
 
    });

    i++;
    if (i > max_value)
        i = min_value;
}


var timeinterval = 1000;
var last_pacekt_len = 0;
function printthroughput()
{	
	console.log(getDateTime() + ' udp bandwidth ' 
	+(Math.round(((packet_len-last_pacekt_len)/timeinterval) * 1000) / 1000).toFixed(3)
	//+ ((packet_len-last_pacekt_len)/timeinterval).toString() 
	+ ' KBps |' + packet_len);
	last_pacekt_len = packet_len;
}

//while(1);
send();
//setInterval(send, 3000);
setInterval(printthroughput, timeinterval);
//setTimeout(process.exit, 20000);
