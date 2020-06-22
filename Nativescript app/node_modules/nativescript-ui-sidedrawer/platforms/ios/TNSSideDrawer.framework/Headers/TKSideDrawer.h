//
//  TKSideDrawer.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerk Inc. All rights reserved.
//

#import "TNSCore/TKView.h"

@class TKSideDrawerItem;
@class TKSideDrawerController;
@class TKSideDrawerTransition;
@class TKSideDrawerStyle;
@class TKSideDrawerSection;
@class TKTheme;
@protocol TKSideDrawerDelegate;
@class TKSideDrawerTableViewCell;

/**
 @enum TKSideDrawerTransitionType
 @discussion Represents an enum that defines TKSideDrawer's transition type.
 */
typedef NS_ENUM(NSInteger, TKSideDrawerTransitionType) {
    
    /**
     TKSideDrawer slides on top of its hostview.
     */
    TKSideDrawerTransitionTypeSlideInOnTop,
    
    /**
     TKSideDrawer reveals underneath its hostview.
     */
    TKSideDrawerTransitionTypeReveal,
    
    /**
     TKSideDrawer pushes its hostview.
     */
    TKSideDrawerTransitionTypePush,
    
    /**
     TKSideDrawer slides along with its hostview.
     */
    TKSideDrawerTransitionTypeSlideAlong,
    
    /**
     TKSideDrawer slides opposite to its hostview.
     */
    TKSideDrawerTransitionTypeReverseSlideOut,
    
    /**
     TKSideDrawer scales up to its final position.
     */
    TKSideDrawerTransitionTypeScaleUp,
    
    /**
     TKSideDrawer fades in over its hostview.
     */
    TKSideDrawerTransitionTypeFadeIn,
    
    /**
     TKSideDrawer's hostview scales down revealing it.
     */
    TKSideDrawerTransitionTypeScaleDownPusher,
    
    /**
     TKSideDrawer is shown/dismissed by a custom transition.
     */
    TKSideDrawerTransitionTypeCustom
};

/**
 @enum TKSideDrawerPosition
 @discussion Represents an enum that defines TKSideDrawer's position.
 */
typedef NS_ENUM(NSInteger, TKSideDrawerPosition) {
    
    /**
     Left postion.
     */
    TKSideDrawerPositionLeft,
    
    /**
     Right postion.
     */
    TKSideDrawerPositionRight,
    
    /**
     Top postion.
     */
    TKSideDrawerPositionTop,
    
    /**
     Bottom postion.
     */
    TKSideDrawerPositionBottom
};

/**
 TKSideDrawer extends the popular slide-out menu design pattern which is mainly associated with navigational purposes. The control allows for embedding any content inside the sliding view from text and icons to sliders and filters. The control is revealed when the end-user swipes a finger from the left/right/top/bottom edge of the screen or when the user touches the menu icon in the navigation bar.

 <img src="../docs/images/sidedrawer-overview001.png">
 
 @see [TKSideDrawer Overview](sidebar-overview)
 @see [Customizing TKSideDrawer appearance](sidebar-customizing)
 */
@interface TKSideDrawer : TKView

/**
 TKSideDrawer's content. If not set, it is an instance of TKSideDrawerTableView.
 */
@property (nonatomic, strong) UIView *content;

/**
 TKSideDrawer's theme.
 */
@property (nonatomic, strong) TKTheme *theme;

/**
 Determines if scrolling is enabled.
 */
@property (nonatomic) BOOL allowScroll;

/**
 Allows canceling the current show/dismiss transition.
 */
@property (nonatomic) BOOL cancelTransition;

/**
 Determines if sidebar should be shown with edge swipe.
 */
@property (nonatomic) BOOL allowEdgeSwipe;

/**
 Treshold used to determine if a swipe should be considered edge swipe.
 */
@property (nonatomic) CGFloat edgeSwipeTreshold;

/**
 Determines if TKSideDrawer should respond to gestures.
 */
@property (nonatomic) BOOL allowGestures;

/**
 TKSideDrawer's title used by the default header view.
 */
@property (nonatomic, copy) NSString *title;

