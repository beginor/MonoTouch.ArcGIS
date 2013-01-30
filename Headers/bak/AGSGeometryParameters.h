/*
 COPYRIGHT 2010 ESRI
 
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

/** @file AGSGeometryParameters.h  */ //Required for Globals API doc

#pragma mark -

/** @brief Parameters for computing areas and lengths 
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>areasAndLengthsWithParameters:</code> operation. 
 
 @define{AGSGeometryParameters.h, ArcGIS}
 @since 1.0
 @see AGSGeometryServiceTask
 */
@interface AGSAreasAndLengthsParameters : NSObject <AGSCoding> {
 @private
	NSArray *_polygons;
	AGSSRUnit _lengthUnit;
	AGSAreaUnits _areaUnit;
}

/** The array of @c AGSPolygon objects whose areas and lengths are to be computed.
 @since 1.0
 */
@property (nonatomic, retain) NSArray *polygons;

/** The length unit in which perimeters of polygons will be calculated. 
 It can be any @c AGSSRUnit constant. If <code>lengthUnit</code> is not specified,
 the units are derived from the spatial reference of the input polygons.
 
 Possible value:
 
 For a complete list, see @c AGSSRUnit
 @since 1.0
 @see AGSSRUnit
 */
@property (nonatomic, assign) AGSSRUnit lengthUnit;

/** The area unit in which areas of polygons will be calculated. It can be any 
 @c AGSAreaUnits constant. If unit is not specified, the units are derived from sr.
 
 Possible values:

 @li @c AGSAreaUnitsSquareInches
 @li @c AGSAreaUnitsSquareFeet
 @li @c AGSAreaUnitsSquareYards
 @li @c AGSAreaUnitsAcres
 @li @c AGSAreaUnitsSquareMiles
 @li @c AGSAreaUnitsSquareMillimeters
 @li @c AGSAreaUnitsSquareCentimeters
 @li @c AGSAreaUnitsSquareDecimeters
 @li @c AGSAreaUnitsSquareMeters
 @li @c AGSAreaUnitsAres
 @li @c AGSAreaUnitsHectares
 @li @c AGSAreaUnitsSquareKilometers

 @since 1.0
 @see AGSAreaUnits
 */
@property (nonatomic, assign) AGSAreaUnits areaUnit;

/** Initialize an autoreleased <code>AGSAreasAndLengthsParameters</code> object.
 @since 1.0
 */
+ (id)areasAndLengthsParameters;

@end

#pragma mark -

/** @brief Parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>lengthsWithParameters:</code> operation.
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>lengthsWithParameters:</code> operation. 
 
 @define{AGSGeometryParameters.h, ArcGIS}
 @since 1.0
 @see AGSGeometryServiceTask
 */
@interface AGSLengthsParameters : NSObject <AGSCoding> {
 @private
	NSArray *_polylines;
	BOOL _geodesic;
	AGSSRUnit _lengthUnit;
}

/** The array of polylines whose lengths are to be computed. 
 @since 1.0
 */
@property (nonatomic, retain) NSArray *polylines;

/** If #polylines are in geographic coordinate system, then #geodesic 
 needs to be set to <code>true</code> in order to calculate the ellipsoidal 
 shortest path distance between each pair of the vertices in the polylines. 
 If #lengthUnit is not specificed, then output is always returned in meters.
 @since 1.0
 */
@property (nonatomic, assign) BOOL geodesic;

/** The length unit in which perimeters of polylines will be calculated. It 
 can be any @c AGSSRUnit constant. If @p lengthUnit is not specified, the units are 
 derived from the spatial reference of the input polylines.
 @since 1.0
 */
@property (nonatomic, assign) AGSSRUnit lengthUnit;

/** @todo
 @since 1.8
 */
- (id)initWithPolyline:(AGSPolyline*)polyline;

/** Returns an autoreleased instance of the <code>AGSLengthParameters</code> object.
 @since 1.0
 */
+ (id)lengthParameters;

/** Returns an autoreleased instance of the <code>AGSLengthParameters</code> object 
 initialized with a single polyline.
 @since 1.8
 */
+ (id)lengthParametersWithPolyline:(AGSPolyline*)polyline;

@end

#pragma mark -

/** @brief Parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>distanceWithParameters:</code> operation.
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>distanceWithParameters:</code> operation. 
 
 @define{AGSGeometryParameters.h, ArcGIS}
 @since 1.0
 @see AGSGeometryServiceTask
 */
