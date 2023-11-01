
const https = require("https");
const fs = require("fs");


var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');

var app = express();


const options = {
  key: fs.readFileSync("./config/cert.key"),
  cert: fs.readFileSync("./config/cert.crt"),
};


// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('port', process.env.PORT || 8001);
app.set('port2', process.env.PORT || 5000);
app.set('view engine', 'pug');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/users', usersRouter);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};
  // render the error page
  res.status(err.status || 500);
  res.render('error');
});



app.listen(app.get('port'), () => {
  console.log(app.get('port'), '번 포트에서 대기중');
  console.log('http://127.0.0.1:'+app.get('port'));
});
https.createServer(options, app).listen(app.get('port2'), () => {
  console.log(app.get('port2'), '번 포트에서 대기중');
  console.log(`https://127.0.0.1:`+app.get('port2'));
});

module.exports = app;

