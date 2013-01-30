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



/** @file AGSServiceAreaTaskParameters.h */

@protocol AGSCoding;
@class AGSSpatialReference;
@class AGSNALayerDefinition;

/** @brief Input parameters for @c AGSServiceAreaTask.
 
 Instances of this class represent parameters to be used as input to the @c AGSServiceAreaTask.
 
 The default parameters for an @c AGSServiceAreaTask can be retrieved by passing @c AGSServiceAreaTask
 the <code>retrieveDefaultServiceAreaTaskParameters</code> message and listening to the 
 <code> serviceAreaTask:operation:didRetrieveDefaultServiceAreaTaskParameters:</code> delegate 
 method.
 
 @since 1.8
 */

@interface AGSServiceAreaTaskParameters : NSObject <AGSCoding> 

/** The list of network attribute names to be accumulated with the analysis, 
 i.e., which attributes should be returned as part of the response.
 
 You can specify any attributes names listed in the Services Directory under 
 "Network Dataset -> Network Attributes" as "Usage Type: esriNAUTCost".
 @since 1.8
 */
@property (nonatomic, copy) NSArray *accumulateAttributeNames;

/** An array of NSDictionary objects that describe the parameter values. Properties of
 this object are:
 (String) attributeName				- Name of the attribute.
 (String) parameterName				- Name of the parameter.
 (Number) value						- Parameter value.
 @since 1.8
 */
@property (nonatomic, copy) NSArray *attributeParameterValues;

/** An array of numbers defining the breaks. 
 @since 1.8
 */
@property (nonatomic, copy) NSArray *defaultBreaks;

/** An array of network source names to NOT use when generating polygons.
 @since 1.8
 */
@property (nonatomic, copy) NSArray *excludeSourcesFromPolygons;

/** The set of facilities loaded as network locations during analysis. Can be 
 either an instance of @c AGSDataLayer or @c AGSFeatureSet.
 @since 1.8
 */
@property (nonatomic, strong) id facilities;

/** The network attribute name to be used as the impedance attribute in analysis. 
  You can specify any attributes names listed in the Service 
 Directory under "Network Dataset -> Network Attributes" as "Usage Type: esriNAUTCost". 
 You can also specify a value of "none" to indicate that no network attributes 
 should be used for impedance. If you specify an empty array, it will default to 
 the default of the service.  
 @since 1.8
 */
@property (nonatomic, copy) NSString *impedanceAttributeName;

/** If <code>true</code>, similar ranges will be merged in the result polygons.
 Default is NO.
 @since 1.8
 */
@property (nonatomic, assign) BOOL mergeSimilarPolygonRanges;

/** The precision of the output geometry after generalization. The default is 5.0.
 @since 1.8
 */
@property (nonatomic, assign) double outputGeometryPrecision;

/** The units of the output geometry precision. The default value is AGSUnitsMeters.
 @since 1.8
 */
@property (nonatomic, assign) AGSUnits outputGeometryPrecisionUnits;

/** The type of lines to be generated in the result.
 
 Known values: see @c AGSNAOutputLine.
 @since 1.8
 */
@property (nonatomic, assign) AGSNAOutputLine outputLines;

/** The type of output polygons to be generated in the result.
 @since 1.8
 */
@property (nonatomic, assign) AGSNAOutputPolygon outputPolygons;

/** The spatial reference in which result geometries should be returned.
 If not specified, the geometries are returned in the
 spatial reference of the service.
 @since 1.8
 */
@property (nonatomic, strong) AGSSpatialReference *outSpatialReference;

/** Indicates if the lines should overlap from multiple facilities.
 Default is NO.
 @since 1.8
 */
@property (nonatomic, assign) BOOL overlapLines;

/** Indicates if the polygons should overlap from multiple facilities.
 Default is NO.
 @since 1.8
 */
@property (nonatomic, assign) BOOL overlapPolygons;

/** The set of point barriers loaded as network locations during analysis. Can 
 be either an instance of @c AGSDataLayer or @c AGSFeatureSet.
 @since 1.8
 */
@property (nonatomic, strong) id pointBarriers;  // Object?

/** The set of polygons barriers loaded as network locations during analysis. 
 Can be either an instance of @c AGSDataLayer or @c AGSFeatureSet.
 @since 1.8
 */
@property (nonatomic, strong) id polygonBarriers; // Object?

/** The set of polyline barriers loaded as network locations during analysis. 
 Can be either an instance of @c AGSDataLayer or @c AGSFeatureSet.
 @since 1.8
 */
@property (nonatomic, strong) id polylineBarriers; // Object?

/** The list of network attribute names to be used as restrictions with the 
 analysis. Possible values are listed in the Service Directory 
 under "Network Dataset -> Network Attributes". You can also specify a value of 
 "none" to indicate that no network attributes should be used as restrictions. 
 If you specify an empty array, it will default to the default of the service.
 @since 1.8
 */
@property (nonatomic, copy) NSArray *restrictionAttributeNames;

/** Specifies how U-Turns should be handled. U-turns can be allowed everywhere, 
 nowhere , only at dead ends, or only at intersections and dead ends.
 Allowing U-turns implies the vehicle can turn around at a junction and double back on the same street.
 
 Known values: see @c AGSNAUTurn.
 @since 1.8
 */
