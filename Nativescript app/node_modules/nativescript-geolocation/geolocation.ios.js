"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var enums_1 = require("tns-core-modules/ui/enums");
var timer_1 = require("tns-core-modules/timer");
var application_1 = require("tns-core-modules/application");
var utils = require("tns-core-modules/utils/utils");
var geolocation_common_1 = require("./geolocation.common");
var Platform = require("platform");
var locationManagers = {};
var locationListeners = {};
var watchId = 0;
var attachedForErrorHandling = false;
var LocationListenerImpl = (function (_super) {
    __extends(LocationListenerImpl, _super);
    function LocationListenerImpl() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    LocationListenerImpl.initWithLocationError = function (successCallback, error) {
        var listener = LocationListenerImpl.new();
        watchId++;
        listener.id = watchId;
        listener._onLocation = successCallback;
        listener._onError = error;
        return listener;
    };
    LocationListenerImpl.initWithPromiseCallbacks = function (resolve, reject, authorizeAlways) {
        if (authorizeAlways === void 0) { authorizeAlways = false; }
        var listener = LocationListenerImpl.new();
        watchId++;
        listener.id = watchId;
        listener._resolve = resolve;
        listener._reject = reject;
        listener.authorizeAlways = authorizeAlways;
        return listener;
    };
    LocationListenerImpl.prototype.locationManagerDidUpdateLocations = function (manager, locations) {
        if (this._onLocation) {
            for (var i = 0, count = locations.count; i < count; i++) {
                var location_1 = locationFromCLLocation(locations.objectAtIndex(i));
                this._onLocation(location_1);
            }
        }
    };
    LocationListenerImpl.prototype.locationManagerDidFailWithError = function (manager, error) {
        if (this._onError) {
            this._onError(new Error(error.localizedDescription));
        }
    };
    LocationListenerImpl.prototype.locationManagerDidChangeAuthorizationStatus = function (manager, status) {
        switch (status) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                if (this._reject) {
                    LocationMonitor.stopLocationMonitoring(this.id);
                    this._reject(new Error("Authorization Denied."));
                }
                break;
            case 3:
            case 4:
                if (this._resolve) {
                    LocationMonitor.stopLocationMonitoring(this.id);
                    this._resolve();
                }
                break;
            default:
                break;
        }
    };
    LocationListenerImpl.ObjCProtocols = [CLLocationManagerDelegate];
    return LocationListenerImpl;
}(NSObject));
function locationFromCLLocation(clLocation) {
    var location = new Location();
    location.latitude = clLocation.coordinate.latitude;
    location.longitude = clLocation.coordinate.longitude;
    location.altitude = clLocation.altitude;
    location.horizontalAccuracy = clLocation.horizontalAccuracy;
    location.verticalAccuracy = clLocation.verticalAccuracy;
    location.speed = clLocation.speed;
    location.direction = clLocation.course;
    var timeIntervalSince1970 = NSDate.dateWithTimeIntervalSinceDate(0, clLocation.timestamp).timeIntervalSince1970;
    location.timestamp = new Date(timeIntervalSince1970 * 1000);
    location.ios = clLocation;
    return location;
}
function clLocationFromLocation(location) {
    var hAccuracy = location.horizontalAccuracy ? location.horizontalAccuracy : -1;
    var vAccuracy = location.verticalAccuracy ? location.verticalAccuracy : -1;
    var speed = location.speed ? location.speed : -1;
    var course = location.direction ? location.direction : -1;
    var altitude = location.altitude ? location.altitude : -1;
    var timestamp = location.timestamp ? location.timestamp : null;
    var iosLocation = CLLocation.alloc()
        .initWithCoordinateAltitudeHorizontalAccuracyVerticalAccuracyCourseSpeedTimestamp(CLLocationCoordinate2DMake(location.latitude, location.longitude), altitude, hAccuracy, vAccuracy, course, speed, timestamp);
    return iosLocation;
}
function errorHandler(errData) {
    while (watchId !== 0) {
        clearWatch(watchId);
        watchId--;
    }
}
function getVersionMaj() {
    return parseInt(Platform.device.osVersion.split(".")[0]);
}
function getCurrentLocation(options) {
    return new Promise(function (resolve, reject) {
        enableLocationRequest().then(function () {
            options = options || {};
            if (options.timeout === 0) {
                var lastLocation = LocationMonitor.getLastKnownLocation();
                if (lastLocation) {
                    if (typeof options.maximumAge === "number") {
                        if (lastLocation.timestamp.valueOf() + options.maximumAge > new Date().valueOf()) {
                            resolve(lastLocation);
                        }
                        else {
                            reject(new Error("Last known location too old!"));
                        }
                    }
                    else {
                        resolve(lastLocation);
                    }
                }
                else {
                    reject(new Error("There is no last known location!"));
                }
            }
            else {
                var timerId_1;
                var locListener_1;
                var initLocation_1;
                var stopTimerAndMonitor_1 = function (locListenerId) {
                    if (timerId_1 !== undefined) {
                        timer_1.clearTimeout(timerId_1);
                    }
                    LocationMonitor.stopLocationMonitoring(locListenerId);
                };
                var successCallback = function (location) {
                    if (getVersionMaj() < 9) {
                        if (typeof options.maximumAge === "number" && location.timestamp.valueOf() + options.maximumAge < new Date().valueOf()) {
                            return;
                        }
                        if (options.desiredAccuracy !== enums_1.Accuracy.any && !initLocation_1) {
                            initLocation_1 = location;
                            return;
                        }
                    }
                    stopTimerAndMonitor_1(locListener_1.id);
                    resolve(location);
                };
                locListener_1 = LocationListenerImpl.initWithLocationError(successCallback, reject);
                try {
                    if (getVersionMaj() >= 9) {
                        LocationMonitor.requestLocation(options, locListener_1);
                    }
                    else {
                        LocationMonitor.startLocationMonitoring(options, locListener_1);
                    }
                }
                catch (e) {
                    stopTimerAndMonitor_1(locListener_1.id);
                    reject(e);
                }
                if (typeof options.timeout === "number") {
                    timerId_1 = timer_1.setTimeout(function () {
                        LocationMonitor.stopLocationMonitoring(locListener_1.id);
                        reject(new Error("Timeout while searching for location!"));
                    }, options.timeout || geolocation_common_1.defaultGetLocationTimeout);
                }
            }
        }, reject);
    });
}
exports.getCurrentLocation = getCurrentLocation;
function watchLocation(successCallback, errorCallback, options) {
    if (!attachedForErrorHandling) {
        attachedForErrorHandling = true;
        application_1.on(application_1.uncaughtErrorEvent, errorHandler.bind(this));
    }
    var zonedSuccessCallback = global.zonedCallback(successCallback);
    var zonedErrorCallback = global.zonedCallback(errorCallback);
    var locListener = LocationListenerImpl.initWithLocationError(zonedSuccessCallback, zonedErrorCallback);
    try {
        var iosLocManager = getIOSLocationManager(locListener, options);
        iosLocManager.startUpdatingLocation();
        return locListener.id;
    }
    catch (e) {
        LocationMonitor.stopLocationMonitoring(locListener.id);
        zonedErrorCallback(e);
        return null;
    }
}
exports.watchLocation = watchLocation;
function clearWatch(_watchId) {
    LocationMonitor.stopLocationMonitoring(_watchId);
}
exports.clearWatch = clearWatch;
function enableLocationRequest(always, iosOpenSettingsIfLocationHasBeenDenied) {
    return new Promise(function (resolve, reject) {
        var locationIsEnabled = _isEnabled();
        if (locationIsEnabled) {
            resolve();
            return;
        }
        else {
            var status_1 = getIOSLocationManagerStatus();
            if (status_1 === 2 &&
                iosOpenSettingsIfLocationHasBeenDenied) {
                utils.ios.getter(UIApplication, UIApplication.sharedApplication).openURL(NSURL.URLWithString(UIApplicationOpenSettingsURLString));
            }
            else {
                var listener = LocationListenerImpl.initWithPromiseCallbacks(resolve, reject, always);
                try {
                    var manager = getIOSLocationManager(listener, null);
                    if (always) {
                        manager.requestAlwaysAuthorization();
                    }
                    else {
                        manager.requestWhenInUseAuthorization();
                    }
                }
                catch (e) {
                    LocationMonitor.stopLocationMonitoring(listener.id);
                    reject(e);
                }
            }
        }
    });
}
exports.enableLocationRequest = enableLocationRequest;
function _isEnabled() {
    if (CLLocationManager.locationServicesEnabled()) {
        var status_2 = getIOSLocationManagerStatus();
        return (status_2 === 4
            || status_2 === 3
            || status_2 === 3);
    }
    return false;
}
function isEnabled(options) {
    return new Promise(function (resolve, reject) {
        var isEnabledResult = _isEnabled();
        resolve(isEnabledResult);
    });
}
exports.isEnabled = isEnabled;
function getIOSLocationManagerStatus() {
    return CLLocationManager.authorizationStatus();
}
exports.getIOSLocationManagerStatus = getIOSLocationManagerStatus;
function distance(loc1, loc2) {
    if (!loc1.ios) {
        loc1.ios = clLocationFromLocation(loc1);
    }
    if (!loc2.ios) {
        loc2.ios = clLocationFromLocation(loc2);
    }
    return loc1.ios.distanceFromLocation(loc2.ios);
}
exports.distance = distance;
var LocationMonitor = (function () {
    function LocationMonitor() {
    }
    LocationMonitor.getLastKnownLocation = function () {
        var iosLocation;
        for (var locManagerId in locationManagers) {
            if (locationManagers.hasOwnProperty(locManagerId)) {
                var tempLocation = locationManagers[locManagerId].location;
                if (!iosLocation || tempLocation.timestamp > iosLocation.timestamp) {
                    iosLocation = tempLocation;
                }
            }
        }
        if (iosLocation) {
            return locationFromCLLocation(iosLocation);
        }
        var locListener = LocationListenerImpl.initWithLocationError(null);
        iosLocation = getIOSLocationManager(locListener, null).location;
        if (iosLocation) {
            return locationFromCLLocation(iosLocation);
        }
        return null;
    };
    LocationMonitor.requestLocation = function (options, locListener) {
        var iosLocManager = getIOSLocationManager(locListener, options);
        iosLocManager.requestLocation();
    };
    LocationMonitor.startLocationMonitoring = function (options, locListener) {
        var iosLocManager = getIOSLocationManager(locListener, options);
        iosLocManager.startUpdatingLocation();
    };
    LocationMonitor.stopLocationMonitoring = function (iosLocManagerId) {
        if (locationManagers[iosLocManagerId]) {
            locationManagers[iosLocManagerId].stopUpdatingLocation();
            locationManagers[iosLocManagerId].delegate = null;
            delete locationManagers[iosLocManagerId];
            delete locationListeners[iosLocManagerId];
        }
    };
    LocationMonitor.createiOSLocationManager = function (locListener, options) {
        var iosLocManager = new CLLocationManager();
        iosLocManager.delegate = locListener;
        iosLocManager.desiredAccuracy = options ? options.desiredAccuracy : enums_1.Accuracy.high;
        iosLocManager.distanceFilter = options ? options.updateDistance : geolocation_common_1.minRangeUpdate;
        locationManagers[locListener.id] = iosLocManager;
        locationListeners[locListener.id] = locListener;
        if (getVersionMaj() >= 9) {
            iosLocManager.allowsBackgroundLocationUpdates =
                options && options.iosAllowsBackgroundLocationUpdates != null ?
                    options.iosAllowsBackgroundLocationUpdates : false;
        }
        iosLocManager.pausesLocationUpdatesAutomatically =
            options && options.iosPausesLocationUpdatesAutomatically != null ?
                options.iosPausesLocationUpdatesAutomatically : true;
        return iosLocManager;
    };
    return LocationMonitor;
}());
exports.LocationMonitor = LocationMonitor;
var iosLocationManager;
function getIOSLocationManager(locListener, options) {
    if (!iosLocationManager) {
        return LocationMonitor.createiOSLocationManager(locListener, options);
    }
    else {
        var manager = new iosLocationManager();
        manager.delegate = locListener;
        manager.desiredAccuracy = options ? options.desiredAccuracy : enums_1.Accuracy.high;
        manager.distanceFilter = options ? options.updateDistance : geolocation_common_1.minRangeUpdate;
        locationManagers[locListener.id] = manager;
        locationListeners[locListener.id] = locListener;
        return manager;
    }
}
function setCustomLocationManager(manager) {
    iosLocationManager = function () { return manager; };
}
exports.setCustomLocationManager = setCustomLocationManager;
var Location = (function (_super) {
    __extends(Location, _super);
    function Location() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    return Location;
}(geolocation_common_1.LocationBase));
exports.Location = Location;
