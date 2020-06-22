//
//  TKChartPieVisualPoint.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartVisualPoint.h"

/**
 @discussion Represents the visual point rendered by TKChart pie series.
 */
@interface TKChartPieVisualPoint : TKChartVisualPoint

/**
 The distance from pie's center.
 */
@property (nonatomic) CGFloat distanceFromCenter;

/**
 The start angle of the point.
 */
@property (nonatomic) CGFloat startAngle;

@end
