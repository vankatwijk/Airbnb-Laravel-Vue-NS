//
//  TKAutoCompleteCoverView.h
//  TelerikUI
//
//  Created by Sophia Lazarova on 12/22/15.
//  Copyright © 2015 Telerik. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
Contains the suggestion pop-up.
 */
@interface TKAutoCompleteCoverView : UIView

/**
 The rect which is supposed to be the target of the touch.
 If the touch point is outside that rect the event is transmitted to the subviews.
 */
@property(assign, nonatomic) CGRect visibleRect;

@end
