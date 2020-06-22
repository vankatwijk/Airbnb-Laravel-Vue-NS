//
//  TKLayout.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//
@class TKLayoutInfo;
/**
 @enum TKLayoutOrientation
 @discussion Layout's orientation modes.
 */
typedef NS_ENUM(NSInteger, TKLayoutOrientation) {
    /**
     Horizontal orientation.
     */
    TKLayoutOrientationHorizontal,
    
    /**
     Vertical orientation.
     */
    TKLayoutOrientationVertical
};

/**
 @discussion Represents layouting information used by layout managers
 */
@protocol TKLayout <NSObject>
@required

/**
 The rect in which the views will be arranged.
 */
@property (nonatomic) CGRect frame;

/**
 Layout's orientation.
 */
@property (nonatomic) TKLayoutOrientation orientation;

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
 Updates the view with the corresponding layuout info.
 @param view The view that will be arranged.
 @param layoutInfo The layout info.
 */
- (void)arrangeView:(UIView *)view withLayoutInfo:(TKLayoutInfo *)layoutInfo;

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
 @return An array containing the views that will be layed out.
 */
- (NSArray *)arrangedViews;

/**
 Lays out the arranged views.
 */
- (void)layoutArrangedViews;

/**
 Measures the size of the of the arranged views to fit in the specified size.
 @param size The size that the views must fit after arrangement.
 @return The optimal size to fit the desired size.
 */
- (CGSize)measurePreferredSizeThatFitsSize:(CGSize)size;

@end
