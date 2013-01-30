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

#import <UIKit/UIKit.h>

@protocol AGSLayerView;
@protocol AGSLayerDelegate;
@protocol AGSTiledLayerTileDelegate;

@class AGSLayer;
@class AGSMapView;
@class AGSEnvelope;
@class AGSLOD;

/** @file AGSTiledLayerView.h */ //Required for Globals API doc

/** @brief A view to display maps from a cached map service

 In a Model-View-Controller architecture, this object represents the View. When corresponding Model 
 objects, subclasses of @c AGSTiledLayer, are added to the map, this view object is used internally 
 to display maps from the cached map service.

 This class extends <code>UIView</code> and implements the AGSLayerView protocol and the AGSTiledLayerTileDelegate protocol.
 You can change the transparency of the layer by modifying 
 the @p alpha property.
 
 @define{AGSTiledLayerView.h, ArcGIS}
 @since 1.0
 @see AGSTiledMapServiceLayer
 */
@interface AGSTiledLayerView : UIView <AGSLayerView, AGSTiledLayerTileDelegate> {
@private
    NSString *_name;
    AGSLayer *_agsLayer;
    AGSMapView *_mapView;
    NSError *_error;
    
    AGSLOD *_lod;
	
	BOOL _isInLevelRange;
	
	BOOL _drawDuringPanning;
	BOOL _drawDuringZooming;
	
	BOOL _enableTileAnimation;
	
	BOOL _limitMemoryUsage; // shrinks extent down for keeping tiles around
	BOOL _keepBgTiles;  // keeps background tiles until new tiles come in
	
	float _envelopeExpandFactor;
	float _limitedEnvelopeExpandFactor;
	
	BOOL _alwaysTryScaleDown;
	
	BOOL _enableTileBatching;
	
	NSMutableSet *_tilesInView;
	NSMutableSet *_tileOps;
	
	pthread_mutex_t _tilesMutex;
	pthread_mutex_t _opsMutex;
	
	int _tilesNeededCount;
    int _lastResetBGLevel;
}

/** Flag to determine whether or not the layer should draw while the map is panning.
 @since 1.0
 */
@property (nonatomic, assign) BOOL drawDuringPanning;

/** Flag to determine whether or not the layer should draw while the map is zooming.
 @since 1.0
 */
@property (nonatomic, assign) BOOL drawDuringZooming;

/** Flag to determine whether or not tile animations should be enabled. If enabled, tiles will
 appear to fade in when they are retrieved.
 @since 1.0
 */
@property (nonatomic, assign) BOOL enableTileAnimation;

/** Flag to limit memory usage. This should be used when targeting older devices such the original
 iPhone or iPhone 3G.
 @since 1.0
 */
@property (nonatomic, assign) BOOL limitMemoryUsage;

/** This is the maximum AGSMapView resolution (map units per point) that this layer renders at. 
 This is a calculation determined by the tile-info's resolution of the first LOD, the layer's
 renderNativeResolution property and the scale of the screen.
 @since 2.1
 */
@property (nonatomic, assign, readonly) double maxResolution;

/** This is the minimum AGSMapView resolution (map units per point) that this layer renders at.
 This is a calculation determined by the tile-info's resolution of the last LOD, the layer's
 renderNativeResolution property and the scale of the screen.
 @since 2.1
 */
@property (nonatomic, assign, readonly) double minResolution;

@end
