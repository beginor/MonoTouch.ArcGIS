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
#import "UIDevice+AGSAdditions.h"

@class AGSGeometry;
@class AGSEnvelope;
@class AGSSpatialReference;
@protocol AGSLayerView;
@class AGSGPS;
@class AGSPoint;
@class AGSCallout;
@class AGSLayer;
@class AGSGraphic;
@class AGSGraphicsLayer;
@class AGSTimeExtent;
@class AGSMagnifierView;
@class AGSActivityIndicatorView;

@protocol AGSCalloutDelegate;
@protocol AGSMapViewDelegate;
@protocol AGSMapViewLayerDelegate;
@protocol AGSMapViewTouchDelegate;
@protocol AGSMapViewCalloutDelegate;

/** @file AGSMapView.h */ //Required for Globals API doc

// DBL_EPSILON is 2.220446e-16 on simulator and iphone 4
// so we will use a little less than that for our epsilon to make
// sure that we are safe
#define RESOLUTION_TOLERANCE 2.2e-13

/** @brief A View component to display maps.
 
 An instance of this class represents a map component. It is a container 
 for layers, graphics, gps display and a callout. It responds to user interaction by providing
 behavior for map navigation, displaying the callout, etc.
 
 The component informs its @c #layerDelegate, @c #touchDelegate, and @c #calloutDelegate  whenever certain events take place and 
 also consults the delegates before performing certain actions. 
 
 For example,  the <code>mapViewDidLoad:</code> method  on @c AGSMapViewLayerDelegate is invoked
 after the first layer has been added to the map. At this point, the component is 
 fully functional. The <code>mapView:didClickAtPoint:mapPoint:graphics:</code> method on @c AGSMapViewTouchDelegate is
 invoked when a user taps on the map. 
 
 You can customize the behavior of the map and respond to events by attaching your own delegate classes. Your delegate classes
 must adopt the necessary protocols.  
 
 The map component also broadcasts four notifications - @em MapViewDidLoad, @em MapTimeExtentChanged,  @em MapDidEndPanning and @em MapDidEndZooming. Observers interested
 in these notifications can register for them using the default <code>NSNotificationCenter</code>. Notificatons are delievered on the main thread. You should not block this 
 thread by pefroming expensive tasks otherwise your application will appear sluggish to the user.
 
 The first layer added to the map is treated as a <i>basemap</i> layer. It defines the 
 spatialReference of the entire map, and the initial and full extents. The map will not load until this layer loads. 
 When the <i>basemap</i> layer fails to load, other layers in the map are still loaded, but the map does not display any layers.If this
 When the <i>basemap</i> layer fails to load, you can either remove it from the map or possibly resubmit it if the credentials
 were incorrect or the network was temporarily down.
 If the <i>basemap</i> layer is removed the map will treat the next layer as
 the <i>basemap</i> layer. The next layer chosen will be the layer that is at the bottom-most position,
 or the layer at index zero.
 
 @see @concept{Creating_A_Map/00pw00000005000000/, Creating a Map}
 @since 1.0
 
 */
@interface AGSMapView : UIView <AGSCalloutDelegate> {
 @private
    AGSEnvelope *_fullEnvelope;
	AGSEnvelope *_preloadEnvelope;
    AGSPoint *_preloadCenter;
    AGSSpatialReference *_spatialReference;
	AGSUnits _units;
	AGSEnvelope *_envelope;
	AGSTimeExtent *_timeExtent;
	double _minResolution;
	double _maxResolution;
	double _maxTiledLayerResolution;
	
	UIView *_mapLayersView;
    NSMutableArray *_mapLayerNames;
	NSArray *_mapLayers;
    NSDictionary *_mapLayerViews;
	UIView<AGSLayerView> *_firstLayerView; // the first layer view added or inserted into the map
	AGSGPS *_gps;
	AGSCallout *_callout;
    AGSGraphic *_calloutGraphic;
	BOOL _calloutShownForGPS;
	UIView *_containerView; // scales
	UIView *_masterView;
	
