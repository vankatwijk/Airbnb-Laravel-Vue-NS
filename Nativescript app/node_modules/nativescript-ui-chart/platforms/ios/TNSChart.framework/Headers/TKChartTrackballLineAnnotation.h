//
//  TKChartTrackballLineAnnotation.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartAnnotation.h"

@class TKChartTrackball;
@class TKChartCrossLineAnnotationStyle;

/**
 A crossed line annotation that is used with a trackball.
 */
@interface TKChartTrackballLineAnnotation : TKChartAnnotation

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
 The selected points that will be presented with this annotation.
 */
@property (nonatomic, strong) NSArray * __nullable selectedPoints;

/**
  The annotation style. It can be used to customize the annotation appearance.
 */
@property (nonatomic, strong) TKChartCrossLineAnnotationStyle* __nonnull style;

@end
