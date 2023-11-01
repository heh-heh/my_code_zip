var path=require("path");

module.exports={
  
  devServer : {
    proxy : {
      '/api' : {
        target : 'http://127.0.0.1:3000/api',
        target : 'https://127.0.0.1:5000/api',
        changerOrigin : true,
        pathRewrite : {
          "^api" : '',
        }
      }
    }
  },
  outputDir : path.resolve("../backend/public")
}