//
//  TKAxisView.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TNSCore/TKView.h"

@class TKView;
@class TKChartAxis;
@class TKChart;
@class TKChartAxisRender;
/**
 @discussion Represents the view of TKAxis.
 */
@interface TKChartAxisView : TKView

/**
 Insets the axis line.
 */
@property (nonatomic, assign) UIEdgeInsets lineInset;

/**
 The associated axis of the view.
 */
@property (nonatomic, strong, readonly) TKChartAxis* axis;

/**
 Initializes the associated axis view.
 @param axis The axis that will be associated with this view.
 */
- (instancetype)initWithAxis:(TKChartAxis*)axis inChart:(TKChart *)chart;

@end
