//
//  TKDataFormPickerViewEditor.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataFormInlineEditor.h"

/**
 @discussion A UIPickerView editor by which you can choose an option from a list of options.
 */
@interface TKDataFormPickerViewEditor : TKDataFormInlineEditor

/**
 An array of all options in the TKDataFormOptions.
 */
@property (nonatomic, strong, nullable) NSArray *options;

/**
 The editor's UIPickerView control.
 */
@property (nonatomic, strong, readonly, nonnull) UIPickerView *pickerView;

/**
 The index for the selected item in the options list.
 */
@property (nonatomic) NSInteger selectedIndex;

@end
