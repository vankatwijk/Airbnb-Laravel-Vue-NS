Object.defineProperty(exports, "__esModule", { value: true });
var trackBallModule = require("./chart-track-ball.common");
var chart_public_enum_1 = require("../../misc/chart-public-enum");
var Trackball = /** @class */ (function (_super) {
    __extends(Trackball, _super);
    function Trackball() {
        return _super.call(this) || this;
    }
    Object.defineProperty(Trackball.prototype, "ios", {
        // private _ios: TKChartTrackball;
        get: function () {
            return this._ios;
        },
        set: function (value) {
            this._ios = value;
            this.updateNativeSnapMode(this.snapMode);
            this.updateShowIntersectionPoints(this.showIntersectionPoints);
        },
        enumerable: true,
        configurable: true
    });
    Trackball.prototype.onSnapModeChanged = function (oldValue, newValue) {
        if (!this._ios) {
            return;
        }
        if (newValue) {
            this.updateNativeSnapMode(newValue);
        }
    };
    Trackball.prototype.onShowIntersectionPointsChanged = function (oldValue, newValue) {
        if (!this._ios) {
            return;
        }
        if (newValue) {
            this.updateShowIntersectionPoints(newValue);
        }
    };
    Trackball.prototype.updateShowIntersectionPoints = function (value) {
        if (value) {
            this.ios.line.style.pointShape.size = CGSizeMake(4, 4);
        }
        else {
            this.ios.line.style.pointShape.size = CGSizeZero;
        }
    };
    Trackball.prototype.updateNativeSnapMode = function (snapMode) {
        if (snapMode === chart_public_enum_1.ChartTrackballSnapMode.ClosestPoint) {
            this.ios.snapMode = 0 /* ClosestPoint */;
        }
        else if (snapMode === chart_public_enum_1.ChartTrackballSnapMode.AllClosestPoints) {
            this.ios.snapMode = 1 /* AllClosestPoints */;
        }
    };
    return Trackball;
}(trackBallModule.Trackball));
exports.Trackball = Trackball;
