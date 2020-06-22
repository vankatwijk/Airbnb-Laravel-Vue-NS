Object.defineProperty(exports, "__esModule", { value: true });
var trackBallModule = require("./chart-track-ball.common");
var chart_public_enum_1 = require("../../misc/chart-public-enum");
var Trackball = /** @class */ (function (_super) {
    __extends(Trackball, _super);
    function Trackball() {
        return _super.call(this) || this;
    }
    Object.defineProperty(Trackball.prototype, "android", {
        // private _android: com.telerik.widget.chart.visualization.behaviors.ChartTrackBallBehavior;
        get: function () {
            return this._android;
        },
        set: function (value) {
            if (this._android) {
                this.unwireContentProviderCallback();
            }
            this._android = value;
            this.wireContentProviderCallback();
            this.updateTrackballSnapMode(this.snapMode);
            this.updateShowIntrsectionPoints(this.showIntersectionPoints);
        },
        enumerable: true,
        configurable: true
    });
    Trackball.prototype.unwireContentProviderCallback = function () {
        this._customProviderImpl = undefined;
        this.android.setCustomContentProvider(null);
    };
    Trackball.prototype.wireContentProviderCallback = function () {
        var that = new WeakRef(this);
        this._customProviderImpl = new com.telerik.widget.chart.visualization.behaviors.ChartTrackballContentAdapter.ChartTrackBallContentProvider({
            resolveContentForDataPoint: function (point) {
                debugger;
                var chartSeries = that.get()._owner.series.getItem ? that.get()._owner.series.getItem(point.parent.index()) : that.get()._owner.series[point.parent.index()];
                var eventData = {
                    eventName: Trackball.trackBallContentRequestedEvent,
                    pointIndex: point.index(),
                    seriesIndex: point.parent.index(),
                    series: chartSeries,
                    pointData: chartSeries.getItemAtIndex(point.index()),
                    object: that.get(),
                    content: undefined
                };
                that.get().notify(eventData);
                if (eventData.content) {
                    return eventData.content;
                }
                return null;
            },
            resolveCustomViewForDataPoint: function (point) {
                return undefined;
            }
        });
        this.android.setCustomContentProvider(this._customProviderImpl);
    };
    Trackball.prototype.onSnapModeChanged = function (oldValue, newValue) {
        if (!this._android) {
            return;
        }
        this.updateTrackballSnapMode(newValue);
    };
    Trackball.prototype.onShowIntersectionPointsChanged = function (oldValue, newValue) {
        if (!this._android) {
            return;
        }
        this.updateShowIntrsectionPoints(newValue);
    };
    Trackball.prototype.updateShowIntrsectionPoints = function (value) {
        this._android.setShowIntersectionPoints(value);
    };
    Trackball.prototype.updateTrackballSnapMode = function (snapMode) {
        if (snapMode === chart_public_enum_1.ChartTrackballSnapMode.ClosestPoint) {
            this.android.setSnapMode(com.telerik.widget.chart.visualization.behaviors.TrackBallSnapMode.CLOSEST_POINT);
        }
        else if (snapMode === chart_public_enum_1.ChartTrackballSnapMode.AllClosestPoints) {
            this.android.setSnapMode(com.telerik.widget.chart.visualization.behaviors.TrackBallSnapMode.ALL_CLOSE_POINTS);
        }
    };
    return Trackball;
}(trackBallModule.Trackball));
exports.Trackball = Trackball;
