using System;
using MonoTouch.Foundation;

namespace MonoTouch.ArcGIS {

	public enum AGSMapViewWrapAroundStatus {
		Disabled,
		Uninitialized,
		Unsupported,
		Enabled
	}

	public enum AGSTextSymbolVAlignment {
		Bottom = 0,
		Middle,
		Top
	}

	public enum AGSTextSymbolHAlignment {
		Left = 0,
		Center,
		Right
	}

	public enum AGSSimpleMarkerSymbolStyle {
		Circle = 0,
		Cross,
		Diamond,
		Square,
		X
	}

	public enum AGSInterpolation : ulong {
		Bilinear = 0,
		CubicConvolution,
		Majority,
		NearestNeighbor = (2147483647L * 2UL + 1UL)
	}

	public enum AGSGeometryRelation {
		Cross = 0,
		Disjoint,
		In,
		InteriorIntersection,
		Intersection,
		LineCoincidence,
		LineTouch,
		Overlap,
		PointTouch,
		Touch,
		Within,
		Relation
	}

	public enum AGSGeometryType {
		Undefined = -1,
		Point,
		Polyline,
		Polygon,
		Multipoint,
		Envelope
	}

	public enum AGSRasterFunctionType {
		Aspect = 0,
		Colormap,
		Hillshade,
		NDVI,
		ShadedRelief,
		Slope,
		Statistics,
		Stretch
	}

	public enum AGSFieldType {
		Integer = 0,
		SmallInteger,
		Double,
		Single,
		String,
		Date,
		Geometry,
		OID,
		Blob,
		GlobalID,
		Raster,
		GUID,
		XML
	}

	public enum AGSTimeIntervalUnits {
		Milliseconds = 0,
		Seconds,
		Minutes,
		Hours,
		Days,
		Weeks,
		Months,
		Years,
		Decades,
		Centuries,
		Unknown
	}

	public enum AGSSpatialRelationship {
		Intersects = 0,
		Contains,
		Crosses,
		EnvelopeIntersects,
		IndexIntersects,
		Overlaps,
		Touches,
		Within,
		Relation
	}

	public enum AGSUnits {
		Centimeters = 0,
		DecimalDegrees,
		Decimeters,
		Feet,
		Inches,
		Kilometers,
		Meters,
		Miles,
		Millimeters,
		NauticalMiles,
		Points,
		Unknown,
		Yards
	}

	public enum AGSAreaUnits {
		SquareInches = 0,
		SquareFeet,
		SquareYards,
		Acres,
		SquareMiles,
		SquareMillimeters,
		SquareCentimeters,
		SquareDecimeters,
		SquareMeters,
		Ares,
		Hectares,
		SquareKilometers
	}

	public enum AGSSRUnit {
		Meter = 9001,
		GermanMeter = 9031,
		Foot = 9002,
		SurveyFoot = 9003,
		ClarkeFoot = 9005,
		Fathom = 9014,
		NauticalMile = 9030,
		SurveyChain = 9033,
		SurveyLink = 9034,
		SurveyMile = 9035,
		Kilometer = 9036,
		ClarkeYard = 9037,
		ClarkeChain = 9038,
		ClarkeLink = 9039,
		SearsYard = 9040,
		SearsFoot = 9041,
		SearsChain = 9042,
		SearsLink = 9043,
		Benoit1895AYard = 9050,
		Benoit1895AFoot = 9051,
		Benoit1895AChain = 9052,
		Benoit1895ALink = 9053,
		Benoit1895BYard = 9060,
		Benoit1895BFoot = 9061,
		Benoit1895BChain = 9062,
		Benoit1895BLink = 9063,
		IndianFoot = 9080,
		Indian1937Foot = 9081,
		Indian1962Foot = 9082,
		Indian1975Foot = 9083,
		IndianYard = 9084,
		Indian1937Yard = 9085,
		Indian1962Yard = 9086,
		Indian1975Yard = 9087,
		Foot1865 = 9070,
		Radian = 9101,
		Degree = 9102,
		ArcMinute = 9103,
		ArcSecond = 9104,
		Grad = 9105,
		Gon = 9106,
		Microradian = 9109,
		ArcMinuteCentesimal = 9112,
		ArcSecondCentesimal = 9113,
		Mil6400 = 9114,
		British1936Foot = 9095,
		GoldCoastFoot = 9094,
		InternationalChain = 109003,
		InternationalLink = 109004,
		InternationalYard = 109001,
		StatuteMile = 9093,
		SurveyYard = 109002,
		Kilometer50Length = 109030,
		Kilometer150Length = 109031,
		Decimeter = 109005,
		Centimeter = 109006,
		Millimeter = 109007,
		InternationalInch = 109008,
		USsurveyInch = 109009,
		InternationalRod = 109010,
		USsurveyRod = 109011,
		USNauticalMile = 109012,
		UKNauticalMile = 109013
	}

