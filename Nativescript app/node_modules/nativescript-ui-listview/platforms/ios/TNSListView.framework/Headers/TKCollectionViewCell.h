//
//  TKCollectionViewCell.h
//  TestDataSource
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

/**
 Represents the collection view cell used by default when binding a TKDataSource with UICollectionView.
 */
@interface TKCollectionViewCell : UICollectionViewCell

/**
 A text label.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel *label;

@end
