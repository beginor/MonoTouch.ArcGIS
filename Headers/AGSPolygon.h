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
@class AGSPoint;
@class AGSEnvelope;

/** @file AGSPolygon.h */ //Required for Globals API doc

/** @brief A polygon object.
 
 Instances of this class represent a polygon object. A polygon is defined by a 
 collection of rings and an optional spatial reference. Each ring is a bounded 
 area represented by a collection of points. The first and last points of a ring 
 must coincide so that the ring is @em closed. Each point constitutes a vertex of 
 the polygon.
 
 <code>%AGSPolygon</code> represents an immutable polygon, it cannot be altered 
 after being created. Use @c AGSMutablePolygon for a mutable polygon. You can get 
 a mutable version from <code>%AGSPolygon</code> by passing the 
 <code>mutableCopy</code> message to an instance of <code>%AGSPolygon</code>.
 
 @define{AGSPolygon.h, ArcGIS}
 @since 1.0
 */
@interface AGSPolygon : AGSGeometry

/** Number of rings in polygon.
 @since 1.0
 */
@property (nonatomic, readonly) NSInteger numRings;

/** Get number of points in the specified ring.
 @param ring The index of desired ring in the polygon.
 @return Number of points in ring.
 @since 1.0
 */
- (NSInteger)numPointsInRing:(NSInteger)ring;

/** Returns the total number of points in the polygon.
 @since 10.1.1
 */
- (NSInteger)numPoints;

/** Get point from ring.
 @param ring The index of desired ring.
 @param index The index of the desired point.
 @return Point in @p ring at @p index.
 @since 1.0
 */
- (AGSPoint *)pointOnRing:(NSInteger)ring atIndex:(NSInteger)index;

/** Initialize a new autoreleased polygon geometry.
 @param json The JSON representation for polygon. See <a href="http://services.arcgisonline.com/ArcGIS/SDK/REST/geometry.html">
 REST API documentation</a> for JSON syntax.
 @return A new, autoreleased, polygon geometry object.
 @since 1.0
 */
+ (id)polygonWithJSON:(NSDictionary *)json;

/** Checks whether @p point is contained in the polygon. The point and the 
 polygon must have the same spatial reference.
 @param point The point to test containment.
 @return <code>YES</code> if @p point is contained within the polygon.
 @since 1.0
 */
- (BOOL)containsPoint:(AGSPoint *)point;

/** Returns a value whether another polygon is equal to this polygon.
 @param other The other polygon to compare to.
 @return Whether or not the other polygon is equal to this polygon.
 @since 1.8
 */
-(BOOL)isEqualToPolygon:(AGSPolygon*)other;
@end


#pragma mark -

/** @brief A mutable polygon object.
 
 A mutable version of @c AGSPolygon.
 
 @define{AGSPolygon.h, ArcGIS}
 @since 1.0
 */
@interface AGSMutablePolygon : AGSPolygon {
}

/** Create new ring and add it to the polygon.
 @since 1.0
 */
- (void)addRingToPolygon;

/** Inserts a ring at a specific index.
 @since 1.8
 */
-(void)insertRingAtIndex:(NSInteger)ringIndex;

/** Add @p point to end of current ring. 
 @param point The point to be added.
 @since 1.0
 */
- (void)addPointToRing:(AGSPoint *)point;

/** Add @p point at end of specified @p ring.
 @param point The point to be added.
 @param ring The index of the ring to add @p point to.
 @since 1.0
 */
- (void)addPoint:(AGSPoint *)point toRing:(NSInteger)ring;

/** Insert @p point into @p ring at specific @p index.
 @param point The point to be added.
 @param ring The index of the ring to add @p point to.
 @param index The index to add @p point at.
 @since 1.0
 */
- (void)insertPoint:(AGSPoint *)point onRing:(NSInteger)ring atIndex:(NSInteger)index;

/** Remove point from specified ring.
 @param ring The index of the ring to remove @p point from.
 @param index The index of the point to remove.
 @since 1.0
 */
- (void)removePointOnRing:(NSInteger)ring atIndex:(NSInteger)index;

/** Update point on specified @p ring at @p index with @p point.
 @param point The point to replace value at current index.
 @param ring The index of the ring to update @p point at.
 @param index The index of the point to update.
 @since 1.0
 */
- (void)updatePoint:(AGSPoint*)point onRing:(NSInteger)ring atIndex:(NSInteger)index;

/** Remove ring from polygon.
 @param index The index of the ring to be removed.
 @since 1.0
 */
- (void)removeRingAtIndex:(NSInteger)index;

/** Close the polygon if it is not closed. This means making the first vertex per part the same as the last vertex in that part.
 The server wants polygons to be closed when we send them to the server.
 @since 1.8
 */
-(void)closePolygon;


/** Geometry's spatial reference.
 @since 1.0
 */
@property (nonatomic, strong, readwrite) AGSSpatialReference *spatialReference;

@end
