//
//  TKCalendarPresenterBase_Internal.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendarPresenterBase.h"
#import "TKViewTransition_Internal.h"

@interface TKCalendarPresenterBase ()

- (TKCalendar*)owner;

- (NSDate*)nextDate;

- (NSDate*)prevDate;

- (BOOL)isDateBefore:(NSDate*)date;

- (BOOL)isDateSelectable:(NSDate*)date;

- (void)navigateToDate:(NSDate *)date animated:(BOOL)animated;

@end

@interface TKCalendarPresenterBase () <TKViewTransitionDelegate>

- (UIImage*)takeScreenshot:(CGRect)frame;

- (void)pan:(UIPanGestureRecognizer*)recognizer;

- (void)tap:(UITapGestureRecognizer*)recognizer;

- (TKViewTransition*)createTransition:(CGRect)frame;

- (CGRect)getTransitionFrame;

@end
