//
//  TKStyleGroupProperty.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

/**
 @discussion Represents a metadata class that stores the property's value.
 */
@interface TKStyleGroupProperty : NSObject

/**
 The value of the property.
 */
@property (nonatomic, strong) id value;

/**
 Determines whether the property value should be set by using the setKeyValue method.
 */
@property (nonatomic, assign) BOOL isKeyPath;

@end
