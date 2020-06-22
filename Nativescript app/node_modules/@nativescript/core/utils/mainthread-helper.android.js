Object.defineProperty(exports, "__esModule", { value: true });
function dispatchToMainThread(func) {
    new android.os.Handler(android.os.Looper.getMainLooper())
        .post(new java.lang.Runnable({
        run: func
    }));
}
exports.dispatchToMainThread = dispatchToMainThread;
function isMainThread() {
    return android.os.Looper.myLooper() === android.os.Looper.getMainLooper();
}
exports.isMainThread = isMainThread;
//# sourceMappingURL=mainthread-helper.android.js.map