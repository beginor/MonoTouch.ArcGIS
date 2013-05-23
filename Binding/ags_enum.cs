using System;

namespace MonoTouch.ArcGIS {

	public enum AGSAttachmentEditState {
		Original = 0,
		Added = 1,
		MarkedForDeletion = 2,
		DeletedFromServer = 3
	}

	public enum AGSBingMapLayerStyle {
		Aerial = 0,
		AerialWithLabels = 1,
		Road = 2
	}

	public enum AGSCalloutLeaderPosition {
		Bottom = 1,
		Top = 2,
		Left = 4,
		Right = 8,
		Any = 15
	}

	public enum AGSAuthenticationType {
		Unknown = 0,
		None = 1,
		Token = 2,
		HTTP = 3,
		ClientCertificate = 4
	}

	public enum  AGSCredentialErrorType : uint {
		None = 0,
		InvalidCredentials = 1,
		SSLRequired = 2,
		Unknown = 3
	}

	public enum AGSDeviceMachineType {
		Unknown = 0,
		IPhoneSimulator = 1,
		IPhone = 2,
		IPhone3G = 3,
		IPhone3GS = 4,
		IPhone4 = 5,
		IPhone5 = 6,
		IPod1stGen = 7,
		IPod2ndGen = 8,
		IPod3rdGen = 9,
		IPod4thGen = 10,
		IPod5thGen = 11,
		IPad1stGen = 12,
		IPad2ndGen = 13,
		IPhone4S = 14,
		IPad3rdGen = 15,
		IPad4thGen = 16,
		IPadMini = 17,
		Mac = 18
	}

public enum AGSMapViewWrapAroundStatus {
		Disabled = 0,
		Uninitialized = 1,
		Unsupported = 2,
		Enabled = 3
	}

	public enum AGSTextSymbolVAlignment {
		Bottom = 0,
		Middle = 1,
		Top = 2
	}

	public enum AGSTextSymbolHAlignment {
		Left = 0,
		Center = 1,
		Right = 2
	}

	public enum AGSSimpleMarkerSymbolStyle {
		Circle = 0,
		Cross = 1,
		Diamond = 2,
		Square = 3,
		X = 4
	}

	public enum AGSInterpolation {
		Bilinear = 0,
		CubicConvolution = 1,
		Majority = 2,
		NearestNeighbor = 3
	}

	public enum AGSGeometryRelation {
		Cross = 0,
		Disjoint = 1,
		In = 2,
		InteriorIntersection = 3,
		Intersection = 4,
		LineCoincidence = 5,
		LineTouch = 6,
		Overlap = 7,
		PointTouch = 8,
		Touch = 9,
		Within = 10,
		Relation = 11
	}

	public enum AGSGeometryType {
		Undefined = -1,
		Point = 0,
		Polyline = 1,
		Polygon = 2,
		Multipoint = 3,
		Envelope = 4
	}

	public enum AGSRasterFunctionType {
		Aspect = 0,
		Colormap = 1,
		Hillshade = 2,
		NDVI = 3,
		ShadedRelief = 4,
		Slope = 5,
		Statistics = 6,
		Stretch = 7
	}

	public enum AGSFieldType {
		Integer = 0,
		SmallInteger = 1,
		Double = 2,
		Single = 3,
		String = 4,
		Date = 5,
		Geometry = 6,
		OID = 7,
		Blob = 8,
		GlobalID = 9,
		Raster = 10,
		GUID = 11,
		XML = 12
	}

	public enum AGSTimeIntervalUnits {
		Milliseconds = 0,
		Seconds = 1,
		Minutes = 2,
		Hours = 3,
		Days = 4,
		Weeks = 5,
		Months = 6,
		Years = 7,
		Decades = 8,
		Centuries = 9,
		Unknown = 10
	}

	public enum AGSSpatialRelationship {
		Intersects = 0,
		Contains = 1,
		Crosses = 2,
		EnvelopeIntersects = 3,
		IndexIntersects = 4,
		Overlaps = 5,
		Touches = 6,
		Within = 7,
		Relation = 8
	}

	public enum AGSUnits {
		Centimeters = 0,
		DecimalDegrees = 1,
		Decimeters = 2,
		Feet = 3,
		Inches = 4,
		Kilometers = 5,
		Meters = 6,
		Miles = 7,
		Millimeters = 8,
		NauticalMiles = 9,
		Points = 10,
		Unknown = 11,
		Yards = 12
	}

	public enum AGSAreaUnits {
		SquareInches = 0,
		SquareFeet = 1,
		SquareYards = 2,
		Acres = 3,
		SquareMiles = 4,
		SquareMillimeters = 5,
		SquareCentimeters = 6,
		SquareDecimeters = 7,
		SquareMeters = 8,
		Ares = 9,
		Hectares = 10,
		SquareKilometers = 11
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
		50KilometerLength = 109030,
		150KilometerLength = 109031,
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
		Bevelled = 1,
		Rounded = 2,
		Square = 3
	}

