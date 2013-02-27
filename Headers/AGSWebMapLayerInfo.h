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

@class AGSWebMapFeatureCollection;
@class AGSPopupInfo;

/** @file AGSWebMapLayerInfo.h */ //Required for Globals API doc

/** @brief Information about top-level layers in a webmap
 
 Instances of this class represent information about top-level layers (such as map service layer, bing maps layer, openstreetmap layer, feature layer, feature collection, wms layer, etc) in the web map. 
 
 @since 2.2
 */
@interface AGSWebMapLayerInfo : NSObject <AGSCoding>

/** The id of the layer in the webmap.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *layerId;

/** The id of an item containing default information for the layer. The item resides on the same portal as the webmap.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *itemId;

/** The title of the layer in the webmap.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *title;

/** URL of the layer's backing service.
 @since 2.2
 */
@property (nonatomic, strong, readonly) NSURL *URL; 

/** If the value is 1, the layer is fully opaque. If 0, the layer is fully transparent.
 @since 2.2
 */
@property (nonatomic, readonly) float opacity;

/** The type of the layer. For example, OpenStreetMap, BingMapsAerial, BingMapsRoad, BingMapsHybrid, WMS, CSV, etc
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *layerType;

/** Whether the layer is visible or not.
 @since 2.2
 */
@property (nonatomic, readonly) BOOL visibility;

/** If YES, then the layer should be drawn on top of all other layers in the web map. Else, it should be drawn
 based on the order it was stored in the web map. This property only applies to basemap layers, not to operational layers.
 @since 2.2
 */
@property (nonatomic, assign, readonly) BOOL isReference;

/** Only applicable if the layer is a feature collection. A feature collection is a representation of one or more feature layers, where each layer contains the definition of that layer and the features that belong to that layer.
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSWebMapFeatureCollection *featureCollection;

/** Only applies if the layer is a feature layer. A value of 0 implies @c AGSFeatureLayerModeSnapshot, 1 implies @c AGSFeatureLayerModeOnDemand, and 2 implies @c AGSFeatureLayerModeSelection. 
 @since 2.2
 */
@property (nonatomic, assign, readonly) NSInteger mode;

/** A popup definition for the layer.
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSPopupInfo *popupInfo;

/** An array of @c AGSWebMapSubLayerInfo objects representing the sublayers of the layer. 
 For example, if the layer is based on an ArcGIS map service. Each sublayer will have an id and optionally a popup definition.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSArray *layers;

/** An array of sub-layer ids that should be visible
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSArray *visibleLayers;

/** Only applicable if the layer is a feature layer. This is the JSON returned by a Map or Feature Service for one of its layers, for example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/SanFrancisco/311Incidents/FeatureServer/0?f=pjson. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSDictionary *layerDefinition;

/** A property indicating whether the web map should show the features from this service in the legend.
 @since 2.3
 */
@property (nonatomic, assign, readonly) BOOL showLegend;

/** Array of bandIds to override the image service layer's defaults.
 @since 2.3
 */
@property (nonatomic, copy, readonly) NSArray *bandIds;

/** The minimum scale at which this layer is visible. If the map is zoomed out
 beyond this scale, the layer will not be visible.
 @since 10.1.1
 */
@property (nonatomic, assign, readonly) double minScale;

/** The maximum scale at which this layer is visible. If the map is zoomed in
 beyond this scale, the layer will not be visible.
 @since 10.1.1
 */
@property (nonatomic, assign, readonly) double maxScale;

/** A property indicating whether the web map has disabled editing for the features in this layer
 @since 10.1.1
 */
@property (nonatomic, assign, readonly) BOOL isEditingDisabled;


@end
