const nodemailer = require('nodemailer');

const transporter = nodemailer.createTransport({
  service: 'gmail',
  auth: {
    user: '',
    pass: '' // naturally, replace both with your real credentials or an application-specific password
  }
});

const mailOptions = {
  from: '',
  to: '',
  subject: 'test',
  text: 'testing.'
};


var express = require("express");
var app = express();
var bodyParser = require('body-parser');
var errorHandler = require('errorhandler');
var methodOverride = require('method-override');
var hostname = process.env.HOSTNAME || 'localhost';
var port = 1234;

app.get("/", function (req, res) {
    res.redirect("index.html")
});

app.get("/sendEmail", function (req, res) {
   // Send Email
   console.log("button pressed");
   transporter.sendMail(mailOptions, function(error, info){
     if (error) {
   	console.log(error);
     } else {
       console.log('Email sent: ' + info.response);
     }
   });
});


app.use(methodOverride());
app.use(bodyParser());
app.use(express.static(__dirname + '/public'));
app.use(errorHandler());

console.log("Simple static server listening at http://" + hostname + ":" + port);
app.listen(port);
