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
  console.log('Data: ' + data);
  port.write(data);
});

