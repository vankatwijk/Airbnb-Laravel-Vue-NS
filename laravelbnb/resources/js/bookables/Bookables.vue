<template>
    <div>
        <div v-if="loading">
            Data is loading.....
        </div>
        <div v-else>
            <div class="row mb-4" v-for="row in rows" :key="'row' + row">
                <div class="col d-flex align-items-stretch" 
                v-for="(bookable,column) in bookablesInRow(row)" 
                :key="'row' + row + column">
                    
                    <BookableListItem
                    :title="bookable.title" 
                    :description="bookable.description" 
                    :id="bookable.id">
                    </BookableListItem>

                </div>
                <div class="col" v-for="p in placeholdersInRow(row)" :key="'placeholder' + row + p">

                </div>
            </div>
        </div>
    </div>
</template>

<script>
import BookableListItem from "./BookableListItem"
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

        const request = axios.get("/api/bookables")
        .then(response => {
            console.log('we got a responese');
            this.bookables = response.data;
            this.loading = false;
        });

    }
}
</script>