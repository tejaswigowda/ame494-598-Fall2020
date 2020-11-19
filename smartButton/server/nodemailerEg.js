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

transporter.sendMail(mailOptions, function(error, info){
  if (error) {
	console.log(error);
  } else {
    console.log('Email sent: ' + info.response);
  }
});

