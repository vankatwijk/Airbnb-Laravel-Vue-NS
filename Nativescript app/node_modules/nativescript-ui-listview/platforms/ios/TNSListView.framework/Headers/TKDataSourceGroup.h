//
//  TKDataSourceGroup.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

/**
 Represents a group of items sharing the same group key in TKDataSource.
 */
@interface TKDataSourceGroup : NSObject

/**
 The group key.
 */
@property (nonatomic, strong, nonnull) id key;

/**
 A display key specific for this group. TKDataSource displayKey property is used if this property value is set to nil.
 */
@property (nonatomic, copy, nullable) NSString *displayKey;

/**
 A value key specific for this group. TKDataSource valueKey property is used if this property value is set to nil.
 */
@property (nonatomic, copy, nullable) NSString *valueKey;

/**
 An array containing the items specific for this group.
 */
@property (nonatomic, strong, nonnull) NSArray *items;

/**
 Initializes the group with an array of items.
 
 @param items The items array specific for this group.
 */
- (instancetype __nonnull)initWithItems:(NSArray* __nonnull)items;

/**
 Initializes the group with an array of items an a value key.
 
 @param items The items array specific for this group.
 @param valueKey The value key.
 */
- (instancetype __nonnull)initWithItems:(NSArray * __nonnull)items valueKey:(NSString* __nullable)valueKey;

/**
 Initializes the group with an array of items value and display keys.
 
 @param items The items array specific for this group.
 @param valueKey The value key.
 @param displayKey The display key.
 */
- (instancetype __nonnull)initWithItems:(NSArray* __nonnull)items valueKey:(NSString* __nullable)valueKey displayKey:(NSString* __nullable)displayKey;

@end
