//
//  TkChartAxisRender.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartRender.h"

@class TKChartAxis;

/**
 The rendering layer for TKChartAxis
 */
@interface TKChartAxisRender : TKChartRender

/**
 The associated axis of the render.
 */
@property (nonatomic, weak, readonly) TKChartAxis *axis;

/**
 Determines if the axis is vertical or horizontal.
 */
@property (nonatomic, readonly) BOOL isVertical;

/**
Returns the axis width and height.
@param size The size available for the axis.
*/
- (CGSize)sizeThatFits:(CGSize)size;

/**
 Initializes the associated axis view.
 @param axis The axis that will be associated with this render.
 @param chart The chart where this axis render resides.
 */
- (instancetype)initWithAxis:(TKChartAxis *)axis chart:(TKChart *)chart;

/**
 Returns the bound of the associated axis.
 */
-(CGRect)boundsRect;

@end