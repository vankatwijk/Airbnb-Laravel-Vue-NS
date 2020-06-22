//
//  TKAccessoryView.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TKDataFormAccessoryView : UIView

@property (nonatomic, strong, readonly, nonnull) UIToolbar *toolbar;

@property (nonatomic, strong, readonly, nonnull) UIBarButtonItem *previousBarItem;

@property (nonatomic, strong, readonly, nonnull) UIBarButtonItem *nextBarItem;

@property (nonatomic, strong, readonly, nonnull) UIBarButtonItem *doneBarItem;

@end
