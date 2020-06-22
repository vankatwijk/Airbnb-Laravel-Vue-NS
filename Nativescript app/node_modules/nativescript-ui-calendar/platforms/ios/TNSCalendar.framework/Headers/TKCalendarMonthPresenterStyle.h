//
//  TKCalendarMonthPresenterStyle.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"
#import "TKCalendarTextEffect.h"

/**
 @discussion A month presenter's style.
 */
@interface TKCalendarMonthPresenterStyle : TKStyleNode

/**
 The color of the popover that displays the events when in popover mode.
 */
@property (nonatomic) UIColor *popoverColor;

/**
 The spacing between rows.
 */
@property (nonatomic) CGFloat rowSpacing;

/**
 The spacing between columns.
 */
@property (nonatomic) CGFloat columnSpacing;

/**
 The presenter background color.
 */
@property (nonatomic,strong) UIColor *backgroundColor;

/**
 The title cell height.
 */
@property (nonatomic) CGFloat titleCellHeight;

/**
 The day name cell height.
 */
@property (nonatomic) CGFloat dayNameCellHeight;

/**
 The week number cell width.
 */
@property (nonatomic) CGFloat weekNumberCellWidth;

/**
 The text effect that will be applied to the month name text.
 
 @discussion The available effects are specified below:
 
 typedef enum {
 TKCalendarTextEffectNone,      // No text effect will be applied.
 TKCalendarTextEffectUppercase, // The text will be converted uppercase.
 TKCalendarTextEffectLowercase  // The text will be converted to lowercase.
 } TKCalendarTextEffect
 
 */
@property (nonatomic) TKCalendarTextEffect monthNameTextEffect;

/**
 The text effect that will be applied to the month name text.
 
 @discussion The available effects are specified below:
 
 typedef enum {
 TKCalendarTextEffectNone,      // No text effect will be applied.
 TKCalendarTextEffectUppercase, // The text will be converted uppercase.
 TKCalendarTextEffectLowercase  // The text will be converted to lowercase.
 } TKCalendarTextEffect
 
 */
@property (nonatomic) TKCalendarTextEffect dayNameTextEffect;

@end
