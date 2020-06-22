//
//  TKChartFinancialDataPoint.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartDataPoint.h"

/**
 @discussion Represents a data point for financial series.
 */
@interface TKChartFinancialDataPoint : NSObject<TKChartData>

/**
 X axis value.
 */
@property (nonatomic, strong, nullable) id dataXValue;

/**
 Y axis value.
 */
@property (nonatomic, strong, nullable) id dataYValue;

/**
 Open price value.
 */
@property (nonatomic, strong, nullable) NSNumber *open;

/**
 High price value.
 */
@property (nonatomic, strong, nullable) NSNumber *high;

/**
 Low price value.
 */
@property (nonatomic, strong, nullable) NSNumber *low;

/**
 Close price value.
 */
@property (nonatomic, strong, nullable) NSNumber *close;

/**
 Volume value.
 */
@property (nonatomic, strong, nullable) NSNumber *volume;

/**
 The name.
 */
@property (nonatomic, strong, nullable) NSString *dataName;

/**
 Creates a financial data point.
 @param xValue X axis value.
 @param open Open price value.
 @param high High price value.
 @param low Low price value.
 @param close Close price value.
 @param volume Volume value.
 */
+ (instancetype __nonnull)dataPointWithX:(id __nullable)xValue open:(NSNumber * __nullable)open high:(NSNumber * __nullable)high low:(NSNumber * __nullable)low close:(NSNumber * __nullable)close volume:(NSNumber * __nullable)volume;

/**
 Creates a financial data point.
 @param xValue X axis value.
 @param open Open price value.
 @param high High price value.
 @param low Low price value.
 @param close Close price value.
 */
+ (instancetype __nonnull)dataPointWithX:(id __nullable)xValue open:(NSNumber * __nullable)open high:(NSNumber * __nullable)high low:(NSNumber * __nullable)low close:(NSNumber * __nullable)close;

/**
 Creates a financial data point.
 @param xValue X axis value.
 @param open Open price value.
 @param high High price value.
 @param low Low price value.
 @param close Close price value.
 @param volume Volume value.
 */
- (instancetype __nonnull)initWithX:(id __nullable)xValue open:(NSNumber * __nullable)open high:(NSNumber * __nullable)high low:(NSNumber * __nullable)low close:(NSNumber * __nullable)close volume:(NSNumber * __nullable)volume;

@end
