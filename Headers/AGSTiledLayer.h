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

@class AGSLayer;
@class AGSTileInfo;

/** @file AGSTiledLayer.h */ //Required for Globals API doc

/**  @brief A base class for tiled layers.
 
 A base class for layers which displays cached maps. You would typically work 
 with one or more sub-classes of this class, for instance, @c AGSTiledMapServiceLayer.
 
 
 @define{AGSTiledLayer.h,ArcGIS}
 @since 1.0
 */
@interface AGSTiledLayer : AGSLayer

/** Tiling scheme for the layer. This property must be implemented by subclasses.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSTileInfo *tileInfo;

/**
 Takes the scale passed in and converts it to a scale you can zoom to on the map
 to see the tiles for that particular LOD. This takes into account how the layer
 is being rendered on the map and the PPI of the device the map is on.
 @param lodScale The scale reported by an @c AGSLOD object
 @return equivalent map scale that you can zoom to
 @since 10.1.1
 */
-(double)convertedScaleForLodScale:(double)lodScale;

/**
 Takes the resolution passed in and converts it to a resolution you can zoom to on the map
 to see the tiles for that particular LOD. This takes into account how the layer
 is being rendered on the map and the PPI of the device the map is on.
 @param lodResolution The resolution reported by an @c AGSLOD object
 @return equivalent map resolution that you can zoom to
 @since 10.1.1
 */
-(double)convertedResolutionForLodResolution:(double)lodResolution;

@end
