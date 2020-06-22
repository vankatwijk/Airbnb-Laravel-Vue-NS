//
//  TKChartAnnotation_Internal.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartAnnotation.h"

@class TKStyleSheet;
@class TKStyleNode;

/**
 An extension of the TKChartAnnotation class.
 */
@interface TKChartAnnotation ()

/**
 The style sheet of the annotation.
 */
@property (nonatomic, strong) TKStyleSheet *styleSheet;

/**
 Gets the TKStyleNode instance which represents the current annotation style.
 */
-(TKStyleNode*)getStyleNode;

@end