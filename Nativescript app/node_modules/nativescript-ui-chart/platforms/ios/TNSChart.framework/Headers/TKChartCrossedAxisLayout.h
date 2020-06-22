//
//  TKChartCrossedAxisLayout.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartAxis.h"
#import "TNSCore/TKCoreLayout.h"

@class TKChartAxis;
@class TKChartAxisView;

/**
 Defines a layout of crossed axis.
 */
@interface TKChartCrossedAxisLayout : NSObject<TKCoreLayout>

@property (nonatomic, strong, readonly, nonnull) NSArray <__kindof TKChartAxis* >* axes;

/**
 Initializes the layout with a view.
 * @param view The view.
 */
- (instancetype __nonnull)initWithView:(UIView* __nonnull)view;

/**
 Adds an axis crossed with another axis.
 @param axisView The axis view.
 @param baselineAxisView The crossed axis view.
 */
- (BOOL)addAxis:(TKChartAxisView * __nonnull)axisView withBaselineAxis:(TKChartAxisView * __nonnull)baselineAxisView;

/**
 Removes all axes.
 */
- (void)removeAxes;

@end
