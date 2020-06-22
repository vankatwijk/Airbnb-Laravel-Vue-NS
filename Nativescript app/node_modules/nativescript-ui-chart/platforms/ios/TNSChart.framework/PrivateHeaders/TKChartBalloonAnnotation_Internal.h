//
//  TKChartBalloonAnnotation_Internal.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartBalloonAnnotation.h"
#import "TKChartBalloonAnnotationStyle.h"

@class TKBalloonShape;

@interface TKChartBalloonAnnotation ()
{
@public
    TKBalloonShape *_shape;
    CGPoint _location;
    CGRect _bounds;
    CGPoint _originalLocation;
    CGRect _innerRect;
    TKChartBalloonVerticalAlignment _verticalAlign;
    TKChartBalloonHorizontalAlignment _horizontalAlign;
    __weak TKChart *_chart;

}

- (void)calcSize;
- (void)calcLocation:(TKChart*)chart inLayer:(CALayer*)layer;
- (void)correctPosition;

@end
