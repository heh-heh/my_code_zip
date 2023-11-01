const express = require("express");
const asyncify = require("express-asyncify");
const postsCtrl = require("../api/posts/posts.ctrl");

const posts = asyncify(express.Router()); 

posts.get("/", postsCtrl.list);
posts.post("/", postsCtrl.write);
posts.get("/:id", postsCtrl.read);
posts.delete("/:id", postsCtrl.remove);
posts.patch("/:id", postsCtrl.update);


module.exports = posts;