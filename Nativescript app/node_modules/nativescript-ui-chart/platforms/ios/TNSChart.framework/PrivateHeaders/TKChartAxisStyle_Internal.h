//
//  TKChartAxisStyle_Internal.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartAxisStyle.h"

@class TKStyleSheet;

typedef NS_OPTIONS(NSInteger, TKChartAxisState)
{
    TKChartAxisStateVertical = 1 << 0
};


@interface TKChartAxisStyle ()

@property (nonatomic, strong) TKStyleSheet *styleSheet;

@end
