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

/** @file AGSEnumerations.h */ 

/**
 Specifies the wrap around status of an AGSMapView.
 @since 10.1.1
 */
typedef enum {
    AGSMapViewWrapAroundStatusDisabled,             /*!<  */
    AGSMapViewWrapAroundStatusUninitialized,        /*!<  */
    AGSMapViewWrapAroundStatusUnsupported,          /*!<  */
    AGSMapViewWrapAroundStatusEnabled               /*!<  */
} AGSMapViewWrapAroundStatus;

/** Specifies how a text symbol should be vertically aligned.
 @since 1.8
 */
typedef enum {
	AGSTextSymbolVAlignmentBottom = 0,		/*!<  */
	AGSTextSymbolVAlignmentMiddle,			/*!<  */
	AGSTextSymbolVAlignmentTop,				/*!<  */
} AGSTextSymbolVAlignment;

/** Specifies how a text symbol should be horizontally aligned.
 @since 1.8
 */
typedef enum {
	AGSTextSymbolHAlignmentLeft = 0,		/*!<  */
	AGSTextSymbolHAlignmentCenter,			/*!<  */
	AGSTextSymbolHAlignmentRight			/*!<  */
} AGSTextSymbolHAlignment;


/** Supported marker styles.
 @since 1.0
 */
typedef enum {
    AGSSimpleMarkerSymbolStyleCircle = 0,	/*!< */
    AGSSimpleMarkerSymbolStyleCross,		/*!< */
    AGSSimpleMarkerSymbolStyleDiamond,		/*!< */			
    AGSSimpleMarkerSymbolStyleSquare,		/*!< */
    AGSSimpleMarkerSymbolStyleX				/*!< */
} AGSSimpleMarkerSymbolStyle;


/** Supported interpolations.
 @since 1.8
 */
typedef enum : NSUInteger {
	AGSInterpolationBilinear = 0,                       /*!<  */
	AGSInterpolationCubicConvolution,                   /*!<  */
	AGSInterpolationMajority,                           /*!<  */
	AGSInterpolationNearestNeighbor = NSUIntegerMax		/*!<  */
} AGSInterpolation;


/** Possible relationships between geometries.
 @since 1.0
 */
