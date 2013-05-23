using System;

using MonoMac.Foundation;

namespace MonoTouch.ArcGIS {

	public partial interface AGSAddressCandidate {

		[Export ("addressString")]
		int AddressString { get; }

		[Export ("address")]
		int Address { get; }

		[Export ("attributes")]
		int Attributes { get; }

		[Export ("location")]
		AGSPoint Location { get; }

		[Export ("score")]
		double Score { get; }
	}

	[Model]
	public partial interface AgsnEtworkActivityDelegate {

		[Export ("networkActivityInProgress")]
		void NetworkActivityInProgress ();

		[Export ("networkActivityEnded")]
		void NetworkActivityEnded ();
	}

	public partial interface AgsaReasAndLengthsParameters {

		[Export ("polygons")]
		int Polygons { get; set; }

		[Export ("lengthUnit")]
		int LengthUnit { get; set; }

		[Export ("areaUnit")]
		int AreaUnit { get; set; }

		[Export ("areasAndLengthsParameters")]
		NSObject AreasAndLengthsParameters { get; }
	}

	public partial interface AgsaTtachment {

		[Export ("attachmentInfo")]
		AGSAttachmentInfo AttachmentInfo { get; }

		[Export ("filepath")]
		int Filepath { get; }

		[Export ("editState")]
		AGSAttachmentEditState EditState { get; }

		[Export ("editResultError")]
		AGSEditResultError EditResultError { get; }

		[Export ("networkError")]
		int NetworkError { get; }

		[Export ("isDownloading")]
		int IsDownloading { get; }

		[Export ("markForDeletion:")]
		void MarkForDeletion (NSObject del);

		[Export ("existsOnServer")]
		NSObject ExistsOnServer { get; }

		[Export ("isLocal")]
		NSObject IsLocal { get; }

		[Export ("thumbnail")]
		NSObject Thumbnail { get; }

		[Export ("data")]
		NSObject Data { get; }
	}

	public partial interface AgsaTtachmentInfo : AGSCoding {

		[Export ("attachmentId")]
		int AttachmentId { get; }

		[Export ("contentType")]
		int ContentType { get; }

		[Export ("size")]
		int Size { get; }

		[Export ("name")]
		int Name { get; }

		[Export ("isEqualToAttachmentInfo:")]
		NSObject IsEqualToAttachmentInfo (AGSAttachmentInfo other);
	}

	public partial interface AgsaTtachmentManager : AGSFeatureLayerEditingDelegate {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("featureLayer")]
		AGSFeatureLayer FeatureLayer { get; }

		[Export ("featureObjectId")]
		int FeatureObjectId { get; }

		[Export ("downloadAttachmentInfosError")]
		int DownloadAttachmentInfosError { get; }

		[Export ("postingLocalEdits")]
		int PostingLocalEdits { get; }

		[Export ("attachments")]
		int Attachments { get; }

		[Export ("attachmentForId:")]
		AGSAttachment AttachmentForId (NSObject attachmentId);

		[Export ("hasLocalEdits")]
		NSObject HasLocalEdits { get; }

		[Export ("cancelLocalEdits")]
		void CancelLocalEdits ();

		[Export ("addAttachmentAsJpgWithImage:name:")]
		AGSAttachment AddAttachmentAsJpgWithImage (NSObject image, NSObject name);

		[Export ("addAttachmentWithData:name:contentType:")]
		AGSAttachment AddAttachmentWithData (NSObject data, NSObject name, NSObject contentType);

		[Export ("markAttachment:forDeletion:")]
		void MarkAttachment (AGSAttachment attachment, NSObject del);

		[Export ("downloadAttachmentInfos")]
		void DownloadAttachmentInfos ();

		[Export ("downloadAttachmentDataForId:")]
		void DownloadAttachmentDataForId (NSObject attachmentId);

		[Export ("postLocalEditsToServer")]
		void PostLocalEditsToServer ();

		[Export ("cancelPostLocalEditsToServer")]
		void CancelPostLocalEditsToServer ();

		[Export ("cancelDownloadDataForId:")]
		void CancelDownloadDataForId (NSObject attachmentId);

		[Export ("cancelAllDownloadDataOperations")]
		void CancelAllDownloadDataOperations ();

