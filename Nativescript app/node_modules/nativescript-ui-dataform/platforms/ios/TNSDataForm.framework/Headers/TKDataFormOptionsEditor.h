//
//  TKDataFormOptionsEditor.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataFormViewControllerEditor.h"

@class TKLabel;

/**
 An editor view which allows editing values in TKDataForm by using an option list.
 */
@interface TKDataFormOptionsEditor : TKDataFormViewControllerEditor

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
 An array of all options in the TKDataFormOptions.
 */
@property (nonatomic, strong, nullable) NSArray *options;

/**
 The index for the selected item in the options list.
 */
@property (nonatomic) NSInteger selectedIndex;

@end
