//
//  TKDataSourceTableViewSettings.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

/**
 Defines a block function that is used when creating a new cell in UITableView when using it with TKDataSource.
 
 @param tableView The collectionView.
 @param indexPath The index path for the cell.
 @param item The item associated with this cell.
 */
typedef UITableViewCell* __nullable (^TKDataSourceTableViewSettings_CreateCellBlock)(UITableView * __nonnull tableView, NSIndexPath* __nonnull indexPath, id __nonnull item);

/**
 Defines a block function that is used when initializing cell properties in UITableView when using it with TKDataSource.
 
 @param tableView The table view.
 @param indexPath The index path for the cell.
 @param cell The cell.
 @param item The item associated with this cell.
 */
typedef void (^TKDataSourceTableViewSettings_InitCellWithItemBlock)(UITableView * __nonnull tableView, NSIndexPath* __nonnull indexPath, UITableViewCell * __nonnull cell, id __nonnull item);

/**
 The settings that can be customized when using TKDataSource with UITableView.
 */
@interface TKDataSourceTableViewSettings : NSObject

/**
 Defines a block function that is called when creating a new cell in UITableView. UITableViewCell is used by default.
 
 @param createCellForItem The block function that will be called when creating a new cell.
 */
- (void)createCell:(TKDataSourceTableViewSettings_CreateCellBlock __nonnull)createCellForItem;

/**
 Defines a block function that is called when initializing the cell properties.

 @param initCellWithItem The block function that will be called when initializing a cell.
 */
- (void)initCell:(TKDataSourceTableViewSettings_InitCellWithItemBlock __nonnull)initCellWithItem;

@end
