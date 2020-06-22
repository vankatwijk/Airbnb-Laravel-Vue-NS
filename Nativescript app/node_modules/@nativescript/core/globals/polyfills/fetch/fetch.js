Object.defineProperty(exports, "__esModule", { value: true });
require("../../core");
require("../../polyfills/xhr");
var polyfill_helpers_1 = require("../polyfill-helpers");
global.registerModule("fetch", function () { return require("../../../fetch"); });
polyfill_helpers_1.installPolyfills("fetch", ["fetch", "Headers", "Request", "Response"]);
//# sourceMappingURL=fetch.js.map