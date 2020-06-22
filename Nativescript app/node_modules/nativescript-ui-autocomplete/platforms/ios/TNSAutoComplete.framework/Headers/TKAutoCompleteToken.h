//
//  TKAutoCompleteToken.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKAutoCompleteTextView;

/**
 Represents token object model.
 */
@interface TKAutoCompleteToken : NSObject

/**
 The token id.
 */
@property (nonatomic, readonly) NSUInteger tokenId;

/**
 The token text.
 */
@property (nonatomic, copy, nullable) NSString *text;

/**
 The token attributed text.
 */
@property (nonatomic, strong, nullable) NSAttributedString *attributedText;

/**
 The token image.
 */
@property (nonatomic, strong, nullable) UIImage *image;

/**
 Initializes TKAutoCompleteToken.
 @param text The token text
 */
- (instancetype __nonnull)initWithText:(NSString* __nullable)text;

@end
