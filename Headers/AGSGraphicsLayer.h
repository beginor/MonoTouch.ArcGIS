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

@class AGSDynamicLayer;
@class AGSRenderer;
@class AGSExportImageParams;
@class AGSTimeExtent;
@class AGSEnvelope;
@class AGSGraphicsLayerDrawingOperation;
@class AGSTimeExtent;

/** @file AGSGraphicsLayer.h */ //Required for Globals API doc

#pragma mark -

/** @brief A layer to display graphics on the map.
 
 This layer  allows you to add graphics on the map. By using these graphics, you 
 can add your own places of interest to the map, or highlight existing places.
 
 Each graphic contains a geometry describing the location and the shape of the 
 graphic. A Graphics layer typically contains @p graphics based on a single 
 geometry type (Point, Multipoint, Polyline, or Polygon).  Each graphic can be 
 associated with an @c AGSSymbol which controls how the graphic looks.  
 Alternatively, the layer can be associated with an @c AGSRenderer which manages 
 the appearance of all graphics in the layer.
  
 In a Model-View-Controller architecture, this object represents the Model. The 
 corresponding View object, @c AGSDynamicLayerView, is created when this object 
 is added to the map.
 
 The @p spatialReference property of a graphics layer is defined either by
 setting the #initialEnvelope with a valid spatial reference or when the first
 graphic is added with a valid geometry and spatial reference. Furthermore, the
 geometry of individual graphics in the layer must be of the same spatial
 reference.
 
 @define{AGSGraphicsLayer.h, ArcGIS}
 @since 1.0
 @see AGSMapViewDelegate for events related to tapping on graphics 
 in the %graphics layer.
 */
@interface AGSGraphicsLayer : AGSDynamicLayer {
 @private
    NSMutableArray *_graphics;
    AGSGraphicsLayerDrawingOperation *_currentOperation;
    CGSize _currentSize;
    AGSEnvelope *_currentEnvelope;
    
    CGContextRef _bitmapContext;
    AGSRenderer *_renderer;
	AGSEnvelope *_initialEnvelope;
	AGSEnvelope *_fullEnvelope;
	
	double _minScale;
	double _maxScale;
	
	NSOperationQueue *_localOpQueue;
	pthread_mutex_t _bitmapContextCreationMutex;
}

/** The array of @c AGSGraphic objects that need to be displayed on the map.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSMutableArray *graphics;

/** @c AGSRenderer assigned to the layer. It is responsible for symbolizing the 
 graphics. It is optional as each graphic may have it's own symbol. If a graphic
 has a symbol, that will be used for drawing the graphic instead of the renderer.
 @since 1.0
 */
@property (nonatomic, retain) AGSRenderer *renderer;

/** Gets or sets the initial envelope of the layer.
 @since 1.0
 */
@property (nonatomic, retain) AGSEnvelope *initialEnvelope;

/** The minimum scale at which this layer is visible. If the map is zoomed out 
 beyond this scale, the layer will not be visible.
 @since 1.0
 */
@property (nonatomic, readwrite) double minScale;

/** The maximum scale at which this layer is visible. If the map is zoomed in 
 beyond this scale, the layer will not be visible.
 @since 1.0
 */
@property (nonatomic, readwrite) double maxScale;

/** Flag indicating if the layer renders at the native resolution. 
 This property will not have any affect iOS devices without a retina display. If using an iOS
 device with a retina display and you want to take advantage of that display you can set
 this value to YES. The property must be set before the layer loads.
 
 When rendering at the native resolution, this layer will use more memory (because the map images will be bigger).
 @since 2.1
 */
@property (nonatomic, assign, readwrite) BOOL renderNativeResolution;

/** A method to get an initialized and autoreleased graphics layer.
 @return A new, autoreleased, graphics layer object.
 @since 1.0
 */
+ (id)graphicsLayer;

/** Adds @p graphic to the layer. You must call @c #dataChanged to redraw the layer.
 @param graphic The graphic to be added.
 @since 1.0
 */
- (void)addGraphic:(AGSGraphic *)graphic;

/** Adds @p graphics to the layer. You must call @c #dataChanged to redraw the layer.
 @param graphics Array of @c AGSGraphic objects to be added.
 @since 1.0
 */
- (void)addGraphics:(NSArray *)graphics;

/** Remove @p graphic from the graphics collection. You must call @c #dataChanged to 
 redraw the layer.
 @param graphic The graphic to be removed.
 @since 1.0
 */
- (void)removeGraphic:(AGSGraphic *)graphic;

/** Remove all graphics from the layer. You must call @c #dataChanged to redraw 
 the layer.
 @since 1.0
 */
- (void)removeAllGraphics;

/** This method tells the graphics layer that the underlying graphics or 
 symbology has changed and that it needs to be redrawn. 
 @since 1.0
 */
-(void)dataChanged;

@end
