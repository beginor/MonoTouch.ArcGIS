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

@protocol AGSLocationDisplayDataSource;
@protocol AGSLocationDisplayDataSourceDelegate;
@class CLLocationManager;

/*@file AGSCLLocationManagerLocationDisplayDataSource.h */

/** @brief A datasource for @c AGSLocationDisplay based on Core Location
 
 Instances of this class represent a datasource that provides the most
 up-to-date device location based on Core Location services.
 
 @since 10.1.1
 @see AGSLocationDisplay
x */

@interface AGSCLLocationManagerLocationDisplayDataSource : NSObject <AGSLocationDisplayDataSource>

/** The location manager used by this datasource. You should not call the start/stop methods
 on the location manager directly (startUpdatingLocation, startUpdatingHeading, stopUpdatingLocation, stopUdpdatingHeading, etc).
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) CLLocationManager *locationManager;
@end