    BOOL _loaded;
	double _resolution; // the current resolution of the view 
	double _mapScale;
	BOOL _panAnimating;
	BOOL _zoomAnimating;
	BOOL _panning; // by user touching/interaction
	BOOL _zooming; // by user touching/interaction
	
	// touch processing vars
	double _touchInitialResolution;
	AGSEnvelope *_touchInitialEnv;
	CFAbsoluteTime _lastTapAndHoldPan;
	CGFloat _totalDeltaX;
	CGFloat _totalDeltaY;
	double _pinchScale;
	UITouch *_pinch1;
	UITouch *_pinch2;
	BOOL _pinched;
	double _pinchInitialDistance;
	double _pinchInitialResolution;
	CATransform3D _pinchInitialTransform;
	AGSEnvelope *_pinchInitialEnv;
	CGPoint _pinchInitialCenter;
	CFAbsoluteTime _pinchZoomNoteTime;
	NSMutableArray *_touchTrack;
	double _pinchZoomCallResolution;
	AGSPoint *_pinchInitialMapCenter;
	CGFloat _pinchInitialAngle;
	CGFloat _pinchInitialRotationAngle;
	CGFloat _lastMaxXPanningNote;
	CGFloat _lastMaxYPanningNote;
	CGFloat _lastMinXPanningNote;
	CGFloat _lastMinYPanningNote;
	BOOL _tapAndHolding;
	BOOL _magnifierHidCallout;
	CGPoint _tapAndHoldInitialLocation;
	BOOL _rotatedBeforePinched;
	BOOL _pinchedBeforeRotated;
	
	CGRect _cachedMapBounds;
	AGSEnvelope *_referenceEnvelope;
	CGRect _referenceFrame;
	
	NSThread *_workerThread;
	
	id<AGSMapViewLayerDelegate> _layerDelegate;
	id<AGSMapViewTouchDelegate> _touchDelegate;
	id<AGSMapViewCalloutDelegate> _calloutDelegate;
	
	UIDeviceMachineType _deviceMachineType;
	BOOL _limitedDeviceCapabilities;
	
	id _workerThreadTarget;

	AGSMagnifierView *_magnifierView;
#ifdef DEBUG
	AGSGraphicsLayer *_debugGraphicLayer;
#endif
	
	BOOL _wrapAround;
	BOOL _showMagnifierOnTapAndHold;
	
	AGSActivityIndicatorView *_tapAndHoldProgView;
	int _currentZoomContext;
	
	CATransform3D _scaleTransform;
	CATransform3D _rotationTransform;
	float _rotationAngle;
	float _rotationAngleRadians;
	CGRect _rotatedBounds;
	BOOL _rotationAnimating;
	AGSEnvelope *_rotatedEnvelope;
	BOOL _rotatedAtLeastOnce; 
	BOOL _allowRotationByPinching;
	
	AGSPolygon *_visibleArea;
    
    BOOL _maxEnvelopeOverridden;
    AGSEnvelope *_maxEnvelope;
}

//
// properties
//

/** Delegate to be notified when map layer actions occur. The delegate class must 
 adopt the @c AGSMapViewLayerDelegate protocol.
 @since 1.8
 */
@property (nonatomic, assign) id<AGSMapViewLayerDelegate> layerDelegate;

/** Delegate to be notified when touch events occur on the map.The delegate class must 
 adopt the @c AGSMapViewTouchDelegate protocol.
 @since 1.8
 */
@property (nonatomic, assign) id<AGSMapViewTouchDelegate> touchDelegate;

/** Delegate to be notified when map callout actions occur.The delegate class must 
 adopt the @c AGSMapViewCalloutDelegate protocol.
 @since 1.8
 */
@property (nonatomic, assign) id<AGSMapViewCalloutDelegate> calloutDelegate;

/** View that contains the layer views. Do not modify the contents of this view directly. It is for informational purposes only.
 @since 1.0
 */
