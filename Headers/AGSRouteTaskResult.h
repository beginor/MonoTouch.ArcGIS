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




/** @file AGSRouteTaskResult.h */

@protocol AGSCoding;

/** @brief Result of an @c AGSRouteTask solve operation.
 
 Instances of this class represent a result of a single @c AGSRouteTask solve operation. The result
 is a collection of computed routes, barriers used in the analysis, and messages generated during the analysis.
 
 @since 1.8
 */
@interface AGSRouteTaskResult : NSObject <AGSCoding>

/** Array of @c AGSRouteResult objects. Each object represents a separate route with
 independent driving directions. See @c routeName property of @c AGSRouteTaskParameters to see how to
 group stops into separate routes.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *routeResults;

/** Array of @c AGSGraphic objects representing the point barriers. Barriers are only returned if 
 the <code>returnPointBarriers</code> parameter of @c AGSRouteTaskParameters is <code>true</code>.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *pointBarriers;

/** Array of @c AGSGraphic objects representing the polyline barriers. Barriers are only returned if 
 the <code>returnPolylineBarriers</code> parameter of @c AGSRouteTaskParameters 
 is <code>true</code>.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *polylineBarriers;

/** Array of @c AGSGraphic objects representing the polygon barriers. Barriers are only returned if 
 the <code>returnPolygonBarriers</code> parameter of @c AGSRouteTaskParameters 
 is <code>true</code>.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *polygonBarriers;

/** Messages received when solve is completed. If a route cannot be solved, the message
 returned by the server identifies the route that could not be solved. This is 
 an array of @c AGSNAMessage objects.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *messages;

@end
