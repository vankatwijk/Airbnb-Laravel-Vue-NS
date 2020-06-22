//
//  TKDataSourceSettings.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKDataSourceCollectionViewSettings;
@class TKDataSourceTableViewSettings;

/**
 Contains various settings allowing appearance customizations of TKDataSource consumers. e.g. TKChart, TKCalendar, UITableView, etc.
 */
@interface TKDataSourceSettings : NSObject

/**
 Settings specific to UICollectionView.
 */
@property (nonatomic, strong, readonly, nonnull) TKDataSourceCollectionViewSettings *collectionView;

/**
 Settings specific to UITableView.
 */
@property (nonatomic, strong, readonly, nonnull) TKDataSourceTableViewSettings *tableView;

@end
