//
//  TKChartBarColumnBand.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKChartSeries;

@interface TKChartBarColumnBand : NSObject

@property (nonatomic, weak) TKChartSeries *series;

@property (nonatomic) NSUInteger dataIndex;

@property (nonatomic) CGRect bounds;

@property (nonatomic) CGFloat opacity;

@property (nonatomic) CGFloat scaleFactor;

@end
