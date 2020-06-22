//
//  TKAutoCompleteDataSourceCollectionViewSettings_Internal.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//
#import "TKAutoCompleteDataSourceCollectionViewSettings.h"

@class TKDataSourceExtended;
@class TKAutoCompleteDataSourceGroup;

@interface TKAutoCompleteDataSourceCollectionViewSettings ()

- (UICollectionViewCell*)ds_cellForItem:(id)item atIndexPath:(NSIndexPath*)indexPath inCollectionView:(UICollectionView*)collectionView;

- (void)ds_initCell:(UICollectionViewCell*)cell withItem:(id)item atIndexPath:(NSIndexPath*)indexPath inGroup:(TKAutoCompleteDataSourceGroup*)group
     fromDataSource:(TKDataSourceExtended*)dataSource inCollectionView:(UICollectionView*)collectionView;

@end
