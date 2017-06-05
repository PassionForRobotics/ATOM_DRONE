
var http = require('http');
var url = require('url');
var fs = require('fs');
var server;

server = http.createServer(function(req, res){
    // your normal server code
    var path = url.parse(req.url).pathname;
    switch (path){
        case '/':
            res.writeHead(200, {'Content-Type': 'text/html'});
            res.write('<h1>Hello! Try the <a href="/test_webserver.html">Test page</a></h1>');
            res.end();
            break;
        case '/test_webserver.html':
            fs.readFile(__dirname + path, function(err, data){
                if (err){ 
                    return send404(res);
                }
                res.writeHead(200, {'Content-Type': path == 'json.js' ? 'text/javascript' : 'text/html'});
                res.write(data, 'utf8');
                res.end();
            });
        break;
        default: send404(res);
    }
}),

send404 = function(res){
    res.writeHead(404);
    res.write('404');
    res.end();
};

var date = 0;
var socketG = 0;
var start = function()
{
	server.listen(8001);

	// use socket.io
	var io = require('socket.io').listen(server);

	//turn off debug
	//io.set('log level', 1);

	// define interactions with client
	io.sockets.on('connection', function(socket){
	    //socketG = socket;
	    //send data to client
	    setInterval(function(){
		socket.emit('date', {'date': date});
		socket.emit('Tmp', {'Tmp': Tmp});
	    }, 1000);

	    //recieve client data
	    socket.on('client_data', function(data){
		process.stdout.write(data.letter);
	    });
	});
};

var update = function(_date)
{
	date = _date;
}

var updateTmp = function(_Tmp)
{
	Tmp = _Tmp;
}

exports.start = start;
exports.update = update;
exports.updateTmp = updateTmp;
