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
            <availability 
            :bookable-id="this.$route.params.id" 
            @availability="checkPrice($event)"
            class="mb-4"
            ></availability>

            <transition name="fade">
                <PriceBreakDown v-if="price" :price="price" class="mb-4"></PriceBreakDown>
            </transition>

            <transition name="fade">
                <button class="btn btn-outline-secondary btn-block" v-if="price" @click="addToBasket" :disabled="inBasketAlready">Book now</button>
            </transition>

            <transition name="fade">
                <button class="btn btn-outline-secondary btn-block" v-if="inBasketAlready" @click="removeFromBasket">Remove from basket</button>
            </transition>
            <div v-if="inBasketAlready" class="mt-4 text-muted warning">Seems like you've already added this to the basket.</div>

        </div>
    </div>
</template>

<script>
import Availability from './Availability.vue'
import ReviewList from './ReviewList'
import PriceBreakDown from './PriceBreakDown'
import { mapState } from 'vuex';

export default {
    components: {
        Availability,
        ReviewList,
        PriceBreakDown
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
                    console.log("here");
                this.price = (await axios.get(
                    `/api/bookables/${this.$route.params.id}/price?from=${this.lastSearch.from}&to=${this.lastSearch.to}`
                    ));
                    console.log(this.price);
            }catch(err){
                this.price = null;
            }
        },
        addToBasket() {
            this.$store.dispatch("addToBasket",{
                bookable: this.bookable,
                price: this.price,
                dates:this.lastSearch
            })
        },
        removeFromBasket() {
            this.$store.dispatch("removeFromBasket", this.bookable.id)
        }

    },
    computed: {
        ...mapState({
            lastSearch: state => state.lastSearch, // just lastSearch will work too
        }),
        inBasketAlready(){
            if(this.bookable === null){
                return false;
            }

            return this.$store.getters.inBasketAlready(this.bookable.id);
        }
    }

}
</script>

<style scoped>
.warning {
font-size: 0.7rem;
}
</style>