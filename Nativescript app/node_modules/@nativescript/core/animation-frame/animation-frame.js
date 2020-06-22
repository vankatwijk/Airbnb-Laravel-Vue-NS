Object.defineProperty(exports, "__esModule", { value: true });
var fps_native_1 = require("../fps-meter/fps-native");
var animation_native_1 = require("./animation-native");
var animationId = 0;
var nextFrameAnimationCallbacks = {};
var shouldStop = true;
var inAnimationFrame = false;
var fpsCallback;
var lastFrameTime = 0;
function getNewId() {
    return animationId++;
}
function ensureNative() {
    if (fpsCallback) {
        return;
    }
    fpsCallback = new fps_native_1.FPSCallback(doFrame);
}
function doFrame(currentTimeMillis) {
    lastFrameTime = currentTimeMillis;
    shouldStop = true;
    var thisFrameCbs = nextFrameAnimationCallbacks;
    nextFrameAnimationCallbacks = {};
    inAnimationFrame = true;
    for (var animationId_1 in thisFrameCbs) {
        if (thisFrameCbs[animationId_1]) {
            thisFrameCbs[animationId_1](lastFrameTime);
        }
    }
    inAnimationFrame = false;
    if (shouldStop) {
        fpsCallback.stop();
    }
}
function requestAnimationFrame(cb) {
    if (!inAnimationFrame) {
        inAnimationFrame = true;
        zonedCallback(cb)(animation_native_1.getTimeInFrameBase());
        inAnimationFrame = false;
        return getNewId();
    }
    ensureNative();
    var animId = getNewId();
    nextFrameAnimationCallbacks[animId] = zonedCallback(cb);
    shouldStop = false;
    fpsCallback.start();
    return animId;
}
exports.requestAnimationFrame = requestAnimationFrame;
function cancelAnimationFrame(id) {
    delete nextFrameAnimationCallbacks[id];
}
exports.cancelAnimationFrame = cancelAnimationFrame;
//# sourceMappingURL=animation-frame.js.map