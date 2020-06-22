//
//  TKDataFormManualValidator.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TKDataFormPropertyValidator.h"

@class TKDataFormManualValidator;

/**
 @discussion The methods declared by the TKDataFormValidationProviderDelegate protocol allow the the usage of a custom validators in TKDataForm.
 */
@protocol TKDataFormValidationProviderDelegate <NSObject>

@required
/**
 Called when a property value should to be validated by the validator.
 @param validator The manual validator that should validate the value.
 @param property The value that should be validated.
 */
- (BOOL)validator:(TKDataFormManualValidator* __nonnull)validator willValidate:(TKEntityProperty* __nonnull)property;
@end

@interface TKDataFormManualValidator : TKDataFormPropertyValidator

/**
 A delegate for the validator to validate values.
 */
@property (nonatomic, weak, nullable) id<TKDataFormValidationProviderDelegate> delegate;

@end
