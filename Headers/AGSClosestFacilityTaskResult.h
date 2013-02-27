/*
 COPYRIGHT 2011 ESRI
 
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


/** @file AGSClosestFacilityTaskResult.h */

@protocol AGSCoding;

/** @brief The result from an @c AGSClosestFacilityTask operation.
 
 The result from an @c AGSClosestFacilityTask operation.

 @since 1.8
 */
@interface AGSClosestFacilityTaskResult : NSObject<AGSCoding>

/** An array of @c AGSClosestFacilityResult objects containing an @c AGSDirectionsSet 
 (if <code>returnDirections</code> is <code>true</code>) and a route graphic (if 
 <code>returnRouteGraphics</code> is <code>true</code>) as well as the name of the route.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *closestFacilityResults;

/** Facilities (points) as an array of @c AGSGraphic objects. These are only returned when <code>returnFacilities</code> is true.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *facilities;

/** Incidents (points) as an array of @c AGSGraphic objects. These are only returned when <code>returnIncidents</code> is true.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *incidents;

/** Messages as an array of @c AGSNAMessage objects. These are received when the solve is complete. If a closest facility cannot be
 solved, the message returned by the server identifies the incident that could not
 be solved.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *messages;

/** The point barriers as an array of @c AGSGraphic objects. They are returned only if <code>returnPointBarriers</code>
 is <code>true</code> (which is not the default). If you send in the point barriers as a feature set 
 (instead of using a data layer), you already have the barriers and might not need to request them
 back from the server.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *pointBarriers;

/** The polygon barriers as an array of  @c AGSGraphic objects. They are returned only if <code>returnPolygonBarriers</code> 
 was set to <code>true</code> (which is not the default). If you send in the polygon barriers as a featureSet 
 (instead of using DataLayer), you already have the barriers and might not need to request them back from the server.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *polygonBarriers;

/** The polyline barriers as an array of  @c AGSGraphic objects. They are returned only if <code>returnPolylineBarriers</code> 
 was set to <code>true</code> (which is not the default). If you send in the polyline barriers as a featureSet 
 (instead of using DataLayer), you already have the barriers and might not need to request them back from the server.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *polylineBarriers;

@end
