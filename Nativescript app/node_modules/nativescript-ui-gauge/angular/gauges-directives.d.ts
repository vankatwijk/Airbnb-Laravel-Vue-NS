import { ElementRef, OnInit } from '@angular/core';
import { RadRadialGauge, RadialScale, RadialBarIndicator, RadialNeedle } from './../';
export declare class RadRadialGaugeComponent {
    private _elementRef;
    private _radialGauge;
    constructor(_elementRef: ElementRef);
    readonly nativeElement: RadRadialGauge;
    readonly radialGauge: RadRadialGauge;
}
export declare class TKRadialScaleDirective {
    private _elementRef;
    private _radialScale;
    constructor(_elementRef: ElementRef);
    readonly radialScale: RadialScale;
}
export declare class TKRadialBarIndicatorDirective {
    private _elementRef;
    private _barIndicator;
    constructor(_elementRef: ElementRef);
    readonly radialScale: RadialBarIndicator;
}
export declare class TKRadialNeedleDirective {
    private _elementRef;
    private _radialNeedle;
    constructor(_elementRef: ElementRef);
    readonly radialNeedle: RadialNeedle;
}
export declare class TKRadialGaugeScalesDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadRadialGaugeComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKRadialScaleStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: TKRadialScaleDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKRadialScaleIndicatorsDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: TKRadialScaleDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKRadialBarIndicatorStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: TKRadialBarIndicatorDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKRadialGaugeTitleStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadRadialGaugeComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKRadialGaugeSubtitleStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadRadialGaugeComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKRadialNeedleStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: TKRadialNeedleDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare const GAUGES_DIRECTIVES: (typeof RadRadialGaugeComponent | typeof TKRadialScaleDirective | typeof TKRadialBarIndicatorDirective | typeof TKRadialNeedleDirective | typeof TKRadialGaugeScalesDirective | typeof TKRadialScaleStyleDirective | typeof TKRadialScaleIndicatorsDirective | typeof TKRadialBarIndicatorStyleDirective | typeof TKRadialGaugeTitleStyleDirective | typeof TKRadialGaugeSubtitleStyleDirective | typeof TKRadialNeedleStyleDirective)[];
export declare class NativeScriptUIGaugeModule {
}
