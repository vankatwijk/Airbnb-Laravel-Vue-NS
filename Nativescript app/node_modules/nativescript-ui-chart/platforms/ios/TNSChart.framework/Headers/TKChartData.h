//
//  TKChartData.h
//
//  Copyright (c) 2013 Telerik. All rights reserved.
#import "TKChartAxis.h"

/**
 * @discussion Represents a data provider protocol for chart's series
 */
@protocol TKChartData <NSObject>

@required

/**
 Returns an x-value in cartesian series. It is used as a value for pie series.
*/
@property (nonatomic, strong, readonly) id dataXValue;

/**
 Returns a y-value in cartesian series.
 */
@property (nonatomic, strong, readonly) id dataYValue;

@optional

/**
 The name for a pie.
 */
@property (nonatomic, strong, readonly) NSString *dataName;

/**
 The value of the bubble area for bubble series.
 */
@property (nonatomic, strong, readonly) NSNumber *area;

/**
 Open price value for financial series.
 */
@property (nonatomic, strong, readonly) NSNumber *open;

/**
 High price value for financial series.
 */
@property (nonatomic, strong, readonly) NSNumber *high;

/**
 Low price value for financial series.
 */
@property (nonatomic, strong, readonly) NSNumber *low;

/**
 Close price value for financial series.
 */
@property (nonatomic, strong, readonly) NSNumber *close;

/**
 Volume value for financial series.
 */
@property (nonatomic, strong, readonly) NSNumber *volume;

/**
 The y axis value for indicator signal line
 */
@property (nonatomic, strong, readonly) id signalYValue;

/**
 Returns a string representation of the current implementation.
 */
-(NSString*) generateStringRepresentationForXAxis:(TKChartAxis *)xAxis yAxis:(TKChartAxis *)yAxis;

@end
