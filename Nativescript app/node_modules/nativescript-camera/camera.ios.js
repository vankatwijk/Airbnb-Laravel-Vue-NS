"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var types = require("tns-core-modules/utils/types");
var imageAssetModule = require("tns-core-modules/image-asset/image-asset");
var trace = require("tns-core-modules/trace/trace");
var UIImagePickerControllerDelegateImpl = (function (_super) {
    __extends(UIImagePickerControllerDelegateImpl, _super);
    function UIImagePickerControllerDelegateImpl() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    UIImagePickerControllerDelegateImpl.new = function () {
        return _super.new.call(this);
    };
    UIImagePickerControllerDelegateImpl.prototype.initWithCallback = function (callback, errorCallback) {
        this._callback = callback;
        this._errorCallback = errorCallback;
        return this;
    };
    UIImagePickerControllerDelegateImpl.prototype.initWithCallbackAndOptions = function (callback, errorCallback, options) {
        this._callback = callback;
        this._errorCallback = errorCallback;
        if (options) {
            this._width = options.width;
            this._height = options.height;
            this._saveToGallery = options.saveToGallery;
            this._allowsEditing = options.allowsEditing;
            this._keepAspectRatio = types.isNullOrUndefined(options.keepAspectRatio) ? true : options.keepAspectRatio;
        }
        return this;
    };
    UIImagePickerControllerDelegateImpl.prototype.imagePickerControllerDidFinishPickingMediaWithInfo = function (picker, info) {
        var _this = this;
        if (info) {
            var currentDate_1 = new Date();
            var source = info.valueForKey(UIImagePickerControllerOriginalImage);
            if (this._allowsEditing) {
                source = info.valueForKey(UIImagePickerControllerEditedImage);
            }
            if (source) {
                var imageSource = require("image-source");
                var imageSourceResult_1 = imageSource.fromNativeSource(source);
                if (this._callback) {
                    var imageAsset_1;
                    if (this._saveToGallery) {
                        PHPhotoLibrary.sharedPhotoLibrary().performChangesCompletionHandler(function () {
                            PHAssetChangeRequest.creationRequestForAssetFromImage(imageSourceResult_1.ios);
                        }, function (success, err) {
                            if (success) {
                                var fetchOptions = PHFetchOptions.alloc().init();
                                var sortDescriptors = NSArray.arrayWithObject(NSSortDescriptor.sortDescriptorWithKeyAscending("creationDate", false));
                                fetchOptions.sortDescriptors = sortDescriptors;
                                fetchOptions.predicate = NSPredicate.predicateWithFormatArgumentArray("mediaType = %d", NSArray.arrayWithObject(1));
                                var fetchResult = PHAsset.fetchAssetsWithOptions(fetchOptions);
                                if (fetchResult.count > 0) {
                                    var asset = fetchResult[0];
                                    var dateDiff = asset.creationDate.valueOf() - currentDate_1.valueOf();
                                    if (Math.abs(dateDiff) > 1000) {
                                        console.warn("Image asset returned was created more than 1 second ago");
                                    }
                                    imageAsset_1 = new imageAssetModule.ImageAsset(asset);
                                    _this.setImageAssetAndCallCallback(imageAsset_1);
                                }
                            }
                            else {
                                trace.write("An error ocurred while saving image to gallery: " +
                                    err, trace.categories.Error, trace.messageType.error);
                            }
                        });
                    }
                    else {
                        imageAsset_1 = new imageAssetModule.ImageAsset(imageSourceResult_1.ios);
                        this.setImageAssetAndCallCallback(imageAsset_1);
                    }
                }
            }
        }
        picker.presentingViewController.dismissViewControllerAnimatedCompletion(true, null);
        listener = null;
    };
    UIImagePickerControllerDelegateImpl.prototype.setImageAssetAndCallCallback = function (imageAsset) {
        if (this._keepAspectRatio) {
            var pictureWidth = imageAsset.nativeImage ? imageAsset.nativeImage.size.width : imageAsset.ios.pixelWidth;
            var pictureHeight = imageAsset.nativeImage ? imageAsset.nativeImage.size.height : imageAsset.ios.pixelHeight;
            var isPictureLandscape = pictureWidth > pictureHeight;
            var areOptionsLandscape = this._width > this._height;
            if (isPictureLandscape !== areOptionsLandscape) {
                var oldWidth = this._width;
                this._width = this._height;
                this._height = oldWidth;
            }
        }
        imageAsset.options = {
            width: this._width,
            height: this._height,
            keepAspectRatio: this._keepAspectRatio
        };
        this._callback(imageAsset);
    };
    UIImagePickerControllerDelegateImpl.prototype.imagePickerControllerDidCancel = function (picker) {
        picker.presentingViewController.dismissViewControllerAnimatedCompletion(true, null);
        listener = null;
        this._errorCallback(new Error("cancelled"));
    };
    UIImagePickerControllerDelegateImpl.ObjCProtocols = [UIImagePickerControllerDelegate];
    return UIImagePickerControllerDelegateImpl;
}(NSObject));
var listener;
exports.takePicture = function (options) {
    return new Promise(function (resolve, reject) {
        listener = null;
        var imagePickerController = UIImagePickerController.new();
        var reqWidth = 0;
        var reqHeight = 0;
        var keepAspectRatio = true;
        var saveToGallery = true;
        var allowsEditing = false;
        if (options) {
            reqWidth = options.width || 0;
            reqHeight = options.height || reqWidth;
            keepAspectRatio = types.isNullOrUndefined(options.keepAspectRatio) ? keepAspectRatio : options.keepAspectRatio;
            saveToGallery = types.isNullOrUndefined(options.saveToGallery) ? saveToGallery : options.saveToGallery;
            allowsEditing = types.isNullOrUndefined(options.allowsEditing) ? allowsEditing : options.allowsEditing;
        }
        var authStatus = PHPhotoLibrary.authorizationStatus();
        if (authStatus !== 3) {
            saveToGallery = false;
        }
        if (reqWidth && reqHeight) {
            listener = UIImagePickerControllerDelegateImpl.new().initWithCallbackAndOptions(resolve, reject, { width: reqWidth, height: reqHeight, keepAspectRatio: keepAspectRatio, saveToGallery: saveToGallery, allowsEditing: allowsEditing });
        }
        else if (saveToGallery) {
            listener = UIImagePickerControllerDelegateImpl.new().initWithCallbackAndOptions(resolve, reject, { saveToGallery: saveToGallery, keepAspectRatio: keepAspectRatio, allowsEditing: allowsEditing });
        }
        else {
            listener = UIImagePickerControllerDelegateImpl.new().initWithCallback(resolve, reject);
        }
        imagePickerController.delegate = listener;
        var sourceType = 1;
        var mediaTypes = UIImagePickerController.availableMediaTypesForSourceType(sourceType);
        var imageMediaType = "public.image";
        if (mediaTypes && mediaTypes.containsObject(imageMediaType)) {
            var mediaTypesArray = new NSMutableArray({ capacity: 1 });
            mediaTypesArray.addObject(imageMediaType);
            imagePickerController.mediaTypes = mediaTypesArray;
            imagePickerController.sourceType = sourceType;
            imagePickerController.cameraDevice = options && options.cameraFacing === "front" ?
                1 : 0;
            imagePickerController.allowsEditing = allowsEditing;
        }
        imagePickerController.modalPresentationStyle = 3;
        var frame = require("tns-core-modules/ui/frame");
        var topMostFrame = frame.topmost();
        if (topMostFrame) {
            var viewController = topMostFrame.currentPage && topMostFrame.currentPage.ios;
            if (viewController) {
                while (viewController.parentViewController) {
                    viewController = viewController.parentViewController;
                }
                while (viewController.presentedViewController) {
                    viewController = viewController.presentedViewController;
                }
                viewController.presentViewControllerAnimatedCompletion(imagePickerController, true, null);
            }
        }
    });
};
exports.isAvailable = function () {
    return UIImagePickerController.isSourceTypeAvailable(1);
};
exports.requestPermissions = function () {
    return new Promise(function (resolve, reject) {
        exports.requestPhotosPermissions().then(function () {
            exports.requestCameraPermissions().then(resolve, reject);
        }, reject);
    });
};
exports.requestPhotosPermissions = function () {
    return new Promise(function (resolve, reject) {
        var authStatus = PHPhotoLibrary.authorizationStatus();
        switch (authStatus) {
            case 0: {
                PHPhotoLibrary.requestAuthorization(function (auth) {
                    if (auth === 3) {
                        if (trace.isEnabled()) {
                            trace.write("Application can access photo library assets.", trace.categories.Debug);
                        }
                        resolve();
                    }
                    else {
                        reject();
                    }
                });
                break;
            }
            case 3: {
                if (trace.isEnabled()) {
                    trace.write("Application can access photo library assets.", trace.categories.Debug);
                }
                resolve();
                break;
            }
            case 1:
            case 2: {
                if (trace.isEnabled()) {
                    trace.write("Application can not access photo library assets.", trace.categories.Debug);
                }
                reject();
                break;
            }
        }
    });
};
exports.requestCameraPermissions = function () {
    return new Promise(function (resolve, reject) {
        var cameraStatus = AVCaptureDevice.authorizationStatusForMediaType(AVMediaTypeVideo);
        switch (cameraStatus) {
            case 0: {
                AVCaptureDevice.requestAccessForMediaTypeCompletionHandler(AVMediaTypeVideo, function (granted) {
                    if (granted) {
                        resolve();
                    }
                    else {
                        reject();
                    }
                });
                break;
            }
            case 3: {
                resolve();
                break;
            }
            case 1:
            case 2: {
                if (trace.isEnabled()) {
                    trace.write("Application can not access Camera assets.", trace.categories.Debug);
                }
                reject();
                break;
            }
        }
    });
};
//# sourceMappingURL=camera.ios.js.map