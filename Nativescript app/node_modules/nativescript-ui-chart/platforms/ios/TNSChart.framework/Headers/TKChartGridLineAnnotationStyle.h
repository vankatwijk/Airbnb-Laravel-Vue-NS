//
//  TKChartLineAnnotationStyle.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartAnnotationStyle.h"

@class TKStroke;

/**
 A grid line's style.
 */
@interface TKChartGridLineAnnotationStyle : TKChartAnnotationStyle

/**
 The horizontal line stroke.
 */
@property (nonatomic, strong) TKStroke * __nullable stroke;

@end
