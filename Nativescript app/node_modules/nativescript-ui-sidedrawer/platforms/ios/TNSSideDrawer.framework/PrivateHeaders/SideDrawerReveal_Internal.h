//
//  SideDrawerReveal_Internal.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "SideDrawerReveal.h"

@interface SideDrawerReveal ()

- (void)setFinalPositions:(BOOL)didPanToEnd;

- (void)panWithTranslation:(CGPoint)translation vertical:(BOOL)isVertical;

- (void)prepareSideDrawer;

@end
