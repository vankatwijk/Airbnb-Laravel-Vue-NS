//
//  TKChartRangeVisualPoint.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKChartVisualPoint.h"

/**
  @discussion Represents a visual point rendered by TKChart rage bar/column series.
 */
@interface TKChartRangeVisualPoint : TKChartVisualPoint

/**
 The low coordinate of the visual point.
 */
@property (nonatomic) CGFloat low;

/**
 The high coordinate of the visual point.
 */
@property (nonatomic) CGFloat high;

/**
 Creates a range visual point.
 @param point The center coordinates of the visual point.
 @param low The low coordinate of the visual point.
 @param high The high coordinate of the visual point.
 */
- (instancetype)initWithPoint:(CGPoint)point low:(CGFloat)low high:(CGFloat)high;

@end
