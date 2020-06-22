Object.defineProperty(exports, "__esModule", { value: true });
exports.default = {
    template: "\n    <NativeRadAutoCompleteTextView\n      ref=\"autocomplete\"\n      v-bind=\"$attrs\"\n      v-on=\"$listeners\">\n      <slot />\n    </NativeRadAutoCompleteTextView>\n  ",
    methods: {
        addToken: function (token) {
            this.$refs.autocomplete.nativeView.addToken(token);
        },
        resetAutoComplete: function () {
            this.$refs.autocomplete.nativeView.resetAutoComplete();
        },
        setLoadSuggestionsAsync: function (func) {
            this.$refs.autocomplete.nativeView.loadSuggestionsAsync = func;
        },
    },
};
