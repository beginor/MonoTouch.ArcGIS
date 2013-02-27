/*
 COPYRIGHT 2012 ESRI
 
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

@class AGSRenderer;

/** @file AGSMPDictionaryRenderer */ //Required for Globals API doc

/** @brief A dictionary renderer object.
 
 This is a client-side representation of the core dictionary renderer. This will be largely “black box” and
 only expose methods to control the visibility of individual text items within multi-layer symbols, or other
 aspects of symbol display. It is not intended that developers will be able to create DictionaryRenderers at
 this stage, although future releases of the API may extent and fully implement this class (at same time as
 Multi-layer symbols).

 The visibility (set / setLabelsVisible) behaves as follows:
 
 If the map is outside @c #labelMaxScale / @c #labelMinScale, the labels will not display, even if @c #labelsVisible is true.
 If the map is within @c #labelMaxScale/ @c #labelMinScale, then the labels will display, unless @c #labelsVisible is false.
 @since 10.1.1
 */

@interface AGSMPDictionaryRenderer : AGSRenderer

/** description.
 @since 10.1.1
 */
@property (nonatomic, copy, readwrite) NSString* dictionaryRendererDescription;

/** dictionary type.
 @since 10.1.1
 */
@property (nonatomic, copy, readonly) NSString* dictionaryType;

/** field name.
 @since 10.1.1
 */
@property (nonatomic, copy, readwrite) NSString* fieldName;

/** label scale maximum.
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) double labelMaxScale;

/** label scale minimum.
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) double labelMinScale;

/** are labels visible?
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) BOOL labelsVisible;

/** symbol scale factor.
 @since 10.1.1
 */
@property (nonatomic, assign, readonly) double symbolScaleFactor;

@end
