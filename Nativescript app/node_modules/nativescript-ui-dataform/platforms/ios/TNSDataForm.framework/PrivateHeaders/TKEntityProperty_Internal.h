//
//  TKEntityProperty_Internal.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKEntityProperty.h"

extern NSString *const kPropertyAnnotationNameKey;
extern NSString *const kPropertyAnnotationTypeKey;
extern NSString *const kPropertyAnnotationDisplayNameKey;
extern NSString *const kPropertyAnnotationGroupNameKey;
extern NSString *const kPropertyAnnotationIndexKey;
extern NSString *const kPropertyAnnotationIgnoreKey;
extern NSString *const kPropertyAnnotationReadOnlyKey;
extern NSString *const kPropertyAnnotationRequiredKey;
extern NSString *const kPropertyAnnotationErrorKey;
extern NSString *const kPropertyAnnotationSuccessKey;
extern NSString *const kPropertyAnnotationHintTextKey;
extern NSString *const kPropertyAnnotationEditorKey;
extern NSString *const kPropertyAnnotationValuesProviderKey;
extern NSString *const kPropertyAnnotationOriginalValueKey;
extern NSString *const kPropertyAnnotationDateFormat;

extern NSString *const kPropertyAnnotationTextFieldKey;
extern NSString *const kPropertyAnnotationEmailEditorKey;
extern NSString *const kPropertyAnnotationPasswordEditorKey;
extern NSString *const kPropertyAnnotationPhoneEditorKey;
extern NSString *const kPropertyAnnotationDecimalEditorKey;
extern NSString *const kPropertyAnnotationNumberEditorKey;
extern NSString *const kPropertyAnnotationSwitchKey;
extern NSString *const kPropertyAnnotationStepperKey;
extern NSString *const kPropertyAnnotationSliderKey;
extern NSString *const kPropertyAnnotationSegmentedEditorKey;
extern NSString *const kPropertyAnnotationDatePickerKey;
extern NSString *const kPropertyAnnotationTimePickerKey;
extern NSString *const kPropertyAnnotationPickerViewKey;
extern NSString *const kPropertyAnnotationOptionsEditorKey;

@class TKEntity;

@interface TKEntityProperty ()

@property (nonatomic, strong) id originalValue;

- (void)switchGroup:(NSString*)groupKey;

- (void)switchIndex:(NSUInteger)index;

- (void)switchPropertyClass:(Class)propertyClass;

- (void)switchPropertyType:(TKEntityPropertyType)type;

- (void)switchValid:(BOOL)isValid;

- (void)setupWithAnnotation:(NSDictionary *)annotation;

@end
