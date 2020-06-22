"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var application_1 = require("application");
var enums_1 = require("tns-core-modules/ui/enums");
var timer_1 = require("tns-core-modules/timer");
var geolocation_common_1 = require("./geolocation.common");
var permissions = require("nativescript-permissions");
var REQUEST_ENABLE_LOCATION = 4269;
var _onEnableLocationSuccess = null;
var _onEnableLocationFail = null;
var locationListeners = {};
var watchIdCounter = 0;
var fusedLocationClient;
var attachedForErrorHandling = false;
function _ensureLocationClient() {
    fusedLocationClient = fusedLocationClient ||
        com.google.android.gms.location.LocationServices.getFusedLocationProviderClient(application_1.android.context);
}
application_1.android.on(application_1.AndroidApplication.activityResultEvent, function (args) {
    if (args.requestCode === REQUEST_ENABLE_LOCATION) {
        if (args.resultCode === 0) {
            if (_onEnableLocationFail) {
                _onEnableLocationFail("Location not enabled.");
            }
        }
        else if (_onEnableLocationSuccess) {
            _onEnableLocationSuccess();
        }
    }
});
function isAirplaneModeOn() {
    return android.provider.Settings.System.getInt(application_1.android.context.getContentResolver(), android.provider.Settings.System.AIRPLANE_MODE_ON) !== 0;
}
function isProviderEnabled(provider) {
    try {
        var locationManager = application_1.android.context
            .getSystemService(android.content.Context.LOCATION_SERVICE);
        return locationManager.isProviderEnabled(provider);
    }
    catch (ex) {
        return false;
    }
}
function errorHandler(errData) {
    while (watchIdCounter !== 0) {
        clearWatch(watchIdCounter);
        watchIdCounter--;
    }
}
function getCurrentLocation(options) {
    return new Promise(function (resolve, reject) {
        enableLocationRequest().then(function () {
            if (options.timeout === 0) {
                LocationManager.getLastLocation(options.maximumAge, resolve, reject);
            }
            else {
                var locationRequest = _getLocationRequest(options);
                var watchId_1 = _getNextWatchId();
                var locationCallback = _getLocationCallback(watchId_1, function (nativeLocation) {
                    clearWatch(watchId_1);
                    resolve(new Location(nativeLocation));
                });
                LocationManager.requestLocationUpdates(locationRequest, locationCallback);
                var timerId_1 = timer_1.setTimeout(function () {
                    clearWatch(watchId_1);
                    timer_1.clearTimeout(timerId_1);
                    reject(new Error("Timeout while searching for location!"));
                }, options.timeout || geolocation_common_1.defaultGetLocationTimeout);
            }
        }, reject);
    });
}
exports.getCurrentLocation = getCurrentLocation;
function _getNextWatchId() {
    var watchId = ++watchIdCounter;
    return watchId;
}
function _getLocationCallback(watchId, onLocation) {
    var LocationCallback = com.google.android.gms.location.LocationCallback.extend({
        onLocationResult: function (locationResult) {
            this.onLocation(locationResult.getLastLocation());
        }
    });
    var locationCallback = new LocationCallback();
    locationCallback.onLocation = onLocation;
    locationListeners[watchId] = locationCallback;
    return locationCallback;
}
function _getLocationRequest(options) {
    var mLocationRequest = new com.google.android.gms.location.LocationRequest();
    var updateTime = options.updateTime === 0 ? 0 : options.updateTime || geolocation_common_1.minTimeUpdate;
    mLocationRequest.setInterval(updateTime);
    var minUpdateTime = options.minimumUpdateTime === 0 ?
        0 : options.minimumUpdateTime || Math.min(updateTime, geolocation_common_1.fastestTimeUpdate);
    mLocationRequest.setFastestInterval(minUpdateTime);
    if (options.updateDistance) {
        mLocationRequest.setSmallestDisplacement(options.updateDistance);
    }
    if (options.desiredAccuracy === enums_1.Accuracy.high) {
        mLocationRequest.setPriority(com.google.android.gms.location.LocationRequest.PRIORITY_HIGH_ACCURACY);
    }
    else {
        mLocationRequest.setPriority(com.google.android.gms.location.LocationRequest.PRIORITY_BALANCED_POWER_ACCURACY);
    }
    return mLocationRequest;
}
function _requestLocationPermissions() {
    return new Promise(function (resolve, reject) {
        if (LocationManager.shouldSkipChecks()) {
            resolve();
        }
        else {
            permissions.requestPermission(android.Manifest.permission.ACCESS_FINE_LOCATION).then(resolve, reject);
        }
    });
}
function _getLocationListener(maxAge, onLocation, onError) {
    return _getTaskSuccessListener(function (nativeLocation) {
        if (nativeLocation != null) {
            var location_1 = new Location(nativeLocation);
            if (typeof maxAge === "number" && nativeLocation != null) {
                if (location_1.timestamp.valueOf() + maxAge > new Date().valueOf()) {
                    onLocation(location_1);
                }
                else {
                    onError(new Error("Last known location too old!"));
                }
            }
            else {
                onLocation(location_1);
            }
        }
        else {
            onError(new Error("There is no last known location!"));
        }
    });
}
function _getTaskSuccessListener(done) {
    return new com.google.android.gms.tasks.OnSuccessListener({
        onSuccess: done
    });
}
function _getTaskFailListener(done) {
    return new com.google.android.gms.tasks.OnFailureListener({
        onFailure: done
    });
}
function watchLocation(successCallback, errorCallback, options) {
    var zonedSuccessCallback = zonedCallback(successCallback);
    var zonedErrorCallback = zonedCallback(errorCallback);
    if ((!permissions.hasPermission(android.Manifest.permission.ACCESS_FINE_LOCATION) ||
        !_isGooglePlayServicesAvailable()) && !LocationManager.shouldSkipChecks()) {
        throw new Error('Cannot watch location. Call "enableLocationRequest" first');
    }
    if (!attachedForErrorHandling) {
        attachedForErrorHandling = true;
        application_1.on(application_1.uncaughtErrorEvent, errorHandler.bind(this));
    }
    var locationRequest = _getLocationRequest(options);
    var watchId = _getNextWatchId();
    var locationCallback = _getLocationCallback(watchId, function (nativeLocation) {
        zonedSuccessCallback(new Location(nativeLocation));
    });
    LocationManager.requestLocationUpdates(locationRequest, locationCallback);
    return watchId;
}
exports.watchLocation = watchLocation;
function clearWatch(watchId) {
    var listener = locationListeners[watchId];
    if (listener) {
        LocationManager.removeLocationUpdates(listener);
        delete locationListeners[watchId];
    }
}
exports.clearWatch = clearWatch;
function enableLocationRequest(always) {
    return new Promise(function (resolve, reject) {
        _requestLocationPermissions().then(function () {
            _makeGooglePlayServicesAvailable().then(function () {
                _isLocationServiceEnabled().then(function () {
                    resolve();
                }, function (ex) {
                    if (typeof ex.getStatusCode === "function") {
                        var statusCode = ex.getStatusCode();
                        if (statusCode === com.google.android.gms.location.LocationSettingsStatusCodes.RESOLUTION_REQUIRED) {
                            try {
                                _onEnableLocationSuccess = resolve;
                                _onEnableLocationFail = reject;
                                return ex.startResolutionForResult(application_1.android.foregroundActivity, REQUEST_ENABLE_LOCATION);
                            }
                            catch (sendEx) {
                                return resolve();
                            }
                        }
                        else if (statusCode === com.google.android.gms.location.LocationSettingsStatusCodes.SETTINGS_CHANGE_UNAVAILABLE
                            && isAirplaneModeOn()
                            && isProviderEnabled(android.location.LocationManager.GPS_PROVIDER)) {
                            return resolve();
                        }
                    }
                    reject(new Error("Cannot enable the location service. " + ex));
                });
            }, reject);
        }, reject);
    });
}
exports.enableLocationRequest = enableLocationRequest;
function _makeGooglePlayServicesAvailable() {
    return new Promise(function (resolve, reject) {
        if (_isGooglePlayServicesAvailable()) {
            resolve();
            return;
        }
        var googleApiAvailability = com.google.android.gms.common.GoogleApiAvailability.getInstance();
        googleApiAvailability.makeGooglePlayServicesAvailable(application_1.android.foregroundActivity)
            .addOnSuccessListener(_getTaskSuccessListener(resolve))
            .addOnFailureListener(_getTaskFailListener(reject));
    });
}
function _isGooglePlayServicesAvailable() {
    if (LocationManager.shouldSkipChecks()) {
        return true;
    }
    var isLocationServiceEnabled = true;
    var googleApiAvailability = com.google.android.gms.common.GoogleApiAvailability.getInstance();
    var resultCode = googleApiAvailability.isGooglePlayServicesAvailable(application_1.android.context);
    if (resultCode !== com.google.android.gms.common.ConnectionResult.SUCCESS) {
        isLocationServiceEnabled = false;
    }
    return isLocationServiceEnabled;
}
function _isLocationServiceEnabled(options) {
    return new Promise(function (resolve, reject) {
        if (LocationManager.shouldSkipChecks()) {
            resolve(true);
            return;
        }
        options = options || { desiredAccuracy: enums_1.Accuracy.high, updateTime: 0, updateDistance: 0, maximumAge: 0, timeout: 0 };
        var locationRequest = _getLocationRequest(options);
        var locationSettingsBuilder = new com.google.android.gms.location.LocationSettingsRequest.Builder();
        locationSettingsBuilder.addLocationRequest(locationRequest);
        locationSettingsBuilder.setAlwaysShow(true);
        var locationSettingsClient = com.google.android.gms.location.LocationServices.getSettingsClient(application_1.android.context);
        locationSettingsClient.checkLocationSettings(locationSettingsBuilder.build())
            .addOnSuccessListener(_getTaskSuccessListener(resolve))
            .addOnFailureListener(_getTaskFailListener(reject));
    });
}
function isEnabled(options) {
    return new Promise(function (resolve, reject) {
        if (!_isGooglePlayServicesAvailable() ||
            !permissions.hasPermission(android.Manifest.permission.ACCESS_FINE_LOCATION)) {
            resolve(false);
        }
        else {
            _isLocationServiceEnabled(options).then(function () {
                resolve(true);
            }, function (ex) {
                if (typeof ex.getStatusCode === "function"
                    && ex.getStatusCode() === com.google.android.gms.location.LocationSettingsStatusCodes.SETTINGS_CHANGE_UNAVAILABLE
                    && isAirplaneModeOn()
                    && isProviderEnabled(android.location.LocationManager.GPS_PROVIDER)) {
                    return resolve(true);
                }
                resolve(false);
            });
        }
    });
}
exports.isEnabled = isEnabled;
function distance(loc1, loc2) {
    if (!loc1.android) {
        loc1.android = androidLocationFromLocation(loc1);
    }
    if (!loc2.android) {
        loc2.android = androidLocationFromLocation(loc2);
    }
    return loc1.android.distanceTo(loc2.android);
}
exports.distance = distance;
function androidLocationFromLocation(location) {
    var androidLocation = new android.location.Location("custom");
    androidLocation.setLatitude(location.latitude);
    androidLocation.setLongitude(location.longitude);
    if (location.altitude) {
        androidLocation.setAltitude(location.altitude);
    }
    if (location.speed) {
        androidLocation.setSpeed(float(location.speed));
    }
    if (location.direction) {
        androidLocation.setBearing(float(location.direction));
    }
    if (location.timestamp) {
        try {
            androidLocation.setTime(long(location.timestamp.getTime()));
        }
        catch (e) {
            console.error("invalid location timestamp");
        }
    }
    return androidLocation;
}
var LocationManager = (function () {
    function LocationManager() {
    }
    LocationManager.getLastLocation = function (maximumAge, resolve, reject) {
        _ensureLocationClient();
        return fusedLocationClient.getLastLocation()
            .addOnSuccessListener(_getLocationListener(maximumAge, resolve, reject))
            .addOnFailureListener(_getTaskFailListener(function (e) { return reject(new Error(e.getMessage())); }));
    };
    LocationManager.requestLocationUpdates = function (locationRequest, locationCallback) {
        _ensureLocationClient();
        fusedLocationClient.requestLocationUpdates(locationRequest, locationCallback, null);
    };
    LocationManager.removeLocationUpdates = function (listener) {
        _ensureLocationClient();
        fusedLocationClient.removeLocationUpdates(listener);
    };
    LocationManager.shouldSkipChecks = function () {
        return false;
    };
    LocationManager.setMockLocationManager = function (MockLocationManager) {
        LocationManager.getLastLocation = MockLocationManager.getLastLocation;
        LocationManager.requestLocationUpdates = MockLocationManager.requestLocationUpdates;
        LocationManager.removeLocationUpdates = MockLocationManager.removeLocationUpdates;
        LocationManager.shouldSkipChecks = MockLocationManager.shouldSkipChecks;
    };
    return LocationManager;
}());
exports.LocationManager = LocationManager;
var Location = (function (_super) {
    __extends(Location, _super);
    function Location(androidLocation) {
        var _this = _super.call(this) || this;
        if (androidLocation) {
            _this.android = androidLocation;
            _this.latitude = androidLocation.getLatitude();
            _this.longitude = androidLocation.getLongitude();
            _this.altitude = androidLocation.getAltitude();
            _this.horizontalAccuracy = androidLocation.getAccuracy();
            _this.verticalAccuracy = androidLocation.getAccuracy();
            _this.speed = androidLocation.getSpeed();
            _this.direction = androidLocation.getBearing();
            _this.timestamp = new Date(androidLocation.getTime());
        }
        return _this;
    }
    return Location;
}(geolocation_common_1.LocationBase));
exports.Location = Location;
function setCustomLocationManager(MockLocationManager) {
    LocationManager.setMockLocationManager(MockLocationManager);
}
exports.setCustomLocationManager = setCustomLocationManager;
