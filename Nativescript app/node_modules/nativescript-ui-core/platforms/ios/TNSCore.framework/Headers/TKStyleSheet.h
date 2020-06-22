//
//  TKStyleSheet.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKStyleGroup;
@class TKStyleID;
@class TKStyleNode;

/**
 @discussion Represents a class that contains the whole style sheet list of style groups.
 */
@interface TKStyleSheet : NSObject

/**
 Returns the count of all style groups in the style sheet.
 @returns The count of style groups in the style sheet.
 */
@property (nonatomic, readonly) NSUInteger styleGroupsCount;

/**
 Adds a style group to the style sheet.
 @param aStyleGroup A style group.
 */
- (void)addStyleGroup:(TKStyleGroup*)aStyleGroup;

/**
 Removes a style group from the style sheet.
 @param aStyleGroup A style group.
 */
- (void)removeStyleGroup:(TKStyleGroup*)aStyleGroup;

/**
 Removes all style groups from the style sheet.
 */
- (void)removeAllStyleGroups;

/** 
 Applies the style sheet to a style node.
 */
- (void)applyStylesToNode:(TKStyleNode*)node;

@end
