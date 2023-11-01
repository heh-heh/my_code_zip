const express = require("express");
const asyncify = require("express-asyncify");
const posts = require('./posts');

const api = asyncify(express.Router()); 

api.use("/posts", posts);

module.exports = api;