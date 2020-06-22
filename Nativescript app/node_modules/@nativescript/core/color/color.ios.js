Object.defineProperty(exports, "__esModule", { value: true });
var common = require("./color-common");
var Color = (function (_super) {
    __extends(Color, _super);
    function Color() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    Object.defineProperty(Color.prototype, "ios", {
        get: function () {
            if (!this._ios) {
                this._ios = UIColor.alloc().initWithRedGreenBlueAlpha(this.r / 255, this.g / 255, this.b / 255, this.a / 255);
            }
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    Color.fromIosColor = function (value) {
        var rgba = CGColorGetComponents(value.CGColor);
        return new Color(Math.round(rgba[3] * 255), Math.round(rgba[0] * 255), Math.round(rgba[1] * 255), Math.round(rgba[2] * 255));
    };
    return Color;
}(common.Color));
exports.Color = Color;
//# sourceMappingURL=color.ios.js.map