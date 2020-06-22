"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = exports.Theme = exports.ClassList = void 0;

var appCommon = _interopRequireWildcard(require("tns-core-modules/application/application-common"));

var app = _interopRequireWildcard(require("tns-core-modules/application"));

var _systemClasses = require("tns-core-modules/css/system-classes");

var _platform = require("tns-core-modules/platform");

var view = _interopRequireWildcard(require("tns-core-modules/ui/core/view"));

var frame = _interopRequireWildcard(require("tns-core-modules/ui/frame"));

function _getRequireWildcardCache() { if (typeof WeakMap !== "function") return null; var cache = new WeakMap(); _getRequireWildcardCache = function () { return cache; }; return cache; }

function _interopRequireWildcard(obj) { if (obj && obj.__esModule) { return obj; } if (obj === null || typeof obj !== "object" && typeof obj !== "function") { return { default: obj }; } var cache = _getRequireWildcardCache(); if (cache && cache.has(obj)) { return cache.get(obj); } var newObj = {}; var hasPropertyDescriptor = Object.defineProperty && Object.getOwnPropertyDescriptor; for (var key in obj) { if (Object.prototype.hasOwnProperty.call(obj, key)) { var desc = hasPropertyDescriptor ? Object.getOwnPropertyDescriptor(obj, key) : null; if (desc && (desc.get || desc.set)) { Object.defineProperty(newObj, key, desc); } else { newObj[key] = obj[key]; } } } newObj.default = obj; if (cache) { cache.set(obj, newObj); } return newObj; }

const display = _platform.screen.mainScreen;
const whiteSpaceRegExp = /\s+/;
const platformClass = `ns-${_platform.isAndroid ? "android" : "ios"}`;

const sdkVersionClass = _platform.device.sdkVersion.replace(".", "-");

let started = false;

class ClassList {
  constructor(className) {
    this.list = new Set();
    (className || "").split(whiteSpaceRegExp).forEach(v => v && this.list.add(v));
  }

  add(...classes) {
    classes.forEach(v => this.list.add(v));
    return this;
  }

  remove(...classes) {
    classes.forEach(v => this.list.delete(v));
    return this;
  }

  get() {
    return Array.from(this.list).join(" ");
  }

}

exports.ClassList = ClassList;

class Theme {
  static setMode(mode, root = app.getRootView()) {
    Theme.currentMode = mode;
    Theme.rootView = root;

    if (!root || !mode) {
      return;
    }

    const classList = new ClassList(Theme.rootView.className);
    classList.remove(Theme.Light, Theme.Dark);

    if (Theme.currentMode !== Theme.Auto) {
      (0, _systemClasses.removeFromRootViewCssClasses)(Theme.Light);
      (0, _systemClasses.removeFromRootViewCssClasses)(Theme.Dark);
      classList.add(Theme.currentMode);
    }

    Theme.rootView.className = classList.get();
  }

  static toggleMode(isDark) {
    if (isDark === undefined) {
      const mode = Theme.currentMode === Theme.Auto && app.systemAppearance ? `ns-${app.systemAppearance()}` : Theme.getMode();
      Theme.setMode(mode === Theme.Light ? Theme.Dark : Theme.Light);
      return;
    }

    Theme.setMode(isDark ? Theme.Dark : Theme.Light);
  }

  static getMode() {
    const root = app.getRootView();
    return Theme.currentMode || ((root && root.className || "").indexOf(Theme.Dark) !== -1 ? Theme.Dark : Theme.Light);
  }

}

exports.Theme = Theme;
Theme.Light = "ns-light";
Theme.Dark = "ns-dark";
Theme.Auto = "auto";
var _default = Theme; // Where the magic happens

exports.default = _default;
const oldSetupAsRootView = view.ViewCommon.prototype._setupAsRootView;

view.ViewCommon.prototype._setupAsRootView = function () {
  oldSetupAsRootView.call(this, ...arguments);
  Theme.setMode(Theme.currentMode, this);
}; // Disable SystemAppearance changes if Theme.currentMode is not auto


const oldSystemAppearanceChanged = appCommon.systemAppearanceChanged;

if (oldSystemAppearanceChanged) {
  appCommon.systemAppearanceChanged = function () {
    if (Theme.currentMode === Theme.Auto) {
      oldSystemAppearanceChanged.call(this, ...arguments);
    }
  };
}
/* Deprecated root class setters, now available in core modules */


function updateRootClasses(orientation, root = app.getRootView(), classes = []) {
  const classList = new ClassList(root.className);
  classList.remove("ns-portrait", "ns-landscape", "ns-unknown", ...classes).add(`ns-${orientation}`, ...classes);
  root.className = classList.get();
}

function handleOrientation({
  newValue: orientation
}) {
  updateRootClasses(orientation);

  if (view._rootModalViews.length) {
    const classList = new ClassList(app.getRootView().className);

    view._rootModalViews.forEach(view => updateRootClasses(orientation, view, classList.add("ns-modal").list));
  }
}

function getOrientation() {
  return display.heightDIPs > display.widthDIPs ? "portrait" : "landscape";
}

const rootModalTrap = {
  defineProperty(target, key, desc) {
    if (desc && "value" in desc) {
      target[key] = desc.value;

      if (desc.value instanceof frame.Frame) {
        const classList = new ClassList(app.getRootView().className);
        updateRootClasses(getOrientation(), desc.value, classList.add("ns-modal").list);
      }
    }

    return target;
  }

};
app.on(app.displayedEvent, () => {
  const root = app.getRootView(); // Bail out if no root view or root classes already set (pre 6.1).

  if (!root || root.cssClasses.has("ns-root")) {
    // Add ns-{platform}-{sdkVersion} classes
    if (root) {
      root.className = new ClassList(root.className).add(`${platformClass}__${sdkVersionClass}`).get();
    }

    return;
  } // Get notified when a modal is created.


  view._rootModalViews = new Proxy(view._rootModalViews, rootModalTrap);
  root.className = new ClassList(root.className).add("ns-root", platformClass, `ns-${_platform.device.deviceType.toLowerCase()}`).get();

  if (!started) {
    handleOrientation({
      newValue: getOrientation()
    });
    app.on(app.orientationChangedEvent, handleOrientation);
    started = true;
  }
});