/**
 Determines the edge of the screen from which TKSideDrawer will appear.
 */
@property (nonatomic) TKSideDrawerPosition position;

/**
 The width of TKSideDrawer's view.
 */
@property (nonatomic) CGFloat width;

/**
 The transition object responsible used to display or hide the Sidebar panel. Setting your own TKSideDrawerTransition descendant will allow you to use your own custom transition.
 */
@property (nonatomic, strong) TKSideDrawerTransition *transitionManager;

/**
 The transition effect used to display or hide the TKSideDrawer view.
 */
@property (nonatomic) TKSideDrawerTransitionType transition;

/**
 The duration of the show/dismiss animation.
 */
@property (nonatomic) CGFloat transitionDuration;

/**
 Returns the header view.
 */
@property (nonatomic, strong) UIView *headerView;

/**
 Returns TKSideDrawer's footer view.
 */
@property (nonatomic, strong) UIView *footerView;

/**
 TKSideDrawer's delegate
 */
@property (nonatomic, weak) id<TKSideDrawerDelegate> delegate;

/**
 Returns the sidebar style. Use the style properties to customize the visual appearance of TKSideDrawer.
 */
@property (nonatomic, strong, readonly) TKSideDrawerStyle *style;

/**
 Returns the host view. A host view is the view at which the TKSideDrawer appears. Depending on the transition effect, the host view is pushed, covered, etc. by the TKSideDrawer view.
 */
@property (nonatomic, weak, readonly) UIView *hostview;

/**
 Determines if TKSideDrawer's view is displayed on screen.
 */
@property (nonatomic, readonly) BOOL isVisible;

/**
 Returns an array containing all TKSideDrawer sections.
 */
@property (nonatomic, strong, readonly) NSArray* sections;

/**
 Attaches tap, pan and edge pan  gesture handlers to the view.
 */
- (void)attachGesturesToView:(UIView *)view;

/**
 Detaches tap, pan and edge pan gesture handlers to the view.
 */
- (void)detachGesturesFromView:(UIView *)view;

/**
 Associates a TKSideDrawer with a UIViewController. Should be used only with a TKSideDrawerController.
 @param index The index of the requested side drawer.
 @param viewController The view controller TKSideDrawer will be associated with.
 */
+ (TKSideDrawer *)findSideDrawerAtIndex:(NSUInteger)index forViewController:(UIViewController *)viewController;

/**
 Displays a TKSideDrawer on sthe creen using the last active transition animation.
 */
- (void)show;

/**
 Displays a TKSideDrawer using the transition type.
 @param transition The transition that is used to display TKSideDrawer.
 */
- (void)showWithTransition:(TKSideDrawerTransitionType)transition;

/**
 Dismisses TKSideDrawer using the current active transition animation.
 */
- (void)dismiss;

/**
 Adds a section to TKSideDrawer.
 @param section The TKSideDrawerSection that will be added to TKSideDrawer.
 */
- (void)addSection:(TKSideDrawerSection *)section;

/**
 Adds a section to TKSideDrawer.
 @param title The title of the TKSideDrawerSection that will be added.
 @return The added TKSideDrawerSection.
 */
- (TKSideDrawerSection *)addSectionWithTitle:(NSString *)title;

/**
 Adds a section to the TKSideDrawer.
 @param title The title of the TKSideDrawerSection that is added.
 @param image The image of the TKSideDrawerSection that is added.
 @return The added TKSideDrawerSection.
 */
- (TKSideDrawerSection *)addSectionWithTitle:(NSString *)title image:(UIImage *)image;

/**
 Removes a section from TKSideDrawer.
 @param section The TKSideDrawerSection that is removed from TKSideDrawer.
 */
- (void)removeSection:(TKSideDrawerSection *)section;

/**
 Removes all sections from TKSideDrawer.
 */
- (void)removeAllSections;

/**
 Inserts a section in TKSideDrawer at a specified index.
 @param section TKSideDrawerSection that is inserted.
 @param index The index at which the section is inserted.
 */
- (void)insertSection:(TKSideDrawerSection *)section atIndex:(NSInteger)index;