	public enum AGSNATimeOfDayUse {
		AsStartTime = 0,
		AsEndTime = 1
	}

	public enum AGSNADirectionsOutputType {
		Standard = 0,
		Complete = 1,
		CompleteNoEvents = 2,
		InstructionsOnly = 3,
		SummaryOnly = 4
	}

	public enum AGSNAOutputLine {
		None = 0,
		Straight = 1,
		TrueShape = 2,
		TrueShapeWithMeasure = 3
	}

	public enum AGSNAUTurn {
		AllowBacktrack = 0,
		AtDeadEndsOnly = 1,
		NoBacktrack = 2,
		AtDeadEndsAndIntersections = 3
	}

	public enum AGSNAUnit {
		Centimeters = 0,
		Days = 1,
		DecimalDegrees = 2,
		Decimeters = 3,
		Feet = 4,
		Hours = 5,
		Inches = 6,
		Kilometers = 7,
		Meters = 8,
		Miles = 9,
		Millimeters = 10,
		Minutes = 11,
		NauticalMiles = 12,
		Points = 13,
		Seconds = 14,
		Unknown = 15,
		Yards = 16
	}

	public enum AGSNALayerType {
		Route = 0,
		ServiceArea = 1,
		ClosestFacility = 2
	}

	public enum AGSNATravelDirection {
		FromFacility = 0,
		ToFacility = 1
	}

	public enum AGSNADirectionsManeuver {
		Unknown = 0,
		Stop = 1,
		Straight = 2,
		BearLeft = 3,
		BearRight = 4,
		TurnLeft = 5,
		TurnRight = 6,
		SharpLeft = 7,
		SharpRight = 8,
		UTurn = 9,
		Ferry = 10,
		Roundabout = 11,
		HighwayMerge = 12,
		HighwayExit = 13,
		HighwayChange = 14,
		ForkCenter = 15,
		ForkLeft = 16,
		ForkRight = 17,
		Depart = 18,
		TripItem = 19,
		EndOfFerry = 20,
		RampRight = 21,
		RampLeft = 22,
		TurnLeftRight = 23,
		TurnRightLeft = 24,
		TurnRightRight = 25,
		TurnLeftLeft = 26,
		PedestrianRamp = 27,
		Elevator = 28,
		Escalator = 29,
		Stairs = 30,
		DoorPassage = 31
	}

	public enum AGSNADirectionsString {
		General = 0,
		Depart = 1,
		Arrive = 2,
		Length = 3,
		Time = 4,
		Summary = 5,
		TimeWindow = 6,
		ViolationTime = 7,
		WaitTime = 8,
		ServiceTime = 9,
		EstimatedArrivalTime = 10,
		CumulativeLength = 11,
		StreetName = 12,
		AltName = 13,
		Branch = 14,
		Toward = 15,
		CrossStreet = 16,
		Exit = 17
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
		None = 1,
		Simplified = 2
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
		MapDocument = 1,
		ExplorerMap = 2,
		GlobeDocument = 3,
		SceneDocument = 4,
		PublishedMap = 5,
		MapPackage = 6,
		GeoprocessingPackage = 7,
		LocatorPackage = 8,
		TilePackage = 9,
		WindowsMobilePackage = 10,
		DesktopApplicationTemplate = 11,
		MapTemplate = 12,
		CodeSample = 13,
		GeoprocessingSample = 14,
		Layer = 15,
		LayerPackage = 16,
		ExplorerLayer = 17,
		DesktopAddIn = 18,
		ExplorerAddIn = 19,
		MapService = 20,
		GeocodingService = 21,
		NetworkAnalysisService = 22,
		GlobeService = 23,
		GeoprocessingService = 24,
		GeodataService = 25,
		ImageService = 26,
		GeometryService = 27,
		FeatureService = 28,
		KML = 29,
		WMS = 30,
		WMTS = 31,
		WebMap = 32,
		WebMappingApplication = 33,
		MobileApplication = 34,
		CodeAttachment = 35,
		FeaturedItems = 36,
		FeatureCollection = 37,
		FeatureCollectionTemplate = 38,
		SymbolSet = 39,
		ColorSet = 40,
		CollectionDefinition = 41,
		OperationView = 42,
		OperationsDashboardAddin = 43,
		CityEngineWebScene = 44,
		WorkflowManagerPackage = 45,
		ArcPadPackage = 46,
		Shapefile = 47,
		CSV = 48,
		ServiceDefinition = 49
	}

	public enum AGSPortalAccess {
		Private = 0,
		Shared = 1,
		Organization = 2,
		Public = 3
	}

	public enum AGSPortalQuerySortOrder {
		Ascending = 0,
		Descending = 1
	}

	public enum AGSPortalMode {
		SingleTenant = 0,
		MultiTenant = 1
	}

