<template>
    <div>
        <h6 class="text-uppercase text-secondary font-weight-bolder">price breakdown</h6>
        <div class="font-weight-bolder">
            Total ${{price.data}}
        </div>
    </div>
</template>

<script>
export default {
    props:{
        price:Object
    }
}
</script>