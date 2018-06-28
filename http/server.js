
const http = require('http');
const port = 3000;

var server = http.createServer(function(request, response) {
    response.writeHead(200,
		       {"Content-Type": "text/plain"});
    response.end("Test");
});

server.listen(port);
