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
@class AGSPolyline;

/*@file AGSSimulatedLocationDisplayDataSource.h */

/** @brief Simulates location updates based on a list of locations or a polyline geometry
 
 Instances of this class represent a datasource that can simulate location updates based on 
 a predefined list of locations or a polyline geometry.
 This is useful for testing or demo purposes.
 
 @since 10.1.1
 @see AGSLocationDisplay
 */

@interface AGSSimulatedLocationDisplayDataSource : NSObject <AGSLocationDisplayDataSource>
/**
 An array of @c AGSLocation objcts that this datasource will use to simulate location updates.
 A location update will be fired every second.
 @since 10.1.1
 */
@property (nonatomic, copy) NSArray *locations;

/** Each vertex in the supplied polyline is used to simulate a location update. This 
 is useful, for example, if you have a polyline geometry representing a route and you want to simulate device movement along the route. A location update will be fired every second.
 @param polyline 
 @since 10.1.1
 */
-(void)setLocationsFromPolyline:(AGSPolyline*)polyline;

@end
