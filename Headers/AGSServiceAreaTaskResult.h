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

/** @file AGSServiceAreaTaskResult.h */

@protocol AGSCoding;
@class AGSNAMessage;

/** @brief The result from an @c AGSServiceAreaTask operation.
 
 The result from an @c AGSServiceAreaTask operation.

 @since 1.8
 */
@interface AGSServiceAreaTaskResult : NSObject<AGSCoding>

/** The facilities (points) as an array of @c AGSGraphic objects. These are only returned if the <code>returnFacilities</code> property
 on @c AGSServiceAreaTaskParameters is set to <code>true</code>.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *facilities;

/** Messages as an array of @c AGSNAMessage objects. These messages are received when solve is completed. If a service area cannot be solved, 
 the message returned by the server identifies the incident that could not be solved.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *messages;

/** The point barriers as an array of @c AGSGraphic objects. They are returned only if 
 <code>returnPointBarriers</code> was set to <code>true</code> (which is not the 
 default). If you send in the point barriers as a featureSet (instead of using 
 @c AGSDataLayer), you already have the barriers and might not need to request 
 them back from the server.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *pointBarriers;

/** The polygon barriers as an array of @c AGSGraphic objects. They are returned only if 
 <code>returnPolygonBarriers</code> was set to <code>true</code> (which is not 
 the default). If you send in the polygon barriers as a featureSet (instead of 
 using @c AGSDataLayer), you already have the barriers and might not need to 
 request them back from the server.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *polygonBarriers;

/** The polyline barriers as an array of @c AGSGraphic objects. They are returned only if 
 <code>returnPolylineBarriers</code> was set to <code>true</code> (which is not 
 the default). If you send in the polyline barriers as a featureSet (instead of 
 using @c AGSDataLayer), you already have the barriers and might not need to 
 request them back from the server.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *polylineBarriers;

/** The resulting service area polygons as an array of @c AGSGraphic objects.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *serviceAreaPolygons;

/** The resulting service area polylines as an array of @c AGSGraphic objects.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *serviceAreaPolylines;

@end
