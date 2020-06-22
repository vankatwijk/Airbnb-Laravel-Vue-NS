Object.defineProperty(exports, "__esModule", { value: true });
require("../../core");
var polyfill_helpers_1 = require("../polyfill-helpers");
global.registerModule("animation", function () { return require("../../../animation-frame"); });
polyfill_helpers_1.installPolyfills("animation", ["requestAnimationFrame", "cancelAnimationFrame"]);
//# sourceMappingURL=animation.js.map