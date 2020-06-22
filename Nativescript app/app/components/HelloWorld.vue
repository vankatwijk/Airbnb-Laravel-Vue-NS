<template>
    <Page>
        <ActionBar title="Home"/>
        <ScrollView>
            <StackLayout class="home-panel">
                <!--Add your page content here-->
                <Label textWrap="true" text="Play with NativeScript!" class="h2 description-label" />
                <Label textWrap="true" text="Write code in the editor or drag and drop components to build a NativeScript mobile application." class="h2 description-label" />
                <Label textWrap="true" text="Scan the QR code with your mobile device and watch the changes sync live while you play with the code." class="h2 description-label" />
            </StackLayout>
        </ScrollView>
    </Page>
</template>

<script>
export default {
    data () {
        return {
        };
    },
}
</script>

<style scoped>
.home-panel {
    vertical-align: center;
    font-size: 20;
    margin: 15;
}

.description-label {
    margin-bottom: 15;
}
</style>
