const express = require('express');
const router =express.Router();

router.use((req,res,next)=>{
    res.locals.user = null;
    res.locals.followerCount=0;
    res.locals.followingCount=0;
    res.locals.followerIdList=[];
    next();
});

router.get('/profile',(req,res)=>{
    res.router('profile',{title : '내 정보 - node'});
});

router.get('/join', (req,res)=>{
    res.render('join', {title:'회원가입'})
})

router.get('/join', (req, res, next)=>{
    const twits= [];
    res.render('main', {
        title : 'nodefill',
        twits,
    });
});

module.exports = router;