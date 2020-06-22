//
//  TKChartCrossLineAnnotation.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartPointAnnotation.h"

@class TKChartCrossLineAnnotationStyle;

/**
 A crossed line annotation.
 */
@interface TKChartCrossLineAnnotation : TKChartPointAnnotation

/**
 The annotation style. It can be used to customize the annotation appearance.
 */
@property (nonatomic, strong, readonly) TKChartCrossLineAnnotationStyle*  __nonnull style;

@end
