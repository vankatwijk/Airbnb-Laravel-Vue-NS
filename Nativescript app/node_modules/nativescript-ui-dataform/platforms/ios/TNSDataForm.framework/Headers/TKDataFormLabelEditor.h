//
//  TKDataFormLabelEditor.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TKDataFormEditor.h"

/**
 @discussion An editor displaying non-editable text. In its essence, it is a UILabel.
 */
@interface TKDataFormLabelEditor : TKDataFormEditor

/**
 The editor's UILabel control.
 */
@property (nonatomic, strong, readonly) UILabel *labelView;

@end