@property (nonatomic, retain, readonly) UIView *mapLayersView;

/** Master view for child views of the map. Do not modify the contents of this view directly. It is for informational purposes only.
 @since 1.0
 */
@property (nonatomic, retain, readonly) UIView *masterView;

/** Array of @c AGSLayer objects representing the layers in the map. Depending upon the type of layer, each object
 will be specific sub-class of @c AGSLayer.
 @since 1.8
 */
@property (nonatomic, retain, readonly) NSArray *mapLayers;

/** Dictionary providing access to @c AGSLayerView objects for each layer in the 
 map. View object can be retrieved using layer's name as the key.
 @see addMapLayer:withName:
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSDictionary *mapLayerViews;

/** After the first layer added to the map is loaded, this value is set to <code>true</code>.
 @since 1.0
 */
@property (nonatomic, readonly) BOOL loaded;

/** The map's current resolution (map units per Point).
 @since 1.0
 */
@property (nonatomic, assign, readonly) double resolution;

/** The current scale of the map. Will return 0 if it cannot be calculated.
 @since 1.0
 */
@property (nonatomic, assign, readonly) double mapScale;

/** The current extent of the map in map units.
 @since 1.0
 @deprecated Deprecated at 2.1. Use #visibleArea polygon instead.
 */
@property (nonatomic, retain, readonly) AGSEnvelope *envelope __attribute__((deprecated));

/** The spatial reference of the map. Defined by the <i>basemap</i> layer.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSSpatialReference *spatialReference;

/** The full extent of map.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSEnvelope *fullEnvelope;

/** The time extent for the map. Will be used only for time-aware layers. 
 @avail{10.0}
 @see @concept{Viewing_Temporal_data/00pw00000051000000/, Viewing Temporal Data}
 @see @sample{5603382f9f77482098398e01c8d276cc, Temporal}
 @since 1.0
 */
@property (nonatomic, retain, readwrite) AGSTimeExtent *timeExtent;

/** The units the map is in. Possible values include
 
 @li @c AGSUnitsCentimeters 
 @li @c AGSUnitsDecimalDegrees
 @li @c AGSUnitsDecimeters
 @li @c AGSUnitsFeet
 @li @c AGSUnitsInches
 @li @c AGSUnitsKilometers
 @li @c AGSUnitsMeters
 @li @c AGSUnitsMiles
 @li @c AGSUnitsMillimeters
 @li @c AGSUnitsNauticalMiles
 @li @c AGSUnitsPoints
 @li @c AGSUnitsUnknown
 @li @c AGSUnitsYards
 
 @since 1.0
 */
@property (nonatomic, assign, readonly) AGSUnits units;

/** The display that shows the current location of the device, which is updated from the CLLocationManager.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSGPS *gps;

/** A callout view for displaying information on the map.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSCallout *callout;

/** Flag to indicate if the map is animating.
 @since 1.0
 */
@property (nonatomic, assign, readonly) BOOL animating;

/** Flag to indicate if the map is panning.
 @since 1.0
 */
@property (nonatomic, assign, readonly) BOOL panning; // by user interaction/touch

/** Flag to indicate if the map is zooming.
 @since 1.0
 */
@property (nonatomic, assign, readonly) BOOL zooming; // by user interaction/touch

/** Returns the type of device currently running the application. This is useful
 if we want to disable certain features to gain performance on older devices.
 @since 1.0
 */
@property (nonatomic, assign, readonly) UIDeviceMachineType deviceMachineType;

/** Flag to indicate if the current device has been limited to gain performance.
 @since 1.0
 */
@property (nonatomic, assign, readonly) BOOL limitedDeviceCapabilities;

/** Flag to indicate if the map should wrap around. Default is @c NO.
 When @c YES, the map may need to zoom depending on the resolution. The map also may reset this property
 back to @c NO if the layers don't conform to certain properties.
 @see @concept{Enabling_Wrap_Around/00pw00000050000000/, Enabling Wrap Around}
 @since 1.8
 */
