import { ElementRef, TemplateRef, EmbeddedViewRef, ViewContainerRef, EventEmitter } from "@angular/core";
import { RadSideDrawer } from "./..";
import { View } from "tns-core-modules/ui/core/view";
import { Page } from "tns-core-modules/ui/page";
import * as sideDrawerModule from './..';
/**
 * [Deprecated: Please use the 'RadSideDrawer' from 'nativescript-telerik-ui/sidedrawer'].
 */
export declare type SideDrawerType = RadSideDrawer & View & {
    toggleDrawerState: () => void;
};
export interface ItemEventArgs {
    object: any;
    view: EmbeddedViewRef<any>;
    returnValue?: boolean;
}
/**
* This is the SideDrawer component. It separates your mobile app's screen
* into a main part and a menu part whereby the menu part is shown upon a swipe
* gesture using a transition effect.
*/
export declare class RadSideDrawerComponent {
    elementRef: ElementRef;
    private page;
    private viewContainer;
    sideDrawer: RadSideDrawer;
    mainTemplate: TemplateRef<ElementRef>;
    drawerTemplate: TemplateRef<ElementRef>;
    private _drawerContentSize;
    private _gesturesEnabled;
    private _drawerTransition;
    private _drawerLocation;
    private sideDrawerMovedToPage;
    drawerOpening: EventEmitter<any>;
    drawerOpen: EventEmitter<any>;
    drawerClosing: EventEmitter<any>;
    drawerClosed: EventEmitter<any>;
    /**
      * [Deprecated: Please use the 'drawerTransition' property instead].
      */
    transition: sideDrawerModule.DrawerTransitionBase;
    constructor(elementRef: ElementRef, page: Page, viewContainer: ViewContainerRef);
    readonly nativeElement: RadSideDrawer;
    /**
      * Defines either the width or the height
      * of the menu pane depending on the location of the SideDrawer.
      * Top or Bottom - height, Right or Left - width.
      */
    drawerContentSize: number;
    gesturesEnabled: boolean;
    drawerTransition: string;
    drawerLocation: string;
    private updateDrawerLocation;
    private updateDrawerTransition;
    private updateGesturesEnabled;
    private updateContentSize;
}
/**
 * Directive identifying the drawer content.
 */
export declare class TKDrawerContentDirective {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
/**
 * Directive identifying the main content.
 */
export declare class TKMainContentDirective {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
/**
 * Directives identifying the RadSideDrawer.
 */
export declare const SIDEDRAWER_DIRECTIVES: (typeof RadSideDrawerComponent | typeof TKDrawerContentDirective | typeof TKMainContentDirective)[];
/**
 * NgModule containing all of the RadSideDrawer directives.
 */
export declare class NativeScriptUISideDrawerModule {
}
