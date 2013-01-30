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
#import <CoreLocation/CoreLocation.h>

/** Modes for gps.
 @since 2.1
 */
typedef enum {
    AGSGPSAutoPanModeOff = 0,		/*!<  The map does not auto pan, and the location symbol may move off screen.*/
    AGSGPSAutoPanModeDefault,		/*!<  The map recenters on the location symbol whenever it moves out of the wander extent*/
    AGSGPSAutoPanModeNavigation,	/*!<  The location symbol is fixed and always points to the top edge of the device. The map pans and rotates based on location and course updates. */
	AGSGPSAutoPanModeCompassNavigation /*!< The location symbol is fixed and always points to the top edge of the device. The map pans and rotates based on location and heading (magnetic) updates. */
} AGSGPSAutoPanMode;


@class AGSPoint;
@class AGSEnvelope;
@class AGSProjectionUtility;
@class AGSGPS;
@class AGSMapView;
@class AGSGPSAccuracyCircleLayer;
@class AGSGeometryEngine;
@class AGSCallout;
@class AGSTimerContainer;

/** @file AGSGPS.h */ //Required for Globals API doc

/** @brief A template describing the contents of @c AGSCallout for gps location. 
 
 A protocol which must be adopted by any class wishing to display content in the
 callout window for the GPS location symbol . An instance of the class must then be 
 set as the <code>infoTemplateDelegate</code> on the map's gps object.
 
 The methods are optional. If the custom view method is implemented and does not return nil,
 then the other methods will not be called. This is because if a custom view is displayed
 in the callout then it is the only content in the callout.
 
 @since 1.0

 */
@protocol AGSGPSInfoTemplateDelegate <NSObject>
@optional

/** Title text to be displayed in the callout.
 @param gps The GPS to display title for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @return The title text.
 @since 1.0
 */
- (NSString *)titleForGPS:(AGSGPS *)gps screenPoint:(CGPoint)screen;

/** Detail string to be displayed in the callout.
 @param gps The GPS to display detail for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @return The detail string.
 @since 1.0
 */
- (NSString *)detailForGPS:(AGSGPS *)gps screenPoint:(CGPoint)screen;

/** Image to be displayed in the callout. The image will be scaled to 40x40 points.
 @param gps The GPS to display image for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @return The image to be displayed in the callout.
 @since 1.8
 */
-(UIImage*)imageForGPS:(AGSGPS *)gps screenPoint:(CGPoint)screen;

/** The custom view to be displayed in the callout. If you implement this function then the title, detail
 and image methods will not get called, as only the custom view will be displayed in the callout.
 The callout will expand to fit the dimensions of the custom view.
 @param gps The GPS to display the custom view for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @return The custom view to be displayed in the callout.
 @since 1.8
 */
-(UIView*)customViewForGPS:(AGSGPS *)gps screenPoint:(CGPoint)screen;

@end

/** @brief Controls how the map responds to GPS input.

 This object controls how the map responds to location updates. It  provides a simple façade over the CoreLocation framework and
 greatly simplifies working with location services.
 
 To make the map start 
 responding, use the <code>start</code> method. Ensure the map is loaded successfully before you call <code>start</code>. 
 
 To make the map stop responding, use the 
 <code>stop</code> method. 
 
 By default, the map uses a blue, round symbol to display the device's location. The map will always try to get 
 most accurate location available. Depending upon signal strength, satellite positions, and other factors, the location
 reported could be a best possible approximation. The map displays a blue-circle around the location symbol to indicate the range of accuracy.
 As the device moves, the map will respond to location updates and appropriately udpate the position of the location symbol.
 
 @see @concept{Displaying_location_on_the_map/00pw0000004q000000/, Display location on the map}
 @see @sample{5e9fe50031f5461796b5d158a11d0bad, GPS Sample}
 @since 1.0
 */
