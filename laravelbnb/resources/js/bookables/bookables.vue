<template>
    <div>
        <BookableListItem 
        v-if='bookable1'
        :item-title="bookable1.title" 
        :item-content="bookable1.content" 
        :price="1000">
        </BookableListItem>

        <BookableListItem 
        v-if='bookable2'
        :item-title="bookable2.title" 
        :item-content="bookable2.content" 
        :price="5000">
        </BookableListItem>
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
            bookable1:{
                title:"cheap villa",
                content:"A very cheap villa"
            },
            bookable2:{
                title:"cheap villa2",
                content:"A very cheap villa"
            }
        }
    }
}
</script>