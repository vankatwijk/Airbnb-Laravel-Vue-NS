//
//  TKChartViewController.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@protocol TKChartDataSource;
@protocol TKChartDelegate;
@class TKChart;

@interface TKChartViewController : UIViewController<TKChartDataSource, TKChartDelegate>

@property (nonatomic, retain, readonly) TKChart * __nonnull chart;

@end
