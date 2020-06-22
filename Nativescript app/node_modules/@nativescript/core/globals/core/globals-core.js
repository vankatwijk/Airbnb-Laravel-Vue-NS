Object.defineProperty(exports, "__esModule", { value: true });
require("../ts-helpers");
require("../register-module-helpers");
global.moduleMerge = function (sourceExports, destExports) {
    for (var key in sourceExports) {
        destExports[key] = sourceExports[key];
    }
};
global.zonedCallback = function (callback) {
    if (global.zone) {
        return global.zone.bind(callback);
    }
    if (global.Zone) {
        return global.Zone.current.wrap(callback);
    }
    else {
        return callback;
    }
};
global.System = {
    import: function (path) {
        return new Promise(function (resolve, reject) {
            try {
                resolve(global.require(path));
            }
            catch (e) {
                reject(e);
            }
        });
    }
};
//# sourceMappingURL=globals-core.js.map