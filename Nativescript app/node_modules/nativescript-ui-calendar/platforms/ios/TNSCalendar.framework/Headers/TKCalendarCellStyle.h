//
//  TKCalMonthCellStyle.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"

@class TKShape;
@class TKFill;
@class TKStroke;

/**
 * @enum TKCalendarCellAlignment
 * @discussion Defines the alignment options for cells in TKCalendar component.
 */
typedef NS_OPTIONS(NSInteger, TKCalendarCellAlignment)
{
    /**
     The cell content is aligned to left.
     */
    TKCalendarCellAlignmentLeft               = 1 << 0,
    
    /**
     The cell content is aligned to right.
     */
    TKCalendarCellAlignmentRight              = 1 << 1,
    
    /**
     The cell content is aligned to top.
     */
    TKCalendarCellAlignmentTop                = 1 << 2,
    
    /**
     The cell content is aligned to bottom.
     */
    TKCalendarCellAlignmentBottom             = 1 << 3,
    
    /**
     The cell content is aligned horizontally.
     */
    TKCalendarCellAlignmentHorizontalCenter   = 1 << 4,
    
    /**
     The cell content is aligned vertically.
     */
    TKCalendarCellAlignmentVerticalCenter     = 1 << 5,
    
};

/**
 @discussion A class that represents a cell's style.
 */
@interface TKCalendarCellStyle : TKStyleNode

/**
 The calendar cell text inset.
 */
@property (nonatomic) UIEdgeInsets textInsets;

/**
 The calendar cell text font.
 */
@property (nonatomic, strong) UIFont * __nullable textFont;

/**
 The calendar cell text color.
 */
@property (nonatomic, strong) UIColor * __nullable textColor;

/**
 The calendar cell text alignment.
 
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
@property (nonatomic) TKCalendarCellAlignment textAlignment;

/**
 The cell background color.
 */
@property (nonatomic, strong) UIColor * __nullable backgroundColor;

/**
 The cell left border color. If set to nil, no left border will be displayed.
 */
@property (nonatomic, strong) UIColor * __nullable leftBorderColor;

/**
 The cell right border color. If set to nil, no right border will be displayed.
 */
@property (nonatomic, strong) UIColor * __nullable rightBorderColor;

/**
 The cell top border color. If set to nil, no top border will be displayed.
 */
@property (nonatomic, strong) UIColor * __nullable topBorderColor;

/**
 The cell bottom border color. If set to nil, no bottom border will be displayed.
 */
@property (nonatomic, strong) UIColor * __nullable bottomBorderColor;

/**
 The left border width.
 */
@property (nonatomic) CGFloat leftBorderWidth;

/**
 The top border width.
 */
@property (nonatomic) CGFloat topBorderWidth;

/**
 The right border width.
 */
@property (nonatomic) CGFloat rightBorderWidth;

/**
 The bottom border width.
 */
@property (nonatomic) CGFloat bottomBorderWidth;

/**
 The cell shape. It is always centered within the cell.
 If its size is set to zero, it will be calculated automatically to wrap the cell text inside.
 */
@property (nonatomic, strong) TKShape * __nullable shape;

/**
 The the cell shape fill.
 */
@property (nonatomic, strong) TKFill * __nullable shapeFill;

/**
 The cell shape stroke.
 */
@property (nonatomic, strong) TKStroke * __nullable shapeStroke;

@end