@interface AGSDistanceParameters : NSObject <AGSCoding> {
 @private
	AGSSRUnit _distanceUnit;
	AGSGeometry *_geometry1;
	AGSGeometry *_geometry2;
	BOOL _geodesic;
}

/** Specifies the units for measuring distance between #geometry1 and #geometry2. 
 If the unit is not specified the units are derived from the spatial reference 
 of the input geometries.
 @since 1.0
 */
@property (nonatomic, assign) AGSSRUnit distanceUnit;

/** The geometry from which the distance is to measured. The geometry can be one 
 of the following geometry types: @c AGSPoint, @c AGSPolyline, @c AGSPolygon or 
 @c AGSMultipoint.
 @since 1.0
 */
@property (nonatomic, retain) AGSGeometry *geometry1;

/** The geometry to which the distance is measured. The geometry can be one of 
 the following geomtry types: @c AGSPoint, @c AGSPolyline, @c AGSPolygon or 
 @c AGSMultipoint.
 @since 1.0
 */
@property (nonatomic, retain) AGSGeometry *geometry2;

/** Default value is <code>false</code>. When <code>true</code> the geodesic 
 distance between #geometry1 and #geometry2 is measured.
 @since 1.0
 */
@property (nonatomic, assign) BOOL geodesic;

/** Returns an autoreleased instance of the distance parameters object.
 @since 1.0
 */
+ (id)distanceParameters;

@end

#pragma mark -

/** Possible relationships between geometries.
 @since 1.0
 */
typedef enum {
    AGSGeometryRelationCross = 0,				/*!<  */
    AGSGeometryRelationDisjoint,				/*!<  */
    AGSGeometryRelationIn,						/*!<  */
    AGSGeometryRelationInteriorIntersection,	/*!<  */
    AGSGeometryRelationIntersection,			/*!<  */
    AGSGeometryRelationLineCoincidence,			/*!<  */
    AGSGeometryRelationLineTouch,				/*!<  */
    AGSGeometryRelationOverlap,					/*!<  */
    AGSGeometryRelationPointTouch,				/*!<  */
    AGSGeometryRelationTouch,					/*!<  */
    AGSGeometryRelationWithin,					/*!<  */
    AGSGeometryRelationRelation					/*!<  */
} AGSGeometryRelation;
	
#pragma mark -

/** @brief Parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>relationWithParameters:</code> operation.
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>relationWithParameters:</code> operation.
 
 @define{AGSGeometryParameters.h, ArcGIS}
 @since 1.0
 @see AGSGeometryServiceTask
 */
@interface AGSRelationParameters : NSObject <AGSCoding> {
 @private
	NSArray *_geometries1;
	NSArray *_geometries2;
	AGSGeometryRelation _relation;
	NSString *_relationParam;
}

/** The first array of geometries to compute the relations. All geometries in 
 this array should be of the type defined by @p geometryType.
 @since 1.0
 */
@property (nonatomic, retain) NSArray *geometries1;

/** The second array of geometries to compute the relations. All geometries in 
 this  array should be of the type defined by @p geometryType.
 @since 1.0
 */
@property (nonatomic, retain) NSArray *geometries2;

/** The spatial relationship to be tested between the two input geometry arrays. Note that
 if the #relation is specified as @c AGSGeometryRelationRelation, the #relationParam 
 parameter describes the spatial relationship and must be specified.
 
 Possible values include
 @li @c AGSGeometryRelationCross  
 @li @c AGSGeometryRelationDisjoint
 @li @c AGSGeometryRelationIn
 @li @c AGSGeometryRelationInteriorIntersection
 @li @c AGSGeometryRelationIntersection
 @li @c AGSGeometryRelationLineCoincidence
 @li @c AGSGeometryRelationLineTouch
 @li @c AGSGeometryRelationOverlap
 @li @c AGSGeometryRelationPointTouch
 @li @c AGSGeometryRelationTouch
 @li @c AGSGeometryRelationWithin
 @li @c AGSGeometryRelationRelation
 @since 1.0
 */
@property (nonatomic, assign) AGSGeometryRelation relation;

/** The 'Shape Comparison Language' string to be evaluated. Strings such as 
 <code>RELATE (G1, G2, "FFFTTT***")</code> are accepted, in addition to other 
 kinds of strings. The string describes the spatial relationship
 to be tested when the #relation parameter is specified as @c AGSGeometryRelationRelation.
 @since 1.0
 @see AGSQuery#relationParam for more information.
 */
