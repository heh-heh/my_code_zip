
const https = require("https");
const fs = require("fs");
const express = require('express');

const app = express();
const createError = require('http-errors');
const path = require('path');
const cookieParser = require('cookie-parser');
const logger = require('morgan');

const mongoose = require('mongoose')
const morgan = require('morgan')

const options = {
  key: fs.readFileSync("./config/cert.key"),
  cert: fs.readFileSync("./config/cert.crt"),
};

const { User } = require('./Models/User');

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('port3', process.env.PORT || 4000);
app.set('port2', process.env.PORT || 5000);
app.set('view engine', 'pug');

app.use(morgan('dev'))

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use(express.urlencoded({ extended: true }));

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


app.post('/register', (req, res) => {
  const user = new User(req.body); // 상단에서 require로 가져온 User 스키마에 req.body를 담아 user라는 인스턴스로 만든다.

  user.save((err, userInfo) => {
    if (err) return res.json({ success: false, err }); // err일 경우 return 값
    return res.status(200).json({
      //status가 200일 경우 return 값
      success: true,
      userInfo,
    });
  });
});

//서버  on
app.listen(app.get('port3'), () => {
  console.log(app.get('port3'), '번 포트에서 대기중');
  console.log('http://127.0.0.1:'+app.get('port3'));
});
https.createServer(options, app).listen(app.get('port2'), () => {
  console.log(app.get('port2'), '번 포트에서 대기중');
  console.log(`https://127.0.0.1:`+app.get('port2'));
});

//DB on
mongoose
  .connect(
    'mongodb+srv://sungwon910:stst1577@cluster0.elqh2ug.mongodb.net/?retryWrites=true&w=majority',
    {
    // useNewUrlPaser: true,
      // useUnifiedTofology: true,
      // useCreateIndex: true,
      // useFindAndModify: false,
    }
  )
  .then(() => console.log('MongoDB conected'))
  .catch((err) => {
    console.log(err);
  });

module.exports = app;

