//
//  TKChartDataPoint.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartData.h"

/**
 @discussion The basic implementation of the TKChartData protocol.
 */
@interface TKChartDataPoint : NSObject<TKChartData>

/**
 X axis value.
 */
@property (nonatomic, strong, nullable) id dataXValue;

/**
 Y axis value.
 */
@property (nonatomic, strong, nullable) id dataYValue;

/**
 The name of the value (used in Pie/Donut Charts).
 */
@property (nonatomic, strong, nullable) NSString* dataName;

/**
 Creates a data point.
 @param xValue X axis value.
 @param yValue Y axis value.
 */
+ (instancetype __nonnull)dataPointWithX:(id __nullable)xValue Y:(id __nullable)yValue;

/**
 Creates a data point.
 @param xValue X axis value.
 @param yValue Y axis value.
 @param name The data point name (used in Pie/Donut Charts).
 */
+ (instancetype __nonnull)dataPointWithX:(id __nullable)xValue Y:(id __nullable)yValue name:(NSString * __nullable)name;

/**
 Creates a data point.
 @param xValue X axis value.
 @param yValue Y axis value.
 */
- (instancetype __nonnull)initWithX:(id __nullable)xValue Y:(id __nullable)yValue;

/**
 Creates a data point.
 @param xValue X axis value.
 @param yValue Y axis value.
 @param name The data point name (used in Pie/Donut Charts).
 */
- (instancetype __nonnull)initWithX:(id __nullable)xValue Y:(id __nullable)yValue name:(NSString * __nullable)name;


/** 
 Creates a data point that will be used in pie chart.
 @param name The data point name (used in Pie/Donut Charts).
 @param value The point value. By default, this sets the xvalue.
 */
- (instancetype __nonnull)initWithName:(NSString * __nullable)name value:(id __nullable)value;

@end
