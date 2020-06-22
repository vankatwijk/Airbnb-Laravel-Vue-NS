var modules = new Map();
var modulesLoadedForUI = new Set();
var defaultExtensionMap = {
    ".js": ".js",
    ".ts": ".js",
    ".kt": ".js",
    ".css": ".css",
    ".scss": ".css",
    ".less": ".css",
    ".sass": ".css",
    ".xml": ".xml"
};
global.moduleResolvers = [global.require];
global.registerModule = function (name, loader) {
    modules.set(name, { loader: loader, moduleId: name });
};
global._unregisterModule = function _unregisterModule(name) {
    modules.delete(name);
};
global._isModuleLoadedForUI = function _isModuleLoadedForUI(moduleName) {
    return modulesLoadedForUI.has(moduleName);
};
global.registerWebpackModules = function registerWebpackModules(context, extensionMap) {
    if (extensionMap === void 0) { extensionMap = {}; }
    context.keys().forEach(function (moduleId) {
        var extDotIndex = moduleId.lastIndexOf(".");
        var base = moduleId.substr(0, extDotIndex);
        var originalExt = moduleId.substr(extDotIndex);
        var registerExt = extensionMap[originalExt] || defaultExtensionMap[originalExt] || originalExt;
        var isSourceFile = originalExt !== registerExt;
        var registerName = base + registerExt;
        var registerWithName = function (nickName) {
            modules.set(nickName, {
                moduleId: moduleId,
                loader: function () {
                    return context(moduleId);
                }
            });
        };
        if (registerName.startsWith("./") && registerName.endsWith(".js")) {
            var jsNickNames = [
                registerName.substr(2, registerName.length - 5),
                registerName.substr(0, registerName.length - 3),
                registerName.substr(2),
            ];
            jsNickNames.forEach(function (jsNickName) {
                if (isSourceFile || !global.moduleExists(jsNickName)) {
                    registerWithName(jsNickName);
                }
            });
        }
        else if (registerName.startsWith("./")) {
            var moduleNickNames = [
                registerName.substr(2),
            ];
            moduleNickNames.forEach(function (moduleNickName) {
                if (!global.moduleExists(moduleNickName)) {
                    registerWithName(moduleNickName);
                }
            });
        }
        if (isSourceFile || !global.moduleExists(registerName)) {
            registerWithName(registerName);
        }
    });
};
global.moduleExists = function moduleExists(name) {
    return modules.has(name);
};
global.loadModule = function loadModule(name, isUIModule) {
    if (isUIModule === void 0) { isUIModule = false; }
    var moduleInfo = modules.get(name);
    if (moduleInfo) {
        if (isUIModule) {
            modulesLoadedForUI.add(moduleInfo.moduleId);
        }
        var result = moduleInfo.loader(name);
        if (result.enableAutoAccept) {
            result.enableAutoAccept();
        }
        return result;
    }
    var _loop_1 = function (resolver) {
        var result = resolver(name);
        if (result) {
            modules.set(name, { moduleId: name, loader: function () { return result; } });
            return { value: result };
        }
    };
    for (var _i = 0, _a = global.moduleResolvers; _i < _a.length; _i++) {
        var resolver = _a[_i];
        var state_1 = _loop_1(resolver);
        if (typeof state_1 === "object")
            return state_1.value;
    }
};
global.getRegisteredModules = function getRegisteredModules() {
    return Array.from(modules.keys());
};
//# sourceMappingURL=register-module-helpers.js.map