"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var urlhandler_common_1 = require("./urlhandler.common");
var getappdelegate_1 = require("./getappdelegate");
var urlhandler_common_2 = require("./urlhandler.common");
exports.handleOpenURL = urlhandler_common_2.handleOpenURL;
exports.appDelegate = getappdelegate_1.getAppDelegate();
function enableMultipleOverridesFor(classRef, methodName, nextImplementation) {
    var currentImplementation = classRef.prototype[methodName];
    classRef.prototype[methodName] = function () {
        var result = currentImplementation && currentImplementation.apply(currentImplementation, Array.from(arguments));
        return nextImplementation.apply(nextImplementation, Array.from(arguments).concat([result]));
    };
}
enableMultipleOverridesFor(exports.appDelegate, 'applicationOpenURLOptions', function (application, url, options) {
    var lastArgument = arguments[arguments.length - 1];
    var previousResult = lastArgument !== options ? lastArgument : undefined;
    if (!previousResult) {
        var appURL_1 = urlhandler_common_1.extractAppURL(url.absoluteString);
        if (appURL_1 != null) {
            setTimeout(function () { return urlhandler_common_1.getCallback()(appURL_1); });
        }
        return true;
    }
    return previousResult;
});
enableMultipleOverridesFor(exports.appDelegate, 'applicationContinueUserActivityRestorationHandler', function (application, userActivity) {
    if (userActivity.activityType === NSUserActivityTypeBrowsingWeb) {
        var appURL_2 = urlhandler_common_1.extractAppURL(userActivity.webpageURL);
        if (appURL_2 !== null) {
            setTimeout(function () { return urlhandler_common_1.getCallback()(appURL_2); });
        }
    }
    return true;
});
//# sourceMappingURL=urlhandler.ios.js.map