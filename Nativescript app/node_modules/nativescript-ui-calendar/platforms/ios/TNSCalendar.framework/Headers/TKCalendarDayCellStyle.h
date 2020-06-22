//
//  TKCalDayCellStyle.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendarCellStyle.h"

/**
 @enum TKCalendarDayCellEventOrientation
 @discussion Defines the event orientation options.
 */
typedef NS_ENUM(NSInteger, TKCalendarDayCellEventOrientation) {
 
    /**
     Events are placed horizontally.
     */
    TKCalendarDayCellEventOrientationHorizontal = 1,
    
    /**
     Events are placed vertically.
     */
    TKCalendarDayCellEventOrientationVertical = 2,
    
};

/**
 @discussion A class that represents a day cell's style.
 */
@interface TKCalendarDayCellStyle : TKCalendarCellStyle

/**
 The event instets.
 */
@property (nonatomic) UIEdgeInsets eventInsets;

/**
 The event font.
 */
@property (nonatomic, strong) UIFont *eventFont;

/**
 The event text color.
 */
@property (nonatomic, strong) UIColor *eventTextColor;

/**
 The all day event text color.
 */
@property (nonatomic, strong) UIColor *allDayEventTextColor;

/**
 The event alignment.
 
 @discussion The available alignment modes are specified below:
 
 typedef enum {
 TKCalendarCellAlignmentLeft               // The cell content is aligned to left.
 TKCalendarCellAlignmentRight              // The cell content is aligned to right.
 TKCalendarCellAlignmentTop                // The cell content is aligned to top.
 TKCalendarCellAlignmentBottom             // The cell content is aligned to bottom.
 TKCalendarCellAlignmentHorizontalCenter   // The cell content is aligned horizontally.
 TKCalendarCellAlignmentVerticalCenter     // The cell content is aligned vertically.
 } TKCalendarCellAlignment;
 
 */
@property (nonatomic) TKCalendarCellAlignment eventAlignment;

/**
 The event shape.
 */
@property (nonatomic, strong) TKShape *eventShape;

/**
 The spacing between events.
 */
@property (nonatomic) CGFloat eventSpacing;

/**
 The event layout orientation.

 @discussion The available orientation modes are specified below:
 
 typedef enum {
 TKCalendarDayCellEventOrientationHorizontal // Events are placed horizontally.
 TKCalendarDayCellEventOrientationVertical   // Events are placed vertically.
 } TKCalendarDayCellEventOrientation;
 
 */
@property (nonatomic) TKCalendarDayCellEventOrientation eventOrientation;

/**
 Defines whether the default selection style should be used. This style is used in range selection mode.
 */
@property (nonatomic) BOOL useDefaultSelectionStyle;

/**
 The selection color to be used when useDefaultSelectionStyle is set to YES.
 */
@property (nonatomic, strong) UIColor *defaultSelectionColor;

/**
 Defines whether to stretch events to fill the available cell area.
 */
@property (nonatomic) BOOL stretchEvents;

/**
 Defines whether to show events as text.
 */
@property (nonatomic) BOOL displayEventsAsText;

/**
 Defines the maximal number of events that can be displayed in a single calendar cell.
 */
@property (nonatomic) NSInteger maxEventsCount;

/**
 Defines whether to wrap the event text.
 */
@property (nonatomic) BOOL wrapEventText;

@end
