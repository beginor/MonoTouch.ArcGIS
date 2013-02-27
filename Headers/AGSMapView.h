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

/*@file AGSMapView.h */

@class AGSMapViewBase;

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
 
 The map component also broadcasts 2 notifications -  @c #AGSMapViewDidEndPanningNotification and @c #AGSMapViewDidEndZoomingNotification . Observers interested
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
 
 <h3>Notifications</h3>
 The map view posts @c #AGSMapViewDidEndZoomingNotification , @c #AGSMapViewDidEndPanningNotification
 
 @see @concept{Creating_A_Map/00pw00000005000000/, Creating a Map}
 @since 1.0
 
 */
@interface AGSMapView : AGSMapViewBase


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

/** Asks delegate whether to find which graphics in the specified layer intersect 
 the tapped location. Default is <code>YES</code>.
 This function may or may not be called on the main thread.
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

/** Asks the delegate whether to show a callout when the user taps the location display.
 Default is <code>YES</code>.
 @param mapView Map containing the callout to be shown.
 @param ld AGSLocationDisplay that the callout will be shown for.
 @since 1.8
 */
- (BOOL)mapView:(AGSMapView *)mapView shouldShowCalloutForLocationDisplay:(AGSLocationDisplay *)ld;

/** Tells the delegate a callout was shown for the location display.
 @param mapView Map containing the callout to be shown.
 @param ld AGSLocationDisplay that the callout was shown for.
 @since 1.8
 */
- (void)mapView:(AGSMapView *)mapView didShowCalloutForLocationDisplay:(AGSLocationDisplay *)ld;


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

/** Tells the delegate that a tap and hold event was cancelled. This may happen when you have the magnifier visible and attempt to take
 a screenshot using the home/lock button combination.
 @param mapView Map tapped and held by the user.
 @since 10.1.1
 */
- (void)mapViewDidCancelTapAndHold:(AGSMapView *)mapView;

@end