
const mongoose = require('mongoose'); // mongoose를 선언해주고,

const userSchema = mongoose.Schema({  // userSchema라는 이름의 schema를 작성해준다. 
    name: { 
        type: String,
        maxLength: 50,
    },
    emial: {
        type: String,
        maxLength: 50,
        trim: true, // space를 없애준다.
        unique: 1, // 같은값은 하나만 존재할 수 있다.
    },
    role: {
        type: Number,
        default: 0, // 값이 정해지지 않았다면 디폴트로 0!
    },
    token: {
        type: String,
    },
    tokenExp: {
        type: Number,
    },
});

const User = mongoose.model('User', userSchema); // userSchema를 model로 감싸준다. 

module.exports = { User }; 