@interface AGSGPS : UIView <CLLocationManagerDelegate> {
@private
	BOOL _enabled;
	AGSGPSAutoPanMode _autoPanMode;
	AGSMapView *_mapView;
	CLLocationManager *_locationManager;
	AGSPoint *_currentPoint;
	CLLocation *_currentLocation;
	CALayer *_imageLayer;
	CALayer *_animationLayer;
	AGSGPSAccuracyCircleLayer *_accuracyCircleLayer;
	AGSEnvelope *_accuracyEnv;
	CALayer *_headingImageLayer;
    CALayer *_compassImageLayer;
	id _animationLayerRenderer;
	AGSProjectionUtility *_projectionUtility;
	BOOL _useApproximationForWebMercator;
	BOOL _useProjectionUtility;
	AGSGeometryEngine *_geometryEngine;
	
    id<AGSGPSInfoTemplateDelegate> _infoTemplateDelegate;
	
	BOOL _zoomedToLocation;
	BOOL _drawImage;
	
	NSArray *_simulationLocations;
	AGSPolyline *_simulationLine;
	AGSTimerContainer *_simulationTimerContainer;
	int _simulationIndex;
	NSNumber *_simulationAccuracy;
	float _simulationInterval;
	
	double _currentSimulatedCourse41;
	
	float _navigationPointHeightFactor;
    
    float _wanderExtentFactor;
    AGSCallout *_callout;
    
    double _lastChangeTime;
    
    UIInterfaceOrientation _interfaceOrientation;
}

/** Indicates whether or not the map will respond to GPS input.
 @since 1.0
 */
@property (nonatomic, readonly) BOOL enabled;

/** Indicates whether or not the map should automatically pan to the latest 
 recieved GPS location. The default is <code>NO</code>.
 @since 1.0
 @deprecated Deprecated at 2.1. Use #autoPanMode property instead.
 */
@property (nonatomic, assign) BOOL autoPan __attribute__((deprecated));

/** Defines the map's auto-pan behavior.
 @since 2.1
 */
@property (nonatomic, assign) AGSGPSAutoPanMode autoPanMode;

/** The latest recieved GPS location, reprojected to match the map's spatial reference. 
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSPoint *currentPoint;

/** Template describing how the callout should display information for location 
 updates.
@since 1.0
 */
@property (nonatomic, assign) id<AGSGPSInfoTemplateDelegate> infoTemplateDelegate;

/** The height factor for placing the GPS location symbol when in navigation auto pan mode.
 The default is 0.125 (1/8th), which places it 1/8th of the height of the map view
 from the bottom of the map view.
 @since 2.1
 */
@property (nonatomic, assign) float navigationPointHeightFactor;

/** The factor that is used to determine when the map recenters on the gps location. This is used only
 when autoPanMode is AGSGPSAutoPanModeDefault. The map automatically recenters when the location symbol moves outside the wander extent.  
 The default value for this property is 0.5. 
 The value expected is between 0 and 1. A value of 0.25 means that an extent 25% of the
 current extent is used as the "wander" extent.  A value of 1 means that the entire
 extent in view is used as the "wander" extent.
 @since 2.1
 */
@property (nonatomic, assign) float wanderExtentFactor;

/** The orientation of the interface. You must set this if you are using the compass
 navigation mode and your application user interface orientation is not portrait. This is 
 used for offsetting the compass heading based on the user interface orientation.
 @since 2.1
 */
@property (nonatomic, assign) UIInterfaceOrientation interfaceOrientation;

//## @cond
-(id)initWithMapView: (AGSMapView *)mapView;
//## @endcond

/** Make the map start responding to GPS input. The map must be loaded before you invoke this method.
 @since 1.0
 */
-(void) start;

/** Make the map stop responding to GPS input.
 @since 1.0
 */
-(void) stop;

/** Retrieve the current GPS location. This is the raw location information provided by iOS and
 is typically in the WGS84 coordinate system.
 @since 1.0
 */
-(CLLocation*)currentLocation;

@end


