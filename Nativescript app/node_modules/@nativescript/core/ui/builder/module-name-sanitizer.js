Object.defineProperty(exports, "__esModule", { value: true });
function sanitizeModuleName(moduleName, removeExtension) {
    if (removeExtension === void 0) { removeExtension = true; }
    moduleName = moduleName.trim();
    if (moduleName.startsWith("~/")) {
        moduleName = moduleName.substring(2);
    }
    else if (moduleName.startsWith("~")) {
        moduleName = moduleName.substring(1);
    }
    else if (moduleName.startsWith("/")) {
        moduleName = moduleName.substring(1);
    }
    if (removeExtension) {
        var extToRemove = ["js", "ts", "xml", "html", "css", "scss"];
        var extensionRegEx = new RegExp("(.*)\\.(?:" + extToRemove.join("|") + ")", "i");
        moduleName = moduleName.replace(extensionRegEx, "$1");
    }
    return moduleName;
}
exports.sanitizeModuleName = sanitizeModuleName;
//# sourceMappingURL=module-name-sanitizer.js.map