	public enum AGSGeometryOffsetType {
		Mitered = 0,
		Bevelled,
		Rounded,
		Square
	}

	public enum AGSNATimeOfDayUse {
		AsStartTime = 0,
		AsEndTime
	}

	public enum AGSNADirectionsOutputType {
		Standard = 0,
		Complete,
		CompleteNoEvents,
		InstructionsOnly,
		SummaryOnly
	}

	public enum AGSNAOutputLine {
		None = 0,
		Straight,
		TrueShape,
		TrueShapeWithMeasure
	}

	public enum AGSNAUTurn {
		AllowBacktrack = 0,
		AtDeadEndsOnly,
		NoBacktrack,
		AtDeadEndsAndIntersections
	}

	public enum AGSNAUnit {
		Centimeters = 0,
		Days,
		DecimalDegrees,
		Decimeters,
		Feet,
		Hours,
		Inches,
		Kilometers,
		Meters,
		Miles,
		Millimeters,
		Minutes,
		NauticalMiles,
		Points,
		Seconds,
		Unknown,
		Yards
	}

	public enum AGSNALayerType {
		Route = 0,
		ServiceArea,
		ClosestFacility
	}

	public enum AGSNATravelDirection {
		FromFacility = 0,
		ToFacility
	}

	public enum AGSNADirectionsManeuver {
		Unknown = 0,
		Stop,
		Straight,
		BearLeft,
		BearRight,
		TurnLeft,
		TurnRight,
		SharpLeft,
		SharpRight,
		UTurn,
		Ferry,
		Roundabout,
		HighwayMerge,
		HighwayExit,
		HighwayChange,
		ForkCenter,
		ForkLeft,
		ForkRight,
		Depart,
		TripItem,
		EndOfFerry,
		RampRight,
		RampLeft,
		TurnLeftRight,
		TurnRightLeft,
		TurnRightRight,
		TurnLeftLeft,
		PedestrianRamp,
		Elevator,
		Escalator,
		Stairs,
		DoorPassage
	}

	public enum AGSNADirectionsStringType {
		General = 0,
		Depart,
		Arrive,
		Length,
		ime,
		Summary,
		imeWindow,
		ViolationTime,
		WaitTime,
		ServiceTime,
		EstimatedArrivalTime,
		CumulativeLength,
		StreetName,
		AltName,
		Branch,
		oward,
		CrossStreet,
		Exit
	}

	public enum AGSNAMessageType {
		Abort = 0,
		Empty = 1,
		Error = 2,
		Informative = 3,
		ProcessDefinition = 50,
		ProcessStart = 100,
		ProcessStop = 101,
		Warning = 200
	}

	public enum AGSNAOutputPolygon {
		Detailed = 0,
		None,
		Simplified
	}

	public enum AGSMGRSConversionMode {
		NewStyle = 0
	}