@property (nonatomic, assign, readwrite) BOOL wrapAround;

/** Flag to indicate if the map should show the magnifier when the user performs a tap
 and hold gesture on the map. Default is @c NO
 */
@property (nonatomic, assign, readwrite) BOOL showMagnifierOnTapAndHold;


/**The rotation angle (in degrees). The map is rotated in a counter-clockwise direction by the amount specified. To specify a new angle, see 
 @see #setRotationAngle:animated: 
 @see #setRotationAngle:aroundMapPoint:animated: 
 @see #setRotationAngle:aroundScreenPoint:animated:
 @since 2.1
 */
@property (nonatomic, assign) float rotationAngle;

/** Flag to indicate if a user should be allowed to rotate the map using a two finger twist gesture.
 Default is @c NO.
 @since 2.1
 */
@property (nonatomic, assign) BOOL allowRotationByPinching;

/** A polygon representing the map's visible area. 
 The polygon always contains 1 ring with 4 vertices, each representing a corner of the map.
 
 This is a replacement for the @c #envelope property which has been deprecated. An envelope is no longer be used to represent the visible area because the map may be rotated and each corner of the map may contain unique x-y coordinates, where as an envelope only permits 2 unique x coordinates (xmin, xmax) and 2 unique y coordinates (ymin, ymax).
 @since 2.1
 */
@property (nonatomic, retain, readonly) AGSPolygon *visibleArea;

/** Limits the amount by which the map can be panned such that its anchor point (typically the center) never goes outside
 this envelope. By default, this is the full envelope of the basemap layer. If you set a custom extent,
 the envelope must have the same spatial reference as the map.
 @since 2.1
 */
@property (nonatomic, retain, readwrite) AGSEnvelope *maxEnvelope;

//
// methods
//

/** Add a layer to the map using the specified name. The first layer added to 
 the map is treated as a <i>basemap</i> layer. It defines the full extent and 
 #spatialReference of the map.
 @param mapLayer Map Layer to be added to the map.
 @param name Name of layer. You can pass nil, in which case a name will be provided. If specified, this name must be unique.
 If the name is not unique, nil will be returned and the layer will never be added to the map.
 @return @c AGSLayerView object used to draw the layer
 @since 1.0
 */
- (UIView<AGSLayerView> *)addMapLayer:(AGSLayer *)mapLayer withName:(NSString *)name;

/** Remove a layer from the map with specified name. Even when the <i>basemap</i> 
 layer is removed, the map's #visibleArea , #fullEnvelope, and #spatialReference  
 properties remain unchanged. 
 @param name Name of the layer to be removed.
 @since 1.0
 */
- (void)removeMapLayerWithName: (NSString *)name;

/** Inserts a layer to the map with specified name at @p index.
 @param mapLayer Map Layer of type @c AGSLayer to be added to map.
 @param name Name of layer. You can pass nil, in which case a name will be provided. If specified, this name must be unique.
  If the name is not unique, nil will be returned and the layer will never be added to the map.
 @param index Index where layer will be inserted.
 @return @c AGSLayerView used to draw layer
 @since 1.0
 */
- (UIView<AGSLayerView> *)insertMapLayer:(AGSLayer *)mapLayer withName:(NSString *)name atIndex:(NSUInteger)index;

/** Convert the specified point in screen units to a point in map units.
 @param point Point in screen units. 
 @return Point in map units. Point will have the same spatial reference as the map.
 @since 1.0
 */
- (AGSPoint *)toMapPoint:(CGPoint)point;

/** Convert the specified point in map units to a point in screen units.
 @param point Point in map units. Point must have the same spatial reference as the map.
 @return Point in screen units.
 @since 1.0
 */
- (CGPoint)toScreenPoint:(AGSPoint *)point;

/** Convert the specified envelope in map units to a @c CGRect in screen units.
 @param envelope Envelope in map units. Envelope must have the same spatial reference as the map.
 @return @c CGRect in screen coordinates
 @since 1.0
 */