/**
 Selects an item at specified index path.
 @param indexPath TKSideDrawerItem's index path.
 */
- (void)selectItemAtIndexPath:(NSIndexPath *)indexPath;

@end


/**
 @discussion The methods declared by the TKSideDrawerDelegate protocol allow the adopting delegate to respond to messages from the TKSideDrawer class and thus respond to different operations such as showing and dismissing TKSideDrawer.
 */
@protocol TKSideDrawerDelegate <NSObject>

@optional
/**
 Called when an item inside TKSideDrawer is selected.
 @param sideDrawer TKSideDrawer instance which item is selected.
 @param indexPath The index path of the selected item.

 */
- (void)sideDrawer:(TKSideDrawer *)sideDrawer didSelectItemAtIndexPath:(NSIndexPath *)indexPath;

/**
 Called just before TKSideDrawer instance becomes visible.
 @param sideDrawer The TKSideDrawer instance which is presented.
 */
- (void)willShowSideDrawer:(TKSideDrawer *)sideDrawer;

/**
 Called when TKSideDrawer is already visible.
 @param sideDrawer The TKSideDrawer instance which is presented.
 */
- (void)didShowSideDrawer:(TKSideDrawer *)sideDrawer;

/**
 Called just before TKSideDrawer is dismissed.
 @param sideDrawer The TKSideDrawer that will be dismissed.
 */
- (void)willDismissSideDrawer:(TKSideDrawer *)sideDrawer;

/**
 Called after TKSideDrawer is dismissed.
 @param sideDrawer The TKSideDrawer instance that was dismissed.
 */
- (void)didDismissSideDrawer:(TKSideDrawer *)sideDrawer;

/**
 Called when TKSideDrawer is panning.
 @param sideDrawer The TKSideDrawer instance that is panning.
 */
- (void)didPanSideDrawer:(TKSideDrawer *)sideDrawer;

/**
 Returns a UIView that is used as header for section in TKSideDrawer.
 @param sideDrawer The TKSideDrawer instance that requeres section view.
 @param sectionIndex The index of the section in TKSideDrawer.
 @return The UIView is used for the header of the specified section.
 */
- (UIView *)sideDrawer:(TKSideDrawer *)sideDrawer viewForHeaderInSection:(NSInteger)sectionIndex;

/**
 Returns the height for a specific item in TKSideDrawer.
 @param sideDrawer The TKSideDrawer instance that requires the height for its items.
 @param indexPath The index path of the item.
 @return The height of the specified item.
 */
- (CGFloat)sideDrawer:(TKSideDrawer *)sideDrawer heightForItemAtIndexPath:(NSIndexPath *)indexPath;

/**
 Called just before an item is rendered.
 @param sideDrawer The TKSideDrawer instance that is presented.
 @param indexPath The index path of the item to be updated.
 */
- (void)sideDrawer:(TKSideDrawer *)sideDrawer updateVisualsForItemAtIndexPath:(NSIndexPath *)indexPath;

/**
 Called just before a section is rendered.
 @param sideDrawer The TKSideDrawer instance that is presented.
 @param sectionIndex The index of the section to be updated.
 */
- (void)sideDrawer:(TKSideDrawer *)sideDrawer updateVisualsForSection:(NSInteger)sectionIndex;

/**
 Returns the TKSideDrawerTableViewCell that is used to display a specified item.
 @param sideDrawer The TKSideDrawer instance that requests the cell.
 @param indexPath The index path of the item that the cell visualizes.
 */
- (TKSideDrawerTableViewCell *)sideDrawer:(TKSideDrawer *)sideDrawer cellForItemAtIndexPath:(NSIndexPath *)indexPath;
@end

@interface UIViewController (TKSideDrawer)

@property (nonatomic, readonly, strong) TKSideDrawer *sideDrawer;

@end

#ifdef DEBUG

@implementation UIViewController (TKSideDrawer)

- (TKSideDrawer *)sideDrawer
{
    return [TKSideDrawer findSideDrawerAtIndex:0 forViewController:self];
}

@end

#endif

