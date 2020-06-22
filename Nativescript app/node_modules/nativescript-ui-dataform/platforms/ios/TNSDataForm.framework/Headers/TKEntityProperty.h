//
//  TKEntityProperty.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKEntity;
@class TKRange;
@class TKEntityPropertyLayoutInfo;
@protocol TKDataFormConverter;
@class TKLayoutInfo;

#import "TNSAutoComplete/TKAutoCompleteTextView.h"


/**
 @enum TKDataFormPropertyType
 @discussion An enum that defines the type of the property.
 */
typedef NS_ENUM(int, TKEntityPropertyType) {

    /**
     The property type is unknown.
     */
    TKEntityPropertyTypeUnknown,
    
    /**
     The property is of type NSNumber.
     */
    TKEntityPropertyTypeNumeric,
    
    /**
     The property is of type decimal number.
     */
    TKEntityPropertyTypeInteger,
    
    /**
     The property is of type floating point number.
     */
    TKEntityPropertyTypeDouble,
    
    /**
     The property is of type bool.
     */
    TKEntityPropertyTypeBool,
    
    /**
     The property is of type string.
     */
    TKEntityPropertyTypeString,
    
    /**
     The property is of type date.
     */
    TKEntityPropertyTypeDate,
};

/**
 @discussion This class represents a model of a property.
 */
@interface TKEntityProperty : NSObject

/**
 The TKDataFormEntity to which the property belongs (read-only).
 */
@property (nonatomic, weak, readonly) TKEntity *owner;

/**
 The name of the source property.
 */
@property (nonatomic, strong, readonly) NSString *name;

/**
 The type of the property.
 */
@property (nonatomic) TKEntityPropertyType type;

/**
 The type of the property.
 */
@property (nonatomic) TKAutoCompleteDisplayMode autoCompleteDisplayMode;

/**
 The class of the source property. Will be nil if it is a primitive (read-only).
 */
@property (nonatomic, strong, readonly) Class propertyClass;

/**
 The name that will be displayed in TKDataForm.
 */
@property (nonatomic, strong) NSString *displayName;

/**
 The name of the group to which this property will belong.
 */
@property (nonatomic) NSString *groupName;

/**
 The index at which a property will be placed in its group.
 */
@property (nonatomic) NSUInteger index;

/**
 The index at which a property will be placed in its group.
 */
@property (nonatomic) NSUInteger columnIndex;

/**
 Layout metadata for the property's editor.
 */
@property (nonatomic, strong) TKLayoutInfo *layoutInfo;

/**
 Determines if the property should be visible in the data form.
 */
@property (nonatomic) BOOL hidden;

/**
 Determines if the property could be edited in the data form.
 */
@property (nonatomic) BOOL readOnly;

/**
 Determines if null value is allowed. Default values us YES.
 */
@property (nonatomic) BOOL isNullable;

/**
 Indicates indicates if the property has passed validation (read-only).
 */
@property (nonatomic, readonly) BOOL isValid;

/**
 Indicates whether a valid property value is required to pass entity validation.
 */
@property (nonatomic) BOOL required;

/**
 An array of validators that adopt the TKDataFormValidator protocol that will be used to validate the property.
 */
@property (nonatomic, strong) NSArray *validators;

/**
 *  A converter that adopts TKDataFormConverter protocol.
 */
@property (nonatomic, strong) id<TKDataFormConverter> converter;

/**
 A feedback message used to show when validation fails.
 */
@property (nonatomic, copy) NSString *errorMessage;

/**
 A feedback message used to show when validation succeeds.
 */
@property (nonatomic, copy) NSString *positiveMessage;

/**
 A UIImage that will be displayed next to the title label of the property.
 */
@property (nonatomic, strong) UIImage *image;

/**
 *  An image that will be displayed if the property value pass validation.
 */
@property (nonatomic, strong) UIImage *positiveImage;

/**
 *  An image that will be displayed if the property value fail validation.
 */
@property (nonatomic, strong) UIImage *errorImage;

/**
 The value of the property model. This value may still not be committed.
 */
@property (nonatomic, strong) id valueCandidate;

/**
 The last committed value.
 */
@property (nonatomic, strong, readonly) id originalValue;

/**
 NSArray instance that specifies the available values.
 */
@property (nonatomic, strong) NSArray *valuesProvider;

/**
 *  A TKRange object that sets min and max values.
 */
@property (nonatomic, strong) TKRange *range;

/**
 *  Determines the step used for value changes.
 */
@property (nonatomic, strong) NSNumber *step;

/**
 *  Determnes if picker editors should use the item's index as value. Default is YES.
 */
@property (nonatomic) BOOL pickersUseIndexValue;

/**
 A hint text.
 */
@property (nonatomic, strong) NSString *hintText;

/**
 The editor class.
 */
@property (nonatomic) Class editorClass;

/**
 A formatter that will be used to format the display value.
 */
@property (nonatomic, strong) NSFormatter *formatter;

/**
 *  Shows if the property has gone throught validation.
 */
@property (nonatomic, readonly) BOOL wasValidated;

/**
 Initializes a new instance of TKEntityProperty with specific property name and owner.
 @param owner The entity which owns this property.
 @param propertyName The property name.
 */
- (instancetype)initWithEntity:(TKEntity*)owner forPropertyName:(NSString*)propertyName;

/**
 Commits the property value. Returns true if the property value passes validation.
 */
- (BOOL)commit;

/**
 Validates the property value.
 */
- (BOOL)validate;

@end
