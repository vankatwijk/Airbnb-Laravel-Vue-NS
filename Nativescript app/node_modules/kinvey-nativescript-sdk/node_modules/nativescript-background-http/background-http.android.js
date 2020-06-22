"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var application = require("tns-core-modules/application");
var observable_1 = require("tns-core-modules/data/observable");
var fileSystemModule = require("tns-core-modules/file-system");
var ProgressReceiver;
function onProgressReceiverProgress(context, uploadInfo) {
    var uploadId = uploadInfo.getUploadId();
    var task = Task.fromId(uploadId);
    var totalBytes = uploadInfo.getTotalBytes();
    var currentBytes = uploadInfo.getUploadedBytes();
    task.setTotalUpload(totalBytes);
    task.setUpload(currentBytes);
    task.setStatus("uploading");
    task.notify({
        eventName: "progress",
        object: task,
        currentBytes: currentBytes,
        totalBytes: totalBytes
    });
}
function onProgressReceiverCancelled(context, uploadInfo) {
    var uploadId = uploadInfo.getUploadId();
    var task = Task.fromId(uploadId);
    task.setStatus("cancelled");
    task.notify({ eventName: "cancelled", object: task });
}
function onProgressReceiverError(context, uploadInfo, response, error) {
    var uploadId = uploadInfo.getUploadId();
    var task = Task.fromId(uploadId);
    task.setStatus("error");
    task.notify({
        eventName: "error",
        object: task,
        error: error,
        responseCode: response && typeof response.getHttpCode === 'function' ? response.getHttpCode() : -1,
        response: response
    });
}
function onProgressReceiverCompleted(context, uploadInfo, response) {
    var uploadId = uploadInfo.getUploadId();
    var task = Task.fromId(uploadId);
    var totalUpload = uploadInfo.getTotalBytes();
    if (!totalUpload || !isFinite(totalUpload) || totalUpload <= 0) {
        totalUpload = 1;
    }
    task.setUpload(totalUpload);
    task.setTotalUpload(totalUpload);
    task.setStatus("complete");
    task.notify({
        eventName: "progress",
        object: task,
        currentBytes: totalUpload,
        totalBytes: totalUpload
    });
    task.notify({
        eventName: "responded",
        object: task,
        data: response.getBodyAsString(),
        responseCode: response && typeof response.getHttpCode === 'function' ? response.getHttpCode() : -1
    });
    task.notify({
        eventName: "complete",
        object: task,
        responseCode: response && typeof response.getHttpCode === 'function' ? response.getHttpCode() : -1,
        response: response
    });
}
function initializeProgressReceiver() {
    if (ProgressReceiver) {
        return;
    }
    var zonedOnProgress = global.zonedCallback(onProgressReceiverProgress);
    var zonedOnCancelled = global.zonedCallback(onProgressReceiverCancelled);
    var zonedOnError = global.zonedCallback(onProgressReceiverError);
    var zonedOnCompleted = global.zonedCallback(onProgressReceiverCompleted);
    var temp = {
        onProgress: function (context, uploadInfo) {
            zonedOnProgress(context, uploadInfo);
        },
        onCancelled: function (context, uploadInfo) {
            zonedOnCancelled(context, uploadInfo);
        },
        onError: function (context, uploadInfo, response, error) {
            zonedOnError(context, uploadInfo, response, error);
        },
        onCompleted: function (context, uploadInfo, serverResponse) {
            zonedOnCompleted(context, uploadInfo, serverResponse);
        }
    };
    var ProgressReceiverImpl = net.gotev.uploadservice.UploadServiceBroadcastReceiver.extend(temp);
    ProgressReceiver = ProgressReceiverImpl;
}
var hasNamespace = false;
function ensureUploadServiceNamespace() {
    if (!hasNamespace) {
        net.gotev.uploadservice.UploadService.NAMESPACE = application.android.packageName;
        hasNamespace = true;
    }
}
var receiver;
function ensureReceiver() {
    if (!receiver) {
        var context = application.android.context;
        initializeProgressReceiver();
        receiver = new ProgressReceiver();
        receiver.register(context);
    }
}
function session(id) {
    return new Session(id);
}
exports.session = session;
var ObservableBase = (function (_super) {
    __extends(ObservableBase, _super);
    function ObservableBase() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    ObservableBase.prototype.notifyPropertyChanged = function (propertyName, value) {
        this.notify({ object: this, eventName: observable_1.Observable.propertyChangeEvent, propertyName: propertyName, value: value });
    };
    return ObservableBase;
}(observable_1.Observable));
var Session = (function () {
    function Session(id) {
        this._id = id;
    }
    Session.prototype.uploadFile = function (fileUri, options) {
        return Task.create(this, fileUri, options);
    };
    Session.prototype.multipartUpload = function (params, options) {
        return Task.createMultiPart(this, params, options);
    };
    Object.defineProperty(Session.prototype, "id", {
        get: function () {
            return this._id;
        },
        enumerable: true,
        configurable: true
    });
    return Session;
}());
var Task = (function (_super) {
    __extends(Task, _super);
    function Task() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    Task.create = function (session, file, options) {
        ensureUploadServiceNamespace();
        ensureReceiver();
        var taskId = session.id + "{" + ++Task.taskCount + "}";
        var request = getBinaryRequest(taskId, options, file);
        var task = Task.initTask(taskId, session, options);
        request.startUpload();
        Task.cache[task._id] = task;
        return task;
    };
    Task.createMultiPart = function (session, params, options) {
        ensureUploadServiceNamespace();
        ensureReceiver();
        var taskId = session.id + "{" + ++Task.taskCount + "}";
        var request = getMultipartRequest(taskId, options, params);
        var task = Task.initTask(taskId, session, options);
        request.startUpload();
        Task.cache[task._id] = task;
        return task;
    };
    Task.initTask = function (taskId, session, options) {
        var task = new Task();
        task._session = session;
        task._id = taskId;
        task.setDescription(options.description);
        task.setUpload(0);
        task.setTotalUpload(1);
        task.setStatus("pending");
        return task;
    };
    Task.fromId = function (id) {
        return Task.cache[id];
    };
    Object.defineProperty(Task.prototype, "upload", {
        get: function () {
            return this._upload;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(Task.prototype, "totalUpload", {
        get: function () {
            return this._totalUpload;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(Task.prototype, "status", {
        get: function () {
            return this._status;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(Task.prototype, "description", {
        get: function () {
            return this._description;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(Task.prototype, "session", {
        get: function () {
            return this._session;
        },
        enumerable: true,
        configurable: true
    });
    Task.prototype.setTotalUpload = function (value) {
        this._totalUpload = value;
        this.notifyPropertyChanged("totalUpload", value);
    };
    Task.prototype.setUpload = function (value) {
        this._upload = value;
        this.notifyPropertyChanged("upload", value);
    };
    Task.prototype.setStatus = function (value) {
        this._status = value;
        this.notifyPropertyChanged("status", value);
    };
    Task.prototype.setDescription = function (value) {
        this._description = value;
        this.notifyPropertyChanged("description", value);
    };
    Task.prototype.cancel = function () {
        net.gotev.uploadservice.UploadService.stopUpload(this._id);
    };
    Task.taskCount = 0;
    Task.cache = {};
    return Task;
}(ObservableBase));
function getBinaryRequest(taskId, options, file) {
    var request = new net.gotev.uploadservice.BinaryUploadRequest(application.android.context, taskId, options.url);
    request.setFileToUpload(file);
    setRequestOptions(request, options);
    return request;
}
function getMultipartRequest(taskId, options, params) {
    var request = new net.gotev.uploadservice.MultipartUploadRequest(application.android.context, taskId, options.url);
    for (var i = 0; i < params.length; i++) {
        var curParam = params[i];
        if (typeof curParam.name === 'undefined') {
            throw new Error("You must have a `name` value");
        }
        if (curParam.filename) {
            var fileName = curParam.filename;
            if (fileName.startsWith("~/")) {
                fileName = fileName.replace("~/", fileSystemModule.knownFolders.currentApp().path + "/");
            }
            var destFileName = curParam.destFilename || fileName.substring(fileName.lastIndexOf('/') + 1, fileName.length);
            request.addFileToUpload(fileName, curParam.name, destFileName, curParam.mimeType);
        }
        else {
            request.addParameter(params[i].name, params[i].value);
        }
    }
    var utf8 = options.utf8;
    if (utf8) {
        request.setUtf8Charset();
    }
    setRequestOptions(request, options);
    return request;
}
function setRequestOptions(request, options) {
    var displayNotificationProgress = typeof options.androidDisplayNotificationProgress === "boolean" ? options.androidDisplayNotificationProgress : true;
    if (displayNotificationProgress) {
        var uploadNotificationConfig = new net.gotev.uploadservice.UploadNotificationConfig();
        var notificationTitle = typeof options.androidNotificationTitle === "string" ? options.androidNotificationTitle : 'File Upload';
        uploadNotificationConfig.setTitleForAllStatuses(notificationTitle);
        request.setNotificationConfig(uploadNotificationConfig);
    }
    var autoDeleteAfterUpload = typeof options.androidAutoDeleteAfterUpload === "boolean" ? options.androidAutoDeleteAfterUpload : false;
    if (autoDeleteAfterUpload) {
        request.setAutoDeleteFilesAfterSuccessfulUpload(true);
    }
    var maxRetryCount = typeof options.androidMaxRetries === "number" ? options.androidMaxRetries : undefined;
    if (maxRetryCount) {
        request.setMaxRetries(maxRetryCount);
    }
    var headers = options.headers;
    if (headers) {
        for (var header in headers) {
            var value = headers[header];
            if (value !== null && value !== void 0) {
                request.addHeader(header, value.toString());
            }
        }
    }
    request.setMethod(options.method ? options.method : "GET");
}
//# sourceMappingURL=background-http.android.js.map