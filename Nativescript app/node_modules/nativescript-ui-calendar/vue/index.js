Object.defineProperty(exports, "__esModule", { value: true });
var __1 = require("./..");
var component_1 = require("./component");
var RadCalendarPlugin = {
    install: function (Vue, options) {
        Vue.registerElement('RadCalendar', function () { return __1.RadCalendar; }, {
            component: component_1.default,
        });
    }
};
exports.default = RadCalendarPlugin;
