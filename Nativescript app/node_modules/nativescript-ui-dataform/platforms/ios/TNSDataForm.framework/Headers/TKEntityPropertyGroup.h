//
//  TKEntityPropertyGroup.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKEntity;
@class TKEntityProperty;

/**
 @discussion This class represents a group of property models defined by TKEntityProperty.
 */
@interface TKEntityPropertyGroup : NSObject

/**
 The TKDataFormEntity to which the property belongs (read-only).
 */
@property (nonatomic, weak) TKEntity *owner;

/**
 The name of the group.
 */
@property (nonatomic, copy) NSString *name;

/**
 @return An array of TKEntityProperty objects containing all the properties.
 */
@property (nonatomic, strong, readonly) NSArray *properties;

/**
 Determines if the property should be visible in the data form.
 */
@property (nonatomic) BOOL hidden;

/**
 Instantiates a TKEntityPropertyGroup object with a name and properties list.
 @param name The name of the group.
 @param properties A list with properties.
 */
- (instancetype)initWithName:(NSString*)name properties:(NSArray*)properties;

/**
 Instantiates a TKEntityPropertyGroup object with a name and properties list.
 @param name The name of the group.
 @param properties A list with properties.
 @param orderByPropertyIndex Determines whether to order propertie by their index property. The default action is to order them by using the order in properties collection.
 */
- (instancetype)initWithName:(NSString*)name properties:(NSArray*)properties orderByPropertyIndex:(BOOL)orderByPropertyIndex;

/**
 Returns the property at the specified index.
 @param index The property index.
 @return TKEntityProperty.
 */
- (TKEntityProperty*)propertyAtIndex:(NSUInteger)index;

/**
 The TKEntityProperty with the specified name.
 @param name of the property that has to be returned.
 @return TKEntityProperty.
 */
- (TKEntityProperty*)propertyWithName:(NSString*)name;

/**
 The TKEntityProperty with the specified name.
 @param propertyName The name of the property that has to be returned.
 @return TKEntityProperty.
 */
- (TKEntityProperty*)objectForKeyedSubscript:(NSString*)propertyName;

/**
 Returns the property at the specified index.
 @param index The property index.
 @return TKEntityProperty.
 */
- (TKEntityProperty*)objectAtIndexedSubscript:(NSUInteger)index;

/**
 Adds a property in the group.
 @param property The property to add.
 */
- (void)addProperty:(TKEntityProperty*)property;

/**
 Inserts a property at the specified index.
 @param property The property instance.
 @param index The index where the group should be inserted.
 */
- (void)insertProperty:(TKEntityProperty*)property atIndex:(NSUInteger)index;

/**
 Removes the property at the specified index.
 @param index The index of the property to remove.
 */
- (void)removePropertyAtIndex:(NSUInteger)index;

/**
 Removes the specified property.
 @param property The property to remove.
 */
- (void)removeProperty:(TKEntityProperty*)property;

/**
 Removes all properties.
 */
- (void)removeAllProperties;

@end

