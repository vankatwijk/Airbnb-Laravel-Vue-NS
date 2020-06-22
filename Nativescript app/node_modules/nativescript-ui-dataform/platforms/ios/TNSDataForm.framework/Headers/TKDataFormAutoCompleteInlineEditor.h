//
//  TKDataFormAutoComplateInlineEditor.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TNSAutoComplete/TKAutoCompleteController.h"
#import "TKDataFormEditor.h"

@class TKDataSourceExtended;
@class TKDataFormAutocompleteEditor;

/**
 The default controller holding inline autocomplete control.
 */
@interface TKDataFormAutoCompleteInlineEditor : TKDataFormEditor

/**
 An instance of TKAutoCompleteTextView.
 */
@property (nonatomic, nonnull) TKAutoCompleteTextView *autoCompleteView;

/**
 The data source associated with the autocomplete text view.
 */
@property (nonatomic, strong, nonnull) TKDataSourceExtended *dataSource;

/**
 Options for the autocomplete to suggest.
 */

@property (nonatomic, strong, nullable) NSArray *options;

/**
 The selected item in the options list.
 */
@property (nonatomic, strong, nullable) NSString *selectedItem;

@end
