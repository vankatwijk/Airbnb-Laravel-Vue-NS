"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var image_1 = require("../image");
var ImagePlugin = {
    install: function (Vue) {
        Vue.registerElement('NSImg', function () { return image_1.Img; });
    }
};
exports.default = ImagePlugin;
//# sourceMappingURL=index.js.map