//
//  TKDataFormEditorView.h
//  TelerikUI
//
//

#import <UIKit/UIKit.h>
#import "TNSCore/TKGridLayoutCellDefinition.h"
#import "TNSCore/TKMarginView.h"

/**
 @discussion A class that represents a segmented control.
 */
@interface TKDataFormEditorView : UIView<TKMarginView>

/**
 Insets for the control.
 */
@property (nonatomic) UIEdgeInsets insets;

/**
 A label for the editor.
 */
@property (nonatomic, weak) UILabel * __nullable label;

/**
 The editor's UIView.
 */
@property (nonatomic, weak) UIView * __nullable editorView;

/**
 The editor's accesory image.
 */
@property (nonatomic, weak) UIImageView * __nullable image;

/**
 The alignment of the label.
 */
@property (nonatomic) TKGridLayoutAlignment labelAlignment;

/**
 The offset of the label from the edge.
 */
@property (nonatomic) CGFloat labelOffset;

/**
 The alignment of the editor.
 */
@property (nonatomic) TKGridLayoutAlignment editorAlignment;

/**
 View margins.
 */
@property (nonatomic) UIEdgeInsets margins;

@end