- (CGRect)toScreenRect:(AGSEnvelope *)envelope;

/** Converts a rectangle in screen coordinates to an envelope in map units.
 @param rect Rectangle in screen coordinates to convert from.
 @return Envelope in map units. Envelope will have the same spatial reference as the map.
 @since 1.0
 */
- (AGSEnvelope *)toMapEnvelope:(CGRect)rect;

/** Zoom/Pan the map to specified envelope.
 @param envelope Map envelope to zoom/pan to. Envelope must have the same spatial reference as the map. 
 Envelope must be in map units.
 @param animated Determines if the scrolling should be animated or immediate.
 @since 1.0
 */
- (void)zoomToEnvelope:(AGSEnvelope *)envelope animated:(BOOL)animated;

/** Zooms map by a factor. Anchor Point is in screen coordinates of the map view.
 @param factor Used to determine the amount to zoom. For example, use 0.5 to 
 zoom in twice as far and 2.0 to zoom out twice as far.
 @param anchorPoint Point in screen coordinates around which to zoom. This is ignored if the gps @link AGSGPS::autoPanMode autoPanMode @endlink is @c AGSGPSAutoPanModeNavigation or @c AGSGPSAutoPanModeCompassNavigation in which case map zooms around the location symbol.
 @param animated Determines if the zooming should be animated or immediate.
 @since 1.0
 */
-(void)zoomWithFactor:(double)factor atAnchorPoint:(CGPoint)anchorPoint animated:(BOOL)animated;

/** Zooms in to the current center of the map by a factor of .5.
 @param animated Determines if the zooming in should be animated or immediate.
 @since 1.0
 */
-(void)zoomIn:(BOOL)animated;

/** Zooms out to the current center of the map by a factor of 2.
 @param animated Determines if the zooming out should be animated or immediate.
 @since 1.0
 */
-(void)zoomOut:(BOOL)animated;

/** Center map at specified location.
 @param point Map point to center map. Point must have the same spatial reference as the map.
 Point must be in map units.
 @param animated Determines if the centering should be animated or immediate.
 @since 1.0
 */
- (void)centerAtPoint:(AGSPoint *)point animated:(BOOL)animated;

/** Zooms the map such that the given geometry fits the bounds of the map.
 @param geometry to zoom to
 @param padding in points so that the geometry may not touch any edges of the map
 @param animated flag indicating whether to animate the zoom action
 @since 2.1
 */
-(void)zoomToGeometry:(AGSGeometry*)geometry withPadding:(float)padding animated:(BOOL)animated;

/** Zooms the map to the given resolution
 @param res The resolution (map units per pixel) to zoom to
 @param centerPoint to zoom around. If nil and the gps @link AGSGPS::autoPanMode autoPanMode @endlink is @c AGSGPSAutoPanModeNavigation or @c AGSGPSAutoPanModeCompassNavigation, the map zooms around the location symbol.
 If the gps is not in those modes, but the centerPoint is nil, map zooms around its center. 
 @param animated flag indicating whether to animate the zoom action
 @since 2.1
 */
-(void)zoomToResolution:(double)res withCenterPoint:(AGSPoint*)centerPoint animated:(BOOL)animated;

/** Zooms the map to the given scale
 @param scale to zoom to
 @param centerPoint to zoom around. If nil and the gps @link AGSGPS::autoPanMode autoPanMode @endlink is @c AGSGPSAutoPanModeNavigation or @c AGSGPSAutoPanModeCompassNavigation, the map zooms around the location symbol.
 If the gps is not in those modes, but the centerPoint is nil, map zooms around its center. 
 @param animated flag indicating whether to animate the zoom action
 @since 2.1
 */
-(void)zoomToScale:(double)scale withCenterPoint:(AGSPoint*)centerPoint animated:(BOOL)animated;


/** Show callout at specified location. The callout's content will need to be
 specified through its (@c AGSCallout) <code>title</code> and <code>detail</code> 
 properties.
 @param point Map point to display callout at. Point must be in map units and must have the 
 same spatial reference as the map.
 @since 1.0
 */
