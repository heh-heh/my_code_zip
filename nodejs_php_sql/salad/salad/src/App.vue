<script setup>
  import Header from './components/Header.vue'
  import { RouterLink, RouterView } from 'vue-router'
  import HelloWorld from './components/HelloWorld.vue'
</script>

<template>
  <Header />
  <RouterView />
</template>

<style scoped>
  header {
    max-width: 100vw ;
    max-height: 100vh;
  }

  .background{
  height: 100vh;
  overflow: hidden;
  margin:0;
  background-image: url("./assets/saladLogo.jpg");
  background-size: cover;
  background-repeat: no-repeat;
  background-position: center;
}

  @media (min-width: 1024px) {
    header {
      display: flex;
      place-items: center;
      padding-right: calc(var(--section-gap) / 2);
    }

    .logo {
      width : auto;
      height : auto;
    }

    header .wrapper {
      display: flex;
      place-items: flex-start;
      flex-wrap: wrap;
    }

    nav {
      text-align: left;
      margin-left: -1rem;
      font-size: 1rem;

      padding: 1rem 0;
      margin-top: 1rem;
    }
  }
</style>
