Object.defineProperty(exports, "__esModule", { value: true });
var MODAL = "modal";
var ROOT = "root";
var cssClasses = [];
exports.CLASS_PREFIX = "ns-";
exports.MODAL_ROOT_VIEW_CSS_CLASS = "" + exports.CLASS_PREFIX + MODAL;
exports.ROOT_VIEW_CSS_CLASS = "" + exports.CLASS_PREFIX + ROOT;
function getSystemCssClasses() {
    return cssClasses;
}
exports.getSystemCssClasses = getSystemCssClasses;
function pushToSystemCssClasses(value) {
    cssClasses.push(value);
    return cssClasses.length;
}
exports.pushToSystemCssClasses = pushToSystemCssClasses;
function removeSystemCssClass(value) {
    var index = cssClasses.indexOf(value);
    var removedElement;
    if (index > -1) {
        removedElement = cssClasses.splice(index, 1);
    }
    return removedElement;
}
exports.removeSystemCssClass = removeSystemCssClass;
function getModalRootViewCssClass() {
    return exports.MODAL_ROOT_VIEW_CSS_CLASS;
}
exports.getModalRootViewCssClass = getModalRootViewCssClass;
function getRootViewCssClasses() {
    return __spreadArrays([exports.ROOT_VIEW_CSS_CLASS], cssClasses);
}
exports.getRootViewCssClasses = getRootViewCssClasses;
function pushToRootViewCssClasses(value) {
    return pushToSystemCssClasses(value) + 1;
}
exports.pushToRootViewCssClasses = pushToRootViewCssClasses;
function removeFromRootViewCssClasses(value) {
    return removeSystemCssClass(value);
}
exports.removeFromRootViewCssClasses = removeFromRootViewCssClasses;
//# sourceMappingURL=system-classes.js.map