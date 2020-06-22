function __export(m) {
    for (var p in m) if (!exports.hasOwnProperty(p)) exports[p] = m[p];
}
Object.defineProperty(exports, "__esModule", { value: true });
var types = require("./types");
var mainthread_helper_1 = require("./mainthread-helper");
var module_name_sanitizer_1 = require("../ui/builder/module-name-sanitizer");
var layout = require("./layout-helper");
exports.layout = layout;
__export(require("./mainthread-helper"));
exports.RESOURCE_PREFIX = "res://";
exports.FILE_PREFIX = "file:///";
function escapeRegexSymbols(source) {
    var escapeRegex = /[\-\[\]\/\{\}\(\)\*\+\?\.\\\^\$\|]/g;
    return source.replace(escapeRegex, "\\$&");
}
exports.escapeRegexSymbols = escapeRegexSymbols;
function convertString(value) {
    var result;
    if (!types.isString(value) || value.trim() === "") {
        result = value;
    }
    else {
        var valueAsNumber = +value;
        if (!isNaN(valueAsNumber)) {
            result = valueAsNumber;
        }
        else if (value && (value.toLowerCase() === "true" || value.toLowerCase() === "false")) {
            result = value.toLowerCase() === "true" ? true : false;
        }
        else {
            result = value;
        }
    }
    return result;
}
exports.convertString = convertString;
function getModuleName(path) {
    var moduleName = path.replace("./", "");
    return module_name_sanitizer_1.sanitizeModuleName(moduleName);
}
exports.getModuleName = getModuleName;
function isFileOrResourcePath(path) {
    if (!types.isString(path)) {
        return false;
    }
    return path.indexOf("~/") === 0 ||
        path.indexOf("/") === 0 ||
        path.indexOf(exports.RESOURCE_PREFIX) === 0;
}
exports.isFileOrResourcePath = isFileOrResourcePath;
function isFontIconURI(uri) {
    if (!types.isString(uri)) {
        return false;
    }
    var firstSegment = uri.trim().split("//")[0];
    return firstSegment && firstSegment.indexOf("font:") === 0;
}
exports.isFontIconURI = isFontIconURI;
function isDataURI(uri) {
    if (!types.isString(uri)) {
        return false;
    }
    var firstSegment = uri.trim().split(",")[0];
    return firstSegment && firstSegment.indexOf("data:") === 0 && firstSegment.indexOf("base64") >= 0;
}
exports.isDataURI = isDataURI;
function mergeSort(arr, compareFunc) {
    if (arr.length < 2) {
        return arr;
    }
    var middle = arr.length / 2;
    var left = arr.slice(0, middle);
    var right = arr.slice(middle, arr.length);
    return merge(mergeSort(left, compareFunc), mergeSort(right, compareFunc), compareFunc);
}
exports.mergeSort = mergeSort;
function merge(left, right, compareFunc) {
    var result = [];
    while (left.length && right.length) {
        if (compareFunc(left[0], right[0]) <= 0) {
            result.push(left.shift());
        }
        else {
            result.push(right.shift());
        }
    }
    while (left.length) {
        result.push(left.shift());
    }
    while (right.length) {
        result.push(right.shift());
    }
    return result;
}
exports.merge = merge;
function hasDuplicates(arr) {
    return arr.length !== eliminateDuplicates(arr).length;
}
exports.hasDuplicates = hasDuplicates;
function eliminateDuplicates(arr) {
    return Array.from(new Set(arr));
}
exports.eliminateDuplicates = eliminateDuplicates;
function executeOnMainThread(func) {
    if (mainthread_helper_1.isMainThread()) {
        return func();
    }
    else {
        mainthread_helper_1.dispatchToMainThread(func);
    }
}
exports.executeOnMainThread = executeOnMainThread;
function mainThreadify(func) {
    return function () {
        var _this = this;
        var argsToPass = arguments;
        executeOnMainThread(function () { return func.apply(_this, argsToPass); });
    };
}
exports.mainThreadify = mainThreadify;
//# sourceMappingURL=utils-common.js.map