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


@class AGSLocation;
@class AGSGraphic;
@class AGSMapView;
@class AGSPoint;
@protocol AGSLocationDisplayDataSource;
@protocol AGSLocationDisplayDataSourceDelegate;
@protocol AGSLocationDisplayInfoTemplateDelegate;

/** @file AGSLocationDisplay.h */


/** Modes for automatically  panning the map in response to location updates
 @since 10.1.1
 */
typedef enum {
    AGSLocationDisplayAutoPanModeOff = 0,		/*!<  The map does not auto pan, and the location symbol may move off screen.*/
    AGSLocationDisplayAutoPanModeDefault,		/*!<  The map recenters on the location symbol whenever it moves out of the wander extent*/
    AGSLocationDisplayAutoPanModeNavigation,	/*!<  The location symbol is fixed and always points to the top edge of the device. The map pans and rotates based on location and course updates. */
	AGSLocationDisplayAutoPanModeCompassNavigation /*!< The location symbol is fixed and always points to the top edge of the device. The map pans and rotates based on location and heading (true) updates. */
} AGSLocationDisplayAutoPanMode;


/** @brief Provides a location display over an @c AGSMapView.
 
 This object controls how the map displays location information. It relies on
 its #dataSource which provides location updates on a frequent basis.
 
 To make the map start
 displaying location information, use the <code>startDataSource</code> method, but ensure the map is loaded successfully before you do..
 
 To make the map stop displaying location information, use the
 <code>stopDataSource</code> method.
 
 By default a blue, round symbol is used to display the device's location. The map will always try to get
 most accurate location available. Depending upon signal strength, satellite positions, and other factors, the location
 reported could be a best possible approximation. The map also displays a blue-circle around the location symbol to indicate the range of accuracy.
 As the device moves, the map will respond to location updates and appropriately udpate the position of the location symbol.
 
 @see @concept{Displaying_location_on_the_map/00pw0000004q000000/, Displaying %location on the map}
 @see @sample{5e9fe50031f5461796b5d158a11d0bad, GPS Sample}
 @since 10.1.1
 */
@interface AGSLocationDisplay : NSObject <AGSLocationDisplayDataSourceDelegate>

/** The source of location updates.
 Defaults to @c AGSCLLocationManagerLocationDisplayDataSource.
 You can create your own datasource, or choose from one of the datasources provided.
 @since 10.1.1
 */
@property (nonatomic, strong) id<AGSLocationDisplayDataSource> dataSource;

/** Most recent location update provided by the datasource
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) AGSLocation *location;

/** Most recent error from the datasource. Will be nil'd out when/if a valid location is received from the datasource.
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) NSError *dataSourceError;

/** Defines the map's auto-pan behavior.
 @since 10.1.1
 */
@property (nonatomic, assign) AGSLocationDisplayAutoPanMode autoPanMode;

/** The factor that is used to determine when the map recenters on the location. This is used only
 when autoPanMode is AGSLocationDisplayAutoPanModeDefault. The map automatically recenters when the location symbol moves outside the wander extent.  
 The default value for this property is 0.5. 
 The value expected is between 0 and 1. A value of 0.25 means that an extent 25% of the
 current extent is used as the "wander" extent.  A value of 1 means that the entire
 extent in view is used as the "wander" extent.
 @since 10.1.1
 */
@property (nonatomic, assign) CGFloat wanderExtentFactor;

/** Template describing how the callout should display information for location 
 updates.
 @since 10.1.1
 */
@property (nonatomic, weak) id<AGSLocationDisplayInfoTemplateDelegate> infoTemplateDelegate;

/** Scale to zoom to when first location is received. Defaults to 10,000.
 @since 10.1.1
 */
@property (nonatomic, assign) double zoomScale;

/** Indicates whether or not the display's datasource is started.
 @since 10.1.1
 */
@property (nonatomic, readonly, getter = isDataSourceStarted) BOOL dataSourceStarted;

#if TARGET_OS_IPHONE
/** The orientation of the interface. You must set this if you are using the compass
 navigation mode and your application user interface orientation is not portrait. This is 
 used for offsetting the compass heading based on the user interface orientation.
 @since 10.1.1
 */
@property (nonatomic, assign) UIInterfaceOrientation interfaceOrientation;
#endif

/** The current location the display is at on the map, projected into map coordinates.
 */
-(AGSPoint*)mapLocation;

/** Starts the location display's datasource.
 @since 10.1.1
 */
-(void) startDataSource;

/** Stops the location display's datasource.
 @since 10.1.1
 */
-(void) stopDataSource;

/** The height factor for placing the GPS location symbol when in navigation auto pan mode.
 The default is 0.125 (1/8th), which places it 1/8th of the height of the map view
 from the bottom of the map view.
 @since 2.1
 */
@property (nonatomic, assign) CGFloat navigationPointHeightFactor;

/** Sets an alpha on the location display.
 @since 10.1.1
 */
@property (nonatomic, assign) CGFloat alpha;

@end


/** @brief A template describing the contents of @c AGSCallout for a location display. 
 
 A protocol which must be adopted by any class wishing to display content in the
 callout window for the location display . An instance of the class must then be 
 set as the <code>infoTemplateDelegate</code> on the map's location display object.
 
 The methods are optional. If the custom view method is implemented and does not return nil,
 then the other methods will not be called. This is because if a custom view is displayed
 in the callout then it is the only content in the callout.
 
 @since 10.1.1
 
 */
@protocol AGSLocationDisplayInfoTemplateDelegate <NSObject>
@optional

/** Title text to be displayed in the callout.
 @param ld The location display to display title for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @return The title text.
 @since 10.1.1
 */
- (NSString *)titleForLocationDisplay:(AGSLocationDisplay *)ld screenPoint:(CGPoint)screen;

/** Detail string to be displayed in the callout.
 @param ld The location display to display detail for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @return The detail string.
 @since 10.1.1
 */
- (NSString *)detailForLocationDisplay:(AGSLocationDisplay *)ld screenPoint:(CGPoint)screen;

/** Image to be displayed in the callout. The image will be scaled to 40x40 points.
 @param ld The location display to display image for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @return The image to be displayed in the callout.
 @since 10.1.1
 */
-(AGSImage*)imageForLocationDisplay:(AGSLocationDisplay *)ld screenPoint:(CGPoint)screen;

/** The custom view to be displayed in the callout. If you implement this function then the title, detail
 and image methods will not get called, as only the custom view will be displayed in the callout.
 The callout will expand to fit the dimensions of the custom view.
 @param ld The location display to display the custom view for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @return The custom view to be displayed in the callout.
 @since 10.1.1
 */
-(AGSView*)customViewForLocationDisplay:(AGSLocationDisplay *)ld screenPoint:(CGPoint)screen;

@end
