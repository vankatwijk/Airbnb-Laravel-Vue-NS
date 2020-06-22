Object.defineProperty(exports, "__esModule", { value: true });
var platform_1 = require("../platform/platform");
var appCommonModule = require("../application/application-common");
var qualifier_matcher_1 = require("./qualifier-matcher");
var non_bundle_workflow_compat_1 = require("./non-bundle-workflow-compat");
var trace_1 = require("../trace");
var ModuleNameResolver = (function () {
    function ModuleNameResolver(context, moduleListProvider) {
        if (moduleListProvider === void 0) { moduleListProvider = global.getRegisteredModules; }
        this.context = context;
        this.moduleListProvider = moduleListProvider;
        this._cache = {};
    }
    ModuleNameResolver.prototype.resolveModuleName = function (path, ext) {
        var key = path + ext;
        var result = this._cache[key];
        if (result === undefined) {
            result = this.resolveModuleNameImpl(path, ext);
            this._cache[key] = result;
        }
        if (trace_1.isEnabled()) {
            trace_1.write("path: '" + path + "' with ext: '" + ext + "' resolved: '" + result + "'", trace_1.categories.ModuleNameResolver);
        }
        return result;
    };
    ModuleNameResolver.prototype.clearCache = function () {
        this._cache = {};
    };
    ModuleNameResolver.prototype.resolveModuleNameImpl = function (path, ext) {
        var result = null;
        ext = ext ? "." + ext : "";
        if (!global.TNS_WEBPACK) {
            non_bundle_workflow_compat_1.registerModulesFromFileSystem(path);
        }
        var candidates = this.getCandidates(path, ext);
        result = qualifier_matcher_1.findMatch(path, ext, candidates, this.context);
        return result;
    };
    ModuleNameResolver.prototype.getCandidates = function (path, ext) {
        var candidates = this.moduleListProvider()
            .filter(function (moduleName) { return moduleName.startsWith(path) && (!ext || moduleName.endsWith(ext)); });
        return candidates;
    };
    return ModuleNameResolver;
}());
exports.ModuleNameResolver = ModuleNameResolver;
var resolverInstance;
function resolveModuleName(path, ext) {
    if (global.__snapshot) {
        return resolveModuleSnapshot(path, ext);
    }
    if (!resolverInstance) {
        resolverInstance = new ModuleNameResolver({
            width: platform_1.screen.mainScreen.widthDIPs,
            height: platform_1.screen.mainScreen.heightDIPs,
            os: platform_1.device.os,
            deviceType: platform_1.device.deviceType
        });
    }
    return resolverInstance.resolveModuleName(path, ext);
}
exports.resolveModuleName = resolveModuleName;
function resolveModuleSnapshot(path, ext) {
    trace_1.write("Resolving module in SNAPSHOT context - path: '" + path + "' with ext: '" + ext + "'", trace_1.categories.ModuleNameResolver);
    return new ModuleNameResolver({
        width: 400,
        height: 800,
        os: "Android",
        deviceType: "Phone"
    }).resolveModuleName(path, ext);
}
function clearCache() {
    if (resolverInstance) {
        resolverInstance.clearCache();
    }
}
exports.clearCache = clearCache;
function _setResolver(resolver) {
    resolverInstance = resolver;
}
exports._setResolver = _setResolver;
appCommonModule.on("livesync", function (args) { return clearCache(); });
appCommonModule.on("orientationChanged", function (args) {
    resolverInstance = undefined;
});
//# sourceMappingURL=module-name-resolver.js.map