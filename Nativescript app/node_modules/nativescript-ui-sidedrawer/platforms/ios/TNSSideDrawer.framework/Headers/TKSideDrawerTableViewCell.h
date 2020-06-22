//
//  TKSideDrawerTableViewCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKSideDrawerItem;
@class TKCoreStackLayout;


/**
 Represents a cell inside the TKSideDrawerTableView.
 */
@interface TKSideDrawerTableViewCell : UITableViewCell

/**
 A view that separates the cell from the cell beneath it.
 */
@property (nonatomic, strong) UIView *separator;

/**
 The TKSideDrawerItem that will be displayed by the cell.
 */
@property (nonatomic, strong) TKSideDrawerItem *item;

/**
 The stack layout used to arrange sub views in this cell.
 */
@property (nonatomic, strong, readonly) TKCoreStackLayout *stack;




/**
 Update the visual appearance of TKSideDrawerTableViewCell to match its item settings.
 */
- (void)update;

@end
