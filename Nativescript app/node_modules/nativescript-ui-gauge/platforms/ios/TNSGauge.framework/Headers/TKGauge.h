//
//  TKGauge.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TNSCore/TKView.h"

@class TKGaugeRange;
@class TKGaugeIndicator;
@class TKGaugeScale;
@class TKGauge;

/**
 @discussion The methods declared by the TKGaugeDelegate protocol allow the adopting delegate to respond to messages from TKGauge class. */
@protocol TKGaugeDelegate <NSObject>

@optional

/**
 This is being called every time TKGauge value is changed.
 @param gauge The gauge where the event was caused.
 @param value The new value.
 @param scale The particular scale that the value is changing for.
 */
- (void)gauge:(TKGauge* __nonnull)gauge valueChanged:(CGFloat)value forScale:(TKGaugeScale* __nonnull)scale;

/**
 Returns the text of a given label in the gauge.
 @param gauge The gauge where the event was caused.
 @param label The label.
 */
- (NSString* __nullable)gauge:(TKGauge* __nonnull)gauge textForLabel:(id __nonnull)label;

@end

/**
 A view visualizing the amount, value, content of some variable.
 */
@interface TKGauge : TKView

/**
 Represents the main label attached to the gauge.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel *labelTitle;

/**
 Represents the secondary label attached to the gauge.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel *labelSubtitle;

/**
 Determines the offset of the main labels attached to the gauge.
 */
@property (nonatomic) CGPoint labelTitleOffset;

/**
 Determines the offset of the secondary labels attached to the gauge.
 */
@property (nonatomic) CGPoint labelSubtitleOffset;

/**
 Represents the insets of the gauge view.
 */
@property (nonatomic) UIEdgeInsets insets;

/**
 Returns the bounds of the gauge view with insets.
 */
@property (nonatomic) CGRect rectWithInsets;

/**
 Represents TKGauge delegate.
 */
@property (nonatomic, weak, nullable) id<TKGaugeDelegate> delegate;

/**
 Contains all the scales in given TKGauge.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray<__kindof TKGaugeScale *>* scales;

/**
 Adds scale to TKGauge.
 @param scale The scale that will be added to the gauge.
 */
-(void)addScale:(TKGaugeScale* __nonnull)scale;

/**
 Removes scale from TKGauge.
 @param scale The scale that will be removed from the gauge.
 */
-(void)removeScale:(TKGaugeScale* __nonnull)scale;

/**
 Removes scale from TKGauge by index.
 @param index The index of the scale that will be removed from the gauge.
 */
-(void)removeScaleAtIndex:(int)index;

/**
 Inserts scale in TKGauge at given index.
 @param scale The scale to insert.
 @param index The index that the scale will be inserted to.
 */
-(void)insertScale:(TKGaugeScale* __nonnull)scale atIndex:(int)index;

/**
 Returns scale at given index.
 @param index The index of the scale that will be returned.
 */
-(TKGaugeScale* __nullable)scaleAtIndex:(int)index;

/**
 Removes all scales from TKGauge.
 */
-(void)removeAllScales;

@end
