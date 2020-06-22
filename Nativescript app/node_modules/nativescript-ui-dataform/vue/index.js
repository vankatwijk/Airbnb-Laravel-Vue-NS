Object.defineProperty(exports, "__esModule", { value: true });
var __1 = require("./..");
var component_1 = require("./component");
var RadDataFormPlugin = {
    install: function (Vue, options) {
        Vue.registerElement('RadDataForm', function () { return __1.RadDataForm; }, {
            component: component_1.default,
        });
        Vue.registerElement('TKDataFormStackLayout', function () { return __1.DataFormStackLayout; });
        Vue.registerElement('TKDataFormGridLayout', function () { return __1.DataFormGridLayout; });
        Vue.registerElement('TKEntityProperty', function () { return __1.EntityProperty; });
        Vue.registerElement('TKPropertyEditor', function () { return __1.PropertyEditor; });
        Vue.registerElement('TKPropertyEditorParams', function () { return __1.PropertyEditorParams; });
        Vue.registerElement('TKPropertyEditorStyle', function () { return __1.PropertyEditorStyle; });
        Vue.registerElement('TKPropertyGroup', function () { return __1.PropertyGroup; });
        Vue.registerElement('TKEmailValidator', function () { return __1.EmailValidator; });
        Vue.registerElement('TKIsTrueValidator', function () { return __1.IsTrueValidator; });
        Vue.registerElement('TKNonEmptyValidator', function () { return __1.NonEmptyValidator; });
        Vue.registerElement('TKMaximumLengthValidator', function () { return __1.MaximumLengthValidator; });
        Vue.registerElement('TKMinimumLengthValidator', function () { return __1.MinimumLengthValidator; });
        Vue.registerElement('TKPhoneValidator', function () { return __1.PhoneValidator; });
        Vue.registerElement('TKRangeValidator', function () { return __1.RangeValidator; });
        Vue.registerElement('TKRegExValidator', function () { return __1.RegExValidator; });
        var setDataFormProperty = {
            inserted: function (el) {
                var dataForm = el.parentNode.nativeView;
                var property = el.nativeView;
                if (dataForm.properties) {
                    dataForm.properties.push(property);
                }
                else {
                    dataForm.properties = new Array(property);
                }
            }
        };
        Vue.directive('tkDataFormProperty', setDataFormProperty);
        var setEntityPropertyEditor = {
            inserted: function (el) {
                var entityProperty = el.parentNode.nativeView;
                var editor = el.nativeView;
                entityProperty.editor = editor;
            }
        };
        Vue.directive('tkEntityPropertyEditor', setEntityPropertyEditor);
        var setEditorParams = {
            inserted: function (el) {
                var propertyEditor = el.parentNode.nativeView;
                var editorParams = el.nativeView;
                propertyEditor.params = editorParams;
            }
        };
        Vue.directive('tkEditorParams', setEditorParams);
        var setPropertyEditorStyle = {
            inserted: function (el) {
                var propertyEditor = el.parentNode.nativeView;
                var style = el.nativeView;
                propertyEditor.propertyEditorStyle = style;
            }
        };
        Vue.directive('tkPropertyEditorStyle', setPropertyEditorStyle);
        var setFormGroups = {
            inserted: function (el) {
                var dataForm = el.parentNode.nativeView;
                var property = el.nativeView;
                if (dataForm.groups) {
                    dataForm.groups.push(property);
                }
                else {
                    dataForm.groups = new Array(property);
                }
            }
        };
        Vue.directive('tkDataFormGroups', setFormGroups);
        var setPropertyGroupProperties = {
            inserted: function (el) {
                var propertyGroup = el.parentNode.nativeView;
                var property = el.nativeView;
                if (propertyGroup.properties) {
                    propertyGroup.properties.push(property);
                }
                else {
                    propertyGroup.properties = new Array(property);
                }
            }
        };
        Vue.directive('tkPropertyGroupProperties', setPropertyGroupProperties);
        var setPropertyValidators = {
            inserted: function (el) {
                var entityProperty = el.parentNode.nativeView;
                var validator = el.nativeView;
                if (entityProperty.validators) {
                    entityProperty.validators.push(validator);
                }
                else {
                    entityProperty.validators = new Array(validator);
                }
            }
        };
        Vue.directive('tkEntityPropertyValidators', setPropertyValidators);
        var setPropertyGroupLayout = {
            inserted: function (el) {
                var propertyGroup = el.parentNode.nativeView;
                var layout = el.nativeView;
                propertyGroup.layout = layout;
            }
        };
        Vue.directive('tkPropertyGroupLayout', setPropertyGroupLayout);
    }
};
exports.default = RadDataFormPlugin;
