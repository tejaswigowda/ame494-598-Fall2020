var express = require("express");
var app = express();
var bodyParser = require('body-parser');
var errorHandler = require('errorhandler');
var methodOverride = require('method-override');
var hostname = process.env.HOSTNAME || 'localhost';
var port = 1234;

var accX, accY, accZ;

app.get("/", function (req, res) {
    res.redirect("index.html")
});

app.get("/sendData", function (req, res) {
  console.log(req.url)
    accX = req.query.x
    accY = req.query.y
    accZ = req.query.z
    console.log(accX, accY, accZ)
    
    res.send("1");
});


app.get("/getData", function (req, res) {
  var ret = {}

    ret.x = accX; 
    ret.y = accY; 
    ret.z = accZ; 
    
    res.send(JSON.stringify(ret));
});

app.use(methodOverride());
app.use(bodyParser());
app.use(express.static(__dirname + '/public'));
app.use(errorHandler());

console.log("Simple static server listening at http://" + hostname + ":" + port);
app.listen(port);
