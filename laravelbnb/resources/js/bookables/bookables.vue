<template>
    <div>
        <div v-if="loading">
            Data is loading.....
        </div>
        <div v-else>
            <div class="row mb-4" v-for="row in rows" :key="'row' + row">
                <div class="col" 
                v-for="(bookable,column) in bookablesInRow(row)" 
                :key="'row' + row + column">
                    
                    <BookableListItem
                    :item-title="bookable.title" 
                    :item-content="bookable.content" 
                    :price="1000">
                    </BookableListItem>

                </div>
                <div class="col" v-for="p in placeholdersInRow(row)" :key="'placeholder' + row + p">

                </div>
            </div>
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
            loading:false,
            columns:3
        }
    },
    computed:{
        rows() {
            return this.bookables == null ? 0 : Math.ceil(this.bookables.length / this.columns);
        }
    },
    methods: {
        bookablesInRow(row){
            return this.bookables.slice((row-1) * this.columns,row * this.columns);
        },
        placeholdersInRow(row) {
            return this.columns - this.bookablesInRow(row).length;
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
                },
                {
                    title:"cheap villa2",
                    content:"A very cheap villa"
                },
                {
                    title:"cheap villa2",
                    content:"A very cheap villa"
                },
                {
                    title:"cheap villa2",
                    content:"A very cheap villa"
                },
                {
                    title:"cheap villa2",
                    content:"A very cheap villa"
                },
                {
                    title:"cheap villa2",
                    content:"A very cheap villa"
                },
                {
                    title:"cheap villa2",
                    content:"A very cheap villa"
                },
                {
                    title:"cheap villa2",
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