	public enum AGSErrorCode {
		OperationNotSupported = 10000,
		NoDataTile = 10001,
		SpatialReferenceNotSupported = 10002,
		InvalidArgument = 10003
	}

	public enum AGSPortalItemType {
		Other = 0,
		MapDocument,
		ExplorerMap,
		GlobeDocument,
		SceneDocument,
		PublishedMap,
		MapPackage,
		GeoprocessingPackage,
		LocatorPackage,
		TilePackage,
		WindowsMobilePackage,
		DesktopApplicationTemplate,
		MapTemplate,
		CodeSample,
		GeoprocessingSample,
		Layer,
		LayerPackage,
		ExplorerLayer,
		DesktopAddIn,
		ExplorerAddIn,
		MapService,
		GeocodingService,
		NetworkAnalysisService,
		GlobeService,
		GeoprocessingService,
		GeodataService,
		ImageService,
		GeometryService,
		FeatureService,
		KML,
		WMS,
		WMTS,
		WebMap,
		WebMappingApplication,
		MobileApplication,
		CodeAttachment,
		FeaturedItems,
		FeatureCollection,
		FeatureCollectionTemplate,
		SymbolSet,
		ColorSet,
		CollectionDefinition,
		OperationView,
		OperationsDashboardAddin,
		CityEngineWebScene,
		WorkflowManagerPackage,
		ArcPadPackage,
		Shapefile,
		CSV,
		ServiceDefinition
	}

	public enum AGSPortalAccess {
		Private = 0,
		Shared,
		Organization,
		Public
	}

	public enum AGSPortalQuerySortOrder {
		Ascending = 0,
		Descending
	}

	public enum AGSPortalMode {
		SingleTenant = 0,
		MultiTenant
	}

	public enum AGSPortalUserRole {
		None = 0,
		User,
		Publisher,
		Admin
	}

	public enum AGSWMTSServiceMode {
		RESTful = 0,
		KVP
	}

	public enum AGSImageFormat {
		Unknown = -1,
		PNG32 = 0,
		PNG24,
		PNG8,
		PNG,
		JPG,
		GIF,
		BMP,
		TIFF,
		JPGPNG,
		JPEG
	}

	public enum AGSPopupsContainerStyle {
		Default = 0,
		Black,
		CustomColor
	}

	public enum AGSPopupsContainerEditingStyle {
		GeometryTool,
		GeometryInline
	}

	public enum AGSPopupsContainerPagingStyle {
		PageControl,
		Toolbar
	}

	public enum AGSQueryStatisticsType {
		Count,
		Sum,
		Min,
		Max,
		Avg,
		StdDev,
		Var
	}

	public enum AGSMPSymbolDictionaryType {
		Mil2525C,
		App6B,
		Simple
	}

	public enum AGSAuthenticationType {
		Unknown = 0,
		None,
		Token,
		HTTP,
		ClientCertificate
	}

	public enum AGSCredentialErrorType {
		None = 0,
		InvalidCredentials,
		SSLRequired,
		Unknown
	}

	public enum AGSMapUpdateType {
		SpatialExtent,
		TimeExtent,
		LayerAdded,
		LayerRemoved
	}

	public enum AGSGPAsyncOperationType {
		Submit = 0,
		CheckStatus,
		QueryResultData,
		QueryResultImage,
		QueryResultImageLayer,
		Cancel
	}

	public enum AGSGPMessageType {
		Informative = 0,
		ProcessDefinition,
		Start,
		Stop,
		Warning,
		Error,
		Empty,
		Abort
	}

	public enum AGSGPParameterType {
		Boolean = 0,
		Double,
		Long,
		String,
		LinearUnit,
		FeatureRecordSetLayer,
		RecordSet,
		DataFile,
		Date,
		RasterData,
		RasterDataLayer,
		MultiValue
	}

