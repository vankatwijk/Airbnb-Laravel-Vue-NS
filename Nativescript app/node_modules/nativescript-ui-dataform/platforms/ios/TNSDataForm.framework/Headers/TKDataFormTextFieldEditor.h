//
//  TKDataFormTextFieldCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataFormEditor.h"

@class TKTextField;
/**
 @discussion The default editor for string properties. In its essence, it is a UITextField.
 */
@interface TKDataFormTextFieldEditor : TKDataFormEditor <UITextFieldDelegate>

/**
 The editor's text field.
 */
@property (nonatomic, strong, readonly) TKTextField *textField;

@end
