Object.defineProperty(exports, "__esModule", { value: true });
require("../../core");
var polyfill_helpers_1 = require("../polyfill-helpers");
global.registerModule("xhr", function () { return require("../../../xhr"); });
polyfill_helpers_1.installPolyfills("xhr", ["XMLHttpRequest", "FormData", "Blob", "File", "FileReader"]);
//# sourceMappingURL=xhr.js.map