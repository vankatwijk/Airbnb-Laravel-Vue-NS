Object.defineProperty(exports, "__esModule", { value: true });
require("../../core");
var polyfill_helpers_1 = require("../polyfill-helpers");
global.registerModule("ui-dialogs", function () { return require("../../../ui/dialogs"); });
polyfill_helpers_1.installPolyfills("ui-dialogs", ["alert", "confirm", "prompt", "login", "action"]);
//# sourceMappingURL=dialogs.js.map