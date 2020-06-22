//
//  TKDataFormDatePickerCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataFormInlineEditor.h"

/**
 @discussion The default editor for date values. In its essence, it is a UIDatePicker.
 */
@interface TKDataFormDatePickerEditor : TKDataFormInlineEditor

@property (nonatomic, strong, readonly, nonnull) UIDatePicker *datePicker;

/**
 The NSDateFormatter object included in the TKDataFormDatePickerEditor.
 */
@property (nonatomic, strong, nullable) NSDateFormatter *dateFormatter;

/**
 The string that is displayed when there is no selection in the editor.
*/
@property (nonatomic, strong, nullable) NSString *placeholder;

@end
