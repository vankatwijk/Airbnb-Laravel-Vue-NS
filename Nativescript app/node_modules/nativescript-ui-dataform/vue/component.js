Object.defineProperty(exports, "__esModule", { value: true });
exports.default = {
    props: {},
    template: "\n    <NativeRadDataForm\n      ref=\"dataform\"\n      v-bind=\"$attrs\"\n      v-on=\"$listeners\">\n      <slot />\n\n    </NativeRadDataForm>\n  ",
    methods: {
        getPropertyByName: function (prop) {
            return this.$refs.dataform.nativeView.getPropertyByName(prop);
        },
        notifyValidated: function (prop, validated) {
            return this.$refs.dataform.nativeView.notifyValidated(prop, validated);
        },
        commitAll: function () {
            return this.$refs.dataform.nativeView.commitAll();
        },
        validateAll: function () {
            return this.$refs.dataform.nativeView.validateAll();
        },
    }
};
