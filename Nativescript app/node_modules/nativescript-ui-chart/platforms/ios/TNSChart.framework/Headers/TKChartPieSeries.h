//
//  TKChartPieSeries.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartSeries.h"

@class TKChartPieSliceStyle;
@class TKChartLabelStyle;
@class TKRange;

/**
 Defines the labels' display mode in TKChartPieSeries.
 */
typedef NS_OPTIONS(NSInteger, TKChartPieSeriesLabelDisplayMode) {
    /**
     Show point labels inside the pie.
     */
    TKChartPieSeriesLabelDisplayModeInside = 1 << 0,
    /**
     Show point labels outside the pie.
     */
    TKChartPieSeriesLabelDisplayModeOutside = 1 << 1,
};

/**
 Represents TKChart pie series.
*/
@interface TKChartPieSeries : TKChartSeries

/**
 Determines the display mode of labels. By default, it is TKChartPieSeriesLabelDisplayModeName.
 
 @discussion The label display modes are defined as follows:
 
    typedef enum {
        TKChartPieSeriesLabelDisplayModeInside,         // Show point labels inside the pie.
        TKChartPieSeriesLabelDisplayModeOutside,        // Show point labels outside the pie.
    } TKChartPieSeriesLabelDisplayMode;

 */
@property (nonatomic, assign) TKChartPieSeriesLabelDisplayMode labelDisplayMode;

/**
  Determines if point labels should display data points percentage values.
 */
@property (nonatomic) BOOL displayPercentage;

/**
  The pie series radius. It is measured in logical coordinates between 0 and 1.
 */
@property (nonatomic, assign) CGFloat outerRadius;

/**
 The radius factor to which a pie slice will expand when selected. It is measured in logical coordinates between 0 and 1, relative to the pie radius.
 */
@property (nonatomic, assign) CGFloat expandRadius;

/**
  The start angle of the series. Use this property along with endAngle to define a pie segment that will be used to present all points in this series. By default, the startAngle property is 0 radians.
 */
@property (nonatomic, assign) CGFloat startAngle;

/**
  The end angle of the series. Use this property along with startAngle to define a pie segment that will be used to present all points in this series. By default, the endAngle property is 2*pi radians.
 */
@property (nonatomic, assign) CGFloat endAngle;

/**
  The pie rotation angle. The angle is measured in radians.
 */
@property (nonatomic, assign) CGFloat rotationAngle;

/**
  Indicates the rotation angle to be used when selecting a slice. The rotation angle is measured in radians. By default, this value is nil. It indicates that no rotation will happen when selecting an item.
 */
@property (nonatomic, strong) NSNumber * __nullable selectionAngle;

/**
 Defines the friction factor used when applying a rotation animation.
 */
@property (nonatomic, assign) CGFloat rotationDeceleration;

/**
 Defines inset for the radius of the pie.
 */
@property (nonatomic) CGFloat radiusInset;

/**
 Determines if pie rotation with gesture is enabled.
 */
@property (nonatomic) BOOL rotationEnabled;

/**
 Adjusts the pie chart size automatically to fit within available size when using expandRadius greather that 1.
 */
@property (nonatomic) BOOL adjustSizeToFit;

@end