@property (nonatomic, assign) AGSNAUTurn uTurns; 

/** If <code>true</code>, facilities will be returned with the analysis results. 
 Default value is <code>false</code>.
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnFacilities;

/** If <code>true</code>, point barriers will be returned in the point barriers property of 
 @c AGSServiceAreaTaskResult. The default value is <code>false</code>.
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnPointBarriers;

/** If <code>true</code>, polygon barriers will be returned in the polygonBarriers 
 property of @c AGSServiceAreaTaskResult. The default value is <code>false</code>.
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnPolygonBarriers;

/** If <code>true</code>, polyline barriers will be returned in the polylineBarriers 
 property of @c AGSServiceAreaTaskResult. The default value is <code>false</code>.
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnPolylineBarriers;

/** If <code>true</code>, lines will be split at breaks.
 Default is NO.
 @since 1.8
 */
@property (nonatomic, assign) BOOL splitLinesAtBreaks;

/** If <code>true</code>, polygons will be split at breaks.
 Default is NO.
 @since 1.8
 */
@property (nonatomic, assign) BOOL splitPolygonsAtBreaks;

/** Options for traveling to or from the facility. Default values are defined by 
 the newtork layer. See @c AGSNATravelDirection for a list of valid values.
 @since 1.8
 */
@property (nonatomic, assign) AGSNATravelDirection travelDirection;

/** If <code>true</code>, the outermost polygon (at the maximum break value) will 
 be trimmed. The default is defined in the network analysis layer in your 
 ServiceAreaTask.
 @since 1.8
 */
@property (nonatomic, assign) BOOL trimOuterPolygon;

/** If polygons are being trimmed, provides the distance to trim. The default is 
 defined in the network analysis layer.
 @since 1.8
 */
@property (nonatomic, assign) double trimPolygonDistance;

/** If polygons are being trimmed, specifies the units of the #trimPolygonDistance. 
 The default is defined in the network analysis layer.
 @since 1.8
 */
@property (nonatomic, assign) AGSUnits trimPolygonDistanceUnits;

/**  Arrival or Departure date and time at the facility. For example, if @c #travelDirection set to AGSNATravelDirectionToFacility, @c timeOfDay represents the arrival time at the facility.
 However, if @c #travelDirection set to AGSNATravelDirectionFromFacility, @c timeOfDay represents the departure time from the facility.
 This is useful if the network analyst service uses historic or real-time traffic data.
 @avail{10.1}
 @since 2.3
 */
@property (nonatomic, strong) NSDate *timeOfDay;

/** If <code>true</code>, the hierarchy attribute for the network should be used in analysis. 
 The default is as defined in the network layer. This cannot be used in conjunction with @c #outputLines. 
 @avail{10.1}
 @since 2.3
 */
@property (nonatomic, assign) BOOL useHierarchy;

/** Initialize an autoreleased <code>AGSServiceAreaTaskParameters</code> object.
 @since 1.8
 */
+ (id)serviceAreaTaskParameters;

/** Set the facilities to be used in the service area operation.
 @param features An array of @c AGSGraphic objects representing features to be used as facilities in the analysis.
 @since 1.8
 */
- (void)setFacilitiesWithFeatures:(NSArray*)features;

/** Set the layer information for the facilities to be used in the service
 area operation.
 @param layerDefinition The @c AGSNALayerDefinition containing information about 
 the facilities to be used in the analysis.
 @since 1.8
 */
- (void)setFacilitiesWithLayerDefinition:(AGSNALayerDefinition*)layerDefinition;

/** Set the point barriers to be used in the service area operation.
 @param features An array of @c AGSGraphic objects representing features to be used as point barriers in the analysis.
 @since 1.8
 */
- (void)setPointBarriersWithFeatures:(NSArray*)features;

/** Set the layer information for the point barriers to be used in the service
 area operation.
 @param layerDefinition The @c AGSNALayerDefinition containing information about 
 the barriers to be used in the analysis.
 @since 1.8
 */
- (void)setPointBarriersWithLayerDefinition:(AGSNALayerDefinition*)layerDefinition;

/** Set the polyline barriers to be used in the service area operation.
 @param features An array of @c AGSGraphic objects representing features to be used as polyline barriers in the analysis.
 @since 1.8
 */
- (void)setPolylineBarriersWithFeatures:(NSArray*)features;

/** Set the layer information for the polyline barriers to be used in the service 
 area operation.
 @param layerDefinition The @c AGSNALayerDefinition containing information about 
 the polyline barriers to be used in the analysis.
 @since 1.8
 */
- (void)setPolylineBarriersWithLayerDefinition:(AGSNALayerDefinition*)layerDefinition;

/** Set the polygon barriers to be used in the service operation.
 @param features An array of @c AGSGraphic objects representing features to be used as polygon barriers in the analysis.
 @since 1.8
 */
- (void)setPolygonBarriersWithFeatures:(NSArray*)features;

/** Set the layer information for the polygon barriers to be used in the service 
 area operation.
 @param layerDefinition The @c AGSNALayerDefinition containing information about 
 the polygon barriers to be used in the analysis.
 @since 1.8
 */
- (void)setPolygonBarriersWithLayerDefinition:(AGSNALayerDefinition*)layerDefinition;


@end
