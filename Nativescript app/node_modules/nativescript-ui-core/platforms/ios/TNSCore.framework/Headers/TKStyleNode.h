//
//  TKStyleNode.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKStyleGroup;
@class TKStyleID;

/**
 Represents a style node that stores visual properties.
 */
@interface TKStyleNode : NSObject

/**
 Represents the style id of the node.
 */
@property (nonatomic, strong) TKStyleID *styleID;

/**
 Determines whether the node is in the theme applying block.
 */
@property (nonatomic, readonly) BOOL isThemeBlock;

/**
 Begins theme block.
 */
- (void)beginThemeBlock;

/**
 Ends theme block.
 */
- (void)endThemeBlock;

/**
 Determines whether a value can be set.
 @param value A property's value
 */
- (BOOL)canSetValue:(NSInteger)value;

/**
 Resets property values to their local values.
 */
- (void)resetLocalValues;

@end
