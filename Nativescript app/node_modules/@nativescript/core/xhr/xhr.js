Object.defineProperty(exports, "__esModule", { value: true });
var http = require("../http");
var types = require("../utils/types");
var XMLHttpRequestResponseType;
(function (XMLHttpRequestResponseType) {
    XMLHttpRequestResponseType.empty = "";
    XMLHttpRequestResponseType.text = "text";
    XMLHttpRequestResponseType.json = "json";
    XMLHttpRequestResponseType.blob = "blob";
    XMLHttpRequestResponseType.arraybuffer = "arraybuffer";
})(XMLHttpRequestResponseType || (XMLHttpRequestResponseType = {}));
var XMLHttpRequest = (function () {
    function XMLHttpRequest() {
        this.UNSENT = 0;
        this.OPENED = 1;
        this.HEADERS_RECEIVED = 2;
        this.LOADING = 3;
        this.DONE = 4;
        this._responseType = "";
        this._listeners = new Map();
        this._readyState = this.UNSENT;
    }
    Object.defineProperty(XMLHttpRequest.prototype, "upload", {
        get: function () {
            return this;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(XMLHttpRequest.prototype, "readyState", {
        get: function () {
            return this._readyState;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(XMLHttpRequest.prototype, "responseType", {
        get: function () {
            return this._responseType;
        },
        set: function (value) {
            if (value === XMLHttpRequestResponseType.empty
                || value in XMLHttpRequestResponseType) {
                this._responseType = value;
            }
            else {
                throw new Error("Response type of '" + value + "' not supported.");
            }
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(XMLHttpRequest.prototype, "responseText", {
        get: function () {
            if (this._responseType !== XMLHttpRequestResponseType.empty
                && this._responseType !== XMLHttpRequestResponseType.text) {
                throw new Error("Failed to read the 'responseText' property from 'XMLHttpRequest': " +
                    "The value is only accessible if the object's 'responseType' is '' or 'text' " +
                    ("(was '" + this._responseType + "')."));
            }
            if (types.isFunction(this._responseTextReader)) {
                return this._responseTextReader();
            }
            return "";
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(XMLHttpRequest.prototype, "response", {
        get: function () {
            if (this._responseType === XMLHttpRequestResponseType.empty
                || this._responseType === XMLHttpRequestResponseType.text) {
                if (this._readyState !== this.LOADING && this._readyState !== this.DONE) {
                    return "";
                }
                else {
                    return this._response;
                }
            }
            else {
                if (this._readyState !== this.DONE) {
                    return null;
                }
                else {
                    return this._response;
                }
            }
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(XMLHttpRequest.prototype, "status", {
        get: function () {
            return this._status;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(XMLHttpRequest.prototype, "statusText", {
        get: function () {
            if (this._readyState === this.UNSENT
                || this._readyState === this.OPENED
                || this._errorFlag) {
                return "";
            }
            return statuses[this._status];
        },
        enumerable: true,
        configurable: true
    });
    XMLHttpRequest.prototype._loadResponse = function (r) {
        this._status = r.statusCode;
        this._headers = r.headers;
        this._setReadyState(this.HEADERS_RECEIVED);
        this._setReadyState(this.LOADING);
        this._responseTextReader = function () { return r.content.toString(); };
        var contentType = this.getResponseHeader("Content-Type");
        var mimeType = (contentType && contentType.toLowerCase()) || "text/xml";
        var finalMimeType = this._overrideMimeType || mimeType;
        if (this._responseType === XMLHttpRequestResponseType.json) {
            this._response = r.content.toJSON();
        }
        else if (this._responseType === XMLHttpRequestResponseType.text
            || this._responseType === XMLHttpRequestResponseType.empty) {
            this._response = this.responseText;
        }
        else if (this._responseType === XMLHttpRequestResponseType.arraybuffer) {
            this._response = r.content.toArrayBuffer();
        }
        else if (this._responseType === XMLHttpRequestResponseType.blob) {
            this._response = new Blob([r.content.toArrayBuffer()], { type: finalMimeType });
        }
        this.emitEvent("progress");
        this._sendFlag = false;
        this._setReadyState(this.DONE);
    };
    XMLHttpRequest.prototype.emitEvent = function (eventName) {
        var args = [];
        for (var _i = 1; _i < arguments.length; _i++) {
            args[_i - 1] = arguments[_i];
        }
        if (types.isFunction(this["on" + eventName])) {
            this["on" + eventName].apply(this, args);
        }
        var handlers = this._listeners.get(eventName) || [];
        handlers.forEach(function (handler) {
            handler.apply(void 0, args);
        });
    };
    XMLHttpRequest.prototype._setReadyState = function (value) {
        if (this._readyState !== value) {
            this._readyState = value;
            this.emitEvent("readystatechange");
        }
        if (this._readyState === this.DONE) {
            this.emitEvent("load");
            this.emitEvent("loadend");
        }
    };
    XMLHttpRequest.prototype._setRequestError = function (eventName, error) {
        this._readyState = this.DONE;
        this._response = error;
        this.emitEvent("readystatechange");
        this.emitEvent(eventName, error);
        this.emitEvent("loadend");
    };
    XMLHttpRequest.prototype.addEventListener = function (eventName, handler) {
        if (["abort", "error", "load", "loadend", "loadstart", "progress", "readystatechange"].indexOf(eventName) === -1) {
            throw new Error("Event not supported: " + eventName);
        }
        var handlers = this._listeners.get(eventName) || [];
        handlers.push(handler);
        this._listeners.set(eventName, handlers);
    };
    XMLHttpRequest.prototype.removeEventListener = function (eventName, toDetach) {
        var handlers = this._listeners.get(eventName) || [];
        handlers = handlers.filter(function (handler) { return handler !== toDetach; });
        this._listeners.set(eventName, handlers);
    };
    XMLHttpRequest.prototype.open = function (method, url, async, user, password) {
        if (types.isString(method) && types.isString(url)) {
            this._options = { url: url, method: method };
            this._options.headers = {};
            if (types.isString(user)) {
                this._options.headers["user"] = user;
            }
            if (types.isString(password)) {
                this._options.headers["password"] = password;
            }
            this._setReadyState(this.OPENED);
        }
    };
    XMLHttpRequest.prototype.abort = function () {
        this._response = null;
        this._responseTextReader = null;
        this._headers = null;
        this._status = null;
        if ((this._readyState === this.OPENED && this._sendFlag)
            || this._readyState === this.HEADERS_RECEIVED
            || this._readyState === this.LOADING) {
            this._errorFlag = true;
            this._sendFlag = false;
            this._setRequestError("abort");
        }
        if (this._readyState === this.DONE) {
            this._readyState = this.UNSENT;
        }
    };
    XMLHttpRequest.prototype.send = function (data) {
        var _this = this;
        this._errorFlag = false;
        this._response = null;
        this._responseTextReader = null;
        this._headers = null;
        this._status = null;
        if (this._readyState !== this.OPENED || this._sendFlag) {
            throw new Error("Failed to execute 'send' on 'XMLHttpRequest': " +
                "The object's state must be OPENED.");
        }
        if (types.isString(data) && this._options.method !== "GET") {
            this._options.content = data;
        }
        else if (data instanceof FormData) {
            this._options.content = data.toString();
        }
        else if (data instanceof Blob) {
            this.setRequestHeader("Content-Type", data.type);
            this._options.content = Blob.InternalAccessor.getBuffer(data);
        }
        else if (data instanceof ArrayBuffer) {
            this._options.content = data;
        }
        this._sendFlag = true;
        this.emitEvent("loadstart");
        http.request(this._options).then(function (r) {
            if (!_this._errorFlag && _this._sendFlag) {
                _this._loadResponse(r);
            }
        }).catch(function (e) {
            _this._errorFlag = true;
            _this._sendFlag = false;
            _this._setRequestError("error", e);
        });
    };
    XMLHttpRequest.prototype.setRequestHeader = function (header, value) {
        if (this._readyState !== this.OPENED || this._sendFlag) {
            throw new Error("Failed to execute 'setRequestHeader' on 'XMLHttpRequest': " +
                "The object's state must be OPENED.");
        }
        if (types.isString(header) && types.isString(value)) {
            this._options.headers[header] = value;
        }
    };
    XMLHttpRequest.prototype.getAllResponseHeaders = function () {
        if (this._readyState < 2 || this._errorFlag) {
            return "";
        }
        var result = "";
        for (var i in this._headers) {
            result += i + ": " + this._headers[i] + "\r\n";
        }
        return result.substr(0, result.length - 2);
    };
    XMLHttpRequest.prototype.getResponseHeader = function (header) {
        if (types.isString(header) && this._readyState > 1
            && this._headers
            && !this._errorFlag) {
            header = header.toLowerCase();
            for (var i in this._headers) {
                if (i.toLowerCase() === header) {
                    return this._headers[i];
                }
            }
        }
        return null;
    };
    XMLHttpRequest.prototype.overrideMimeType = function (mime) {
        if (this._readyState === this.LOADING || this._readyState === this.DONE) {
            throw new Error("Failed to execute 'overrideMimeType' on 'XMLHttpRequest': " +
                "MimeType cannot be overridden when the state is LOADING or DONE.");
        }
        this._overrideMimeType = mime;
    };
    return XMLHttpRequest;
}());
exports.XMLHttpRequest = XMLHttpRequest;
var statuses = {
    100: "Continue",
    101: "Switching Protocols",
    200: "OK",
    201: "Created",
    202: "Accepted",
    203: "Non - Authoritative Information",
    204: "No Content",
    205: "Reset Content",
    206: "Partial Content",
    300: "Multiple Choices",
    301: "Moved Permanently",
    302: "Found",
    303: "See Other",
    304: "Not Modified",
    305: "Use Proxy",
    307: "Temporary Redirect",
    400: "Bad Request",
    401: "Unauthorized",
    402: "Payment Required",
    403: "Forbidden",
    404: "Not Found",
    405: "Method Not Allowed",
    406: "Not Acceptable",
    407: "Proxy Authentication Required",
    408: "Request Timeout",
    409: "Conflict",
    410: "Gone",
    411: "Length Required",
    412: "Precondition Failed",
    413: "Request Entity Too Large",
    414: "Request - URI Too Long",
    415: "Unsupported Media Type",
    416: "Requested Range Not Satisfiable",
    417: "Expectation Failed",
    500: "Internal Server Error",
    501: "Not Implemented",
    502: "Bad Gateway",
    503: "Service Unavailable",
    504: "Gateway Timeout",
    505: "HTTP Version Not Supported"
};
var FormData = (function () {
    function FormData() {
        this._data = new Map();
    }
    FormData.prototype.append = function (name, value) {
        this._data.set(name, value);
    };
    FormData.prototype.toString = function () {
        var arr = new Array();
        this._data.forEach(function (value, name, map) {
            arr.push(encodeURIComponent(name) + "=" + encodeURIComponent(value));
        });
        return arr.join("&");
    };
    return FormData;
}());
exports.FormData = FormData;
var Blob = (function () {
    function Blob(chunks, opts) {
        if (chunks === void 0) { chunks = []; }
        if (opts === void 0) { opts = {}; }
        this[Symbol.toStringTag] = "Blob";
        var dataChunks = [];
        for (var _i = 0, chunks_1 = chunks; _i < chunks_1.length; _i++) {
            var chunk = chunks_1[_i];
            if (chunk instanceof Blob) {
                dataChunks.push(chunk._buffer);
            }
            else if (typeof chunk === "string") {
                var textEncoder = new TextEncoder();
                dataChunks.push(textEncoder.encode(chunk));
            }
            else if (chunk instanceof DataView) {
                dataChunks.push(new Uint8Array(chunk.buffer.slice(0)));
            }
            else if (chunk instanceof ArrayBuffer || ArrayBuffer.isView(chunk)) {
                dataChunks.push(new Uint8Array(ArrayBuffer.isView(chunk)
                    ? chunk.buffer.slice(0)
                    : chunk.slice(0)));
            }
            else {
                var textEncoder = new TextEncoder();
                dataChunks.push(textEncoder.encode(String(chunk)));
            }
        }
        var size = dataChunks.reduce(function (size, chunk) { return size + chunk.byteLength; }, 0);
        var buffer = new Uint8Array(size);
        var offset = 0;
        for (var i = 0; i < dataChunks.length; i++) {
            var chunk = dataChunks[i];
            buffer.set(chunk, offset);
            offset += chunk.byteLength;
        }
        this._buffer = buffer;
        this._size = this._buffer.byteLength;
        this._type = opts.type || "";
        if (/[^\u0020-\u007E]/.test(this._type)) {
            this._type = "";
        }
        else {
            this._type = this._type.toLowerCase();
        }
    }
    Object.defineProperty(Blob.prototype, "size", {
        get: function () {
            return this._size;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(Blob.prototype, "type", {
        get: function () {
            return this._type;
        },
        enumerable: true,
        configurable: true
    });
    Blob.prototype.arrayBuffer = function () {
        return Promise.resolve(this._buffer);
    };
    Blob.prototype.text = function () {
        var textDecoder = new TextDecoder();
        return Promise.resolve(textDecoder.decode(this._buffer));
    };
    Blob.prototype.slice = function (start, end, type) {
        var slice = this._buffer.slice(start || 0, end || this._buffer.length);
        return new Blob([slice], { type: type });
    };
    Blob.prototype.stream = function () {
        throw new Error("stream is currently not supported");
    };
    Blob.prototype.toString = function () {
        return "[object Blob]";
    };
    Blob.InternalAccessor = (function () {
        function class_1() {
        }
        class_1.getBuffer = function (blob) {
            return blob._buffer;
        };
        return class_1;
    }());
    return Blob;
}());
exports.Blob = Blob;
var File = (function (_super) {
    __extends(File, _super);
    function File(chunks, name, opts) {
        if (opts === void 0) { opts = {}; }
        var _this = _super.call(this, chunks, opts) || this;
        _this[Symbol.toStringTag] = "File";
        _this._name = name.replace(/\//g, ":");
        _this._lastModified =
            opts.lastModified
                ? new Date(opts.lastModified).valueOf()
                : Date.now();
        return _this;
    }
    Object.defineProperty(File.prototype, "name", {
        get: function () {
            return this._name;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(File.prototype, "lastModified", {
        get: function () {
            return this._lastModified;
        },
        enumerable: true,
        configurable: true
    });
    File.prototype.toString = function () {
        return "[object File]";
    };
    return File;
}(Blob));
exports.File = File;
var FileReader = (function () {
    function FileReader() {
        this.EMPTY = 0;
        this.LOADING = 1;
        this.DONE = 2;
        this._listeners = new Map();
        this[Symbol.toStringTag] = "FileReader";
    }
    Object.defineProperty(FileReader.prototype, "readyState", {
        get: function () {
            return this._readyState;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(FileReader.prototype, "result", {
        get: function () {
            return this._result;
        },
        enumerable: true,
        configurable: true
    });
    FileReader.prototype._array2base64 = function (input) {
        var byteToCharMap = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
        var output = [];
        for (var i = 0; i < input.length; i += 3) {
            var byte1 = input[i];
            var haveByte2 = i + 1 < input.length;
            var byte2 = haveByte2 ? input[i + 1] : 0;
            var haveByte3 = i + 2 < input.length;
            var byte3 = haveByte3 ? input[i + 2] : 0;
            var outByte1 = byte1 >> 2;
            var outByte2 = ((byte1 & 0x03) << 4) | (byte2 >> 4);
            var outByte3 = ((byte2 & 0x0F) << 2) | (byte3 >> 6);
            var outByte4 = byte3 & 0x3F;
            if (!haveByte3) {
                outByte4 = 64;
                if (!haveByte2) {
                    outByte3 = 64;
                }
            }
            output.push(byteToCharMap[outByte1], byteToCharMap[outByte2], byteToCharMap[outByte3], byteToCharMap[outByte4]);
        }
        return output.join("");
    };
    FileReader.prototype._read = function (blob, kind) {
        var _this = this;
        if (!(blob instanceof Blob)) {
            throw new TypeError("Failed to execute '" + kind + "' on 'FileReader': parameter 1 is not of type 'Blob'.");
        }
        this._result = "";
        setTimeout(function () {
            _this._readyState = _this.LOADING;
            _this.emitEvent("load");
            _this.emitEvent("loadend");
        });
    };
    FileReader.prototype.emitEvent = function (eventName) {
        var args = [];
        for (var _i = 1; _i < arguments.length; _i++) {
            args[_i - 1] = arguments[_i];
        }
        if (types.isFunction(this["on" + eventName])) {
            this["on" + eventName].apply(this, args);
        }
        var handlers = this._listeners.get(eventName) || [];
        handlers.forEach(function (handler) {
            handler.apply(void 0, args);
        });
    };
    FileReader.prototype.addEventListener = function (eventName, handler) {
        if (["abort", "error", "load", "loadend", "loadstart", "progress"].indexOf(eventName) === -1) {
            throw new Error("Event not supported: " + eventName);
        }
        var handlers = this._listeners.get(eventName) || [];
        handlers.push(handler);
        this._listeners.set(eventName, handlers);
    };
    FileReader.prototype.removeEventListener = function (eventName, toDetach) {
        var handlers = this._listeners.get(eventName) || [];
        handlers = handlers.filter(function (handler) { return handler !== toDetach; });
        this._listeners.set(eventName, handlers);
    };
    FileReader.prototype.readAsDataURL = function (blob) {
        this._read(blob, "readAsDataURL");
        this._result = "data:" + blob.type + ";base64," + this._array2base64(Blob.InternalAccessor.getBuffer(blob));
    };
    FileReader.prototype.readAsText = function (blob) {
        this._read(blob, "readAsText");
        var textDecoder = new TextDecoder();
        this._result = textDecoder.decode(Blob.InternalAccessor.getBuffer(blob));
    };
    FileReader.prototype.readAsArrayBuffer = function (blob) {
        this._read(blob, "readAsArrayBuffer");
        this._result = Blob.InternalAccessor.getBuffer(blob).buffer.slice(0);
    };
    FileReader.prototype.abort = function () {
    };
    FileReader.prototype.toString = function () {
        return "[object FileReader]";
    };
    return FileReader;
}());
exports.FileReader = FileReader;
//# sourceMappingURL=xhr.js.map