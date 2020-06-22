"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var application = require("application");
function getAppDelegate() {
    if (application.ios.delegate === undefined) {
        var UIApplicationDelegateImpl = (function (_super) {
            __extends(UIApplicationDelegateImpl, _super);
            function UIApplicationDelegateImpl() {
                return _super !== null && _super.apply(this, arguments) || this;
            }
            UIApplicationDelegateImpl.new = function () {
                return _super.new.call(this);
            };
            UIApplicationDelegateImpl.ObjCProtocols = [UIApplicationDelegate];
            return UIApplicationDelegateImpl;
        }(UIResponder));
        application.ios.delegate = UIApplicationDelegateImpl;
    }
    return application.ios.delegate;
}
exports.getAppDelegate = getAppDelegate;
//# sourceMappingURL=getappdelegate.js.map