//
//  TKCalendarPresenterBase.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendar.h"

@class TKViewTransition;

/**
 @enum TKCalendarTransition
 @discussion Defines the transition effects available in calendar presenters.
 */
typedef NS_ENUM(NSInteger, TKCalendarTransitionMode) {
    
    /**
     No tranisition effect.
     */
    TKCalendarTransitionModeNone,
    
    /**
     Flip transition effect.
     */
    TKCalendarTransitionModeFlip,
    
    /**
     Fold transition effect.
     */
    TKCalendarTransitionModeFold,
    
    /**
     Float transition effect.
     */
    TKCalendarTransitionModeFloat,
    
    /**
     Card transition effect.
     */
    TKCalendarTransitionModeCard,
    
    /**
     Rotate transition effect.
     */
    TKCalendarTransitionModeRotate,
    
    /**
     Scroll transition effect.
     */
    TKCalendarTransitionModeScroll,
    
};

/**
 @discussion The methods declared by the TKCalendarPresenterDelegate protocol allow the adopting delegate to handle notifications from the calendar presenter.
 */
@protocol TKCalendarPresenterDelegate <NSObject>

@optional

/**
 Called when the presenter is about to start a transition.
 *
 @param presenter The presenter in which this event occurred.
 @param transition The transition that is about to start.
 */
- (void)presenter:(id<TKCalendarPresenter> __nonnull)presenter beginTransition:(TKViewTransition* __nonnull)transition;

/**
 *  Called when the presenter finished a transition.
 *
 *  @param presenter The presenter in which this event occurred.
 *  @param transition The finishing transition. 
 *  @param canceled  A value indicating whether the transition was canceled.
 */
- (void)presenter:(id<TKCalendarPresenter> __nonnull)presenter finishTransition:(TKViewTransition* __nonnull)transition isCanceled:(BOOL)canceled;

@end

/**
 @discussion A base class for different view mode presenters in TKCalendar view.
 */
@interface TKCalendarPresenterBase : UIView <TKCalendarPresenter>

/**
 A delegate for handling presenter notifications.
 */
@property (nonatomic, weak, nullable) id<TKCalendarPresenterDelegate> delegate;

/**
 The transition effect.

 @discussion The available transition effects are specified below:

 typedef enum {
 TKCalendarTransitionModeNone,      // No transition will be applied.
 TKCalendarTransitionModeFlip,      // Flip transition.
 TKCalendarTransitionModeFold,      // Fold transition.
 TKCalendarTransitionModeFloat,     // Float transition.
 TKCalendarTransitionModeCard,      // Card transition.
 TKCalendarTransitionModeRotate,    // Rotate transition.
 TKCalendarTransitionModeScroll,    // Scroll transition.
 } TKCalendarTransitionMode
 
 */
@property (nonatomic) TKCalendarTransitionMode transitionMode;

/**
 Defines whether the transition is vertical or horizontal.
 */
@property (nonatomic) BOOL transitionIsVertical;

/**
 Defines whether to reverse the transition direction (forward or backward).
 */
@property (nonatomic) BOOL transitionIsReverse;

/**
 *  Gets or sets the transition duration.
 */
@property (nonatomic) NSTimeInterval transitionDuration;

/**
 Defines a threshold (in points) for the pan gesture.
 */
@property (nonatomic) CGFloat panGestureSensitivity;

@end
