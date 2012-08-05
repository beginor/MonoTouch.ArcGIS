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

/** @file AGSOpenStreetMapLayer.h */ //Required for Globals API doc

/** @brief A layer based on OpenStreetMap.

 An instance of this class allows you display maps from Open Street Map. 
 
 In a Model-View-Controller architecture, this object represents the Model. The 
 corresponding View object, @c AGSTiledLayerView,  is created when this object 
 is added to the map. 
 
 @define{AGSOpenStreetMapLayer.h, ArcGIS}
 @since 1.0
 */
@interface AGSOpenStreetMapLayer : AGSTiledLayer {
 @private
	AGSSpatialReference *_spatialReference;
	AGSEnvelope *_fullEnvelope;
	AGSEnvelope *_initialEnvelope;
	AGSTileInfo *_tileInfo;
	NSURL *_URL;
}

/** Spatial Reference used by OpenStreetMap.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSSpatialReference *spatialReference;

/** Full extent of OpenStreetMap.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSEnvelope *fullEnvelope;

/** Initial extent of OpenStreetMap.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSEnvelope *initialEnvelope;

/** Tiling scheme used by OpenStreetMap.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSTileInfo *tileInfo;

//## @cond
@property (nonatomic, retain, readonly) NSURL *URL;
//## @endcond

/** Return an initialized, auto released, layer.
 @since 1.8
 */
+(AGSOpenStreetMapLayer*)openStreetMapLayer;

@end
