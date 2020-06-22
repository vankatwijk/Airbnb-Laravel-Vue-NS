//
//  TKDataSourceCollectionViewSettings.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

/**
 Defines a block function that is used when creating a new cell in UICollectionView when using it with TKDataSource.
 
 @param collectionView The collectionView.
 @param indexPath The index path for the cell.
 @param item The item associated with this cell.
 */
typedef UICollectionViewCell* __nullable (^TKDataSourceCollectionViewSettings_CreatrCellBlock)(UICollectionView * __nonnull collectionView,
                                                                                    NSIndexPath * __nonnull indexPath,
                                                                                    id __nonnull item);

/**
 Defines a block function that is used when initializing cell properties in UICollectionView when using it with TKDataSource.
 
 @param collectionView The collectionView.
 @param indexPath The index path for the cell.
 @param cell The cell.
 @param item The item associated with this cell.
 */
typedef void (^TKDataSourceCollectionViewSettings_InitCellWithItemBlock)(UICollectionView * __nonnull collectionView,
                                                                         NSIndexPath* __nonnull indexPath,
                                                                         UICollectionViewCell * __nonnull cell,
                                                                         id __nonnull item);

/**
 The settings that can be customized when using TKDataSource with UICollectionView.
 */
@interface TKDataSourceCollectionViewSettings : NSObject

/**
 Defines a block function that is called when creating a new cell in UICollectionView. TKCollectionViewCell is used by default.
 
 @param cellIdForItem The block function that will be called when creating a new cell.
 */
- (void)createCell:(TKDataSourceCollectionViewSettings_CreatrCellBlock __nonnull)cellIdForItem;

/**
 Defines a block function that is called when initializing the cell properties.
 
 @param initCellWithItem The block function that will be called when initializing a new cell.
 */
- (void)initCell:(TKDataSourceCollectionViewSettings_InitCellWithItemBlock __nonnull)initCellWithItem;

@end
