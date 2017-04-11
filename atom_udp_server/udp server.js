var PORT = 20000;
//var HOST = '127.0.0.1';

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

server.on('listening', function () {
    var address = server.address();
    console.log('UDP Server listening on ' + address.address + ":" + address.port);
});

server.on('message', function (message, remote) {
    console.log(remote.size + ':' + remote.address + ':' + remote.port +' - ' + ascii_to_hex(message) + '  ' +message);

});

server.bind(PORT);//, HOST);
