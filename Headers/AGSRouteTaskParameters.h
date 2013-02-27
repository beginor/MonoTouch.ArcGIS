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



/** @file AGSRouteTaskParameters.h */

@protocol AGSCoding;
@class AGSSpatialReference;
@class AGSNALayerDefinition;


/** @brief Input paramters for @c AGSRouteTask.
 
 Instances of this class represent input parameters for the @c AGSRouteTask. 
 
 The default
 parameters for an @c AGSRouteTask can be retrieved by passing @c AGSRouteTask
 the <code>retrieveDefaultRouteTaskParameters</code> message and listening to the 
 <code>routeTask:operation:didRetrieveDefaultRouteTaskParameters:</code> delegate 
 method.
 @since 1.8
 */
@interface AGSRouteTaskParameters : NSObject <AGSCoding> 

/** This list of network attribute names to be accumulated with the analysis, i.e.
 which attributes should be returned as part of the response. 
 
 The default is as defined by the network analysis layer used in your task. You
 can specify any attributes names listed in the Services Directory under 
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

/** The language used when computing directions. For example, en_US, fr_FR, etc. 
 The default is as defined by the network analysis layer used in your task.
 
 By default, NAServer
 gets installed with en_US only - it is up to the server administrator to add 
 additional languages.
 @since 1.8
 */
@property (nonatomic, copy) NSString *directionsLanguage;

/** The length units to use when computing directions. 
 The default is as defined by the network analysis layer used in your task.
 
 Possible types include
 
 @li @c AGSNAUnitCentimeters 	
 @li @c AGSNAUnitDays 	
 @li @c AGSNAUnitDecimalDegrees 	
 @li @c AGSNAUnitDecimeters 	
 @li @c AGSNAUnitFeet 	
 @li @c AGSNAUnitHours 	
 @li @c AGSNAUnitInches 	
 @li @c AGSNAUnitKilometers 	
 @li @c AGSNAUnitMeters 	
 @li @c AGSNAUnitMiles 	
 @li @c AGSNAUnitMillimeters 	
 @li @c AGSNAUnitMinutes 	
 @li @c AGSNAUnitNauticalMiles 	
 @li @c AGSNAUnitPoints 	
 @li @c AGSNAUnitSeconds 	
 @li @c AGSNAUnitUnknown 	
 @li @c AGSNAUnitYards 
  
 @since 1.8
 */
@property (nonatomic, assign) AGSNAUnit directionsLengthUnits;

/** The style to be used when returning the directions. The default is as defined in the network layer. 
 @since 1.8
 */
@property (nonatomic, copy) NSString *directionsStyleName;

/** The name of network attribute to use for the drive time when computing 
 directions. The default is as defined by the network analysis layer used in your task.
 @since 1.8
 */
@property (nonatomic, copy) NSString *directionsTimeAttributeName;

/** If <code>true</code>, avoids network elements restricted by @p pointBarriers or
 due to restrictions specified in @p restrictionAttributeNames.
 @since 1.8
 */
@property (nonatomic, assign) BOOL doNotLocateOnRestrictedElements;

/** If <code>true</code>, optimizes the order of the stops in the route while
 taking into account @p preserveFirstStop and @p preserveLastStop, if they are
 set to <code>true</code>. The default is as defined by the network analysis layer used in your task.
 Default value is NO.
 @since 1.8
 */
@property (nonatomic, assign) BOOL findBestSequence;

/** In routes where a stop is not located on a network or a stop could not be
 reached, the results will differ depending on the value of @p ignoreInvalidLocations.
 When <code>false</code>, the solve operation will fail if at least one of the stops
 specified cannot be located or reached.
 When <code>true</code>, as long as there are at least two valid stops that have 
 been connected by a route, a valid result is returned. If multiple routes are
 processed in a single request, as long as at least one route is built, a valid
 result is returned.
 Default value is NO.
 @since 1.8
 */
@property (nonatomic, assign) BOOL ignoreInvalidLocations;

/** The network attribute name to be used as the impedance attribute in analysis. 
 The default is as defined by the network analysis layer used in your task.
 You can specify any attributes names listed in the Service 
 Directory under "Network Dataset -> Network Attributes" as "Usage Type: esriNAUTCost". 
 You can also specify a value of "none" to indicate that no network attributes 
 should be used for impedance. If you specify an empty array, it will default to 
 the default of the service.  
 @since 1.8
 */
@property (nonatomic, copy) NSString *impedanceAttributeName;

/** The precision of the output geometry after generalization. If 0, no generalization
 of output is performed. If present and positive, it represents the MaximumAllowableOffset
 parameter. The default value is 5.0 meters.
 @since 1.8
 */
@property (nonatomic, assign) double outputGeometryPrecision;

/** The units of the output geometry precision. The default value is AGSUnitsMeters.
 
 Possible types include
 
 @li @c AGSUnitsCentimeters 
 @li @c AGSUnitsDecimalDegrees
 @li @c AGSUnitsDecimeters
 @li @c AGSUnitsFeet
 @li @c AGSUnitsInches
 @li @c AGSUnitsKilometers
 @li @c AGSUnitsMeters
 @li @c AGSUnitsMiles
 @li @c AGSUnitsMillimeters
 @li @c AGSUnitsNauticalMiles
 @li @c AGSUnitsPoints
 @li @c AGSUnitsUnknown
 @li @c AGSUnitsYards
 
 @since 1.8
 */
