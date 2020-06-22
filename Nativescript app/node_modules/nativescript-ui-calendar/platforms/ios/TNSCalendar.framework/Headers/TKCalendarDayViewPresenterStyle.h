//
//  TKCalendarDayViewPresenterStyle.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"
#import "TKCalendarTextEffect.h"

/**
 @discussion A day view presenter's style.
 */
@interface TKCalendarDayViewPresenterStyle : TKStyleNode

/**
 The presenter background color.
 */
@property (nonatomic,strong) UIColor * __nullable backgroundColor;

/**
 The title cell height.
 */
@property (nonatomic) CGFloat titleCellHeight;

/**
 The day name cell height.
 */
@property (nonatomic) CGFloat dayNameCellHeight;

/**
 The day name cell height.
 */
@property (nonatomic) CGFloat dayCellHeight;

/**
 The week number cell width.
 */
@property (nonatomic) CGFloat weekNumberCellWidth;

/**
 The spacing between columns.
 */
@property (nonatomic) CGFloat columnSpacing;

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
