import { DoCheck, ElementRef, IterableDiffers } from "@angular/core";
import { RadCalendar } from "./../";
export declare class RadCalendarComponent implements DoCheck {
    private _elementRef;
    private _iterableDiffers;
    private _calendar;
    private _eventSource;
    private _differ;
    private timerId;
    private doCheckDelay;
    constructor(_elementRef: ElementRef, _iterableDiffers: IterableDiffers);
    eventSource: any;
    readonly nativeElement: RadCalendar;
    readonly calendar: RadCalendar;
    ngDoCheck(): void;
}
export declare const CALENDAR_DIRECTIVES: (typeof RadCalendarComponent)[];
export declare class NativeScriptUICalendarModule {
}
