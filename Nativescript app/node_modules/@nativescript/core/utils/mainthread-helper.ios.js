Object.defineProperty(exports, "__esModule", { value: true });
function dispatchToMainThread(func) {
    NSOperationQueue.mainQueue.addOperationWithBlock(func);
}
exports.dispatchToMainThread = dispatchToMainThread;
function isMainThread() {
    return NSThread.isMainThread;
}
exports.isMainThread = isMainThread;
//# sourceMappingURL=mainthread-helper.ios.js.map