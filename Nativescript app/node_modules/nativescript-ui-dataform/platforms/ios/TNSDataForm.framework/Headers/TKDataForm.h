//
//  TKDataForm.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKEntityProperty.h"

@protocol TKDataFormDataSource;
@protocol TKDataFormDelegate;
@class TKDataFormEditor;
@class TKEntityPropertyGroup;
@class TKEntityPropertyGroupView;
@class TKEntityPropertyGroupTitleView;
@class TKDataFormAccessoryView;
@class TKDataFormViewControllerEditor;
/**
 @enum TKDataFormCommitMode
 @discussion An enum that defines the commit modes for TKDataForm.
 */
typedef NS_ENUM(int, TKDataFormCommitMode)
{
    /**
     The property value will be commited on every change happening in the editor. The property will first be validated.
     */
    TKDataFormCommitModeImmediate,
    
    /**
     The property will be commited when the focus changes to another editor.
     If validation mode is delayed, the property will still be validated before commit.
     */
    TKDataFormCommitModeOnLostFocus,
    
    /**
     The entered data will be commited when the TKDataForm's commit method is called explicitly.
     */
    TKDataFormCommitModeManual
};

/**
 @enum TKDataFormValidationMode
 @discussion An enum that defines the validation modes for TKDataForm.
 */
typedef NS_ENUM(int, TKDataFormValidationMode)
{
    /**
     The property will be validated on every change of its value.
     */
    TKDataFormValidationModeImmediate,
    
    /**
     The property will be validated when the focus changes to another editor.
     */
    TKDataFormValidationModeOnLostFocus,
    
    /**
     The property will be validated when the commit method is invoked. This should be used only with TKDataFormCommitModeDelayed.
     */
    TKDataFormValidationModeManual
};

/**
 @discussion TKDataForm is a component that allows you to easily edit a business object's properties.
 */
@interface TKDataForm : UIView

/**
 TKDataForm's data source.
 */
@property (nonatomic, weak, nullable) id<TKDataFormDataSource> dataSource;

/**
 The UIViewController that contains this form.
 */
@property (nonatomic, weak, nullable) UIViewController *owner;

/**
 TKDataForm's delegate.
 */
@property (nonatomic, weak, nullable) id<TKDataFormDelegate> delegate;

/**
 TKDataForm's commit mode. It determines when the data the user has just entered will be reflected on the underlying business object.
 */
@property (nonatomic) TKDataFormCommitMode commitMode;

/**
 TKDataForm's validation mode.
 */
@property (nonatomic) TKDataFormValidationMode validationMode;

/**
 The spacing betweent groups in TKDataForm
 */
@property (nonatomic) CGFloat groupSpacing;

/**
 Determines if scrolling is enabled.
 */
@property (nonatomic) BOOL allowScroll;

/**
 *  Determines if the data form can be edited.
 */
@property (nonatomic) BOOL readOnly;

/**
 Insets for the control's editors.
 */
@property (nonatomic) UIEdgeInsets insets;

/**
 *  Creates new instance of TKDataForm using JSON annotations.
 *
 *  @param resourceName Path to JSON annotations.
 *  @param type         The type of the resource
 *
 *  @return New instace of TKDataForm.
 */
- (instancetype __nonnull)initWithJSONAnnotationsResource:(NSString * __nonnull)resourceName ofType:(NSString * __nonnull)type;

/**
 *  Setups TKDataForm using JSON annotations.
 *
 *  @param str          The string with JSON annotations.
 */
-(void)setupWithJSONAnnotationsString:(NSString * __nonnull)str;

/**
 Validates the data entered in TKDataForm.
 */
- (void)validate;

/**
 Commits the data entered in TKDataForm. This method takes effect only when commit mode is TKDataFormCommitModeManual.
 */
- (void)commit;

/**
 Commits the data entered in TKDataForm immediattely without attmepting validation.
 */
- (void)commitForced;

/**
 Checks the 'validation' state of the TKDataForm.
 @return Returns true if any of the TKDataForm editors validation is not valid.
 */
- (bool)hasValidationErrors;

/**
 Registers an editor class for a specified property. This method has highest priority among the other two register methods (for type and for class).
 @param editorClass The class of the editor that will be used.
 @param propertyName The property for which the editor class will be used.
 */
