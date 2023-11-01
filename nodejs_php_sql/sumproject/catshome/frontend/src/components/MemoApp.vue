<template>
    <div class="memo-app">
        <MemoForm @addMemo="addMemo"/>
        <ul class="memo-list">
            <Memo v-for="memo in memos"
                :key="memo.id"
                :memo="memo"
                @deleteMemo="deleteMemo"
                @updateMemo="updateMemo"/>
        </ul>
    </div>
</template>

<script>
import MemoForm from './MemoForm.vue'
import Memo from './Memo.vue'
export default{
  name: 'MemoApp',
  components: {
    MemoForm,
    Memo
  },
  data () {
    return {
      memos: []
    }
  },
  created () {
    this.memos = localStorage.memos ? JSON.parse(localStorage.memos) : []
  },
  methods: {
    addMemo (payload) {
      this.memos.push(payload)
      this.storeMemo()
    },
    storeMemo () {
      const memosToString = JSON.stringify(this.memos)
      localStorage.setItem('memos', memosToString)
    },
    deleteMemo (id) {
      const targetIndex = this.memos.findIndex(v => v.id === id)
      this.memos.splice(targetIndex, 1)
      this.storeMemo()
    },
    updateMemo (payload) {
      const {id, content} = payload
      const targetIndex = this.memos.findIndex(v => v.id === id)
      const targetMemo = this.memos[targetIndex]
      this.memos.splice(targetIndex, 1, {...targetMemo, content})
      this.storeMemo()
    }
  }
}
</script>

<style scoped>
.memo-list{
    padding: 20px 0;
    margin: 0;
}
</style>
