import ExampleComponent from "./components/ExampleComponent";
import Example2 from "./components/Example2";
import VueRouter from "vue-router";

const routes = [
    {
        path: "/",
        component:ExampleComponent,
        name:"home",
    },

    {
        path: "/second",
        component:Example2,
        name:"sencond",
    }
];

const router = new VueRouter({
    routes,
    mode:"history",
});


export default router;