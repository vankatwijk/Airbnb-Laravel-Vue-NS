Object.defineProperty(exports, "__esModule", { value: true });
require("../../core");
require("../../polyfills/xhr");
var polyfill_helpers_1 = require("../polyfill-helpers");
global.registerModule("text", function () { return require("../../../text"); });
polyfill_helpers_1.installPolyfills("text", ["TextDecoder", "TextEncoder"]);
//# sourceMappingURL=text.js.map