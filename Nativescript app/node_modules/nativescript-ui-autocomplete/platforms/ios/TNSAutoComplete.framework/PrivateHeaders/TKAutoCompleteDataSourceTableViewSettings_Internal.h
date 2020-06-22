//
//  TKAutoCompleteDataSourceTableViewSettings_Internal.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//
#import "TKAutoCompleteDataSourceTableViewSettings.h"

@class TKAutoCompleteDataSourceGroup;
@class TKDataSourceExtended;

@interface TKAutoCompleteDataSourceTableViewSettings ()

- (void)ds_initCell:(UITableViewCell*)cell withItem:(id)item atIndexPath:(NSIndexPath*)indexPath
            inGroup:(TKAutoCompleteDataSourceGroup*)group fromDataSource:(TKDataSourceExtended*)dataSource  inTableView:(UITableView*)tableView;

- (UITableViewCell*)ds_cellForItem:(id)item atIndexPath:(NSIndexPath*)indexPath inGroup:(TKAutoCompleteDataSourceGroup*)group inTableView:(UITableView*)tableView;

@end
