//
//  TKChartBalloonAnnotation.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartPointAnnotation.h"

@class TKBalloonShape;
@class TKChartBalloonAnnotationStyle;

/**
 A balloon annotation.
 */
@interface TKChartBalloonAnnotation : TKChartPointAnnotation

/**
 Initializes the annotation with a text.
 @param text The text that is displayed with this annotation.
 @param xValue The X coordinate of the annotation.
 @param yValue The Y coordinate of the annotation.
 @param series The TKChartSeries instance to use with these coordinates.
 */
- (instancetype __nonnull)initWithText:(NSString* __nonnull)text X:(id __nonnull)xValue Y:(id __nonnull)yValue forSeries:(TKChartSeries* __nonnull)series;

/**
 Initializes the annotation with a text.
 @param text The text that will be displayed with this annotation.
 @param point The location of the annotation.
 @param series The TKChartSeries instance to use with these coordinates.
 */
- (instancetype __nonnull)initWithText:(NSString * __nonnull)text point:(id<TKChartData> __nonnull)point forSeries:(TKChartSeries * __nonnull)series;

/**
 Initializes the annotation with a text, X-value, Y-value, X-axis and a Y-axis.
 @param text The text that is displayed with this annotation.
 @param xValue The X coordinate of the annotation.
 @param yValue The Y coordinate of the annotation.
 @param xAxis The X TKChartAxis instance to use with the X coordinate.
 @param yAxis The Y TKChartAxis instance to use with the Y coordinate.
 */
- (instancetype __nonnull)initWithText:(NSString* __nonnull)text X:(id __nonnull)xValue Y:(id __nonnull)yValue forXAxis:(TKChartAxis* __nonnull)xAxis forYAxis:(TKChartAxis * __nonnull)yAxis;

/**
 Initializes the annotation with a text, data point, X-axis and a Y-axis.
 @param text The text that will be displayed with this annotation.
 @param point The location of the annotation.
 @param xAxis The X TKChartAxis instance to use with the X coordinate of the provided data point.
 @param yAxis The Y TKChartAxis instance to use with the Y coordinate of the provided data point.
 */
- (instancetype __nonnull)initWithText:(NSString * __nonnull)text point:(id<TKChartData> __nonnull)point forXAxis:(TKChartAxis* __nonnull)xAxis forYAxis:(TKChartAxis * __nonnull)yAxis;


/**
 Initializes the annotation with a text.
 @param text The text that is displayed with this annotation.
 */
- (instancetype __nonnull)initWithText:(NSString * __nonnull)text;

/**
 The text that will be displayed with this annotation.
 */
@property (nonatomic, copy) NSString * __nullable text;

/**
 The attributed text that will be displayed with this annotation.
 When set, this property disables the effect of the text property.
 */
@property (nonatomic, strong) NSAttributedString * __nullable attributedText;

/**
 An optional view to display with this annotation.
 */
@property (nonatomic, strong) UIView * __nullable view;

/**
 The balloon size. The size is calculated automatically when this property is set to CGSizeEmpty (which is by default).
 */
@property (nonatomic, assign) CGSize size;

/**
 The annotation style. It can be used to customize the annotation appearance.
 */
@property (nonatomic, strong, readonly) TKChartBalloonAnnotationStyle *  __nonnull style;

@end
