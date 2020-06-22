Object.defineProperty(exports, "__esModule", { value: true });
require("../../core");
var polyfill_helpers_1 = require("../polyfill-helpers");
global.registerModule("timer", function () { return require("../../../timer"); });
polyfill_helpers_1.installPolyfills("timer", ["setTimeout", "clearTimeout", "setInterval", "clearInterval"]);
//# sourceMappingURL=timers.js.map