- (void)showCalloutAtPoint:(AGSPoint *)point;

/** Show callout at specified location for a specific graphic. The graphic's 
 <code>attributes</code> and <code>infoTemplateDelegate</code> will be used to 
 display content in the callout.
 @param mapPoint Map point that will be used for the callout. You can pass <code>nil</code> 
 if you want the center of the graphic to be used. If the graphic is represented 
 by a marker symbol, then the @p mapPoint is ignored in order to best place the 
 callout.
 @param graphic Graphic that the callout is displaying for.
 @param animated Determines whether or not the callout should animate when it is shown.
 @since 1.0
 */
-(void)showCalloutAtPoint:(AGSPoint*)mapPoint forGraphic:(AGSGraphic*) graphic animated:(BOOL)animated;

/** Resets the map to an original and unloaded state. Will remove any and all layers from the map. The spatial reference,
 extents, and othe properties related to the layer will be cleared. The first
 layer subsequently added to the map after invoking this method will be treated as a basemap layer.
 @since 1.8
 */
-(void)reset;

/** Rotate the map in counter-clockwise direction based on the angle (degrees) specified.
 @param angle to rotate the map by
 @param animated flag indicating if the map should animate to new rotation angle
 @since 2.1
 */
-(void)setRotationAngle:(float)angle animated:(BOOL)animated;

/** Rotate the map in counter-clockwise direction based on the angle (degrees) specified.
 @param angle to rotate the map by
 @param screenPoint the location on screen around which the map should be rotated
 @param animated flag indicating if the map should animate to new rotation angle
 @since 2.1
 */
-(void)setRotationAngle:(float)angle aroundScreenPoint:(CGPoint)screenPoint animated:(BOOL)animated;

/** Rotate the map in counter-clockwise direction based on the angle (degrees) specified.
 @param angle to rotate the map by
 @param mapPoint the location on the map around which the map should be rotated. The point
 should have the same spatial reference as the map.
 @param animated flag indicating if the map should animate to new rotation angle
 @since 2.1
 */
-(void)setRotationAngle:(float)angle aroundMapPoint:(AGSPoint*)mapPoint animated:(BOOL)animated;
@end



/** @brief A delegate of @c AGSMapView.
 
 A protocol which must be adopted by a class wishing to be called for layer related actions
 happening on the map.
 
 All of the methods of this protocol are optional.
 
 @define{AGSMapView.h, ArcGIS}
 @since 1.8
 */
@protocol AGSMapViewLayerDelegate <NSObject>

@optional

#pragma mark Layer Related Methods

/** Tells the delegate the map is loaded and ready for use. Fires when the map's base layer loads.
 @param mapView The map that has loaded.
 @since 1.8
 */
- (void)mapViewDidLoad:(AGSMapView *)mapView;

/** Tells the delegate the map failed to load. This happens when the following conditions
 are met. (1) The map never loaded any valid layers. (2) All layers are removed from the map.
 @param mapView The map that failed to load.
 @param error Error describing reason for failure.
 @since 1.8
 @deprecated Deprecated at 2.1. Use #failedLoadingLayerForLayerView:baseLayer:withError: instead.
 */
- (void)mapView:(AGSMapView *)mapView failedLoadingWithError:(NSError *)error __attribute__((deprecated));

/** Tells the delegate a layer that was added to the map was loaded.
 @param mapView Map to which layer has been added.
 @param layerView Layer view that was added to map
 @since 1.8
 */
- (void)mapView:(AGSMapView *)mapView didLoadLayerForLayerView:(UIView<AGSLayerView> *)layerView;

/** Tells the delegate a layer that was added to the map could not be loaded.
 @param mapView Map to which layer had to be added.
 @param layerView Layer view that failed to be added.
 @param error Error describing reason for failure.
 @since 1.8
 @deprecated Deprecated at 2.1. Use #failedLoadingLayerForLayerView:baseLayer:withError: instead.
 */
