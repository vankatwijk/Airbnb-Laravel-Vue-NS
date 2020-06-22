//
//  TKCalendarDayViewAllDayEventCellStyle.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"

/**
 @discussion A class that represents TKCalendarDayViewAllDayEventCell style.
 */
@interface TKCalendarDayViewAllDayEventCellStyle : TKStyleNode

/**
 The background of the cell.
 */
@property (nonatomic, strong, nonnull)UIColor * backgroundColor;

/**
 The color of the cell's text.
 */
@property (nonatomic, strong, nonnull)UIColor * textColor;

/**
 The font of the cell's text.
 */
@property (nonatomic, strong, nonnull)UIFont * textFont;

/**
 The margins of the cell's text.
 */
@property (nonatomic)UIEdgeInsets textInsets;


@end
