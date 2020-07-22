<template>
    <div class="row">
        <div class="col-md-8">
            <div class="card">
                <div class="card-body">
                    <div v-if="!loading">
                        <h2>{{ bookable.title }}</h2>
                        <hr/>
                        <article>{{ bookable.description }}</article>
                    </div>
                    <div v-else>
                        Loading....
                    </div>
                </div>
            </div>
            <ReviewList :bookable-id="this.$route.params.id"></ReviewList>
        </div>
        <div class="col-md-4">
            <availability :bookable-id="this.$route.params.id" @availability="checkPrice($event)"></availability>
        </div>
    </div>
</template>

<script>
import Availability from './Availability.vue'
import ReviewList from './ReviewList'
import { mapState } from 'vuex';

export default {
    components: {
        Availability,
        ReviewList
    },
    data() {
        return{
            bookable:null,
            loading:false,
            price:null
        }
    },
    created() {
        this.loading = true;
        axios.get(`/api/bookables/${this.$route.params.id}`)
        .then(response => {
            this.bookable = response.data.data;
            this.loading = false;
        });
    },
    methods: {
        async checkPrice(hasAvailability){
            if(!hasAvailability){
                this.price = null;
                return;
            }

            try{
                this.price = (await axios.get(
                    `/api/bookables/${this.$route.params.id}/availability?from=${this.lastSearch.from}&to=${this.lastSearch.to}`
                    )).data.data;
            }catch(err){
                this.price = null;
            }
        }
    },
    computed: {
        ...mapState({
            lastSearch: state => state.lastSearch // just lastSearch will work too
        })
    }

}
</script>