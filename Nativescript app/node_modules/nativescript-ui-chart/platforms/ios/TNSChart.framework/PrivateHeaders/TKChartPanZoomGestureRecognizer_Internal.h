//
//  TKChartPanZoomGestureRecognizer_Internal.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import "TKChartPanZoomGestureRecognizer.h"

@interface TKChartPanZoomGestureRecognizer ()

@property (nonatomic) BOOL decelerating;

- (void)stopDeceleration;

@end
