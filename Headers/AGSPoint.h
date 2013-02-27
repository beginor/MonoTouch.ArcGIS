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

@class AGSGeometry;
@class AGSSpatialReference;
@class AGSEnvelope;

/** @file AGSPoint.h */ //Required for Globals API doc

/** @brief A point object.
 
 Instances of this class represent a point. The point is defined by a pair of x 
 and y coordinates, and an optional spatial reference. 
 
 <code>%AGSPoint</code> represents an immutable point, it cannot be altered after 
 being created. Use @c AGSMutablePoint for a mutable point. You can get a mutable 
 version from <code>%AGSPoint</code> by passing the <code>mutableCopy</code> 
 message to an instance of <code>%AGSPoint</code>.

 @define{AGSPoint.h, ArcGIS}
 @since 1.0
 @see AGSMutablePoint for a mutable version.
 */
@interface AGSPoint : AGSGeometry 

/** X coordinate for point in map units.
 @since 1.0
 */
@property (nonatomic, readonly) double x;

/** Y coordinate for point in map units.
 @since 1.0
 */
@property (nonatomic, readonly) double y;

/** Initialize a new point geometry.
 @param x The x coordinate in map units.
 @param y The y coordinate in map units.
 @param spatialReference The coordinates' spatial reference.
 @return A new point geometry object.
 @since 1.0
*/
- (id)initWithX:(double)x y:(double)y spatialReference:(AGSSpatialReference *)spatialReference;

/** Initialize a new autoreleased point geometry.
 @param x The x coordinate in map units.
 @param y The y coordinate in map units.
 @param spatialReference The coordinates' spatial reference.
 @return A new, autoreleased, point geometry object.
 @since 1.0
 **/
+ (id)pointWithX:(double)x y:(double)y spatialReference:(AGSSpatialReference *)spatialReference;

/** Returns whether or not the other point is equal to this point.
 @param other The other point to compare.
 @return Whether or not the two points are equal.
 @since 1.8
 */
-(BOOL)isEqualToPoint:(AGSPoint*)other;

/** Calculates the distance between this point and another point.
 @param other The other point to get the distance to.
 @return The distance between the points, in the units of the spatial reference of the points.
 */
-(double)distanceToPoint:(AGSPoint*)other;

@end



#pragma mark -

/** @brief A mutable point object.
 
 A mutable version of @c AGSPoint.
 @define{AGSPoint.h, ArcGIS}
 @since 1.0
 */
@interface AGSMutablePoint : AGSPoint

/** Update current coordinates with @p x and @p y.
 @param x The x coordinate in map units.
 @param y The y coordinate in map units.
 @since 1.0
 */
- (void)updateWithX:(double)x y:(double)y;

/** Offset current coordinates by argument x and y values.
 @param xOffset The offset along x coordinate.
 @param yOffset The offset along y coordinate.
 @since 1.0
 */
- (void)offsetByX:(double)xOffset y:(double)yOffset;

/** 
 @since 1.8
 */
-(void)normalize;

/**
 @since 1.8
 */
-(void)normalizeToEnvelope:(AGSEnvelope*)env;

/** Geometry's spatial reference.
 @since 1.0
 */
@property (nonatomic, strong, readwrite) AGSSpatialReference *spatialReference;

@end

