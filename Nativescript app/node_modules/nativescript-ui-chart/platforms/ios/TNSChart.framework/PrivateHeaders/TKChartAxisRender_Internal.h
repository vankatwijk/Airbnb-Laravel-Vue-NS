//
//  TKChartAxisRender_Internal.h
//  TelerikUI
//
//  Copyright (c) 2015 г. Telerik. All rights reserved.
//

#import "TKChartAxisRender.h"

@interface TKChartAxisRender ()

@property (nonatomic) CGFloat clipWidth;

@property (nonatomic) CGFloat clipHeight;

@property (nonatomic, readonly) CGSize titleSize;

@property (nonatomic, readonly) CGFloat ticksBarSize;

@property (nonatomic, readonly) CGFloat labelsBarSize;

@property (nonatomic, readonly) CGSize titleShadowOffset;

@property (nonatomic, readonly) BOOL isMultiline;

@property (nonatomic, readonly, strong) NSDictionary* labelAttributes;

@property (nonatomic, readonly) CGSize originalTitleSize;

@property (nonatomic, readonly, strong) NSDictionary * titleAttributes;

@property (nonatomic, readonly) CGFloat initialSize;

@property (nonatomic, readonly) UIEdgeInsets insets;

@property (nonatomic, readonly) CGFloat lineSize;



@end