//
//  TKView_Internal.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKView.h"

@class TKFill;
@class TKStroke;
@protocol TKCoreLayout;

@interface TKView ()
{
@protected
    TKFill *_fill;
    TKStroke *_stroke;
    id<TKCoreLayout> _layout;
}

@end



