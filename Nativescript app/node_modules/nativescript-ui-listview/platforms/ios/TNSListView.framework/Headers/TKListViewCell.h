//
//  TKListViewCell.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKListViewReusableCell.h"

/**
 A cell in a list view.
 */
@interface TKListViewCell:TKListViewReusableCell

/**
 The background view that becomes visible after the user swipes the content view.
 */
@property (nonatomic, strong, readonly, nonnull) UIView *swipeBackgroundView;

/**
 A default view in the cell that may be used to display an image.
 */
@property (nonatomic, strong, readonly, nonnull) UIImageView *imageView;

/**
 A visual glyph used as hint that cell can be dragged when cell reorder is enabled.
 */
@property (nonatomic, strong, nonnull) UIView *reorderHandle;

/**
 A text label that may be used to display detailed text below the main text label in the cell.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel *detailTextLabel;

/**
 Defines insets that are applied to the content of the contentView.
 */
@property (nonatomic) UIEdgeInsets contentInsets;

/**
 Determines whether the content view will offset to reveal the multiple selection indicator.
 */
@property (nonatomic) BOOL offsetContentViewInMultipleSelection;

- (BOOL)shouldSelect;

@end
