//
//  TKChartShapeView.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKChartPaletteItem;
@class TKShape;

@interface TKChartShapeView : UIView

- (instancetype __nonnull)initWithShape:(TKShape * __nonnull)shape andPaletteItem:(TKChartPaletteItem * __nonnull)paletteItem;

@property (nonatomic, strong) TKChartPaletteItem * __nonnull paletteItem;

@property (nonatomic, strong) TKShape * __nonnull shape;

@end
