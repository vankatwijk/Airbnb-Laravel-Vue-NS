//
//  TKBasicAnimation.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>

/*
 Subclass for basic animations. 
 */
@interface TKBasicAnimation : CABasicAnimation

/**
 Gets or sets a metadata for this animation
 */
@property (nonatomic, strong) id metadata;

@end
