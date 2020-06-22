//
//  TKDataSourceSortDescriptor.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

/**
 A sort descriptor that is used in TKDataSource to sort items.
 */
@interface TKDataSourceSortDescriptor : NSObject

/**
 The name of the property by which values sorted. The name of this property is ignored when the comparator property is set.
 */
@property (nonatomic, copy, nullable) NSString *propertyName;

/**
 A comparison block function that is used to sort items. This property has higher priority than the propertyName.
 */
@property (readonly, nullable) NSComparator comparator;

/**
 Defines the sort direction. Ignored when using a comparator function.
 */
@property (nonatomic, assign) BOOL ascending;

/**
 Returns an instance of NSSortDescriptor based on the settings of the group descriptor.
 */
@property (nonatomic, strong, readonly, nonnull) NSSortDescriptor* descriptor;

/**
 Initializes the sort descriptor with a property name and sort direction.
 
 @param propertyName The name of the property that is sorted.
 @param ascending The sort direction.
 */
- (instancetype __nonnull)initWithProperty:(NSString* __nonnull)propertyName ascending:(BOOL)ascending;

/**
 Initializes the sort descriptor with a comparator.
 
 @param comparator The comparator function to use when sorting items.
 */
- (instancetype __nonnull)initWithComparator:(NSComparator __nonnull)comparator;

@end
