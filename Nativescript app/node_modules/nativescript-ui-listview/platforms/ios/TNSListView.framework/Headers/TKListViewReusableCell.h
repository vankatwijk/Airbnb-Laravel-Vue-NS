//
//  TKListViewReusableCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

/**
 A base class for header and footer cells.
 */
@interface TKListViewReusableCell : UICollectionViewCell

/**
 A default label that may be used to display text in the cell.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel* textLabel;

@end
