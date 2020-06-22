//
//  TKChartPointLabel.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartData.h"

@class TKChartPointLabelStyle;
@class TKChartVisualPoint;
@class TKChartSeries;

/**
 Represents a point label.
 */
@interface TKChartPointLabel : NSObject

/**
 Point label's text.
 */
@property (nonatomic, copy) NSString * __nullable text;

/**
 Point label's style.
 */
@property (nonatomic, strong, readonly) TKChartSeries *  __nonnull series;

/**
 The corresponding data point.
 */
@property (nonatomic, strong, readonly) id<TKChartData>  __nullable dataPoint;

@property (nonatomic, strong, readonly) TKChartPointLabelStyle * __nonnull style;

/**
 Initializes the point label with a data point, style and text.
 @param point The corresponding data point.
 @param series The series to which the point belongs.
 @param text Point label's text.
 */
- (instancetype __nonnull)initWithPoint:(id<TKChartData>  __nonnull)point series:(TKChartSeries* __nonnull)series text:(NSString *  __nonnull)text;


/**
 Returns the point label's width and height.
 @param size The size available for the point label.
 */
- (CGSize)sizeThatFits:(CGSize)size;

/**
 Draws the point label in specified rect.
 @param ctx CGContext instance.
 @param bounds Point label's rect.
 @param visualPoint Point label's corresponding visual point.
 @param paletteTextColor The text color to be used.
 */
- (void)drawInContext:(CGContextRef __nonnull)ctx inRect:(CGRect)bounds forVisualPoint:(TKChartVisualPoint * __nullable)visualPoint color:(UIColor* __nullable)paletteTextColor;

@end
