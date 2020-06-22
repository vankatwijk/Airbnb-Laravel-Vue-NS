Object.defineProperty(exports, "__esModule", { value: true });
var Object_prototype_toString = ({}).toString;
var ArrayBufferString = Object_prototype_toString.call(ArrayBuffer.prototype);
function decoderReplacer(encoded) {
    var codePoint = encoded.charCodeAt(0) << 24;
    var leadingOnes = Math.clz32(~codePoint) | 0;
    var endPos = 0, stringLen = encoded.length | 0;
    var result = "";
    if (leadingOnes < 5 && stringLen >= leadingOnes) {
        codePoint = (codePoint << leadingOnes) >>> (24 + leadingOnes);
        for (endPos = 1; endPos < leadingOnes; endPos = endPos + 1 | 0) {
            codePoint = (codePoint << 6) | (encoded.charCodeAt(endPos) & 0x3f);
        }
        if (codePoint <= 0xFFFF) {
            result += String.fromCharCode(codePoint);
        }
        else if (codePoint <= 0x10FFFF) {
            codePoint = codePoint - 0x10000 | 0;
            result += String.fromCharCode((codePoint >> 10) + 0xD800 | 0, (codePoint & 0x3ff) + 0xDC00 | 0);
        }
        else {
            endPos = 0;
        }
    }
    for (; endPos < stringLen; endPos = endPos + 1 | 0) {
        result += "\ufffd";
    }
    return result;
}
function encoderReplacer(nonAsciiChars) {
    var point = nonAsciiChars.charCodeAt(0) | 0;
    if (point >= 0xD800 && point <= 0xDBFF) {
        var nextcode = nonAsciiChars.charCodeAt(1) | 0;
        if (nextcode !== nextcode) {
            return String.fromCharCode(0xef, 0xbf, 0xbd);
        }
        if (nextcode >= 0xDC00 && nextcode <= 0xDFFF) {
            point = ((point - 0xD800) << 10) + nextcode - 0xDC00 + 0x10000 | 0;
            if (point > 0xffff) {
                return String.fromCharCode((0x1e << 3) | (point >>> 18), (0x2 << 6) | ((point >>> 12) & 0x3f), (0x2 << 6) | ((point >>> 6) & 0x3f), (0x2 << 6) | (point & 0x3f));
            }
        }
        else {
            return String.fromCharCode(0xef, 0xbf, 0xbd);
        }
    }
    if (point <= 0x007f) {
        return nonAsciiChars;
    }
    else if (point <= 0x07ff) {
        return String.fromCharCode((0x6 << 5) | (point >>> 6), (0x2 << 6) | (point & 0x3f));
    }
    else {
        return String.fromCharCode((0xe << 4) | (point >>> 12), (0x2 << 6) | ((point >>> 6) & 0x3f), (0x2 << 6) | (point & 0x3f));
    }
}
var TextDecoder = (function () {
    function TextDecoder() {
        this[Symbol.toStringTag] = "TextDecoder";
    }
    Object.defineProperty(TextDecoder.prototype, "encoding", {
        get: function () {
            return "utf-8";
        },
        enumerable: true,
        configurable: true
    });
    TextDecoder.prototype.decode = function (input) {
        var buffer = ArrayBuffer.isView(input) ? input.buffer : input;
        if (Object_prototype_toString.call(buffer) !== ArrayBufferString) {
            throw Error("Failed to execute 'decode' on 'TextDecoder': The provided value is not of type '(ArrayBuffer or ArrayBufferView)'");
        }
        var inputAs8 = new Uint8Array(buffer);
        var resultingString = "";
        for (var index_1 = 0, len = inputAs8.length | 0; index_1 < len; index_1 = index_1 + 32768 | 0) {
            resultingString += String.fromCharCode.apply(0, inputAs8.slice(index_1, index_1 + 32768 | 0));
        }
        return resultingString.replace(/[\xc0-\xff][\x80-\xbf]*/g, decoderReplacer);
    };
    TextDecoder.prototype.toString = function () {
        return "[object TextDecoder]";
    };
    return TextDecoder;
}());
exports.TextDecoder = TextDecoder;
var TextEncoder = (function () {
    function TextEncoder() {
        this[Symbol.toStringTag] = "TextEncoder";
    }
    Object.defineProperty(TextEncoder.prototype, "encoding", {
        get: function () {
            return "utf-8";
        },
        enumerable: true,
        configurable: true
    });
    TextEncoder.prototype.encode = function (input) {
        if (input === void 0) { input = ""; }
        var encodedString = input === undefined ? "" : ("" + input).replace(/[\x80-\uD7ff\uDC00-\uFFFF]|[\uD800-\uDBFF][\uDC00-\uDFFF]?/g, encoderReplacer);
        var len = encodedString.length | 0, result = new Uint8Array(len);
        for (var i = 0; i < len; i = i + 1 | 0) {
            result[i] = encodedString.charCodeAt(i);
        }
        return result;
    };
    TextEncoder.prototype.toString = function () {
        return "[object TextEncoder]";
    };
    return TextEncoder;
}());
exports.TextEncoder = TextEncoder;
//# sourceMappingURL=text-common.js.map