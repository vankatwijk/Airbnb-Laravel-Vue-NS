//
//  TKCalendarYearPresenterStyle.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"
#import "TKCalendarTextEffect.h"


@class TKShape;
@class TKFill;
@class TKStroke;

#define TKCalendarYearPresenterInLandscape 1

/**
 @discussion A year presenter's style.
 */
@interface TKCalendarYearPresenterStyle : TKStyleNode

/**
 The number of months to be shown on a single page.
 */
@property (nonatomic) NSInteger monthsPerPage;

/**
 The day text color.
 */
@property (nonatomic, strong) UIColor *dayTextColor;

/**
 The weekend text color.
 */
@property (nonatomic, strong) UIColor *weekendTextColor;

/**
 The today text color.
 */
@property (nonatomic, strong) UIColor *todayTextColor;

/**
 The day name text color.
 */
@property (nonatomic, strong) UIColor *dayNameTextColor;

/**
 The month name text color.
 */
@property (nonatomic, strong) UIColor *monthNameTextColor;

/**
 The day text font.
 */
@property (nonatomic, strong) UIFont *dayFont;

/**
 The day name text font.
 */
@property (nonatomic, strong) UIFont *dayNameFont;

/**
 The month name text font.
 */
@property (nonatomic, strong) UIFont *monthNameFont;

/**
 The today cell shape.
 */
@property (nonatomic, strong) TKShape *todayShape;

/**
 The today shape fill.
 */
@property (nonatomic, strong) TKFill *todayShapeFill;

/**
 The today shape stroke.
 */
@property (nonatomic, strong) TKStroke *todayShapeStroke;

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
 The text effect to be applied to the day name text.
 
 @discussion The available effects are specified below:
 
 typedef enum {
 TKCalendarTextEffectNone,      // No text effect will be applied.
 TKCalendarTextEffectUppercase, // The text will be converted uppercase.
 TKCalendarTextEffectLowercase  // The text will be converted to lowercase.
 } TKCalendarTextEffect
 
 */
@property (nonatomic) TKCalendarTextEffect dayNameTextEffect;

/**
 The text alignment for the month name.
 */
@property (nonatomic) NSTextAlignment monthNameTextAlignment;

@end
