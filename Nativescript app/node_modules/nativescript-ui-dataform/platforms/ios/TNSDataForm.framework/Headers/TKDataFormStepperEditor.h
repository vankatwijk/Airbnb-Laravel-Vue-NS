//
//  TKDataFormStepperCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataFormEditor.h"

/**
 The editor view is used to edit numeric values. In its essence, it is a UIStepper.
 */
@interface TKDataFormStepperEditor : TKDataFormEditor

/**
 The value label of TKDataFormStepperEditor.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel *valueLabel;

/**
 The editor's UIStepper control.
 */
@property (nonatomic, strong, readonly, nonnull) UIStepper *stepperView;

/**
 A number formatter fot the editor's value.
 */
@property (nonatomic, strong, nullable) NSNumberFormatter *formatter;

@end
