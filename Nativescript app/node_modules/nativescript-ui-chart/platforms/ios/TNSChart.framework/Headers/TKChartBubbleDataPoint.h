//
//  TKChartBubbleDataPoint.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartDataPoint.h"

/**
 @discussion Represents a data point for bubble series.
 */
@interface TKChartBubbleDataPoint : NSObject<TKChartData>

/**
 X axis value.
 */
@property (nonatomic, strong, nullable) id dataXValue;

/**
 Y axis value.
 */
@property (nonatomic, strong, nullable) id dataYValue;

/**
 Bubble area value.
 */
@property (nonatomic, strong, nullable) NSNumber *area;

/**
 Creates a data point for bubble series.
 @param xValue X axis value.
 @param yValue Y axis value.
 @param area Bubble area value.
 */
+ (instancetype __nonnull)dataPointWithX:(id __nullable)xValue Y:(id __nullable)yValue area:(NSNumber * __nullable)area;

/**
 Creates a data point for bubble series.
 @param xValue X axis value.
 @param yValue Y axis value.
 @param area Bubble area value.
 */
- (instancetype __nonnull)initWithX:(id __nullable)xValue Y:(id __nullable)yValue area:(NSNumber * __nullable)area;

@end
