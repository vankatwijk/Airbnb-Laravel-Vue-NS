//
//  TKDataSourceFilterDescriptor.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataSource.h"

/**
 A filter descriptor used in TKDataSource to filter items.
 */
@interface TKDataSourceFilterDescriptor : NSObject

/**
 An SQL-like string query used when filtering items. Check the documentation of NSPredicate for detailed explanation for the syntax of this property value. The value of this property is ignored when the filterBlock property is set.
 */
@property (nonatomic, readonly, nonnull) NSString *query;

/**
 The block function that is used to filter items. This property has higher priority than the query.
 */
@property (readonly, nullable) TKDataSourceFilterBlock filterBlock;

/**
 Initializes the filter descriptor with a query.

 @param query The query to use when filtering items.
 */
- (instancetype __nonnull)initWithQuery:(NSString* __nonnull)query;

/**
 Initializes the filter descriptor with a block function.

 @param filterBlock The block function that is used to filter items.
 */
- (instancetype __nonnull)initWithBlock:(TKDataSourceFilterBlock __nonnull)filterBlock;

/**
 Returns true if the specified item should remain in the filtered list.
 
 @param item The item to filter.
 */
- (BOOL)evaluate:(id __nonnull)item;

@end
