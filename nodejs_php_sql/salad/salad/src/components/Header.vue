<template>
    <div>
        <b-navbar toggleable="lg" type="dark" variant="info">
            <b-navbar-brand href="#">SALAD</b-navbar-brand>
    
            <b-navbar-toggle target="nav_collapse"/>
    
            <b-collapse is-nav id="nav_collapse">
            <b-navbar-nav>
                <b-nav-item to="/board/free">수업자료</b-nav-item>
                <b-nav-item to="/board/free/create">글쓰기</b-nav-item>
            </b-navbar-nav>
            </b-collapse>
        </b-navbar>
        </div>
</template>

<script>
    export default {
        name: "Header",
        data() {
            return {};
    }
    };
</script>
