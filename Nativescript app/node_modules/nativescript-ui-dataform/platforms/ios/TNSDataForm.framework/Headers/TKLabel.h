//
//  TKLabel.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TNSCore/TKMarginView.h"

/**
 @discussion A class that represents a label.
 */
@interface TKLabel : UILabel<TKMarginView>

/**
 Insets for the label's text.
 */
@property (nonatomic) UIEdgeInsets textInsets;

/**
 Margins for the label.
 */
@property (nonatomic) UIEdgeInsets margins;

@end
