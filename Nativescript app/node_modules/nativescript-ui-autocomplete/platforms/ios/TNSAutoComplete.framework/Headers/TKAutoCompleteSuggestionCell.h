//
//  TKAutoCompleteSuggestionCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

/**
 The default cell used in the TKSuggestionListView.
 */
@interface TKAutoCompleteSuggestionCell : UICollectionViewCell

/**
 A default view in the cell that may be used to display an image.
 */
@property (nonatomic, strong, readonly, nonnull) UIImageView *imageView;

/**
 A default label that may be used to display text in the cell.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel* textLabel;

/**
 Defines insets that are applied to the content of the contentView.
 */
@property (nonatomic) UIEdgeInsets contentInsets;

@end