- (void)mapView:(AGSMapView *)mapView failedLoadingLayerForLayerView:(UIView<AGSLayerView> *)layerView withError:(NSError *)error __attribute__((deprecated));

/** Tells the delegate a layer that was added to the map could not be loaded.
 If the layer that failed is the base layer, the map will be in an unloaded and waiting state until
 the base layer is either removed, resubmitted or replaced.
 @param mapView Map to which layer had to be added.
 @param layerView Layer view that failed to be added.
 @param baseLayer Whether or not the layer is the map's current designated base layer.
 @param error Error describing reason for failure.
 @since 2.1
 */
- (void)mapView:(AGSMapView *)mapView failedLoadingLayerForLayerView:(UIView<AGSLayerView> *)layerView baseLayer:(BOOL)baseLayer withError:(NSError *)error;

/** Asks delegate whether to find which graphics in the specified layer intersect 
 the tapped location. Default is <code>YES</code>.
 @param mapView Map containing callout to be shown.
 @param graphicsLayer Graphics layer in which to find graphics.
 @param screen Location in screen coordinates.
 @param mappoint Map point.
 @since 1.8
 */
- (BOOL)mapView:(AGSMapView *)mapView shouldFindGraphicsInLayer:(AGSGraphicsLayer *)graphicsLayer atPoint:(CGPoint)screen mapPoint:(AGSPoint *)mappoint;

@end






/** @brief A delegate of @c AGSMapView.
 
 A protocol which must be adopted by a class wishing to be called for callout related actions
 happening on the map.
 
 All of the methods of this protocol are optional.
 
 @define{AGSMapView.h, ArcGIS}
 @since 1.8
 */
@protocol AGSMapViewCalloutDelegate <NSObject>
@optional
#pragma mark Callout Related Delegate Methods

/** Asks the delegate whether to show a callout when the user taps the GPS display.
 Default is <code>YES</code>.
 @param mapView Map containing the callout to be shown.
 @param gps GPS display that the callout will be shown for.
 @since 1.8
 */
- (BOOL)mapView:(AGSMapView *)mapView shouldShowCalloutForGPS:(AGSGPS *)gps;

/** Tells the delegate a callout was shown for the GPS display.
 @param mapView Map containing the callout to be shown.
 @param gps GPS display that the callout was shown for.
 @since 1.8
 */
- (void)mapView:(AGSMapView *)mapView didShowCalloutForGPS:(AGSGPS *)gps;

/** Tells the delegate the callout accessory button was tapped on for the GPS callout.
 @param mapView Map containing callout.
 @param gps GPS display for which the callout was shown.
 @since 1.8
 */
- (void)mapView:(AGSMapView *)mapView didClickCalloutAccessoryButtonForGPS:(AGSGPS *)gps;


/** Asks delegate whether to show callout for a graphic that has been tapped on.
 Default is <code>YES</code>.
 @param mapView Map containing callout to be shown.
 @param graphic Graphic to show callout for.
 @return <code>BOOL</code> value whether callout should be shown for the graphic.
 @since 1.8
 */
- (BOOL)mapView:(AGSMapView *)mapView shouldShowCalloutForGraphic:(AGSGraphic *)graphic;

/** Tells the delegate callout was shown for a graphic that was tapped on. 
 @param mapView Map containing callout.
 @param graphic Graphic for which callout was shown.
 @since 1.8
 */
- (void)mapView:(AGSMapView *)mapView didShowCalloutForGraphic:(AGSGraphic *)graphic;

/** Tells the delegate the callout accessory button was tapped on.
 @param mapView Map containing callout.
 @param graphic Graphic for which callout was shown.
 @since 1.8
 */
- (void)mapView:(AGSMapView *)mapView didClickCalloutAccessoryButtonForGraphic:(AGSGraphic *)graphic;

// NOTE: that there are no 'shouldShowCalloutAtPoint:' or 'didShowCalloutAtPoint:' delegate methods.
// This is because the 'showCalloutAtPoint:' method is designed to be called programmatically.
// The following method supports that programmatic access.

