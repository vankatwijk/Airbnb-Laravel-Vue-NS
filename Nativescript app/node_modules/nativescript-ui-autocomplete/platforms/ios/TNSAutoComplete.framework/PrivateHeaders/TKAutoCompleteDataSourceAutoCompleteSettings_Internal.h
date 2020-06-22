//
//  TKAutoCompleteDataSourceListViewSettings_Internal.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//
#import "TKAutoCompleteDataSourceAutoCompleteSettings.h"

@interface TKAutoCompleteDataSourceAutoCompleteSettings ()

- (TKAutoCompleteToken*)tokenForItem:(id)item atIndex:(NSUInteger)dataIndex fromDataSource:(TKDataSourceExtended*)dataSource;

@end
