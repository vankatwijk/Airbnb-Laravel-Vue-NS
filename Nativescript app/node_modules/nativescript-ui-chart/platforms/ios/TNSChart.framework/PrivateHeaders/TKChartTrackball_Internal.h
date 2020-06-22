//
//  TKChartTrackball_Internal.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartTrackball.h"

/**
 The trackball used in TKChart.
 */
@interface TKChartTrackball ()
{
@public
    NSMutableArray *_selection;
    __weak TKChart *_chart;
}

- (BOOL)wasVisible;

@end
