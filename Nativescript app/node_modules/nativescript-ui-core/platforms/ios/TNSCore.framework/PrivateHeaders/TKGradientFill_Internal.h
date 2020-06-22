//
//  TKGradientFill_Internal.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@interface TKGradientFill ()
{
@protected
    NSMutableArray* _colorsMutable;
    CGColorSpaceRef _colorSpace;
    CGGradientRef _gradient;
    CGFloat* _locationsArray;
}

@end
