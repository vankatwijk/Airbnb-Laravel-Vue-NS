//
//  TKDataFormAutocompleteEditor.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import "TKDataFormViewControllerEditor.h"

/**
 AutoCompleteTextView editor.
 */
@interface TKDataFormAutocompleteEditor : TKDataFormViewControllerEditor

/**
 The label of the selected option (read-only).
 */
@property (nonatomic, strong, readonly, nonnull) TKLabel *selectedOptionLabel;

/**
 The accessory image view.
 */
@property (nonatomic, strong, readonly, nonnull) UIImageView *accessoryImageView;

/**
 A bool that determines if accessory image should be visible.
 */
@property (nonatomic) BOOL showAccessoryImage;

/**
 Options for the autocomplete to suggest.
 */

@property (nonatomic, strong, nullable) NSArray *options;

/**
 The selected item in the options list.
 */
@property (nonatomic, strong, nullable) NSString *selectedItem;

/**
 The string that is displayed when there is no selection in the autocomplete field.
 */
@property (nonatomic, strong, nullable) NSString *placeholder;

@end
