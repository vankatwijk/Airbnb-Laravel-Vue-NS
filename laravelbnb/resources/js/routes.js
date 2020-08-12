import VueRouter from "vue-router";
import Bookables from "./bookables/Bookables"
import Bookable from "./bookable/Bookable"
import Review from "./review/Review"
import Basket from "./basket/Basket"

const routes = [
    {
        path: "/",
        component:Bookables,
        name:"home",
    },
    {
        path: "/bookable/:id",
        component:Bookable,
        name:"bookable",
    },
    {
        path: "/review/:id",
        component:Review,
        name:"review",
    },
    {
        path: "/basket",
        component:Basket,
        name:"basket",
    },
    {
        path: "/auth/login",
        component:require("./auth/Login").default,
        name:"Login",
    },
];

const router = new VueRouter({
    routes,
    mode:"history",
});


export default router;