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

@class AGSPopupInfo;

/** @file AGSWebMapSubLayerInfo.h */ //Required for Globals API doc

/** @brief Information about sub-layers of a top level layer in a webmap.
 
 Instances of this class represent sub-layers of a top level layer in a webmap.
 The sub-layers may be individual feature layers belonging to an AGSWebMapFeatureCollection, or they may be sub-layers of a map service layer.
 
 @since 2.2
 */
@interface AGSWebMapSubLayerInfo : NSObject <AGSCoding>

/** The id of the layer
 @since 2.2
 */
@property (nonatomic, assign, readonly) NSUInteger layerId;

/** The popup definition of the layer
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSPopupInfo *popupInfo;

/** JSON representation of an AGSFeatureSet containing the features to be displayed by the layer. Only applicable if the layer is part of an @c AGSWebMapFeatureCollection.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSDictionary *featureSet;

/** JSON representation of the layer's properties. Only applicable if the layer is part of an @c AGSWebMapFeatureCollection. This is the JSON returned by a Map or Feature Service for one of its layers, for example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/SanFrancisco/311Incidents/FeatureServer/0?f=pjson. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSDictionary *layerDefinition;

/** URL of the sub-layer's backing service. This can be used to query the layer for popups.
 @since 2.3
 */
@property (nonatomic, strong, readonly) NSURL *layerURL; 

/**
 @since 2.3
 */
@property (nonatomic, assign, readonly) BOOL showLegend;
@end

