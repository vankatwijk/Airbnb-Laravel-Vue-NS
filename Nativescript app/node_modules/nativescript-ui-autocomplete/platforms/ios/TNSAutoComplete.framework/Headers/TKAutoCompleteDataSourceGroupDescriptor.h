//
//  TKAutoCompleteDataSourceGroupDescriptor.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataSourceExtended.h"

/**
 Represents a group descriptor that is used in TKDataSourceExtended to group items.
 */
@interface TKAutoCompleteDataSourceGroupDescriptor : NSObject

/**
 The name of the property by which values are grouped. The value of this property is ignored when the keyForItemBlock property is set.
 */
@property (nonatomic, copy, nullable) NSString * propertyName;

/**
 The block function that is used to define the group key. This property has higher priority than the propertyName.
 */
@property (readonly, nullable) TKAutoCompleteDataSourceMapFunctionBlock keyForItemBlock;

/**
 A comparator block to be used when sorting group items.
 */
@property (readonly, nullable) NSComparator comparatorBlock;

/**
 Initializes the group descriptor with a property name.

 @param propertyName The name of the property by which values are grouped.
 */
- (instancetype __nonnull)initWithProperty:(NSString* __nonnull)propertyName;

/**
 Initializes the group descriptor with a property name.
 
 @param propertyName The name of the property by which values are grouped.
 @param comparatorBlock The block functuon that is used to sort the groups.
 */
- (instancetype __nonnull)initWithProperty:(NSString* __nonnull)propertyName comparator:(NSComparator __nonnull)comparatorBlock;

/**
 Initializes the group descriptor with a block function.

 @param keyForItemBlock The block function that is used to define the group key.
 */
- (instancetype __nonnull)initWithBlock:(TKAutoCompleteDataSourceMapFunctionBlock __nonnull)keyForItemBlock;

/**
 Initializes the group descriptor with a block function.
 
 @param keyForItemBlock The block function that is used to define the group key.
 @param comparatorBlock The block functuon that is used to sort the groups.
 */
- (instancetype __nonnull)initWithBlock:(TKAutoCompleteDataSourceMapFunctionBlock __nonnull)keyForItemBlock comparator:(NSComparator __nonnull)comparatorBlock;

/**
 Returns the group key based on a specified item.

 @param item The item's group key that is requested.
 */
- (id __nonnull)keyForItem:(id __nonnull)item;

@end
