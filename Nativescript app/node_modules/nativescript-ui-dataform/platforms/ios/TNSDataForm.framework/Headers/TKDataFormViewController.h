//
//  TKDataFormViewController.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataForm.h"

/**
 @discussion The TKDataFormViewController class represents a view controller whose content consists of a TKDataForm view.
 */
@interface TKDataFormViewController : UIViewController <TKDataFormDelegate, TKDataFormDataSource>

/**
 TKDataFormViewController's TKDataForm (read-only).
 */
@property (nonatomic, strong, readonly, nonnull) TKDataForm *dataForm;

@end