@property (nonatomic, copy) NSString *relationParam;

/** Returns an autoreleased instance of the relation parameters object.
 @since 1.0
 */
+ (id)relationParameters;

@end

#pragma mark -

/** @brief Parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>trimExtendWithParameters:</code> operation.
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>trimExtendWithParameters:</code> operation. 
 
 @define{AGSGeometryParameters.h, ArcGIS}
 @since 1.0
 @see AGSGeometryServiceTask
 */
@interface AGSTrimExtendParameters : NSObject <AGSCoding> {
 @private
	NSArray *_polylines;
	AGSPolyline *_trimExtendTo;
	NSUInteger _extendHow;
}

/** An array of polylines to be trimmed or extended.
 @since 1.0
 */
@property (nonatomic, retain) NSArray *polylines;

/** A polyline which is used as a guide for trimming / extending input polylines.
 @since 1.0
 */
@property (nonatomic, retain) AGSPolyline *trimExtendTo;

/** An optional flag with the following possible values:
 
 @li 0 - By default, extension considers both ends of paths. The old ends remain 
 and new points are added to the extended ends. The new points have attributes 
 that are extrapolated from adjacent existing segments. 
 @li 1 - If an extension is performed at an end, relocate the end point to the 
 new position instead of leaving the old point and adding a new point at the new 
 position.
 @li 2 - If an extension is performed at an end, do not extrapolate the 
 end-segment's attributes for the new point. Instead, make its attributes the 
 same as the current end. Incompatible with esriNoAttributes.
 @li 4 - If an extension is performed at an end, do not extrapolate the 
 end-segment's attributes for the new point. Instead, make its attributes be 
 empty. Incompatible with esriKeepAttributes.
 @li 8 - Do not extend the 'from' end of any path.
 @li 16 - Do not extend the 'to' end of any path.
 
 @since 1.0
 */
@property (nonatomic, assign) NSUInteger extendHow;

/** Returns an autoreleased instance of the <code>%AGSTrimExtendParameters</code> object.
 @since 1.0
 */
+ (id)trimExtendParameters;

@end


#pragma mark -

/** Supported @p offsetHow types for the <code>AGSGeometryServiceTask</code>'s 
 <code>offsetWithParameters:</code> operation.

 @since 1.0
 */
typedef enum {
	AGSGeometryOffsetTypeMitered = 0,   /*!<  */
	AGSGeometryOffsetTypeBevelled,      /*!<  */
	AGSGeometryOffsetTypeRounded,       /*!<  */
	AGSGeometryOffsetTypeSquare /** Only applicable with the AGSGeometryEngine */
} AGSGeometryOffsetType;

#pragma mark -

/** @brief Parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>offsetWithParameters:</code> operation.
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>offsetWithParameters:</code> operation. 
 
 @define{AGSGeometryParameters.h, ArcGIS}
 @since 1.0
 @see AGSGeometryServiceTask
 */

@interface AGSOffsetParameters : NSObject <AGSCoding> {
 @private
	double _offsetDistance;
	AGSSRUnit _offsetUnit;
	AGSGeometryOffsetType _offsetHow;
	double _bevelRatio;
	BOOL _simplifyResult;
	NSArray *_geometries;
}

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
@property (nonatomic, retain) NSArray *geometries;

/** Returns an autoreleased instance of the <code>%AGSOffsetParameters</code> object.
 @since 1.0
 */
+ (id)offsetParameters;

@end


#pragma mark -

/** @brief Parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>generalizeWithParameters:</code> operation.
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>generalizewithParameters:</code> operation. 
 
 @define{AGSGeometryParameters.h, ArcGIS}
 @since 1.0
 @see AGSGeometryServiceTask
 */
@interface AGSGeneralizeParameters : NSObject <AGSCoding> {
@private
	double _maxDeviation;
	AGSSRUnit _deviationUnit;
	NSArray *_geometries;
}

/** Specifies the maximum deviation for constructing a generalized geometry 
 based on the input geometries.
 @since 1.0
 */
@property (nonatomic) double maxDeviation;

/** (Optional) The units to be used for #maxDeviation. If the @p deviationUnit 
 is not specified, the units are derived from the spatial reference of the input 
 geometries. 
 @since 1.0
 */
@property (nonatomic) AGSSRUnit deviationUnit;

