//
//  TKCalendarDayViewEventCellStyle.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"

/**
 @discussion A class that represents TKCalendarDayViewEventCell style.
 */
@interface TKCalendarDayViewEventCellStyle : TKStyleNode

/**
 The view margins.
 */
@property (nonatomic) UIEdgeInsets insets;

/**
 The width of the event view decoration.
 */
@property (nonatomic) CGFloat decorationWidth;

/**
 The margin of the event title.
 */
@property (nonatomic) UIEdgeInsets titleInsets;

/**
 The margin of the event details.
 */
@property (nonatomic) UIEdgeInsets detailInsets;

/**
 The text color for the title and decotration labels.
 */
@property (nonatomic, strong, nonnull) UIColor * textColor;

/**
 The font of the title label.
 */
@property (nonatomic, strong, nonnull) UIFont * titleFont;

/**
 The font of the detail label.
 */
@property (nonatomic, strong, nonnull) UIFont * detailFont;

/**
 The maximum number of lines of the title label. Set to 0 to remove the limit.
 */
@property (nonatomic) NSInteger titleNumberOfLines;

/**
 The maximum number of lines of the detail label. Set to 0 to remove the limit.
 */
@property (nonatomic) NSInteger detailNumberOfLines;

/**
 Transparency of the event background.
 */
@property (nonatomic) CGFloat transparency;


@end
