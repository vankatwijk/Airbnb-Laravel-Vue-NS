import { ElementRef, TemplateRef, EmbeddedViewRef, ViewContainerRef, OnInit, EventEmitter } from '@angular/core';
import { RadAutoCompleteTextView, SuggestionView, CollectionViewEventData } from './../';
import { View } from 'tns-core-modules/ui/core/view';
export declare class ListItemContext extends ElementRef {
    $implicit?: any;
    item?: any;
    index?: number;
    even?: boolean;
    odd?: boolean;
    constructor($implicit?: any, item?: any, index?: number, even?: boolean, odd?: boolean);
}
export interface ItemEventArgs {
    object?: any;
    view: EmbeddedViewRef<any>;
    data: any;
    index: number;
    returnValue?: boolean;
    context: any;
}
export declare type RootLocator = (nodes: Array<any>, nestLevel: number) => View;
export declare class RadAutoCompleteTextViewComponent {
    private _elementRef;
    private loader;
    private _autoCompleteTextView;
    private _itemTemplate;
    setupItemView: EventEmitter<ItemEventArgs>;
    constructor(_elementRef: ElementRef, loader: ViewContainerRef);
    readonly nativeElement: RadAutoCompleteTextView;
    readonly autoCompleteTextView: RadAutoCompleteTextView;
    itemTemplate: TemplateRef<ElementRef>;
    onItemLoading(args: CollectionViewEventData): void;
    setupViewRef(viewRef: EmbeddedViewRef<any>, data: any, index: number): void;
    private detectChangesOnChild;
}
export declare class TKAutoCompleteSuggestionViewDirective implements OnInit {
    private owner;
    private _elementRef;
    private _suggestionView;
    constructor(owner: RadAutoCompleteTextViewComponent, _elementRef: ElementRef);
    ngOnInit(): void;
    readonly nativeElement: SuggestionView;
    readonly autoCompleteTextView: SuggestionView;
}
export declare class TKSuggestionItemTemplateDirective {
    private owner;
    private template;
    constructor(owner: RadAutoCompleteTextViewComponent, template: TemplateRef<any>);
    ngOnInit(): void;
}
export declare const AUTOCOMPLETETEXTVIEW_DIRECTIVES: (typeof RadAutoCompleteTextViewComponent | typeof TKAutoCompleteSuggestionViewDirective | typeof TKSuggestionItemTemplateDirective)[];
export declare class NativeScriptUIAutoCompleteTextViewModule {
}
