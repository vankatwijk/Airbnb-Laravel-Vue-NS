Object.defineProperty(exports, "__esModule", { value: true });
require("../../core");
function registerOnGlobalContext(moduleName, exportName) {
    Object.defineProperty(global, exportName, {
        get: function () {
            var m = global.loadModule(moduleName);
            var resolvedValue = m[exportName];
            Object.defineProperty(global, exportName, { value: resolvedValue, configurable: true, writable: true });
            return resolvedValue;
        },
        configurable: true
    });
}
function installPolyfills(moduleName, exportNames) {
    if (global.__snapshot) {
        var loadedModule_1 = global.loadModule(moduleName);
        exportNames.forEach(function (exportName) { return global[exportName] = loadedModule_1[exportName]; });
    }
    else {
        exportNames.forEach(function (exportName) { return registerOnGlobalContext(moduleName, exportName); });
    }
}
exports.installPolyfills = installPolyfills;
//# sourceMappingURL=polyfill-helpers.js.map