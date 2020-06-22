//
//  TKCalendarInlineViewTableViewCellStyle.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"

@class TKFill;

/**
 @discussion Inline view table view cell's style.
 */
@interface TKCalendarInlineViewTableViewCellStyle : TKStyleNode

/**
 The event font.
 */
@property (nonatomic, strong) UIFont *eventFont;

/**
 The time font.
 */
@property (nonatomic, strong) UIFont *timeFont;

/**
 The event color.
 */
@property (nonatomic, strong) UIColor *eventColor;

/**
 The time color.
 */
@property (nonatomic, strong) UIColor *timeColor;

/**
 The event shape size.
 */
@property (nonatomic) CGSize shapeSize;

/**
 The separator color.
 */
@property (nonatomic, strong) UIColor *separatorColor;

/**
 The event cell background color.
 */
@property (nonatomic, strong) UIColor *backgroundColor;

@end
