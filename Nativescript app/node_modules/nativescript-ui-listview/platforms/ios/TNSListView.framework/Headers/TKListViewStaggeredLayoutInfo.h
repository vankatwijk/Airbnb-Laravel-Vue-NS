//
//  TKListViewStaggeredLayoutInfo.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@interface TKListViewStaggeredLayoutInfo : NSObject

@property (nonatomic) CGRect frame;

@property (nonatomic) CGSize itemSize;

@property (nonatomic, strong) UICollectionViewLayoutAttributes * __nonnull attributes;

- (instancetype __nonnull)initWithFrame:(CGRect)frame andIndexPath:(UICollectionViewLayoutAttributes* __nonnull)attributes itemSize:(CGSize)itemSize;

@end
