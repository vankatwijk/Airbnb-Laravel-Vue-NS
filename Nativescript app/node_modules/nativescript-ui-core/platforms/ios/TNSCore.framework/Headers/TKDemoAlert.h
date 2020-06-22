//
//  TKDemoAlert.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

@interface TKDemoAlert : NSObject <UIAlertViewDelegate>

+ (TKDemoAlert *)sharedInstance;

+ (UILabel*)addDemo:(UIView*)view frame:(CGRect)frame;

+ (void)updateAlert:(UIView*)view frame:(CGRect)frame;

@end
