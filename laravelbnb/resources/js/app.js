
require('./bootstrap');
import router from "./routes";
import VueRouter from "vue-router";
import Vuex from "vuex";
import Index from "./index"
import moment from "moment"
import StarRating from "./shared/components/StarRating";
import FatalError from "./shared/components/FatalError";
import Success from "./shared/components/Success";
import ValidationErrors from "./shared/components/ValidationErrors";
import storeDefinition from "./store";
import Axios from "axios";

window.Vue = require('vue');

// Vue.component(
//     'example-component', 
//     require('./components/ExampleComponent.vue').default);

// Vue.component(
//     'example-2', 
//     require('./components/Example2.vue').default);


Vue.use(VueRouter);
Vue.use(Vuex);

Vue.filter("fromNow", value => moment(value).fromNow());

Vue.component("star-rating", StarRating);
Vue.component("fatal-error", FatalError);
Vue.component("success", Success);
Vue.component("v-errors", ValidationErrors);

const store = new Vuex.Store(storeDefinition);


const app = new Vue({
    el: '#app',
    router,
    store,
    components:{
        "index":Index
    },
    async beforeCreate(){
        this.$store.dispatch("loadStoredState");

        await Axios.get('/sanctum/csrf-cookie');
        await axios.post("/login",{
            email: 'herzog.adrianna@example.org',
            password: 'password'
        });

        await axios.get('/user');
    }
});