/** The array of input geometries to generalize. All geometries in this array 
 must be of the same geometry type (@c AGSPolyline or @c AGSPolygon).
 @since 1.0
 */
@property (nonatomic, retain) NSArray *geometries;

/** Returns an autoreleased instance of the <code>%AGSGeneralizeParameters</code> object.
 @since 1.0
 */
+ (id)generalizeParameters;

@end

#pragma mark -

/** @brief Parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>densifyWithParameters:</code> operation.
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>densifyGeometries:withParams:</code> operation.
 
 @define{AGSGeometryParameters.h, ArcGIS}
 @since 1.0
 @see AGSGeometryServiceTask
 */
@interface AGSDensifyParameters : NSObject <AGSCoding> {
@private
	NSArray *_geometries;
	NSUInteger _maxSegmentLength;
	AGSSRUnit _lengthUnit;
	BOOL _geodesic;
}

/** The array of geometries to be densified.
 @since 1.0
 */
@property (nonatomic, retain) NSArray *geometries;
 
/**All segments longer than @c maxSegmentLength are replaced with sequences of 
 lines no longer than @c maxSegmentLength.
 @since 1.0
 */
@property (nonatomic) NSUInteger maxSegmentLength;

/** (Optional) The length unit of @c #maxSegmentLength, can be any @c AGSSRUnit 
 constant.
 @since 1.0
 */
@property (nonatomic) AGSSRUnit lengthUnit;

/** A flag that can be set to <code>true</code> if GCS spatial references are 
 used or densify geodesic is to be performed.
 @since 1.0
 */
@property (nonatomic) BOOL geodesic;

/** Returns an autoreleased instance of the densify parameters object.
 @since 1.0
 */
+ (id)densifyParameters;

@end


#pragma mark -

/** @brief Parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>bufferWithParameters:</code> operation.
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>bufferWithParameters:</code> operation.
 
 @define{AGSGeometryParameters.h, ArcGIS}
 @since 1.0
 */
@interface AGSBufferParameters : NSObject <AGSCoding> {
@private
	AGSSpatialReference *_bufferSpatialReference;
    NSArray *_distances; //NSNumber[]
    NSArray *_geometries; //AGSGeometry[]
    AGSSpatialReference *_outSpatialReference;
    BOOL _unionResults;
    AGSSRUnit _unit;
}

/** The spatial reference in which the geometries should be buffered. If 
 @p bufferSpatialReference is not specified, the geometries are buffered in the 
 spatial reference specified by #outSpatialReference. If #outSpatialReference is 
 also not specified, they are buffered in their original spatial reference.
 @since 1.0
 */
@property (nonatomic, retain) AGSSpatialReference *bufferSpatialReference;

/** The distances by which the input geometries are to be buffered. The distance 
 units are specified by #unit.
 @since 1.0
 */
@property (nonatomic, retain) NSArray *distances;

/** The input geometries to buffer.
 @since 1.0
 */
@property (nonatomic, retain) NSArray *geometries;

/** The spatial reference for the returned geometries. If this is not specified, 
 the output geometries are in the spatial reference specified by 
 #bufferSpatialReference. If #bufferSpatialReference is also not specified, they 
 are returned in their original spatial reference.
 @since 1.0
 */
@property (nonatomic, retain) AGSSpatialReference *outSpatialReference;

/** If <code>YES</code>, all geometries buffered at a given distance are unioned 
 into a single (possibly multipart) polygon. Default is <code>NO</code>.
 @since 1.0
 */
@property (nonatomic) BOOL unionResults;

/** The units of the buffer distance. Possible values are listed in the 
 documentation for <a href="http://resources.esri.com/help/9.3/ArcGISDesktop/ArcObjects/esriGeometry/esriSRUnitType.htm">esriSRUnitType</a> and 
 <a href="http://resources.esri.com/help/9.3/ArcGISDesktop/ArcObjects/esriGeometry/esriSRUnit2Type.htm">esriSRUnit2Type</a>.
 
 If @p unit is not specified, the units are derived from #bufferSpatialReference. 
 If #bufferSpatialReference is not specified, the units are derived from the 
 features' spatial reference.
 @since 1.0
 */
@property (nonatomic) AGSSRUnit unit;

/** Returns an autoreleased instance of the <code>%AGSBufferParameters</code> object.
 @since 1.0
 */
+ (id)bufferParameters;

@end