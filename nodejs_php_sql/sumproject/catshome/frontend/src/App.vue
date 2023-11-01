<template>
  <div id="app">
    <AppHeader class="AppHeader"/>
    <MemoApp/>
  </div>
</template>

<script>
import AppHeader from './components/AppHeader.vue'
import MemoApp from './components/MemoApp.vue'
export default {
  name: 'app',
  components: {
    AppHeader,
    MemoApp
  }
}
</script>

<style>
  @import "./styles/reset.css";
  #app {
    width: 560px;
    margin: 0 auto;
  }
  .AppHeader {
    width: 400px;
    height: 200px;
  }
</style>
