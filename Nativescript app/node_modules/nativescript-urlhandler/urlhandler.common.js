"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var URL_HANDLER_CB;
function extractAppURL(urlParam) {
    if (!!urlParam) {
        var url_1 = urlParam.toString(), params = new Map(), urlWithPath = url_1.indexOf('//') < url_1.length - 2, urlWithParams = url_1.indexOf('?') !== -1, path = urlWithPath ? url_1.substring(url_1.indexOf('//') + 2, urlWithParams ? url_1.indexOf('?') : url_1.length) : null, parameters = url_1.substring(url_1.indexOf('?') + 1).split('&');
        if (urlWithParams) {
            for (var i = 0, len = parameters.length; i < len; i++) {
                var paramData = parameters[i].split('=');
                params.set(paramData[0], paramData[1] ? paramData[1] : null);
            }
        }
        return {
            params: params,
            path: path,
            toString: function () { return url_1; }
        };
    }
    else {
        return null;
    }
}
exports.extractAppURL = extractAppURL;
function handleOpenURL(handler) {
    URL_HANDLER_CB = handler;
}
exports.handleOpenURL = handleOpenURL;
function getCallback() {
    if (!URL_HANDLER_CB) {
        URL_HANDLER_CB = function () {
            console.error('No callback provided. Please ensure that you called "handleOpenURL" during application init!');
        };
    }
    return URL_HANDLER_CB;
}
exports.getCallback = getCallback;
//# sourceMappingURL=urlhandler.common.js.map