//
//  TKChartTrackballBalloonAnnotation.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartBalloonAnnotation.h"

@class TKChartTrackball;

/**
  The trackball tooltip pin positions.
 */
typedef NS_ENUM(NSInteger, TKChartTrackballPinPosition) {
    
    /**
     The tooltip appeara around the selected point.
     */
    TKChartTrackballPinPositionNone,
    
    /**
     The tooltip appeara at the left side of the plot area.
     */
    TKChartTrackballPinPositionLeft,
    
    /**
     The tooltip appears at the right side of the plot area.
     */
    TKChartTrackballPinPositionRight,
    
    /**
     The tooltip appeara at the top side of the plot area.
     */
    TKChartTrackballPinPositionTop,
    
    /**
     The tooltip appeara at the bottom side of the plot area.
     */
    TKChartTrackballPinPositionBottom,
    
};

/**
 A balloon annotation used with a trackball.
 */
@interface TKChartTrackballTooltipAnnotation : TKChartBalloonAnnotation

/**
 Initializes the annotation with a trackball.
 @param trackball The trackball which owns the annotation.
 */
- (instancetype __nonnull)initWithTrackball:(TKChartTrackball* __nonnull)trackball;

/**
 This method is called by the trackball when its visibility changes.
 */
- (void)updateContent;

/**
 The pin position for the tooltip.
 
 @discussion The available pin positions are specified below:
 
 typedef enum {
    TKChartTrackballPinPositionNone,   // The tooltip will appear around the selected point.
    TKChartTrackballPinPositionLeft,   // The tooltip will appear on the left side of the plot area.
    TKChartTrackballPinPositionRight,  // The tooltip will appear on the right side of the plot area.
    TKChartTrackballPinPositionTop,    // The tooltip will appear on the top side of the plot area.
    TKChartTrackballPinPositionBottom, // The tooltip will appear on the bottom side of the plot area.
 } TKChartTrackballPinPosition;
 
 */
@property (nonatomic, assign) TKChartTrackballPinPosition pinPosition;

@end
