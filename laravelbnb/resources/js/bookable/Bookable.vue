<template>
    <div class="row"></div>
</template>

<script>
export default {
    data() {
        return{
            bookable:null
        }
    },
    created() {
        console.log(this.$route.params.id);
        axios.get(`/api/bookables/${this.$route.params.id}`)
        .then(response => (this.bookable = response.data));
    }

}
</script>