Object.defineProperty(exports, "__esModule", { value: true });
var __1 = require("./..");
var component_1 = require("./component");
var RadAutoCompletePlugin = {
    install: function (Vue, options) {
        Vue.registerElement('RadAutoCompleteTextView', function () { return __1.RadAutoCompleteTextView; }, {
            component: component_1.default,
        });
        Vue.registerElement('SuggestionView', function () { return __1.SuggestionView; });
        Vue.directive('suggestionItemTemplate', {
            inserted: function (el, binding, vnode) {
                Vue.nextTick(function () {
                    // get the autocomplete View
                    var autocomplete = el.parentNode.parentNode.nativeView;
                    // listen for the itemLoading event, and patch the template
                    autocomplete.on('itemLoading', function (_a) {
                        var index = _a.index, data = _a.data, view = _a.view;
                        var oldVnode = view['__vueVNodeRef__'];
                        el.$templates.patchTemplate('default', { item: data }, oldVnode);
                    });
                    // set the itemViewLoader to use the default template
                    autocomplete.itemViewLoader = function (viewType) {
                        switch (viewType) {
                            case __1.AutoCompleteViewType.ItemView:
                                return el.$templates.patchTemplate('default', { item: {} });
                        }
                    };
                });
            }
        });
    }
};
exports.default = RadAutoCompletePlugin;
