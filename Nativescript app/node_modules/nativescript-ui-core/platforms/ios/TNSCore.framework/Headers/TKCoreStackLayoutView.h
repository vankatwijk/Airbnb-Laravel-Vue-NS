//
//  TKCoreStackLayoutView.h
//  TestLayout
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKCoreStackLayout.h"

/**
 @discussion A view that layouts its subviews by using a stack layout.
 */
@interface TKCoreStackLayoutView : UIScrollView

/**
 The stack layout used to arrange sub views in this view.
 */
@property (nonatomic, strong) TKCoreStackLayout *stack;

@end
