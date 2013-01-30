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

/** @file AGSPolyline.h */ //Required for Globals API doc

/** @brief A polyline object
 
 Instances of this class represent polyline objects. A polyline is defined by 
 a collection of paths and an optional spatial reference. A path represents a 
 continuous line and is defined by an array of points. Each point constitutes 
 a vertex of the polyline.
 
 <code>%AGSPolyline</code> represents an immutable polyline, it cannot be altered 
 after being created. Use @c AGSMutablePolyline for a mutable polyline. You can get 
 a mutable version from <code>%AGSPolyline</code> by passing the 
 <code>mutableCopy</code> message to an instance of <code>%AGSPolyline</code>.

 @define{AGSPolyline.h, ArcGIS}
 @since 1.0
 */
@interface AGSPolyline : AGSGeometry

/** Number of paths in polyline.
 @since 1.0
 */
@property (nonatomic, readonly) NSInteger numPaths;

/** Get number of points in the specified @p path.
 @param path The index of the desired path.
 @return Number of points in path.
 @since 1.0
 */
- (NSInteger)numPointsInPath:(NSInteger)path;

/** Returns the total number for points in the polyline.
 @since 10.1.1
 */
- (NSInteger)numPoints;

/** Get point from @p path at specified @p index.
 @param path The index of desired path.
 @param index The index of the desired point.
 @return Point in @p path at @p index.
 @since 1.0
 */
- (AGSPoint *)pointOnPath:(NSInteger)path atIndex:(NSInteger)index;

/** Initialize a new autoreleased polyline geometry.
 @param json The JSON representation for polyline. See <a href="http://services.arcgisonline.com/ArcGIS/SDK/REST/geometry.html">
 REST API documentation</a> for JSON syntax.
 @return A new, autoreleased, polyline geometry object.
 @since 1.0
 */
+ (id)polylineWithJSON:(NSDictionary *)json;

/** Returns a value whether another polyline is equal to this polyline.
 @param other The other polyline to compare to.
 @return Whether or not the other polyline is equal to this polyline.
 @since 1.8
 */
-(BOOL)isEqualToPolyline:(AGSPolyline*)other;
@end


#pragma mark -

/** @brief A mutable polyline object.
 
 A mutable version of @c AGSPolyline.
 
 @define{AGSPolyline.h, ArcGIS}
 @since 1.0
 */
@interface AGSMutablePolyline : AGSPolyline {

}

/** Create new path and add it to the polyline. 
 @since 1.0
 */
- (void)addPathToPolyline;

/** Inserts a path at a specific index.
 @since 1.8
 */
-(void)insertPathAtIndex:(NSInteger)pathIndex;

/** Add @p point to end of current path.
 @param point The point to be added.
 @since 1.0
 */
- (void)addPointToPath:(AGSPoint *)point;

/** Add @p point to the end of @p path.
 @param point The point to be added.
 @param path The index of the path to add @p point to.
 @since 1.0
 */
- (void)addPoint:(AGSPoint *)point toPath:(NSInteger)path;

/** Insert @p point into @p path at specific @p index.
 @param point The point to be added.
 @param path The index of the path to add @p point to.
 @param index The index to add @p point at.
 @since 1.0
 */
- (void)insertPoint:(AGSPoint *)point onPath:(NSInteger)path atIndex:(NSInteger)index;

/** Remove point from specified @p path.
 @param path The index of the path to remove point from.
 @param index The index to remove point from.
 @since 1.0
 */
- (void)removePointOnPath:(NSInteger)path atIndex:(NSInteger)index;

/** Update point on specified path and index with @p point.
 @param point The point to update current point.
 @param pathIndex The index of the path that contains the point to be updated.
 @param ptIndex The index to update point at.
 @since 1.0
 */
- (void)updatePoint:(AGSPoint *)point onPath:(NSInteger)pathIndex atIndex:(NSInteger)ptIndex;

/** Remove path from polyline.
 @param index The index of the path to be removed.
 @since 1.0
 */
- (void)removePathAtIndex:(NSInteger)index;

/** Geometry's spatial reference.
 @since 1.0
 */
@property (nonatomic, strong, readwrite) AGSSpatialReference *spatialReference;

@end
