//
//  TKChartRender_Internal.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartRender.h"

@interface TKChartRender()
{
@public
    __weak TKChart *_chart;
}

/**
 Indicates that the render is initialized
 */
@property (nonatomic, assign, readonly) BOOL initialized;

@end