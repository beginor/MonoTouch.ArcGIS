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



/** @file AGSClosestFacilityTaskParameters.h */

@protocol AGSCoding;
@class AGSNALayerDefinition;
@class AGSSpatialReference;

/** @brief Parameters for @c AGSClosestFacilityTask.
 
 Instances of this class represent parameters to be used as input to the @c AGSClosestFacilityTask.
 
 The default parameters for an @c AGSClosestFacilityTask can be retrieved by passing @c AGSClosestFacilityTask
 the <code>retrieveDefaultClosestFacilityTaskParameters</code> message and listening to the 
 <code> closestFacilityTask:operation:didRetrieveDefaultClosestFacilityTaskParameters:</code> delegate 
 method.
 @
 since 1.8
 */
@interface AGSClosestFacilityTaskParameters : NSObject<AGSCoding>

/** The list of network attribute names to be accumulated with the analysis, 
 i.e.,which attributes should be returned as part of the response.
 
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

/** The cutoff value used to determine when to stop traversing.
 @since 1.8
 */
@property (nonatomic, assign) double defaultCutoffValue;

/** The number of facilities to find.
 @since 1.8
 */
@property (nonatomic, assign) NSInteger defaultTargetFacilityCount;

/** The language used when computing directions. The default is as defined by the network analysis layer used in your task.
 @since 1.8
 */
@property (nonatomic, copy) NSString *directionsLanguage;

/** The length units used when computing directions. The default is as defined by the network analysis layer used in your task.
 @since 1.8
 */
@property (nonatomic, assign) AGSNAUnit directionsLengthUnits;

/** 
 @since 1.8 
 */
@property (nonatomic, copy) NSString *directionsStyleName;

/** The name of the attribute field that contains the drive time values. If not 
 specified the task will use the attribute field defined by the closest facility 
 network layer.
 @since 1.8
 */
@property (nonatomic, copy) NSString *directionsTimeAttributeName;

/** The network attribute name to be used as the impedance attribute in analysis. 
 The default is as defined in the specific closest facility network layer used in your 
 task. You can specify any attributes names listed in the Service 
 Directory under "Network Dataset -> Network Attributes" as "Usage Type: esriNAUTCost". 
 You can also specify a value of "none" to indicate that no network attributes 
 should be used for impedance. If you specify an empty array, it will default to 
 the default of the service.  
 @since 1.8
 */
@property (nonatomic, copy) NSString *impedanceAttributeName;

/** The output geometry precision. The default value is 5.0.
 @since 1.8
 */
@property (nonatomic, assign) double outputGeometryPrecision;

/** The units of the output geometry precision. The default value is AGSUnitsMeters.
 @since 1.8
 */
@property (nonatomic, assign) AGSUnits outputGeometryPrecisionUnits;

/** The type of lines to be generated in the result. The default is as 
 defined in the specific closest facility network layer used in your task.
 
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

/** If <code>true</code>, barriers will be returned in the barriers 
 property of the @c AGSClosestFacilityTaskResult. Default value is <code>false</code>.
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnPointBarriers;

/** If <code>true</code>, directions will be generated and returned in the 
 directions property of each @c AGSClosestFacilityResult. Default
 value is <code>false</code>.
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnDirections;

/** If <code>true</code>, facilities will be returned with the analysis results. 
 Default value is <code>false</code>.
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnFacilities;

/** If <code>true</code>, incidents will be returned with the analysis results. 
 Default value is <code>false</code>.
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnIncidents;

/** If <code>true</code>, polygon barriers will be returned in the polygon barriers 
 property of the @c AGSClosestFacilityTaskResult. Default value is <code>false</code>.
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnPolygonBarriers;

/** If <code>true</code>, polyline barriers will be returned in the polyline barriers 
 property of the @c AGSClosestFacilityTaskResult. Default value is <code>false</code>.
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnPolylineBarriers;

/** When <code>true</code>, closest facility routes will be generated and returned 
 in the route property of each @c AGSClosestFacilityResult and @c AGSClosestFacilityTaskResult. 
 Default value is <code>true</code>.
 @since 1.8
 */
@property (nonatomic, assign) BOOL returnRouteGraphics;

/** Options for traveling to or from the facility.
 @since 1.8
 */
@property (nonatomic, assign) AGSNATravelDirection travelDirection;

/** If <code>true</code>, the hierarchy attribute for the network will be used 
 in analysis.  
 @since 1.8
 */
@property (nonatomic, assign) BOOL useHierarchy;

/** Arrival or Departure date and time. For example, if @c #travelDirection set to AGSNATravelDirectionToFacility 
 and @c #timeOfDayUsage set to AGSNATimeOfDayUseAsEndTime and @c timeOfDay is set to 8:00 AM, the route(s) built 
 will arrive at the Facility at 8:00 in the morning, local time. 
 This is useful if the network analyst service uses historic or real-time traffic data.
 @since 2.3
 @avail{10.1}
 @see #timeOfDayUsage
 */
@property (nonatomic, strong) NSDate *timeOfDay;

/** Defines the way @c #timeOfDay value is used. The default is as defined in the network layer.
 @avail{10.1}
 @since 2.3
 */
@property (nonatomic, assign) AGSNATimeOfDayUse timeOfDayUsage;

/** Defines content, verbosity of returned directions. The default is AGSNADirectionsOutputTypeStandard. 
 @avail{10.1}
 @since 2.3
 */
@property (nonatomic, assign) AGSNADirectionsOutputType directionsOutputType;

/** Initialize an autoreleased <code>AGSClosestFacilityTaskParameters</code> object.
 @since 1.8
 */
+ (id)closestFacilityTaskParameters;

/** Set the facilities to be used in the closest facility operation.
 @param features An array of @c AGSGraphic objects representing  features to be used as facilities in the analysis.
 @since 1.8
 */
- (void)setFacilitiesWithFeatures:(NSArray*)features;

/** Set the layer information for the facilities to be used in the closest
 facility operation.
 @param layerDefinition The @c AGSNALayerDefinition containing information about 
 the facilities to be used in the analysis.
 @since 1.8
 */
- (void)setFacilitiesWithLayerDefinition:(AGSNALayerDefinition*)layerDefinition;

/** Set the incidents to be used in the closest facility operation.
 @param features An array of @c AGSGraphic objects representing features to be used as incidents in the analysis.
 @since 1.8
 */
- (void)setIncidentsWithFeatures:(NSArray*)features;

/** Set the layer information for the incidents to be used in the closest
 facility operation.
 @param layerDefinition The @c AGSNALayerDefinition containing information about 
 the incidents to be used in the analysis.
 @since 1.8
 */
- (void)setIncidentsWithLayerDefinition:(AGSNALayerDefinition*)layerDefinition;

/** Set the point barriers to be used in the solve operation.
 @param features An array of @c AGSGraphic objects representing features to be used as point barriers in the analysis.
 @since 1.8
 */
- (void)setPointBarriersWithFeatures:(NSArray*)features;

/** Set the layer information for the point barriers to be used in the solve operation.
 @param layerDefinition The @c AGSNALayerDefinition containing information about 
 the barriers to be used in the analysis.
 @since 1.8
 */
- (void)setPointBarriersWithLayerDefinition:(AGSNALayerDefinition*)layerDefinition;

/** Set the polyline barriers to be used in the solve operation.
 @param features An array of @c AGSGraphic objects representing  features to be used as polyline barriers in the analysis.
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

/** Set the polygon barriers to be used in the solve operation.
 @param features An array of @c AGSGraphic objects representing  features to be used as polygon barriers in the analysis.
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
