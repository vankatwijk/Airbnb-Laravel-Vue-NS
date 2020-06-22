//
//  TKDataFormValidator.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKEntityProperty;

/**
 A protocol used to validate values when using TKDataForm.
 */
@protocol TKDataFormValidator <NSObject>
@required

/**
 Returns a positive validation message.
 */
@property (nonatomic, strong, nullable) NSString *positiveMessage;

/**
 Returns error validation message.
 */
@property (nonatomic, strong, nullable) NSString *errorMessage;

/**
 Defines the validation logic for a specific property.
 @param property The property to validate.
 */
- (BOOL)validateProperty:(TKEntityProperty * __nonnull)property;

@end
