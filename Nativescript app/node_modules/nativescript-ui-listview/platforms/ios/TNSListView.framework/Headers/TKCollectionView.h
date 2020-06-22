//
//  TKCollectionView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKListView;

@interface TKCollectionView : UICollectionView

@property (nonatomic, weak) TKListView *ownerListView;

@property (nonatomic) BOOL skipTouch;

@end
