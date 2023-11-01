import { createRouter, createWebHistory } from 'vue-router'
import Board from '../components/board.vue'
import HelloWorld from '../components/HelloWorld.vue'
import Create from '../components/Create.vue'
import ContentDetail from '../components/ContentDetail.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'HelloWorld',
      component: HelloWorld
    },
    {
      path: '/board/free',
      name: 'Board',
      component: Board
    },
    {
      path: '/board/free/detail/:contentId',
      name: 'ContentDetail',
      component: ContentDetail
    },
    {
      path: '/board/free/create/:contentId?',
      name: 'Create',
      component: Create
    }

  ]
})

export default router
