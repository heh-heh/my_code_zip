var express = require('express');
var router = express.Router();
var path = require('path');

/* GET home page. */
router.get('/', function(req, res, next) {
  res.sendfile(path.join('E:/sumproject/catshome/backend/public/index.html'));
})

module.exports = router;
