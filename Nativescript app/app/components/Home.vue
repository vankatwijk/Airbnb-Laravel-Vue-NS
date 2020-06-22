<template>
    <Page class="page" actionBarHidden="true" backgroundSpanUnderStatusBar="true">

        <DockLayout class="screen" stretchLastChild="true">
            <GridLayout class="bottom-tabs" columns="*,*,*,*" height="71"
                orientation="horizontal" dock="bottom">
                <Image row="0" col="0" height="20" src="~/assets/images/home.png" />
                <Image row="0" col="1" height="20" src="~/assets/images/explore.png" />
                <Image row="0" col="2" height="20" src="~/assets/images/saved.png" />
                <Image row="0" col="3" height="20" src="~/assets/images/contacts.png" />
            </GridLayout>
            <ScrollView dock="top">
                <StackLayout orientation="vertical">
                    <GridLayout class="header" rows="auto" columns="*,auto,auto">
                        <Label text="Explore" row="0" col="0"></Label>
                        <Image src="~/assets/images/search.png"
                            verticalAlignment="center" marginRight="25" row="0"
                            col="1" height="22" />
                        <Image src="~/assets/images/header-cart.png"
                            verticalAlignment="middle" marginRight="10" row="0"
                            col="2" height="14" />
                    </GridLayout>
                    <GridLayout class="tabs" columns="*,*,*,*,*" height="30">
                        <Label class="active" text="Standard" row="0" col="0"></Label>
                        <Label text="King" row="0" col="1"></Label>
                        <Label text="Suit" row="0" col="2"></Label>
                        <Label text="Villa" row="0" col="3"></Label>
                        <Label text="Cabana" row="0" col="4"></Label>
                    </GridLayout>
                    <StackLayout class="content">
                        <Label class="h1" text="Featured Rooms"></Label>
                        <GridLayout class="room-list-header" rows="auto"
                            columns="*,auto" height="19">
                            <Label class="h2" text="Single Standard" row="0"
                                col="0" colspan="6"></Label>
                            <Label class="see-all" text="See all" row="0" col="1"
                                colspan="2"></Label>
                        </GridLayout>
                        <ScrollView class="rooms" height="185" orientation="horizontal"
                            loaded="disableScrollBar">
                            <StackLayout orientation="horizontal">
                                <StackLayout class="first-child room" width="138"
                                    @tap="showDetails()" pageTransition="fade">
                                    <Image height="138" src="~/assets/images/room1.jpg" />
                                    <StackLayout height="9.71" class="stars"
                                        orientation="horizontal">
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />

                                    </StackLayout>
                                    <Label class="h2" height="21" text="$ 300"></Label>
                                </StackLayout>
                                <StackLayout class="room" width="138" @tap="showDetails()">
                                    <Image height="138" src="~/assets/images/room3.jpg" />
                                    <StackLayout height="9.71" class="stars"
                                        orientation="horizontal">
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-empty.png" />
                                    </StackLayout>
                                    <Label class="h2" height="21" text="$ 300"></Label>
                                </StackLayout>
                                <StackLayout class="room" width="138" @tap="showDetails()">
                                    <Image height="138" src="~/assets/images/room2.jpg" />
                                    <StackLayout height="9.71" class="stars"
                                        orientation="horizontal">
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-empty.png" />
                                        <Image width="10.28" src="~/assets/images/star-empty.png" />
                                    </StackLayout>
                                    <Label class="h2" height="21" text="$ 300"></Label>
                                </StackLayout>
                            </StackLayout>
                        </ScrollView>
                        <GridLayout class="room-list-header" rows="auto"
                            columns="*,auto" height="19">
                            <Label class="h2" text="Double Standard" row="0"
                                col="0" colspan="6"></Label>
                            <Label class="see-all" text="See all" row="0" col="1"
                                colspan="2"></Label>
                        </GridLayout>
                        <ScrollView class="rooms" height="185" orientation="horizontal">
                            <StackLayout orientation="horizontal">
                                <StackLayout class="first-child room" width="138">
                                    <Image height="138" src="~/assets/images/room2.jpg" />
                                    <StackLayout height="9.71" class="stars"
                                        orientation="horizontal">
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-empty.png" />
                                    </StackLayout>
                                    <Label class="h2" height="21" text="$ 300"></Label>
                                </StackLayout>
                                <StackLayout class="room" width="138">
                                    <Image height="138" src="~/assets/images/room1.jpg" />
                                    <StackLayout height="9.71" class="stars"
                                        orientation="horizontal">
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                    </StackLayout>
                                    <Label class="h2" height="21" text="$ 300"></Label>
                                </StackLayout>
                                <StackLayout class="room" width="138">
                                    <Image height="138" src="~/assets/images/room3.jpg" />
                                    <StackLayout height="9.71" class="stars"
                                        orientation="horizontal">
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-filled.png" />
                                        <Image width="10.28" src="~/assets/images/star-empty.png" />
                                        <Image width="10.28" src="~/assets/images/star-empty.png" />
                                    </StackLayout>
                                    <Label class="h2" height="21" text="$ 300"></Label>
                                </StackLayout>
                            </StackLayout>
                        </ScrollView>
                    </StackLayout>
                </StackLayout>
            </ScrollView>
        </DockLayout>

    </page>
</template>
<script>
    import Details from "./Details";

    export default {
        computed: {},
        mounted() {},
        data() {
            return {};
        },
        methods: {
            onButtonTap() {},
            showDetails() {
                this.$navigateTo(Details, {
                    animated: true,
                    transition: {
                        name: "fade",
                        duration: 380,
                        curve: "easeIn"
                    }
                });
            }
        }
    };
</script>

<style scoped>
    .bottom-tabs,
    .header {
        padding: 18 18;
    }

    .see-all {
        padding: 0 18;
    }

    .tabs {
        font-size: 13pt;
        font-weight: bold;
        padding: 0 9;
    }

    .tabs Label {
        border-bottom-color: #686871;
        border-bottom-width: 1;
        color: #979797;
        padding-bottom: 12;
        text-align: center;
    }

    .tabs Label.active {
        border-bottom-color: #ED2567;
        border-bottom-width: 1;
        color: #ED2567;
    }

    .content {
        padding: 32 0 0 0;
    }

    .content .h1,
    .content .h2 {
        padding-left: 18;
    }

    .room-list-header {
        margin-top: 24;
    }

    .see-all {
        color: #979797;
        font-size: 10pt;
        font-weight: 600;
        text-align: right;
    }

    .rooms {
        margin-top: 18;
    }

    .room {
        padding-right: 12;
    }

    .room.first-child {
        margin-left: 18;
    }

    .room .h2 {
        padding-left: 0;
    }

    .room Image {
        border-radius: 12;
    }

    .room Label.h2 {
        color: #CE9F70;
        margin-top: 8.29;
    }

    .stars {
        margin-top: 8;
    }

    .stars Image {
        padding-right: 1.71;
    }
</style>