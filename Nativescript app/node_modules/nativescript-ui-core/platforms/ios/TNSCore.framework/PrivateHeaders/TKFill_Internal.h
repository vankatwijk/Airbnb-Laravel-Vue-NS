//
//  TKFill_Internal.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//


/**
 * @discussion TKFill extension
 */
@interface TKFill ()
{
@public
    CGSize _cornerRadii;
    UIRectCorner _corners;
}

/**
 Insets a rectangle
 */
- (CGRect)insectRect:(CGRect)rect;

@end
