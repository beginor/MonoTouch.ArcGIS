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

/** @file AGSMultipoint.h */ //Required for Globals API doc

/** @brief A multipoint object.
 
 Instances of this class represent a multipoint. A multipoint is defined by 
 ordered collection of points, and an optional spatial reference. 
 
 <code>%AGSMultipoint</code> represents an immutable multipoint, it cannot be 
 altered after being created. Use @c AGSMutablePoint for a mutable multipoint. You 
 can get a mutable version from <code>%AGSMultipoint</code> by passing the  
 <code>mutableCopy</code> message to an instance.
 
 @define{AGSMultipoint.h, ArcGIS}
 @since 1.0
 @see AGSMutableMultipoint for a mutable version.
 */
@interface AGSMultipoint : AGSGeometry

/** Number of points in collection.
 @since 1.0
*/
@property (nonatomic, readonly) NSInteger numPoints;

/** Return point from collection at @p index.
 @param index The index of a point in collection.
 @return Point in collection.
 @since 1.0
 */
- (AGSPoint *)pointAtIndex:(NSInteger)index;

/** Returns a value whether another multipoint is equal to this multipoint.
 @param other The other multipoint to compare to.
 @return Whether or not the other multipoint is equal to this multipoint.
 @since 1.8
 */
-(BOOL)isEqualToMultipoint:(AGSMultipoint*)other;

@end



#pragma mark -

/** @brief A mutable multipoint object.
 
 A mutable version of @c AGSMultipoint.
 @define{AGSMultipoint.h, ArcGIS}
 @since 1.0
 */
@interface AGSMutableMultipoint : AGSMultipoint {
}

/** Add @p point to collection. The point is added to the end of the collection.
 @param point The point to add to collection.
 @since 1.0
 */
- (void)addPoint:(AGSPoint *)point;

/** Insert @p point into collection at the specified @p index.
 @param point The point to add to collection.
 @param index The index in which to add @p point.
 @since 1.0
 */
- (void)insertPoint:(AGSPoint *)point atIndex:(NSInteger)index;

/** Remove point from specified @p index in the collection.
 @param index The index of the point to remove from the collection.
 @since 1.0
*/
- (void)removePointAtIndex:(NSInteger)index;

/** Update a point at @p index with @p point.
 @param point The point to be placed at @p index.
 @param index The index of the point to be updated.
 @since 1.0
 */
- (void)updatePoint:(AGSPoint *)point atIndex:(NSInteger)index;

/** Geometry's spatial reference.
 @since 1.0
 */
@property (nonatomic, strong, readwrite) AGSSpatialReference *spatialReference;

@end
