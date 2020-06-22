//
//  TKAutoCompleteDataSourceSettings.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKAutoCompleteDataSourceCollectionViewSettings;
@class TKAutoCompleteDataSourceTableViewSettings;
@class TKAutoCompleteDataSourceAutoCompleteSettings;

/**
 Contains various settings allowing appearance customizations of TKDataSourceExtended consumers. e.g. TKChart, TKCalendar, UITableView, etc.
 */
@interface TKAutoCompleteDataSourceSettings : NSObject

/**
 Settings specific to UICollectionView.
 */
@property (nonatomic, strong, readonly, nonnull) TKAutoCompleteDataSourceCollectionViewSettings *collectionView;

/**
 Settings specific to UITableView.
 */
@property (nonatomic, strong, readonly, nonnull) TKAutoCompleteDataSourceTableViewSettings *tableView;

/**
 Settings specific to TKAutoComplete.
 */
@property (nonatomic, strong, readonly, nonnull) TKAutoCompleteDataSourceAutoCompleteSettings *autocomplete;

@end
