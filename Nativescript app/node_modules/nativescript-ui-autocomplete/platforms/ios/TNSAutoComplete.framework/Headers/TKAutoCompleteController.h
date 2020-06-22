//
//  TKAutoCompleteController.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TKAutoCompleteTextView;

/**
 @discussion The container UIViewController that holds TKAutocompleteTextView instance.
 */

@interface TKAutoCompleteController : UIViewController

/**
 TKautoCompleteTextView instance
 */
@property(strong,nonatomic) TKAutoCompleteTextView *autocomplete;

@end
