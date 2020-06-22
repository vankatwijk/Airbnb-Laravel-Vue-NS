//
//  TKStackLayout.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKLayout.h"
/**
 @enum TKStackLayoutAlignment
 @disucssion Alignement modes for TKStackLayout.
 */
typedef NS_ENUM(NSInteger, TKStackLayoutAlignment) {
    /**
     Stretches the views to fill the layout width/height.
     */
    TKStackLayoutAlignmentFill,
    
    /**
     Top alignment.
     */
    TKStackLayoutAlignmentTop,
    
    /**
     Center alignment.
     */
    TKStackLayoutAlignmentCenter,
    
    /**
     Bottom alignment.
     */
    TKStackLayoutAlignmentBottom,
    
    /**
     Alignes the views to the leading edge in vertical layout.
     */
    TKStackLayoutAlignmentLeading,
    
    /**
     Alignes the views to the trailing edge in vertical layout.
     */
    TKStackLayoutAlignmentTrailing
};

/**
 @enum TKStackLayoutDistribution
 @disussion Distribution modes for TKStackLayout.
 */
typedef NS_ENUM(NSInteger, TKStackLayoutDistribution){
    /**
     Does not change the size of the views that will be layed out.
     */
    TKStackLayoutDistributionNone,
    
    /**
     Arranges the views to fill the layout equally.
     */
    TKStackLayoutDistributionFillEqually,
    
    /**
     Arranges the views to fill the layout proportionally.
     */
    TKStackLayoutDistributionFillProportionally
};

/**
 @discussion A class that is able to arrange views in stack layout.
 */
@interface TKStackLayout : NSObject <TKLayout>

/**
 The rect in which the views will be arranged.
 */
@property (nonatomic) CGRect frame;

/**
 An array containing the views that will be layed out.
 */
@property (nonatomic, strong, readonly) NSArray *arrangedViews;

/**
 Layout's orientation.
 */
@property (nonatomic) TKLayoutOrientation orientation;

/**
 Stack layout's distribution.
 */
@property (nonatomic) TKStackLayoutDistribution distribution;

/**
 Stack layout's alignment.
 */
@property (nonatomic) TKStackLayoutAlignment alignment;

/**
 Spacing between the views.
 */
@property (nonatomic) CGFloat spacing;

/**
 Instantiates TKStackLayout object.
 @param frame The layout's frame.
 @return TKStackLayout instance.
 */
- (id)initWithFrame:(CGRect)frame;

/**
 Adds arranged view.
 @param view The view that will be added to the layout.
 */
- (void)addArrangedView:(UIView *)view;

/**
 Inserts arranged view.
 @param view The view that will be inserted.
 @param index The index at which the view will be inserted.
 */
- (void)insertArrangedView:(UIView *)view atIndex:(NSUInteger)index;

/**
 Removes arranged view.
 @param view The view that will be remove.
 */
- (void)removeArrangedView:(UIView *)view;

/**
 Removes all arranged views.
 */
- (void)removeAllArrangedViews;

/**
 Measures the size of the of the arranged views to fit in the specified size.
 @param size The size that the views must fit after arrangement.
 @return The optimal size to fit the desired size.
 */
- (CGSize)measurePreferredSizeThatFitsSize:(CGSize)size;

/**
 Updates the view with the corresponding layuout info.
 @param view The view that will be arranged.
 @param layoutInfo The layout info.
 */
- (void)arrangeView:(UIView *)view withLayoutInfo:(TKLayoutInfo *)layoutInfo;

/**
 Lays out the arranged views.
 */
- (void)layoutArrangedViews;

@end
