//
//  TKDataFormSwitchCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataFormEditor.h"

/**
 The default editor for boolean values. In its essence it is a UISwitch.
 */
@interface TKDataFormSwitchEditor : TKDataFormEditor

/**
 The editor's UISwitch control.
 */
@property (nonatomic, strong, readonly) UISwitch *switchView;

@end
