import { DoCheck, ElementRef, TemplateRef, EmbeddedViewRef, IterableDiffers, ViewContainerRef, OnInit, EventEmitter, AfterContentInit } from '@angular/core';
import { NativeScriptRendererFactory } from "nativescript-angular/renderer";
import { RadListView, ListViewLayoutBase, ListViewEventData } from './../';
import { View } from 'tns-core-modules/ui/core/view';
export declare class ListItemContext extends ElementRef {
    $implicit?: any;
    item?: any;
    index?: number;
    even?: boolean;
    odd?: boolean;
    category?: string;
    constructor($implicit?: any, item?: any, index?: number, even?: boolean, odd?: boolean, category?: string);
}
export declare type RootLocator = (nodes: Array<any>, nestLevel: number) => View;
export declare class RadListViewComponent implements AfterContentInit, DoCheck {
    private _elementRef;
    private _iterableDiffers;
    private _renderer;
    private _listView;
    private _items;
    private _differ;
    private _headerTemplate;
    private _footerTemplate;
    private _itemTemplate;
    private _groupTemplate;
    private _itemSwipeTemplate;
    private _loadOnDemandTemplate;
    private _templateMap;
    loader: ViewContainerRef;
    setupItemView: EventEmitter<any>;
    constructor(_elementRef: ElementRef, _iterableDiffers: IterableDiffers, _renderer: NativeScriptRendererFactory);
    ngAfterContentInit(): void;
    itemTemplateQuery: TemplateRef<ListItemContext>;
    readonly nativeElement: RadListView;
    readonly listView: RadListView;
    loadOnDemandTemplate: TemplateRef<any>;
    headerTemplate: TemplateRef<ElementRef>;
    groupTemplate: TemplateRef<ElementRef>;
    footerTemplate: TemplateRef<ElementRef>;
    itemTemplate: TemplateRef<ElementRef>;
    itemSwipeTemplate: TemplateRef<ElementRef>;
    items: any;
    ngDoCheck(): void;
    onItemLoadingInternal(args: ListViewEventData): void;
    setupViewRef(viewRef: EmbeddedViewRef<any>, data: any, index: number): void;
    setLayout(layout: ListViewLayoutBase): void;
    private detectChangesOnChild;
    private setItemTemplates;
    registerTemplate(key: string, template: TemplateRef<ListItemContext>): void;
}
export declare class ListViewLinearLayoutDirective {
    constructor();
}
export declare class ListViewGridLayoutDirective {
    constructor();
}
export declare class ListViewStaggeredLayoutDirective {
    constructor();
}
export declare class ReorderHandleDirective {
    constructor();
}
export declare class TKListViewHeaderDirective implements OnInit {
    private owner;
    private template;
    constructor(owner: RadListViewComponent, template: TemplateRef<any>);
    ngOnInit(): void;
}
export declare class TKListViewFooterDirective implements OnInit {
    private owner;
    private template;
    constructor(owner: RadListViewComponent, template: TemplateRef<any>);
    ngOnInit(): void;
}
export declare class TKListViewItemSwipeDirective implements OnInit {
    private owner;
    private template;
    constructor(owner: RadListViewComponent, template: TemplateRef<any>);
    ngOnInit(): void;
}
export declare class TKListViewItemDirective implements OnInit {
    private owner;
    private template;
    constructor(owner: RadListViewComponent, template: TemplateRef<any>);
    ngOnInit(): void;
}
export declare class TKGroupTemplateDirective implements OnInit {
    private owner;
    private template;
    constructor(owner: RadListViewComponent, template: TemplateRef<any>);
    ngOnInit(): void;
}
export declare class TKTemplateKeyDirective {
    private templateRef;
    private owner;
    constructor(templateRef: TemplateRef<any>, owner: RadListViewComponent);
    tkTemplateKey: any;
}
export declare class TKListViewLoadOnDemandDirective implements OnInit {
    private owner;
    private template;
    constructor(owner: RadListViewComponent, template: TemplateRef<any>);
    ngOnInit(): void;
}
export declare class TKListViewLayoutDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadListViewComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare function getItemViewRoot(viewRef: EmbeddedViewRef<any>, rootLocator?: RootLocator): View;
export declare const LISTVIEW_DIRECTIVES: (typeof RadListViewComponent | typeof ListViewLinearLayoutDirective | typeof TKListViewHeaderDirective | typeof TKListViewFooterDirective | typeof TKListViewItemSwipeDirective | typeof TKListViewItemDirective | typeof TKGroupTemplateDirective | typeof TKTemplateKeyDirective | typeof TKListViewLoadOnDemandDirective | typeof TKListViewLayoutDirective)[];
export declare class NativeScriptUIListViewModule {
}
