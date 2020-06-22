//
//  TKDataFormOptionsViewController.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKDataFormOptionsEditor;

/**
 @discussion The TKDataFormOptionsViewController class represents a view controller used to represent a list with options in master/detail scenario.
 */
@interface TKDataFormOptionsViewController : UITableViewController

/**
 The editor items.
 */
@property (nonatomic, strong, nullable) NSArray *items;

/**
 An instance of TKDataFormOptionsEditor.
 */
@property (nonatomic, weak, nullable) TKDataFormOptionsEditor *editor;

@end
