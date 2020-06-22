//
//  TKDataFromAutocompleteController.h
//  TelerikUI
//.
//  Copyright © 2015 Telerik. All rights reserved.
//

#import "TNSAutoComplete/TKAutoCompleteController.h"
#import "TNSAutoComplete/TKAutoCompleteTextView.h"

@class TKDataSourceExtended;
@class TKDataFormAutocompleteEditor;

/**
The default controller holding autocomplete control.
 */
@interface TKDataFormAutocompleteController : TKAutoCompleteController<TKAutoCompleteDelegate>

/**
 An instance of TKDataFormOptionsEditor.
 */
@property (nonatomic, weak) TKDataFormAutocompleteEditor *editor;

/**
 The data source associated with the autocomplete text view.
 */
@property (nonatomic, strong, readonly) TKDataSourceExtended *dataSource;

@end
