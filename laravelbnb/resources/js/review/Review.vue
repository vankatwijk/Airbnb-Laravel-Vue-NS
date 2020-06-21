<template>
    <div>
        <div v-if="loading">
            Loading...
        </div>
        <div v-else>
            
            <div v-if="alreadyReviewed">
                <h3>You've already reviews this</h3>
            </div>
            <div v-else>
                <div class="form-group">
                    <label class="text-muted">select the star rating</label>
                    <star-rating
                    class="fa-4x" 
                    v-model="review.rating"
                    ></star-rating>
                </div>
                <div class="form-group">
                    <label for="content" class="text-muted">
                        Describe  your expirience with
                    </label>
                    <textarea name="content" cols="30" rows="10" class="form-control" v-model="review.content"></textarea>
                </div>
                <button class="btn btn-lg btm-primary btn-block">Submit</button>
            </div>

        </div>
    </div>
</template>


<script>
export default {
    data(){
        return{
            review:{
                rating:5,
                content:null
            },
            existingReview:null,
            loading:false
        }
    },
    created(){
        this.loading = true;
        axios.get(`/api/reviews/${this.$route.params.id}`)
        .then(response => (this.existingReview = response.data.data))
        .catch(err => {

        }).then(() => (this.loading = false));
    },
    computed: {
        alreadyReviewed(){
            return this.existingReview !== null;
        }
    }
}
</script>