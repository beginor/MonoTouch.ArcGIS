/*
 COPYRIGHT 2011 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */

@class AGSGraphic;
@class AGSPopupInfo;
@class AGSPopupFieldInfo;
@class AGSPopupUtility;
@class AGSFeatureLayer;
@class AGSGeometry;

/** @file AGSPopup.h */ //Required for Globals API doc

/** @brief A popup which displays a graphic's information.
 
 Instances of this class represent a popup which associates a graphic with popup definition for the purpose of displaying in an AGSPopupsContainer.
 @since 2.0
 */
@interface AGSPopup : NSObject

/** The graphic whose details need to be displayed in the popup.
 @since 2.0
 */
@property (nonatomic, strong, readonly) AGSGraphic *graphic;

/** A popup definition that dictates which information belonging to the graphic should be displayed in the popup  and how it should be formatted. 
 @since 2.0
 */
@property (nonatomic, strong, readonly) AGSPopupInfo *popupInfo;

/** A convenient way to retrieve the feature layer for the popup graphic. Will be nil if
 the graphic was not part of a feature layer when the popup was initialized. This is
 helpful if you have popups open for graphics in an OnDemand feature layer that is refreshing
 and the graphics are getting removed from the feature layer. This will cache the feature layer,
 at the time of initialization so that you can post edits, etc, on this reference.
 @since 2.1
 */
@property (nonatomic, strong, readonly) AGSFeatureLayer *featureLayer;

/** Whether or not the popup should allow the graphic to be edited.
 @since 2.3
 */
@property (nonatomic, assign) BOOL allowEdit;

/** Whether or not the popup should allow the graphic's geometry should be edited. Only applicable when #allowEdit is YES.
 @since 2.3
 */
@property (nonatomic, assign) BOOL allowEditGeometry;

/** Whether or not the popup should allow the graphic to be deleted.
 @since 2.3
 */
@property (nonatomic, assign) BOOL allowDelete;

/** Initializes an @c AGSPopup instance.
 @param graphic for which the popup needs to be displayed
 @param popupInfo defining how information about the graphic should be displayed
 @return An AGSPopup
 @since 2.0
 */
-(id)initWithGraphic:(AGSGraphic*)graphic popupInfo:(AGSPopupInfo*)popupInfo;

/** Initializes an @c AGSPopup instance.
 @param graphic for which the popup needs to be displayed
 @param popupInfo defining how information about the graphic should be displayed
 @param featureLayer if one is associated with the graphic
 @return An AGSPopup
 @since 10.1.1
 */
-(id)initWithGraphic:(AGSGraphic*)graphic popupInfo:(AGSPopupInfo*)popupInfo featureLayer:(AGSFeatureLayer*)featureLayer;

/** Returns an autoreleased @c AGSPopup.
 @param graphic for which the popup needs to be displayed
 @param popupInfo defining how information about the graphic should be displayed
 @return An autoreleased AGSPopup
 @since 2.0
 */
+(AGSPopup*)popupWithGraphic:(AGSGraphic*)graphic popupInfo:(AGSPopupInfo*)popupInfo;

/** Returns an autoreleased @c AGSPopup.
 @param graphic for which the popup needs to be displayed
 @param popupInfo defining how information about the graphic should be displayed
 @param featureLayer if one is associated with the graphic
 @return An autoreleased AGSPopup
 @since 10.1.1
 */
+(AGSPopup*)popupWithGraphic:(AGSGraphic*)graphic popupInfo:(AGSPopupInfo*)popupInfo featureLayer:(AGSFeatureLayer*)featureLayer;

/** Returns a string attribute value for a field info based on the graphic
 that this AGSPopup represents.
 @since 10.1.1
 */
-(NSString*)attributeForPopupFieldInfo:(AGSPopupFieldInfo*)popupFieldInfo;

/** A convenience method that returns a string that has the templated portions replaced with attributes from the graphic. For example, a template string <i>Population of ${CITY_NAME} is ${POP1990}</i> will return a string
 with templates replaced by  values of attribute CITY_NAME and POP1990 in the graphic.
 @param aString The template string with templates enclosed in ${}
 @since 10.1.1
 */
-(NSString *)stringForTemplatedString:(NSString *)aString;

@end
