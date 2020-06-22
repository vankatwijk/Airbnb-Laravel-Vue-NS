//
//  TKCoreLayout.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

/**
 @enum TKLayoutStretchMode
 @discussion Defines the different stretching modes that can be used when arranging subviews in TKCoreStackLayout.
 */
typedef NS_ENUM(NSInteger, TKCoreLayoutStretchMode) {
    /**
     The subview should not stretch.
     */
    TKCoreLayoutStretchModeNone = 0,
    /**
     The subview should stretch horizontally and occupy the available area.
     */
    TKCoreLayoutStretchModeHorizontal = 1,
    /**
     The subview should stretch vertically and occupy the avaialable area.
     */
    TKCoreLayoutStretchModeVertical = 2
};

/**
 @enum TKLayoutAlignmentMode
 @discussion Defines the different alignment modes that can be used when arranging subviews in TKCoreStackLayout.
 */
typedef NS_OPTIONS(NSInteger, TKCoreLayoutAlignmentMode) {
    /**
     The subview should be aligned to the left.
     */
    TKCoreLayoutAlignmentModeLeft = 1,
    /**
     The subview should be aligned to the right.
     */
    TKCoreLayoutAlignmentModeTop  = 2,
    /**
     The subview should be aligned to the top.
     */
    TKCoreLayoutAlignmentModeRight = 4,
    /**
     The subview should be aligned to the bottom.
     */
    TKCoreLayoutAlignmentModeBottom = 8,
    /**
     The subview should be centered horizontally.
     */
    TKCoreLayoutAlignmentModeHorizontalCenter = 16,
    /**
     The subview should be centered vertically.
     */
    TKCoreLayoutAlignmentModeVerticalCenter = 32
};

/**
 Represents layouting information used by layout managers
 */
@protocol TKCoreLayout <NSObject>

/**
 Measures the size required by the layout item by using the provided size as a constraint.
 @param size The available size that could be used when arranging this item.
 @return The desired size that is required by this item.
 */
-(CGSize)measure:(CGSize)size;

/**
 Lays out the item within the provided rectangle.
 @param rect The rectangle that is provided to this item for arrange.
 */
-(void)arrange:(CGRect)rect;

@property (nonatomic,readonly) CGSize desiredSize;

@optional

/**
 The alignment mode that will be used when arranging the view.

 @discussion The alignment modes are defined as follows:
 
    typedef enum {
        TKCoreLayoutAlignmentModeLeft = 1,              // The subview should be aligned to the left.
        TKCoreLayoutAlignmentModeTop  = 2,              // The subview should be aligned to the right.
        TKCoreLayoutAlignmentModeRight = 4,             // The subview should be aligned to the top.
        TKCoreLayoutAlignmentModeBottom = 8,            // The subview should be aligned to the bottom.
        TKCoreLayoutAlignmentModeHorizontalCenter = 16, // The subview should be centered horizontally.
        TKCoreLayoutAlignmentModeVerticalCenter = 32    // The subview should be centered vertically.
    } TKCoreLayoutAlignmentMode;

 */
@property TKCoreLayoutAlignmentMode alignmentMode;

/**
 The streching mode that will be used when arranging the view.
 
 @discussion The stretch modes are defined as follows:
 
    typedef enum {
        TKCoreLayoutStretchModeNone = 0,        // The subview should not stretch.
        TKCoreLayoutStretchModeHorizontal = 1,  // The subview should stretch horizontally and occupy the available area.
        TKCoreLayoutStretchModeVertical = 2     // The subview should stretch vertically and occupy the avaialable area.
    } TKCoreLayoutStretchMode;

 */
@property TKCoreLayoutStretchMode stretchMode;

/**
 This method is being called when the item is removed from its owner layout.
 */
-(void)itemWasRemoved;

/**
 This method is being called when the item is added to a layout.
 @param layout The layout to which this item is being added.
 */
-(void)itemWasAddedInLayout:(id<TKCoreLayout>)layout;

@end

