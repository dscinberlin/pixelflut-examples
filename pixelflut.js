
var net = require('net');

var client = new net.Socket();
client.connect(1234, '35.234.105.190', function() {
	console.log('Connected');
    for(x = 0; x < 1920; x++) {
        for(y = 0; y < 1920; y++) {
            client.write('CC ' + x + ' ' + y + ' AA00AA\n');
        }
    }

});

client.on('close', function() {
	console.log('Connection closed');
});