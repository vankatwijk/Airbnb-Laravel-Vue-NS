Object.defineProperty(exports, "__esModule", { value: true });
exports.default = {
    props: {},
    template: "\n    <NativeRadSideDrawer\n      ref=\"drawer\"\n      v-bind=\"$attrs\"\n      v-on=\"$listeners\">\n      <slot />\n    </NativeRadSideDrawer>\n  ",
    methods: {
        showDrawer: function () {
            return this.$refs.drawer.nativeView.showDrawer();
        },
        closeDrawer: function () {
            return this.$refs.drawer.nativeView.closeDrawer();
        },
        toggleDrawerState: function () {
            return this.$refs.drawer.nativeView.toggleDrawerState();
        },
    }
};
