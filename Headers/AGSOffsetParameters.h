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

/** @file AGSOffsetParameters.h */ //Required for Globals API doc

/** @brief Parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>offsetWithParameters:</code> operation.
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>offsetWithParameters:</code> operation. 
 
 @define{AGSOffsetParameters.h, ArcGIS}
 @since 1.0
 @see AGSGeometryServiceTask
 */
@interface AGSOffsetParameters : NSObject <AGSCoding>

/** Specifies the distance for constructing an offset based on the input geometries.
 If the @p offsetDistance parameter is positive the constructed offset will be 
 on the right side of the curve. (Left side offsets are constructed with 
 negative values.)
 @since 1.0
 */
@property (nonatomic, assign) double offsetDistance;

/** (Optional) A unit for offset distance. If unit is not specified, the units are 
 derived from the spatial reference.
 @since 1.0
 */
@property (nonatomic, assign) AGSSRUnit offsetUnit;


/** Options that determine how the ends intersect.
 
 Possible @p offsetHow types include:
 
 @li @c AGSGeometryOffsetTypeMitered
 @li @c AGSGeometryOffsetTypeBevelled
 @li @c AGSGeometryOffsetTypeRounded
 
 @since 1.0
 */
@property (nonatomic, assign) AGSGeometryOffsetType offsetHow;

/** @p bevelRatio is multiplied by the #offsetDistance and the result determines 
 how far a mitered offset intersection can be located before it is bevelled. When 
 mitered is specified, the input bevel ratio is ignored and 10 is used internally. 
 When bevelled is specified, 1.1 will be used if @p bevelRatio is not specified. 
 @p bevelRatio is ignored for rounded.
 @since 1.0
 */
@property (nonatomic, assign) double bevelRatio; 

/** If set to <code>true</code>, the resulting geometries will be simplified.
 @since 1.0
 */
@property (nonatomic, assign) BOOL simplifyResult;

/** The array of geometries to be offset.
 @since 1.0
 */
@property (nonatomic, copy) NSArray *geometries;

/** Returns an autoreleased instance of the <code>%AGSOffsetParameters</code> object.
 @since 1.0
 */
+ (id)offsetParameters;

@end