- (void)registerEditor:(Class __nonnull)editorClass forProperty:(NSString * __nonnull)propertyName;

/**
 Registers an editor of a specified class for a property of a specified class.
 @param editorClass The class of the editor that will be used.
 @param propertyClass The property class for which the editor class will be used.
 */
- (void)registerEditor:(Class __nonnull)editorClass forPropertyOfClass:(Class __nonnull)propertyClass;

/**
 Registers an editor class for a property type.
 @param editorClass The class of the editor that will be used.
 @param propertyType The type of the properties that will be registered.
 */
- (void)registerEditor:(Class __nonnull)editorClass forPropertyOfType:(TKEntityPropertyType)propertyType;

/**
 Sets an edior on focus. Use this method in TKDataFormEditor subclasses.
 @param editor The editor that will be set on fucus.
 */
- (void)setEditorOnFocus:(TKDataFormEditor * __nullable)editor;

/**
 Notify the data form that an editor has changed its value.
 @param editor The editor which value has changed.
 */
- (void)editorValueChanged:(TKDataFormEditor * __nonnull)editor;


-(void)onValidationStarted: (TKEntityProperty* __nonnull)property editor: (TKDataFormEditor* __nonnull) editor;

-(void)onValidationResult:(BOOL) result value:(NSObject* __nullable)value property:(TKEntityProperty* __nonnull)property editor: (TKDataFormEditor* __nonnull) editor;

/**
 Reloads TKDataForm.
 */
- (void)reloadData;

/**
 *  Updates only the editor for the corresponding property.
 *  @param property The property which editor will be updated.
 */
- (void)updateEditorForProperty:(TKEntityProperty * __nonnull)property;

/**
 Updates the visual appearance of all editors in TKDataForm.
 */
- (void)update;

/**
 *  Gets the group view for the corresponding group.
 *  @param group The group whose view will be returned.
 */
- (TKEntityPropertyGroupView * __nullable)groupViewForGroup:(TKEntityPropertyGroup * __nonnull)group;

@end

/**
 @discussion The TKDataSourceExtended protocol is adopted by an object that mediates the application's data model for a TKDataForm object.
 The data source provides the data form object with the information it needs to construct and modify a data form.
 */
@protocol TKDataFormDataSource <NSObject>

@required

/**
 The TKEntityProperty at the specified index path.
 @param dataForm The requesting TKDataForm object.
 @param groupIndex The index of the properties group.
 @param propertyIndex The index of the propery in the group.
 @return The TKEntityProperty at the specified index path.
 */
- (TKEntityProperty * __nullable)dataForm:(TKDataForm * __nonnull)dataForm propertyInGroup:(NSUInteger)groupIndex atIndex:(NSUInteger)propertyIndex;

/**
 The number of rows in the corresponding section.
 @param dataForm The requesting TKDataForm object.
 @param groupIndex The index of the group.
 @return The number of rows in the corresponding section.
 */
- (NSUInteger)dataForm:(TKDataForm * __nonnull)dataForm numberOfPropertiesInGroup:(NSUInteger)groupIndex;

/**
 Defines the value for the corresponding property.
 @param dataForm The requesting TKDataForm object.
 @param value The value that will be set to the property.
 @param property The propery which value will be set.
 @return Returns true if the value was set properly.
 */
- (BOOL)dataForm:(TKDataForm * __nonnull)dataForm setValue:(id __nullable)value forProperty:(TKEntityProperty * __nonnull)property;

/**
 TKEntityPropertyGroup at specified index.
 @param dataForm The requesting TKDataForm object.
 @param groupIndex The index of the requested group.
 @return The TKEntityPropertyGroup at the specified index.
 */
- (TKEntityPropertyGroup * __nonnull)dataForm:(TKDataForm * __nonnull)dataForm groupAtIndex:(NSUInteger)groupIndex;

/**
 *  The index of the specified group.
 *  @param group The which index is requested
 *  @return The index of the group.
 */
- (NSUInteger)indexOfGroupInDataForm:(TKEntityPropertyGroup * __nonnull)group;

@optional



/**
 The number of sections in the form.
 @param dataForm The requesting TKDataForm object.
 @return The number of section in the data form.
 */
