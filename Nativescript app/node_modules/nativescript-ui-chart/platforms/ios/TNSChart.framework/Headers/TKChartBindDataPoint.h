//
//  TKChartBindDataPoint.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartData.h"

@interface TKChartBindDataPoint : NSObject<TKChartData>

- (instancetype)initWithItem:(id)item forKeys:(NSDictionary *)keys;

/**
 X axis value.
 */
@property (nonatomic, strong, readwrite) id dataXValue;

/**
 Y axis value.
 */
@property (nonatomic, strong, readwrite) id dataYValue;

/**
 The name of the data point.
 */
@property (nonatomic, strong, readwrite) NSString* dataName;


/**
 * Binds model object properties to the TKChartData protocol.
 * @param item The model object.
 * @param keys The dictionary to describe yjr binding between the items properites and the properties of the TKChartData protocol.
 */
- (void)bind:(id)item forKeys:(NSDictionary *)keys;

@end
