Object.defineProperty(exports, "__esModule", { value: true });
var MIN_WH = "minWH";
var MIN_W = "minW";
var MIN_H = "minH";
var PRIORITY_STEP = 10000;
var minWidthHeightQualifier = {
    isMatch: function (value) {
        return value.indexOf(MIN_WH) === 0;
    },
    getMatchValue: function (value, context) {
        var numVal = parseInt(value.substr(MIN_WH.length));
        if (isNaN(numVal)) {
            return -1;
        }
        var actualLength = Math.min(context.width, context.height);
        if (actualLength < numVal) {
            return -1;
        }
        return PRIORITY_STEP - (actualLength - numVal);
    }
};
var minWidthQualifier = {
    isMatch: function (value) {
        return value.indexOf(MIN_W) === 0 && value.indexOf(MIN_WH) < 0;
    },
    getMatchValue: function (value, context) {
        var numVal = parseInt(value.substr(MIN_W.length));
        if (isNaN(numVal)) {
            return -1;
        }
        var actualWidth = context.width;
        if (actualWidth < numVal) {
            return -1;
        }
        return PRIORITY_STEP - (actualWidth - numVal);
    }
};
var minHeightQualifier = {
    isMatch: function (value) {
        return value.indexOf(MIN_H) === 0 && value.indexOf(MIN_WH) < 0;
    },
    getMatchValue: function (value, context) {
        var numVal = parseInt(value.substr(MIN_H.length));
        if (isNaN(numVal)) {
            return -1;
        }
        var actualHeight = context.height;
        if (actualHeight < numVal) {
            return -1;
        }
        return PRIORITY_STEP - (actualHeight - numVal);
    }
};
var platformQualifier = {
    isMatch: function (value) {
        return value === "android" ||
            value === "ios";
    },
    getMatchValue: function (value, context) {
        return value === context.os.toLowerCase() ? 1 : -1;
    }
};
var orientationQualifier = {
    isMatch: function (value) {
        return value === "land" ||
            value === "port";
    },
    getMatchValue: function (value, context) {
        var isLandscape = (context.width > context.height) ? 1 : -1;
        return (value === "land") ? isLandscape : -isLandscape;
    }
};
var supportedQualifiers = [
    minWidthHeightQualifier,
    minWidthQualifier,
    minHeightQualifier,
    orientationQualifier,
    platformQualifier
];
function checkQualifiers(qualifiers, context) {
    var result = 0;
    var value;
    for (var i = 0; i < qualifiers.length; i++) {
        if (qualifiers[i]) {
            value = checkQualifier(qualifiers[i], context);
            if (value < 0) {
                return -1;
            }
            result += value;
        }
    }
    return result;
}
function checkQualifier(value, context) {
    var result;
    for (var i = 0; i < supportedQualifiers.length; i++) {
        if (supportedQualifiers[i].isMatch(value)) {
            result = supportedQualifiers[i].getMatchValue(value, context);
            if (result > 0) {
                result += (supportedQualifiers.length - i) * PRIORITY_STEP;
            }
            return result;
        }
    }
    return -1;
}
function findMatch(path, ext, candidates, context) {
    var bestValue = -1;
    var result = null;
    for (var i = 0; i < candidates.length; i++) {
        var filePath = candidates[i];
        var qualifiersStr = filePath.substr(path.length, filePath.length - path.length - (ext ? ext.length : 0));
        var qualifiers = qualifiersStr.split(".");
        var value = checkQualifiers(qualifiers, context);
        if (value >= 0 && value > bestValue) {
            bestValue = value;
            result = candidates[i];
        }
    }
    return result;
}
exports.findMatch = findMatch;
//# sourceMappingURL=qualifier-matcher.js.map