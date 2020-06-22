Object.defineProperty(exports, "__esModule", { value: true });
exports.default = {
    props: {},
    template: "\n    <NativeRadCalendar\n      ref=\"calendar\"\n      v-bind=\"$attrs\"\n      v-on=\"$listeners\">\n      <slot />\n\n    </NativeRadCalendar>\n  ",
    methods: {
        navigateForward: function () {
            this.$refs.calendar.nativeView.navigateForward();
        },
        navigateBack: function () {
            this.$refs.calendar.nativeView.navigateBack();
        },
        goToDate: function (date) {
            this.$refs.calendar.nativeView.goToDate(date);
        }
    }
};
