import { ElementRef, OnInit } from '@angular/core';
import { RadDataForm, EntityProperty, PropertyEditor, PropertyGroup, DataFormGridLayout, DataFormStackLayout, CustomPropertyEditor, PropertyEditorParams } from './../';
export declare class RadDataFormComponent {
    private _elementRef;
    private _dataForm;
    readonly nativeElement: RadDataForm;
    constructor(_elementRef: ElementRef);
    readonly dataForm: RadDataForm;
}
export declare class TKEntityPropertyDirective {
    private _elementRef;
    protected _entityProperty: EntityProperty;
    constructor(_elementRef: ElementRef);
    readonly entityProperty: EntityProperty;
}
export declare class TKDataFormGridLayoutDirective {
    private _elementRef;
    protected _dataFormGridLayout: DataFormGridLayout;
    constructor(_elementRef: ElementRef);
    readonly dataFormGridLayout: DataFormGridLayout;
}
export declare class TKDataFormStackLayoutDirective {
    private _elementRef;
    protected _dataFormStackLayout: DataFormStackLayout;
    constructor(_elementRef: ElementRef);
    readonly dataFormStackLayout: DataFormStackLayout;
}
export declare class TKPropertyGroupDirective {
    private _elementRef;
    protected _propertyGroup: PropertyGroup;
    constructor(_elementRef: ElementRef);
    readonly propertyGroup: PropertyGroup;
}
export declare class TKPropertyEditorDirective {
    private _elementRef;
    protected _propertyEditor: PropertyEditor;
    constructor(_elementRef: ElementRef);
    readonly propertyEditor: PropertyEditor;
}
export declare class TKCustomPropertyEditorDirective {
    private _elementRef;
    protected _propertyEditor: CustomPropertyEditor;
    constructor(_elementRef: ElementRef);
    readonly propertyEditor: CustomPropertyEditor;
}
export declare class TKPropertyEditorParamsDirective {
    private _elementRef;
    protected _propertyEditorParams: PropertyEditorParams;
    constructor(_elementRef: ElementRef);
    readonly propertyEditorParams: PropertyEditorParams;
}
export declare class TKEditorParamsDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: TKPropertyEditorDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKDataFormPropertyDirective {
    private owner;
    private _elementRef;
    constructor(owner: RadDataFormComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKPropertyGroupLayoutDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: TKPropertyGroupDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKDataFormGroupsDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadDataFormComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKPropertyGroupTitleStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: TKPropertyGroupDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKPropertyEditorStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: TKPropertyEditorDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKCustomPropertyEditorStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: TKCustomPropertyEditorDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKPropertyGroupPropertiesDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: TKPropertyGroupDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKEntityPropertyEditorDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: TKEntityPropertyDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKEntityPropertyValidatorsDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: TKEntityPropertyDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare const DATAFORM_DIRECTIVES: (typeof RadDataFormComponent | typeof TKEntityPropertyDirective | typeof TKDataFormGridLayoutDirective | typeof TKDataFormStackLayoutDirective | typeof TKPropertyGroupDirective | typeof TKPropertyEditorDirective | typeof TKCustomPropertyEditorDirective | typeof TKPropertyEditorParamsDirective | typeof TKEditorParamsDirective | typeof TKDataFormPropertyDirective | typeof TKPropertyGroupLayoutDirective | typeof TKDataFormGroupsDirective | typeof TKPropertyGroupTitleStyleDirective | typeof TKPropertyEditorStyleDirective | typeof TKCustomPropertyEditorStyleDirective | typeof TKPropertyGroupPropertiesDirective | typeof TKEntityPropertyEditorDirective | typeof TKEntityPropertyValidatorsDirective)[];
export declare class NativeScriptUIDataFormModule {
}
