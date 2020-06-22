//
//  TKDataFormViewControllerEditor.h
//  TelerikUI
//
//  Created by Tsvetan Raikov on 1/5/16.
//  Copyright © 2016 Telerik. All rights reserved.
//

#import "TKDataFormEditor.h"

/**
 An editor view which allows editing values by presenting them with a different view controller.
 */
@interface TKDataFormViewControllerEditor : TKDataFormEditor

/**
 Called by TKDataForm to present a new view controller.
 */
- (void)presentViewController;

/**
 Creates a new editor view controller.
 */
- (UIViewController*)createViewController;

@end
