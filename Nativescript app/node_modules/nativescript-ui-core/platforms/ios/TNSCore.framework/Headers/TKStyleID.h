//
//  TKStyleID.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

/**
 @discussion Represens an identifier of TKStyleGroup.
 */
@interface TKStyleID : NSObject

/**
 Initializes a style id for a particular class and state.
 @param aStylableClass The stylable class.
 @param aState The visual state of the object.
 */
- (instancetype __nonnull)initWithClass:(Class __nonnull)aStylableClass withState:(NSInteger)aState;

/**
 The stylable class TKStyleID is associated with.
 */
@property (nonatomic, strong, nonnull) Class stylableClass;

/**
 Defines a conditional class.
 */
@property (nonatomic, strong, nullable) Class conditionClass;

/**
 The visual state TKStyleID is associated with.
 */
@property (nonatomic, assign) NSInteger state;

@end