		[Export ("cancelDownloadAttachmentInfos")]
		void CancelDownloadAttachmentInfos ();
	}

	[Model]
	public partial interface AgsaTtachmentManagerDelegate {

		[Export ("attachmentManager:didDownloadAttachmentInfos:")]
		void AttachmentManager (AGSAttachmentManager attachmentManager, NSObject attachmentInfos);

		[Export ("attachmentManager:didDownloadDataForAttachment:")]
		void AttachmentManager (AGSAttachmentManager attachmentManager, AGSAttachment attachment);

		[Export ("attachmentManager:didPostLocalEditsToServer:")]
		void AttachmentManager (AGSAttachmentManager attachmentManager, NSObject attachmentsPosted);
	}

	public partial interface AgsbAse64 {

		[Static, Export ("initialize")]
		void Initialize ();

		[Static, Export ("encode:length:")]
		NSObject Encode (NSObject input, NSObject length);

		[Static, Export ("encode:")]
		NSObject Encode (NSObject rawBytes);

		[Static, Export ("decode:length:")]
		NSObject Decode (string string, NSObject inputLength);

		[Static, Export ("decode:")]
		NSObject Decode (NSObject string);
	}

	public partial interface AgsbIngMapLayer {

		[Export ("spatialReference")]
		AGSSpatialReference SpatialReference { get; }

		[Export ("fullEnvelope")]
		AGSEnvelope FullEnvelope { get; }

		[Export ("tileInfo")]
		AGSTileInfo TileInfo { get; }

		[Export ("appID")]
		int AppId { get; }

		[Export ("style")]
		AGSBingMapLayerStyle Style { get; set; }

		[Export ("locale")]
		int Locale { get; set; }

		[Export ("initWithAppID:style:")]
		IntPtr Constructor (NSObject appID, AGSBingMapLayerStyle style);
	}

	public partial interface AgsbIngMapLayerMetadata {

		[Export ("imageUri")]
		int ImageUri { get; }

		[Export ("subDomains")]
		int SubDomains { get; }

		[Export ("zoomRangeFrom")]
		int ZoomRangeFrom { get; }

		[Export ("zoomRangeTo")]
		int ZoomRangeTo { get; }
	}

	public partial interface AgsbUfferParameters {

		[Export ("bufferSpatialReference")]
		AGSSpatialReference BufferSpatialReference { get; set; }

		[Export ("distances")]
		int Distances { get; set; }

		[Export ("geometries")]
		int Geometries { get; set; }

		[Export ("outSpatialReference")]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("unionResults")]
		int UnionResults { get; set; }

		[Export ("unit")]
		int Unit { get; set; }

		[Export ("bufferParameters")]
		NSObject BufferParameters { get; }
	}

	public partial interface AgscAllout {

		[Export ("mapView")]
		AGSMapView MapView { get; }

		[Export ("mapLocation")]
		AGSPoint MapLocation { get; }

		[Export ("pixelOffset")]
		int PixelOffset { get; }

		[Export ("width")]
		int Width { get; set; }

		[Export ("title")]
		int Title { get; set; }

		[Export ("detail")]
		int Detail { get; set; }

		[Export ("color")]
		int Color { get; set; }

		[Export ("highlight")]
		int Highlight { get; set; }

		[Export ("titleColor")]
		int TitleColor { get; set; }

		[Export ("detailColor")]
		int DetailColor { get; set; }

		[Export ("accessoryButtonHidden")]
		int AccessoryButtonHidden { [Bind ("isAccessoryButtonHidden")] get; set; }

		[Export ("leaderPositionFlags")]
		AGSCalloutLeaderPosition LeaderPositionFlags { get; set; }

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("moveCalloutTo:pixelOffset:animated:")]
		void MoveCalloutTo (AGSPoint mapLocation, NSObject pixelOffset, NSObject animated);

		[Export ("showCalloutAt:pixelOffset:animated:")]
		void ShowCalloutAt (AGSPoint mapLocation, NSObject pixelOffset, NSObject animated);

		[Export ("customView")]
		int CustomView { get; set; }

		[Export ("margin")]
		int Margin { get; set; }

		[Export ("cornerRadius")]
		int CornerRadius { get; set; }

		[Export ("maxWidth")]
		int MaxWidth { get; set; }

		[Export ("image")]
		int Image { get; set; }

		[Export ("autoAdjustWidth")]
		int AutoAdjustWidth { get; set; }

		[Export ("representedObject")]
		NSObject RepresentedObject { get; }

		[Export ("showCalloutAtPoint:forGraphic:animated:")]
		void ShowCalloutAtPoint (AGSPoint mapPoint, AGSGraphic graphic, NSObject animated);

		[Export ("showCalloutForLocationDisplay")]
		void ShowCalloutForLocationDisplay ();

		[Export ("showCalloutAt:pixelOffset:rotateOffsetWithMap:animated:")]
		void ShowCalloutAt (AGSPoint mapLocation, NSObject pixelOffset, NSObject rotateOffsetWithMap, NSObject animated);

		[Export ("moveCalloutTo:pixelOffset:rotateOffsetWithMap:animated:")]
		void MoveCalloutTo (AGSPoint mapLocation, NSObject pixelOffset, NSObject rotateOffsetWithMap, NSObject animated);

		[Export ("dismiss")]
		void Dismiss ();
	}

	[Model]
	public partial interface AgscAlloutDelegate {

		[Export ("didClickAccessoryButtonForCallout:")]
		void DidClickAccessoryButtonForCallout (AGSCallout callout);
	}

	public partial interface AgscAlloutTemplate : AGSInfoTemplateDelegate {

		[Export ("titleTemplate")]
		int TitleTemplate { get; set; }

		[Export ("detailTemplate")]
		int DetailTemplate { get; set; }
	}

	public partial interface AgscLassBreak : AGSCoding {

		[Export ("label")]
		int Label { get; set; }

		[Export ("breakDescription")]
		int BreakDescription { get; set; }

		[Export ("maxValue")]
		double MaxValue { get; set; }

		[Export ("symbol")]
		AGSSymbol Symbol { get; set; }

		[Export ("initWithLabel:description:maxValue:symbol:")]
		IntPtr Constructor (NSObject label, NSObject description, double maxValue, AGSSymbol symbol);

		[Static, Export ("classBreakInfoWithLabel:description:maxValue:symbol:")]
		NSObject ClassBreakInfoWithLabel (NSObject label, NSObject description, double maxValue, AGSSymbol symbol);

		[Export ("compare:")]
		NSObject Compare (AGSClassBreak anotherClassBreak);
	}

	public partial interface AgscLassBreaksRenderer {

		[Export ("field")]
		int Field { get; set; }

		[Export ("classBreaks")]
		int ClassBreaks { get; set; }

		[Export ("minValue")]
		double MinValue { get; set; }

		[Export ("defaultSymbol")]
		AGSSymbol DefaultSymbol { get; set; }
	}

	public partial interface AgscllOcationManagerLocationDisplayDataSource : AGSLocationDisplayDataSource {

		[Export ("locationManager")]
		CLLocationManager LocationManager { get; }
	}

	public partial interface AgscLosestFacilityResult {

		[Export ("directions")]
		AGSDirectionSet Directions { get; }

		[Export ("routeGraphic")]
		AGSGraphic RouteGraphic { get; }

		[Export ("routeName")]
		int RouteName { get; }
	}

	public partial interface AgscLosestFacilityTask {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Static, Export ("closestFacilityTaskWithURL:")]
		NSObject ClosestFacilityTaskWithUrl (NSObject url);

		[Static, Export ("closestFacilityTaskWithURL:credential:")]
		NSObject ClosestFacilityTaskWithUrl (NSObject url, AGSCredential cred);

		[Export ("solveClosestFacilityWithParameters:")]
		NSObject SolveClosestFacilityWithParameters (AGSClosestFacilityTaskParameters closestFacilityParams);

		[Export ("retrieveDefaultClosestFacilityTaskParameters")]
		NSObject RetrieveDefaultClosestFacilityTaskParameters { get; }
	}

	[Model]
	public partial interface AgscLosestFacilityTaskDelegate {

		[Export ("closestFacilityTask:operation:didSolveClosestFacilityWithResult:")]
		void ClosestFacilityTask (AGSClosestFacilityTask closestFacilityTask, NSObject op, AGSClosestFacilityTaskResult closestFacilityTaskResult);

		[Export ("closestFacilityTask:operation:didFailSolveWithError:")]
		void ClosestFacilityTask (AGSClosestFacilityTask closestFacilityTask, NSObject op, NSObject error);

		[Export ("closestFacilityTask:operation:didRetrieveDefaultClosestFacilityTaskParameters:")]
		void ClosestFacilityTask (AGSClosestFacilityTask closestFacilityTask, NSObject op, AGSClosestFacilityTaskParameters closestFacilityParams);

		[Export ("closestFacilityTask:operation:didFailToRetrieveDefaultClosestFacilityTaskParametersWithError:")]
		void ClosestFacilityTask (AGSClosestFacilityTask closestFacilityTask, NSObject op, NSObject error);
	}

	public partial interface AgscLosestFacilityTaskParameters : AGSCoding {

		[Export ("accumulateAttributeNames")]
		int AccumulateAttributeNames { get; set; }

		[Export ("attributeParameterValues")]
		int AttributeParameterValues { get; set; }

		[Export ("defaultCutoffValue")]
		double DefaultCutoffValue { get; set; }

		[Export ("defaultTargetFacilityCount")]
		int DefaultTargetFacilityCount { get; set; }

		[Export ("directionsLanguage")]
		int DirectionsLanguage { get; set; }

		[Export ("directionsLengthUnits")]
		int DirectionsLengthUnits { get; set; }

		[Export ("directionsStyleName")]
		int DirectionsStyleName { get; set; }

		[Export ("directionsTimeAttributeName")]
		int DirectionsTimeAttributeName { get; set; }

		[Export ("impedanceAttributeName")]
		int ImpedanceAttributeName { get; set; }

		[Export ("outputGeometryPrecision")]
		double OutputGeometryPrecision { get; set; }

		[Export ("outputGeometryPrecisionUnits")]
		int OutputGeometryPrecisionUnits { get; set; }

		[Export ("outputLines")]
		int OutputLines { get; set; }

		[Export ("outSpatialReference")]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("restrictionAttributeNames")]
		int RestrictionAttributeNames { get; set; }

		[Export ("uTurns")]
		int UTUrns { get; set; }

		[Export ("returnPointBarriers")]
		int ReturnPointBarriers { get; set; }

		[Export ("returnDirections")]
		int ReturnDirections { get; set; }

		[Export ("returnFacilities")]
		int ReturnFacilities { get; set; }

		[Export ("returnIncidents")]
		int ReturnIncidents { get; set; }

		[Export ("returnPolygonBarriers")]
		int ReturnPolygonBarriers { get; set; }

		[Export ("returnPolylineBarriers")]
		int ReturnPolylineBarriers { get; set; }

		[Export ("returnRouteGraphics")]
		int ReturnRouteGraphics { get; set; }

		[Export ("travelDirection")]
		int TravelDirection { get; set; }

		[Export ("useHierarchy")]
		int UseHierarchy { get; set; }

		[Export ("timeOfDay")]
		int TimeOfDay { get; set; }

		[Export ("timeOfDayUsage")]
		int TimeOfDayUsage { get; set; }

		[Export ("directionsOutputType")]
		int DirectionsOutputType { get; set; }

		[Export ("closestFacilityTaskParameters")]
		NSObject ClosestFacilityTaskParameters { get; }

		[Export ("facilitiesWithFeatures")]
		NSObject FacilitiesWithFeatures { set; }

		[Export ("facilitiesWithLayerDefinition")]
		AGSNALayerDefinition FacilitiesWithLayerDefinition { set; }

		[Export ("incidentsWithFeatures")]
		NSObject IncidentsWithFeatures { set; }

		[Export ("incidentsWithLayerDefinition")]
		AGSNALayerDefinition IncidentsWithLayerDefinition { set; }

		[Export ("pointBarriersWithFeatures")]
		NSObject PointBarriersWithFeatures { set; }

		[Export ("pointBarriersWithLayerDefinition")]
		AGSNALayerDefinition PointBarriersWithLayerDefinition { set; }

		[Export ("polylineBarriersWithFeatures")]
		NSObject PolylineBarriersWithFeatures { set; }

		[Export ("polylineBarriersWithLayerDefinition")]
		AGSNALayerDefinition PolylineBarriersWithLayerDefinition { set; }

		[Export ("polygonBarriersWithFeatures")]
		NSObject PolygonBarriersWithFeatures { set; }

		[Export ("polygonBarriersWithLayerDefinition")]
		AGSNALayerDefinition PolygonBarriersWithLayerDefinition { set; }
	}

	public partial interface AgscLosestFacilityTaskResult : AGSCoding {

		[Export ("closestFacilityResults")]
		int ClosestFacilityResults { get; }

		[Export ("facilities")]
		int Facilities { get; }

		[Export ("incidents")]
		int Incidents { get; }

		[Export ("messages")]
		int Messages { get; }

		[Export ("pointBarriers")]
		int PointBarriers { get; }

		[Export ("polygonBarriers")]
		int PolygonBarriers { get; }

		[Export ("polylineBarriers")]
		int PolylineBarriers { get; }
	}

	public partial interface AgscOdedValue {

		[Export ("name")]
		int Name { get; }

		[Export ("code")]
		NSObject Code { get; }
	}

	public partial interface AgscOdedValueDomain {

		[Export ("codedValues")]
		int CodedValues { get; }
	}

	[Model]
	public partial interface AgscOding {

		[Export ("initWithJSON:")]
		IntPtr Constructor (NSObject json);

		[Export ("decodeWithJSON:")]
		void DecodeWithJson (NSObject json);

		[Export ("encodeToJSON")]
		NSObject EncodeToJson { get; }
	}

	public partial interface AgscOmpositeSymbol {

		[Export ("symbols")]
		int Symbols { get; }

		[Export ("compositeSymbol")]
		NSObject CompositeSymbol { get; }

		[Export ("addSymbol:")]
		void AddSymbol (AGSSymbol symbol);

		[Export ("addSymbols:")]
		void AddSymbols (NSObject symbols);

		[Export ("removeSymbol:")]
		void RemoveSymbol (AGSSymbol symbol);

		[Export ("removeAllSymbols")]
		void RemoveAllSymbols ();
	}

	public partial interface AgscRedential {

		[Export ("username")]
		int Username { get; set; }

		[Export ("password")]
		int Password { get; set; }

		[Export ("tokenUrl")]
		int TokenUrl { get; set; }

		[Export ("authType")]
		AGSAuthenticationType AuthType { get; set; }

		[Export ("referer")]
		int Referer { get; }

		[Export ("token")]
		int Token { get; set; }

		[Export ("sslRequired")]
		int SslRequired { get; }

		[Export ("identity")]
		NSObject Identity { get; }

		[Export ("initWithUser:password:")]
		IntPtr Constructor (NSObject username, NSObject password);

		[Export ("initWithUser:password:authenticationType:")]
		IntPtr Constructor (NSObject username, NSObject password, AGSAuthenticationType authType);

		[Export ("initWithUser:password:authenticationType:tokenUrl:")]
		IntPtr Constructor (NSObject username, NSObject password, AGSAuthenticationType authType, NSObject tokenUrl);

		[Export ("initWithToken:")]
		IntPtr Constructor (NSObject token);

		[Export ("initWithIdentityRef:")]
		IntPtr Constructor (NSObject identityRef);

		[Export ("initWithToken:referer:")]
		IntPtr Constructor (NSObject token, NSObject referer);

		[Static, Export ("getTokenServiceUrl:error:")]
		NSObject GetTokenServiceUrl (NSObject url, NSObject error);

		[Static, Export ("isServiceSecured:error:")]
		AGSAuthenticationType IsServiceSecured (NSObject url, NSObject error);

		[Static, Export ("identitiesForProtectionSpace:")]
		NSObject IdentitiesForProtectionSpace (NSObject protectionSpace);

		[Static, Export ("importCertificateData:password:overwrite:error:")]
		NSObject ImportCertificateData (NSObject data, NSObject password, NSObject overwrite, NSObject error);

		[Static, Export ("removeIdentityFromKeychain:")]
		NSObject RemoveIdentityFromKeychain (NSObject identityRef);

		[Export ("authenticatingHost")]
		NSObject AuthenticatingHost { get; }
	}

	[Model]
	public partial interface AgssEcuredResource {

		[Export ("credential")]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache")]
		AGSCredentialCache CredentialCache { get; set; }
	}

	public partial interface AgscRedentialCache {

		[Export ("shouldAutoCacheCredentials")]
		int ShouldAutoCacheCredentials { get; set; }

		[Export ("removeAllCredentials")]
		void RemoveAllCredentials ();

		[Export ("setCredential:forUrl:")]
		void SetCredential (AGSCredential credential, NSObject url);

		[Export ("credentialForUrl:")]
		AGSCredential CredentialForUrl (NSObject url);

		[Export ("removeCredentialForUrl:")]
		void RemoveCredentialForUrl (NSObject url);

		[Export ("removeCredential:")]
		void RemoveCredential (AGSCredential credential);

		[Export ("defaultCache")]
		AGSCredentialCache DefaultCache { get; }
	}

	public partial interface AgsdEnsifyParameters {

		[Export ("geometries")]
		int Geometries { get; set; }

		[Export ("maxSegmentLength")]
		int MaxSegmentLength { get; set; }

		[Export ("lengthUnit")]
		int LengthUnit { get; set; }

		[Export ("geodesic")]
		int Geodesic { get; set; }

		[Export ("densifyParameters")]
		NSObject DensifyParameters { get; }
	}

	public partial interface AgsdEvice {

		[Export ("currentDevice")]
		AGSDevice CurrentDevice { get; }

		[Export ("systemVersion")]
		NSObject SystemVersion { get; }

		[Export ("machine")]
		NSObject Machine { get; }

		[Export ("machineType")]
		AGSDeviceMachineType MachineType { get; }

		[Export ("isIPad")]
		NSObject IsIPAd { get; }

		[Export ("isAtLeastiOS4")]
		NSObject IsAtLeastiOS4 { get; }

		[Export ("isAtLeastiOS5")]
		NSObject IsAtLeastiOS5 { get; }

		[Export ("isAtLeastiOS6")]
		NSObject IsAtLeastiOS6 { get; }

		[Export ("isMac")]
		NSObject IsMac { get; }

		[Export ("ppi")]
		int Ppi { get; }
	}

	public partial interface AgsdIrectionGraphic : AGSCoding {

		[Export ("length")]
		double Length { get; }

		[Export ("time")]
		double Time { get; }

		[Export ("text")]
		int Text { get; }

		[Export ("ETA")]
		int Eta { get; }

		[Export ("maneuverType")]
		int ManeuverType { get; }

		[Export ("directionsStrings")]
		int DirectionsStrings { get; }
	}

	public partial interface AgsdIrectionSet : AGSCoding {

		[Export ("graphics")]
		int Graphics { get; }

		[Export ("extent")]
		AGSEnvelope Extent { get; }

		[Export ("mergedGeometry")]
		AGSPolyline MergedGeometry { get; }

		[Export ("routeId")]
		int RouteId { get; }

		[Export ("routeName")]
		int RouteName { get; }

		[Export ("totalDriveTime")]
		double TotalDriveTime { get; }

		[Export ("totalLength")]
		double TotalLength { get; }

		[Export ("totalTime")]
		double TotalTime { get; }
	}

	public partial interface AgsdIstanceParameters {

		[Export ("distanceUnit")]
		int DistanceUnit { get; set; }

		[Export ("geometry1")]
		AGSGeometry Geometry1 { get; set; }

		[Export ("geometry2")]
		AGSGeometry Geometry2 { get; set; }

		[Export ("geodesic")]
		int Geodesic { get; set; }

		[Export ("distanceParameters")]
		NSObject DistanceParameters { get; }
	}

	public partial interface AgsdOmain {

		[Export ("name")]
		int Name { get; }

		[Static, Export ("domainWithJSON:parentField:")]
		NSObject DomainWithJson (NSObject json, AGSField parentField);
	}

	public partial interface AgsdYnamicLayer {

		[Export ("autoRefreshInterval")]
		double AutoRefreshInterval { get; set; }
	}

	[Category, BaseType (typeof (AGSDynamicLayer))]
	public partial interface ForSubclassEyesOnlyAgsdYnamicLayer {

		[Export ("requestImageWithWidth:height:envelope:timeExtent:")]
		void RequestImageWithWidth (NSObject width, NSObject height, AGSEnvelope env, AGSTimeExtent timeExtent);

		[Export ("setImageData:forEnvelope:")]
		void SetImageData (NSObject data, AGSEnvelope env);

		[Export ("queue")]
		int Queue { get; }

		[Export ("wrapAroundSupported")]
		int WrapAroundSupported { get; set; }
	}

	public partial interface AgsdYnamicMapServiceLayer : AGSCoding, AGSSecuredResource {

		[Export ("URL")]
		int Url { get; }

		[Export ("mapServiceInfo")]
		AGSMapServiceInfo MapServiceInfo { get; }

		[Export ("credential")]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache")]
		int CredentialCache { get; set; }

		[Export ("dpi")]
		int Dpi { get; set; }

		[Export ("imageFormat")]
		int ImageFormat { get; set; }

		[Export ("transparent")]
		int Transparent { get; set; }

		[Export ("layerDefinitions")]
		int LayerDefinitions { get; set; }

		[Export ("visibleLayers")]
		int VisibleLayers { get; set; }

		[Export ("layerTimeOptions")]
		int LayerTimeOptions { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSObject url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSObject url, AGSCredential cred);

		[Export ("initWithMapServiceInfo:")]
		IntPtr Constructor (AGSMapServiceInfo info);

		[Static, Export ("dynamicMapServiceLayerWithURL:")]
		NSObject DynamicMapServiceLayerWithUrl (NSObject url);

		[Static, Export ("dynamicMapServiceLayerWithURL:credential:")]
		NSObject DynamicMapServiceLayerWithUrl (NSObject url, AGSCredential cred);

		[Static, Export ("dynamicMapServiceLayerWithMapServiceInfo:")]
		NSObject DynamicMapServiceLayerWithMapServiceInfo (AGSMapServiceInfo info);

		[Export ("initWithJSON:URL:credential:")]
		IntPtr Constructor (NSObject json, NSObject url, AGSCredential cred);

		[Export ("resubmit")]
		void Resubmit ();

		[Export ("resubmitWithURL:credential:")]
		void ResubmitWithUrl (NSObject url, AGSCredential cred);

		[Export ("checkCurrentScaleVisibilityForSubLayer:")]
		NSObject CheckCurrentScaleVisibilityForSubLayer (AGSMapServiceLayerInfo msli);
	}

	public partial interface AgseDitFieldsInfo : AGSCoding {

		[Export ("creationDateField")]
		int CreationDateField { get; }

		[Export ("creatorField")]
		int CreatorField { get; }

		[Export ("editDateField")]
		int EditDateField { get; }

		[Export ("editorField")]
		int EditorField { get; }
	}

	public partial interface AgseDitResult {

		[Export ("objectId")]
		int ObjectId { get; }

		[Export ("globalId")]
		int GlobalId { get; }

		[Export ("success")]
		int Success { get; }

		[Export ("error")]
		AGSEditResultError Error { get; }
	}

	public partial interface AgseDitResultError {

		[Export ("code")]
		int Code { get; }

		[Export ("errorDescription")]
		int ErrorDescription { get; }
	}

	public partial interface AgseNvelope {

		[Export ("xmin")]
		double Xmin { get; }

		[Export ("ymin")]
		double Ymin { get; }

		[Export ("xmax")]
		double Xmax { get; }

		[Export ("ymax")]
		double Ymax { get; }

		[Export ("center")]
		AGSPoint Center { get; }

		[Export ("width")]
		double Width { get; }

		[Export ("height")]
		double Height { get; }

		[Export ("initWithXmin:ymin:xmax:ymax:spatialReference:")]
		IntPtr Constructor (double xmin, double ymin, double xmax, double ymax, NSObject spatialReference);

		[Static, Export ("envelopeWithXmin:ymin:xmax:ymax:spatialReference:")]
		NSObject EnvelopeWithXmin (double xmin, double ymin, double xmax, double ymax, NSObject spatialReference);

		[Export ("containsPoint:")]
		NSObject ContainsPoint (AGSPoint point);

		[Export ("containsEnvelope:")]
		NSObject ContainsEnvelope (AGSEnvelope env);

		[Export ("simpleRepresentation")]
		NSObject SimpleRepresentation { get; }

		[Export ("intersectsWithEnvelope:")]
		NSObject IntersectsWithEnvelope (AGSEnvelope envelope);

		[Export ("intersectionWithEnvelope:")]
		AGSEnvelope IntersectionWithEnvelope (AGSEnvelope envelope);

		[Export ("isEmpty")]
		NSObject IsEmpty { get; }

		[Export ("isEqualToEnvelope:")]
		NSObject IsEqualToEnvelope (AGSEnvelope other);
	}

	[BaseType (typeof (AGSEnvelope))]
	public partial interface AgsmUtableEnvelope {

		[Export ("updateWithXmin:ymin:xmax:ymax:")]
		void UpdateWithXmin (double xmin, double ymin, double xmax, double ymax);

		[Export ("centerAtPoint:")]
		void CenterAtPoint (AGSPoint point);

		[Export ("unionWithEnvelope:")]
		void UnionWithEnvelope (AGSEnvelope envelope);

		[Export ("unionWithPoint:")]
		void UnionWithPoint (AGSPoint point);

		[Export ("expandByFactor:")]
		void ExpandByFactor (double factor);

		[Export ("expandByFactor:withAnchorPoint:")]
		void ExpandByFactor (double factor, AGSPoint anchorPoint);

		[Export ("reaspect:")]
		void Reaspect (NSObject size);

		[Export ("offsetByX:y:")]
		void OffsetByX (double offsetX, double offsetY);

		[Export ("normalize")]
		void Normalize ();

		[Export ("normalizeToEnvelope:")]
		void NormalizeToEnvelope (AGSEnvelope env);

		[Export ("spatialReference")]
		int SpatialReference { get; set; }
	}

	public partial interface AgsfAcilityGraphic : AGSCoding {

		[Export ("name")]
		int Name { get; set; }

		[Export ("initWithPoint:name:")]
		IntPtr Constructor (AGSPoint pt, NSObject name);

		[Static, Export ("graphicWithPoint:name:")]
		NSObject GraphicWithPoint (AGSPoint pt, NSObject name);
	}

	public partial interface AgsfEatureLayer : AGSCoding, AGSInfoTemplateDelegate {

		[Export ("URL")]
		int Url { get; }

		[Export ("mode")]
		AGSFeatureLayerMode Mode { get; }

		[Export ("credential")]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache")]
		int CredentialCache { get; set; }

		[Export ("requestCachePolicy")]
		int RequestCachePolicy { get; set; }

		[Export ("timeoutInterval")]
		int TimeoutInterval { get; set; }

		[Export ("layerId")]
		int LayerId { get; }

		[Export ("serviceLayerName")]
		int ServiceLayerName { get; }

		[Export ("layerDescription")]
		int LayerDescription { get; }

		[Export ("type")]
		int Type { get; }

		[Export ("geometryType")]
		int GeometryType { get; }

		[Export ("displayField")]
		int DisplayField { get; }

		[Export ("fields")]
		int Fields { get; }

		[Export ("objectIdField")]
		int ObjectIdField { get; }

		[Export ("typeIdField")]
		int TypeIdField { get; }

		[Export ("defaultDefinitionExpression")]
		int DefaultDefinitionExpression { get; }

		[Export ("types")]
		int Types { get; }

		[Export ("templates")]
		int Templates { get; }

		[Export ("relationships")]
		int Relationships { get; }

		[Export ("timeInfo")]
		AGSTimeInfo TimeInfo { get; }

		[Export ("attachments")]
		int Attachments { [Bind ("hasAttachments")] get; }

		[Export ("definitionExpression")]
		int DefinitionExpression { get; set; }

		[Export ("editingDelegate")]
		[unmapped: unexposed: Unexposed] EditingDelegate { get; set; }

		[Export ("queryDelegate")]
		[unmapped: unexposed: Unexposed] QueryDelegate { get; set; }

		[Export ("outFields")]
		int OutFields { get; set; }

		[Export ("maxAllowableOffset")]
		double MaxAllowableOffset { get; set; }

		[Export ("queryable")]
		int Queryable { [Bind ("isQueryable")] get; }

		[Export ("infoTemplateDelegate")]
		[unmapped: unexposed: Unexposed] InfoTemplateDelegate { get; set; }

		[Export ("expirationInterval")]
		double ExpirationInterval { get; set; }

		[Export ("autoRefreshOnExpiration")]
		int AutoRefreshOnExpiration { get; set; }

		[Export ("bufferFactor")]
		int BufferFactor { get; set; }

		[Export ("constraintFactor")]
		int ConstraintFactor { get; set; }

		[Export ("version")]
		int Version { get; }

		[Export ("serviceFullEnvelope")]
		int ServiceFullEnvelope { get; }

		[Export ("labelingInfo")]
		int LabelingInfo { get; }

		[Export ("timeDefinition")]
		AGSTimeExtent TimeDefinition { get; set; }

		[Export ("editFieldsInfo")]
		AGSEditFieldsInfo EditFieldsInfo { get; }

		[Export ("canUpdateGeometry")]
		int CanUpdateGeometry { get; }

		[Export ("canCreate")]
		int CanCreate { get; }

		[Export ("canUpdate")]
		int CanUpdate { get; }

		[Export ("canDelete")]
		int CanDelete { get; }

		[Export ("initWithURL:mode:")]
		IntPtr Constructor (NSObject url, AGSFeatureLayerMode mode);

		[Export ("initWithURL:mode:credential:")]
		IntPtr Constructor (NSObject url, AGSFeatureLayerMode mode, AGSCredential cred);

		[Export ("initWithURL:mode:error:")]
		IntPtr Constructor (NSObject url, AGSFeatureLayerMode mode, NSObject error);

		[Export ("initWithURL:mode:credential:error:")]
		IntPtr Constructor (NSObject url, AGSFeatureLayerMode mode, AGSCredential cred, NSObject error);

		[Static, Export ("featureServiceLayerWithURL:mode:")]
		NSObject FeatureServiceLayerWithUrl (NSObject url, AGSFeatureLayerMode mode);

		[Static, Export ("featureServiceLayerWithURL:mode:credential:")]
		NSObject FeatureServiceLayerWithUrl (NSObject url, AGSFeatureLayerMode mode, AGSCredential cred);

		[Export ("initWithLayerDefinitionJSON:featureSetJSON:")]
		IntPtr Constructor (NSObject layerDefinitionJSON, NSObject featureSetJSON);

		[Export ("initWithLayerDefinitionJSON:featureSet:")]
		IntPtr Constructor (NSObject layerDefinitionJSON, AGSFeatureSet featureSet);

		[Export ("queryFeatures:")]
		NSObject QueryFeatures (AGSQuery query);

		[Export ("queryIds:")]
		NSObject QueryIds (AGSQuery query);

		[Export ("queryFeatureCount:")]
		NSObject QueryFeatureCount (AGSQuery query);

		[Export ("queryRelatedFeatures:")]
		NSObject QueryRelatedFeatures (AGSRelationshipQuery query);

		[Export ("selectFeaturesWithQuery:selectionMethod:")]
		NSObject SelectFeaturesWithQuery (AGSQuery query, AGSFeatureLayerSelectionMethod selectionMethod);

		[Export ("selectFeature:withSelectionMethod:")]
		void SelectFeature (AGSGraphic feature, AGSFeatureLayerSelectionMethod selectionMethod);

		[Export ("clearSelection")]
		void ClearSelection ();

		[Export ("lookupFeatureWithObjectId:")]
		AGSGraphic LookupFeatureWithObjectId (NSObject objectId);

		[Export ("refresh")]
		void Refresh ();

		[Export ("objectIdForFeature:")]
		int ObjectIdForFeature (AGSGraphic feature);

		[Export ("resubmit")]
		void Resubmit ();

		[Export ("resubmitWithURL:credential:")]
		void ResubmitWithUrl (NSObject url, AGSCredential cred);

		[Export ("templateForFeature:type:")]
		AGSFeatureTemplate TemplateForFeature (AGSGraphic feature, out AGSFeatureType type);

		[Export ("findFieldWithName:")]
		AGSField FindFieldWithName (NSObject fieldName);

		[Export ("attachmentManagerForFeature:")]
		AGSAttachmentManager AttachmentManagerForFeature (AGSGraphic feature);

		[Export ("clearAttachmentManagers")]
		void ClearAttachmentManagers ();

		[Export ("clearAttachmentManagerForFeatureWithObjectId:")]
		void ClearAttachmentManagerForFeatureWithObjectId (NSObject objectId);

		[Export ("canUpdateFeature:")]
		NSObject CanUpdateFeature (AGSGraphic feature);

		[Export ("canDeleteFeature:")]
		NSObject CanDeleteFeature (AGSGraphic feature);

		[Export ("editSummaryForFeature:")]
		NSObject EditSummaryForFeature (AGSGraphic feature);
	}

	[Model]
	public partial interface AgsfEatureLayerQueryDelegate {

		[Export ("featureLayer:operation:didQueryFeaturesWithFeatureSet:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, AGSFeatureSet featureSet);

		[Export ("featureLayer:operation:didFailQueryFeaturesWithError:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject error);

		[Export ("featureLayer:operation:didQueryObjectIdsWithResults:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject objectIds);

		[Export ("featureLayer:operation:didFailQueryObjectIdsWithError:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject error);

		[Export ("featureLayer:operation:didQueryFeatureCountWithResult:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject count);

		[Export ("featureLayer:operation:didFailQueryFeatureCountWithError:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject error);

		[Export ("featureLayer:operation:didQueryRelatedFeaturesWithResults:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject relatedFeatures);

		[Export ("featureLayer:operation:didFailQueryRelatedFeaturesWithError:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject error);

		[Export ("featureLayer:operation:didSelectFeaturesWithFeatureSet:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, AGSFeatureSet featureSet);

		[Export ("featureLayer:operation:didFailSelectFeaturesWithError:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject error);
	}

	[Category, BaseType (typeof (AGSFeatureLayer))]
	public partial interface EditingAgsfEatureLayer {

		[Export ("featureWithTemplate:")]
		AGSGraphic FeatureWithTemplate (AGSFeatureTemplate featureTemplate);

		[Export ("featureWithType:")]
		AGSGraphic FeatureWithType (AGSFeatureType featureType);

		[Export ("addFeatures:")]
		NSObject AddFeatures (NSObject features);

		[Export ("updateFeatures:")]
		NSObject UpdateFeatures (NSObject features);

		[Export ("deleteFeaturesWithObjectIds:")]
		NSObject DeleteFeaturesWithObjectIds (NSObject objectIds);

		[Export ("deleteFeaturesWithWhereClause:geometry:spatialRelation:")]
		NSObject DeleteFeaturesWithWhereClause (NSObject where, AGSGeometry geometry, NSObject spatialRelation);

		[Export ("applyEditsWithFeaturesToAdd:toUpdate:toDelete:")]
		NSObject ApplyEditsWithFeaturesToAdd (NSObject addFeatures, NSObject updateFeatures, NSObject objectIds);

		[Export ("addAttachment:data:filename:contentType:")]
		NSObject AddAttachment (NSObject objectId, NSObject data, NSObject filename, NSObject contentType);

		[Export ("addAttachment:data:filename:")]
		NSObject AddAttachment (NSObject objectId, NSObject data, NSObject filename);

		[Export ("addAttachment:filepath:contentType:")]
		NSObject AddAttachment (NSObject objectId, NSObject filepath, NSObject contentType);

		[Export ("addAttachment:filepath:")]
		NSObject AddAttachment (NSObject objectId, NSObject filepath);

		[Export ("updateAttachment:data:filename:contentType:attachmentId:")]
		NSObject UpdateAttachment (NSObject objectId, NSObject data, NSObject filename, NSObject contentType, NSObject attachmentId);

		[Export ("updateAttachment:data:filename:attachmentId:")]
		NSObject UpdateAttachment (NSObject objectId, NSObject data, NSObject filename, NSObject attachmentId);

		[Export ("deleteAttachmentsForObjectId:attachmentIds:")]
		NSObject DeleteAttachmentsForObjectId (NSObject objectId, NSObject attachmentIds);

		[Export ("queryAttachmentInfosForObjectId:")]
		NSObject QueryAttachmentInfosForObjectId (NSObject objectId);

		[Export ("retrieveAttachmentForObjectId:attachmentId:")]
		NSObject RetrieveAttachmentForObjectId (NSObject objectId, NSObject attachmentId);
	}

	[Model]
	public partial interface AgsfEatureLayerEditingDelegate {

		[Export ("featureLayer:operation:didFeatureEditsWithResults:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, AGSFeatureLayerEditResults editResults);

		[Export ("featureLayer:operation:didFailFeatureEditsWithError:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject error);

		[Export ("featureLayer:operation:didAttachmentEditsWithResults:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, AGSFeatureLayerAttachmentResults attachmentResults);

		[Export ("featureLayer:operation:didFailAttachmentEditsWithError:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject error);

		[Export ("featureLayer:operation:didQueryAttachmentInfosWithResults:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject attachmentInfos);

		[Export ("featureLayer:operation:didFailQueryAttachmentInfosWithError:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject error);

		[Export ("featureLayer:operation:didRetrieveAttachmentWithData:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject attachmentData);

		[Export ("featureLayer:operation:didFailRetrieveAttachmentWithError:")]
		void FeatureLayer (AGSFeatureLayer featureLayer, NSObject op, NSObject error);
	}

	public partial interface AgsfEatureLayerAttachmentResults {

		[Export ("addResult")]
		AGSEditResult AddResult { get; }

		[Export ("updateResult")]
		AGSEditResult UpdateResult { get; }

		[Export ("deleteResults")]
		int DeleteResults { get; }
	}

	public partial interface AgsfEatureLayerEditResults {

		[Export ("addResults")]
		int AddResults { get; }

		[Export ("updateResults")]
		int UpdateResults { get; }

		[Export ("deleteResults")]
		int DeleteResults { get; }

		[Export ("deleteWithQuerySuccess")]
		int DeleteWithQuerySuccess { get; }
	}

	public partial interface AgsfEatureSet {

		[Export ("displayFieldName")]
		int DisplayFieldName { get; }

		[Export ("features")]
		int Features { get; set; }

		[Export ("fieldAliases")]
		int FieldAliases { get; }

		[Export ("spatialReference")]
		AGSSpatialReference SpatialReference { get; }

		[Export ("geometryType")]
		int GeometryType { get; }

		[Export ("fields")]
		int Fields { get; }

		[Export ("initWithDisplayFieldName:features:fieldAliases:spatialReference:geometryType:")]
		IntPtr Constructor (NSObject displayFieldName, NSObject features, NSObject fieldAliases, AGSSpatialReference spatialReference, NSObject geometryType);

		[Export ("initWithFeatures:")]
		IntPtr Constructor (NSObject features);

		[Static, Export ("featureSetWithFeatures:")]
		NSObject FeatureSetWithFeatures (NSObject features);
	}

	public partial interface AgsfEatureTemplate {

		[Export ("name")]
		int Name { get; }

		[Export ("featureDescription")]
		int FeatureDescription { get; }

		[Export ("prototype")]
		AGSGraphic Prototype { get; }
	}

	public partial interface AgsfEatureType {

		[Export ("typeId")]
		NSObject TypeId { get; }

		[Export ("name")]
		int Name { get; }

		[Export ("templates")]
		int Templates { get; }

		[Export ("domains")]
		int Domains { get; }
	}

	public partial interface AgsfIeld {

		[Export ("name")]
		int Name { get; }

		[Export ("type")]
		int Type { get; }

		[Export ("alias")]
		int Alias { get; }

		[Export ("domain")]
		AGSDomain Domain { get; }

		[Export ("editable")]
		int Editable { get; }

		[Export ("nullable")]
		int Nullable { get; }

		[Export ("length")]
		int Length { get; }
	}

	public partial interface AgsfIllSymbol {

		[Export ("outline")]
		AGSSimpleLineSymbol Outline { get; set; }
	}

	public partial interface AgsfIndParameters {

		[Export ("contains")]
		int Contains { get; set; }

		[Export ("layerIds")]
		int LayerIds { get; set; }

		[Export ("outSpatialReference")]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("returnGeometry")]
		int ReturnGeometry { get; set; }

		[Export ("searchFields")]
		int SearchFields { get; set; }

		[Export ("searchText")]
		int SearchText { get; set; }

		[Export ("layerDefinitions")]
		int LayerDefinitions { get; set; }

		[Export ("maxAllowableOffset")]
		double MaxAllowableOffset { get; set; }
	}

	public partial interface AgsfIndResult {

		[Export ("displayFieldName")]
		int DisplayFieldName { get; }

		[Export ("feature")]
		AGSGraphic Feature { get; }

		[Export ("foundFieldName")]
		int FoundFieldName { get; }

		[Export ("layerId")]
		int LayerId { get; }

		[Export ("layerName")]
		int LayerName { get; }
	}

	public partial interface AgsfIndTask {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Static, Export ("findTaskWithURL:")]
		NSObject FindTaskWithUrl (NSObject url);

		[Static, Export ("findTaskWithURL:credential:")]
		NSObject FindTaskWithUrl (NSObject url, AGSCredential cred);

		[Export ("executeWithParameters:")]
		NSObject ExecuteWithParameters (AGSFindParameters params);
	}

	[Model]
	public partial interface AgsfIndTaskDelegate {

		[Export ("findTask:operation:didExecuteWithFindResults:")]
		void FindTask (AGSFindTask findTask, NSObject op, NSObject results);

		[Export ("findTask:operation:didFailWithError:")]
		void FindTask (AGSFindTask findTask, NSObject op, NSObject error);
	}

	public partial interface AgsgEneralizeParameters {

		[Export ("maxDeviation")]
		double MaxDeviation { get; set; }

		[Export ("deviationUnit")]
		int DeviationUnit { get; set; }

		[Export ("geometries")]
		int Geometries { get; set; }

		[Export ("generalizeParameters")]
		NSObject GeneralizeParameters { get; }
	}

	public partial interface AgsgEometry : AGSCoding {

		[Export ("spatialReference")]
		AGSSpatialReference SpatialReference { get; }

		[Export ("envelope")]
		AGSEnvelope Envelope { get; }

		[Export ("initWithSpatialReference:")]
		IntPtr Constructor (AGSSpatialReference spatialReference);

		[Export ("initWithJSON:spatialReference:")]
		IntPtr Constructor (NSObject json, AGSSpatialReference sr);

		[Export ("intersectsWithEnvelope:")]
		NSObject IntersectsWithEnvelope (AGSEnvelope envelope);

		[Export ("isEmpty")]
		NSObject IsEmpty { get; }

		[Export ("isValid")]
		NSObject IsValid { get; }

		[Field ("AGSGeometry")]
		Int  { get; }

		[Field ("AGSGeometry")]
		Int  { get; }

		[Field ("AGSGeometryType")]
		Int Type { get; }

		[Field ("NSString")]
		Int NssTring { get; }

		[Field ("AGSGeometryType")]
		Int Type { get; }

		[Field ("BOOL")]
		Int Bool { get; }

		[Field ("AGSGeometry")]
		Int  { get; }

		[Field ("AGSGeometry")]
		Int  { get; }

		[Field ("AGSGeometry")]
		Int  { get; }
	}

	public partial interface AgsgEometryEngine {

		[Export ("projectGeometry:toSpatialReference:")]
		AGSGeometry ProjectGeometry (AGSGeometry geometry, AGSSpatialReference spatialReference);

		[Export ("areaOfGeometry:")]
		double AreaOfGeometry (AGSGeometry geometry);

		[Export ("shapePreservingAreaOfGeometry:inUnit:")]
		double ShapePreservingAreaOfGeometry (AGSGeometry geometry, NSObject areaUnit);

		[Export ("lengthOfGeometry:")]
		double LengthOfGeometry (AGSGeometry geometry);

		[Export ("geodesicLengthOfGeometry:inUnit:")]
		double GeodesicLengthOfGeometry (AGSGeometry geometry, NSObject lengthUnit);

		[Export ("shapePreservingLengthOfGeometry:inUnit:")]
		double ShapePreservingLengthOfGeometry (AGSGeometry geometry, NSObject lengthUnit);

		[Export ("simplifyGeometry:")]
		AGSGeometry SimplifyGeometry (AGSGeometry geometry);

		[Export ("cutGeometry:withCutter:")]
		NSObject CutGeometry (AGSGeometry geometry, AGSPolyline cutter);

		[Export ("bufferGeometry:byDistance:")]
		AGSMutablePolygon BufferGeometry (AGSGeometry geometry, double distance);

		[Export ("bufferGeometries:byDistance:")]
		AGSMutablePolygon BufferGeometries (NSObject geometries, double distance);

		[Export ("unionGeometries:")]
		AGSGeometry UnionGeometries (NSObject geometries);

		[Export ("densifyGeometry:withMaxSegmentLength:")]
		AGSGeometry DensifyGeometry (AGSGeometry geometry, double maxSegmentLength);

		[Export ("geodesicDensifyGeometry:withMaxSegmentLength:inUnit:")]
		AGSGeometry GeodesicDensifyGeometry (AGSGeometry geometry, double maxSegmentLength, NSObject lengthUnit);

		[Export ("intersectionOfGeometry:andGeometry:")]
		AGSGeometry IntersectionOfGeometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("clipGeometry:withEnvelope:")]
		AGSGeometry ClipGeometry (AGSGeometry geometry, AGSEnvelope envelope);

		[Export ("differenceOfGeometry:andGeometry:")]
		AGSGeometry DifferenceOfGeometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("symmetricDifferenceOfGeometry:andGeometry:")]
		AGSGeometry SymmetricDifferenceOfGeometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("distanceFromGeometry:toGeometry:")]
		double DistanceFromGeometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("labelPointForPolygon:")]
		AGSMutablePoint LabelPointForPolygon (AGSPolygon polygon);

		[Export ("offsetGeometry:byDistance:withJointType:bevelRatio:flattenError:")]
		AGSGeometry OffsetGeometry (AGSGeometry geometry, double distance, NSObject joinType, double bevelRatio, double flattenError);

		[Export ("geometry:intersectsGeometry:")]
		NSObject Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("geometry:crossesGeometry:")]
		NSObject Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("geometry:withinGeometry:")]
		NSObject Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("geometry:disjointToGeometry:")]
		NSObject Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("geometry:touchesGeometry:")]
		NSObject Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("geometry:containsGeometry:")]
		NSObject Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("geometry:overlapsGeometry:")]
		NSObject Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("nearestVertexInGeometry:toPoint:")]
		AGSProximityResult NearestVertexInGeometry (AGSGeometry geometry, AGSPoint point);

		[Export ("nearestCoordinateInGeometry:toPoint:")]
		AGSProximityResult NearestCoordinateInGeometry (AGSGeometry geometry, AGSPoint point);

		[Export ("normalizeCentralMeridianOfGeometry:")]
		AGSGeometry NormalizeCentralMeridianOfGeometry (AGSGeometry geometry);

		[Export ("defaultGeometryEngine")]
		AGSGeometryEngine DefaultGeometryEngine { get; }

		[Export ("mgrsFromPoint:numDigits:rounding:addSpaces:")]
		NSObject MgrsFromPoint (AGSPoint pt, NSObject digits, NSObject rounding, NSObject addSpaces);

		[Export ("pointFromMGRS:")]
		AGSPoint PointFromMgrs (NSObject mgrs);
	}

	public partial interface AgsgEometryRelationship {

		[Export ("geometry1")]
		AGSGeometry Geometry1 { get; }

		[Export ("geometry2")]
		AGSGeometry Geometry2 { get; }

		[Export ("type")]
		int Type { get; }
	}

	public partial interface AgsgEometryServiceTask {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Static, Export ("geometryServiceTaskWithURL:")]
		NSObject GeometryServiceTaskWithUrl (NSObject url);

		[Static, Export ("geometryServiceTaskWithURL:credential:")]
		NSObject GeometryServiceTaskWithUrl (NSObject url, AGSCredential cred);

		[Export ("relationWithParameters:")]
		NSObject RelationWithParameters (AGSRelationParameters relationParams);

		[Export ("distanceWithParameters:")]
		NSObject DistanceWithParameters (AGSDistanceParameters distanceParams);

		[Export ("unionGeometries:")]
		NSObject UnionGeometries (NSObject geometries);

		[Export ("reshapeGeometry:withReshaper:")]
		NSObject ReshapeGeometry (AGSGeometry geometry, AGSPolyline reshaper);

		[Export ("convexHullGeometries:")]
		NSObject ConvexHullGeometries (NSObject geometries);
	}

	[Model]
	public partial interface AgsgEometryServiceTaskDelegate {

		[Export ("geometryServiceTask:operation:didReturnBufferedGeometries:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject bufferedGeometries);

		[Export ("geometryServiceTask:operation:didFailBufferWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnProjectedGeometries:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject projectedGeometries);

		[Export ("geometryServiceTask:operation:didFailProjectWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnSimplifiedGeometries:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject simplifiedGeometries);

		[Export ("geometryServiceTask:operation:didFailSimplifyWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnAreas:andLengths:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject areas, NSObject lengths);

		[Export ("geometryServiceTask:operation:didFailAreasAndLengthsWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnLabelPoints:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject labelPoints);

		[Export ("geometryServiceTask:operation:didFailLabelPointsWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnLengths:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject lengths);

		[Export ("geometryServiceTask:operation:didFailLengthsWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnRelations:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject relations);

		[Export ("geometryServiceTask:operation:didFailRelationWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnDistance:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, double distance);

		[Export ("geometryServiceTask:operation:didFailDistanceWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnDensifiedGeometries:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject geometries);

		[Export ("geometryServiceTask:operation:didFailDensifyWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnGeneralizedGeometries:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject geometries);

		[Export ("geometryServiceTask:operation:didFailGeneralizeWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnUnionedGeometry:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, AGSGeometry geometry);

		[Export ("geometryServiceTask:operation:didFailUnionWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnReshapedGeometry:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, AGSGeometry geometry);

		[Export ("geometryServiceTask:operation:didFailReshapeWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnIntersectingGeometries:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject geometries);

		[Export ("geometryServiceTask:operation:didFailIntersectWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnDifferenceGeometries:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject geometries);

		[Export ("geometryServiceTask:operation:didFailDifferenceWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnCutGeometries:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject geometries);

		[Export ("geometryServiceTask:operation:didFailCutWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnAutoCompletedPolygons:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject polygons);

		[Export ("geometryServiceTask:operation:didFailAutoCompleteWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnConvexHullGeometry:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, AGSGeometry geometry);

		[Export ("geometryServiceTask:operation:didFailConvexHullWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnOffsetGeometries:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject geometries);

		[Export ("geometryServiceTask:operation:didFailOffsetWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);

		[Export ("geometryServiceTask:operation:didReturnTrimExtendPolylines:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject polylines);

		[Export ("geometryServiceTask:operation:didFailTrimExtendWithError:")]
		void GeometryServiceTask (AGSGeometryServiceTask geometryServiceTask, NSObject op, NSObject error);
	}

	[Model]
	public partial interface AgsgEoprocessorDelegate {

		[Export ("geoprocessor:operation:didExecuteWithResults:messages:")]
		void Geoprocessor (AGSGeoprocessor geoprocessor, NSObject op, NSObject results, NSObject messages);

		[Export ("geoprocessor:operation:didFailExecuteWithError:")]
		void Geoprocessor (AGSGeoprocessor geoprocessor, NSObject op, NSObject error);

		[Export ("geoprocessor:operation:jobDidSucceed:")]
		void Geoprocessor (AGSGeoprocessor geoprocessor, NSObject op, AGSGPJobInfo jobInfo);

		[Export ("geoprocessor:operation:didQueryWithResult:forJob:")]
		void Geoprocessor (AGSGeoprocessor geoprocessor, NSObject op, AGSGPParameterValue result, NSObject jobId);

		[Export ("geoprocessor:operation:didQueryWithResultImage:forJob:")]
		void Geoprocessor (AGSGeoprocessor geoprocessor, NSObject op, NSObject image, NSObject jobId);

		[Export ("geoprocessor:operation:didQueryWithResultImageLayer:forJob:")]
		void Geoprocessor (AGSGeoprocessor geoprocessor, NSObject op, AGSGPResultLayer lyr, NSObject jobId);

		[Export ("geoprocessor:operation:ofType:didFailWithError:forJob:")]
		void Geoprocessor (AGSGeoprocessor geoprocessor, NSObject op, AGSGPAsyncOperationType opType, NSObject error, NSObject jobId);

		[Export ("geoprocessor:operation:didSubmitJob:")]
		void Geoprocessor (AGSGeoprocessor geoprocessor, NSObject op, AGSGPJobInfo jobInfo);

		[Export ("geoprocessor:willCheckJobStatus:")]
		void Geoprocessor (AGSGeoprocessor geoprocessor, AGSGPJobInfo jobInfo);

		[Export ("geoprocessor:operation:didCheckJobStatus:")]
		void Geoprocessor (AGSGeoprocessor geoprocessor, NSObject op, AGSGPJobInfo jobInfo);

		[Export ("geoprocessor:operation:jobDidFail:")]
		void Geoprocessor (AGSGeoprocessor geoprocessor, NSObject op, AGSGPJobInfo jobInfo);

		[Export ("geoprocessor:operation:didCancelJob:")]
		void Geoprocessor (AGSGeoprocessor geoprocessor, NSObject op, AGSGPJobInfo jobInfo);

		[Export ("geoprocessor:operation:didFailToCancelJob:withError:")]
		void Geoprocessor (AGSGeoprocessor geoprocessor, NSObject op, AGSGPJobInfo jobInfo, NSObject error);
	}

	public partial interface AgsgpjObInfo {

		[Export ("jobId")]
		int JobId { get; }

		[Export ("jobStatus")]
		int JobStatus { get; }

		[Export ("messages")]
		int Messages { get; }
	}

	public partial interface AgsgplInearUnit {

		[Export ("units")]
		int Units { get; set; }

		[Export ("distance")]
		double Distance { get; set; }
	}

	public partial interface AgsgpmEssage {

		[Export ("type")]
		AGSGPMessageType Type { get; }

		[Export ("messageDescription")]
		int MessageDescription { get; }
	}

	public partial interface AgsgppArameterValue {

		[Export ("type")]
		AGSGPParameterType Type { get; }

		[Export ("name")]
		int Name { get; }

		[Export ("value")]
		NSObject Value { get; }

		[Export ("initWithName:type:value:")]
		IntPtr Constructor (NSObject name, AGSGPParameterType type, NSObject value);

		[Static, Export ("parameterWithName:type:value:")]
		NSObject ParameterWithName (NSObject name, AGSGPParameterType type, NSObject value);
	}

	public partial interface AgsgprAsterData {

		[Export ("URL")]
		int Url { get; set; }

		[Export ("format")]
		int Format { get; set; }
	}

	public partial interface AgsgprEsultLayer : AGSSecuredResource {

		[Export ("URL")]
		int Url { get; }

		[Export ("credential")]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache")]
		int CredentialCache { get; set; }

		[Export ("dpi")]
		int Dpi { get; set; }

		[Export ("imageFormat")]
		int ImageFormat { get; set; }

		[Export ("transparent")]
		int Transparent { get; set; }

		[Export ("renderNativeResolution")]
		int RenderNativeResolution { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSObject url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSObject url, AGSCredential cred);
	}

	public partial interface AgsgpxlOcationDisplayDataSource {

		[Export ("initWithPath:")]
		IntPtr Constructor (NSObject path);

		[Export ("initWithGPXData:")]
		IntPtr Constructor (NSObject gpxData);

		[Export ("initWithURL:")]
		IntPtr Constructor (NSObject gpxUrl);
	}

	public partial interface AgsgRaphic {

		[Export ("allAttributes")]
		NSObject AllAttributes { get; set; }

		[Export ("hasAttributeForKey:")]
		NSObject HasAttributeForKey (NSObject key);

		[Export ("attributeForKey:")]
		NSObject AttributeForKey (NSObject key);

		[Export ("safeAttributeForKey:")]
		NSObject SafeAttributeForKey (NSObject key);

		[Export ("setAttribute:forKey:")]
		void SetAttribute (NSObject value, NSObject key);

		[Export ("removeAttributeForKey:")]
		void RemoveAttributeForKey (NSObject key);

		[Export ("setAttributeWithString:forKey:")]
		void SetAttributeWithString (NSObject value, NSObject key);

		[Export ("setAttributeWithDouble:forKey:")]
		void SetAttributeWithDouble (double value, NSObject key);

		[Export ("setAttributeWithInt:forKey:")]
		void SetAttributeWithInt (int value, NSObject key);

		[Export ("setAttributeWithUnsignedInt:forKey:")]
		void SetAttributeWithUnsignedInt (NSObject value, NSObject key);

		[Export ("setAttributeWithFloat:forKey:")]
		void SetAttributeWithFloat (float value, NSObject key);

		[Export ("setAttributeWithBool:forKey:")]
		void SetAttributeWithBool (NSObject value, NSObject key);

		[Export ("setAttributeWithDate:forKey:")]
		void SetAttributeWithDate (NSObject value, NSObject key);

		[Export ("setAttributeWithLong:forKey:")]
		void SetAttributeWithLong (int value, NSObject key);

		[Export ("setAttributeWithInteger:forKey:")]
		void SetAttributeWithInteger (NSObject value, NSObject key);

		[Export ("attributeToNullForKey")]
		NSObject AttributeToNullForKey { set; }

		[Export ("attributeAsStringForKey:")]
		NSObject AttributeAsStringForKey (NSObject key);

		[Export ("attributeAsDateForKey:")]
		NSObject AttributeAsDateForKey (NSObject key);

		[Export ("attributeAsDoubleForKey:exists:")]
		double AttributeAsDoubleForKey (NSObject key, NSObject exists);

		[Export ("attributeAsIntForKey:exists:")]
		int AttributeAsIntForKey (NSObject key, NSObject exists);

		[Export ("attributeAsUnsignedIntForKey:exists:")]
		NSObject AttributeAsUnsignedIntForKey (NSObject key, NSObject exists);

		[Export ("attributeAsFloatForKey:exists:")]
		float AttributeAsFloatForKey (NSObject key, NSObject exists);

		[Export ("attributeAsBoolForKey:exists:")]
		NSObject AttributeAsBoolForKey (NSObject key, NSObject exists);

		[Export ("attributeAsLongForKey:exists:")]
		int AttributeAsLongForKey (NSObject key, NSObject exists);

		[Export ("attributeAsIntegerForKey:exists:")]
		NSObject AttributeAsIntegerForKey (NSObject key, NSObject exists);

		[Export ("geometry")]
		AGSGeometry Geometry { get; set; }

		[Export ("symbol")]
		AGSSymbol Symbol { get; set; }

		[Export ("infoTemplateDelegate")]
		[unmapped: unexposed: Unexposed] InfoTemplateDelegate { get; set; }

		[Export ("layer")]
		AGSGraphicsLayer Layer { get; }

		[Export ("visible")]
		int Visible { [Bind ("isVisible")] get; set; }

		[Export ("initWithGeometry:symbol:attributes:infoTemplateDelegate:")]
		IntPtr Constructor (AGSGeometry geometry, AGSSymbol symbol, NSObject attributes, [unmapped: unexposed: Unexposed] infoTemplateDelegate);

		[Static, Export ("graphicWithGeometry:symbol:attributes:infoTemplateDelegate:")]
		NSObject GraphicWithGeometry (AGSGeometry geometry, AGSSymbol symbol, NSObject attributes, [unmapped: unexposed: Unexposed] infoTemplateDelegate);
	}

	public partial interface AgsgRaphicsLayer {

		[Export ("initWithFullEnvelope:")]
		IntPtr Constructor (AGSEnvelope fullEnv);

		[Export ("initWithSpatialReference:")]
		IntPtr Constructor (AGSSpatialReference sr);

		[Export ("graphics")]
		int Graphics { get; }

		[Export ("graphicsCount")]
		int GraphicsCount { get; }

		[Export ("renderer")]
		AGSRenderer Renderer { get; set; }

		[Export ("startTimeField")]
		int StartTimeField { get; set; }

		[Export ("endTimeField")]
		int EndTimeField { get; set; }

		[Export ("timeOffset")]
		double TimeOffset { get; set; }

		[Export ("timeOffsetUnits")]
		int TimeOffsetUnits { get; set; }

		[Export ("graphicsLayer")]
		NSObject GraphicsLayer { get; }

		[Export ("addGraphic:")]
		void AddGraphic (AGSGraphic graphic);

		[Export ("addGraphics:")]
		void AddGraphics (NSObject graphics);

		[Export ("removeGraphic:")]
		void RemoveGraphic (AGSGraphic graphic);

		[Export ("removeAllGraphics")]
		void RemoveAllGraphics ();

		[Export ("removeGraphics:")]
		void RemoveGraphics (NSObject objects);

		[Export ("selectionSymbol")]
		AGSSymbol SelectionSymbol { get; set; }

		[Export ("selectionColor")]
		int SelectionColor { get; set; }

		[Export ("setSelected:forGraphic:")]
		void SetSelected (NSObject selected, AGSGraphic graphic);

		[Export ("isGraphicSelected:")]
		NSObject IsGraphicSelected (AGSGraphic graphic);

		[Export ("clearSelection")]
		void ClearSelection ();

		[Export ("selectedGraphics")]
		NSObject SelectedGraphics { get; }

		[Export ("refresh")]
		void Refresh ();
	}

	public partial interface AgsgRoupLayer {

		[Export ("layers")]
		int Layers { get; }

		[Export ("layerAtIndex:")]
		AGSLayer LayerAtIndex (NSObject index);
	}

	public partial interface AgsiDentifyParameters {

		[Export ("dpi")]
		int Dpi { get; set; }

		[Export ("size")]
		int Size { get; set; }

		[Export ("returnGeometry")]
		int ReturnGeometry { get; set; }

		[Export ("tolerance")]
		int Tolerance { get; set; }

		[Export ("layerOption")]
		AGSIdentifyParametersLayerOption LayerOption { get; set; }

		[Export ("geometry")]
		AGSGeometry Geometry { get; set; }

		[Export ("layerIds")]
		int LayerIds { get; set; }

		[Export ("mapEnvelope")]
		AGSEnvelope MapEnvelope { get; set; }

		[Export ("spatialReference")]
		AGSSpatialReference SpatialReference { get; set; }

		[Export ("layerDefinitions")]
		int LayerDefinitions { get; set; }

		[Export ("maxAllowableOffset")]
		double MaxAllowableOffset { get; set; }

		[Export ("layerTimeOptions")]
		int LayerTimeOptions { get; set; }

		[Export ("timeExtent")]
		AGSTimeExtent TimeExtent { get; set; }

		[Export ("identifyParameters")]
		NSObject IdentifyParameters { get; }
	}

	public partial interface AgsiDentifyResult {

		[Export ("displayFieldName")]
		int DisplayFieldName { get; }

		[Export ("feature")]
		AGSGraphic Feature { get; }

		[Export ("layerId")]
		int LayerId { get; }

		[Export ("layerName")]
		int LayerName { get; }
	}

	public partial interface AgsiDentifyTask {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Static, Export ("identifyTaskWithURL:")]
		NSObject IdentifyTaskWithUrl (NSObject url);

		[Static, Export ("identifyTaskWithURL:credential:")]
		NSObject IdentifyTaskWithUrl (NSObject url, AGSCredential cred);

		[Export ("executeWithParameters:")]
		NSObject ExecuteWithParameters (AGSIdentifyParameters params);
	}

	[Model]
	public partial interface AgsiDentifyTaskDelegate {

		[Export ("identifyTask:operation:didExecuteWithIdentifyResults:")]
		void IdentifyTask (AGSIdentifyTask identifyTask, NSObject op, NSObject results);

		[Export ("identifyTask:operation:didFailWithError:")]
		void IdentifyTask (AGSIdentifyTask identifyTask, NSObject op, NSObject error);
	}

	public partial interface AgsiMageParameters {

		[Export ("bbox")]
		AGSEnvelope Bbox { get; set; }

		[Export ("dpi")]
		int Dpi { get; set; }

		[Export ("format")]
		int Format { get; set; }

		[Export ("height")]
		int Height { get; set; }

		[Export ("imageSpatialReference")]
		AGSSpatialReference ImageSpatialReference { get; set; }

		[Export ("layerIds")]
		int LayerIds { get; set; }

		[Export ("transparent")]
		int Transparent { get; set; }

		[Export ("width")]
		int Width { get; set; }

		[Export ("timeExtent")]
		AGSTimeExtent TimeExtent { get; set; }

		[Export ("layerTimeOptions")]
		int LayerTimeOptions { get; set; }

		[Export ("encodeToJSON")]
		NSObject EncodeToJson { get; }
	}

	public partial interface AgsiMageServiceIdentifyParameters : AGSCoding {

		[Export ("geometry")]
		AGSGeometry Geometry { get; set; }

		[Export ("mosaicRule")]
		AGSMosaicRule MosaicRule { get; set; }

		[Export ("pixelSizeX")]
		double PixelSizeX { get; set; }

		[Export ("pixelSizeY")]
		double PixelSizeY { get; set; }

		[Export ("imageServiceIdentifyParameters")]
		NSObject ImageServiceIdentifyParameters { get; }
	}

	public partial interface AgsiMageServiceIdentifyResult : AGSCoding {

		[Export ("catalogItems")]
		AGSFeatureSet CatalogItems { get; }

		[Export ("catalogItemVisibilities")]
		int CatalogItemVisibilities { get; }

		[Export ("location")]
		AGSPoint Location { get; }

		[Export ("name")]
		int Name { get; }

		[Export ("objectId")]
		int ObjectId { get; }

		[Export ("properties")]
		int Properties { get; }

		[Export ("value")]
		int Value { get; }
	}

	public partial interface AgsiMageServiceIdentifyTask {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("identifyWithParameters:")]
		NSObject IdentifyWithParameters (AGSImageServiceIdentifyParameters identifyParams);
	}

	[Model]
	public partial interface AgsiMageServiceIdentifyDelegate {

		[Export ("imageServiceIdentifyTask:operation:didIdentifyWithResult:")]
		void ImageServiceIdentifyTask (AGSImageServiceIdentifyTask identifyTask, NSObject op, AGSImageServiceIdentifyResult result);

		[Export ("imageServiceIdentifyTask:operation:didFailToIdentifyWithError:")]
		void ImageServiceIdentifyTask (AGSImageServiceIdentifyTask identifyTask, NSObject op, NSObject error);
	}

	public partial interface AgsiMageServiceInfo : AGSCoding {

		[Export ("serviceDescription")]
		int ServiceDescription { get; }

		[Export ("name")]
		int Name { get; }

		[Export ("extent")]
		AGSEnvelope Extent { get; }

		[Export ("pixelSizeX")]
		double PixelSizeX { get; }

		[Export ("pixelSizeY")]
		double PixelSizeY { get; }

		[Export ("bandCount")]
		int BandCount { get; }

		[Export ("pixelType")]
		int PixelType { get; }

		[Export ("minPixelSize")]
		double MinPixelSize { get; }

		[Export ("maxPixelSize")]
		double MaxPixelSize { get; }

		[Export ("copyrightText")]
		int CopyrightText { get; }

		[Export ("serviceDataType")]
		int ServiceDataType { get; }

		[Export ("minValues")]
		int MinValues { get; }

		[Export ("maxValues")]
		int MaxValues { get; }

		[Export ("meanValues")]
		int MeanValues { get; }

		[Export ("stdvValues")]
		int StdvValues { get; }

		[Export ("version")]
		float Version { get; }

		[Export ("timeInfo")]
		AGSTimeInfo TimeInfo { get; }

		[Export ("objectIdField")]
		int ObjectIdField { get; }

		[Export ("fields")]
		int Fields { get; }
	}

	public partial interface AgsiMageServiceLayer {

		[Export ("URL")]
		int Url { get; }

		[Export ("imageServiceInfo")]
		AGSImageServiceInfo ImageServiceInfo { get; }

		[Export ("compressionQuality")]
		int CompressionQuality { get; set; }

		[Export ("bandIds")]
		int BandIds { get; set; }

		[Export ("credential")]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache")]
		int CredentialCache { get; set; }

		[Export ("renderingRule")]
		AGSRasterFunction RenderingRule { get; set; }

		[Export ("noData")]
		int NoData { get; set; }

		[Export ("format")]
		int Format { get; set; }

		[Export ("interpolation")]
		int Interpolation { get; set; }

		[Export ("mosaicRule")]
		AGSMosaicRule MosaicRule { get; set; }

		[Export ("renderNativeResolution")]
		int RenderNativeResolution { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSObject url);

		[Static, Export ("imageServiceLayerWithURL:")]
		NSObject ImageServiceLayerWithUrl (NSObject url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSObject url, AGSCredential cred);

		[Static, Export ("imageServiceLayerWithURL:credential:")]
		NSObject ImageServiceLayerWithUrl (NSObject url, AGSCredential cred);

		[Export ("initWithJSON:URL:credential:")]
		IntPtr Constructor (NSObject json, NSObject url, AGSCredential cred);

		[Export ("resubmit")]
		void Resubmit ();

		[Export ("resubmitWithURL:credential:")]
		void ResubmitWithUrl (NSObject url, AGSCredential cred);
	}

	public partial interface AgsiNcidentGraphic : AGSCoding {

		[Export ("name")]
		int Name { get; set; }

		[Export ("initWithPoint:name:")]
		IntPtr Constructor (AGSPoint pt, NSObject name);

		[Static, Export ("graphicWithPoint:name:")]
		NSObject GraphicWithPoint (AGSPoint pt, NSObject name);
	}

	[Model]
	public partial interface AgsiNfoTemplateDelegate {

		[Export ("titleForGraphic:screenPoint:mapPoint:")]
		NSObject TitleForGraphic (AGSGraphic graphic, NSObject screen, AGSPoint mapPoint);

		[Export ("detailForGraphic:screenPoint:mapPoint:")]
		NSObject DetailForGraphic (AGSGraphic graphic, NSObject screen, AGSPoint mapPoint);

		[Export ("imageForGraphic:screenPoint:mapPoint:")]
		NSObject ImageForGraphic (AGSGraphic graphic, NSObject screen, AGSPoint mapPoint);

		[Export ("customViewForGraphic:screenPoint:mapPoint:")]
		NSObject CustomViewForGraphic (AGSGraphic graphic, NSObject screen, AGSPoint mapPoint);
	}

	public partial interface AgsjsonuTility {

		[Static, Export ("encodeToDictionary:withKey:AGSCodingArray:")]
		void EncodeToDictionary (NSObject json, NSObject key, NSObject items);

		[Static, Export ("decodeFromDictionary:withKey:fromClass:")]
		NSObject DecodeFromDictionary (NSObject json, NSObject key, [unmapped: objcclass: ObjCClass] cls);

		[Static, Export ("getStringFromDictionary:withKey:")]
		NSObject GetStringFromDictionary (NSObject json, NSObject key);
	}

	public partial interface AgslAbelClass {

		[Export ("placement")]
		AGSLabelPlacement Placement { get; }

		[Export ("labelExpression")]
		int LabelExpression { get; }

		[Export ("useCodedValues")]
		int UseCodedValues { get; }

		[Export ("symbol")]
		AGSTextSymbol Symbol { get; }

		[Export ("minScale")]
		int MinScale { get; }

		[Export ("maxScale")]
		int MaxScale { get; }

		[Field ("NSString")]
		Int NssTring { get; }

		[Field ("NSString")]
		Int NssTring { get; }

		[Field ("NSString")]
		Int NssTring { get; }
	}

	public partial interface AgslAyer {

		[Export ("loaded")]
		int Loaded { get; }

		[Export ("error")]
		int Error { get; }

		[Export ("renderNativeResolution")]
		int RenderNativeResolution { get; set; }

		[Export ("opacity")]
		int Opacity { get; set; }

		[Export ("name")]
		int Name { get; set; }

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("spatialReferenceStatusValid")]
		int SpatialReferenceStatusValid { get; set; }

		[Export ("spatialReference")]
		AGSSpatialReference SpatialReference { get; }

		[Export ("fullEnvelope")]
		AGSEnvelope FullEnvelope { get; }

		[Export ("initialEnvelope")]
		AGSEnvelope InitialEnvelope { get; set; }

		[Export ("minScale")]
		double MinScale { get; set; }

		[Export ("maxScale")]
		double MaxScale { get; set; }

		[Export ("refresh")]
		void Refresh ();

		[Export ("timeAware")]
		int TimeAware { [Bind ("isTimeAware")] get; }

		[Export ("visible")]
		int Visible { [Bind ("isVisible")] get; set; }

		[Export ("isInScale")]
		NSObject IsInScale { get; }
	}

	public partial interface AgslAyerDefinition {

		[Export ("layerId")]
		int LayerId { get; set; }

		[Export ("definition")]
		int Definition { get; set; }

		[Export ("init")]
		IntPtr Constructor ();

		[Export ("initWithLayerId:definition:")]
		IntPtr Constructor (NSObject layerId, NSObject definition);

		[Static, Export ("layerDefinitionWithLayerId:definition:")]
		NSObject LayerDefinitionWithLayerId (NSObject layerId, NSObject definition);

		[Static, Export ("encodeToJSON:")]
		NSObject EncodeToJson (NSObject array);

		[Static, Export ("decodeWithJSON:")]
		NSObject DecodeWithJson (NSObject json);
	}

	[Model]
	public partial interface AgslAyerDelegate {

		[Export ("layerDidLoad:")]
		void LayerDidLoad (AGSLayer layer);

		[Export ("layer:didFailToLoadWithError:")]
		void Layer (AGSLayer layer, NSObject error);

		[Export ("layer:didInitializeSpatialReferenceStatus:")]
		void Layer (AGSLayer layer, NSObject srStatusValid);
	}

	public partial interface AgslAyerInfo {

		[Export ("layerId")]
		int LayerId { get; }

		[Export ("name")]
		int Name { get; }

		[Export ("minScale")]
		double MinScale { get; }

		[Export ("maxScale")]
		double MaxScale { get; }

		[Export ("legendImages")]
		int LegendImages { get; }

		[Export ("legendLabels")]
		int LegendLabels { get; }
	}

	public partial interface AgslAyerTimeOptions {

		[Export ("useTime")]
		int UseTime { get; set; }

		[Export ("timeDataCumulative")]
		int TimeDataCumulative { get; set; }

		[Export ("timeOffset")]
		double TimeOffset { get; set; }

		[Export ("timeOffsetUnits")]
		int TimeOffsetUnits { get; set; }

		[Export ("layerId")]
		int LayerId { get; set; }
	}

	public partial interface AgslEngthsParameters {

		[Export ("polylines")]
		int Polylines { get; set; }

		[Export ("geodesic")]
		int Geodesic { get; set; }

		[Export ("lengthUnit")]
		int LengthUnit { get; set; }

		[Export ("initWithPolyline:")]
		IntPtr Constructor (AGSPolyline polyline);

		[Export ("lengthParameters")]
		NSObject LengthParameters { get; }

		[Static, Export ("lengthParametersWithPolyline:")]
		NSObject LengthParametersWithPolyline (AGSPolyline polyline);
	}

	public partial interface AgslOcalTiledLayer {

		[Export ("cachePath")]
		int CachePath { get; }

		[Export ("thumbnail")]
		int Thumbnail { get; }

		[Export ("renderNativeResolution")]
		int RenderNativeResolution { get; set; }

		[Export ("layerInfos")]
		int LayerInfos { get; }

		[Export ("initWithPath:")]
		IntPtr Constructor (NSObject fullPath);

		[Static, Export ("localTiledLayerWithPath:")]
		NSObject LocalTiledLayerWithPath (NSObject fullPath);
	}

	public partial interface AgslOcation {

		[Export ("point")]
		AGSPoint Point { get; set; }

		[Export ("accuracy")]
		double Accuracy { get; set; }

		[Export ("course")]
		double Course { get; set; }

		[Export ("velocity")]
		double Velocity { get; set; }

		[Static, Export ("locationWithCLLocation:")]
		AGSLocation LocationWithCllOcation (NSObject cllocation);
	}

	public partial interface AgslOcationDisplay : AGSLocationDisplayDataSourceDelegate {

		[Export ("dataSource")]
		[unmapped: unexposed: Unexposed] DataSource { get; set; }

		[Export ("location")]
		AGSLocation Location { get; }

		[Export ("dataSourceError")]
		int DataSourceError { get; }

		[Export ("autoPanMode")]
		AGSLocationDisplayAutoPanMode AutoPanMode { get; set; }

		[Export ("wanderExtentFactor")]
		int WanderExtentFactor { get; set; }

		[Export ("infoTemplateDelegate")]
		[unmapped: unexposed: Unexposed] InfoTemplateDelegate { get; set; }

		[Export ("zoomScale")]
		double ZoomScale { get; set; }

		[Export ("dataSourceStarted")]
		int DataSourceStarted { [Bind ("isDataSourceStarted")] get; }

		[Export ("mapLocation")]
		AGSPoint MapLocation { get; }

		[Export ("startDataSource")]
		void StartDataSource ();

		[Export ("stopDataSource")]
		void StopDataSource ();

		[Export ("navigationPointHeightFactor")]
		int NavigationPointHeightFactor { get; set; }

		[Export ("alpha")]
		int Alpha { get; set; }
	}

	[Model]
	public partial interface AgslOcationDisplayInfoTemplateDelegate {

		[Export ("titleForLocationDisplay:screenPoint:")]
		NSObject TitleForLocationDisplay (AGSLocationDisplay ld, NSObject screen);

		[Export ("detailForLocationDisplay:screenPoint:")]
		NSObject DetailForLocationDisplay (AGSLocationDisplay ld, NSObject screen);

		[Export ("imageForLocationDisplay:screenPoint:")]
		NSObject ImageForLocationDisplay (AGSLocationDisplay ld, NSObject screen);

		[Export ("customViewForLocationDisplay:screenPoint:")]
		NSObject CustomViewForLocationDisplay (AGSLocationDisplay ld, NSObject screen);
	}

	[Model]
	public partial interface AgslOcationDisplayDataSource {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("start")]
		void Start ();

		[Export ("stop")]
		void Stop ();

		[Export ("started")]
		int Started { [Bind ("isStarted")] get; }

		[Export ("error")]
		int Error { get; }
	}

	[Model]
	public partial interface AgslOcationDisplayDataSourceDelegate {

		[Export ("locationDisplayDataSource:didUpdateWithLocation:")]
		void LocationDisplayDataSource ([unmapped: unexposed: Unexposed] dataSource, AGSLocation location);

		[Export ("locationDisplayDataSource:didUpdateWithHeading:")]
		void LocationDisplayDataSource ([unmapped: unexposed: Unexposed] dataSource, double heading);

		[Export ("locationDisplayDataSource:didFailWithError:")]
		void LocationDisplayDataSource ([unmapped: unexposed: Unexposed] dataSource, NSObject error);

		[Export ("locationDisplayDataSourceStopped:")]
		void LocationDisplayDataSourceStopped ([unmapped: unexposed: Unexposed] dataSource);

		[Export ("locationDisplayDataSourceStarted:")]
		void LocationDisplayDataSourceStarted ([unmapped: unexposed: Unexposed] dataSource);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AgslOcationsForAddressParameters {

		[Export ("address")]
		NSDictionary Address { get; set; }

		[Export ("sourceCountry")]
		string SourceCountry { get; set; }

		[Export ("searchExtent")]
		AGSEnvelope SearchExtent { get; set; }

		[Export ("outSpatialReference")]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("outFields")]
		NSObject [] OutFields { get; set; }

		[Export ("location")]
		AGSPoint Location { get; set; }

		[Export ("distance")]
		int Distance { get; set; }

		[Export ("encodeToJSON")]
		NSDictionary EncodeToJson { get; }
	}

	public partial interface AgslOcator {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("locator")]
		NSObject Locator { get; }

		[Static, Export ("locatorWithURL:")]
		NSObject LocatorWithUrl (NSObject url);

		[Static, Export ("locatorWithURL:credential:")]
		NSObject LocatorWithUrl (NSObject url, AGSCredential cred);

		[Export ("addressForLocation:maxSearchDistance:")]
		NSObject AddressForLocation (AGSPoint location, double distance);

		[Export ("addressForLocation:maxSearchDistance:outSpatialReference:")]
		NSObject AddressForLocation (AGSPoint location, double distance, NSObject sr);

		[Export ("locationsForAddress:returnFields:")]
		NSObject LocationsForAddress (NSObject address, NSObject outFields);

		[Export ("locationsForAddress:returnFields:outSpatialReference:")]
		NSObject LocationsForAddress (NSObject address, NSObject outFields, NSObject sr);

		[Export ("locationsForAddressWithParameters:")]
		NSObject LocationsForAddressWithParameters (AGSLocationsForAddressParameters params);

		[Export ("findWithParameters:")]
		NSObject FindWithParameters (AGSLocatorFindParameters findParams);
	}

	[Model]
	public partial interface AgslOcatorDelegate {

		[Export ("locator:operation:didFindLocationsForAddress:")]
		void Locator (AGSLocator locator, NSObject op, NSObject candidates);

		[Export ("locator:operation:didFailLocationsForAddress:")]
		void Locator (AGSLocator locator, NSObject op, NSObject error);

		[Export ("locator:operation:didFindAddressForLocation:")]
		void Locator (AGSLocator locator, NSObject op, AGSAddressCandidate candidate);

		[Export ("locator:operation:didFailAddressForLocation:")]
		void Locator (AGSLocator locator, NSObject op, NSObject error);

		[Export ("locator:operation:didFind:")]
		void Locator (AGSLocator locator, NSObject op, NSObject results);

		[Export ("locator:operation:didFailToFindWithError:")]
		void Locator (AGSLocator locator, NSObject op, NSObject error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AgslOcatorFindParameters {

		[Export ("text")]
		string Text { get; set; }

		[Export ("sourceCountry")]
		string SourceCountry { get; set; }

		[Export ("searchExtent")]
		AGSEnvelope SearchExtent { get; set; }

		[Export ("outSpatialReference")]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("outFields")]
		NSObject [] OutFields { get; set; }

		[Export ("maxLocations")]
		uint MaxLocations { get; set; }

		[Export ("location")]
		AGSPoint Location { get; set; }

		[Export ("distance")]
		int Distance { get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AgslOcatorFindResult {

		[Export ("extent")]
		AGSEnvelope Extent { get; }

		[Export ("graphic")]
		AGSGraphic Graphic { get; }

		[Export ("name")]
		string Name { get; }
	}

	public partial interface Agslod {

		[Export ("level")]
		int Level { get; }

		[Export ("resolution")]
		double Resolution { get; }

		[Export ("scale")]
		double Scale { get; }

		[Export ("startTileRow")]
		int StartTileRow { get; set; }

		[Export ("endTileRow")]
		int EndTileRow { get; set; }

		[Export ("startTileColumn")]
		int StartTileColumn { get; set; }

		[Export ("endTileColumn")]
		int EndTileColumn { get; set; }

		[Export ("initWithLevel:resolution:scale:")]
		IntPtr Constructor (NSObject level, double resolution, double scale);
	}

	public partial interface AgsmApServiceInfo : AGSSecuredResource {

		[Export ("URL")]
		int Url { get; }

		[Export ("copyright")]
		int Copyright { get; }

		[Export ("serviceDescription")]
		int ServiceDescription { get; }

		[Export ("version")]
		int Version { get; }

		[Export ("units")]
		int Units { get; }

		[Export ("layerInfos")]
		int LayerInfos { get; }

		[Export ("spatialReference")]
		AGSSpatialReference SpatialReference { get; }

		[Export ("fullEnvelope")]
		AGSEnvelope FullEnvelope { get; }

		[Export ("initialEnvelope")]
		AGSEnvelope InitialEnvelope { get; }

		[Export ("tileInfo")]
		AGSTileInfo TileInfo { get; }

		[Export ("singleFusedMapCache")]
		int SingleFusedMapCache { get; }

		[Export ("credential")]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache")]
		int CredentialCache { get; set; }

		[Export ("timeInfo")]
		AGSTimeInfo TimeInfo { get; }

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("tableInfos")]
		int TableInfos { get; }

		[Export ("minScale")]
		double MinScale { get; }

		[Export ("maxScale")]
		double MaxScale { get; }

		[Export ("initWithURL:error:")]
		IntPtr Constructor (NSObject url, NSObject error);

		[Static, Export ("mapServiceInfoWithURL:error:")]
		NSObject MapServiceInfoWithUrl (NSObject url, NSObject error);

		[Export ("initWithURL:credential:error:")]
		IntPtr Constructor (NSObject url, AGSCredential cred, NSObject error);

		[Static, Export ("mapServiceInfoWithURL:credential:error:")]
		NSObject MapServiceInfoWithUrl (NSObject url, AGSCredential cred, NSObject error);

		[Export ("initWithJSON:URL:credential:")]
		IntPtr Constructor (NSObject json, NSObject url, AGSCredential credential);

		[Export ("retrieveLegendInfo")]
		NSObject RetrieveLegendInfo { get; }
	}

	[Model]
	public partial interface AgsmApServiceInfoDelegate {

		[Export ("mapServiceInfo:operationDidRetrieveLegendInfo:")]
		void MapServiceInfo (AGSMapServiceInfo mapServiceInfo, NSObject op);

		[Export ("mapServiceInfo:operation:didFailToRetrieveLegendInfoWithError:")]
		void MapServiceInfo (AGSMapServiceInfo mapServiceInfo, NSObject op, NSObject error);
	}

	public partial interface AgsmApServiceLayerInfo : AGSCoding {

		[Export ("defaultVisibility")]
		int DefaultVisibility { get; }

		[Export ("parentLayerID")]
		int ParentLayerId { get; }

		[Export ("subLayerIDs")]
		int SubLayerIdS { get; }
	}

	public partial interface AgsmApServiceTableInfo {

		[Export ("tableId")]
		int TableId { get; }

		[Export ("name")]
		int Name { get; }
	}

	[Model]
	public partial interface AgsmApViewLayerDelegate {

		[Export ("mapViewDidLoad:")]
		void MapViewDidLoad (AGSMapView mapView);

		[Export ("mapView:shouldFindGraphicsInLayer:atPoint:mapPoint:")]
		NSObject MapView (AGSMapView mapView, NSObject graphicsLayer, NSObject screen, NSObject mappoint);
	}

	[Model]
	public partial interface AgsmApViewCalloutDelegate {

		[Export ("mapView:shouldShowCalloutForLocationDisplay:")]
		NSObject MapView (AGSMapView mapView, NSObject ld);

		[Export ("mapView:didShowCalloutForLocationDisplay:")]
		void MapView (AGSMapView mapView, NSObject ld);

		[Export ("mapView:shouldShowCalloutForGraphic:")]
		NSObject MapView (AGSMapView mapView, NSObject graphic);

		[Export ("mapView:didShowCalloutForGraphic:")]
		void MapView (AGSMapView mapView, NSObject graphic);

		[Export ("mapViewWillDismissCallout:")]
		void MapViewWillDismissCallout (AGSMapView mapView);

		[Export ("mapViewDidDismissCallout:")]
		void MapViewDidDismissCallout (AGSMapView mapView);
	}

	[Model]
	public partial interface AgsmApViewTouchDelegate {

		[Export ("mapView:shouldProcessClickAtPoint:mapPoint:")]
		NSObject MapView (AGSMapView mapView, NSObject screen, NSObject mappoint);

		[Export ("mapView:didClickAtPoint:mapPoint:graphics:")]
		void MapView (AGSMapView mapView, NSObject screen, NSObject mappoint, NSObject graphics);

		[Export ("mapView:didTapAndHoldAtPoint:mapPoint:graphics:")]
		void MapView (AGSMapView mapView, NSObject screen, NSObject mappoint, NSObject graphics);

		[Export ("mapView:didMoveTapAndHoldAtPoint:mapPoint:graphics:")]
		void MapView (AGSMapView mapView, NSObject screen, NSObject mappoint, NSObject graphics);

		[Export ("mapView:didEndTapAndHoldAtPoint:mapPoint:graphics:")]
		void MapView (AGSMapView mapView, NSObject screen, NSObject mappoint, NSObject graphics);

		[Export ("mapViewDidCancelTapAndHold:")]
		void MapViewDidCancelTapAndHold (AGSMapView mapView);

		[Field ("NSString")]
		Int NssTring { get; }

		[Field ("NSString")]
		Int NssTring { get; }
	}

	public partial interface AgsmApViewBase {

		[Export ("layerDelegate")]
		[unmapped: unexposed: Unexposed] LayerDelegate { get; set; }

		[Export ("touchDelegate")]
		[unmapped: unexposed: Unexposed] TouchDelegate { get; set; }

		[Export ("calloutDelegate")]
		[unmapped: unexposed: Unexposed] CalloutDelegate { get; set; }

		[Export ("mapLayers")]
		int MapLayers { get; }

		[Export ("loaded")]
		int Loaded { get; }

		[Export ("resolution")]
		double Resolution { get; }

		[Export ("mapScale")]
		double MapScale { get; }

		[Export ("spatialReference")]
		AGSSpatialReference SpatialReference { get; }

		[Export ("timeExtent")]
		AGSTimeExtent TimeExtent { get; set; }

		[Export ("showMagnifierOnTapAndHold")]
		int ShowMagnifierOnTapAndHold { get; set; }

		[Export ("allowMagnifierToPanMap")]
		int AllowMagnifierToPanMap { get; set; }

		[Export ("rotationAngle")]
		double RotationAngle { get; set; }

		[Export ("allowRotationByPinching")]
		int AllowRotationByPinching { get; set; }

		[Export ("visibleArea")]
		AGSPolygon VisibleArea { get; }

		[Export ("visibleAreaEnvelope")]
		AGSEnvelope VisibleAreaEnvelope { get; }

		[Export ("mapAnchor")]
		AGSPoint MapAnchor { get; }

		[Export ("maxEnvelope")]
		AGSEnvelope MaxEnvelope { get; set; }

		[Export ("locationDisplay")]
		AGSLocationDisplay LocationDisplay { get; }

		[Export ("callout")]
		AGSCallout Callout { get; }

		[Export ("baseLayer")]
		AGSLayer BaseLayer { get; }

		[Export ("backgroundColor")]
		int BackgroundColor { get; set; }

		[Export ("gridSize")]
		int GridSize { get; set; }

		[Export ("gridLineWidth")]
		int GridLineWidth { get; set; }

		[Export ("gridLineColor")]
		int GridLineColor { get; set; }

		[Export ("interacting")]
		int Interacting { get; }

		[Export ("animating")]
		int Animating { get; }

		[Export ("lastChangeFromInteraction")]
		int LastChangeFromInteraction { get; }

		[Export ("toMapPoint:")]
		AGSPoint ToMapPoint (NSObject point);

		[Export ("toScreenPoint:")]
		NSObject ToScreenPoint (AGSPoint point);

		[Export ("toScreenRect:")]
		NSObject ToScreenRect (AGSEnvelope envelope);

		[Export ("toMapEnvelope:")]
		AGSEnvelope ToMapEnvelope (NSObject rect);

		[Export ("zoomToEnvelope:animated:")]
		void ZoomToEnvelope (AGSEnvelope envelope, NSObject animated);

		[Export ("zoomWithFactor:atAnchorPoint:animated:")]
		void ZoomWithFactor (double factor, NSObject anchorPoint, NSObject animated);

		[Export ("zoomIn:")]
		void ZoomIn (NSObject animated);

		[Export ("zoomOut:")]
		void ZoomOut (NSObject animated);

		[Export ("centerAtPoint:animated:")]
		void CenterAtPoint (AGSPoint point, NSObject animated);

		[Export ("zoomToGeometry:withPadding:animated:")]
		void ZoomToGeometry (AGSGeometry geometry, float padding, NSObject animated);

		[Export ("zoomToResolution:withCenterPoint:animated:")]
		void ZoomToResolution (double res, AGSPoint centerPoint, NSObject animated);

		[Export ("zoomToScale:withCenterPoint:animated:")]
		void ZoomToScale (double scale, AGSPoint centerPoint, NSObject animated);

		[Export ("zoomToResolution:animated:")]
		void ZoomToResolution (double res, NSObject animated);

		[Export ("zoomToScale:animated:")]
		void ZoomToScale (double scale, NSObject animated);

		[Export ("reset")]
		void Reset ();

		[Export ("setRotationAngle:animated:")]
		void SetRotationAngle (double angle, NSObject animated);

		[Export ("setRotationAngle:aroundScreenPoint:animated:")]
		void SetRotationAngle (double angle, NSObject screenPoint, NSObject animated);

		[Export ("setRotationAngle:aroundMapPoint:animated:")]
		void SetRotationAngle (double angle, AGSPoint mapPoint, NSObject animated);

		[Export ("addMapLayer:withName:")]
		void AddMapLayer (AGSLayer mapLayer, NSObject name);

		[Export ("removeMapLayerWithName:")]
		void RemoveMapLayerWithName (NSObject name);

		[Export ("insertMapLayer:withName:atIndex:")]
		void InsertMapLayer (AGSLayer mapLayer, NSObject name, NSObject index);

		[Export ("addMapLayer:")]
		void AddMapLayer (AGSLayer lyr);

		[Export ("insertMapLayer:atIndex:")]
		void InsertMapLayer (AGSLayer lyr, NSObject index);

		[Export ("removeMapLayer:")]
		void RemoveMapLayer (AGSLayer lyr);

		[Export ("mapLayerForName:")]
		AGSLayer MapLayerForName (NSObject name);

		[Export ("enableWrapAround")]
		void EnableWrapAround ();

		[Export ("disableWrapAround")]
		void DisableWrapAround ();

		[Export ("wrapAroundStatus")]
		NSObject WrapAroundStatus { get; }
	}

	public partial interface AgsmArkerSymbol {

		[Export ("angle")]
		double Angle { get; set; }

		[Export ("offset")]
		int Offset { get; set; }

		[Export ("leaderPoint")]
		int LeaderPoint { get; set; }

		[Export ("size")]
		int Size { get; set; }
	}

	public partial interface AgsmOsaicRule {

		[Export ("ascending")]
		int Ascending { get; set; }

		[Export ("lockRasterIds")]
		int LockRasterIds { get; set; }

		[Export ("method")]
		AGSMosaicMethod Method { get; set; }

		[Export ("objectIds")]
		int ObjectIds { get; set; }

		[Export ("operation")]
		AGSMosaicOperationType Operation { get; set; }

		[Export ("sortField")]
		int SortField { get; set; }

		[Export ("sortValue")]
		int SortValue { get; set; }

		[Export ("viewpoint")]
		AGSPoint Viewpoint { get; set; }

		[Export ("where")]
		int Where { get; set; }
	}

	public partial interface AgsmpdIctionaryRenderer {

		[Export ("dictionaryRendererDescription")]
		int DictionaryRendererDescription { get; set; }

		[Export ("dictionaryType")]
		int DictionaryType { get; }

		[Export ("fieldName")]
		int FieldName { get; set; }

		[Export ("labelMaxScale")]
		double LabelMaxScale { get; set; }

		[Export ("labelMinScale")]
		double LabelMinScale { get; set; }

		[Export ("labelsVisible")]
		int LabelsVisible { get; set; }

		[Export ("symbolScaleFactor")]
		double SymbolScaleFactor { get; }
	}

	public partial interface AgsmpmEssage {

		[Export ("messageId")]
		int MessageId { get; set; }

		[Export ("properties")]
		int Properties { get; set; }

		[Export ("initWithMessage:")]
		IntPtr Constructor (AGSMPMessage message);

		[Export ("propertyForKey:")]
		NSObject PropertyForKey (NSObject key);

		[Export ("setProperty:forKey:")]
		void SetProperty (NSObject value, NSObject key);
	}

	public partial interface AgsmpmEssageHelper {

		[Static, Export ("mil2525CRemoveMessageWithId:messageType:")]
		AGSMPMessage Mil2525CREmoveMessageWithId (NSObject messageId, NSObject messageType);

		[Static, Export ("mil2525CUpdateMessageWithId:messageType:controlPoints:properties:")]
		AGSMPMessage Mil2525CUPdateMessageWithId (NSObject messageId, NSObject messageType, NSObject controlPoints, NSObject properties);

		[Static, Export ("mil2525CUpdateMessageWithId:properties:")]
		AGSMPMessage Mil2525CUPdateMessageWithId (NSObject messageId, NSObject properties);

		[Static, Export ("mil2525CUpdateMessageWithId:messageType:controlPoints:properties:spatialReference:")]
		AGSMPMessage Mil2525CUPdateMessageWithId (NSObject messageId, NSObject messageType, NSObject controlPoints, NSObject properties, AGSSpatialReference spatialReference);
	}

	public partial interface AgsmpmEssageProcessor {

		[Export ("defaultMessageSpatialReference")]
		AGSSpatialReference DefaultMessageSpatialReference { get; set; }

		[Export ("dictionaryType")]
		int DictionaryType { get; }

		[Export ("messageTypes")]
		int MessageTypes { get; }

		[Export ("symbolDictionary")]
		AGSMPSymbolDictionary SymbolDictionary { get; }

		[Export ("groupLayer")]
		AGSGroupLayer GroupLayer { get; }

		[Export ("initWithSymbolDictionaryType:groupLayer:")]
		IntPtr Constructor (NSObject type, AGSGroupLayer layer);

		[Export ("initWithSymbolDictionaryType:groupLayer:symbolDictionaryPath:")]
		IntPtr Constructor (NSObject type, AGSGroupLayer layer, NSObject path);

		[Export ("messageFromGraphic:")]
		AGSMPMessage MessageFromGraphic (AGSGraphic graphic);

		[Export ("messageFromId:")]
		AGSMPMessage MessageFromId (NSObject messageId);

		[Export ("processMessage:")]
		NSObject ProcessMessage (AGSMPMessage message);

		[Export ("graphicForId:")]
		AGSGraphic GraphicForId (NSObject messageId);
	}

	public partial interface AgsmpsYmbolDictionary {

		[Export ("filterNames")]
		int FilterNames { get; }

		[Export ("keywords")]
		int Keywords { get; }

		[Export ("initWithSymbolDictionaryType:")]
		IntPtr Constructor (NSObject type);

		[Export ("initWithSymbolDictionaryType:resourcePath:")]
		IntPtr Constructor (NSObject type, NSObject path);

		[Export ("valuesForFilter:")]
		NSObject ValuesForFilter (NSObject filterName);

		[Export ("swatchForSymbol:")]
		NSObject SwatchForSymbol (NSObject symbolName);

		[Export ("keywordsForSymbol:")]
		NSObject KeywordsForSymbol (NSObject symbolName);

		[Export ("namesForQuery:")]
		NSObject NamesForQuery (AGSMPSymbolDictionaryQuery query);

		[Export ("valuesForSymbol:")]
		NSObject ValuesForSymbol (NSObject symbolName);
	}

	public partial interface AgsmpsYmbolDictionaryFilter {

		[Export ("name")]
		int Name { get; set; }

		[Export ("value")]
		int Value { get; set; }

		[Export ("initWithValue:forName:")]
		IntPtr Constructor (NSObject value, NSObject name);

		[Static, Export ("filterWithValue:forName:")]
		NSObject FilterWithValue (NSObject value, NSObject name);
	}

	public partial interface AgsmpsYmbolDictionaryQuery {

		[Export ("filters")]
		int Filters { get; }

		[Export ("keywords")]
		int Keywords { get; }

		[Export ("addFilter:")]
		void AddFilter (AGSMPSymbolDictionaryFilter filter);

		[Export ("addKeyword:")]
		void AddKeyword (NSObject keyword);

		[Export ("removeAll")]
		void RemoveAll ();

		[Export ("removeFilter:")]
		void RemoveFilter (AGSMPSymbolDictionaryFilter filter);

		[Export ("removeKeyword:")]
		void RemoveKeyword (NSObject keyword);
	}

	public partial interface AgsmUltipoint {

		[Export ("numPoints")]
		int NumPoints { get; }

		[Export ("pointAtIndex:")]
		AGSPoint PointAtIndex (NSObject index);

		[Export ("isEqualToMultipoint:")]
		NSObject IsEqualToMultipoint (AGSMultipoint other);
	}

	[BaseType (typeof (AGSMultipoint))]
	public partial interface AgsmUtableMultipoint {

		[Export ("addPoint:")]
		void AddPoint (AGSPoint point);

		[Export ("insertPoint:atIndex:")]
		void InsertPoint (AGSPoint point, NSObject index);

		[Export ("removePointAtIndex:")]
		void RemovePointAtIndex (NSObject index);

		[Export ("updatePoint:atIndex:")]
		void UpdatePoint (AGSPoint point, NSObject index);

		[Export ("spatialReference")]
		int SpatialReference { get; set; }
	}

	public partial interface AgsnadIrectionsString : AGSCoding {

		[Export ("value")]
		int Value { get; }

		[Export ("type")]
		int Type { get; }
	}

	public partial interface AgsnalAyerDefinition : AGSCoding {

		[Export ("geometry")]
		AGSGeometry Geometry { get; set; }

		[Export ("layerName")]
		int LayerName { get; set; }

		[Export ("spatialRelationship")]
		int SpatialRelationship { get; set; }

		[Export ("where")]
		int Where { get; set; }

		[Export ("URL")]
		int Url { get; }

		[Export ("query")]
		AGSQuery Query { get; }

		[Export ("initWithLayerName:geometry:spatialRelationship:where:")]
		IntPtr Constructor (NSObject layerName, AGSGeometry geometry, NSObject spatialRelationship, NSObject where);

		[Export ("initWithLayerName:where:")]
		IntPtr Constructor (NSObject layerName, NSObject where);

		[Export ("initWithURL:query:")]
		IntPtr Constructor (NSObject url, AGSQuery query);
	}

	public partial interface AgsnalAyerInfoBase : AGSCoding {

		[Export ("layerName")]
		int LayerName { get; }

		[Export ("layerType")]
		int LayerType { get; }

		[Export ("impedance")]
		int Impedance { get; }

		[Export ("restrictions")]
		int Restrictions { get; }

		[Export ("snapTolerance")]
		int SnapTolerance { get; }

		[Export ("maxSnapTolerance")]
		int MaxSnapTolerance { get; }

		[Export ("snapToleranceUnits")]
		int SnapToleranceUnits { get; }

		[Export ("ignoreInvalidLocations")]
		int IgnoreInvalidLocations { get; }

		[Export ("uTurns")]
		int UTUrns { get; }

		[Export ("accumulateAttributeNames")]
		int AccumulateAttributeNames { get; }

		[Export ("attributeParameterValues")]
		int AttributeParameterValues { get; }

		[Export ("outputSpatialReference")]
		AGSSpatialReference OutputSpatialReference { get; }

		[Export ("useHierarchy")]
		int UseHierarchy { get; }
	}

	public partial interface AgsnamEssage : AGSCoding {

		[Export ("messageDescription")]
		int MessageDescription { get; }

		[Export ("type")]
		int Type { get; }
	}

	public partial interface AgsoFfsetParameters {

		[Export ("offsetDistance")]
		double OffsetDistance { get; set; }

		[Export ("offsetUnit")]
		int OffsetUnit { get; set; }

		[Export ("offsetHow")]
		int OffsetHow { get; set; }

		[Export ("bevelRatio")]
		double BevelRatio { get; set; }

		[Export ("simplifyResult")]
		int SimplifyResult { get; set; }

		[Export ("geometries")]
		int Geometries { get; set; }

		[Export ("offsetParameters")]
		NSObject OffsetParameters { get; }
	}

	public partial interface AgsoPenStreetMapLayer {

		[Export ("openStreetMapLayer")]
		AGSOpenStreetMapLayer OpenStreetMapLayer { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AgsoUtStatistic {

		[Export ("statisticType")]
		int StatisticType { get; set; }

		[Export ("onStatisticField")]
		string OnStatisticField { get; set; }

		[Export ("outStatisticFieldName")]
		string OutStatisticFieldName { get; set; }
	}

	public partial interface AgspIctureFillSymbol {

		[Export ("size")]
		int Size { get; set; }

		[Export ("image")]
		int Image { get; }

		[Export ("angle")]
		double Angle { get; set; }

		[Export ("offset")]
		int Offset { get; set; }

		[Export ("scale")]
		int Scale { get; set; }

		[Export ("initWithImage:")]
		IntPtr Constructor (NSObject image);

		[Static, Export ("pictureFillSymbolWithImage:")]
		NSObject PictureFillSymbolWithImage (NSObject image);

		[Export ("initWithImageNamed:")]
		IntPtr Constructor (string imageName);

		[Static, Export ("pictureFillSymbolWithImageNamed:")]
		NSObject PictureFillSymbolWithImageNamed (string imageName);

		[Export ("initWithContentsOfFile:")]
		IntPtr Constructor (string imagePath);
	}

	public partial interface AgspIctureMarkerSymbol {

		[Export ("image")]
		int Image { get; set; }

		[Export ("error")]
		int Error { get; }

		[Export ("imageWithData")]
		NSObject ImageWithData { set; }

		[Export ("imageWithName")]
		NSObject ImageWithName { set; }

		[Export ("imageWithContentsOfFile")]
		NSObject ImageWithContentsOfFile { set; }

		[Export ("initWithImage:")]
		IntPtr Constructor (NSObject image);

		[Static, Export ("pictureMarkerSymbolWithImage:")]
		NSObject PictureMarkerSymbolWithImage (NSObject image);

		[Export ("initWithImageNamed:")]
		IntPtr Constructor (NSObject imageName);

		[Export ("initWithContentsOfFile:")]
		IntPtr Constructor (NSObject imagePath);

		[Static, Export ("pictureMarkerSymbolWithImageNamed:")]
		NSObject PictureMarkerSymbolWithImageNamed (NSObject imageName);
	}

	public partial interface AgspOint {

		[Export ("x")]
		double X { get; }

		[Export ("y")]
		double Y { get; }

		[Export ("initWithX:y:spatialReference:")]
		IntPtr Constructor (double x, double y, AGSSpatialReference spatialReference);

		[Static, Export ("pointWithX:y:spatialReference:")]
		NSObject PointWithX (double x, double y, AGSSpatialReference spatialReference);

		[Export ("isEqualToPoint:")]
		NSObject IsEqualToPoint (AGSPoint other);

		[Export ("distanceToPoint:")]
		double DistanceToPoint (AGSPoint other);
	}

	[BaseType (typeof (AGSPoint))]
	public partial interface AgsmUtablePoint {

		[Export ("updateWithX:y:")]
		void UpdateWithX (double x, double y);

		[Export ("offsetByX:y:")]
		void OffsetByX (double xOffset, double yOffset);

		[Export ("normalize")]
		void Normalize ();

		[Export ("normalizeToEnvelope:")]
		void NormalizeToEnvelope (AGSEnvelope env);

		[Export ("spatialReference")]
		AGSSpatialReference SpatialReference { get; set; }
	}

	public partial interface AgspOlygon {

		[Export ("numRings")]
		int NumRings { get; }

		[Export ("numPointsInRing:")]
		NSObject NumPointsInRing (NSObject ring);

		[Export ("numPoints")]
		NSObject NumPoints { get; }

		[Export ("pointOnRing:atIndex:")]
		AGSPoint PointOnRing (NSObject ring, NSObject index);

		[Static, Export ("polygonWithJSON:")]
		NSObject PolygonWithJson (NSObject json);

		[Export ("containsPoint:")]
		NSObject ContainsPoint (AGSPoint point);

		[Export ("isEqualToPolygon:")]
		NSObject IsEqualToPolygon (AGSPolygon other);
	}

	[BaseType (typeof (AGSPolygon))]
	public partial interface AgsmUtablePolygon {

		[Export ("addRingToPolygon")]
		void AddRingToPolygon ();

		[Export ("insertRingAtIndex:")]
		void InsertRingAtIndex (NSObject ringIndex);

		[Export ("addPointToRing:")]
		void AddPointToRing (AGSPoint point);

		[Export ("addPoint:toRing:")]
		void AddPoint (AGSPoint point, NSObject ring);

		[Export ("insertPoint:onRing:atIndex:")]
		void InsertPoint (AGSPoint point, NSObject ring, NSObject index);

		[Export ("removePointOnRing:atIndex:")]
		void RemovePointOnRing (NSObject ring, NSObject index);

		[Export ("updatePoint:onRing:atIndex:")]
		void UpdatePoint (AGSPoint point, NSObject ring, NSObject index);

		[Export ("removeRingAtIndex:")]
		void RemoveRingAtIndex (NSObject index);

		[Export ("closePolygon")]
		void ClosePolygon ();

		[Export ("spatialReference")]
		int SpatialReference { get; set; }
	}

	public partial interface AgspOlyline {

		[Export ("numPaths")]
		int NumPaths { get; }

		[Export ("numPointsInPath:")]
		NSObject NumPointsInPath (NSObject path);

		[Export ("numPoints")]
		NSObject NumPoints { get; }

		[Export ("pointOnPath:atIndex:")]
		AGSPoint PointOnPath (NSObject path, NSObject index);

		[Static, Export ("polylineWithJSON:")]
		NSObject PolylineWithJson (NSObject json);

		[Export ("isEqualToPolyline:")]
		NSObject IsEqualToPolyline (AGSPolyline other);
	}

	[BaseType (typeof (AGSPolyline))]
	public partial interface AgsmUtablePolyline {

		[Export ("addPathToPolyline")]
		void AddPathToPolyline ();

		[Export ("insertPathAtIndex:")]
		void InsertPathAtIndex (NSObject pathIndex);

		[Export ("addPointToPath:")]
		void AddPointToPath (AGSPoint point);

		[Export ("addPoint:toPath:")]
		void AddPoint (AGSPoint point, NSObject path);

		[Export ("insertPoint:onPath:atIndex:")]
		void InsertPoint (AGSPoint point, NSObject path, NSObject index);

		[Export ("removePointOnPath:atIndex:")]
		void RemovePointOnPath (NSObject path, NSObject index);

		[Export ("updatePoint:onPath:atIndex:")]
		void UpdatePoint (AGSPoint point, NSObject pathIndex, NSObject ptIndex);

		[Export ("removePathAtIndex:")]
		void RemovePathAtIndex (NSObject index);

		[Export ("spatialReference")]
		int SpatialReference { get; set; }
	}

	public partial interface AgspOpup {

		[Export ("graphic")]
		AGSGraphic Graphic { get; }

		[Export ("popupInfo")]
		AGSPopupInfo PopupInfo { get; }

		[Export ("featureLayer")]
		AGSFeatureLayer FeatureLayer { get; }

		[Export ("allowEdit")]
		int AllowEdit { get; set; }

		[Export ("allowEditGeometry")]
		int AllowEditGeometry { get; set; }

		[Export ("allowDelete")]
		int AllowDelete { get; set; }

		[Export ("initWithGraphic:popupInfo:")]
		IntPtr Constructor (AGSGraphic graphic, AGSPopupInfo popupInfo);

		[Export ("initWithGraphic:popupInfo:featureLayer:")]
		IntPtr Constructor (AGSGraphic graphic, AGSPopupInfo popupInfo, AGSFeatureLayer featureLayer);

		[Static, Export ("popupWithGraphic:popupInfo:")]
		AGSPopup PopupWithGraphic (AGSGraphic graphic, AGSPopupInfo popupInfo);

		[Static, Export ("popupWithGraphic:popupInfo:featureLayer:")]
		AGSPopup PopupWithGraphic (AGSGraphic graphic, AGSPopupInfo popupInfo, AGSFeatureLayer featureLayer);

		[Export ("attributeForPopupFieldInfo:")]
		NSObject AttributeForPopupFieldInfo (AGSPopupFieldInfo popupFieldInfo);

		[Export ("stringForTemplatedString:")]
		NSObject StringForTemplatedString (NSObject aString);
	}

	public partial interface AgspOpupFieldInfo {

		[Export ("fieldName")]
		int FieldName { get; set; }

		[Export ("label")]
		int Label { get; set; }

		[Export ("tooltip")]
		int Tooltip { get; set; }

		[Export ("numDecimalPlaces")]
		int NumDecimalPlaces { get; set; }

		[Export ("showDigitSeparator")]
		int ShowDigitSeparator { get; set; }

		[Export ("dateFormat")]
		AGSPopupFieldInfoDateFormat DateFormat { get; set; }

		[Export ("editable")]
		int Editable { [Bind ("isEditable")] get; set; }

		[Export ("visible")]
		int Visible { [Bind ("isVisible")] get; set; }
	}

	public partial interface AgspOpupInfo {

		[Export ("title")]
		int Title { get; set; }

		[Export ("customDescription")]
		int CustomDescription { get; set; }

		[Export ("fieldInfos")]
		int FieldInfos { get; set; }

		[Export ("mediaInfos")]
		int MediaInfos { get; set; }

		[Export ("showAttachments")]
		int ShowAttachments { get; set; }

		[Static, Export ("popupInfoForGraphic:")]
		AGSPopupInfo PopupInfoForGraphic (AGSGraphic graphic);
	}

	public partial interface AgspOpupMediaInfo {

		[Export ("caption")]
		int Caption { get; set; }

		[Export ("title")]
		int Title { get; set; }

		[Export ("type")]
		AGSPopupMediaInfoType Type { get; set; }

		[Export ("value")]
		int Value { get; set; }

		[Export ("initWithTitle:caption:type:value:")]
		IntPtr Constructor (NSObject title, NSObject caption, AGSPopupMediaInfoType type, NSObject value);

		[Static, Export ("popupMediaInfoWithTitle:caption:type:value:")]
		AGSPopupMediaInfo PopupMediaInfoWithTitle (NSObject title, NSObject caption, AGSPopupMediaInfoType type, NSObject value);
	}

	[Model]
	public partial interface AgspOpupsContainer {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("popups")]
		int Popups { get; set; }

		[Export ("inEditingMode")]
		int InEditingMode { get; }

		[Export ("style")]
		int Style { get; set; }

		[Export ("styleColor")]
		int StyleColor { get; set; }

		[Export ("currentEditingGeometry")]
		AGSGeometry CurrentEditingGeometry { get; }

		[Export ("currentPopup")]
		AGSPopup CurrentPopup { get; }

		[Export ("editingStyle")]
		int EditingStyle { get; set; }

		[Export ("doneButton")]
		int DoneButton { get; set; }

		[Export ("actionButton")]
		int ActionButton { get; set; }

		[Export ("defaultActionButton")]
		int DefaultActionButton { get; }

		[Export ("defaultDoneButton")]
		int DefaultDoneButton { get; }

		[Export ("modalPresenter")]
		int ModalPresenter { get; set; }

		[Export ("showAdditionalPopups:")]
		void ShowAdditionalPopups (NSObject popupInfos);

		[Export ("startEditingCurrentPopup")]
		void StartEditingCurrentPopup ();

		[Export ("clearAllPopups")]
		void ClearAllPopups ();
	}

	[Model]
	public partial interface AgspOpupsContainerDelegate : NSObject {

		[Export ("popupsContainer:wantsNewMutableGeometryForPopup:")]
		NSObject PopupsContainer ([unmapped: unexposed: Unexposed] popupsContainer, AGSPopup popup);

		[Export ("popupsContainer:readyToEditGraphicGeometry:forPopup:")]
		void PopupsContainer ([unmapped: unexposed: Unexposed] popupsContainer, NSObject geometry, AGSPopup popup);

		[Export ("popupsContainer:didStartEditingGraphicForPopup:")]
		void PopupsContainer ([unmapped: unexposed: Unexposed] popupsContainer, AGSPopup popup);

		[Export ("popupsContainer:didFinishEditingGraphicForPopup:")]
		void PopupsContainer ([unmapped: unexposed: Unexposed] popupsContainer, AGSPopup popup);

		[Export ("popupsContainer:didCancelEditingGraphicForPopup:")]
		void PopupsContainer ([unmapped: unexposed: Unexposed] popupsContainer, AGSPopup popup);

		[Export ("popupsContainer:wantsToDeleteGraphicForPopup:")]
		void PopupsContainer ([unmapped: unexposed: Unexposed] popupsContainer, AGSPopup popup);

		[Export ("popupsContainerDidFinishViewingPopups:")]
		void PopupsContainerDidFinishViewingPopups ([unmapped: unexposed: Unexposed] popupsContainer);

		[Export ("popupsContainer:wantsToShowViewController:ofType:fromViewController:atRect:")]
		void PopupsContainer ([unmapped: unexposed: Unexposed] popupsContainer, UIViewController svc, NSObject viewType, UIViewController fvc, RectangleF rect);

		[Export ("popupsContainer:wantsToHideViewController:ofType:")]
		void PopupsContainer ([unmapped: unexposed: Unexposed] popupsContainer, UIViewController vc, NSObject viewType);

		[Export ("popupsContainer:shouldAutorotateToInterfaceOrientation:forViewController:ofType:")]
		bool PopupsContainer ([unmapped: unexposed: Unexposed] popupsContainer, UIInterfaceOrientation interfaceOrientation, UIViewController vc, NSObject viewType);

		[Export ("popupsContainer:didChangeToCurrentPopup:")]
		void PopupsContainer ([unmapped: unexposed: Unexposed] popupsContainer, AGSPopup popup);

		[Export ("popupsContainer:wantsToPreviewDocumentAtURL:fromViewController:atRect:")]
		void PopupsContainer ([unmapped: unexposed: Unexposed] popupsContainer, NSUrl documentURL, UIViewController fvc, RectangleF rect);

		[Export ("popupsContainer:didChangeFeatureTypeForPopup:")]
		void PopupsContainer ([unmapped: unexposed: Unexposed] popupsContainer, AGSPopup popup);
	}

	[BaseType (typeof (UIViewController))]
	public partial interface AgspOpupsContainerViewController : UIScrollViewDelegate, AGSPopupsContainer, UIActionSheetDelegate {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("popups")]
		NSObject [] Popups { get; set; }

		[Export ("inEditingMode")]
		bool InEditingMode { get; }

		[Export ("style")]
		int Style { get; set; }

		[Export ("styleColor")]
		UIColor StyleColor { get; set; }

		[Export ("currentEditingGeometry")]
		AGSGeometry CurrentEditingGeometry { get; }

		[Export ("currentPopup")]
		AGSPopup CurrentPopup { get; }

		[Export ("editingStyle")]
		int EditingStyle { get; set; }

		[Export ("pagingStyle")]
		int PagingStyle { get; set; }

		[Export ("actionSheetContainerView")]
		UIView ActionSheetContainerView { get; set; }

		[Export ("doneButton")]
		UIBarButtonItem DoneButton { get; set; }

		[Export ("actionButton")]
		UIBarButtonItem ActionButton { get; set; }

		[Export ("defaultActionButton")]
		UIBarButtonItem DefaultActionButton { get; }

		[Export ("defaultDoneButton")]
		UIBarButtonItem DefaultDoneButton { get; }

		[Export ("modalPresenter")]
		UIViewController ModalPresenter { get; set; }

		[Export ("initWithPopups:")]
		IntPtr Constructor (NSObject [] popups);

		[Export ("initWithPopups:usingNavigationControllerStack:")]
		IntPtr Constructor (NSObject [] popups, bool usingNavigationControllerStack);

		[Export ("initWithPopupInfo:graphic:usingNavigationControllerStack:")]
		IntPtr Constructor (AGSPopupInfo popupInfo, AGSGraphic graphic, bool usingNavigationControllerStack);

		[Export ("initWithWebMap:forFeature:usingNavigationControllerStack:")]
		IntPtr Constructor (AGSWebMap webmap, AGSGraphic feature, bool usingNavigationControllerStack);

		[Export ("showAdditionalPopups:")]
		void ShowAdditionalPopups (NSObject [] popupInfos);

		[Export ("startEditingCurrentPopup")]
		void StartEditingCurrentPopup ();

		[Export ("clearAllPopups")]
		void ClearAllPopups ();
	}

	public partial interface AgspOrtal : AGSSecuredResource {

		[Export ("URL")]
		int Url { get; }

		[Export ("credential")]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache")]
		int CredentialCache { get; set; }

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("portalInfo")]
		AGSPortalInfo PortalInfo { get; }

		[Export ("user")]
		AGSPortalUser User { get; }

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSObject url, AGSCredential cred);

		[Export ("resubmit")]
		void Resubmit ();

		[Export ("resubmitWithURL:credential:")]
		void ResubmitWithUrl (NSObject url, AGSCredential cred);

		[Export ("findItemsWithQueryParams:")]
		NSObject FindItemsWithQueryParams (AGSPortalQueryParams queryParams);

		[Export ("findGroupsWithQueryParams:")]
		NSObject FindGroupsWithQueryParams (AGSPortalQueryParams queryParams);
	}

	[Model]
	public partial interface AgspOrtalDelegate {

		[Export ("portalDidLoad:")]
		void PortalDidLoad (AGSPortal portal);

		[Export ("portal:didFailToLoadWithError:")]
		void Portal (AGSPortal portal, NSObject error);

		[Export ("portal:operation:didFindItems:")]
		void Portal (AGSPortal portal, NSObject op, AGSPortalQueryResultSet resultSet);

		[Export ("portal:operation:didFailToFindItemsForQueryParams:withError:")]
		void Portal (AGSPortal portal, NSObject op, AGSPortalQueryParams queryParams, NSObject error);

		[Export ("portal:operation:didFindGroups:")]
		void Portal (AGSPortal portal, NSObject op, AGSPortalQueryResultSet resultSet);

		[Export ("portal:operation:didFailToFindGroupsForQueryParams:withError:")]
		void Portal (AGSPortal portal, NSObject op, AGSPortalQueryParams queryParams, NSObject error);
	}

	public partial interface AgspOrtalFolder {

		[Export ("folderId")]
		int FolderId { get; }

		[Export ("title")]
		int Title { get; }

		[Export ("created")]
		int Created { get; }
	}

	public partial interface AgspOrtalGroup {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("portal")]
		AGSPortal Portal { get; }

		[Export ("groupId")]
		int GroupId { get; }

		[Export ("title")]
		int Title { get; }

		[Export ("owner")]
		int Owner { get; }

		[Export ("groupDescription")]
		int GroupDescription { get; }

		[Export ("snippet")]
		int Snippet { get; }

		[Export ("thumbnailFileName")]
		int ThumbnailFileName { get; }

		[Export ("tags")]
		int Tags { get; }

		[Export ("created")]
		int Created { get; }

		[Export ("modified")]
		int Modified { get; }

		[Export ("access")]
		int Access { get; }

		[Export ("isInvitationOnly")]
		int IsInvitationOnly { get; }

		[Export ("thumbnail")]
		int Thumbnail { get; }

		[Export ("users")]
		int Users { get; }

		[Export ("admins")]
		int Admins { get; }

		[Export ("fetchThumbnail")]
		NSObject FetchThumbnail { get; }

		[Export ("fetchUsers")]
		NSObject FetchUsers { get; }
	}

	[Model]
	public partial interface AgspOrtalGroupDelegate {

		[Export ("portalGroup:operation:didFetchThumbnail:")]
		void PortalGroup (AGSPortalGroup portalGroup, NSObject op, NSObject thumbnail);

		[Export ("portalGroup:operation:didFailToFetchThumbnailWithError:")]
		void PortalGroup (AGSPortalGroup portalGroup, NSObject op, NSObject error);

		[Export ("portalGroup:operation:didFetchUsers:admins:")]
		void PortalGroup (AGSPortalGroup portalGroup, NSObject op, NSObject users, NSObject admins);

		[Export ("portalGroup:operation:didFailToFetchUsersWithError:")]
		void PortalGroup (AGSPortalGroup portalGroup, NSObject op, NSObject error);
	}

	public partial interface AgspOrtalInfo {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("portal")]
		AGSPortal Portal { get; }

		[Export ("organizationId")]
		int OrganizationId { get; }

		[Export ("organizationName")]
		int OrganizationName { get; }

		[Export ("organizationDescription")]
		int OrganizationDescription { get; }

		[Export ("portalName")]
		int PortalName { get; }

		[Export ("featuredItemsGroupQuery")]
		int FeaturedItemsGroupQuery { get; }

		[Export ("canSharePublic")]
		int CanSharePublic { get; }

		[Export ("canSearchPublic")]
		int CanSearchPublic { get; }

		[Export ("organizationThumbnailFileName")]
		int OrganizationThumbnailFileName { get; }

		[Export ("portalThumbnailFileName")]
		int PortalThumbnailFileName { get; }

		[Export ("basemapGalleryGroupQuery")]
		int BasemapGalleryGroupQuery { get; }

		[Export ("defaultBasemap")]
		AGSWebMapBaseMap DefaultBasemap { get; }

		[Export ("defaultExtent")]
		AGSEnvelope DefaultExtent { get; }

		[Export ("homepageFeaturedContentGroupQuery")]
		int HomepageFeaturedContentGroupQuery { get; }

		[Export ("featuredGroupsQueries")]
		int FeaturedGroupsQueries { get; }

		[Export ("portalThumbnail")]
		int PortalThumbnail { get; }

		[Export ("organizationThumbnail")]
		int OrganizationThumbnail { get; }

		[Export ("access")]
		int Access { get; }

		[Export ("portalMode")]
		int PortalMode { get; }

		[Export ("customBaseUrl")]
		int CustomBaseUrl { get; }

		[Export ("urlKey")]
		int UrlKey { get; }

		[Export ("geocodeServiceUrls")]
		int GeocodeServiceUrls { get; }

		[Export ("routeServiceUrl")]
		int RouteServiceUrl { get; }

		[Export ("geometryServiceUrl")]
		int GeometryServiceUrl { get; }

		[Export ("printTaskUrl")]
		int PrintTaskUrl { get; }

		[Export ("fetchPortalThumbnail")]
		NSObject FetchPortalThumbnail { get; }

		[Export ("fetchOrganizationThumbnail")]
		NSObject FetchOrganizationThumbnail { get; }
	}

	[Model]
	public partial interface AgspOrtalInfoDelegate {

		[Export ("portalInfo:operation:didFetchPortalThumbnail:")]
		void PortalInfo (AGSPortalInfo portalInfo, NSObject op, NSObject thumbnail);

		[Export ("portalInfo:operation:didFailToFetchPortalThumbnailWithError:")]
		void PortalInfo (AGSPortalInfo portalInfo, NSObject op, NSObject error);

		[Export ("portalInfo:operation:didFetchOrganizationThumbnail:")]
		void PortalInfo (AGSPortalInfo portalInfo, NSObject op, NSObject thumbnail);

		[Export ("portalInfo:operation:didFailToFetchOrganizationThumbnailWithError:")]
		void PortalInfo (AGSPortalInfo portalInfo, NSObject op, NSObject error);
	}

	public partial interface AgspOrtalItem {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("portal")]
		AGSPortal Portal { get; }

		[Export ("itemId")]
		int ItemId { get; }

		[Export ("owner")]
		int Owner { get; }

		[Export ("title")]
		int Title { get; }

		[Export ("type")]
		int Type { get; }

		[Export ("itemDescription")]
		int ItemDescription { get; }

		[Export ("snippet")]
		int Snippet { get; }

		[Export ("credits")]
		int Credits { get; }

		[Export ("license")]
		int License { get; }

		[Export ("thumbnailFileName")]
		int ThumbnailFileName { get; }

		[Export ("locale")]
		int Locale { get; }

		[Export ("tags")]
		int Tags { get; }

		[Export ("created")]
		int Created { get; }

		[Export ("modified")]
		int Modified { get; }

		[Export ("extent")]
		AGSEnvelope Extent { get; }

		[Export ("spatialReference")]
		AGSSpatialReference SpatialReference { get; }

		[Export ("size")]
		int Size { get; }

		[Export ("numComments")]
		int NumComments { get; }

		[Export ("numRatings")]
		int NumRatings { get; }

		[Export ("avgRating")]
		int AvgRating { get; }

		[Export ("numViews")]
		int NumViews { get; }

		[Export ("access")]
		int Access { get; }

		[Export ("thumbnail")]
		int Thumbnail { get; }

		[Export ("comments")]
		int Comments { get; }

		[Export ("initWithPortal:itemId:")]
		IntPtr Constructor (AGSPortal portal, NSObject itemId);

		[Export ("fetchData")]
		NSObject FetchData { get; }

		[Export ("fetchThumbnail")]
		NSObject FetchThumbnail { get; }

		[Export ("fetchComments")]
		NSObject FetchComments { get; }
	}

	[Model]
	public partial interface AgspOrtalItemDelegate {

		[Export ("portalItemDidLoad:")]
		void PortalItemDidLoad (AGSPortalItem portalItem);

		[Export ("portalItem:didFailToLoadWithError:")]
		void PortalItem (AGSPortalItem portalItem, NSObject error);

		[Export ("portalItem:operation:didFetchData:")]
		void PortalItem (AGSPortalItem portalItem, NSObject op, NSObject data);

		[Export ("portalItem:operation:didFailToFetchDataWithError:")]
		void PortalItem (AGSPortalItem portalItem, NSObject op, NSObject error);

		[Export ("portalItem:operation:didFetchThumbnail:")]
		void PortalItem (AGSPortalItem portalItem, NSObject op, NSObject thumbnail);

		[Export ("portalItem:operation:didFailToFetchThumbnailWithError:")]
		void PortalItem (AGSPortalItem portalItem, NSObject op, NSObject error);

		[Export ("portalItem:operation:didFetchComments:")]
		void PortalItem (AGSPortalItem portalItem, NSObject op, NSObject comments);

		[Export ("portalItem:operation:didFailToFetchCommentsWithError:")]
		void PortalItem (AGSPortalItem portalItem, NSObject op, NSObject error);
	}

	public partial interface AgspOrtalItemComment {

		[Export ("owner")]
		int Owner { get; }

		[Export ("commentId")]
		int CommentId { get; }

		[Export ("comment")]
		int Comment { get; }

		[Export ("created")]
		int Created { get; }
	}

	public partial interface AgspOrtalQueryParams {

		[Export ("query")]
		int Query { get; set; }

		[Export ("sortField")]
		int SortField { get; set; }

		[Export ("sortOrder")]
		int SortOrder { get; set; }

		[Export ("startIndex")]
		int StartIndex { get; set; }

		[Export ("limit")]
		int Limit { get; set; }

		[Export ("initWithQuery:")]
		IntPtr Constructor (NSObject query);

		[Static, Export ("queryParamsWithQuery:")]
		AGSPortalQueryParams QueryParamsWithQuery (NSObject query);

		[Export ("initWithQuery:limit:")]
		IntPtr Constructor (NSObject query, NSObject limit);

		[Static, Export ("queryParamsWithQuery:limit:")]
		AGSPortalQueryParams QueryParamsWithQuery (NSObject query, NSObject limit);

		[Static, Export ("queryParamsForGroupsWithOwner:title:")]
		AGSPortalQueryParams QueryParamsForGroupsWithOwner (NSObject username, NSObject title);

		[Static, Export ("queryParamsForItemsOfType:withSearchString:")]
		AGSPortalQueryParams QueryParamsForItemsOfType (NSObject type, NSObject searchString);

		[Static, Export ("queryParamsForItemsOfType:inGroup:withSearchString:")]
		AGSPortalQueryParams QueryParamsForItemsOfType (NSObject type, NSObject groupId, NSObject searchString);

		[Static, Export ("queryParamsForItemsOfType:inGroup:")]
		AGSPortalQueryParams QueryParamsForItemsOfType (NSObject type, NSObject groupId);

		[Static, Export ("queryParamsForItemsInGroup:")]
		AGSPortalQueryParams QueryParamsForItemsInGroup (NSObject groupId);

		[Static, Export ("queryParamsForItemWithId:")]
		AGSPortalQueryParams QueryParamsForItemWithId (NSObject itemId);
	}

	public partial interface AgspOrtalQueryResultSet {

		[Export ("queryParams")]
		AGSPortalQueryParams QueryParams { get; }

		[Export ("nextQueryParams")]
		AGSPortalQueryParams NextQueryParams { get; }

		[Export ("totalResults")]
		int TotalResults { get; }

		[Export ("results")]
		int Results { get; }
	}

	public partial interface AgspOrtalUser {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("portal")]
		AGSPortal Portal { get; }

		[Export ("username")]
		int Username { get; }

		[Export ("fullName")]
		int FullName { get; }

		[Export ("userDescription")]
		int UserDescription { get; }

		[Export ("email")]
		int Email { get; }

		[Export ("organizationId")]
		int OrganizationId { get; }

		[Export ("thumbnailFileName")]
		int ThumbnailFileName { get; }

		[Export ("tags")]
		int Tags { get; }

		[Export ("groups")]
		int Groups { get; }

		[Export ("access")]
		int Access { get; }

		[Export ("created")]
		int Created { get; }

		[Export ("modified")]
		int Modified { get; }

		[Export ("thumbnail")]
		int Thumbnail { get; }

		[Export ("role")]
		int Role { get; }

		[Export ("fetchContent")]
		NSObject FetchContent { get; }

		[Export ("fetchContentInFolder:")]
		NSObject FetchContentInFolder (NSObject folderId);

		[Export ("fetchThumbnail")]
		NSObject FetchThumbnail { get; }

		[Export ("initWithPortal:username:")]
		IntPtr Constructor (AGSPortal portal, NSObject username);
	}

	[Model]
	public partial interface AgspOrtalUserDelegate {

		[Export ("portalUserDidLoad:")]
		void PortalUserDidLoad (AGSPortalUser portalUser);

		[Export ("portalUser:didFailToLoadWithError:")]
		void PortalUser (AGSPortalUser portalUser, NSObject error);

		[Export ("portalUser:operation:didFetchContent:folders:inFolder:")]
		void PortalUser (AGSPortalUser portalUser, NSObject op, NSObject items, NSObject folders, NSObject folderId);

		[Export ("portalUser:operation:didFailToFetchContentInFolder:withError:")]
		void PortalUser (AGSPortalUser portalUser, NSObject op, NSObject folderId, NSObject error);

		[Export ("portalUser:operation:didFetchThumbnail:")]
		void PortalUser (AGSPortalUser portalUser, NSObject op, NSObject thumbnail);

		[Export ("portalUser:operation:didFailToFetchThumbnailWithError:")]
		void PortalUser (AGSPortalUser portalUser, NSObject op, NSObject error);
	}

	public partial interface AgspRoximityResult {

		[Export ("point")]
		AGSPoint Point { get; }

		[Export ("pointIndex")]
		int PointIndex { get; }

		[Export ("partIndex")]
		int PartIndex { get; }

		[Export ("distance")]
		double Distance { get; }
	}

	public partial interface AgsqUery {

		[Export ("geometry")]
		AGSGeometry Geometry { get; set; }

		[Export ("outFields")]
		int OutFields { get; set; }

		[Export ("outSpatialReference")]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("returnGeometry")]
		int ReturnGeometry { get; set; }

		[Export ("spatialRelationship")]
		int SpatialRelationship { get; set; }

		[Export ("text")]
		int Text { get; set; }

		[Export ("where")]
		int Where { get; set; }

		[Export ("objectIds")]
		int ObjectIds { get; set; }

		[Export ("relationParam")]
		int RelationParam { get; set; }

		[Export ("timeExtent")]
		AGSTimeExtent TimeExtent { get; set; }

		[Export ("maxAllowableOffset")]
		double MaxAllowableOffset { get; set; }

		[Export ("outStatistics")]
		int OutStatistics { get; set; }

		[Export ("groupByFieldsForStatistics")]
		int GroupByFieldsForStatistics { get; set; }

		[Export ("orderByFields")]
		int OrderByFields { get; set; }

		[Export ("query")]
		NSObject Query { get; }
	}

	public partial interface AgsqUeryTask {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Static, Export ("queryTaskWithURL:")]
		NSObject QueryTaskWithUrl (NSObject url);

		[Static, Export ("queryTaskWithURL:credential:")]
		NSObject QueryTaskWithUrl (NSObject url, AGSCredential cred);

		[Export ("executeWithQuery:")]
		NSObject ExecuteWithQuery (AGSQuery query);

		[Export ("executeForIdsWithQuery:")]
		NSObject ExecuteForIdsWithQuery (AGSQuery query);

		[Export ("executeWithRelationshipQuery:")]
		NSObject ExecuteWithRelationshipQuery (AGSRelationshipQuery query);

		[Export ("executeFeatureCountWithQuery:")]
		NSObject ExecuteFeatureCountWithQuery (AGSQuery query);
	}

	[Model]
	public partial interface AgsqUeryTaskDelegate {

		[Export ("queryTask:operation:didExecuteWithFeatureSetResult:")]
		void QueryTask (AGSQueryTask queryTask, NSObject op, AGSFeatureSet featureSet);

		[Export ("queryTask:operation:didFailWithError:")]
		void QueryTask (AGSQueryTask queryTask, NSObject op, NSObject error);

		[Export ("queryTask:operation:didExecuteWithObjectIds:")]
		void QueryTask (AGSQueryTask queryTask, NSObject op, NSObject objectIds);

		[Export ("queryTask:operation:didFailQueryForIdsWithError:")]
		void QueryTask (AGSQueryTask queryTask, NSObject op, NSObject error);

		[Export ("queryTask:operation:didExecuteWithRelatedFeatures:")]
		void QueryTask (AGSQueryTask queryTask, NSObject op, NSObject relatedFeatures);

		[Export ("queryTask:operation:didFailRelationshipQueryWithError:")]
		void QueryTask (AGSQueryTask queryTask, NSObject op, NSObject error);

		[Export ("queryTask:operation:didExecuteWithFeatureCount:")]
		void QueryTask (AGSQueryTask queryTask, NSObject op, NSObject count);

		[Export ("queryTask:operation:didFailQueryFeatureCountWithError:")]
		void QueryTask (AGSQueryTask queryTask, NSObject op, NSObject error);
	}

	public partial interface AgsrAngeDomain {

		[Export ("minValue")]
		int MinValue { get; }

		[Export ("maxValue")]
		int MaxValue { get; }
	}

	public partial interface AgsrAsterFunction {

		[Export ("type")]
		int Type { get; set; }

		[Export ("arguments")]
		int Arguments { get; set; }
	}

	public partial interface AgsrElationParameters {

		[Export ("geometries1")]
		int Geometries1 { get; set; }

		[Export ("geometries2")]
		int Geometries2 { get; set; }

		[Export ("relation")]
		int Relation { get; set; }

		[Export ("relationParam")]
		int RelationParam { get; set; }

		[Export ("relationParameters")]
		NSObject RelationParameters { get; }
	}

	public partial interface AgsrElationship {

		[Export ("relationshipId")]
		int RelationshipId { get; }

		[Export ("name")]
		int Name { get; }

		[Export ("relatedTableId")]
		int RelatedTableId { get; }
	}

	public partial interface AgsrElationshipQuery {

		[Export ("relationshipId")]
		int RelationshipId { get; set; }

		[Export ("objectIds")]
		int ObjectIds { get; set; }

		[Export ("definitionExpression")]
		int DefinitionExpression { get; set; }

		[Export ("outFields")]
		int OutFields { get; set; }

		[Export ("returnGeometry")]
		int ReturnGeometry { get; set; }

		[Export ("outSpatialReference")]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("maxAllowableOffset")]
		double MaxAllowableOffset { get; set; }

		[Export ("relationshipQuery")]
		NSObject RelationshipQuery { get; }
	}

	public partial interface AgsrEnderer {

		[Export ("layer")]
		AGSGraphicsLayer Layer { get; }

		[Export ("symbolForGraphic:timeExtent:")]
		AGSSymbol SymbolForGraphic (AGSGraphic graphic, AGSTimeExtent timeExtent);

		[Export ("swatchForGraphic:size:")]
		NSObject SwatchForGraphic (AGSGraphic graphic, NSObject size);

		[Export ("swatchForGraphic:geometryType:size:")]
		NSObject SwatchForGraphic (AGSGraphic graphic, NSObject geometryType, NSObject size);
	}

	public partial interface AgsrEquest {

		[Static, Export ("requestForURL:credential:resource:queryParameters:doPOST:")]
		NSObject RequestForUrl (NSObject url, AGSCredential cred, NSObject operation, NSObject query, NSObject post);

		[Static, Export ("requestForURL:credential:resource:queryParameters:doPOST:cachePolicy:timeoutInterval:")]
		NSObject RequestForUrl (NSObject url, AGSCredential cred, NSObject operation, NSObject queryParams, NSObject post, NSObject cachePolicy, NSObject timeoutInterval);

		[Static, Export ("dataForURL:resource:queryParameters:doPOST:error:")]
		NSObject DataForUrl (NSObject url, NSObject operation, NSObject query, NSObject post, NSObject error);

		[Static, Export ("dataForURL:credential:resource:queryParameters:doPOST:error:")]
		NSObject DataForUrl (NSObject url, AGSCredential cred, NSObject operation, NSObject query, NSObject post, NSObject error);

		[Static, Export ("dataForRequest:error:")]
		NSObject DataForRequest (NSObject request, NSObject error);

		[Export ("additionalUserAgentInfo")]
		NSObject AdditionalUserAgentInfo { set; }

		[Export ("userAgent")]
		NSObject UserAgent { get; }

		[Export ("forcePostForAllRequests")]
		NSObject ForcePostForAllRequests { get; set; }
	}

	public partial interface AgsrEquestOperation {

		[Export ("URL")]
		int Url { get; }

		[Export ("resource")]
		int Resource { get; }

		[Export ("query")]
		int Query { get; }

		[Export ("post")]
		int Post { get; }

		[Export ("request")]
		int Request { get; }

		[Export ("state")]
		int State { get; }

		[Export ("credential")]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache")]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("securedResource")]
		[unmapped: unexposed: Unexposed] SecuredResource { get; set; }

		[Export ("response")]
		int Response { get; }

		[Export ("shouldCacheResponse")]
		int ShouldCacheResponse { get; set; }

		[Export ("requestCachePolicy")]
		int RequestCachePolicy { get; set; }

		[Export ("timeoutInterval")]
		int TimeoutInterval { get; set; }

		[Export ("initWithRequest:")]
		IntPtr Constructor (NSObject req);

		[Export ("initWithURL:")]
		IntPtr Constructor (NSObject url);

		[Export ("initWithURL:queryParameters:")]
		IntPtr Constructor (NSObject url, NSObject query);

		[Export ("initWithURL:resource:queryParameters:")]
		IntPtr Constructor (NSObject url, NSObject resource, NSObject query);

		[Export ("initWithURL:resource:queryParameters:doPOST:")]
		IntPtr Constructor (NSObject url, NSObject resource, NSObject query, NSObject post);

		[Export ("sharedOperationQueue")]
		NSObject SharedOperationQueue { get; }

		[Export ("shouldProcessResultDataInBackground:")]
		NSObject ShouldProcessResultDataInBackground (NSObject data);

		[Export ("processResultData:")]
		NSObject ProcessResultData (NSObject data);

		[Export ("processError:")]
		NSObject ProcessError (NSObject error);
	}

	public partial interface AgsrOuteResult {

		[Export ("directions")]
		AGSDirectionSet Directions { get; }

		[Export ("routeGraphic")]
		AGSGraphic RouteGraphic { get; }

		[Export ("routeName")]
		int RouteName { get; }

		[Export ("stopGraphics")]
		int StopGraphics { get; }
	}

	public partial interface AgsrOuteTask {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Static, Export ("routeTaskWithURL:")]
		NSObject RouteTaskWithUrl (NSObject url);

		[Static, Export ("routeTaskWithURL:credential:")]
		NSObject RouteTaskWithUrl (NSObject url, AGSCredential cred);

		[Export ("solveWithParameters:")]
		NSObject SolveWithParameters (AGSRouteTaskParameters routeParams);

		[Export ("retrieveDefaultRouteTaskParameters")]
		NSObject RetrieveDefaultRouteTaskParameters { get; }
	}

	[Model]
	public partial interface AgsrOuteTaskDelegate {

		[Export ("routeTask:operation:didSolveWithResult:")]
		void RouteTask (AGSRouteTask routeTask, NSObject op, AGSRouteTaskResult routeTaskResult);

		[Export ("routeTask:operation:didFailSolveWithError:")]
		void RouteTask (AGSRouteTask routeTask, NSObject op, NSObject error);

		[Export ("routeTask:operation:didRetrieveDefaultRouteTaskParameters:")]
		void RouteTask (AGSRouteTask routeTask, NSObject op, AGSRouteTaskParameters routeParams);

		[Export ("routeTask:operation:didFailToRetrieveDefaultRouteTaskParametersWithError:")]
		void RouteTask (AGSRouteTask routeTask, NSObject op, NSObject error);
	}

	public partial interface AgsrOuteTaskParameters : AGSCoding {

		[Export ("accumulateAttributeNames")]
		int AccumulateAttributeNames { get; set; }

		[Export ("attributeParameterValues")]
		int AttributeParameterValues { get; set; }

		[Export ("directionsLanguage")]
		int DirectionsLanguage { get; set; }

		[Export ("directionsLengthUnits")]
		int DirectionsLengthUnits { get; set; }

		[Export ("directionsStyleName")]
		int DirectionsStyleName { get; set; }

		[Export ("directionsTimeAttributeName")]
		int DirectionsTimeAttributeName { get; set; }

		[Export ("doNotLocateOnRestrictedElements")]
		int DoNotLocateOnRestrictedElements { get; set; }

		[Export ("findBestSequence")]
		int FindBestSequence { get; set; }

		[Export ("ignoreInvalidLocations")]
		int IgnoreInvalidLocations { get; set; }

		[Export ("impedanceAttributeName")]
		int ImpedanceAttributeName { get; set; }

		[Export ("outputGeometryPrecision")]
		double OutputGeometryPrecision { get; set; }

		[Export ("outputGeometryPrecisionUnits")]
		int OutputGeometryPrecisionUnits { get; set; }

		[Export ("outputLines")]
		int OutputLines { get; set; }

		[Export ("outSpatialReference")]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("preserveFirstStop")]
		int PreserveFirstStop { get; set; }

		[Export ("preserveLastStop")]
		int PreserveLastStop { get; set; }

		[Export ("restrictionAttributeNames")]
		int RestrictionAttributeNames { get; set; }

		[Export ("uTurns")]
		int UTUrns { get; set; }

		[Export ("returnPointBarriers")]
		int ReturnPointBarriers { get; set; }

		[Export ("returnDirections")]
		int ReturnDirections { get; set; }

		[Export ("returnPolygonBarriers")]
		int ReturnPolygonBarriers { get; set; }

		[Export ("returnPolylineBarriers")]
		int ReturnPolylineBarriers { get; set; }

		[Export ("returnRouteGraphics")]
		int ReturnRouteGraphics { get; set; }

		[Export ("returnStopGraphics")]
		int ReturnStopGraphics { get; set; }

		[Export ("startTime")]
		int StartTime { get; set; }

		[Export ("useHierarchy")]
		int UseHierarchy { get; set; }

		[Export ("useTimeWindows")]
		int UseTimeWindows { get; set; }

		[Export ("directionsOutputType")]
		int DirectionsOutputType { get; set; }

		[Export ("routeTaskParameters")]
		NSObject RouteTaskParameters { get; }

		[Export ("stopsWithFeatures")]
		NSObject StopsWithFeatures { set; }

		[Export ("stopsWithLayerDefinition")]
		AGSNALayerDefinition StopsWithLayerDefinition { set; }

		[Export ("pointBarriersWithFeatures")]
		NSObject PointBarriersWithFeatures { set; }

		[Export ("pointBarriersWithLayerDefinition")]
		AGSNALayerDefinition PointBarriersWithLayerDefinition { set; }

		[Export ("polylineBarriersWithFeatures")]
		NSObject PolylineBarriersWithFeatures { set; }

		[Export ("polylineBarriersWithLayerDefinition")]
		AGSNALayerDefinition PolylineBarriersWithLayerDefinition { set; }

		[Export ("polygonBarriersWithFeatures")]
		NSObject PolygonBarriersWithFeatures { set; }

		[Export ("polygonBarriersWithLayerDefinition")]
		AGSNALayerDefinition PolygonBarriersWithLayerDefinition { set; }
	}

	public partial interface AgsrOuteTaskResult : AGSCoding {

		[Export ("routeResults")]
		int RouteResults { get; }

		[Export ("pointBarriers")]
		int PointBarriers { get; }

		[Export ("polylineBarriers")]
		int PolylineBarriers { get; }

		[Export ("polygonBarriers")]
		int PolygonBarriers { get; }

		[Export ("messages")]
		int Messages { get; }
	}

	public partial interface AgsrUnLoopOperation {

		[Export ("target")]
		NSObject Target { get; set; }

		[Export ("action")]
		Selector Action { get; set; }

		[Export ("errorAction")]
		Selector ErrorAction { get; set; }

		[Export ("runLoopThread")]
		int RunLoopThread { get; set; }

		[Export ("waitUntilActionSelectorIsDone")]
		int WaitUntilActionSelectorIsDone { get; set; }

		[Export ("result")]
		NSObject Result { get; }

		[Export ("completionHandler")]
		AGSIdBlock CompletionHandler { get; set; }

		[Export ("errorHandler")]
		AGSErrorBlock ErrorHandler { get; set; }

		[Export ("finishWithResult:")]
		void FinishWithResult (NSObject result);

		[Export ("operationDidStart")]
		void OperationDidStart ();

		[Export ("operationWillFinish")]
		void OperationWillFinish ();
	}

	public partial interface AgstAsk : AGSSecuredResource {

		[Export ("URL")]
		int Url { get; }

		[Export ("credential")]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache")]
		int CredentialCache { get; set; }

		[Export ("requestCachePolicy")]
		int RequestCachePolicy { get; set; }

		[Export ("timeoutInterval")]
		int TimeoutInterval { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSObject url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSObject url, AGSCredential cred);
	}

	public partial interface AgstExtSymbol {

		[Export ("backgroundColor")]
		int BackgroundColor { get; set; }

		[Export ("borderLineColor")]
		int BorderLineColor { get; set; }

		[Export ("borderLineWidth")]
		int BorderLineWidth { get; set; }

		[Export ("vAlignment")]
		int VALignment { get; set; }

		[Export ("hAlignment")]
		int HALignment { get; set; }

		[Export ("fontFamily")]
		int FontFamily { get; set; }

		[Export ("fontSize")]
		int FontSize { get; set; }

		[Export ("text")]
		int Text { get; set; }

		[Export ("bold")]
		int Bold { get; set; }

		[Export ("italic")]
		int Italic { get; set; }

		[Export ("underline")]
		int Underline { get; set; }

		[Export ("strikeThru")]
		int StrikeThru { get; set; }

		[Export ("initWithText:color:")]
		IntPtr Constructor (NSObject text, NSObject color);

		[Static, Export ("textSymbolWithText:color:")]
		AGSTextSymbol TextSymbolWithText (NSObject text, NSObject color);
	}

	public partial interface AgstIledLayer {

		[Export ("tileInfo")]
		AGSTileInfo TileInfo { get; }

		[Export ("convertedScaleForLodScale:")]
		double ConvertedScaleForLodScale (double lodScale);

		[Export ("convertedResolutionForLodResolution:")]
		double ConvertedResolutionForLodResolution (double lodResolution);
	}

	public partial interface AgstIledMapServiceLayer {

		[Export ("URL")]
		int Url { get; }

		[Export ("mapServiceInfo")]
		AGSMapServiceInfo MapServiceInfo { get; }

		[Export ("credential")]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache")]
		int CredentialCache { get; set; }

		[Export ("renderNativeResolution")]
		int RenderNativeResolution { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSObject url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSObject url, AGSCredential cred);

		[Export ("initWithMapServiceInfo:")]
		IntPtr Constructor (AGSMapServiceInfo info);

		[Static, Export ("tiledMapServiceLayerWithURL:")]
		NSObject TiledMapServiceLayerWithUrl (NSObject url);

		[Static, Export ("tiledMapServiceLayerWithURL:credential:")]
		NSObject TiledMapServiceLayerWithUrl (NSObject url, AGSCredential cred);

		[Static, Export ("tiledMapServiceLayerWithMapServiceInfo:")]
		NSObject TiledMapServiceLayerWithMapServiceInfo (AGSMapServiceInfo info);

		[Export ("initWithJSON:URL:credential:")]
		IntPtr Constructor (NSObject json, NSObject url, AGSCredential cred);

		[Export ("resubmit")]
		void Resubmit ();

		[Export ("resubmitWithURL:credential:")]
		void ResubmitWithUrl (NSObject url, AGSCredential cred);

		[Export ("checkCurrentScaleVisibilityForSubLayer:")]
		NSObject CheckCurrentScaleVisibilityForSubLayer (AGSMapServiceLayerInfo msli);
	}

	public partial interface AgstIleInfo {

		[Export ("dpi")]
		int Dpi { get; }

		[Export ("format")]
		int Format { get; }

		[Export ("tileSize")]
		int TileSize { get; }

		[Export ("lods")]
		int Lods { get; }

		[Export ("origin")]
		AGSPoint Origin { get; }

		[Export ("spatialReference")]
		AGSSpatialReference SpatialReference { get; }

		[Export ("computeTileBounds:")]
		void ComputeTileBounds (AGSEnvelope envelope);

		[Export ("envelopeForTileAtLevel:row:column:")]
		AGSEnvelope EnvelopeForTileAtLevel (NSObject level, NSObject row, NSObject column);

		[Export ("envelopeForTileAtLOD:row:column:")]
		AGSEnvelope EnvelopeForTileAtLod (AGSLOD lod, NSObject row, NSObject col);

		[Export ("initWithDpi:format:lods:origin:spatialReference:tileSize:")]
		IntPtr Constructor (NSObject dpi, NSObject format, NSObject lods, AGSPoint origin, AGSSpatialReference spatialReference, NSObject tileSize);
	}

	public partial interface AgstIleKey {

		[Export ("column")]
		int Column { get; set; }

		[Export ("row")]
		int Row { get; set; }

		[Export ("level")]
		int Level { get; set; }

		[Export ("initWithColumn:row:level:")]
		IntPtr Constructor (NSObject c, NSObject r, NSObject l);

		[Static, Export ("tileKeyWithColumn:row:level:")]
		AGSTileKey TileKeyWithColumn (NSObject c, NSObject r, NSObject l);

		[Export ("isEqualToTileKey:")]
		NSObject IsEqualToTileKey (AGSTileKey key);
	}

	public partial interface AgstImeExtent {

		[Export ("start")]
		int Start { get; }

		[Export ("end")]
		int End { get; }

		[Export ("initWithStart:end:")]
		IntPtr Constructor (NSObject start, NSObject end);

		[Export ("isEqualToTimeExtent:")]
		NSObject IsEqualToTimeExtent (AGSTimeExtent timeExtent);

		[Export ("timeExtentByOffset:units:")]
		AGSTimeExtent TimeExtentByOffset (NSObject offsetValue, NSObject units);

		[Static, Export ("intersectionOfTimeExtent:andTimeExtent:")]
		AGSTimeExtent IntersectionOfTimeExtent (AGSTimeExtent timeExtent1, AGSTimeExtent timeExtent2);

		[Static, Export ("timeExtentWithStart:end:")]
		AGSTimeExtent TimeExtentWithStart (NSObject start, NSObject end);

		[Static, Export ("dateByOffsettingDate:offset:units:")]
		NSObject DateByOffsettingDate (NSObject date, NSObject offsetValue, NSObject units);
	}

	public partial interface AgstImeInfo {

		[Export ("startTimeField")]
		int StartTimeField { get; }

		[Export ("endTimeField")]
		int EndTimeField { get; }

		[Export ("trackIdField")]
		int TrackIdField { get; }

		[Export ("timeExtent")]
		AGSTimeExtent TimeExtent { get; }

		[Export ("timeReference")]
		AGSTimeReference TimeReference { get; }

		[Export ("timeInterval")]
		double TimeInterval { get; }

		[Export ("timeIntervalUnits")]
		int TimeIntervalUnits { get; }
	}

	public partial interface AgstImeReference {

		[Export ("timeZone")]
		int TimeZone { get; set; }

		[Export ("respectsDaylightSaving")]
		int RespectsDaylightSaving { get; set; }
	}

	public partial interface AgstRimExtendParameters {

		[Export ("polylines")]
		int Polylines { get; set; }

		[Export ("trimExtendTo")]
		AGSPolyline TrimExtendTo { get; set; }

		[Export ("extendHow")]
		int ExtendHow { get; set; }

		[Export ("trimExtendParameters")]
		NSObject TrimExtendParameters { get; }
	}

	public partial interface AgsuNiqueValue : AGSCoding {

		[Export ("value")]
		int Value { get; }

		[Export ("label")]
		int Label { get; }

		[Export ("valueDescription")]
		int ValueDescription { get; }

		[Export ("symbol")]
		AGSSymbol Symbol { get; }

		[Static, Export ("uniqueValueWithValue:symbol:")]
		NSObject UniqueValueWithValue (NSObject value, AGSSymbol symbol);

		[Export ("initWithValue:label:description:symbol:")]
		IntPtr Constructor (NSObject value, NSObject label, NSObject description, AGSSymbol symbol);
	}

	public partial interface AgsuNiqueValueRenderer {

		[Export ("defaultSymbol")]
		AGSSymbol DefaultSymbol { get; set; }

		[Export ("fields")]
		int Fields { get; set; }

		[Export ("fieldDelimiter")]
		int FieldDelimiter { get; set; }

		[Export ("defaultLabel")]
		int DefaultLabel { get; set; }

		[Export ("uniqueValues")]
		int UniqueValues { get; set; }
	}

	public partial interface AgswEbMap {

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSObject url, AGSCredential cred);

		[Static, Export ("webMapWithURL:credential:")]
		AGSWebMap WebMapWithUrl (NSObject url, AGSCredential cred);

		[Static, Export ("webMapWithItemId:credential:")]
		AGSWebMap WebMapWithItemId (NSObject itemId, AGSCredential cred);

		[Export ("initWithItemId:credential:")]
		IntPtr Constructor (NSObject itemId, AGSCredential cred);

		[Static, Export ("webMapWithItemId:sharingEndPoint:credential:")]
		AGSWebMap WebMapWithItemId (NSObject itemId, NSObject sharingEndPoint, AGSCredential cred);

		[Export ("initWithItemId:sharingEndPoint:credential:")]
		IntPtr Constructor (NSObject itemId, NSObject sharingEndPoint, AGSCredential cred);

		[Export ("initWithPortalItem:")]
		IntPtr Constructor (AGSPortalItem item);

		[Static, Export ("webMapWithPortalItem:")]
		AGSWebMap WebMapWithPortalItem (AGSPortalItem item);

		[Static, Export ("webMapWithItemId:portal:")]
		AGSWebMap WebMapWithItemId (NSObject itemId, AGSPortal portal);

		[Export ("initWithItemId:portal:")]
		IntPtr Constructor (NSObject itemId, AGSPortal portal);

		[Export ("URL")]
		int Url { get; }

		[Export ("credential")]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache")]
		int CredentialCache { get; set; }

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("zoomToDefaultExtentOnOpen")]
		int ZoomToDefaultExtentOnOpen { get; set; }

		[Export ("bookmarks")]
		int Bookmarks { get; }

		[Export ("loaded")]
		int Loaded { [Bind ("isLoaded")] get; }

		[Export ("version")]
		int Version { get; }

		[Export ("operationalLayers")]
		int OperationalLayers { get; }

		[Export ("baseMap")]
		AGSWebMapBaseMap BaseMap { get; }

		[Export ("portalItem")]
		AGSPortalItem PortalItem { get; }

		[Export ("queries")]
		int Queries { get; }

		[Export ("openIntoMapView:")]
		void OpenIntoMapView (AGSMapView mapView);

		[Export ("openIntoMapView:withAlternateBaseMap:")]
		void OpenIntoMapView (AGSMapView mapView, AGSWebMapBaseMap baseMap);

		[Export ("openIntoMapView:withAlternateBaseMap:resetMapView:")]
		void OpenIntoMapView (AGSMapView mapView, AGSWebMapBaseMap baseMap, NSObject reset);

		[Export ("continueOpenWithCredential:")]
		void ContinueOpenWithCredential (AGSCredential credential);

		[Export ("continueOpenAndSkipCurrentLayer")]
		void ContinueOpenAndSkipCurrentLayer ();

		[Export ("cancelOpen")]
		void CancelOpen ();

		[Export ("popupInfoForMapServiceLayerWithURL:sublayerId:")]
		AGSPopupInfo PopupInfoForMapServiceLayerWithUrl (NSObject url, NSObject sublayerId);

		[Export ("popupInfoForDynamicMapServiceLayer:sublayerId:")]
		AGSPopupInfo PopupInfoForDynamicMapServiceLayer (AGSDynamicMapServiceLayer dmsl, NSObject sublayerId);

		[Export ("popupInfoForTiledMapServiceLayer:sublayerId:")]
		AGSPopupInfo PopupInfoForTiledMapServiceLayer (AGSTiledMapServiceLayer tmsl, NSObject sublayerId);

		[Export ("popupInfoForFeatureLayer:")]
		AGSPopupInfo PopupInfoForFeatureLayer (AGSFeatureLayer featureLayer);

		[Export ("webMapLayerInfoForLayer:subLayerInfo:")]
		AGSWebMapLayerInfo WebMapLayerInfoForLayer (AGSLayer layer, out AGSWebMapSubLayerInfo subLayerInfo);
	}

	[Model]
	public partial interface AgswEbMapDelegate {

		[Export ("webMapDidLoad:")]
		void WebMapDidLoad (AGSWebMap webMap);

		[Export ("webMap:didFailToLoadWithError:")]
		void WebMap (AGSWebMap webMap, NSObject error);

		[Export ("didOpenWebMap:intoMapView:")]
		void DidOpenWebMap (AGSWebMap webMap, AGSMapView mapView);

		[Export ("didFailToLoadLayer:url:baseLayer:withError:")]
		void DidFailToLoadLayer (NSObject layerTitle, NSObject url, NSObject baseLayer, NSObject error);

		[Export ("webMap:didFailToLoadLayer:baseLayer:federated:withError:")]
		void WebMap (AGSWebMap webMap, AGSWebMapLayerInfo layerInfo, NSObject baseLayer, NSObject federated, NSObject error);

		[Export ("didLoadLayer:")]
		void DidLoadLayer (AGSLayer layer);

		[Export ("webMap:didLoadLayer:")]
		void WebMap (AGSWebMap webMap, AGSLayer layer);

		[Export ("bingAppId")]
		NSObject BingAppId { get; }

		[Export ("bingAppIdForWebMap:")]
		NSObject BingAppIdForWebMap (AGSWebMap webMap);
	}

	public partial interface AgswEbMapBaseMap {

		[Export ("title")]
		int Title { get; }

		[Export ("baseMapLayers")]
		int BaseMapLayers { get; }
	}

	public partial interface AgswEbMapBookmark {

		[Export ("extent")]
		AGSEnvelope Extent { get; }

		[Export ("name")]
		int Name { get; }
	}

	public partial interface AgswEbMapFeatureCollection {

		[Export ("layers")]
		int Layers { get; }

		[Export ("showLegend")]
		int ShowLegend { get; }

		[Export ("initWithJSON:")]
		IntPtr Constructor (NSObject json);
	}

	public partial interface AgswEbMapLayerInfo {

		[Export ("layerId")]
		int LayerId { get; }

		[Export ("itemId")]
		int ItemId { get; }

		[Export ("title")]
		int Title { get; }

		[Export ("URL")]
		int Url { get; }

		[Export ("opacity")]
		float Opacity { get; }

		[Export ("layerType")]
		int LayerType { get; }

		[Export ("visibility")]
		int Visibility { get; }

		[Export ("isReference")]
		int IsReference { get; }

		[Export ("featureCollection")]
		AGSWebMapFeatureCollection FeatureCollection { get; }

		[Export ("mode")]
		int Mode { get; }

		[Export ("popupInfo")]
		AGSPopupInfo PopupInfo { get; }

		[Export ("layers")]
		int Layers { get; }

		[Export ("visibleLayers")]
		int VisibleLayers { get; }

		[Export ("layerDefinition")]
		int LayerDefinition { get; }

		[Export ("showLegend")]
		int ShowLegend { get; }

		[Export ("bandIds")]
		int BandIds { get; }

		[Export ("minScale")]
		double MinScale { get; }

		[Export ("maxScale")]
		double MaxScale { get; }

		[Export ("isEditingDisabled")]
		int IsEditingDisabled { get; }
	}

	public partial interface AgswEbMapQuery {

		[Export ("name")]
		int Name { get; }

		[Export ("displayField")]
		int DisplayField { get; }

		[Export ("URL")]
		int Url { get; }

		[Export ("whereClause")]
		int WhereClause { get; }

		[Export ("parameters")]
		int Parameters { get; }

		[Export ("visibleFields")]
		int VisibleFields { get; }
	}

	public partial interface AgswEbMapQueryParameter {

		[Export ("defaultValue")]
		int DefaultValue { get; }

		[Export ("field")]
		int Field { get; }

		[Export ("paramOperator")]
		int ParamOperator { get; }

		[Export ("prompt")]
		int Prompt { get; }

		[Export ("helpTip")]
		int HelpTip { get; }

		[Export ("initWithPrompt:field:defaultValue:paramOperator:helpTip:")]
		IntPtr Constructor (NSObject p, NSObject f, NSObject dv, NSObject op, NSObject h);
	}

	public partial interface AgswEbMapSubLayerInfo {

		[Export ("layerId")]
		int LayerId { get; }

		[Export ("popupInfo")]
		AGSPopupInfo PopupInfo { get; }

		[Export ("featureSet")]
		int FeatureSet { get; }

		[Export ("layerDefinition")]
		int LayerDefinition { get; }

		[Export ("layerURL")]
		int LayerUrl { get; }

		[Export ("showLegend")]
		int ShowLegend { get; }
	}

	public partial interface AgswmslAyer : AGSSecuredResource {

		[Export ("version")]
		int Version { get; }

		[Export ("copyright")]
		int Copyright { get; }

		[Export ("spatialReference")]
		AGSSpatialReference SpatialReference { get; }

		[Export ("layerInfos")]
		int LayerInfos { get; }

		[Export ("credential")]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache")]
		int CredentialCache { get; set; }

		[Export ("imageFormat")]
		int ImageFormat { get; set; }

		[Export ("transparent")]
		int Transparent { get; set; }

		[Export ("visibleLayers")]
		int VisibleLayers { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSObject url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSObject url, AGSCredential cred);

		[Static, Export ("wmsLayerWithURL:")]
		NSObject WmsLayerWithUrl (NSObject url);

		[Static, Export ("wmsLayerWithURL:credential:")]
		NSObject WmsLayerWithUrl (NSObject url, AGSCredential cred);
	}

	public partial interface AgswmslAyerInfo {

		[Export ("name")]
		int Name { get; }

		[Export ("title")]
		int Title { get; }

		[Export ("extent")]
		AGSEnvelope Extent { get; }

		[Export ("subLayers")]
		int SubLayers { get; }
	}

	public partial interface AgswmtsiNfo : AGSSecuredResource {

		[Export ("delegate")]
		[unmapped: unexposed: Unexposed] Delegate { get; set; }

		[Export ("layerInfos")]
		int LayerInfos { get; }

		[Export ("credential")]
		int Credential { get; set; }

		[Export ("credentialCache")]
		int CredentialCache { get; set; }

		[Export ("URL")]
		int Url { get; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSObject url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSObject url, NSObject credential);

		[Static, Export ("wmtsInfoWithURL:")]
		NSObject WmtsInfoWithUrl (NSObject url);

		[Static, Export ("wmtsInfoWithURL:credential:")]
		NSObject WmtsInfoWithUrl (NSObject url, NSObject credential);

		[Export ("wmtsLayerWithLayerInfo:andSpatialReference:")]
		AGSWMTSLayer WmtsLayerWithLayerInfo (AGSWMTSLayerInfo layerInfo, NSObject sr);
	}

	[Model]
	public partial interface AgswmtsiNfoDelegate {

		[Export ("wmtsInfoDidLoad:")]
		void WmtsInfoDidLoad (AGSWMTSInfo wmtsInfo);

		[Export ("wmtsInfo:DidFailToLoad:")]
		void WmtsInfo (AGSWMTSInfo wmtsInfo, NSObject error);
	}

	public partial interface AgswmtslAyer : AGSSecuredResource {

		[Export ("URL")]
		int Url { get; }

		[Export ("version")]
		int Version { get; }

		[Export ("copyright")]
		int Copyright { get; }

		[Export ("spatialReference")]
		AGSSpatialReference SpatialReference { get; }

		[Export ("credential")]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache")]
		int CredentialCache { get; set; }

		[Export ("imageFormat")]
		int ImageFormat { get; set; }

		[Export ("layerDescription")]
		int LayerDescription { get; }

		[Export ("title")]
		int Title { get; }

		[Export ("style")]
		AGSWMTSStyle Style { get; set; }
	}

	public partial interface AgswmtslAyerInfo {

		[Export ("title")]
		int Title { get; }

		[Export ("imageFormats")]
		int ImageFormats { get; }

		[Export ("tileMatrixSet")]
		int TileMatrixSet { get; set; }

		[Export ("tileMatrixSetIds")]
		int TileMatrixSetIds { get; }

		[Export ("style")]
		AGSWMTSStyle Style { get; set; }

		[Export ("styles")]
		int Styles { get; }
	}

	public partial interface AgswmtssTyle {

		[Export ("identifier")]
		int Identifier { get; }

		[Export ("title")]
		int Title { get; }

		[Export ("abstract")]
		int Abstract { get; }

		[Export ("isDefault")]
		int IsDefault { get; }
	}

	[Category, BaseType (typeof (NSObject))]
	public partial interface NsoBjectAgssbjSonWritingNsoBject {

		[Export ("ags_JSONRepresentation")]
		string AgsJsonrEpresentation { get; }
	}

	[Category, BaseType (typeof (NSString))]
	public partial interface NssTringAgssbjSonParsingNssTring {

		[Export ("ags_JSONValue")]
		NSObject AgsJsonvAlue { get; }
	}

	[Category, BaseType (typeof (NSData))]
	public partial interface NsdAtaAgssbjSonParsingNsdAta {

		[Export ("ags_JSONValue")]
		NSObject AgsJsonvAlue { get; }
	}
}