	public enum AGSMosaicMethod {
		None = 0,
		Center,
		Nadir,
		Viewpoint,
		Attribute,
		LockRaster,
		Northwest,
		Seamline
	}

	public enum AGSMosaicOperationType {
		First = 0,
		Last,
		Min,
		Max,
		Mean,
		Blend
	}

	public enum AGSBingMapLayerStyle {
		Aerial,
		AerialWithLabels,
		Road
	}

	public enum AGSCalloutLeaderPosition : ulong {
		Bottom = 1UL << 0,
		Top = 1UL << 1,
		Left = 1UL << 2,
		Right = 1UL << 3,
		Any = Bottom | Top | Left | Right
	}

	public enum AGSIdentifyParametersLayerOption {
		Top = 0,
		Visible,
		All
	}

	public enum AGSDeviceMachineType {
		Unknown = 0,
		iPhoneSimulator,
		iPhone,
		iPhone3G,
		iPhone3GS,
		iPhone4,
		iPhone5,
		iPod1stGen,
		iPod2ndGen,
		iPod3rdGen,
		iPod4thGen,
		iPod5thGen,
		iPad1stGen,
		iPad2ndGen,
		iPhone4S,
		iPad3rdGen,
		iPad4thGen,
		iPadMini,
		Mac
	}

	public enum AGSSBJsonStreamParserStatus {
		Complete,
		WaitingForData,
		Error
	}

	public enum AGSSBJsonStreamParserAdapterType {
		None,
		Array,
		Object
	}

	public enum AGSSimpleFillSymbolStyle {
		BackwardDiagonal = 0,
		Cross,
		DiagonalCross,
		ForwardDiagonal,
		Horizontal,
		Null,
		Solid,
		Vertical
	}

	public enum AGSSimpleLineSymbolStyle {
		Dash = 0,
		Dot,
		DashDot,
		DashDotDot,
		InsideFrame,
		Null,
		Solid
	}

	public enum AGSFeatureLayerMode {
		Snapshot = 0,
		OnDemand,
		Selection
	}

	public enum AGSFeatureLayerSelectionMethod {
		Add = 0,
		New,
		Subtract
	}

	public enum AGSAttachmentEditState {
		Original = 0,
		Added,
		MarkedForDeletion,
		DeletedFromServer
	}

	public enum AGSLabelPlacement {
		PointAboveCenter = 0,
		PointBelowCenter,
		PointCenterCenter,
		PointAboveLeft,
		PointBelowLeft,
		PointCenterLeft,
		PointAboveRight,
		PointBelowRight,
		PointCenterRight,
		LineAboveAfter,
		LineAboveStart,
		LineBelowAfter,
		LineBelowStart,
		LineCenterAfter,
		LineCenterStart,
		LineAboveAlong,
		LineAboveEnd,
		LineBelowAlong,
		LineBelowEnd,
		LineCenterAlong,
		LineCenterEnd,
		LineAboveBefore,
		LineBelowBefore,
		LineCenterBefore,
		PolygonAlwaysHorizontal
	}

	public enum AGSPopupFieldInfoDateFormat {
		ShortDate = 0,
		LongMonthDayYear,
		ShortMonthYear,
		DayShortMonthYear,
		LongDate,
		ShortDateShortTime,
		ShortDateShortTime24,
		LongMonthYear,
		Year,
		ShortDateLongTime,
		ShortDateLongTime24
	}

	public enum AGSPopupMediaInfoType {
		Image = 0,
		LineChart,
		BarChart,
		PieChart,
		ColumnChart
	}

	public enum AGSPopupViewType {
		Container = 0,
		UIImagePicker,
		FullMedia,
		Web,
		Attachments,
		Movie,
		Attribute
	}

	public enum AGSLocationDisplayAutoPanMode {
		Off = 0,
		Default,
		Navigation,
		CompassNavigation
	}

	public enum AGSGraphicsLayerRenderingMode {
		Static = 0,
		Dynamic
	}
}

