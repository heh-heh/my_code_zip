const Sequelize = require('sequelize');


module.exports=class user extends Sequelize.Model{
    static init(sequelize){
        return super.init({
            email:{
                type : Sequelize.STRING(40),
                allowNull : true,
                unique : true,
        },
        nick:{
            type : Sequelize.STRING(15),
            allowNull:true,
        },
        password : { 
            type : Sequelize.STRING(100),
            allowNull : true,
        },
        provider :{
            type : Sequelize.STRING(10),
            allowNull : false,
            defaultValue: 'local',
        },
        snsid : {
            type :Sequelize.STRING(30),
            allowNull : true,
        },
    },{
        sequelize,
        timestamps:true,
        underscored : false,
        modelName : 'User',
        tableName : 'users',
        paranoio : true,
        charset : 'utf8',
        collate : 'utf8_general_ci',
    });
    }
    static associate(db){
        db.User.hasMany(db.Post);
        db.User.belongsToMany(db.User,{
            foreignKey : 'followingId',
            as : "Follwers",
            throuhg : 'Follow',
        });
        db.User.belongsToMany(db.User,{
            foreignKey : 'followerId',
            as :'Followings',
            through : 'Follow',
        })
    };
};