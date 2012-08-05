/*
 COPYRIGHT 2009 ESRI
 
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

#import <Foundation/Foundation.h>

@class AGSLayer;
@class AGSTiledLayer;
@class AGSSpatialReference;
@class AGSEnvelope;
@class AGSTileInfo;
@class AGSBingMapLayerMetadata;

/** @file AGSBingMapLayer.h */

/** Supported map styles for BingMaps.
 @since 1.0
 */
typedef enum { 
	AGSBingMapLayerStyleAerial,				/*!<  */
	AGSBingMapLayerStyleAerialWithLabels,	/*!<  */
	AGSBingMapLayerStyleRoad				/*!<  */
} AGSBingMapLayerStyle;

/** @brief A layer based on Bing Maps.
 
 An instance of this class allows you display maps from Bing Maps.
 
 In a Model-View-Controller architecture, this object represents the Model. The 
 corresponding View object, @c AGSTiledLayerView, is created when this layer is 
 added to an instance of @c AGSMapView.
 
 @define{AGSBingMapLayer.h, ArcGIS}
 @since 1.0
 */
@interface AGSBingMapLayer : AGSTiledLayer {
 @private
	AGSSpatialReference *_spatialReference;
	AGSEnvelope *_fullEnvelope;
	AGSEnvelope *_initialEnvelope;
	AGSTileInfo *_tileInfo;
	NSURL *_URL;
	NSString *_appID;
	AGSBingMapLayerStyle _style;
	AGSBingMapLayerMetadata *_metadata;
	NSInteger _subDomainIterator;
}

/** Spatial Reference used by Bing Maps.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSSpatialReference *spatialReference;

/** Full extent of Bing Maps.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSEnvelope *fullEnvelope;

/** Initial extent of Bing Maps.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSEnvelope *initialEnvelope;

/** Tiling scheme used by Bing Maps.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSTileInfo *tileInfo;

/** An AppID which has been authorized to use Bing Maps.
 @since 1.0
 @see <a href="http://msdn.microsoft.com/en-us/library/b80e6336-6a33-4555-b26a-ba834c8d756c"> Getting Started with Bing API </a>
 */
@property (nonatomic, copy, readonly) NSString *appID;

/** The map style. Possible values include 
 
 @li @c AGSBingMapLayerStyleAerial
 @li @c AGSBingMapLayerStyleAerialWithLabels
 @li @c AGSBingMapLayerStyleRoad
 
 @since 1.0
 */

@property (nonatomic, assign) AGSBingMapLayerStyle style;

/** The locale to use for the Bing Map service.
 The default is the current locale of the device.
 @since 2.2
 */
@property (nonatomic, retain) NSLocale *locale;

/** Initialize this layer with an AppID and a map style.
 @param appID The appID authorized to use Bing Maps.
 @param style The style of the map. See #style.
 @return A new Bing Maps layer object.
 @since 1.0
 @see AGSBingMapLayerStyle
 */
-(id)initWithAppID: (NSString*) appID style:(AGSBingMapLayerStyle) style;

@end






