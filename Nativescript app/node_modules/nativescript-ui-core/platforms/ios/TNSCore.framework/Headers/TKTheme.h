//
//  TKTheme.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKStyleGroup;
@class TKStyleNode;
@class TKStyleSheet;


/**
 @discussion Represents the theme of a stylable object.
 */
@interface TKTheme : NSObject
/**
 Adds a style group to the theme.
 @param aStyleGroup The style group.
 */
- (void)addStyleGroup:(TKStyleGroup*)aStyleGroup;

/**
 Removes a style from the theme.
 @param aStyleGroup The style group
 */
- (void)removeStyleGroup:(TKStyleGroup*)aStyleGroup;

/**
 Removes all style groups from the theme.
 */
- (void)removeAllStyleGroups;

/**
 Returns a style sheet for particular class.
 @param aClass A class.
 @returns A style sheet for particular class.
 */
- (TKStyleSheet*)stylesForClass:(Class)aClass;

- (void)addStyleGroupWithClass:(Class)aClass settings:(NSDictionary*)settings;
- (void)addStyleGroupWithClass:(Class)aClass state:(NSInteger)aState settings:(NSDictionary*)settings;

@end