typedef enum : NSUInteger {
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

/** Supported geometry types.
 @since 1.0
 */
typedef enum  {
    AGSGeometryTypeUndefined = -1,  /*!<  */
    AGSGeometryTypePoint,           /*!<  */
    AGSGeometryTypePolyline,        /*!<  */
    AGSGeometryTypePolygon,         /*!<  */
    AGSGeometryTypeMultipoint,      /*!<  */
    AGSGeometryTypeEnvelope         /*!<  */
} AGSGeometryType;

/** Supported raster function types. These types correspond to the names of
 raster functions.
 @since 1.8
 */
typedef enum {
	AGSRasterFunctionTypeAspect = 0,		/*!<  */
	AGSRasterFunctionTypeColormap,			/*!<  */
	AGSRasterFunctionTypeHillshade,			/*!<  */
	AGSRasterFunctionTypeNDVI,				/*!<  */
	AGSRasterFunctionTypeShadedRelief,		/*!<  */
	AGSRasterFunctionTypeSlope,				/*!<  */
	AGSRasterFunctionTypeStatistics,		/*!<  */
	AGSRasterFunctionTypeStretch,			/*!<  */
} AGSRasterFunctionType;
	

/** List of supported <code>%AGSFieldType</code>'s
 @since 1.0
 */
typedef enum {
    AGSFieldTypeInteger = 0,        /*!<  */
    AGSFieldTypeSmallInteger,       /*!<  */
	AGSFieldTypeDouble,             /*!<  */
	AGSFieldTypeSingle,             /*!<  */
	AGSFieldTypeString,             /*!<  */
	AGSFieldTypeDate,               /*!<  */
	AGSFieldTypeGeometry,           /*!<  */
	AGSFieldTypeOID,                /*!<  */
	AGSFieldTypeBlob,               /*!<  */
	AGSFieldTypeGlobalID,           /*!<  */
	AGSFieldTypeRaster,             /*!<  */
	AGSFieldTypeGUID,               /*!<  */
	AGSFieldTypeXML                 /*!<  */
} AGSFieldType;


/** Supported time interval units.
 @since 1.0
 */
typedef enum {
    AGSTimeIntervalUnitsMilliseconds = 0,	/*!< */
    AGSTimeIntervalUnitsSeconds,		/*!< */
    AGSTimeIntervalUnitsMinutes,		/*!< */
    AGSTimeIntervalUnitsHours,			/*!< */
    AGSTimeIntervalUnitsDays,           /*!< */
    AGSTimeIntervalUnitsWeeks,          /*!< */
    AGSTimeIntervalUnitsMonths,			/*!< */
    AGSTimeIntervalUnitsYears,           /*!< */
    AGSTimeIntervalUnitsDecades,		/*!< */
    AGSTimeIntervalUnitsCenturies,	/*!< */
    AGSTimeIntervalUnitsUnknown		/*!< */	
} AGSTimeIntervalUnits;

/** Possible spatial relationships.
 @since 1.8
 */
typedef enum : NSUInteger {
    AGSSpatialRelationshipIntersects = 0,		/*!<  */
    AGSSpatialRelationshipContains,				/*!<  */
    AGSSpatialRelationshipCrosses,				/*!<  */
    AGSSpatialRelationshipEnvelopeIntersects,	/*!<  */
    AGSSpatialRelationshipIndexIntersects,		/*!<  */
    AGSSpatialRelationshipOverlaps,				/*!<  */
    AGSSpatialRelationshipTouches,				/*!<  */
    AGSSpatialRelationshipWithin,				/*!<  */
	AGSSpatialRelationshipRelation				/*!<  */
} AGSSpatialRelationship;

/** Supported linear units.
 @since 1.0
 */
typedef enum : NSUInteger {
    AGSUnitsCentimeters = 0,	/*!<  */
    AGSUnitsDecimalDegrees,		/*!<  */
    AGSUnitsDecimeters,			/*!<  */
    AGSUnitsFeet,				/*!<  */
    AGSUnitsInches,				/*!<  */
    AGSUnitsKilometers,			/*!<  */
    AGSUnitsMeters,				/*!<  */
    AGSUnitsMiles,				/*!<  */
    AGSUnitsMillimeters,		/*!<  */	
    AGSUnitsNauticalMiles,		/*!<  */
    AGSUnitsPoints,				/*!<  */
    AGSUnitsUnknown,			/*!<  */
    AGSUnitsYards				/*!<  */
} AGSUnits;

/** Supported area units.
 @since 1.0
 */
typedef enum : NSUInteger {
    AGSAreaUnitsSquareInches = 0,		/*!<  */
    AGSAreaUnitsSquareFeet,				/*!<  */
    AGSAreaUnitsSquareYards,			/*!<  */
    AGSAreaUnitsAcres,					/*!<  */
    AGSAreaUnitsSquareMiles,			/*!<  */
    AGSAreaUnitsSquareMillimeters,		/*!<  */
    AGSAreaUnitsSquareCentimeters,		/*!<  */
    AGSAreaUnitsSquareDecimeters,		/*!<  */
    AGSAreaUnitsSquareMeters,			/*!<  */
    AGSAreaUnitsAres,					/*!<  */
    AGSAreaUnitsHectares,				/*!<  */
    AGSAreaUnitsSquareKilometers		/*!<  */
} AGSAreaUnits;

/** Supported esriSRUnits.
 @since 1.0
 */
typedef enum : NSUInteger {
    AGSSRUnitMeter					= 9001,     /*!< International meter. */
    AGSSRUnitGermanMeter			= 9031,     /*!< German legal meter. */
    AGSSRUnitFoot					= 9002,     /*!< International foot. */
    AGSSRUnitSurveyFoot				= 9003,     /*!< US survey foot. */
    AGSSRUnitClarkeFoot				= 9005,     /*!< Clarke's foot. */
    AGSSRUnitFathom					= 9014,     /*!< Fathom. */
    AGSSRUnitNauticalMile			= 9030,     /*!< International nautical mile. */
    AGSSRUnitSurveyChain			= 9033,     /*!< US survey chain. */
    AGSSRUnitSurveyLink				= 9034,     /*!< US survey link. */
    AGSSRUnitSurveyMile				= 9035,     /*!< US survey mile. */
    AGSSRUnitKilometer				= 9036,     /*!< Kilometer. */
    AGSSRUnitClarkeYard				= 9037,     /*!< Yard (Clarke's ratio). */
    AGSSRUnitClarkeChain			= 9038,     /*!< Chain (Clarke's ratio). */
    AGSSRUnitClarkeLink				= 9039,     /*!< Link (Clarke's ratio). */
    AGSSRUnitSearsYard				= 9040,     /*!< Yard (Sears). */
    AGSSRUnitSearsFoot				= 9041,     /*!< Sears' foot. */
    AGSSRUnitSearsChain				= 9042,     /*!< Chain (Sears). */
    AGSSRUnitSearsLink				= 9043,     /*!< Link (Sears). */
    AGSSRUnitBenoit1895AYard		= 9050,     /*!< Yard (Benoit 1895 A). */
    AGSSRUnitBenoit1895AFoot		= 9051,     /*!< Foot (Benoit 1895 A). */
    AGSSRUnitBenoit1895AChain		= 9052,     /*!< Chain (Benoit 1895 A). */
    AGSSRUnitBenoit1895ALink		= 9053,     /*!< Link (Benoit 1895 A). */
    AGSSRUnitBenoit1895BYard		= 9060,     /*!< Yard (Benoit 1895 B). */
    AGSSRUnitBenoit1895BFoot		= 9061,     /*!< Foot (Benoit 1895 B). */
    AGSSRUnitBenoit1895BChain		= 9062,     /*!< Chain (Benoit 1895 B). */
    AGSSRUnitBenoit1895BLink		= 9063,     /*!< Link (Benoit 1895 B). */
    AGSSRUnitIndianFoot				= 9080,     /*!< Indian geodetic foot. */
    AGSSRUnitIndian1937Foot			= 9081,     /*!< Indian foot (1937). */
    AGSSRUnitIndian1962Foot			= 9082,     /*!< Indian foot (1962). */
    AGSSRUnitIndian1975Foot			= 9083,     /*!< Indian foot (1975). */
    AGSSRUnitIndianYard				= 9084,     /*!< Indian yard. */
    AGSSRUnitIndian1937Yard			= 9085,     /*!< Indian yard (1937). */
    AGSSRUnitIndian1962Yard			= 9086,     /*!< Indian yard (1962). */
    AGSSRUnitIndian1975Yard			= 9087,     /*!< Indian yard (1975). */
    AGSSRUnitFoot1865				= 9070,     /*!< Foot (1865). */
    AGSSRUnitRadian					= 9101,     /*!< Radian. */
    AGSSRUnitDegree					= 9102,     /*!< Degree. */
    AGSSRUnitArcMinute				= 9103,     /*!< Arc-minute. */
    AGSSRUnitArcSecond				= 9104,     /*!< Arc-second. */
    AGSSRUnitGrad					= 9105,     /*!< Grad. */
    AGSSRUnitGon					= 9106,     /*!< Gon. */
    AGSSRUnitMicroradian			= 9109,     /*!< Microradian. */
    AGSSRUnitArcMinuteCentesimal	= 9112,     /*!< Centesimal arc-minute. */
    AGSSRUnitArcSecondCentesimal	= 9113,     /*!< Centesimal arc-second. */
    AGSSRUnitMil6400				= 9114,     /*!< Mil. */
    AGSSRUnitBritish1936Foot		= 9095,		/*!< British Foot (1936). */
    AGSSRUnitGoldCoastFoot			= 9094,		/*!< Gold Coast Foot. */
    AGSSRUnitInternationalChain		= 109003,	/*!< International Chain. */
    AGSSRUnitInternationalLink		= 109004,	/*!< International Link. */
    AGSSRUnitInternationalYard		= 109001,	/*!< International Yard. */
    AGSSRUnitStatuteMile			= 9093,		/*!< Statute Mile. */
    AGSSRUnitSurveyYard				= 109002,	/*!< US survey Yard. */
    AGSSRUnit50KilometerLength		= 109030,	/*!< 50 Kilometer Length. */
    AGSSRUnit150KilometerLength		= 109031,	/*!< 150 Kilometer Length. */
    AGSSRUnitDecimeter				= 109005,	/*!< Decimeter. */
    AGSSRUnitCentimeter				= 109006,	/*!< Centimeter. */
    AGSSRUnitMillimeter				= 109007,	/*!< Millimeter. */
    AGSSRUnitInternationalInch		= 109008,	/*!< International inch. */
    AGSSRUnitUSsurveyInch			= 109009,	/*!< US survey inch. */
    AGSSRUnitInternationalRod		= 109010,	/*!< International rod. */
    AGSSRUnitUSsurveyRod			= 109011,	/*!< US survey rod. */
    AGSSRUnitUSNauticalMile			= 109012,	/*!< US nautical mile (pre-1954). */
    AGSSRUnitUKNauticalMile			= 109013	/*!< UK nautical mile (pre-1970). */
} AGSSRUnit;

/** Supported @p offsetHow types for the <code>AGSGeometryServiceTask</code>'s 
 <code>offsetWithParameters:</code> operation.
 @since 1.0
 */
typedef enum {
	AGSGeometryOffsetTypeMitered = 0,   /*!<  */
	AGSGeometryOffsetTypeBevelled,      /*!<  */
	AGSGeometryOffsetTypeRounded,       /*!<  */
	AGSGeometryOffsetTypeSquare         /** Only applicable with the AGSGeometryEngine */
} AGSGeometryOffsetType;


/** Specifies the way of timeOfDay property is used.
 @since 2.3
 @avail{10.1}
 */
typedef enum {
    AGSNATimeOfDayUseAsStartTime = 0, /*!<  Use as the start time.*/
    AGSNATimeOfDayUseAsEndTime        /*!<  Use as the end time.*/
} AGSNATimeOfDayUse;

/** Defines content, verbosity of returned directions.
 @since 2.3
 @avail{10.1}
 */
typedef enum {
    AGSNADirectionsOutputTypeStandard = 0,		/*!< Standard directions output ﾖ direction text instructions, geometry, time, length, ETA. Does not include events, new types*/
	AGSNADirectionsOutputTypeComplete,      	/*!< Directions output that includes all directions properties.*/
    AGSNADirectionsOutputTypeCompleteNoEvents,  /*!< Directions output that includes all directions properties except events.*/
    AGSNADirectionsOutputTypeInstructionsOnly,  /*!< Directions output that includes text instructions, time, length and ETA. Does not include geometry.*/
    AGSNADirectionsOutputTypeSummaryOnly        /*!< Directions output that contains only summary (time and length). Detailed text instructions and geometry are not provided.*/
} AGSNADirectionsOutputType;

/** Specifies the type of lines generated by the network analyst solvers.
 
 Note: <code>AGSNAOutputLineTrueShapeWithMeasure</code> is only available at 10.1 and beyond.
 @since 1.8
 */
typedef enum : NSUInteger {
	AGSNAOutputLineNone = 0,				/*!< No polylines are generated. */
	AGSNAOutputLineStraight,				/*!< Straight polylines between the two endpoints are generated. */
	AGSNAOutputLineTrueShape,				/*!< Polylines based on the true network feature geometry are generated. */
    AGSNAOutputLineTrueShapeWithMeasure     /*!< Polylines based on the true network feature geometry are generated, and measures are added whenever possible. */
} AGSNAOutputLine;

/** Constants representing how U-Turns are handled
 @since 1.8
 */
typedef enum : NSUInteger {
	AGSNAUTurnAllowBacktrack = 0,			/*!<  Allow U-turns anywhere.*/
	AGSNAUTurnAtDeadEndsOnly,				/*!<  Allow U-turns only at dead ends only.*/
	AGSNAUTurnNoBacktrack,					/*!<  Don't allow U-turns anywhere.*/
	AGSNAUTurnAtDeadEndsAndIntersections,	/*!<  Allow U-turns at dead ends and intersections only. */
} AGSNAUTurn;

/** Constants representing directions length units for the @c AGSRouteTask.
 @since 1.8
 */
typedef enum : NSUInteger {
	AGSNAUnitCentimeters = 0,	/*!< */
	AGSNAUnitDays,				/*!< */
	AGSNAUnitDecimalDegrees,	/*!< */
	AGSNAUnitDecimeters,		/*!< */
	AGSNAUnitFeet,				/*!< */
	AGSNAUnitHours,				/*!< */
	AGSNAUnitInches,			/*!< */
	AGSNAUnitKilometers,		/*!< */
	AGSNAUnitMeters,			/*!< */
	AGSNAUnitMiles,				/*!< */
	AGSNAUnitMillimeters,		/*!< */
	AGSNAUnitMinutes,			/*!< */
	AGSNAUnitNauticalMiles,		/*!< */
	AGSNAUnitPoints,			/*!< */
	AGSNAUnitSeconds,			/*!< */
	AGSNAUnitUnknown,			/*!< */
	AGSNAUnitYards,				/*!< */
} AGSNAUnit;

/** Constant representing the type of network layer.
 @since 1.8
 */
typedef enum {
	AGSNALayerTypeRoute = 0,			/*!<  Route Layer. */
	AGSNALayerTypeServiceArea,			/*!<  Service Area Layer. */
	AGSNALayerTypeClosestFacility,		/*!<  Closest Facility Layer. */
} AGSNALayerType;

/** Constants representing how the geometry is returned.
 @since 1.8
 */
typedef enum : NSUInteger {
	AGSNATravelDirectionFromFacility = 0,	/*!< Tavel to the facility. */
	AGSNATravelDirectionToFacility,			/*!< Travel from the facility. */
} AGSNATravelDirection;

/** Constants representing maneuver types for a direction.
 @since 1.8
 */
typedef enum {
	AGSNADirectionsManeuverUnknown = 0,		/*!< Unknown */
	AGSNADirectionsManeuverStop,			/*!< Arrive At Stop. */
	AGSNADirectionsManeuverStraight,		/*!< Go straight. */
	AGSNADirectionsManeuverBearLeft,		/*!< Bear left.*/
	AGSNADirectionsManeuverBearRight,		/*!< Bear righty. */
	AGSNADirectionsManeuverTurnLeft,		/*!< Turn left.*/
	AGSNADirectionsManeuverTurnRight,		/*!< Turn right. */
	AGSNADirectionsManeuverSharpLeft,		/*!< Make sharp left. */
	AGSNADirectionsManeuverSharpRight,		/*!< Make sharp right. */
	AGSNADirectionsManeuverUTurn,			/*!< Make a U-turn. */
	AGSNADirectionsManeuverFerry,			/*!< Take ferry. */
	AGSNADirectionsManeuverRoundabout,		/*!< Take roundabout. */
	AGSNADirectionsManeuverHighwayMerge,	/*!< Merge to highway. */
	AGSNADirectionsManeuverHighwayExit,		/*!< Exit highway. */
	AGSNADirectionsManeuverHighwayChange,	/*!< Go on another highway. */
    AGSNADirectionsManeuverForkCenter,		/*!< At fork keep center. */
	AGSNADirectionsManeuverForkLeft,		/*!< At fork keep left. */
	AGSNADirectionsManeuverForkRight,		/*!< At fork keep right. */
	AGSNADirectionsManeuverDepart,			/*!< Depart stop. */
	AGSNADirectionsManeuverTripItem,		/*!< Trip planning item. */
	AGSNADirectionsManeuverEndOfFerry,		/*!< End of ferry. */
    AGSNADirectionsManeuverRampRight,       /*!< Ramp right. */
    AGSNADirectionsManeuverRampLeft,        /*!< Ramp left. */
    AGSNADirectionsManeuverTurnLeftRight,	/*!< Turn left and immediately turn right. */
    AGSNADirectionsManeuverTurnRightLeft,	/*!< Turn right and immediately turn left. */
	AGSNADirectionsManeuverTurnRightRight,	/*!< Turn right and immediately turn right. */
    AGSNADirectionsManeuverTurnLeftLeft,	/*!< Turn left and immediately turn left. */
    AGSNADirectionsManeuverPedestrianRamp,  /*!< Pedestrian ramp. */
    AGSNADirectionsManeuverElevator,        /*!< Elevator. */
    AGSNADirectionsManeuverEscalator,       /*!< Escalator. */
    AGSNADirectionsManeuverStairs,          /*!< Stairs. */
    AGSNADirectionsManeuverDoorPassage,     /*!< Door passage. */
} AGSNADirectionsManeuver;

/** Types of direction strings. These are associated with the more detailed
 direction info passed back from a route solving operation.
 @since 2.3
 @avail{10.1}
 */
typedef enum {
    AGSNADirectionsStringGeneral = 0,           /*!< General directions string type.*/
    AGSNADirectionsStringDepart,                /*!< Depart directions string type.*/
    AGSNADirectionsStringArrive,                /*!< Arrive directions string type.*/
    AGSNADirectionsStringLength,                /*!< Length directions string type.*/
    AGSNADirectionsStringTime,                  /*!< Time directions string type.*/
    AGSNADirectionsStringSummary,               /*!< Time directions string type.*/
    AGSNADirectionsStringTimeWindow,            /*!< Time Window directions string type.*/
    AGSNADirectionsStringViolationTime,         /*!< Violation Time directions string type.*/
    AGSNADirectionsStringWaitTime,              /*!< Wait Time directions string type.*/
    AGSNADirectionsStringServiceTime,           /*!< Service Time directions string type.*/
    AGSNADirectionsStringEstimatedArrivalTime,  /*!< Estimated Arrival Time directions string type.*/
    AGSNADirectionsStringCumulativeLength,      /*!< Cumulative Length directions string type.*/
    AGSNADirectionsStringStreetName,            /*!< Street name directions string type.*/
    AGSNADirectionsStringAltName,               /*!< Alternate street name directions string type.*/
    AGSNADirectionsStringBranch,                /*!< Sign branch information directions string type.*/
    AGSNADirectionsStringToward,                /*!< Sign toward information directions string type.*/
    AGSNADirectionsStringCrossStreet,           /*!< Cross street name directions string type.*/
    AGSNADirectionsStringExit,                  /*!< Sign exit number directions string type.*/
} AGSNADirectionsStringType;

/** Constants representing the network analyst message type.
 @since 1.8
 */
typedef enum {
	AGSNAMessageTypeAbort = 0,					/*!<  */
	AGSNAMessageTypeEmpty = 1,					/*!<  */
	AGSNAMessageTypeError = 2,					/*!<  */
	AGSNAMessageTypeInformative = 3,			/*!<  */
	AGSNAMessageTypeProcessDefinition = 50,		/*!<  */
	AGSNAMessageTypeProcessStart = 100,			/*!<  */
	AGSNAMessageTypeProcessStop = 101,			/*!<  */
	AGSNAMessageTypeWarning = 200,				/*!<  */
} AGSNAMessageType;

/** Contstants representing how the geometry is returned.
 @since 1.8
 */
typedef enum : NSUInteger {
	AGSNAOutputPolygonDetailed = 0,			/*!< No polygons are generated. */	
	AGSNAOutputPolygonNone,					/*!< Simplified polygons are generated. */
	AGSNAOutputPolygonSimplified			/*!< Detailed polygons are generated. */
} AGSNAOutputPolygon;

/** Conversion mode for MGRS coordinates
 @since 2.3
 */
typedef enum {
    AGSMGRSConversionModeNewStyle = 0,      /*!<  */
} AGSMGRSConversionMode;

/** Constants representing error codes.
 @since 2.1
 */
typedef enum {
	AGSErrorCodeOperationNotSupported = 10000,          /*!<  */
    AGSErrorCodeNoDataTile = 10001,                     /*!<  */
    AGSErrorCodeSpatialReferenceNotSupported = 10002,   /*!<  */
    AGSErrorCodeInvalidArgument = 10003                 /*!<  */
} AGSErrorCode;



///** Defines the drawing behavior for a dynamic layer when
// the map's location display is in an autopan mode other than off.
// @since 2.1
// */
//typedef enum {
//	AGSDynamicLayerAutoPanDrawingModeNormal = 0,	/*!< Dynamic layer draws normally. */
//    AGSDynamicLayerAutoPanDrawingModeConservative, /*!< Dynamic layer draws only when it doesn't currently have a drawing operation in progress. 
//                                                       This lessens the load on the server.*/
//    AGSDynamicLayerAutoPanDrawingModeNone /*!< Dynamic layer does not draw when the map is in navigation mode. */
//} AGSDynamicLayerAutoPanDrawingMode;


/**
 @since 2.2
 */
typedef enum : NSUInteger {
    AGSPortalItemTypeOther = 0,                          /*!< */
    AGSPortalItemTypeMapDocument,               /*!< ArcMap Document (mxd) */
    AGSPortalItemTypeExplorerMap,                   /*!< ArcGIS Explorer Document (nmf) */
    AGSPortalItemTypeGlobeDocument,                 /*!< ArcGlobe Document (3dd) */
    AGSPortalItemTypeSceneDocument,                 /*!< ArcScene Document (sxd) */
    //AGSPortalItemTypeExplorerMap,                  /*!< ArcGIS Explorer Application Configuration (ncfg) */
    AGSPortalItemTypePublishedMap,                  /*!< ArcReader Document (pmf) */
    AGSPortalItemTypeMapPackage,                    /*!< ArcGIS Map Package (mpk)  */
    AGSPortalItemTypeGeoprocessingPackage,          /*!< ArcGIS Geoprocessing Package (gpk) */
    AGSPortalItemTypeLocatorPackage,                /*!< ArcGIS Locator Package (apk) */
    AGSPortalItemTypeTilePackage,                   /*!< ArcGIS Server Tile Package (tpk)*/
    AGSPortalItemTypeWindowsMobilePackage,          /*!< ArcGIS Windows Mobile Package */
    AGSPortalItemTypeDesktopApplicationTemplate,    /*!< The Desktop Application Template (.zip) includes either a desktop add in or a toolbar.exe */
    AGSPortalItemTypeMapTemplate,                   /*!< The Map Template (.zip) contains documentation, a map and GDB folder */
    AGSPortalItemTypeCodeSample,                    /*!< Developer Sample */
    AGSPortalItemTypeGeoprocessingSample,           /*!< Tool, Geoprocessing Sample */
    AGSPortalItemTypeLayer,                         /*!< Layer File (lyr) */
    AGSPortalItemTypeLayerPackage,                  /*!< Layer Package (lpk) */
    AGSPortalItemTypeExplorerLayer,                 /*!< ArcGIS Explorer Layer (nmc) */
    AGSPortalItemTypeDesktopAddIn,                  /*!< ArcGIS Add In (esriaddin) */
    AGSPortalItemTypeExplorerAddIn,                 /*!< ArcGIS Explorer Layer (eaz) */
    AGSPortalItemTypeMapService,                    /*!< ArcGIS Server Map Service */
    AGSPortalItemTypeGeocodingService,              /*!< ArcGIS Server Geocoding Service */
    AGSPortalItemTypeNetworkAnalysisService,        /*!< ArcGIS Server Network Analyst Service */
    AGSPortalItemTypeGlobeService,                  /*!< ArcGIS Server Globe Service */
    AGSPortalItemTypeGeoprocessingService,          /*!< ArcGIS Server Geoprocessing Service */
    AGSPortalItemTypeGeodataService,                /*!< ArcGIS Server Geodata Service */
    AGSPortalItemTypeImageService,                  /*!< ArcGIS Server Image Service */
    AGSPortalItemTypeGeometryService,               /*!< ArcGIS Server Geometry Service */
    AGSPortalItemTypeFeatureService,                /*!< ArcGIS Feature Service */
    AGSPortalItemTypeKML,                           /*!< Data, Map, kml */
    AGSPortalItemTypeWMS,                           /*!< Data, Service, Web Map Service, OGC */
    AGSPortalItemTypeWMTS,                          /*!< Data, Service, Web Map Tile Service, OGC */
    AGSPortalItemTypeWebMap,                        /*!< Web Map authored using the arcgis.com Javascript Web Map viewer or using ArcGIS Explorer online. Usable by web, mobile, and desktop clients */
    AGSPortalItemTypeWebMappingApplication,         /*!< A web mapping application built using ArcGIS API for Javascript, ArcGIS API for Flex, ArcGIS API for Silverlight, Java Web Application Developer Framework, .NET Web Application Developer Framework */
    AGSPortalItemTypeMobileApplication,             /*!< A mobile application build using the ArcGIS for iPhone SDK, ArcGIS for Android SDK, ArcGIS Mobile SDK for the Windows Mobile Platform, or the JavaScript or Flex API */
    AGSPortalItemTypeCodeAttachment,                /*!< Code Attachment */
    AGSPortalItemTypeFeaturedItems,                 /*!< Empty Item type with relationships to items that user wants featured */
    AGSPortalItemTypeFeatureCollection,             /*!< A feature collection is a saved web map feature layer with layer definition and a feature set */
    AGSPortalItemTypeFeatureCollectionTemplate,     /*!< Feature Collection, Feature Service Template, Map Notes Template */
    AGSPortalItemTypeSymbolSet,                     /*!< Symbol Set*/
    AGSPortalItemTypeColorSet,                      /*!< Color Set */
    AGSPortalItemTypeCollectionDefinition,          /*!< The definition for a feature collection/web map feature layer */
    AGSPortalItemTypeOperationView,                 /*!< An Operation View */
    AGSPortalItemTypeOperationsDashboardAddin,      /*!< An Operations Dashboard Addin */
    AGSPortalItemTypeCityEngineWebScene,            /*!< A CityEngine Web Scene */
    AGSPortalItemTypeWorkflowManagerPackage,        /*!< A Workflow Manager Package (wpk) */
    AGSPortalItemTypeArcPadPackage,                 /*!< An ArcPad Package (appk) */
    AGSPortalItemTypeShapefile,                     /*!< A shapefile */
    AGSPortalItemTypeCSV,                           /*!< A text file of data values separated by commas or other delimiters */
    AGSPortalItemTypeServiceDefinition              /*!< A Service Definition that can be published to create a geospatial web service */
} AGSPortalItemType;

/** Access types on Portal, Item, Group or User. 
 
 <b> For Portal or Organization </b>
 
 Determines who can view your organization as an anonymous user. <code>AGSPortalAccessPublic</code> 
 means it allows anonymous users to access your organization's custom URL. <code>AGSPortalAccessPrivate </code> restricts access to only members of your organization.  
 
 <b> For Portal Item </b>
 
 Indicates the access level of the item. If <code>AGSPortalAccessPrivate</code>, only the item owner can
 access. <code>AGSPortalAccessShared</code> allows the item to be shared with a specific group. <code>
 AGSPortalAccessOrganization</code> restricts item access to members of your organization. If <code>
 AGSPortalAccessPublic</code>, all users can access the item.
 
 <b> For Portal Group </b>
 
 Determines who can access the group. <code>AGSPortalAccessPrivate</code> gives access to only the group
 members. If <code>AGSPortalAccessOrganization</code>, all members of this organization can access the
 group. <code>AGSPortalAccessPublic</code> makes the group accessible to all.
 
 <b> For Portal User </b>
 
 Determines if other users can search for this user's name to find content and groups owned by this user
 and to invite this user to join their groups. <code>AGSPortalAccessPrivate</code> hides the user from
 user searches and invites. If <code>AGSPortalAccessOrganization</code>, only members of this user's 
 organization can search for this user, the content and groups. <code>AGSPortalAccessPublic</code> makes 
 the user findable.
 
 @since 2.2
 */
typedef enum { 
    AGSPortalAccessPrivate = 0,                     /*!< Applicable for All  */
    AGSPortalAccessShared,                          /*!< Applicable for only Items  */
    AGSPortalAccessOrganization,                    /*!< Applicable for Items, Groups and Users  */
    AGSPortalAccessPublic                           /*!< Applicable for All  */
} AGSPortalAccess;

/** Indicates the oder of results of the portal query.  
 @since 2.2
 */
typedef enum{
	AGSPortalQuerySortOrderAscending = 0,   	/*!<  */
	AGSPortalQuerySortOrderDescending,			/*!<  */
} AGSPortalQuerySortOrder;


/** Indicating whether the portal contains multiple organizations or not. 
 @since 2.2
 */
typedef enum {
	AGSPortalModeSingleTenant = 0,   	/*!< Only one organization*/
	AGSPortalModeMultiTenant,			/*!< Multiple organizations*/
} AGSPortalMode;

/** Indicates the role of the portal user within an organization.
 @since 10.1.1
 */
typedef enum {
    AGSPortalUserRoleNone = 0,              /*!< The user does not belong to an organization */
    AGSPortalUserRoleUser,                  /*!< Information worker */
    AGSPortalUserRolePublisher,             /*!< Publisher */
    AGSPortalUserRoleAdmin,                 /*!< Administrator */
} AGSPortalUserRole;

/**
 @since 2.3
 */
typedef enum {
    AGSWMTSServiceModeRESTful = 0,              /*!<  */
    AGSWMTSServiceModeKVP                       /*!<  */
} AGSWMTSServiceMode;


/** Supported image formats.
 @since 1.0
 */
typedef enum {
    AGSImageFormatUnknown = -1, /*!<  */
    AGSImageFormatPNG32 = 0,	/*!<  */
    AGSImageFormatPNG24,		/*!<  */
    AGSImageFormatPNG8,			/*!<  */
    AGSImageFormatPNG,			/*!<  */
    AGSImageFormatJPG,			/*!<  */
    AGSImageFormatGIF,			/*!<  */
	AGSImageFormatBMP,			/*!<  */
	AGSImageFormatTIFF,			/*!<  */
	AGSImageFormatJPGPNG,		/*!<  */
    //For most layers JPEG should be treated the same as JPG using jpg for the files extension, however for some (only WMTS so far)
    //the file extension used for JPEG needs to be jpeg.
	AGSImageFormatJPEG          /*!<  */
} AGSImageFormat;

/** An enumeration that is used for defining the style of an AGSPopupsContainer.
 @since 2.0
 */
typedef enum {
	AGSPopupsContainerStyleDefault = 0, /*!<  */
	AGSPopupsContainerStyleBlack,       /*!<  */
	AGSPopupsContainerStyleCustomColor  /*!<  */
} AGSPopupsContainerStyle;

/** An enumeration that is used for defining the editing style of an AGSPopupsContainer.
 @since 2.0
 */
typedef enum {
	AGSPopupsContainerEditingStyleGeometryTool,     /*!< Shows a toolbar with a button for attachments and a button for collecting the geometry */
	AGSPopupsContainerEditingStyleGeometryInline    /*!< has a view to switch between attributes and attachments,
                                                     there is no button for the collecting the geometry, as this is assumed
                                                     the user has access to the map while the popup is up (think ipad), or
                                                     the user will not be collecting a geometry at all. */
} AGSPopupsContainerEditingStyle;

/** An enumeration that is used for defining the Paging style of an AGSPopupsContainer.
 @since 2.0
 */
typedef enum {
	AGSPopupsContainerPagingStylePageControl,   /*!<  */
	AGSPopupsContainerPagingStyleToolbar        /*!<  */
} AGSPopupsContainerPagingStyle;

/** An enumeration that is used for defining statistic calculations in AGSOutStatistics.
 @since 10.1.1
 */
typedef enum {
    AGSQueryStatisticsTypeCount,            /*!<  */
    AGSQueryStatisticsTypeSum,              /*!<  */
    AGSQueryStatisticsTypeMin,              /*!<  */
    AGSQueryStatisticsTypeMax,              /*!<  */
    AGSQueryStatisticsTypeAvg,              /*!<  */
    AGSQueryStatisticsTypeStdDev,           /*!<  */
    AGSQueryStatisticsTypeVar,              /*!<  */
} AGSQueryStatisticsType;

/** Military symbology dictionary type
 @since 10.1.1
 */
typedef enum {
    AGSMPSymbolDictionaryTypeMil2525C,              /*!<  */
    AGSMPSymbolDictionaryTypeApp6B,                 /*!<  */
    AGSMPSymbolDictionaryTypeSimple                 /*!<  */
} AGSMPSymbolDictionaryType;
    
/** Returns the image format as a string.
 @since 1.0
 */
AGS_EXTERN NSString *AGSFileFormatForImageFormat(AGSImageFormat imageFormat);
    
/** Returns the image format as a string.
 @since 10.1.1
 */
AGS_EXTERN NSString *AGSFileFormatForImageFormatWithJPEGEqualToJPG(AGSImageFormat imageFormat, BOOL IsJPEGEqualToJPG);
