//
//  TKCollectionView_Internal.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//
#import "TNSListView/TKCollectionView.h"

typedef NS_ENUM(NSInteger, MyCollectionViewState)
{
    MyCollectionViewStateNormal,
    MyCollectionViewStateReload,
    MyCollectionViewStateInsert,
    MyCollectionViewStateDelete,
    MyCollectionViewStateReorder,
};

@interface TKCollectionView ()

@property (nonatomic) BOOL useInternalCellCache;

@property (nonatomic) MyCollectionViewState state;

@property (nonatomic, weak) NSArray *invalidatedItems;

- (BOOL)isCellIDRegistered:(NSString*)cellID;

@end