- (NSUInteger)numberOfGroupsInDataForm:(TKDataForm * __nonnull)dataForm;

/**
 The header title of the corresponding section.
 @param dataForm The requesting TKDataForm object.
 @param groupIndex The section which requests a header title.
 @return The title string.
 */
- (NSString * __nullable)dataForm:(TKDataForm * __nonnull)dataForm titleForHeaderInGroup:(NSUInteger)groupIndex;

/**
 The TKDataFormEditor for the specified property.
 @param dataForm The requesting TKDataForm object.
 @param property The property for which an editor will be returned.
 @return The TKDataFormEditor for the corresponding property.
 */
- (Class __nullable)dataForm:(TKDataForm * __nonnull)dataForm editorClassForProperty:(TKEntityProperty * __nonnull)property;

@end

/**
 @discussion The methods declared by the TKDataFormDelegate protocol allow the adopting delegate to respond to messages from the TKDataForm class and thus respond to different operations.
 */
@protocol TKDataFormDelegate <NSObject>
@optional

/**
 Called when a row with the corresponding property is selected.
 @param dataForm The requesting TKDataForm object.
 @param editor The property editor.
 @param property The property that has been selected.
 */
- (void)dataForm:(TKDataForm * __nonnull)dataForm didSelectEditor:(TKDataFormEditor * __nonnull)editor forProperty:(TKEntityProperty * __nonnull)property;

/**
 Called when a row with the corresponding property is deselected.
 @param dataForm The requesting TKDataForm object.
 @param editor The property editor.
 @param property The property that has been selected.
 */
- (void)dataForm:(TKDataForm * __nonnull)dataForm didDeselectEditor:(TKDataFormEditor * __nonnull)editor forProperty:(TKEntityProperty * __nonnull)property;

/**
 Called after a property is edited.
 @param dataForm The requesting TKDataForm object.
 @param property The edited property.
 */
- (void)dataForm:(TKDataForm * __nonnull)dataForm didEditProperty:(TKEntityProperty * __nonnull)property;

/**
 Called after a property is validated.
 @param dataForm The requesting TKDataForm object.
 @param property The validated property.
 @param editor The property edior.
 */
- (void)dataForm:(TKDataForm * __nonnull)dataForm didValidateProperty:(TKEntityProperty * __nonnull)property editor:(TKDataFormEditor * __nonnull)editor;

/**
 Called when a property has to be validated.
 @param dataForm The requesting TKDataForm object.
 @param property The property that has to be validated.
 @param editor The property's editor.
 */
- (BOOL)dataForm:(TKDataForm * __nonnull)dataForm validateProperty:(TKEntityProperty * __nonnull)property editor:(TKDataFormEditor * __nonnull)editor;


/**
 Called when the dataform has finished validation of all properties.
 @param dataForm The requesting TKDataForm object.
 @param result The result from the validation.
 */
- (BOOL)dataForm:(TKDataForm * __nonnull)dataForm didFinishValidation:(BOOL)result;


/**
 Called when the dataform has finished commit of all properties.
 @param dataForm The requesting TKDataForm object.
 @param result Whether the properties were committed.
 */
- (BOOL)dataForm:(TKDataForm * __nonnull)dataForm didFinishCommit:(BOOL)result;

/**
 *  Called once when the data form creates its ediors. This method lets you to set properties that are not going to be changed.
 *
 *  @param dataForm The data form that requests the setup.
 *  @param editor   The editor that will be set up.
 *  @param property The editor's property.
 */
- (void)dataForm:(TKDataForm * __nonnull)dataForm setupEditor:(TKDataFormEditor * __nonnull)editor forProperty:(TKEntityProperty * __nonnull)property;

/**
 *  Called once when the data form layouts its ediors. This method check the frame that has been assigned.
 *
 *  @param dataForm The data form that layouts editors.
 *  @param editor   The editor that was laid out.
 *  @param property The editor's property.
 */
- (void)dataForm:(TKDataForm * __nonnull)dataForm didLayoutEditor:(TKDataFormEditor * __nonnull)editor forProperty:(TKEntityProperty * __nonnull)property;

/** Called before an editor is created. This method lets you provide custom implementation of the TKDataFormEditor object.
 @param dataForm The requesting TKDataForm object.
 @param property The property for the editor.
 */
