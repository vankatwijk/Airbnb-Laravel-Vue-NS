//
//  TKDataFormSegmentedCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataFormEditor.h"

/**
 An editor view used to edit values in TKDataForm by using a UISegmentedControl.
 */
@interface TKDataFormSegmentedEditor : TKDataFormEditor

@property (nonatomic, strong, readonly, nonnull) UISegmentedControl *segmentedControl;

/**
 The names of all the segments in TKDataFormSegmentedEditor.
 */
@property (nonatomic, strong, nullable) NSArray *options;

/**
 The index for the selected item in the options list.
 */
@property (nonatomic) NSInteger selectedIndex;

@end
