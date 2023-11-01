const Post = require("../../models/post");

module.exports = {
  // 데이터 생성
    write: async (req, res ) => {
        const {title, body, tags } = req.body;
      	
      	// new 키워드를 사용하여 Post 인스턴스를 생성
        const post = new Post({
            title,
            body,
            tags,
        })
        try {
          // save() 함수를 통해 데이터베이스에 저장시킴
            await post.save();
            return res
                .status(200)
                .json(post);
        } catch(err) {
            return res.status(500).json({error: err});
        }
    }, 
	
  // 데이터 조회
    list: async (req, res ) => {
        try {
          // find() 함수 사용, 이후 exec()를 붙여주어야 서버에 쿼리 요청
            const posts = await Post.find().exec();
            return  res
                .status(200)
                .json(posts)
        } catch(err) {
            return res.status(500).json({error: err});
        }
    }, 

  // 특정 id를 가진 포스트 조회
    read: async (req, res ) => {
        const { id } = req.params;
        try {
          // 특정 id를 가진 데이터를 조회할 때는 findById() 함수를 사용
          // find() 함수와 마찬가지로 exec()를 붙여주어야 쿼리를 요청
            const post = await Post.findById(id).exec();
            if(!post) {
                return res.status(404).end()      
            }else{
                return  res
                .status(200)
                .json(post)
            }
        } catch(err) {
            return res.status(500).json({error: err});
        }
    }, 

    remove: async (req, res ) => {}, 

    update: async (req, res ) => {}, 
}