/** Tells the delegate the callout accessory button was tapped on.
 @param mapView Map containing callout.
 @param point Map point at which callout was shown.
 @since 1.8
 */
- (void)mapView:(AGSMapView *)mapView didClickCalloutAccessoryButtonAtPoint:(AGSPoint *)point;

/** Tells the delegate that a callout will be dismissed.
 @since 2.0
 */
-(void)mapViewWillDismissCallout:(AGSMapView*)mapView;

/** Tells the delegate that the callout was dismissed.
 @since 1.8
 */
-(void)mapViewDidDismissCallout:(AGSMapView*)mapView;
@end








/** @brief A delegate of @c AGSMapView.
 
 A protocol which must be adopted by a class wishing to be called for touch event related actions
 happening on the map.
 
 All of the methods of this protocol are optional.
 
 @define{AGSMapView.h, ArcGIS}
 @since 1.8
 */
@protocol AGSMapViewTouchDelegate <NSObject>
@optional

#pragma mark Touch Delegate Methods

/** Asks the delegate if the map should process the click at the given location. The default value if
 this method is not implemented is <code>YES</code>.
 @param mapView Map tapped by the user.
 @param screen Location in screen coordinates.
 @param mappoint Location in map coordinates.
 @return <code>BOOL</code> value whether the click should be processed by the map.
 @since 2.0
 */
- (BOOL)mapView:(AGSMapView*)mapView shouldProcessClickAtPoint:(CGPoint)screen mapPoint:(AGSPoint*)mappoint;

/** Tells the delegate the map was single-tapped at specified location.
 @param mapView Map tapped by the user.
 @param screen Location in screen coordinates.
 @param mappoint Location in map coordinates.
 @param graphics Graphics from all graphics layers in the map that intersect or contain 
 the location. The dictionary contains layer name (key) : @c AGSGraphic array (value)
 @since 1.8
 */
- (void)mapView:(AGSMapView *)mapView didClickAtPoint:(CGPoint)screen mapPoint:(AGSPoint *)mappoint graphics:(NSDictionary *)graphics;

/** Tells the delegate that a point on the map was tapped and held at specified
 location.
 @param mapView Map tapped and held by the user.
 @param screen Location in screen coordinates.
 @param mappoint Location in map coordinates.
 @param graphics Graphics from all graphics layers in the map that intersect or contain 
 the location. The dictionary contains layer name (key) : @c AGSGraphic array (value)
 @since 1.8
 */
- (void)mapView:(AGSMapView *)mapView didTapAndHoldAtPoint:(CGPoint)screen mapPoint:(AGSPoint *)mappoint graphics:(NSDictionary *)graphics;

/** Tells the delegate that the user moved his finger while tapping and holding on the map.
 @param mapView Map tapped and held by the user.
 @param screen Location in screen coordinates.
 @param mappoint Location in map coordinates.
 @param graphics Graphics from all graphics layers in the map that intersect or contain 
 the location. The dictionary contains layer name (key) : @c AGSGraphic array (value)
 @since 1.8
 */
- (void)mapView:(AGSMapView *)mapView didMoveTapAndHoldAtPoint:(CGPoint)screen mapPoint:(AGSPoint *)mappoint graphics:(NSDictionary *)graphics;

/** Tells the delegate that a tap and hold event has ended.
 @param mapView Map tapped and held by the user.
 @param screen Screen coordinates of where the user ended the tap and hold.
 @param mappoint Map coordinates of where the user ended the tap and hold.
 @param graphics Graphics from all graphics layers in the map that intersect or contain 
 the location. The dictionary contains layer name (key) : @c AGSGraphic array (value)
 @since 1.8
 */
- (void)mapView:(AGSMapView *)mapView didEndTapAndHoldAtPoint:(CGPoint)screen mapPoint:(AGSPoint *)mappoint graphics:(NSDictionary *)graphics;

@end