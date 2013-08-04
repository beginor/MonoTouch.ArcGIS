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

/** @brief The default datasource for AGSLocationDisplay. Uses Core Location Services
 to get location information.
 @since 10.1.1
 */

@interface AGSCLLocationManagerLocationDisplayDataSource : NSObject <AGSLocationDisplayDataSource>

/** The location manager used by this datasource. You should not call the start/stop methods
 on the location manager directly (startUpdatingLocation, startUpdatingHeading, stopUpdatingLocation, stopUdpdatingHeading, etc).
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) CLLocationManager *locationManager;
@end
