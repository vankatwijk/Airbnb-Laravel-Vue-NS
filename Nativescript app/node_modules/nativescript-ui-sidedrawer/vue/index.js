Object.defineProperty(exports, "__esModule", { value: true });
var component_1 = require("./component");
var RadSideDrawerPlugin = {
    install: function (Vue) {
        Vue.registerElement('RadSideDrawer', function () { return require('./..').RadSideDrawer; }, {
            component: component_1.default,
        });
    }
};
exports.default = RadSideDrawerPlugin;
