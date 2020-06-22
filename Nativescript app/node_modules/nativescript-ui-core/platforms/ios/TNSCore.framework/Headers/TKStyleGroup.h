//
//  TKStyleGroup.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKStyleNode;
@class TKStyleID;

/**
 @discussion Represents a class that contains a set of properties for a particular style.
 */
@interface TKStyleGroup : NSObject

+ (id)styleGroupWithClass:(Class)aClass settings:(NSDictionary *)settings;

+ (id)styleGroupWithClass:(Class)aClass state:(NSInteger)aState settings:(NSDictionary*)settings;

/**
 The id of the style group.
 */
@property (nonatomic, strong) TKStyleID *styleID;

/**
 The style properties.
 */
@property (nonatomic, strong, readonly) NSDictionary* properties;

/**
 Initializes a TKStyleGroup class.
 @param aClass The class for which the group is instantiated.
 */
- (instancetype)initWithClass:(Class)aClass;

/**
 Sets a value for a particular property.
 @param value The value.
 @param key The property's value.
 */
- (void)setPropertyValue:(id)value forKey:(NSString*)key;

/**
 Determines a property's value.
 @param key The property's name.
 @returns The property's value.
 */
- (id)propettyValueForKey:(NSString*)key;

/**
 Resets the values of all associated properties.
 */
- (void)resetPropertyValues;

/**
 Applies a style to a node.
 * @param node The style node.
 */
- (void)applyStyleToNode:(TKStyleNode*)node;

@end
