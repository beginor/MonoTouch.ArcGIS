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

@class AGSGeometry;

/** @file AGSGeometryRelationship.h */ //Required for Globals API doc

/** @brief Object returned by <code>AGSGeometryServiceTask</code>'s 
 <code>relationWithParameters:</code> operation.
 
 The <code>relationWithParameters:</code> operation on @c AGSGeometryServiceTask
 returns an array of <code>%AGSGeometryRelationship</code> objects. These
 objects demonstrate the relationship of @p geometry1 in relation to 
 @p geometry2 characterized by the given @p type.
 
 Possible values of @p type include members of the @c AGSGeometryRelation
 enumeration.
 
 @define{AGSGeometryRelationship.h, ArcGIS}
 @since 1.0
 */
@interface AGSGeometryRelationship : NSObject

/** The geometry whose relation is being questioned.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSGeometry *geometry1;

/** The geometry being used to relate to.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSGeometry *geometry2;

/** Relationship between @p geometry1 and @p geometry2. Possible values include
 
 @li @c		AGSGeometryRelationCross
 @li @c		AGSGeometryRelationDisjoint
 @li @c		AGSGeometryRelationIn
 @li @c		AGSGeometryRelationInteriorIntersection
 @li @c		AGSGeometryRelationIntersection
 @li @c		AGSGeometryRelationLineCoincidence
 @li @c		AGSGeometryRelationLineTouch
 @li @c		AGSGeometryRelationOverlap
 @li @c		AGSGeometryRelationPointTouch
 @li @c		AGSGeometryRelationTouch
 @li @c		AGSGeometryRelationWithin
 @li @c		AGSGeometryRelationRelation		
 
 @since 1.0
 */
@property (nonatomic, assign, readonly) AGSGeometryRelation type;



@end
