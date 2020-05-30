<template>
    <div>
        <div v-if="loading">
            Data is loading.....
        </div>
        <div v-else>
            <BookableListItem
            :item-title="bookable.title" 
            :item-content="bookable.content" 
            :price="1000"
            v-for="(bookable, index) in bookables"
            :key="index">
            </BookableListItem>
        </div>
    </div>
</template>

<script>
import BookableListItem from "./bookableListItem"
export default {
    components:{
        BookableListItem
    },
    data() {
        return {
            bookables:null,
            loading:false
        }
    },
    created(){
        this.loading = true;
        setTimeout(()=>{

            this.bookables =[
                {
                    title:"cheap villa",
                    content:"A very cheap villa"
                },
                {
                    title:"cheap villa2",
                    content:"A very cheap villa"
                }
            ];

            this.loading = false;
        },2000);
    }
}
</script>