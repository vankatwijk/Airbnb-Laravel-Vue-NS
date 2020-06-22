//
//  TKChartGridRender.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartRender.h"

@class TKChartGridStyle;

/**
 @discussion TKChart grid renderer.
 */
@interface TKChartGridRender : TKChartRender

@property (nonatomic, strong) TKChartGridStyle *gridStyle;

@property (nonatomic, strong) TKStyleSheet *styleSheet;

@end