- (TKDataFormEditor* __nullable)dataForm:(TKDataForm * __nonnull)dataForm createEditorForProperty:(TKEntityProperty * __nonnull)property;

/** Called before an editor is desplayed to the screen or after validation. This method lets you change the visual styles and setting of TKDataFormEditor object.
 @param dataForm The requesting TKDataForm object.
 @param editor The editor that will be updated.
 @param property The editor's property.
 */
- (void)dataForm:(TKDataForm * __nonnull)dataForm updateEditor:(TKDataFormEditor * __nonnull)editor forProperty:(TKEntityProperty * __nonnull)property;

/**
 This method lets you change the visual styles and setting of TKEntityPropertyGroupView object.
 @param dataForm dataForm The requesting TKDataForm object.
 @param groupView The TKEntityPropertyGroupView object that will be updated.
 @param groupIndex The index of the group view.
 */
- (void)dataForm:(TKDataForm * __nonnull)dataForm updateGroupView:(TKEntityPropertyGroupView * __nonnull)groupView forGroupAtIndex:(NSUInteger)groupIndex;

/**
 Called just before a property value will be commited to the business object.
 @param dataForm The requesting TKDataForm object.
 @param property The property which value is about to be committed.
 @return Return true to allow the commit operation.
 */
- (BOOL)dataForm:(TKDataForm * __nonnull)dataForm willCommitProperty:(TKEntityProperty * __nonnull)property;

/**
 Called after a property value is committed to the business object.
 @param dataForm The requesting TKDataForm object.
 @param property The property that has been committed.
 */
- (void)dataForm:(TKDataForm * __nonnull)dataForm didCommitProperty:(TKEntityProperty * __nonnull)property;

/**
 The header for the corresponding group.
 @param dataForm The requesting TKDataForm object.
 @param groupIndex The index of the group.
 @return The header for the group.
 */
- (TKEntityPropertyGroupTitleView * __nonnull)dataForm:(TKDataForm * __nonnull)dataForm viewForHeaderInGroup:(NSUInteger)groupIndex;

/**
 The height for the editor at specified indices.
 @param dataForm The requesting TKDataForm object.
 @param groupIndex The index of the editor's group.
 @param editorIndex The index of the editor in the group.
 @return The height of the editor.
 */
- (CGFloat)dataForm:(TKDataForm * __nonnull)dataForm heightForEditorInGroup:(NSUInteger)groupIndex atIndex:(NSUInteger)editorIndex;

/**
 The height of the group header.
 @param dataForm The requesting TKDataForm object.
 @param groupIndex The index of the group.
 @return The height of the group's header.
 */
- (CGFloat)dataForm:(TKDataForm * __nonnull)dataForm heightForHeaderInGroup:(NSUInteger)groupIndex;

/**
 *  Return input accessory view for text field editors.
 *  @param dataForm The data form requesting accessory view.
 *  @return Input accessory view.
 */
- (TKDataFormAccessoryView * __nullable)inputAccessoryViewForDataForm:(TKDataForm * __nonnull)dataForm;

/**
 Initializes a view controller specific for a given view controller editor.
 @param dataForm The requesting TKDataForm object.
 @param viewController The view controller to be initialized
 @param editor The view controller editor which presents the view controller.
 */
- (void)dataForm:(TKDataForm * __nonnull)dataForm initViewController:(UIViewController* __nonnull)viewController forEditor:(TKDataFormViewControllerEditor * __nonnull)editor;

/**
 Called when a group view is being collapsed.
 @param dataForm The TKDataForm instance.
 @param groupView The collpased group view.
 */
- (void)dataForm:(TKDataForm *__nonnull)dataForm didCollapseGroupView:(TKEntityPropertyGroupView *__nonnull)groupView;

/**
 Called when a group view is being expanded.
 @param dataForm The TKDataForm instance.
 @param groupView The expanded group view.
 */
- (void)dataForm:(TKDataForm *__nonnull)dataForm didExpandGroupView:(TKEntityPropertyGroupView *__nonnull)groupView;

- (void)dataFormDidFinishEditorIntitialization:(TKDataForm *__nonnull)dataForm;

@end