@property (nonatomic, assign) AGSUnits outputGeometryPrecisionUnits;

/** The type of lines to be generated in the result. 
  
 Known values: see @c AGSNAOutputLine.
 @since 1.8
 */
@property (nonatomic, assign) AGSNAOutputLine outputLines;

/** The spatial reference in which result geometries should be returned.
 If not specified, the geometries are returned in the
 spatial reference of the service.
 @since 1.8
 */
@property (nonatomic, strong) AGSSpatialReference *outSpatialReference;

/** If <code>true</code>, keeps the first stop fixed in the sequence even when
 @p findBestSequence is <code>true</code>. Only applicable if @p findBestSequence
 is <code>true</code>. 
 Default is NO.
 @since 1.8
 */
@property (nonatomic, assign) BOOL preserveFirstStop;

/** If <code>true</code>, keeps the last stop fixed in the sequence even when
 @p findBestSequence is <code>true</code>. Only applicable if @p findBestSequence
 is <code>true</code>. 
 Default is NO.
 @since 1.8
 */
@property (nonatomic, assign) BOOL preserveLastStop;

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

/** If @c true, point barriers used in the analysis are returned in the @c  pointBarriers
 property of @c AGSRouteTaskResult. 
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnPointBarriers;

/** If <code>true</code>, directions are generated and returned in the @p directions
 property of each @c AGSRouteResult. 
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnDirections;

/** If @c true, polygon barriers used in the analysis are returned in the @c  pointBarriers
 property of @c AGSRouteTaskResult
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnPolygonBarriers;

/** If @c true, polyline barriers used in the analysis are returned in the @c  pointBarriers
 property of @c AGSRouteTaskResult
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnPolylineBarriers;

/** If <code>true</code>, routes are generated and returned in the @p route property
 of each @c AGSRouteResult.
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnRouteGraphics;

/** If <code>true</code>, stops are returned in the @p stops property of each
 @c AGSRouteResult. Returned stops may contain some additional
 attributes providing information about the route.
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnStopGraphics;

/** The time the route begins. If not specified, defaults to the time the task
 is executed.
 @since 1.8
 */
@property (nonatomic, strong) NSDate *startTime;

/** If <code>true</code>, the hierarchy attribute for the network should be used 
 in analysis.
 Default is NO.
 @since 1.8
 */
@property (nonatomic, assign) BOOL useHierarchy;

/** If <code>true</code>, time windows should be used in the analysis. 
 Default is NO.
 @since 1.8
 */
@property (nonatomic, assign) BOOL useTimeWindows;

/** Defines content, verbosity of returned directions. The default is AGSNADirectionsOutputTypeStandard.
 @avail{10.1}
 @since 2.3
 */
@property (nonatomic, assign) AGSNADirectionsOutputType directionsOutputType;

/** Initialize an autoreleased <code>AGSRouteTaskParameters</code> object.
 @since 1.8
 */
+ (id)routeTaskParameters;

/** Set the stops to be used in the solve operation as an array of @c AGSStopGraphic objects.
 @param features The set of features to be used as stops in the analysis.
 @since 1.8
 */
- (void)setStopsWithFeatures:(NSArray*)features;

/** Set the layer information for the stops to be used in the solve operation.
 @param layerDefinition The @c AGSNALayerDefinition containing information about 
 the stops to be used in the analysis.
 @since 1.8
 */
- (void)setStopsWithLayerDefinition:(AGSNALayerDefinition*)layerDefinition;

/** Set the point barriers to be used in the solve operation as an array of @c AGSGraphic objects.
 @param features The set of features to be used as point barriers in the analysis.
 @since 1.8
 */
- (void)setPointBarriersWithFeatures:(NSArray*)features;

/** Set the layer information for the point barriers to be used in the solve operation.
 @param layerDefinition The @c AGSNALayerDefinition containing information about 
 the barriers to be used in the analysis.
 @since 1.8
 */
- (void)setPointBarriersWithLayerDefinition:(AGSNALayerDefinition*)layerDefinition;

/** Set the polyline barriers to be used in the solve operation as an array of @c AGSGraphic objects.
 @param features The set of features to be used as polyline barriers in the analysis.
 @since 1.8
 */
- (void)setPolylineBarriersWithFeatures:(NSArray*)features;

/** Set the layer information for the polyline barriers to be used in the solve 
 operation.
 @param layerDefinition The @c AGSNALayerDefinition containing information about 
 the polyline barriers to be used in the analysis.
 @since 1.8
 */
- (void)setPolylineBarriersWithLayerDefinition:(AGSNALayerDefinition*)layerDefinition;

/** Set the polygon barriers to be used in the solve operation as an array of @c AGSGraphic objects.
 @param features The set of features to be used as polygon barriers in the analysis.
 @since 1.8
 */
- (void)setPolygonBarriersWithFeatures:(NSArray*)features;

/** Set the layer information for the polygon barriers to be used in the solve 
 operation.
 @param layerDefinition The @c AGSNALayerDefinition containing information about 
 the polygon barriers to be used in the analysis.
 @since 1.8
 */
- (void)setPolygonBarriersWithLayerDefinition:(AGSNALayerDefinition*)layerDefinition;

@end