	public enum AGSPortalUserRole {
		None = 0,
		User = 1,
		Publisher = 2,
		Admin = 3
	}

	public enum AGSWMTSServiceMode {
		RESTful = 0,
		KVP = 1
	}

	public enum AGSImageFormat {
		Unknown = -1,
		PNG32 = 0,
		PNG24 = 1,
		PNG8 = 2,
		PNG = 3,
		JPG = 4,
		GIF = 5,
		BMP = 6,
		TIFF = 7,
		JPGPNG = 8,
		JPEG = 9
	}

	public enum AGSPopupsContainerStyle {
		Default = 0,
		Black = 1,
		CustomColor = 2
	}

	public enum AGSPopupsContainerEditingStyle {
		GeometryTool = 0,
		GeometryInline = 1
	}

	public enum AGSPopupsContainerPagingStyle {
		PageControl = 0,
		Toolbar = 1
	}

	public enum AGSQueryStatisticsType {
		Count = 0,
		Sum = 1,
		Min = 2,
		Max = 3,
		Avg = 4,
		StdDev = 5,
		Var = 6
	}

	public enum AGSMPSymbolDictionaryType : uint {
		Mil2525C = 0,
		App6B = 1,
		Simple = 2
	}

	public enum AGSFeatureLayerMode {
		Snapshot = 0,
		OnDemand = 1,
		Selection = 2
	}

	public enum AGSFeatureLayerSelectionMethod : uint {
		Add = 0,
		New = 1,
		Subtract = 2
	}

	public enum AGSGPAsyncOperationType {
		Submit = 0,
		CheckStatus = 1,
		QueryResultData = 2,
		QueryResultImage = 3,
		QueryResultImageLayer = 4,
		Cancel = 5
	}

	public enum AGSGPMessageType {
		Informative = 0,
		ProcessDefinition = 1,
		Start = 2,
		Stop = 3,
		Warning = 4,
		Error = 5,
		Empty = 6,
		Abort = 7
	}

	public enum AGSGPParameterType {
		Boolean = 0,
		Double = 1,
		Long = 2,
		String = 3,
		LinearUnit = 4,
		FeatureRecordSetLayer = 5,
		RecordSet = 6,
		DataFile = 7,
		Date = 8,
		RasterData = 9,
		RasterDataLayer = 10,
		MultiValue = 11
	}

	public enum AGSIdentifyParametersLayerOption {
		Top = 0,
		Visible = 1,
		All = 2
	}

	public enum AGSLabelPlacement {
		PointAboveCenter = 0,
		PointBelowCenter = 1,
		PointCenterCenter = 2,
		PointAboveLeft = 3,
		PointBelowLeft = 4,
		PointCenterLeft = 5,
		PointAboveRight = 6,
		PointBelowRight = 7,
		PointCenterRight = 8,
		LineAboveAfter = 9,
		LineAboveStart = 10,
		LineBelowAfter = 11,
		LineBelowStart = 12,
		LineCenterAfter = 13,
		LineCenterStart = 14,
		LineAboveAlong = 15,
		LineAboveEnd = 16,
		LineBelowAlong = 17,
		LineBelowEnd = 18,
		LineCenterAlong = 19,
		LineCenterEnd = 20,
		LineAboveBefore = 21,
		LineBelowBefore = 22,
		LineCenterBefore = 23,
		PolygonAlwaysHorizontal = 24
	}

	public enum AGSMapUpdateType {
		SpatialExtent = 0,
		TimeExtent = 1,
		LayerAdded = 2,
		LayerRemoved = 3
	}

	public enum AGSLocationDisplayAutoPanMode {
		Off = 0,
		Default = 1,
		Navigation = 2,
		CompassNavigation = 3
	}

	public enum AGSMosaicMethod {
		None = 0,
		Center = 1,
		Nadir = 2,
		Viewpoint = 3,
		Attribute = 4,
		LockRaster = 5,
		Northwest = 6,
		Seamline = 7
	}

	public enum AGSMosaicOperationType : uint {
		First = 0,
		Last = 1,
		Min = 2,
		Max = 3,
		Mean = 4,
		Blend = 5
	}

	public enum AGSPopupFieldInfoDateFormat {
		ShortDate = 0,
		LongMonthDayYear = 1,
		ShortMonthYear = 2,
		DayShortMonthYear = 3,
		LongDate = 4,
		ShortDateShortTime = 5,
		ShortDateShortTime24 = 6,
		LongMonthYear = 7,
		Year = 8,
		ShortDateLongTime = 9,
		ShortDateLongTime24 = 10
	}

	public enum AGSPopupMediaInfoType {
		Image = 0,
		LineChart = 1,
		BarChart = 2,
		PieChart = 3,
		ColumnChart = 4
	}

	public enum AGSPopupViewType {
		Container = 0,
		UIImagePicker = 1,
		FullMedia = 2,
		Web = 3,
		Attachments = 4,
		Movie = 5,
		Attribute = 6
	}
}