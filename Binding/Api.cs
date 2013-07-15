
using System.Drawing;
using System;

using MonoTouch.ObjCRuntime;
using MonoTouch.Foundation;

namespace MonoTouch.ArcGIS {

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSCoding {

		[Export ("initWithJSON:")]
		IntPtr Constructor (NSDictionary json);

		[Export ("decodeWithJSON:")]
		void DecodeWithJSON (NSDictionary json);

		[Export ("encodeToJSON")]
		NSDictionary EncodeToJSON();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSCredential {

		[Export ("username", ArgumentSemantic.Copy)]
		string Username { get; set; }

		[Export ("password", ArgumentSemantic.Copy)]
		string Password { get; set; }

		[Export ("tokenUrl", ArgumentSemantic.Copy)]
		NSUrl TokenUrl { get; set; }

		[Export ("authType")]
		AGSAuthenticationType AuthType { get; set; }

		[Export ("referer", ArgumentSemantic.Copy)]
		string Referer { get; }

		[Export ("token", ArgumentSemantic.Copy)]
		string Token { get; set; }

		[Export ("sslRequired")]
		bool SslRequired { get; }

		[Export ("identity")]
		SecIdentity Identity();

		[Export ("initWithUser:password:")]
		IntPtr Constructor (string username, string password);

		[Export ("initWithUser:password:authenticationType:")]
		IntPtr Constructor (string username, string password, AGSAuthenticationType authType);

		[Export ("initWithUser:password:authenticationType:tokenUrl:")]
		IntPtr Constructor (string username, string password, AGSAuthenticationType authType, NSUrl tokenUrl);

		[Export ("initWithToken:")]
		IntPtr Constructor (string token);

		[Export ("initWithIdentityRef:")]
		IntPtr Constructor (SecIdentity identityRef);

		[Export ("initWithToken:referer:")]
		IntPtr Constructor (string token, string referer);

		[Static, Export ("getTokenServiceUrl:error:")]
		NSUrl GetTokenServiceUrl (NSUrl url, out NSError error);

		[Static, Export ("isServiceSecured:error:")]
		AGSAuthenticationType IsServiceSecured (NSUrl url, out NSError error);

		[Static, Export ("identitiesForProtectionSpace:")]
		SecIdentityRef [] IdentitiesForProtectionSpace (NSURLProtectionSpace protectionSpace);

		[Static, Export ("importCertificateData:password:overwrite:error:")]
		SecIdentity ImportCertificateData (NSData data, string password, bool overwrite, out NSError error);

		[Static, Export ("removeIdentityFromKeychain:")]
		OSStatus RemoveIdentityFromKeychain (SecIdentity identityRef);

		[Export ("authenticatingHost")]
		string AuthenticatingHost();
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSSecuredResource {

		[Export ("credential", ArgumentSemantic.Copy)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSCredentialCache {

		[Export ("shouldAutoCacheCredentials")]
		bool ShouldAutoCacheCredentials { get; set; }

		[Export ("removeAllCredentials")]
		void RemoveAllCredentials ();

		[Export ("setCredential:forUrl:")]
		void SetCredential (AGSCredential credential, NSUrl url);

		[Export ("credentialForUrl:")]
		AGSCredential CredentialForUrl (NSUrl url);

		[Export ("removeCredentialForUrl:")]
		void RemoveCredentialForUrl (NSUrl url);

		[Export ("removeCredential:")]
		void RemoveCredential (AGSCredential credential);

		[Static, Export ("defaultCache")]
		AGSCredentialCache DefaultCache ();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSJSONUtility {

		[Static, Export ("encodeToDictionary:withKey:AGSCodingArray:")]
		void EncodeToDictionary (NSMutableDictionary json, string key, NSObject [] items);

		[Static, Export ("decodeFromDictionary:withKey:fromClass:")]
		NSMutableArray DecodeFromDictionary (NSDictionary json, string key, Class cls);

		[Static, Export ("getStringFromDictionary:withKey:")]
		string GetStringFromDictionary (NSDictionary json, string key);
	}

	[Category, BaseType (typeof (NSDictionary))]
	public partial interface AGSAdditions_NSDictionary {

		[Export ("ags_encodeQueryParams"), Target(typeof(NSDictionary))]
		string EncodeQueryParams();

		[Export ("ags_encodeJSON"), Target(typeof(NSDictionary))]
		NSDictionary EncodeJSON();

		[Export ("ags_stringByApplyingTemplate:"), Target(typeof(NSDictionary))]
		string Ags_stringByApplyingTemplate (string templateString);

		[Export ("ags_safeGetObjectForKey:"), Target(typeof(NSDictionary))]
		NSObject Ags_safeGetObjectForKey (NSObject key);

		[Export ("ags_safeValueForKey:"), Target(typeof(NSDictionary))]
		NSObject Ags_safeValueForKey (string key);

		[Export ("ags_safeObjectForKey:"), Target(typeof(NSDictionary))]
		NSObject Ags_safeObjectForKey (NSObject key);

		[Export ("ags_URLForKey:"), Target(typeof(NSDictionary))]
		NSUrl Ags_URLForKey (NSObject key);
	}

	[Category, BaseType (typeof (NSMutableDictionary))]
	public partial interface AGSAdditions_NSMutableDictionary {

		[Export ("ags_safeSetObject:forKey:")]
		void Ags_safeSetObject (NSObject obj, string key);

		[Export ("ags_safeSetObject:forKey:useNSNull:")]
		void Ags_safeSetObject (NSObject obj, string key, bool useNSNull);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSRequest {

		[Static, Export ("requestForURL:credential:resource:queryParameters:doPOST:")]
		NSURLRequest RequestForURL (NSUrl url, AGSCredential cred, string operation, NSDictionary query, bool post);

		[Static, Export ("requestForURL:credential:resource:queryParameters:doPOST:cachePolicy:timeoutInterval:")]
		NSURLRequest RequestForURL (NSUrl url, AGSCredential cred, string operation, NSDictionary queryParams, bool post, NSURLRequestCachePolicy cachePolicy, double timeoutInterval);

		[Static, Export ("dataForURL:resource:queryParameters:doPOST:error:")]
		NSData DataForURL (NSUrl url, string operation, NSDictionary query, bool post, out NSError error);

		[Static, Export ("dataForURL:credential:resource:queryParameters:doPOST:error:")]
		NSData DataForURL (NSUrl url, AGSCredential cred, string operation, NSDictionary query, bool post, out NSError error);

		[Static, Export ("dataForRequest:error:")]
		NSData DataForRequest (NSURLRequest request, out NSError error);

		[Static, Export ("setAdditionalUserAgentInfo:")]
		string SetAdditionalUserAgentInfo(string userAgentInfo);

		[Static]
		string UserAgent { [Bind ("userAgent")]get; }

		[Static]
		bool ForcePostForAllRequests { [Bind ("forcePostForAllRequests")]get; [Bind ("setForcePostForAllRequests")]set; }
	}

	[BaseType (typeof (NSOperation))]
	public partial interface AGSRunLoopOperation {

		[Export ("target", ArgumentSemantic.Assign)]
		NSObject Target { get; set; }

		[Export ("action", ArgumentSemantic.Assign)]
		Selector Action { get; set; }

		[Export ("errorAction", ArgumentSemantic.Assign)]
		Selector ErrorAction { get; set; }

		[Export ("runLoopThread", ArgumentSemantic.Retain)]
		NSThread RunLoopThread { get; set; }

		[Export ("waitUntilActionSelectorIsDone")]
		bool WaitUntilActionSelectorIsDone { get; set; }

		[Export ("result", ArgumentSemantic.Retain)]
		NSObject Result { get; }

		[Export ("completionHandler", ArgumentSemantic.Copy)]
		AGSIdBlock CompletionHandler { get; set; }

		[Export ("errorHandler", ArgumentSemantic.Copy)]
		AGSErrorBlock ErrorHandler { get; set; }

		[Export ("finishWithResult:")]
		void FinishWithResult (NSObject result);

		[Export ("operationDidStart")]
		void OperationDidStart ();

		[Export ("operationWillFinish")]
		void OperationWillFinish ();
	}

	[BaseType (typeof (AGSRunLoopOperation))]
	public partial interface AGSRequestOperation {

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		[Export ("resource", ArgumentSemantic.Copy)]
		string Resource { get; }

		[Export ("query", ArgumentSemantic.Copy)]
		NSDictionary Query { get; }

		[Export ("post")]
		bool Post { get; }

		[Export ("request", ArgumentSemantic.Retain)]
		NSURLRequest Request { get; }

		[Export ("state", ArgumentSemantic.Retain)]
		NSMutableDictionary State { get; }

		[Export ("credential", ArgumentSemantic.Retain)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("securedResource", ArgumentSemantic.Assign)]
		AGSSecuredResource SecuredResource { get; set; }

		[Export ("response", ArgumentSemantic.Retain)]
		NSURLResponse Response { get; }

		[Export ("shouldCacheResponse")]
		bool ShouldCacheResponse { get; set; }

		[Export ("requestCachePolicy")]
		NSURLRequestCachePolicy RequestCachePolicy { get; set; }

		[Export ("timeoutInterval")]
		double TimeoutInterval { get; set; }

		[Export ("initWithRequest:")]
		IntPtr Constructor (NSURLRequest req);

		[Export ("initWithURL:")]
		IntPtr Constructor (NSUrl url);

		[Export ("initWithURL:queryParameters:")]
		IntPtr Constructor (NSUrl url, NSDictionary query);

		[Export ("initWithURL:resource:queryParameters:")]
		IntPtr Constructor (NSUrl url, string resource, NSDictionary query);

		[Export ("initWithURL:resource:queryParameters:doPOST:")]
		IntPtr Constructor (NSUrl url, string resource, NSDictionary query, bool post);

		[Static]
		NSOperationQueue SharedOperationQueue { [Export ("sharedOperationQueue")]get; }

		[Export ("shouldProcessResultDataInBackground:")]
		bool ShouldProcessResultDataInBackground (NSData data);

		[Export ("processResultData:")]
		NSObject ProcessResultData (NSData data);

		[Export ("processError:")]
		NSError ProcessError (NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSSpatialReference : AGSCoding {

		[Export ("wkid")]
		uint Wkid { get; }

		[Export ("wkt", ArgumentSemantic.Copy)]
		string Wkt { get; }

		[Export ("initWithWKID:")]
		IntPtr Constructor (uint wkid);

		[Export ("initWithWKT:")]
		IntPtr Constructor (string wkt);

		[Static, Export ("spatialReferenceWithWKID:")]
		NSObject SpatialReferenceWithWKID (uint wkid);

		[Static, Export ("spatialReferenceWithWKT:")]
		NSObject SpatialReferenceWithWKT (string wkt);

		[Export ("initWithWKID:WKT:")]
		IntPtr Constructor (uint wkid, string wkt);

		[Static, Export ("spatialReferenceWithWKID:WKT:")]
		NSObject SpatialReferenceWithWKID (uint wkid, string wkt);

		bool IsAnyWebMercator { [Bind ("isAnyWebMercator")]get; }

		bool IsWGS84 { [Bind ("isWGS84")]get; }

		[Export ("isEqualToSpatialReference:")]
		bool IsEqualToSpatialReference (AGSSpatialReference sr);

		[Export ("isEqualToWKID:")]
		bool IsEqualToWKID (uint wkid);

		[Export ("encodeToJSON:forKey:")]
		void EncodeToJSON (NSMutableDictionary json, string key);

		AGSSRUnit Unit { [Bind ("unit")]get; }

		[Static]
		AGSSpatialReference WebMercatorSpatialReference { [Bind ("webMercatorSpatialReference")]get; }

		[Static]
		AGSSpatialReference Wgs84SpatialReference { [Bind ("wgs84SpatialReference")]get; }

		[Export ("convertValue:toUnit:")]
		double ConvertValue (double val, AGSSRUnit unit);

		[Export ("convertValue:fromUnit:")]
		double ConvertValue (double val, AGSSRUnit fromUnit);

		bool IsSupported { [Bind ("isSupported")]get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSGeometry : AGSCoding, NSMutableCopying {

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; }

		[Export ("envelope", ArgumentSemantic.Copy)]
		AGSEnvelope Envelope { get; }

		[Export ("initWithSpatialReference:")]
		IntPtr Constructor (AGSSpatialReference spatialReference);

		[Export ("initWithJSON:spatialReference:")]
		IntPtr Constructor (NSDictionary json, AGSSpatialReference sr);

		[Export ("intersectsWithEnvelope:")]
		bool IntersectsWithEnvelope (AGSEnvelope envelope);

		bool IsEmpty { [Bind ("isEmpty")]get; }

		bool IsValid { [Bind ("isValid")]get; }
	}

	[BaseType (typeof (AGSGeometry))]
	public partial interface AGSEnvelope {

		[Export ("xmin")]
		double Xmin { get; }

		[Export ("ymin")]
		double Ymin { get; }

		[Export ("xmax")]
		double Xmax { get; }

		[Export ("ymax")]
		double Ymax { get; }

		[Export ("center", ArgumentSemantic.Retain)]
		AGSPoint Center { get; }

		[Export ("width")]
		double Width { get; }

		[Export ("height")]
		double Height { get; }

		[Export ("initWithXmin:ymin:xmax:ymax:spatialReference:")]
		IntPtr Constructor (double xmin, double ymin, double xmax, double ymax, AGSSpatialReference spatialReference);

		[Static, Export ("envelopeWithXmin:ymin:xmax:ymax:spatialReference:")]
		NSObject EnvelopeWithXmin (double xmin, double ymin, double xmax, double ymax, AGSSpatialReference spatialReference);

		[Export ("containsPoint:")]
		bool ContainsPoint (AGSPoint point);

		[Export ("containsEnvelope:")]
		bool ContainsEnvelope (AGSEnvelope env);

		string SimpleRepresentation { [Bind ("simpleRepresentation")]get; }

		[Export ("intersectsWithEnvelope:")]
		bool IntersectsWithEnvelope (AGSEnvelope envelope);

		[Export ("intersectionWithEnvelope:")]
		AGSEnvelope IntersectionWithEnvelope (AGSEnvelope envelope);

		bool IsEmpty { [Bind ("isEmpty")]get; }

		[Export ("isEqualToEnvelope:")]
		bool IsEqualToEnvelope (AGSEnvelope other);
	}

	[BaseType (typeof (AGSEnvelope))]
	public partial interface AGSMutableEnvelope {

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
		void Reaspect (SizeF size);

		[Export ("offsetByX:y:")]
		void OffsetByX (double offsetX, double offsetY);

		[Export ("normalize")]
		void Normalize ();

		[Export ("normalizeToEnvelope:")]
		void NormalizeToEnvelope (AGSEnvelope env);

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; set; }
	}

	[BaseType (typeof (AGSGeometry))]
	public partial interface AGSMultipoint {

		[Export ("numPoints")]
		int NumPoints { get; }

		[Export ("pointAtIndex:")]
		AGSPoint PointAtIndex (int index);

		[Export ("isEqualToMultipoint:")]
		bool IsEqualToMultipoint (AGSMultipoint other);
	}

	[BaseType (typeof (AGSMultipoint))]
	public partial interface AGSMutableMultipoint {

		[Export ("addPoint:")]
		void AddPoint (AGSPoint point);

		[Export ("insertPoint:atIndex:")]
		void InsertPoint (AGSPoint point, int index);

		[Export ("removePointAtIndex:")]
		void RemovePointAtIndex (int index);

		[Export ("updatePoint:atIndex:")]
		void UpdatePoint (AGSPoint point, int index);

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; set; }
	}

	[BaseType (typeof (AGSGeometry))]
	public partial interface AGSPoint {

		[Export ("x")]
		double X { get; }

		[Export ("y")]
		double Y { get; }

		[Export ("initWithX:y:spatialReference:")]
		IntPtr Constructor (double x, double y, AGSSpatialReference spatialReference);

		[Static, Export ("pointWithX:y:spatialReference:")]
		NSObject PointWithX (double x, double y, AGSSpatialReference spatialReference);

		[Export ("isEqualToPoint:")]
		bool IsEqualToPoint (AGSPoint other);

		[Export ("distanceToPoint:")]
		double DistanceToPoint (AGSPoint other);
	}

	[BaseType (typeof (AGSPoint))]
	public partial interface AGSMutablePoint {

		[Export ("updateWithX:y:")]
		void UpdateWithX (double x, double y);

		[Export ("offsetByX:y:")]
		void OffsetByX (double xOffset, double yOffset);

		[Export ("normalize")]
		void Normalize ();

		[Export ("normalizeToEnvelope:")]
		void NormalizeToEnvelope (AGSEnvelope env);

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; set; }
	}

	[BaseType (typeof (AGSGeometry))]
	public partial interface AGSPolygon {

		[Export ("numRings")]
		int NumRings { get; }

		[Export ("numPointsInRing:")]
		int NumPointsInRing (int ring);

		int NumPoints { [Bind ("numPoints")]get; }

		[Export ("pointOnRing:atIndex:")]
		AGSPoint PointOnRing (int ring, int index);

		[Static, Export ("polygonWithJSON:")]
		NSObject PolygonWithJSON (NSDictionary json);

		[Export ("containsPoint:")]
		bool ContainsPoint (AGSPoint point);

		[Export ("isEqualToPolygon:")]
		bool IsEqualToPolygon (AGSPolygon other);
	}

	[BaseType (typeof (AGSPolygon))]
	public partial interface AGSMutablePolygon {

		[Export ("addRingToPolygon")]
		void AddRingToPolygon ();

		[Export ("insertRingAtIndex:")]
		void InsertRingAtIndex (int ringIndex);

		[Export ("addPointToRing:")]
		void AddPointToRing (AGSPoint point);

		[Export ("addPoint:toRing:")]
		void AddPoint (AGSPoint point, int ring);

		[Export ("insertPoint:onRing:atIndex:")]
		void InsertPoint (AGSPoint point, int ring, int index);

		[Export ("removePointOnRing:atIndex:")]
		void RemovePointOnRing (int ring, int index);

		[Export ("updatePoint:onRing:atIndex:")]
		void UpdatePoint (AGSPoint point, int ring, int index);

		[Export ("removeRingAtIndex:")]
		void RemoveRingAtIndex (int index);

		[Export ("closePolygon")]
		void ClosePolygon ();

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; set; }
	}

	[BaseType (typeof (AGSGeometry))]
	public partial interface AGSPolyline {

		[Export ("numPaths")]
		int NumPaths { get; }

		[Export ("numPointsInPath:")]
		int NumPointsInPath (int path);

		int NumPoints { [Bind ("numPoints")]get; }

		[Export ("pointOnPath:atIndex:")]
		AGSPoint PointOnPath (int path, int index);

		[Static, Export ("polylineWithJSON:")]
		NSObject PolylineWithJSON (NSDictionary json);

		[Export ("isEqualToPolyline:")]
		bool IsEqualToPolyline (AGSPolyline other);
	}

	[BaseType (typeof (AGSPolyline))]
	public partial interface AGSMutablePolyline {

		[Export ("addPathToPolyline")]
		void AddPathToPolyline ();

		[Export ("insertPathAtIndex:")]
		void InsertPathAtIndex (int pathIndex);

		[Export ("addPointToPath:")]
		void AddPointToPath (AGSPoint point);

		[Export ("addPoint:toPath:")]
		void AddPoint (AGSPoint point, int path);

		[Export ("insertPoint:onPath:atIndex:")]
		void InsertPoint (AGSPoint point, int path, int index);

		[Export ("removePointOnPath:atIndex:")]
		void RemovePointOnPath (int path, int index);

		[Export ("updatePoint:onPath:atIndex:")]
		void UpdatePoint (AGSPoint point, int pathIndex, int ptIndex);

		[Export ("removePathAtIndex:")]
		void RemovePathAtIndex (int index);

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSGeometryEngine {

		[Export ("projectGeometry:toSpatialReference:")]
		AGSGeometry ProjectGeometry (AGSGeometry geometry, AGSSpatialReference spatialReference);

		[Export ("areaOfGeometry:")]
		double AreaOfGeometry (AGSGeometry geometry);

		[Export ("shapePreservingAreaOfGeometry:inUnit:")]
		double ShapePreservingAreaOfGeometry (AGSGeometry geometry, AGSAreaUnits areaUnit);

		[Export ("lengthOfGeometry:")]
		double LengthOfGeometry (AGSGeometry geometry);

		[Export ("geodesicLengthOfGeometry:inUnit:")]
		double GeodesicLengthOfGeometry (AGSGeometry geometry, AGSSRUnit lengthUnit);

		[Export ("shapePreservingLengthOfGeometry:inUnit:")]
		double ShapePreservingLengthOfGeometry (AGSGeometry geometry, AGSSRUnit lengthUnit);

		[Export ("simplifyGeometry:")]
		AGSGeometry SimplifyGeometry (AGSGeometry geometry);

		[Export ("cutGeometry:withCutter:")]
		AGSGeometry [] CutGeometry (AGSGeometry geometry, AGSPolyline cutter);

		[Export ("bufferGeometry:byDistance:")]
		AGSMutablePolygon BufferGeometry (AGSGeometry geometry, double distance);

		[Export ("bufferGeometries:byDistance:")]
		AGSMutablePolygon BufferGeometries (AGSGeometry [] geometries, double distance);

		[Export ("unionGeometries:")]
		AGSGeometry UnionGeometries (AGSGeometry [] geometries);

		[Export ("densifyGeometry:withMaxSegmentLength:")]
		AGSGeometry DensifyGeometry (AGSGeometry geometry, double maxSegmentLength);

		[Export ("geodesicDensifyGeometry:withMaxSegmentLength:inUnit:")]
		AGSGeometry GeodesicDensifyGeometry (AGSGeometry geometry, double maxSegmentLength, AGSSRUnit lengthUnit);

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
		AGSGeometry OffsetGeometry (AGSGeometry geometry, double distance, AGSGeometryOffsetType joinType, double bevelRatio, double flattenError);

		[Export ("geometry:intersectsGeometry:")]
		bool Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("geometry:crossesGeometry:")]
		bool Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("geometry:withinGeometry:")]
		bool Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("geometry:disjointToGeometry:")]
		bool Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("geometry:touchesGeometry:")]
		bool Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("geometry:containsGeometry:")]
		bool Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("geometry:overlapsGeometry:")]
		bool Geometry (AGSGeometry geometry1, AGSGeometry geometry2);

		[Export ("nearestVertexInGeometry:toPoint:")]
		AGSProximityResult NearestVertexInGeometry (AGSGeometry geometry, AGSPoint point);

		[Export ("nearestCoordinateInGeometry:toPoint:")]
		AGSProximityResult NearestCoordinateInGeometry (AGSGeometry geometry, AGSPoint point);

		[Export ("normalizeCentralMeridianOfGeometry:")]
		AGSGeometry NormalizeCentralMeridianOfGeometry (AGSGeometry geometry);

		[Static]
		AGSGeometryEngine DefaultGeometryEngine { [Bind ("defaultGeometryEngine")]get; }

		[Export ("mgrsFromPoint:numDigits:rounding:addSpaces:")]
		string MgrsFromPoint (AGSPoint pt, int digits, bool rounding, bool addSpaces);

		[Export ("pointFromMGRS:")]
		AGSPoint PointFromMGRS (string mgrs);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSProximityResult {

		[Export ("point", ArgumentSemantic.Retain)]
		AGSPoint Point { get; }

		[Export ("pointIndex")]
		int PointIndex { get; }

		[Export ("partIndex")]
		int PartIndex { get; }

		[Export ("distance")]
		double Distance { get; }
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSLayerDelegate {

		[Notification, Field ("AGSLayerDidLoadNotification")]
		NSString AGSLayerDidLoadNotification { get; }

		[Notification, Field ("AGSLayerDidFailToLoadNotification")]
		NSString AGSLayerDidFailToLoadNotification { get; }

		[Notification, Field ("AGSLayerDidInitializeSpatialReferenceStatusNotification")]
		NSString AGSLayerDidInitializeSpatialReferenceStatusNotification { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSLayer {

		[Export ("loaded")]
		bool Loaded { get; }

		[Export ("error", ArgumentSemantic.Retain)]
		NSError Error { get; }

		[Export ("renderNativeResolution")]
		bool RenderNativeResolution { get; set; }

		[Export ("opacity")]
		float Opacity { get; set; }

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; set; }

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSLayerDelegate Delegate { get; set; }

		[Export ("spatialReferenceStatusValid")]
		bool SpatialReferenceStatusValid { get; set; }

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; }

		[Export ("fullEnvelope", ArgumentSemantic.Retain)]
		AGSEnvelope FullEnvelope { get; }

		[Export ("initialEnvelope", ArgumentSemantic.Retain)]
		AGSEnvelope InitialEnvelope { get; set; }

		[Export ("minScale")]
		double MinScale { get; set; }

		[Export ("maxScale")]
		double MaxScale { get; set; }

		[Export ("refresh")]
		void Refresh ();

		bool TimeAware { [Bind ("timeAware")]get; [Bind ("isTimeAware")]set;}

		bool Visible { [Bind ("visible")]get; [Bind ("isVisible")]set; }

		bool IsInScale { [Bind ("isInScale")]get; }
	}

	[Category, BaseType (typeof (AGSLayer))]
	public partial interface ForSubclassEyesOnly_AGSLayer {

		[Export ("error", ArgumentSemantic.Retain)]
		NSError Error { get; set; }

		int DefaultDpi { [Bind ("defaultDpi")]get; }

		[Export ("layerDidLoad")]
		void LayerDidLoad ();

		[Export ("layerDidFailToLoad:")]
		void LayerDidFailToLoad (NSError error);

		[Export ("spatialReferenceStatusInitialized")]
		void SpatialReferenceStatusInitialized ();

		[Export ("mapDidUpdate:")]
		void MapDidUpdate (AGSMapUpdateType updateType);

		[Export ("mapView", ArgumentSemantic.Assign)]
		AGSMapView MapView { get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSTileInfo : AGSCoding {

		[Export ("dpi")]
		uint Dpi { get; }

		[Export ("format", ArgumentSemantic.Copy)]
		string Format { get; }

		[Export ("tileSize")]
		SizeF TileSize { get; }

		[Export ("lods", ArgumentSemantic.Copy)]
		AGSLOD [] Lods { get; }

		[Export ("origin", ArgumentSemantic.Retain)]
		AGSPoint Origin { get; }

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; }

		[Export ("computeTileBounds:")]
		void ComputeTileBounds (AGSEnvelope envelope);

		[Export ("envelopeForTileAtLevel:row:column:")]
		AGSEnvelope EnvelopeForTileAtLevel (int level, int row, int column);

		[Export ("envelopeForTileAtLOD:row:column:")]
		AGSEnvelope EnvelopeForTileAtLOD (AGSLOD lod, int row, int col);

		[Export ("initWithDpi:format:lods:origin:spatialReference:tileSize:")]
		IntPtr Constructor (uint dpi, string format, NSObject [] lods, AGSPoint origin, AGSSpatialReference spatialReference, SizeF tileSize);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSTileKey {

		[Export ("column")]
		int Column { get; set; }

		[Export ("row")]
		int Row { get; set; }

		[Export ("level")]
		int Level { get; set; }

		[Export ("initWithColumn:row:level:")]
		IntPtr Constructor (int c, int r, int l);

		[Static, Export ("tileKeyWithColumn:row:level:")]
		AGSTileKey TileKeyWithColumn (int c, int r, int l);

		[Export ("isEqualToTileKey:")]
		bool IsEqualToTileKey (AGSTileKey key);
	}

	[BaseType (typeof (AGSLayer))]
	public partial interface AGSTiledLayer {

		[Export ("tileInfo", ArgumentSemantic.Retain)]
		AGSTileInfo TileInfo { get; }

		[Export ("convertedScaleForLodScale:")]
		double ConvertedScaleForLodScale (double lodScale);

		[Export ("convertedResolutionForLodResolution:")]
		double ConvertedResolutionForLodResolution (double lodResolution);
	}

	[Category, BaseType (typeof (AGSTiledLayer))]
	public partial interface ForSubclassEyesOnly_AGSTiledLayer {

		[Export ("requestTileForKey:")]
		void RequestTileForKey (AGSTileKey key);

		[Export ("cancelRequestForKey:")]
		void CancelRequestForKey (AGSTileKey key);

		[Export ("setTileData:forKey:")]
		void SetTileData (NSData data, AGSTileKey tilekey);
	}

	[Category, BaseType (typeof (AGSTiledServiceLayer))]
	public partial interface ForSubclassEyesOnly_AGSTiledServiceLayer {

		[Export ("urlForTileKey:")]
		NSUrl UrlForTileKey (AGSTileKey key);
	}

	[BaseType (typeof (AGSTiledServiceLayer))]
	public partial interface AGSTiledMapServiceLayer : AGSCoding, AGSSecuredResource {

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		[Export ("mapServiceInfo", ArgumentSemantic.Retain)]
		AGSMapServiceInfo MapServiceInfo { get; }

		[Export ("credential", ArgumentSemantic.Copy)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("renderNativeResolution")]
		bool RenderNativeResolution { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSUrl url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSUrl url, AGSCredential cred);

		[Export ("initWithMapServiceInfo:")]
		IntPtr Constructor (AGSMapServiceInfo info);

		[Static, Export ("tiledMapServiceLayerWithURL:")]
		NSObject TiledMapServiceLayerWithURL (NSUrl url);

		[Static, Export ("tiledMapServiceLayerWithURL:credential:")]
		NSObject TiledMapServiceLayerWithURL (NSUrl url, AGSCredential cred);

		[Static, Export ("tiledMapServiceLayerWithMapServiceInfo:")]
		NSObject TiledMapServiceLayerWithMapServiceInfo (AGSMapServiceInfo info);

		[Export ("initWithJSON:URL:credential:")]
		IntPtr Constructor (NSDictionary json, NSUrl url, AGSCredential cred);

		[Export ("resubmit")]
		void Resubmit ();

		[Export ("resubmitWithURL:credential:")]
		void ResubmitWithURL (NSUrl url, AGSCredential cred);

		[Export ("checkCurrentScaleVisibilityForSubLayer:")]
		bool CheckCurrentScaleVisibilityForSubLayer (AGSMapServiceLayerInfo msli);
	}

	[BaseType (typeof (AGSTiledServiceLayer))]
	public partial interface AGSOpenStreetMapLayer {

		[Static, Export ("openStreetMapLayer")]
		AGSOpenStreetMapLayer OpenStreetMapLayer();
	}

	[BaseType (typeof (AGSLayer))]
	public partial interface AGSDynamicLayer {

		[Export ("autoRefreshInterval")]
		double AutoRefreshInterval { get; set; }
	}

	[Category, BaseType (typeof (AGSDynamicLayer))]
	public partial interface ForSubclassEyesOnly_AGSDynamicLayer {

		[Export ("requestImageWithWidth:height:envelope:timeExtent:")]
		void RequestImageWithWidth (int width, int height, AGSEnvelope env, AGSTimeExtent timeExtent);

		[Export ("setImageData:forEnvelope:")]
		void SetImageData (NSData data, AGSEnvelope env);

		[Export ("queue", ArgumentSemantic.Retain)]
		NSOperationQueue Queue { get; }

		[Export ("wrapAroundSupported")]
		bool WrapAroundSupported { get; set; }
	}

	[BaseType (typeof (AGSDynamicLayer))]
	public partial interface AGSDynamicMapServiceLayer : AGSCoding, AGSSecuredResource {

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		[Export ("mapServiceInfo", ArgumentSemantic.Retain)]
		AGSMapServiceInfo MapServiceInfo { get; }

		[Export ("credential", ArgumentSemantic.Copy)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("dpi")]
		uint Dpi { get; set; }

		[Export ("imageFormat")]
		AGSImageFormat ImageFormat { get; set; }

		[Export ("transparent")]
		bool Transparent { get; set; }

		[Export ("layerDefinitions", ArgumentSemantic.Copy)]
		AGSLayerDefinition [] LayerDefinitions { get; set; }

		[Export ("visibleLayers", ArgumentSemantic.Copy)]
		AGSMapServiceLayerInfo [] VisibleLayers { get; set; }

		[Export ("layerTimeOptions", ArgumentSemantic.Copy)]
		AGSLayerTimeOptions [] LayerTimeOptions { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSUrl url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSUrl url, AGSCredential cred);

		[Export ("initWithMapServiceInfo:")]
		IntPtr Constructor (AGSMapServiceInfo info);

		[Static, Export ("dynamicMapServiceLayerWithURL:")]
		NSObject DynamicMapServiceLayerWithURL (NSUrl url);

		[Static, Export ("dynamicMapServiceLayerWithURL:credential:")]
		NSObject DynamicMapServiceLayerWithURL (NSUrl url, AGSCredential cred);

		[Static, Export ("dynamicMapServiceLayerWithMapServiceInfo:")]
		NSObject DynamicMapServiceLayerWithMapServiceInfo (AGSMapServiceInfo info);

		[Export ("initWithJSON:URL:credential:")]
		IntPtr Constructor (NSDictionary json, NSUrl url, AGSCredential cred);

		[Export ("resubmit")]
		void Resubmit ();

		[Export ("resubmitWithURL:credential:")]
		void ResubmitWithURL (NSUrl url, AGSCredential cred);

		[Export ("checkCurrentScaleVisibilityForSubLayer:")]
		bool CheckCurrentScaleVisibilityForSubLayer (AGSMapServiceLayerInfo msli);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSLayerDefinition {

		[Export ("layerId")]
		int LayerId { get; set; }

		[Export ("definition", ArgumentSemantic.Copy)]
		string Definition { get; set; }

		[Export ("init")]
		IntPtr Constructor ();

		[Export ("initWithLayerId:definition:")]
		IntPtr Constructor (int layerId, string definition);

		[Static, Export ("layerDefinitionWithLayerId:definition:")]
		NSObject LayerDefinitionWithLayerId (int layerId, string definition);

		[Static, Export ("encodeToJSON:")]
		NSDictionary EncodeToJSON (AGSLayerDefinition [] array);

		[Static, Export ("decodeWithJSON:")]
		AGSLayerDefinition [] DecodeWithJSON (NSDictionary json);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSLayerDelegate {

		[Export ("layerDidLoad:")]
		void LayerDidLoad (AGSLayer layer);

		[Export ("layer:didFailToLoadWithError:")]
		void DidFailToLoadWithError (AGSLayer layer, NSError error);

		[Export ("layer:didInitializeSpatialReferenceStatus:")]
		void DidInitializeSpatialReferenceStatus (AGSLayer layer, bool srStatusValid);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSMapServiceInfo : AGSCoding, AGSSecuredResource {

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		[Export ("copyright", ArgumentSemantic.Copy)]
		string Copyright { get; }

		[Export ("serviceDescription", ArgumentSemantic.Copy)]
		string ServiceDescription { get; }

		[Export ("version")]
		float Version { get; }

		[Export ("units")]
		AGSUnits Units { get; }

		[Export ("layerInfos", ArgumentSemantic.Copy)]
		AGSMapServiceLayerInfo [] LayerInfos { get; }

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; }

		[Export ("fullEnvelope", ArgumentSemantic.Retain)]
		AGSEnvelope FullEnvelope { get; }

		[Export ("initialEnvelope", ArgumentSemantic.Retain)]
		AGSEnvelope InitialEnvelope { get; }

		[Export ("tileInfo", ArgumentSemantic.Retain)]
		AGSTileInfo TileInfo { get; }

		[Export ("singleFusedMapCache")]
		bool SingleFusedMapCache { get; }

		[Export ("credential", ArgumentSemantic.Copy)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("timeInfo", ArgumentSemantic.Retain)]
		AGSTimeInfo TimeInfo { get; }

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSMapServiceInfoDelegate Delegate { get; set; }

		[Export ("tableInfos", ArgumentSemantic.Retain)]
		AGSMapServiceTableInfo [] TableInfos { get; }

		[Export ("minScale")]
		double MinScale { get; }

		[Export ("maxScale")]
		double MaxScale { get; }

		[Export ("initWithURL:error:")]
		IntPtr Constructor (NSUrl url, out NSError error);

		[Static, Export ("mapServiceInfoWithURL:error:")]
		NSObject MapServiceInfoWithURL (NSUrl url, out NSError error);

		[Export ("initWithURL:credential:error:")]
		IntPtr Constructor (NSUrl url, AGSCredential cred, out NSError error);

		[Static, Export ("mapServiceInfoWithURL:credential:error:")]
		NSObject MapServiceInfoWithURL (NSUrl url, AGSCredential cred, out NSError error);

		[Export ("initWithJSON:URL:credential:")]
		IntPtr Constructor (NSDictionary json, NSUrl url, AGSCredential credential);

		[Export ("retrieveLegendInfo")]
		NSOperation RetrieveLegendInfo();
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSMapServiceInfoDelegate {

		[Export ("mapServiceInfo:operationDidRetrieveLegendInfo:")]
		void OperationDidRetrieveLegendInfo (AGSMapServiceInfo mapServiceInfo, NSOperation op);

		[Export ("mapServiceInfo:operation:didFailToRetrieveLegendInfoWithError:")]
		void Operation (AGSMapServiceInfo mapServiceInfo, NSOperation op, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSLayerInfo : AGSCoding {

		[Export ("layerId")]
		uint LayerId { get; }

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("minScale")]
		double MinScale { get; }

		[Export ("maxScale")]
		double MaxScale { get; }

		[Export ("legendImages", ArgumentSemantic.Copy)]
		UIImage [] LegendImages { get; }

		[Export ("legendLabels", ArgumentSemantic.Copy)]
		string [] LegendLabels { get; }
	}

	[BaseType (typeof (AGSLayerInfo))]
	public partial interface AGSMapServiceLayerInfo : AGSCoding {

		[Export ("defaultVisibility")]
		bool DefaultVisibility { get; }

		[Export ("parentLayerID")]
		int ParentLayerID { get; }

		[Export ("subLayerIDs", ArgumentSemantic.Copy)]
		uint [] SubLayerIDs { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSMapServiceTableInfo : AGSCoding {

		[Export ("tableId")]
		uint TableId { get; }

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSTask : AGSSecuredResource {

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		[Export ("credential", ArgumentSemantic.Copy)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("requestCachePolicy")]
		NSURLRequestCachePolicy RequestCachePolicy { get; set; }

		[Export ("timeoutInterval")]
		double TimeoutInterval { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSUrl url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSUrl url, AGSCredential cred);
	}

	[BaseType (typeof (AGSTask))]
	public partial interface AGSGeoprocessor {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSGeoprocessorDelegate Delegate { get; set; }

		[Export ("processSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference ProcessSpatialReference { get; set; }

		[Export ("outputSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference OutputSpatialReference { get; set; }

		[Export ("interval")]
		double Interval { get; set; }

		[Static, Export ("geoprocessorWithURL:")]
		NSObject GeoprocessorWithURL (NSUrl url);

		[Static, Export ("geoprocessorWithURL:credential:")]
		NSObject GeoprocessorWithURL (NSUrl url, AGSCredential cred);

		[Export ("executeWithParameters:")]
		NSOperation ExecuteWithParameters (AGSGPParameterValue [] parameters);

		[Export ("submitJobWithParameters:")]
		NSOperation SubmitJobWithParameters (AGSGPParameterValue [] parameters);

		[Export ("checkStatusForJob:")]
		NSOperation CheckStatusForJob (string jobId);

		[Export ("queryResultData:paramName:")]
		NSOperation QueryResultData (string jobId, string paramName);

		[Export ("queryResultImage:paramName:imageParams:")]
		NSOperation QueryResultImage (string jobId, string paramName, AGSImageParameters imageParams);

		[Export ("queryResultImageLayer:paramName:")]
		NSOperation QueryResultImageLayer (string jobId, string paramName);

		[Export ("cancelJob:")]
		NSOperation CancelJob (string jobId);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSGeoprocessorDelegate {

		[Export ("geoprocessor:operation:didExecuteWithResults:messages:")]
		void Operation (AGSGeoprocessor geoprocessor, NSOperation op, AGSGPParameterValue [] results, AGSGPMessage [] messages);

		[Export ("geoprocessor:operation:didFailExecuteWithError:")]
		void Operation (AGSGeoprocessor geoprocessor, NSOperation op, NSError error);

		[Export ("geoprocessor:operation:jobDidSucceed:")]
		void Operation (AGSGeoprocessor geoprocessor, NSOperation op, AGSGPJobInfo jobInfo);

		[Export ("geoprocessor:operation:didQueryWithResult:forJob:")]
		void Operation (AGSGeoprocessor geoprocessor, NSOperation op, AGSGPParameterValue result, string jobId);

		[Export ("geoprocessor:operation:didQueryWithResultImage:forJob:")]
		void Operation (AGSGeoprocessor geoprocessor, NSOperation op, UIImage image, string jobId);

		[Export ("geoprocessor:operation:didQueryWithResultImageLayer:forJob:")]
		void Operation (AGSGeoprocessor geoprocessor, NSOperation op, AGSGPResultLayer lyr, string jobId);

		[Export ("geoprocessor:operation:ofType:didFailWithError:forJob:")]
		void Operation (AGSGeoprocessor geoprocessor, NSOperation op, AGSGPAsyncOperationType opType, NSError error, string jobId);

		[Export ("geoprocessor:operation:didSubmitJob:")]
		void Operation (AGSGeoprocessor geoprocessor, NSOperation op, AGSGPJobInfo jobInfo);

		[Export ("geoprocessor:willCheckJobStatus:")]
		void WillCheckJobStatus (AGSGeoprocessor geoprocessor, AGSGPJobInfo jobInfo);

		[Export ("geoprocessor:operation:didCheckJobStatus:")]
		void Operation (AGSGeoprocessor geoprocessor, NSOperation op, AGSGPJobInfo jobInfo);

		[Export ("geoprocessor:operation:jobDidFail:")]
		void Operation (AGSGeoprocessor geoprocessor, NSOperation op, AGSGPJobInfo jobInfo);

		[Export ("geoprocessor:operation:didCancelJob:")]
		void Operation (AGSGeoprocessor geoprocessor, NSOperation op, AGSGPJobInfo jobInfo);

		[Export ("geoprocessor:operation:didFailToCancelJob:withError:")]
		void Operation (AGSGeoprocessor geoprocessor, NSOperation op, AGSGPJobInfo jobInfo, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSImageParameters {

		[Export ("bbox", ArgumentSemantic.Retain)]
		AGSEnvelope Bbox { get; set; }

		[Export ("dpi")]
		uint Dpi { get; set; }

		[Export ("format", ArgumentSemantic.Copy)]
		string Format { get; set; }

		[Export ("height")]
		uint Height { get; set; }

		[Export ("imageSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference ImageSpatialReference { get; set; }

		[Export ("layerIds", ArgumentSemantic.Copy)]
		uint [] LayerIds { get; set; }

		[Export ("transparent")]
		bool Transparent { get; set; }

		[Export ("width")]
		uint Width { get; set; }

		[Export ("timeExtent", ArgumentSemantic.Retain)]
		AGSTimeExtent TimeExtent { get; set; }

		[Export ("layerTimeOptions", ArgumentSemantic.Copy)]
		AGSLayerTimeOptions [] LayerTimeOptions { get; set; }

		[Export ("encodeToJSON")]
		NSDictionary EncodeToJSON();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSGPJobInfo {

		[Export ("jobId", ArgumentSemantic.Copy)]
		string JobId { get; }

		[Export ("jobStatus", ArgumentSemantic.Copy)]
		string JobStatus { get; }

		[Export ("messages", ArgumentSemantic.Copy)]
		AGSGPMessage [] Messages { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSGPRasterData : AGSCoding {

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; set; }

		[Export ("format", ArgumentSemantic.Copy)]
		string Format { get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSGPLinearUnit : AGSCoding {

		[Export ("units")]
		AGSUnits Units { get; set; }

		[Export ("distance")]
		double Distance { get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSGPMessage : AGSCoding {

		[Export ("type")]
		AGSGPMessageType Type { get; }

		[Export ("messageDescription", ArgumentSemantic.Copy)]
		string MessageDescription { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSGPParameterValue : AGSCoding {

		[Export ("type")]
		AGSGPParameterType Type { get; }

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("value", ArgumentSemantic.Retain)]
		NSObject Value { get; }

		[Export ("initWithName:type:value:")]
		IntPtr Constructor (string name, AGSGPParameterType type, NSObject value);

		[Static, Export ("parameterWithName:type:value:")]
		NSObject ParameterWithName (string name, AGSGPParameterType type, NSObject value);
	}

	[BaseType (typeof (AGSDynamicLayer))]
	public partial interface AGSGPResultLayer : AGSCoding, AGSSecuredResource {

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		[Export ("credential", ArgumentSemantic.Copy)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("dpi")]
		uint Dpi { get; set; }

		[Export ("imageFormat")]
		AGSImageFormat ImageFormat { get; set; }

		[Export ("transparent")]
		bool Transparent { get; set; }

		[Export ("renderNativeResolution")]
		bool RenderNativeResolution { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSUrl url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSUrl url, AGSCredential cred);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSNADirectionsString : AGSCoding {

		[Export ("value", ArgumentSemantic.Copy)]
		string Value { get; }

		[Export ("type")]
		AGSNADirectionsStringType Type { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSNALayerInfoBase : AGSCoding {

		[Export ("layerName", ArgumentSemantic.Copy)]
		string LayerName { get; }

		[Export ("layerType")]
		AGSNALayerType LayerType { get; }

		[Export ("impedance", ArgumentSemantic.Copy)]
		string Impedance { get; }

		[Export ("restrictions", ArgumentSemantic.Copy)]
		string [] Restrictions { get; }

		[Export ("snapTolerance")]
		uint SnapTolerance { get; }

		[Export ("maxSnapTolerance")]
		uint MaxSnapTolerance { get; }

		[Export ("snapToleranceUnits")]
		AGSUnits SnapToleranceUnits { get; }

		[Export ("ignoreInvalidLocations")]
		bool IgnoreInvalidLocations { get; }

		[Export ("uTurns")]
		AGSNAUTurn UTurns { get; }

		[Export ("accumulateAttributeNames", ArgumentSemantic.Copy)]
		string [] AccumulateAttributeNames { get; }

		[Export ("attributeParameterValues", ArgumentSemantic.Copy)]
		string [] AttributeParameterValues { get; }

		[Export ("outputSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference OutputSpatialReference { get; }

		[Export ("useHierarchy")]
		bool UseHierarchy { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSNAMessage : AGSCoding {

		[Export ("messageDescription", ArgumentSemantic.Copy)]
		string MessageDescription { get; }

		[Export ("type")]
		AGSNAMessageType Type { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSNALayerDefinition : AGSCoding {

		[Export ("geometry", ArgumentSemantic.Retain)]
		AGSGeometry Geometry { get; set; }

		[Export ("layerName", ArgumentSemantic.Copy)]
		string LayerName { get; set; }

		[Export ("spatialRelationship")]
		AGSSpatialRelationship SpatialRelationship { get; set; }

		[Export ("where", ArgumentSemantic.Copy)]
		string Where { get; set; }

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		[Export ("query", ArgumentSemantic.Retain)]
		AGSQuery Query { get; }

		[Export ("initWithLayerName:geometry:spatialRelationship:where:")]
		IntPtr Constructor (string layerName, AGSGeometry geometry, AGSSpatialRelationship spatialRelationship, string where);

		[Export ("initWithLayerName:where:")]
		IntPtr Constructor (string layerName, string where);

		[Export ("initWithURL:query:")]
		IntPtr Constructor (NSUrl url, AGSQuery query);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSDirectionSet : AGSCoding {

		[Export ("graphics", ArgumentSemantic.Copy)]
		AGSDirectionGraphic [] Graphics { get; }

		[Export ("extent", ArgumentSemantic.Retain)]
		AGSEnvelope Extent { get; }

		[Export ("mergedGeometry", ArgumentSemantic.Retain)]
		AGSPolyline MergedGeometry { get; }

		[Export ("routeId", ArgumentSemantic.Copy)]
		string RouteId { get; }

		[Export ("routeName", ArgumentSemantic.Copy)]
		string RouteName { get; }

		[Export ("totalDriveTime")]
		double TotalDriveTime { get; }

		[Export ("totalLength")]
		double TotalLength { get; }

		[Export ("totalTime")]
		double TotalTime { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSRouteTaskParameters : AGSCoding {

		[Export ("accumulateAttributeNames", ArgumentSemantic.Copy)]
		string [] AccumulateAttributeNames { get; set; }

		[Export ("attributeParameterValues", ArgumentSemantic.Copy)]
		string [] AttributeParameterValues { get; set; }

		[Export ("directionsLanguage", ArgumentSemantic.Copy)]
		string DirectionsLanguage { get; set; }

		[Export ("directionsLengthUnits")]
		AGSNAUnit DirectionsLengthUnits { get; set; }

		[Export ("directionsStyleName", ArgumentSemantic.Copy)]
		string DirectionsStyleName { get; set; }

		[Export ("directionsTimeAttributeName", ArgumentSemantic.Copy)]
		string DirectionsTimeAttributeName { get; set; }

		[Export ("doNotLocateOnRestrictedElements")]
		bool DoNotLocateOnRestrictedElements { get; set; }

		[Export ("findBestSequence")]
		bool FindBestSequence { get; set; }

		[Export ("ignoreInvalidLocations")]
		bool IgnoreInvalidLocations { get; set; }

		[Export ("impedanceAttributeName", ArgumentSemantic.Copy)]
		string ImpedanceAttributeName { get; set; }

		[Export ("outputGeometryPrecision")]
		double OutputGeometryPrecision { get; set; }

		[Export ("outputGeometryPrecisionUnits")]
		AGSUnits OutputGeometryPrecisionUnits { get; set; }

		[Export ("outputLines")]
		AGSNAOutputLine OutputLines { get; set; }

		[Export ("outSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("preserveFirstStop")]
		bool PreserveFirstStop { get; set; }

		[Export ("preserveLastStop")]
		bool PreserveLastStop { get; set; }

		[Export ("restrictionAttributeNames", ArgumentSemantic.Copy)]
		string [] RestrictionAttributeNames { get; set; }

		[Export ("uTurns")]
		AGSNAUTurn UTurns { get; set; }

		[Export ("returnPointBarriers")]
		bool ReturnPointBarriers { get; set; }

		[Export ("returnDirections")]
		bool ReturnDirections { get; set; }

		[Export ("returnPolygonBarriers")]
		bool ReturnPolygonBarriers { get; set; }

		[Export ("returnPolylineBarriers")]
		bool ReturnPolylineBarriers { get; set; }

		[Export ("returnRouteGraphics")]
		bool ReturnRouteGraphics { get; set; }

		[Export ("returnStopGraphics")]
		bool ReturnStopGraphics { get; set; }

		[Export ("startTime", ArgumentSemantic.Retain)]
		NSDate StartTime { get; set; }

		[Export ("useHierarchy")]
		bool UseHierarchy { get; set; }

		[Export ("useTimeWindows")]
		bool UseTimeWindows { get; set; }

		[Export ("directionsOutputType")]
		AGSNADirectionsOutputType DirectionsOutputType { get; set; }

		[Static, Export ("routeTaskParameters")]
		AGSRouteTaskParameters RouteTaskParameters();

		[Export ("setStopsWithFeatures:")]
		void SetStopsWithFeatures(AGSStopGraphic [] stopFeatures);

		[Export ("setStopsWithLayerDefinition:")]
		void SetStopsWithLayerDefinition(AGSNALayerDefinition layerDefinition);

		[Export ("setPointBarriersWithFeatures:")]
		void SetPointBarriersWithFeatures(AGSGraphic [] features);

		[Export ("setPointBarriersWithLayerDefinition:")]
		void SetPointBarriersWithLayerDefinition (AGSNALayerDefinition layerDefinition);

		[Export ("setPolylineBarriersWithFeatures:")]
		void SetPolylineBarriersWithFeatures (AGSGraphic [] features);

		[Export ("setPolylineBarriersWithLayerDefinition:")]
		void SetPolylineBarriersWithLayerDefinition (AGSNALayerDefinition layerDefinition);

		[Export ("setPolygonBarriersWithFeatures:")]
		void SetPolygonBarriersWithFeatures (AGSGraphic [] features);

		[Export ("setPolygonBarriersWithLayerDefinition:")]
		void SetPolygonBarriersWithLayerDefinition (AGSNALayerDefinition layerDefinition);
	}

	[BaseType (typeof (AGSTask))]
	public partial interface AGSRouteTask {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSRouteTaskDelegate Delegate { get; set; }

		[Static, Export ("routeTaskWithURL:")]
		NSObject RouteTaskWithURL (NSUrl url);

		[Static, Export ("routeTaskWithURL:credential:")]
		NSObject RouteTaskWithURL (NSUrl url, AGSCredential cred);

		[Export ("solveWithParameters:")]
		NSOperation SolveWithParameters (AGSRouteTaskParameters routeParams);

		[Export ("retrieveDefaultRouteTaskParameters")]
		NSOperation RetrieveDefaultRouteTaskParameters ();
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSRouteTaskDelegate {

		[Export ("routeTask:operation:didSolveWithResult:")]
		void Operation (AGSRouteTask routeTask, NSOperation op, AGSRouteTaskResult routeTaskResult);

		[Export ("routeTask:operation:didFailSolveWithError:")]
		void Operation (AGSRouteTask routeTask, NSOperation op, NSError error);

		[Export ("routeTask:operation:didRetrieveDefaultRouteTaskParameters:")]
		void Operation (AGSRouteTask routeTask, NSOperation op, AGSRouteTaskParameters routeParams);

		[Export ("routeTask:operation:didFailToRetrieveDefaultRouteTaskParametersWithError:")]
		void Operation (AGSRouteTask routeTask, NSOperation op, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSRouteTaskResult : AGSCoding {

		[Export ("routeResults", ArgumentSemantic.Copy)]
		AGSRouteResult [] RouteResults { get; }

		[Export ("pointBarriers", ArgumentSemantic.Copy)]
		AGSGraphic [] PointBarriers { get; }

		[Export ("polylineBarriers", ArgumentSemantic.Copy)]
		AGSGraphic [] PolylineBarriers { get; }

		[Export ("polygonBarriers", ArgumentSemantic.Copy)]
		AGSGraphic [] PolygonBarriers { get; }

		[Export ("messages", ArgumentSemantic.Copy)]
		AGSNAMessage [] Messages { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSRouteResult {

		[Export ("directions", ArgumentSemantic.Retain)]
		AGSDirectionSet Directions { get; }

		[Export ("routeGraphic", ArgumentSemantic.Retain)]
		AGSGraphic RouteGraphic { get; }

		[Export ("routeName", ArgumentSemantic.Copy)]
		string RouteName { get; }

		[Export ("stopGraphics", ArgumentSemantic.Copy)]
		AGSStopGraphic [] StopGraphics { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSServiceAreaTaskParameters : AGSCoding {

		[Export ("accumulateAttributeNames", ArgumentSemantic.Copy)]
		string [] AccumulateAttributeNames { get; set; }

		[Export ("attributeParameterValues", ArgumentSemantic.Copy)]
		NSDictionary [] AttributeParameterValues { get; set; }

		[Export ("defaultBreaks", ArgumentSemantic.Copy)]
		int [] DefaultBreaks { get; set; }

		[Export ("excludeSourcesFromPolygons", ArgumentSemantic.Copy)]
		string [] ExcludeSourcesFromPolygons { get; set; }

		[Export ("facilities", ArgumentSemantic.Retain)]
		NSObject Facilities { get; set; }

		[Export ("impedanceAttributeName", ArgumentSemantic.Copy)]
		string ImpedanceAttributeName { get; set; }

		[Export ("mergeSimilarPolygonRanges")]
		bool MergeSimilarPolygonRanges { get; set; }

		[Export ("outputGeometryPrecision")]
		double OutputGeometryPrecision { get; set; }

		[Export ("outputGeometryPrecisionUnits")]
		AGSUnits OutputGeometryPrecisionUnits { get; set; }

		[Export ("outputLines")]
		AGSNAOutputLine OutputLines { get; set; }

		[Export ("outputPolygons")]
		AGSNAOutputPolygon OutputPolygons { get; set; }

		[Export ("outSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("overlapLines")]
		bool OverlapLines { get; set; }

		[Export ("overlapPolygons")]
		bool OverlapPolygons { get; set; }

		[Export ("pointBarriers", ArgumentSemantic.Retain)]
		NSObject PointBarriers { get; set; }

		[Export ("polygonBarriers", ArgumentSemantic.Retain)]
		NSObject PolygonBarriers { get; set; }

		[Export ("polylineBarriers", ArgumentSemantic.Retain)]
		NSObject PolylineBarriers { get; set; }

		[Export ("restrictionAttributeNames", ArgumentSemantic.Copy)]
		string [] RestrictionAttributeNames { get; set; }

		[Export ("uTurns")]
		AGSNAUTurn UTurns { get; set; }

		[Export ("returnFacilities")]
		bool ReturnFacilities { get; set; }

		[Export ("returnPointBarriers")]
		bool ReturnPointBarriers { get; set; }

		[Export ("returnPolygonBarriers")]
		bool ReturnPolygonBarriers { get; set; }

		[Export ("returnPolylineBarriers")]
		bool ReturnPolylineBarriers { get; set; }

		[Export ("splitLinesAtBreaks")]
		bool SplitLinesAtBreaks { get; set; }

		[Export ("splitPolygonsAtBreaks")]
		bool SplitPolygonsAtBreaks { get; set; }

		[Export ("travelDirection")]
		AGSNATravelDirection TravelDirection { get; set; }

		[Export ("trimOuterPolygon")]
		bool TrimOuterPolygon { get; set; }

		[Export ("trimPolygonDistance")]
		double TrimPolygonDistance { get; set; }

		[Export ("trimPolygonDistanceUnits")]
		AGSUnits TrimPolygonDistanceUnits { get; set; }

		[Export ("timeOfDay", ArgumentSemantic.Retain)]
		NSDate TimeOfDay { get; set; }

		[Export ("useHierarchy")]
		bool UseHierarchy { get; set; }

		[Static, Export ("serviceAreaTaskParameters")]
		AGSServiceAreaTaskParameters ServiceAreaTaskParameters ();

		[Export ("setFacilitiesWithFeatures:")]
		void SetFacilitiesWithFeatures (AGSGraphic [] features);

		[Export ("setFacilitiesWithLayerDefinition:")]
		void SetSetFacilitiesWithLayerDefinition (AGSNALayerDefinition layerDefinition);

		[Export ("setPointBarriersWithFeatures:")]
		void SetPointBarriersWithFeatures (AGSGraphic [] features);

		[Export ("setPointBarriersWithLayerDefinition:")]
		void SetPointBarriersWithLayerDefinition (AGSNALayerDefinition layerDefinition);

		[Export ("setPolylineBarriersWithFeatures:")]
		void SetPolylineBarriersWithFeatures (AGSGraphic [] features);

		[Export ("setPolylineBarriersWithLayerDefinition:")]
		void SetPolylineBarriersWithLayerDefinition (AGSNALayerDefinition layerDefinition);

		[Export ("setPolygonBarriersWithFeatures:")]
		void SetPolygonBarriersWithFeatures (AGSGraphic [] features);

		[Export ("setPolygonBarriersWithLayerDefinition:")]
		void SetPolygonBarriersWithLayerDefinition (AGSNALayerDefinition layerDefinition);
	}

	[BaseType (typeof (AGSTask))]
	public partial interface AGSServiceAreaTask {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSServiceAreaTaskDelegate Delegate { get; set; }

		[Static, Export ("serviceAreaTaskWithURL:")]
		NSObject ServiceAreaTaskWithURL (NSUrl url);

		[Static, Export ("serviceAreaTaskWithURL:credential:")]
		NSObject ServiceAreaTaskWithURL (NSUrl url, AGSCredential cred);

		[Export ("solveServiceAreaWithParameters:")]
		NSOperation SolveServiceAreaWithParameters (AGSServiceAreaTaskParameters serviceAreaParams);

		[Export ("retrieveDefaultServiceAreaTaskParameters")]
		NSOperation RetrieveDefaultServiceAreaTaskParameters ();
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSServiceAreaTaskDelegate {

		[Export ("serviceAreaTask:operation:didSolveServiceAreaWithResult:")]
		void Operation (AGSServiceAreaTask serviceAreaTask, NSOperation op, AGSServiceAreaTaskResult serviceAreaTaskResult);

		[Export ("serviceAreaTask:operation:didFailSolveWithError:")]
		void Operation (AGSServiceAreaTask serviceAreaTask, NSOperation op, NSError error);

		[Export ("serviceAreaTask:operation:didRetrieveDefaultServiceAreaTaskParameters:")]
		void Operation (AGSServiceAreaTask serviceAreaTask, NSOperation op, AGSServiceAreaTaskParameters serviceAreaParams);

		[Export ("serviceAreaTask:operation:didFailToRetrieveDefaultServiceAreaTaskParametersWithError:")]
		void Operation (AGSServiceAreaTask serviceAreaTask, NSOperation op, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSServiceAreaTaskResult : AGSCoding {

		[Export ("facilities", ArgumentSemantic.Copy)]
		AGSGraphic [] Facilities { get; }

		[Export ("messages", ArgumentSemantic.Copy)]
		AGSNAMessage [] Messages { get; }

		[Export ("pointBarriers", ArgumentSemantic.Copy)]
		AGSGraphic [] PointBarriers { get; }

		[Export ("polygonBarriers", ArgumentSemantic.Copy)]
		AGSGraphic [] PolygonBarriers { get; }

		[Export ("polylineBarriers", ArgumentSemantic.Copy)]
		AGSGraphic [] PolylineBarriers { get; }

		[Export ("serviceAreaPolygons", ArgumentSemantic.Copy)]
		AGSGraphic [] ServiceAreaPolygons { get; }

		[Export ("serviceAreaPolylines", ArgumentSemantic.Copy)]
		AGSGraphic [] ServiceAreaPolylines { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSClosestFacilityResult {

		[Export ("directions", ArgumentSemantic.Retain)]
		AGSDirectionSet Directions { get; }

		[Export ("routeGraphic", ArgumentSemantic.Retain)]
		AGSGraphic RouteGraphic { get; }

		[Export ("routeName", ArgumentSemantic.Copy)]
		string RouteName { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSClosestFacilityTaskParameters : AGSCoding {

		[Export ("accumulateAttributeNames", ArgumentSemantic.Copy)]
		string [] AccumulateAttributeNames { get; set; }

		[Export ("attributeParameterValues", ArgumentSemantic.Copy)]
		NSDictionary [] AttributeParameterValues { get; set; }

		[Export ("defaultCutoffValue")]
		double DefaultCutoffValue { get; set; }

		[Export ("defaultTargetFacilityCount")]
		int DefaultTargetFacilityCount { get; set; }

		[Export ("directionsLanguage", ArgumentSemantic.Copy)]
		string DirectionsLanguage { get; set; }

		[Export ("directionsLengthUnits")]
		AGSNAUnit DirectionsLengthUnits { get; set; }

		[Export ("directionsStyleName", ArgumentSemantic.Copy)]
		string DirectionsStyleName { get; set; }

		[Export ("directionsTimeAttributeName", ArgumentSemantic.Copy)]
		string DirectionsTimeAttributeName { get; set; }

		[Export ("impedanceAttributeName", ArgumentSemantic.Copy)]
		string ImpedanceAttributeName { get; set; }

		[Export ("outputGeometryPrecision")]
		double OutputGeometryPrecision { get; set; }

		[Export ("outputGeometryPrecisionUnits")]
		AGSUnits OutputGeometryPrecisionUnits { get; set; }

		[Export ("outputLines")]
		AGSNAOutputLine OutputLines { get; set; }

		[Export ("outSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("restrictionAttributeNames", ArgumentSemantic.Copy)]
		string [] RestrictionAttributeNames { get; set; }

		[Export ("uTurns")]
		AGSNAUTurn UTurns { get; set; }

		[Export ("returnPointBarriers")]
		bool ReturnPointBarriers { get; set; }

		[Export ("returnDirections")]
		bool ReturnDirections { get; set; }

		[Export ("returnFacilities")]
		bool ReturnFacilities { get; set; }

		[Export ("returnIncidents")]
		bool ReturnIncidents { get; set; }

		[Export ("returnPolygonBarriers")]
		bool ReturnPolygonBarriers { get; set; }

		[Export ("returnPolylineBarriers")]
		bool ReturnPolylineBarriers { get; set; }

		[Export ("returnRouteGraphics")]
		bool ReturnRouteGraphics { get; set; }

		[Export ("travelDirection")]
		AGSNATravelDirection TravelDirection { get; set; }

		[Export ("useHierarchy")]
		bool UseHierarchy { get; set; }

		[Export ("timeOfDay", ArgumentSemantic.Retain)]
		NSDate TimeOfDay { get; set; }

		[Export ("timeOfDayUsage")]
		AGSNATimeOfDayUse TimeOfDayUsage { get; set; }

		[Export ("directionsOutputType")]
		AGSNADirectionsOutputType DirectionsOutputType { get; set; }

		[Static, Export ("closestFacilityTaskParameters")]
		AGSClosestFacilityTaskParameters ClosestFacilityTaskParameters ();

		[Export ("setFacilitiesWithFeatures:")]
		void SetFacilitiesWithFeatures (AGSGraphic [] features);

		[Export ("setFacilitiesWithLayerDefinition:")]
		void SetFacilitiesWithLayerDefinition (AGSNALayerDefinition layerDefinition);

		[Export ("setIncidentsWithFeatures:")]
		void SetIncidentsWithFeatures (AGSGraphic [] features);

		[Export ("setIncidentsWithLayerDefinition:")]
		void SetIncidentsWithLayerDefinition (AGSNALayerDefinition layerDefinition);

		[Export ("setPointBarriersWithFeatures:")]
		void SetPointBarriersWithFeatures (AGSGraphic [] features);

		[Export ("setPointBarriersWithLayerDefinition:")]
		void SetPointBarriersWithLayerDefinition (AGSNALayerDefinition layerDefinition);

		[Export ("setPolylineBarriersWithFeatures:")]
		void SetPolylineBarriersWithFeatures (AGSGraphic [] features);

		[Export ("setPolylineBarriersWithLayerDefinition:")]
		void SetPolylineBarriersWithLayerDefinition (AGSNALayerDefinition layerDefinition);

		[Export ("setPolygonBarriersWithFeatures:")]
		void SetPolygonBarriersWithFeatures (AGSGraphic [] features);

		[Export ("setPolygonBarriersWithLayerDefinition:")]
		void SetPolygonBarriersWithLayerDefinition (AGSNALayerDefinition layerDefinition);
	}

	[BaseType (typeof (AGSTask))]
	public partial interface AGSClosestFacilityTask {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSClosestFacilityTaskDelegate Delegate { get; set; }

		[Static, Export ("closestFacilityTaskWithURL:")]
		NSObject ClosestFacilityTaskWithURL (NSUrl url);

		[Static, Export ("closestFacilityTaskWithURL:credential:")]
		NSObject ClosestFacilityTaskWithURL (NSUrl url, AGSCredential cred);

		[Export ("solveClosestFacilityWithParameters:")]
		NSOperation SolveClosestFacilityWithParameters (AGSClosestFacilityTaskParameters closestFacilityParams);

		[Export ("retrieveDefaultClosestFacilityTaskParameters")]
		NSOperation RetrieveDefaultClosestFacilityTaskParameters();
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSClosestFacilityTaskDelegate {

		[Export ("closestFacilityTask:operation:didSolveClosestFacilityWithResult:")]
		void Operation (AGSClosestFacilityTask closestFacilityTask, NSOperation op, AGSClosestFacilityTaskResult closestFacilityTaskResult);

		[Export ("closestFacilityTask:operation:didFailSolveWithError:")]
		void Operation (AGSClosestFacilityTask closestFacilityTask, NSOperation op, NSError error);

		[Export ("closestFacilityTask:operation:didRetrieveDefaultClosestFacilityTaskParameters:")]
		void Operation (AGSClosestFacilityTask closestFacilityTask, NSOperation op, AGSClosestFacilityTaskParameters closestFacilityParams);

		[Export ("closestFacilityTask:operation:didFailToRetrieveDefaultClosestFacilityTaskParametersWithError:")]
		void Operation (AGSClosestFacilityTask closestFacilityTask, NSOperation op, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSClosestFacilityTaskResult : AGSCoding {

		[Export ("closestFacilityResults", ArgumentSemantic.Copy)]
		AGSClosestFacilityResult [] ClosestFacilityResults { get; }

		[Export ("facilities", ArgumentSemantic.Copy)]
		AGSGraphic [] Facilities { get; }

		[Export ("incidents", ArgumentSemantic.Copy)]
		AGSGraphic [] Incidents { get; }

		[Export ("messages", ArgumentSemantic.Copy)]
		AGSNAMessage [] Messages { get; }

		[Export ("pointBarriers", ArgumentSemantic.Copy)]
		AGSGraphic [] PointBarriers { get; }

		[Export ("polygonBarriers", ArgumentSemantic.Copy)]
		AGSGraphic [] PolygonBarriers { get; }

		[Export ("polylineBarriers", ArgumentSemantic.Copy)]
		AGSGraphic [] PolylineBarriers { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSMosaicRule : AGSCoding {

		[Export ("ascending")]
		bool Ascending { get; set; }

		[Export ("lockRasterIds", ArgumentSemantic.Copy)]
		int [] LockRasterIds { get; set; }

		[Export ("method")]
		AGSMosaicMethod Method { get; set; }

		[Export ("objectIds", ArgumentSemantic.Copy)]
		int [] ObjectIds { get; set; }

		[Export ("operation")]
		AGSMosaicOperationType Operation { get; set; }

		[Export ("sortField", ArgumentSemantic.Copy)]
		string SortField { get; set; }

		[Export ("sortValue", ArgumentSemantic.Copy)]
		string SortValue { get; set; }

		[Export ("viewpoint", ArgumentSemantic.Retain)]
		AGSPoint Viewpoint { get; set; }

		[Export ("where", ArgumentSemantic.Copy)]
		string Where { get; set; }
	}

	[BaseType (typeof (AGSTask))]
	public partial interface AGSImageServiceIdentifyTask {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSImageServiceIdentifyDelegate Delegate { get; set; }

		[Export ("identifyWithParameters:")]
		NSOperation IdentifyWithParameters (AGSImageServiceIdentifyParameters identifyParams);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSImageServiceIdentifyDelegate {

		[Export ("imageServiceIdentifyTask:operation:didIdentifyWithResult:")]
		void Operation (AGSImageServiceIdentifyTask identifyTask, NSOperation op, AGSImageServiceIdentifyResult result);

		[Export ("imageServiceIdentifyTask:operation:didFailToIdentifyWithError:")]
		void Operation (AGSImageServiceIdentifyTask identifyTask, NSOperation op, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSImageServiceIdentifyResult : AGSCoding {

		[Export ("catalogItems", ArgumentSemantic.Retain)]
		AGSFeatureSet CatalogItems { get; }

		[Export ("catalogItemVisibilities", ArgumentSemantic.Copy)]
		double [] CatalogItemVisibilities { get; }

		[Export ("location", ArgumentSemantic.Retain)]
		AGSPoint Location { get; }

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("objectId", ArgumentSemantic.Retain)]
		NSNumber ObjectId { get; }

		[Export ("properties", ArgumentSemantic.Copy)]
		NSDictionary Properties { get; }

		[Export ("value", ArgumentSemantic.Copy)]
		string Value { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSImageServiceIdentifyParameters : AGSCoding {

		[Export ("geometry", ArgumentSemantic.Retain)]
		AGSGeometry Geometry { get; set; }

		[Export ("mosaicRule", ArgumentSemantic.Retain)]
		AGSMosaicRule MosaicRule { get; set; }

		[Export ("pixelSizeX")]
		double PixelSizeX { get; set; }

		[Export ("pixelSizeY")]
		double PixelSizeY { get; set; }

		[Static, Export ("imageServiceIdentifyParameters")]
		NSObject ImageServiceIdentifyParameters();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSImageServiceInfo : AGSCoding {

		[Export ("serviceDescription", ArgumentSemantic.Copy)]
		string ServiceDescription { get; }

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("extent", ArgumentSemantic.Retain)]
		AGSEnvelope Extent { get; }

		[Export ("pixelSizeX")]
		double PixelSizeX { get; }

		[Export ("pixelSizeY")]
		double PixelSizeY { get; }

		[Export ("bandCount")]
		int BandCount { get; }

		[Export ("pixelType", ArgumentSemantic.Copy)]
		string PixelType { get; }

		[Export ("minPixelSize")]
		double MinPixelSize { get; }

		[Export ("maxPixelSize")]
		double MaxPixelSize { get; }

		[Export ("copyrightText", ArgumentSemantic.Copy)]
		string CopyrightText { get; }

		[Export ("serviceDataType", ArgumentSemantic.Copy)]
		string ServiceDataType { get; }

		[Export ("minValues", ArgumentSemantic.Copy)]
		double [] MinValues { get; }

		[Export ("maxValues", ArgumentSemantic.Copy)]
		double [] MaxValues { get; }

		[Export ("meanValues", ArgumentSemantic.Copy)]
		double [] MeanValues { get; }

		[Export ("stdvValues", ArgumentSemantic.Copy)]
		double [] StdvValues { get; }

		[Export ("version")]
		float Version { get; }

		[Export ("timeInfo", ArgumentSemantic.Retain)]
		AGSTimeInfo TimeInfo { get; }

		[Export ("objectIdField", ArgumentSemantic.Copy)]
		string ObjectIdField { get; }

		[Export ("fields", ArgumentSemantic.Copy)]
		AGSField [] Fields { get; }
	}

	[BaseType (typeof (AGSDynamicLayer))]
	public partial interface AGSImageServiceLayer : AGSCoding, AGSSecuredResource {

		[Export ("URL", ArgumentSemantic.Retain)]
		NSUrl URL { get; }

		[Export ("imageServiceInfo", ArgumentSemantic.Retain)]
		AGSImageServiceInfo ImageServiceInfo { get; }

		[Export ("compressionQuality")]
		uint CompressionQuality { get; set; }

		[Export ("bandIds", ArgumentSemantic.Copy)]
		int [] BandIds { get; set; }

		[Export ("credential", ArgumentSemantic.Copy)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("renderingRule", ArgumentSemantic.Retain)]
		AGSRasterFunction RenderingRule { get; set; }

		[Export ("noData")]
		uint NoData { get; set; }

		[Export ("format")]
		AGSImageFormat Format { get; set; }

		[Export ("interpolation")]
		AGSInterpolation Interpolation { get; set; }

		[Export ("mosaicRule", ArgumentSemantic.Retain)]
		AGSMosaicRule MosaicRule { get; set; }

		[Export ("renderNativeResolution")]
		bool RenderNativeResolution { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSUrl url);

		[Static, Export ("imageServiceLayerWithURL:")]
		NSObject ImageServiceLayerWithURL (NSUrl url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSUrl url, AGSCredential cred);

		[Static, Export ("imageServiceLayerWithURL:credential:")]
		NSObject ImageServiceLayerWithURL (NSUrl url, AGSCredential cred);

		[Export ("initWithJSON:URL:credential:")]
		IntPtr Constructor (NSDictionary json, NSUrl url, AGSCredential cred);

		[Export ("resubmit")]
		void Resubmit ();

		[Export ("resubmitWithURL:credential:")]
		void ResubmitWithURL (NSUrl url, AGSCredential cred);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSRasterFunction : AGSCoding {

		[Export ("type")]
		AGSRasterFunctionType Type { get; set; }

		[Export ("arguments", ArgumentSemantic.Retain)]
		NSMutableDictionary Arguments { get; set; }
	}

	[BaseType (typeof (AGSDynamicLayer))]
	public partial interface AGSWMSLayer : AGSSecuredResource {

		[Export ("version", ArgumentSemantic.Copy)]
		string Version { get; }

		[Export ("copyright", ArgumentSemantic.Copy)]
		string Copyright { get; }

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; }

		[Export ("layerInfos", ArgumentSemantic.Copy)]
		AGSWMSLayerInfo [] LayerInfos { get; }

		[Export ("credential", ArgumentSemantic.Copy)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("imageFormat")]
		AGSImageFormat ImageFormat { get; set; }

		[Export ("transparent")]
		bool Transparent { get; set; }

		[Export ("visibleLayers", ArgumentSemantic.Copy)]
		string [] VisibleLayers { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSUrl url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSUrl url, AGSCredential cred);

		[Static, Export ("wmsLayerWithURL:")]
		AGSWMSLayer WmsLayerWithURL (NSUrl url);

		[Static, Export ("wmsLayerWithURL:credential:")]
		AGSWMSLayer WmsLayerWithURL (NSUrl url, AGSCredential cred);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSWMSLayerInfo {

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("title", ArgumentSemantic.Copy)]
		string Title { get; }

		[Export ("extent", ArgumentSemantic.Retain)]
		AGSEnvelope Extent { get; }

		[Export ("subLayers", ArgumentSemantic.Copy)]
		AGSWMSLayerInfo [] SubLayers { get; }
	}

	[BaseType (typeof (AGSTiledServiceLayer))]
	public partial interface AGSBingMapLayer {

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; }

		[Export ("fullEnvelope", ArgumentSemantic.Retain)]
		AGSEnvelope FullEnvelope { get; }

		[Export ("tileInfo", ArgumentSemantic.Retain)]
		AGSTileInfo TileInfo { get; }

		[Export ("appID", ArgumentSemantic.Copy)]
		string AppID { get; }

		[Export ("style")]
		AGSBingMapLayerStyle Style { get; set; }

		[Export ("locale", ArgumentSemantic.Retain)]
		NSLocale Locale { get; set; }

		[Export ("initWithAppID:style:")]
		IntPtr Constructor (string appID, AGSBingMapLayerStyle style);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSBingMapLayerMetadata : AGSCoding {

		[Export ("imageUri", ArgumentSemantic.Copy)]
		string ImageUri { get; }

		[Export ("subDomains", ArgumentSemantic.Copy)]
		string [] SubDomains { get; }

		[Export ("zoomRangeFrom")]
		int ZoomRangeFrom { get; }

		[Export ("zoomRangeTo")]
		int ZoomRangeTo { get; }
	}

	[BaseType (typeof (AGSTiledLayer))]
	public partial interface AGSLocalTiledLayer {

		[Export ("cachePath", ArgumentSemantic.Copy)]
		string CachePath { get; }

		[Export ("thumbnail", ArgumentSemantic.Retain)]
		UIImage Thumbnail { get; }

		[Export ("renderNativeResolution")]
		bool RenderNativeResolution { get; set; }

		[Export ("layerInfos", ArgumentSemantic.Copy)]
		AGSLayerInfo [] LayerInfos { get; }

		[Export ("initWithName:")]
		IntPtr Constructor (string name);

		[Static, Export ("localTiledLayerWithName:")]
		AGSLocalTiledLayer LocalTiledLayerWithName (string name);

		[Export ("initWithPath:")]
		IntPtr Constructor (string fullPath);

		[Static, Export ("localTiledLayerWithPath:")]
		AGSLocalTiledLayer LocalTiledLayerWithPath (string fullPath);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSLOD : AGSCoding {

		[Export ("level")]
		uint Level { get; }

		[Export ("resolution")]
		double Resolution { get; }

		[Export ("scale")]
		double Scale { get; }

		[Export ("startTileRow")]
		uint StartTileRow { get; set; }

		[Export ("endTileRow")]
		uint EndTileRow { get; set; }

		[Export ("startTileColumn")]
		uint StartTileColumn { get; set; }

		[Export ("endTileColumn")]
		uint EndTileColumn { get; set; }

		[Export ("initWithLevel:resolution:scale:")]
		IntPtr Constructor (uint level, double resolution, double scale);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSLayerTimeOptions : AGSCoding {

		[Export ("useTime")]
		bool UseTime { get; set; }

		[Export ("timeDataCumulative")]
		bool TimeDataCumulative { get; set; }

		[Export ("timeOffset")]
		double TimeOffset { get; set; }

		[Export ("timeOffsetUnits")]
		AGSTimeIntervalUnits TimeOffsetUnits { get; set; }

		[Export ("layerId")]
		uint LayerId { get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSTimeExtent {

		[Export ("start", ArgumentSemantic.Copy)]
		NSDate Start { get; }

		[Export ("end", ArgumentSemantic.Copy)]
		NSDate End { get; }

		[Export ("initWithStart:end:")]
		IntPtr Constructor (NSDate start, NSDate end);

		[Export ("isEqualToTimeExtent:")]
		bool IsEqualToTimeExtent (AGSTimeExtent timeExtent);

		[Export ("timeExtentByOffset:units:")]
		AGSTimeExtent TimeExtentByOffset (int offsetValue, AGSTimeIntervalUnits units);

		[Static, Export ("intersectionOfTimeExtent:andTimeExtent:")]
		AGSTimeExtent IntersectionOfTimeExtent (AGSTimeExtent timeExtent1, AGSTimeExtent timeExtent2);

		[Static, Export ("timeExtentWithStart:end:")]
		AGSTimeExtent TimeExtentWithStart (NSDate start, NSDate end);

		[Static, Export ("dateByOffsettingDate:offset:units:")]
		NSDate DateByOffsettingDate (NSDate date, int offsetValue, AGSTimeIntervalUnits units);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSTimeInfo : AGSCoding {

		[Export ("startTimeField", ArgumentSemantic.Copy)]
		string StartTimeField { get; }

		[Export ("endTimeField", ArgumentSemantic.Copy)]
		string EndTimeField { get; }

		[Export ("trackIdField", ArgumentSemantic.Copy)]
		string TrackIdField { get; }

		[Export ("timeExtent", ArgumentSemantic.Retain)]
		AGSTimeExtent TimeExtent { get; }

		[Export ("timeReference", ArgumentSemantic.Retain)]
		AGSTimeReference TimeReference { get; }

		[Export ("timeInterval")]
		double TimeInterval { get; }

		[Export ("timeIntervalUnits")]
		AGSTimeIntervalUnits TimeIntervalUnits { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSTimeReference : AGSCoding {

		[Export ("timeZone", ArgumentSemantic.Copy)]
		NSTimeZone TimeZone { get; set; }

		[Export ("respectsDaylightSaving")]
		bool RespectsDaylightSaving { get; set; }
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSMapViewTouchDelegate {

		[Notification, Field ("AGSMapViewDidEndZoomingNotification")]
		NSString AGSMapViewDidEndZoomingNotification { get; }

		[Notification, Field ("AGSMapViewDidEndPanningNotification")]
		NSString AGSMapViewDidEndPanningNotification { get; }
	}

	[BaseType (typeof (UIView))]
	public partial interface AGSMapViewBase {

		[Export ("layerDelegate", ArgumentSemantic.Assign)]
		AGSMapViewLayerDelegate LayerDelegate { get; set; }

		[Export ("touchDelegate", ArgumentSemantic.Assign)]
		AGSMapViewTouchDelegate TouchDelegate { get; set; }

		[Export ("calloutDelegate", ArgumentSemantic.Assign)]
		AGSMapViewCalloutDelegate CalloutDelegate { get; set; }

		[Export ("mapLayers", ArgumentSemantic.Copy)]
		AGSLayer [] MapLayers { get; }

		[Export ("loaded")]
		bool Loaded { get; }

		[Export ("resolution")]
		double Resolution { get; }

		[Export ("mapScale")]
		double MapScale { get; }

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; }

		[Export ("timeExtent", ArgumentSemantic.Retain)]
		AGSTimeExtent TimeExtent { get; set; }

		[Export ("showMagnifierOnTapAndHold")]
		bool ShowMagnifierOnTapAndHold { get; set; }

		[Export ("allowMagnifierToPanMap")]
		bool AllowMagnifierToPanMap { get; set; }

		[Export ("rotationAngle")]
		double RotationAngle { get; set; }

		[Export ("allowRotationByPinching")]
		bool AllowRotationByPinching { get; set; }

		AGSPolygon VisibleArea { [Bind ("visibleArea")]get; }

		[Export ("visibleAreaEnvelope", ArgumentSemantic.Copy)]
		AGSEnvelope VisibleAreaEnvelope { get; }

		[Export ("mapAnchor", ArgumentSemantic.Copy)]
		AGSPoint MapAnchor { get; }

		[Export ("maxEnvelope", ArgumentSemantic.Retain)]
		AGSEnvelope MaxEnvelope { get; set; }

		[Export ("locationDisplay", ArgumentSemantic.Retain)]
		AGSLocationDisplay LocationDisplay { get; }

		[Export ("callout", ArgumentSemantic.Retain)]
		AGSCallout Callout { get; }

		[Export ("baseLayer", ArgumentSemantic.Retain)]
		AGSLayer BaseLayer { get; }

		[Export ("backgroundColor", ArgumentSemantic.Retain)]
		UIColor BackgroundColor { get; set; }

		[Export ("gridSize")]
		float GridSize { get; set; }

		[Export ("gridLineWidth")]
		float GridLineWidth { get; set; }

		[Export ("gridLineColor", ArgumentSemantic.Retain)]
		UIColor GridLineColor { get; set; }

		[Export ("interacting")]
		bool Interacting { get; }

		[Export ("animating")]
		bool Animating { get; }

		[Export ("lastChangeFromInteraction")]
		bool LastChangeFromInteraction { get; }

		[Export ("toMapPoint:")]
		AGSPoint ToMapPoint (PointF point);

		[Export ("toScreenPoint:")]
		PointF ToScreenPoint (AGSPoint point);

		[Export ("toScreenRect:")]
		RectangleF ToScreenRect (AGSEnvelope envelope);

		[Export ("toMapEnvelope:")]
		AGSEnvelope ToMapEnvelope (RectangleF rect);

		[Export ("zoomToEnvelope:animated:")]
		void ZoomToEnvelope (AGSEnvelope envelope, bool animated);

		[Export ("zoomWithFactor:atAnchorPoint:animated:")]
		void ZoomWithFactor (double factor, PointF anchorPoint, bool animated);

		[Export ("zoomIn:")]
		void ZoomIn (bool animated);

		[Export ("zoomOut:")]
		void ZoomOut (bool animated);

		[Export ("centerAtPoint:animated:")]
		void CenterAtPoint (AGSPoint point, bool animated);

		[Export ("zoomToGeometry:withPadding:animated:")]
		void ZoomToGeometry (AGSGeometry geometry, float padding, bool animated);

		[Export ("zoomToResolution:withCenterPoint:animated:")]
		void ZoomToResolution (double res, AGSPoint centerPoint, bool animated);

		[Export ("zoomToScale:withCenterPoint:animated:")]
		void ZoomToScale (double scale, AGSPoint centerPoint, bool animated);

		[Export ("zoomToResolution:animated:")]
		void ZoomToResolution (double res, bool animated);

		[Export ("zoomToScale:animated:")]
		void ZoomToScale (double scale, bool animated);

		[Export ("reset")]
		void Reset ();

		[Export ("setRotationAngle:animated:")]
		void SetRotationAngle (double angle, bool animated);

		[Export ("setRotationAngle:aroundScreenPoint:animated:")]
		void SetRotationAngle (double angle, PointF screenPoint, bool animated);

		[Export ("setRotationAngle:aroundMapPoint:animated:")]
		void SetRotationAngle (double angle, AGSPoint mapPoint, bool animated);

		[Export ("addMapLayer:withName:")]
		void AddMapLayer (AGSLayer mapLayer, string name);

		[Export ("removeMapLayerWithName:")]
		void RemoveMapLayerWithName (string name);

		[Export ("insertMapLayer:withName:atIndex:")]
		void InsertMapLayer (AGSLayer mapLayer, string name, uint index);

		[Export ("addMapLayer:")]
		void AddMapLayer (AGSLayer lyr);

		[Export ("insertMapLayer:atIndex:")]
		void InsertMapLayer (AGSLayer lyr, int index);

		[Export ("removeMapLayer:")]
		void RemoveMapLayer (AGSLayer lyr);

		[Export ("mapLayerForName:")]
		AGSLayer MapLayerForName (string name);

		[Export ("enableWrapAround")]
		void EnableWrapAround ();

		[Export ("disableWrapAround")]
		void DisableWrapAround ();

		AGSMapViewWrapAroundStatus WrapAroundStatus { [Bind ("wrapAroundStatus")]get; }

		[Export ("releaseHardwareResourcesWhenBackgrounded")]
		bool ReleaseHardwareResourcesWhenBackgrounded { get; set; }
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSMapViewLayerDelegate {

		[Export ("mapViewDidLoad:")]
		void MapViewDidLoad (AGSMapView mapView);

		[Export ("mapView:shouldFindGraphicsInLayer:atPoint:mapPoint:")]
		bool ShouldFindGraphicsInLayer (AGSMapView mapView, AGSGraphicsLayer graphicsLayer, PointF screen, AGSPoint mappoint);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSMapViewCalloutDelegate {

		[Export ("mapView:shouldShowCalloutForLocationDisplay:")]
		bool ShouldShowCalloutForLocationDisplay (AGSMapView mapView, AGSLocationDisplay ld);

		[Export ("mapView:didShowCalloutForLocationDisplay:")]
		void DidShowCalloutForLocationDisplay (AGSMapView mapView, AGSLocationDisplay ld);

		[Export ("mapView:shouldShowCalloutForGraphic:")]
		bool ShouldShowCalloutForGraphic (AGSMapView mapView, AGSGraphic graphic);

		[Export ("mapView:didShowCalloutForGraphic:")]
		void DidShowCalloutForGraphic (AGSMapView mapView, AGSGraphic graphic);

		[Export ("mapViewWillDismissCallout:")]
		void WillDismissCallout (AGSMapView mapView);

		[Export ("mapViewDidDismissCallout:")]
		void DidDismissCallout (AGSMapView mapView);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSMapViewTouchDelegate {

		[Export ("mapView:shouldProcessClickAtPoint:mapPoint:")]
		bool ShouldProcessClickAtPoint (AGSMapView mapView, PointF screen, AGSPoint mappoint);

		[Export ("mapView:didClickAtPoint:mapPoint:graphics:")]
		void DidClickAtPoint (AGSMapView mapView, PointF screen, AGSPoint mappoint, NSDictionary graphics);

		[Export ("mapView:didTapAndHoldAtPoint:mapPoint:graphics:")]
		void DidTapAndHoldAtPoint (AGSMapView mapView, PointF screen, AGSPoint mappoint, NSDictionary graphics);

		[Export ("mapView:didMoveTapAndHoldAtPoint:mapPoint:graphics:")]
		void DidMoveTapAndHoldAtPoint (AGSMapView mapView, PointF screen, AGSPoint mappoint, NSDictionary graphics);

		[Export ("mapView:didEndTapAndHoldAtPoint:mapPoint:graphics:")]
		void DidEndTapAndHoldAtPoint (AGSMapView mapView, PointF screen, AGSPoint mappoint, NSDictionary graphics);

		[Export ("mapViewDidCancelTapAndHold:")]
		void DidCancelTapAndHold (AGSMapView mapView);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSDomain : AGSCoding {

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Static, Export ("domainWithJSON:parentField:")]
		NSObject DomainWithJSON (NSDictionary json, AGSField parentField);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSCodedValue : AGSCoding {

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("code", ArgumentSemantic.Retain)]
		NSObject Code { get; }
	}

	[BaseType (typeof (AGSDomain))]
	public partial interface AGSCodedValueDomain {

		[Export ("codedValues", ArgumentSemantic.Copy)]
		AGSCodedValue [] CodedValues { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSFeatureSet : AGSCoding {

		[Export ("displayFieldName", ArgumentSemantic.Copy)]
		string DisplayFieldName { get; }

		[Export ("features", ArgumentSemantic.Copy)]
		AGSGraphic [] Features { get; set; }

		[Export ("fieldAliases", ArgumentSemantic.Copy)]
		NSDictionary FieldAliases { get; }

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; }

		[Export ("geometryType")]
		AGSGeometryType GeometryType { get; }

		[Export ("fields", ArgumentSemantic.Copy)]
		AGSField [] Fields { get; }

		[Export ("initWithDisplayFieldName:features:fieldAliases:spatialReference:geometryType:")]
		IntPtr Constructor (string displayFieldName, NSObject [] features, NSDictionary fieldAliases, AGSSpatialReference spatialReference, AGSGeometryType geometryType);

		[Export ("initWithFeatures:")]
		IntPtr Constructor (NSObject [] features);

		[Static, Export ("featureSetWithFeatures:")]
		AGSFeatureSet FeatureSetWithFeatures ( AGSGraphic [] features);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSField : AGSCoding {

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("type")]
		AGSFieldType Type { get; }

		[Export ("alias", ArgumentSemantic.Copy)]
		string Alias { get; }

		[Export ("domain", ArgumentSemantic.Retain)]
		AGSDomain Domain { get; }

		[Export ("editable")]
		bool Editable { get; }

		[Export ("nullable")]
		bool Nullable { get; }

		[Export ("length")]
		int Length { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSGraphic : AGSCoding {

		NSDictionary AllAttributes { [Bind ("allAttributes")]get; [Bind ("setAllAttributes:")]set; }

		[Export ("hasAttributeForKey:")]
		bool HasAttributeForKey (string key);

		[Export ("attributeForKey:")]
		NSObject AttributeForKey (string key);

		[Export ("safeAttributeForKey:")]
		NSObject SafeAttributeForKey (string key);

		[Export ("setAttribute:forKey:")]
		void SetAttribute (NSObject value, string key);

		[Export ("removeAttributeForKey:")]
		void RemoveAttributeForKey (string key);

		[Export ("setAttributeWithString:forKey:")]
		void SetAttributeWithString (string value, string key);

		[Export ("setAttributeWithDouble:forKey:")]
		void SetAttributeWithDouble (double value, string key);

		[Export ("setAttributeWithInt:forKey:")]
		void SetAttributeWithInt (int value, string key);

		[Export ("setAttributeWithUnsignedInt:forKey:")]
		void SetAttributeWithUnsignedInt (uint value, string key);

		[Export ("setAttributeWithFloat:forKey:")]
		void SetAttributeWithFloat (float value, string key);

		[Export ("setAttributeWithBool:forKey:")]
		void SetAttributeWithBool (bool value, string key);

		[Export ("setAttributeWithDate:forKey:")]
		void SetAttributeWithDate (NSDate value, string key);

		[Export ("setAttributeWithLong:forKey:")]
		void SetAttributeWithLong (int value, string key);

		[Export ("setAttributeWithInteger:forKey:")]
		void SetAttributeWithInteger (int value, string key);

		[Export ("setAttributeToNullForKey:")]
		void SetAttributeToNullForKey (string key);

		[Export ("attributeAsStringForKey:")]
		string AttributeAsStringForKey (string key);

		[Export ("attributeAsDateForKey:")]
		NSDate AttributeAsDateForKey (string key);

		[Export ("attributeAsDoubleForKey:exists:")]
		double AttributeAsDoubleForKey (string key, [unmapped: pointer: Pointer] exists);

		[Export ("attributeAsIntForKey:exists:")]
		int AttributeAsIntForKey (string key, [unmapped: pointer: Pointer] exists);

		[Export ("attributeAsUnsignedIntForKey:exists:")]
		uint AttributeAsUnsignedIntForKey (string key, [unmapped: pointer: Pointer] exists);

		[Export ("attributeAsFloatForKey:exists:")]
		float AttributeAsFloatForKey (string key, [unmapped: pointer: Pointer] exists);

		[Export ("attributeAsBoolForKey:exists:")]
		bool AttributeAsBoolForKey (string key, [unmapped: pointer: Pointer] exists);

		[Export ("attributeAsLongForKey:exists:")]
		int AttributeAsLongForKey (string key, [unmapped: pointer: Pointer] exists);

		[Export ("attributeAsIntegerForKey:exists:")]
		int AttributeAsIntegerForKey (string key, [unmapped: pointer: Pointer] exists);

		[Export ("geometry", ArgumentSemantic.Copy)]
		AGSGeometry Geometry { get; set; }

		[Export ("symbol", ArgumentSemantic.Retain)]
		AGSSymbol Symbol { get; set; }

		[Export ("infoTemplateDelegate", ArgumentSemantic.Assign)]
		AGSInfoTemplateDelegate InfoTemplateDelegate { get; set; }

		[Export ("layer", ArgumentSemantic.Assign)]
		AGSGraphicsLayer Layer { get; }

		[Export ("visible")]
		bool Visible { [Bind ("isVisible")] get; set; }

		[Export ("initWithGeometry:symbol:attributes:infoTemplateDelegate:")]
		IntPtr Constructor (AGSGeometry geometry, AGSSymbol symbol, NSDictionary attributes, AGSInfoTemplateDelegate infoTemplateDelegate);

		[Static, Export ("graphicWithGeometry:symbol:attributes:infoTemplateDelegate:")]
		NSObject GraphicWithGeometry (AGSGeometry geometry, AGSSymbol symbol, NSDictionary attributes, AGSInfoTemplateDelegate infoTemplateDelegate);
	}

	[BaseType (typeof (AGSGraphic))]
	public partial interface AGSDirectionGraphic : AGSCoding {

		[Export ("length")]
		double Length { get; }

		[Export ("time")]
		double Time { get; }

		[Export ("text", ArgumentSemantic.Copy)]
		string Text { get; }

		[Export ("ETA", ArgumentSemantic.Copy)]
		NSDate ETA { get; }

		[Export ("maneuverType")]
		AGSNADirectionsManeuver ManeuverType { get; }

		[Export ("directionsStrings", ArgumentSemantic.Copy)]
		AGSNADirectionsStrings [] DirectionsStrings { get; }
	}

	[BaseType (typeof (AGSGraphic))]
	public partial interface AGSStopGraphic : AGSCoding {

		[Export ("sequence")]
		uint Sequence { get; set; }

		[Export ("routeName", ArgumentSemantic.Assign)]
		string RouteName { get; set; }

		[Export ("name", ArgumentSemantic.Assign)]
		string Name { get; set; }

		[Export ("timeWindowStart", ArgumentSemantic.Assign)]
		NSDate TimeWindowStart { get; set; }

		[Export ("timeWindowEnd", ArgumentSemantic.Assign)]
		NSDate TimeWindowEnd { get; set; }
	}

	[BaseType (typeof (AGSGraphic))]
	public partial interface AGSFacilityGraphic : AGSCoding {

		[Export ("name", ArgumentSemantic.Assign)]
		string Name { get; set; }

		[Export ("initWithPoint:name:")]
		IntPtr Constructor (AGSPoint pt, string name);

		[Static, Export ("graphicWithPoint:name:")]
		NSObject GraphicWithPoint (AGSPoint pt, string name);
	}

	[BaseType (typeof (AGSGraphic))]
	public partial interface AGSIncidentGraphic : AGSCoding {

		[Export ("name", ArgumentSemantic.Assign)]
		string Name { get; set; }

		[Export ("initWithPoint:name:")]
		IntPtr Constructor (AGSPoint pt, string name);

		[Static, Export ("graphicWithPoint:name:")]
		NSObject GraphicWithPoint (AGSPoint pt, string name);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSInfoTemplateDelegate {

		[Export ("titleForGraphic:screenPoint:mapPoint:")]
		string ScreenPoint (AGSGraphic graphic, PointF screen, AGSPoint mapPoint);

		[Export ("detailForGraphic:screenPoint:mapPoint:")]
		string ScreenPoint (AGSGraphic graphic, PointF screen, AGSPoint mapPoint);

		[Export ("imageForGraphic:screenPoint:mapPoint:")]
		UIImage ScreenPoint (AGSGraphic graphic, PointF screen, AGSPoint mapPoint);

		[Export ("customViewForGraphic:screenPoint:mapPoint:")]
		UIView ScreenPoint (AGSGraphic graphic, PointF screen, AGSPoint mapPoint);
	}

	[BaseType (typeof (UIView))]
	public partial interface AGSCallout {

		[Export ("mapView", ArgumentSemantic.Assign)]
		AGSMapView MapView { get; }

		[Export ("mapLocation", ArgumentSemantic.Retain)]
		AGSPoint MapLocation { get; }

		[Export ("pixelOffset")]
		PointF PixelOffset { get; }

		[Export ("width")]
		float Width { get; set; }

		[Export ("title", ArgumentSemantic.Copy)]
		string Title { get; set; }

		[Export ("detail", ArgumentSemantic.Copy)]
		string Detail { get; set; }

		[Export ("color", ArgumentSemantic.Retain)]
		UIColor Color { get; set; }

		[Export ("highlight", ArgumentSemantic.Retain)]
		UIColor Highlight { get; set; }

		[Export ("titleColor", ArgumentSemantic.Retain)]
		UIColor TitleColor { get; set; }

		[Export ("detailColor", ArgumentSemantic.Retain)]
		UIColor DetailColor { get; set; }

		[Export ("accessoryButtonHidden")]
		bool AccessoryButtonHidden { [Bind ("isAccessoryButtonHidden")] get; set; }

		[Export ("leaderPositionFlags")]
		AGSCalloutLeaderPosition LeaderPositionFlags { get; set; }

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSCalloutDelegate Delegate { get; set; }

		[Export ("moveCalloutTo:pixelOffset:animated:")]
		void MoveCalloutTo (AGSPoint mapLocation, PointF pixelOffset, bool animated);

		[Export ("showCalloutAt:pixelOffset:animated:")]
		void ShowCalloutAt (AGSPoint mapLocation, PointF pixelOffset, bool animated);

		[Export ("customView", ArgumentSemantic.Retain)]
		UIView CustomView { get; set; }

		[Export ("margin")]
		SizeF Margin { get; set; }

		[Export ("cornerRadius")]
		float CornerRadius { get; set; }

		[Export ("maxWidth")]
		float MaxWidth { get; set; }

		[Export ("accessoryButtonType")]
		UIButtonType AccessoryButtonType { get; set; }

		[Export ("accessoryButtonImage", ArgumentSemantic.Retain)]
		UIImage AccessoryButtonImage { get; set; }

		[Export ("image", ArgumentSemantic.Retain)]
		UIImage Image { get; set; }

		[Export ("autoAdjustWidth")]
		bool AutoAdjustWidth { get; set; }

		[Export ("representedObject", ArgumentSemantic.Retain)]
		NSObject RepresentedObject { get; }

		[Export ("showCalloutAtPoint:forGraphic:animated:")]
		void ShowCalloutAtPoint (AGSPoint mapPoint, AGSGraphic graphic, bool animated);

		[Export ("showCalloutForLocationDisplay")]
		void ShowCalloutForLocationDisplay ();

		[Export ("showCalloutAt:pixelOffset:rotateOffsetWithMap:animated:")]
		void ShowCalloutAt (AGSPoint mapLocation, PointF pixelOffset, bool rotateOffsetWithMap, bool animated);

		[Export ("moveCalloutTo:pixelOffset:rotateOffsetWithMap:animated:")]
		void MoveCalloutTo (AGSPoint mapLocation, PointF pixelOffset, bool rotateOffsetWithMap, bool animated);

		[Export ("dismiss")]
		void Dismiss ();
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSCalloutDelegate {

		[Export ("didClickAccessoryButtonForCallout:")]
		void  (AGSCallout callout);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSCalloutTemplate : AGSInfoTemplateDelegate {

		[Export ("titleTemplate", ArgumentSemantic.Copy)]
		string TitleTemplate { get; set; }

		[Export ("detailTemplate", ArgumentSemantic.Copy)]
		string DetailTemplate { get; set; }
	}

	[BaseType (typeof (AGSDomain))]
	public partial interface AGSRangeDomain {

		[Export ("minValue", ArgumentSemantic.Retain)]
		NSNumber MinValue { get; }

		[Export ("maxValue", ArgumentSemantic.Retain)]
		NSNumber MaxValue { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSAddressCandidate : AGSCoding {

		[Export ("addressString", ArgumentSemantic.Copy)]
		string AddressString { get; }

		[Export ("address", ArgumentSemantic.Copy)]
		NSDictionary Address { get; }

		[Export ("attributes", ArgumentSemantic.Copy)]
		NSDictionary Attributes { get; }

		[Export ("location", ArgumentSemantic.Retain)]
		AGSPoint Location { get; }

		[Export ("score")]
		double Score { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSFindParameters : AGSCoding {

		[Export ("contains")]
		bool Contains { get; set; }

		[Export ("layerIds", ArgumentSemantic.Copy)]
		int [] LayerIds { get; set; }

		[Export ("outSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("returnGeometry")]
		bool ReturnGeometry { get; set; }

		[Export ("searchFields", ArgumentSemantic.Copy)]
		string [] SearchFields { get; set; }

		[Export ("searchText", ArgumentSemantic.Copy)]
		string SearchText { get; set; }

		[Export ("layerDefinitions", ArgumentSemantic.Copy)]
		AGSLayerDefinition [] LayerDefinitions { get; set; }

		[Export ("maxAllowableOffset")]
		double MaxAllowableOffset { get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSFindResult : AGSCoding {

		[Export ("displayFieldName", ArgumentSemantic.Copy)]
		string DisplayFieldName { get; }

		[Export ("feature", ArgumentSemantic.Retain)]
		AGSGraphic Feature { get; }

		[Export ("foundFieldName", ArgumentSemantic.Copy)]
		string FoundFieldName { get; }

		[Export ("layerId")]
		uint LayerId { get; }

		[Export ("layerName", ArgumentSemantic.Copy)]
		string LayerName { get; }
	}

	[BaseType (typeof (AGSTask))]
	public partial interface AGSFindTask {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSFindTaskDelegate Delegate { get; set; }

		[Static, Export ("findTaskWithURL:")]
		NSObject FindTaskWithURL (NSUrl url);

		[Static, Export ("findTaskWithURL:credential:")]
		NSObject FindTaskWithURL (NSUrl url, AGSCredential cred);

		[Export ("executeWithParameters:")]
		NSOperation ExecuteWithParameters (AGSFindParameters params);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSFindTaskDelegate {

		[Export ("findTask:operation:didExecuteWithFindResults:")]
		void DidExecuteWithFindResults (AGSFindTask findTask, NSOperation op, AGSFindResult [] results);

		[Export ("findTask:operation:didFailWithError:")]
		void DidFailWithError (AGSFindTask findTask, NSOperation op, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSIdentifyParameters : AGSCoding {

		[Export ("dpi")]
		uint Dpi { get; set; }

		[Export ("size")]
		SizeF Size { get; set; }

		[Export ("returnGeometry")]
		bool ReturnGeometry { get; set; }

		[Export ("tolerance")]
		uint Tolerance { get; set; }

		[Export ("layerOption")]
		AGSIdentifyParametersLayerOption LayerOption { get; set; }

		[Export ("geometry", ArgumentSemantic.Retain)]
		AGSGeometry Geometry { get; set; }

		[Export ("layerIds", ArgumentSemantic.Copy)]
		int [] LayerIds { get; set; }

		[Export ("mapEnvelope", ArgumentSemantic.Retain)]
		AGSEnvelope MapEnvelope { get; set; }

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; set; }

		[Export ("layerDefinitions", ArgumentSemantic.Copy)]
		AGSLayerDefinition [] LayerDefinitions { get; set; }

		[Export ("maxAllowableOffset")]
		double MaxAllowableOffset { get; set; }

		[Export ("layerTimeOptions", ArgumentSemantic.Copy)]
		AGSLayerTimeOptions [] LayerTimeOptions { get; set; }

		[Export ("timeExtent", ArgumentSemantic.Retain)]
		AGSTimeExtent TimeExtent { get; set; }

		[Static]
		NSObject IdentifyParameters { [Bind ("identifyParameters")]get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSIdentifyResult : AGSCoding {

		[Export ("displayFieldName", ArgumentSemantic.Copy)]
		string DisplayFieldName { get; }

		[Export ("feature", ArgumentSemantic.Retain)]
		AGSGraphic Feature { get; }

		[Export ("layerId")]
		uint LayerId { get; }

		[Export ("layerName", ArgumentSemantic.Copy)]
		string LayerName { get; }
	}

	[BaseType (typeof (AGSTask))]
	public partial interface AGSIdentifyTask {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSIdentifyTaskDelegate Delegate { get; set; }

		[Static, Export ("identifyTaskWithURL:")]
		NSObject IdentifyTaskWithURL (NSUrl url);

		[Static, Export ("identifyTaskWithURL:credential:")]
		NSObject IdentifyTaskWithURL (NSUrl url, AGSCredential cred);

		[Export ("executeWithParameters:")]
		NSOperation ExecuteWithParameters (AGSIdentifyParameters params);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSIdentifyTaskDelegate {

		[Export ("identifyTask:operation:didExecuteWithIdentifyResults:")]
		void DidExecuteWithIdentifyResults (AGSIdentifyTask identifyTask, NSOperation op, AGSIdentifyResult [] results);

		[Export ("identifyTask:operation:didFailWithError:")]
		void DidFailWithError (AGSIdentifyTask identifyTask, NSOperation op, NSError error);
	}

	[BaseType (typeof (AGSTask))]
	public partial interface AGSLocator {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSLocatorDelegate Delegate { get; set; }

		[Static]
		AGSLocator Locator { [Bind ("locator")]get; }

		[Static, Export ("locatorWithURL:")]
		AGSLocator LocatorWithURL (NSUrl url);

		[Static, Export ("locatorWithURL:credential:")]
		AGSLocator LocatorWithURL (NSUrl url, AGSCredential cred);

		[Export ("addressForLocation:maxSearchDistance:")]
		NSOperation AddressForLocation (AGSPoint location, double distance);

		[Export ("addressForLocation:maxSearchDistance:outSpatialReference:")]
		NSOperation AddressForLocation (AGSPoint location, double distance, AGSSpatialReference sr);

		[Export ("locationsForAddress:returnFields:")]
		NSOperation LocationsForAddress (NSDictionary address, string [] outFields);

		[Export ("locationsForAddress:returnFields:outSpatialReference:")]
		NSOperation LocationsForAddress (NSDictionary address, string [] outFields, AGSSpatialReference sr);

		[Export ("locationsForAddressWithParameters:")]
		NSOperation LocationsForAddressWithParameters (AGSLocationsForAddressParameters params);

		[Export ("findWithParameters:")]
		NSOperation FindWithParameters (AGSLocatorFindParameters findParams);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSLocatorDelegate {

		[Export ("locator:operation:didFindLocationsForAddress:")]
		void DidFindLocationsForAddress (AGSLocator locator, NSOperation op, AGSAddressCandidate [] candidates);

		[Export ("locator:operation:didFailLocationsForAddress:")]
		void Operation (AGSLocator locator, NSOperation op, NSError error);

		[Export ("locator:operation:didFindAddressForLocation:")]
		void Operation (AGSLocator locator, NSOperation op, AGSAddressCandidate candidate);

		[Export ("locator:operation:didFailAddressForLocation:")]
		void Operation (AGSLocator locator, NSOperation op, NSError error);

		[Export ("locator:operation:didFind:")]
		void Operation (AGSLocator locator, NSOperation op, AGSLocatorFindResult [] results);

		[Export ("locator:operation:didFailToFindWithError:")]
		void Operation (AGSLocator locator, NSOperation op, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSLocationsForAddressParameters {

		[Export ("address", ArgumentSemantic.Copy)]
		NSDictionary Address { get; set; }

		[Export ("sourceCountry", ArgumentSemantic.Copy)]
		string SourceCountry { get; set; }

		[Export ("searchExtent", ArgumentSemantic.Retain)]
		AGSEnvelope SearchExtent { get; set; }

		[Export ("outSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("outFields", ArgumentSemantic.Copy)]
		string [] OutFields { get; set; }

		[Export ("location", ArgumentSemantic.Retain)]
		AGSPoint Location { get; set; }

		[Export ("distance")]
		float Distance { get; set; }

		[Export ("encodeToJSON")]
		NSDictionary EncodeToJSON ();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSLocatorFindParameters : AGSCoding {

		[Export ("text", ArgumentSemantic.Copy)]
		string Text { get; set; }

		[Export ("sourceCountry", ArgumentSemantic.Copy)]
		string SourceCountry { get; set; }

		[Export ("searchExtent", ArgumentSemantic.Retain)]
		AGSEnvelope SearchExtent { get; set; }

		[Export ("outSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("outFields", ArgumentSemantic.Copy)]
		string [] OutFields { get; set; }

		[Export ("maxLocations")]
		uint MaxLocations { get; set; }

		[Export ("location", ArgumentSemantic.Retain)]
		AGSPoint Location { get; set; }

		[Export ("distance")]
		float Distance { get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSLocatorFindResult {

		[Export ("extent", ArgumentSemantic.Retain)]
		AGSEnvelope Extent { get; }

		[Export ("graphic", ArgumentSemantic.Retain)]
		AGSGraphic Graphic { get; }

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSQuery : AGSCoding {

		[Export ("geometry", ArgumentSemantic.Retain)]
		AGSGeometry Geometry { get; set; }

		[Export ("outFields", ArgumentSemantic.Copy)]
		string [] OutFields { get; set; }

		[Export ("outSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("returnGeometry")]
		bool ReturnGeometry { get; set; }

		[Export ("spatialRelationship")]
		AGSSpatialRelationship SpatialRelationship { get; set; }

		[Export ("text", ArgumentSemantic.Copy)]
		string Text { get; set; }

		[Export ("where", ArgumentSemantic.Copy)]
		string Where { get; set; }

		[Export ("objectIds", ArgumentSemantic.Copy)]
		int [] ObjectIds { get; set; }

		[Export ("relationParam", ArgumentSemantic.Copy)]
		string RelationParam { get; set; }

		[Export ("timeExtent", ArgumentSemantic.Retain)]
		AGSTimeExtent TimeExtent { get; set; }

		[Export ("maxAllowableOffset")]
		double MaxAllowableOffset { get; set; }

		[Export ("outStatistics", ArgumentSemantic.Copy)]
		AGSOutStatistic [] OutStatistics { get; set; }

		[Export ("groupByFieldsForStatistics", ArgumentSemantic.Copy)]
		string [] GroupByFieldsForStatistics { get; set; }

		[Export ("orderByFields", ArgumentSemantic.Copy)]
		string [] OrderByFields { get; set; }

		[Static, Export ("query")]
		AGSQuery Query ();
	}

	[BaseType (typeof (AGSTask))]
	public partial interface AGSQueryTask {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSQueryTaskDelegate Delegate { get; set; }

		[Static, Export ("queryTaskWithURL:")]
		AGSQueryTask QueryTaskWithURL (NSUrl url);

		[Static, Export ("queryTaskWithURL:credential:")]
		AGSQueryTask QueryTaskWithURL (NSUrl url, AGSCredential cred);

		[Export ("executeWithQuery:")]
		NSOperation ExecuteWithQuery (AGSQuery query);

		[Export ("executeForIdsWithQuery:")]
		NSOperation ExecuteForIdsWithQuery (AGSQuery query);

		[Export ("executeWithRelationshipQuery:")]
		NSOperation ExecuteWithRelationshipQuery (AGSRelationshipQuery query);

		[Export ("executeFeatureCountWithQuery:")]
		NSOperation ExecuteFeatureCountWithQuery (AGSQuery query);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSQueryTaskDelegate {

		[Export ("queryTask:operation:didExecuteWithFeatureSetResult:")]
		void DidExecuteWithFeatureSetResult (AGSQueryTask queryTask, NSOperation op, AGSFeatureSet featureSet);

		[Export ("queryTask:operation:didFailWithError:")]
		void DidFailWithError (AGSQueryTask queryTask, NSOperation op, NSError error);

		[Export ("queryTask:operation:didExecuteWithObjectIds:")]
		void DidFailWithError (AGSQueryTask queryTask, NSOperation op, int [] objectIds);

		[Export ("queryTask:operation:didFailQueryForIdsWithError:")]
		void DidFailQueryForIdsWithError (AGSQueryTask queryTask, NSOperation op, NSError error);

		[Export ("queryTask:operation:didExecuteWithRelatedFeatures:")]
		void DidExecuteWithRelatedFeatures (AGSQueryTask queryTask, NSOperation op, NSDictionary relatedFeatures);

		[Export ("queryTask:operation:didFailRelationshipQueryWithError:")]
		void DidFailRelationshipQueryWithError (AGSQueryTask queryTask, NSOperation op, NSError error);

		[Export ("queryTask:operation:didExecuteWithFeatureCount:")]
		void DidExecuteWithFeatureCount (AGSQueryTask queryTask, NSOperation op, int count);

		[Export ("queryTask:operation:didFailQueryFeatureCountWithError:")]
		void DidFailQueryFeatureCountWithError (AGSQueryTask queryTask, NSOperation op, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSRelationshipQuery : AGSCoding {

		[Export ("relationshipId")]
		int RelationshipId { get; set; }

		[Export ("objectIds", ArgumentSemantic.Copy)]
		int [] ObjectIds { get; set; }

		[Export ("definitionExpression", ArgumentSemantic.Copy)]
		string DefinitionExpression { get; set; }

		[Export ("outFields", ArgumentSemantic.Copy)]
		string [] OutFields { get; set; }

		[Export ("returnGeometry")]
		bool ReturnGeometry { get; set; }

		[Export ("outSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("maxAllowableOffset")]
		double MaxAllowableOffset { get; set; }

		[Static, Export ("relationshipQuery")]
		NSObject RelationshipQuery ();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSOutStatistic : AGSCoding {

		[Export ("statisticType")]
		AGSQueryStatisticsType StatisticType { get; set; }

		[Export ("onStatisticField", ArgumentSemantic.Copy)]
		string OnStatisticField { get; set; }

		[Export ("outStatisticFieldName", ArgumentSemantic.Copy)]
		string OutStatisticFieldName { get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSAreasAndLengthsParameters : AGSCoding {

		[Export ("polygons", ArgumentSemantic.Copy)]
		AGSPolygon [] Polygons { get; set; }

		[Export ("lengthUnit")]
		AGSSRUnit LengthUnit { get; set; }

		[Export ("areaUnit")]
		AGSAreaUnits AreaUnit { get; set; }

		[Static, Export ("areasAndLengthsParameters")]
		AGSAreasAndLengthsParameters AreasAndLengthsParameters ();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSBufferParameters : AGSCoding {

		[Export ("bufferSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference BufferSpatialReference { get; set; }

		[Export ("distances", ArgumentSemantic.Copy)]
		double [] Distances { get; set; }

		[Export ("geometries", ArgumentSemantic.Copy)]
		AGSGeometry [] Geometries { get; set; }

		[Export ("outSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference OutSpatialReference { get; set; }

		[Export ("unionResults")]
		bool UnionResults { get; set; }

		[Export ("unit")]
		AGSSRUnit Unit { get; set; }

		[Static, Export ("bufferParameters")]
		AGSBufferParameters BufferParameters ();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSDensifyParameters : AGSCoding {

		[Export ("geometries", ArgumentSemantic.Copy)]
		AGSGeometry [] Geometries { get; set; }

		[Export ("maxSegmentLength")]
		uint MaxSegmentLength { get; set; }

		[Export ("lengthUnit")]
		AGSSRUnit LengthUnit { get; set; }

		[Export ("geodesic")]
		bool Geodesic { get; set; }

		[Static, Export ("densifyParameters")]
		AGSDensifyParameters DensifyParameters ();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSDistanceParameters : AGSCoding {

		[Export ("distanceUnit")]
		AGSSRUnit DistanceUnit { get; set; }

		[Export ("geometry1", ArgumentSemantic.Retain)]
		AGSGeometry Geometry1 { get; set; }

		[Export ("geometry2", ArgumentSemantic.Retain)]
		AGSGeometry Geometry2 { get; set; }

		[Export ("geodesic")]
		bool Geodesic { get; set; }

		[Static, Export ("distanceParameters")]
		AGSDistanceParameters DistanceParameters ();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSGeneralizeParameters : AGSCoding {

		[Export ("maxDeviation")]
		double MaxDeviation { get; set; }

		[Export ("deviationUnit")]
		AGSSRUnit DeviationUnit { get; set; }

		[Export ("geometries", ArgumentSemantic.Copy)]
		AGSGeometry [] Geometries { get; set; }

		[Static, Export ("generalizeParameters")]
		AGSGeneralizeParameters GeneralizeParameters { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSGeometryRelationship {

		[Export ("geometry1", ArgumentSemantic.Retain)]
		AGSGeometry Geometry1 { get; }

		[Export ("geometry2", ArgumentSemantic.Retain)]
		AGSGeometry Geometry2 { get; }

		[Export ("type")]
		AGSGeometryRelation Type { get; }
	}

	[BaseType (typeof (AGSTask))]
	public partial interface AGSGeometryServiceTask {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSGeometryServiceTaskDelegate Delegate { get; set; }

		[Static, Export ("geometryServiceTaskWithURL:")]
		NSObject GeometryServiceTaskWithURL (NSUrl url);

		[Static, Export ("geometryServiceTaskWithURL:credential:")]
		NSObject GeometryServiceTaskWithURL (NSUrl url, AGSCredential cred);

		[Export ("relationWithParameters:")]
		NSOperation RelationWithParameters (AGSRelationParameters relationParams);

		[Export ("distanceWithParameters:")]
		NSOperation DistanceWithParameters (AGSDistanceParameters distanceParams);

		[Export ("unionGeometries:")]
		NSOperation UnionGeometries (AGSGeometry [] geometries);

		[Export ("reshapeGeometry:withReshaper:")]
		NSOperation ReshapeGeometry (AGSGeometry geometry, AGSPolyline reshaper);

		[Export ("convexHullGeometries:")]
		NSOperation ConvexHullGeometries (AGSGeometry [] geometries);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSGeometryServiceTaskDelegate {

		[Export ("geometryServiceTask:operation:didReturnBufferedGeometries:")]
		void DidReturnBufferedGeometries (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry [] bufferedGeometries);

		[Export ("geometryServiceTask:operation:didFailBufferWithError:")]
		void DidFailBufferWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnProjectedGeometries:")]
		void DidReturnProjectedGeometries (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry [] projectedGeometries);

		[Export ("geometryServiceTask:operation:didFailProjectWithError:")]
		void DidFailProjectWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnSimplifiedGeometries:")]
		void DidReturnSimplifiedGeometries (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry [] simplifiedGeometries);

		[Export ("geometryServiceTask:operation:didFailSimplifyWithError:")]
		void DidFailSimplifyWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnAreas:andLengths:")]
		void DidReturnAreasAndLengths (AGSGeometryServiceTask geometryServiceTask, NSOperation op, double [] areas, double [] lengths);

		[Export ("geometryServiceTask:operation:didFailAreasAndLengthsWithError:")]
		void DidFailAreasAndLengthsWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnLabelPoints:")]
		void DidReturnLabelPoints (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGraphic [] labelPoints);

		[Export ("geometryServiceTask:operation:didFailLabelPointsWithError:")]
		void DidFailLabelPointsWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnLengths:")]
		void DidReturnLengths (AGSGeometryServiceTask geometryServiceTask, NSOperation op, double [] lengths);

		[Export ("geometryServiceTask:operation:didFailLengthsWithError:")]
		void DidFailLengthsWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnRelations:")]
		void DidReturnRelations (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometryRelationship [] relations);

		[Export ("geometryServiceTask:operation:didFailRelationWithError:")]
		void DidFailRelationWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnDistance:")]
		void DidReturnDistance (AGSGeometryServiceTask geometryServiceTask, NSOperation op, double distance);

		[Export ("geometryServiceTask:operation:didFailDistanceWithError:")]
		void DidFailDistanceWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnDensifiedGeometries:")]
		void DidReturnDensifiedGeometries (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry [] geometries);

		[Export ("geometryServiceTask:operation:didFailDensifyWithError:")]
		void DidFailDensifyWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnGeneralizedGeometries:")]
		void DidReturnGeneralizedGeometries (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry [] geometries);

		[Export ("geometryServiceTask:operation:didFailGeneralizeWithError:")]
		void DidFailGeneralizeWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnUnionedGeometry:")]
		void DidReturnUnionedGeometry (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry geometry);

		[Export ("geometryServiceTask:operation:didFailUnionWithError:")]
		void DidFailUnionWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnReshapedGeometry:")]
		void DidReturnReshapedGeometry (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry geometry);

		[Export ("geometryServiceTask:operation:didFailReshapeWithError:")]
		void DidFailReshapeWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnIntersectingGeometries:")]
		void DidReturnIntersectingGeometries (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry [] geometries);

		[Export ("geometryServiceTask:operation:didFailIntersectWithError:")]
		void DidFailIntersectWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnDifferenceGeometries:")]
		void DidReturnDifferenceGeometries (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry [] geometries);

		[Export ("geometryServiceTask:operation:didFailDifferenceWithError:")]
		void DidFailDifferenceWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnCutGeometries:")]
		void DidReturnCutGeometries (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry [] geometries);

		[Export ("geometryServiceTask:operation:didFailCutWithError:")]
		void DidFailCutWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnAutoCompletedPolygons:")]
		void DidReturnAutoCompletedPolygons (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry [] polygons);

		[Export ("geometryServiceTask:operation:didFailAutoCompleteWithError:")]
		void DidFailAutoCompleteWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnConvexHullGeometry:")]
		void DidReturnConvexHullGeometry (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry geometry);

		[Export ("geometryServiceTask:operation:didFailConvexHullWithError:")]
		void DidFailConvexHullWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnOffsetGeometries:")]
		void DidReturnOffsetGeometries (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry [] geometries);

		[Export ("geometryServiceTask:operation:didFailOffsetWithError:")]
		void DidFailOffsetWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);

		[Export ("geometryServiceTask:operation:didReturnTrimExtendPolylines:")]
		void DidReturnTrimExtendPolylines (AGSGeometryServiceTask geometryServiceTask, NSOperation op, AGSGeometry [] polylines);

		[Export ("geometryServiceTask:operation:didFailTrimExtendWithError:")]
		void DidFailTrimExtendWithError (AGSGeometryServiceTask geometryServiceTask, NSOperation op, NSError error);
	}

	[Category, BaseType (typeof (AGSGeometryServiceTask))]
	public partial interface AGSGeometryArray_AGSGeometryServiceTask {

		[Export ("bufferWithParameters:")]
		NSOperation BufferWithParameters (AGSBufferParameters params);

		[Export ("projectGeometries:toSpatialReference:")]
		NSOperation ProjectGeometries (AGSGeometry [] geometries, AGSSpatialReference spatialReference);

		[Export ("simplifyGeometries:")]
		NSOperation SimplifyGeometries (AGSGeometry [] geometries);

		[Export ("labelPointsForPolygons:")]
		NSOperation LabelPointsForPolygons (AGSGeometry [] polygons);

		[Export ("densifyWithParameters:")]
		NSOperation DensifyWithParameters (AGSDensifyParameters densifyParams);

		[Export ("generalizeWithParameters:")]
		NSOperation GeneralizeWithParameters (AGSGeneralizeParameters generalizeParams);

		[Export ("intersectGeometries:withGeometry:")]
		NSOperation IntersectGeometries (AGSGeometry [] geometries, AGSGeometry intersectGeometry);

		[Export ("differenceGeometries:withGeometry:")]
		NSOperation DifferenceGeometries (AGSGeometry [] geometries, AGSGeometry differenceGeometry);

		[Export ("cutGeometries:withGeometry:")]
		NSOperation CutGeometries (AGSGeometry [] geometries, AGSPolyline cutterGeometry);

		[Export ("autoCompletePolygons:withPolylines:")]
		NSOperation AutoCompletePolygons (AGSGeometry [] polygons, AGSGeometry [] polylines);

		[Export ("offsetWithParameters:")]
		NSOperation OffsetWithParameters (AGSOffsetParameters offsetParams);

		[Export ("trimExtendWithParameters:")]
		NSOperation TrimExtendWithParameters (AGSTrimExtendParameters trimExtendParams);
	}

	[Category, BaseType (typeof (AGSGeometryServiceTask))]
	public partial interface AreasAndLengths_AGSGeometryServiceTask {

		[Export ("areasAndLengthsWithParameters:")]
		NSOperation AreasAndLengthsWithParameters (AGSAreasAndLengthsParameters areasAndLengthsParams);

		[Export ("lengthsWithParameters:")]
		NSOperation LengthsWithParameters (AGSLengthsParameters lengthsParams);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSLengthsParameters : AGSCoding {

		[Export ("polylines", ArgumentSemantic.Copy)]
		AGSPolyline [] Polylines { get; set; }

		[Export ("geodesic")]
		bool Geodesic { get; set; }

		[Export ("lengthUnit")]
		AGSSRUnit LengthUnit { get; set; }

		[Export ("initWithPolyline:")]
		IntPtr Constructor (AGSPolyline polyline);

		[Static, Export ("lengthParameters")]
		AGSLengthsParameters LengthParameters ();

		[Static, Export ("lengthParametersWithPolyline:")]
		AGSLengthsParameters LengthParametersWithPolyline (AGSPolyline polyline);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSOffsetParameters : AGSCoding {

		[Export ("offsetDistance")]
		double OffsetDistance { get; set; }

		[Export ("offsetUnit")]
		AGSSRUnit OffsetUnit { get; set; }

		[Export ("offsetHow")]
		AGSGeometryOffsetType OffsetHow { get; set; }

		[Export ("bevelRatio")]
		double BevelRatio { get; set; }

		[Export ("simplifyResult")]
		bool SimplifyResult { get; set; }

		[Export ("geometries", ArgumentSemantic.Copy)]
		AGSGeometry [] Geometries { get; set; }

		[Static, Export ("offsetParameters")]
		AGSOffsetParameters OffsetParameters ();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSRelationParameters : AGSCoding {

		[Export ("geometries1", ArgumentSemantic.Copy)]
		AGSGeometry [] Geometries1 { get; set; }

		[Export ("geometries2", ArgumentSemantic.Copy)]
		AGSGeometry [] Geometries2 { get; set; }

		[Export ("relation")]
		AGSGeometryRelation Relation { get; set; }

		[Export ("relationParam", ArgumentSemantic.Copy)]
		string RelationParam { get; set; }

		[Static, Export ("relationParameters")]
		AGSRelationParameters RelationParameters ();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSTrimExtendParameters : AGSCoding {

		[Export ("polylines", ArgumentSemantic.Copy)]
		AGSPolyline [] Polylines { get; set; }

		[Export ("trimExtendTo", ArgumentSemantic.Retain)]
		AGSPolyline TrimExtendTo { get; set; }

		[Export ("extendHow")]
		uint ExtendHow { get; set; }

		[Static, Export ("trimExtendParameters")]
		AGSTrimExtendParameters TrimExtendParameters ();
	}

	[Category, BaseType (typeof (UIApplication))]
	public partial interface AGSAdditions_UIApplication {

		[Static, Export ("ags_setNetworkActivityDelegate:")]
		void SetNetworkActivityDelegate (AGSNetworkActivityDelegate delegate);

		[Static, Export ("ags_showNetworkActivityIndicator:")]
		void AShowNetworkActivityIndicator (bool show);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSNetworkActivityDelegate {

		[Export ("networkActivityInProgress")]
		void NetworkActivityInProgress ();

		[Export ("networkActivityEnded")]
		void NetworkActivityEnded ();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSBase64 {

		[Static, Export ("initialize")]
		void Initialize ();

		[Static, Export ("encode:length:")]
		string Encode ([unmapped: pointer: Pointer] input, int length);

		[Static, Export ("encode:")]
		string Encode (NSData rawBytes);

		[Static, Export ("decode:length:")]
		NSData Decode ([unmapped: pointer: Pointer] string, int inputLength);

		[Static, Export ("decode:")]
		NSData Decode (string string);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSDevice {

		[Static]
		AGSDevice CurrentDevice { [Bind ("currentDevice")]get; }

		string SystemVersion { [Bind ("systemVersion")]get; }

		string Machine { [Bind ("machine")]get; }

		AGSDeviceMachineType MachineType { [Bind ("machineType")]get; }

		bool IsIPad { [Bind ("isIPad")]get; }

		bool IsAtLeastiOS4 { [Bind ("isAtLeastiOS4")]get; }

		bool IsAtLeastiOS5 { [Bind ("isAtLeastiOS5")]get; }

		bool IsAtLeastiOS6 { [Bind ("isAtLeastiOS6")]get; }

		bool IsMac { [Bind ("isMac")]get; }

		int Ppi { [Bind ("ppi")]get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSScreen {

		[Static]
		float MainScreenScale { [Bind ("mainScreenScale")]get; }

		[Static]
		int MainScreenPpi { [Bind ("mainScreenPpi")]get; }

		[Static]
		int BasePpi { [Bind ("basePpi")]get; }
	}

	[Category, BaseType (typeof (NSError))]
	public partial interface AGSAdditions_NSError {

		bool IsAuthenticationError { [Bind ("ags_isAuthenticationError")]get; }
	}

	[Category, BaseType (typeof (NSURL))]
	public partial interface AGSAdditions_NSURL {

		[Static, Export ("ags_URLWithUnicodeString:")]
		NSUrl URLWithUnicodeString (string urlString);
	}

	[Category, BaseType (typeof (NSURLConnection))]
	public partial interface AGSAdditions_NSURLConnection {

		[Static]
		IList<string> TrustedHosts { [Bind ("ags_trustedHosts")]get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSSBJsonParser {

		[Export ("maxDepth")]
		uint MaxDepth { get; set; }

		[Export ("error", ArgumentSemantic.Copy)]
		string Error { get; set; }

		[Export ("objectWithData:")]
		NSObject ObjectWithData (NSData data);

		[Export ("objectWithString:")]
		NSObject ObjectWithString (string repr);

		[Export ("objectWithString:error:")]
		NSObject ObjectWithString (string jsonText, out NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSSBJsonWriter {

		[Export ("maxDepth")]
		uint MaxDepth { get; set; }

		[Export ("error", ArgumentSemantic.Copy)]
		string Error { get; }

		[Export ("humanReadable")]
		bool HumanReadable { get; set; }

		[Export ("sortKeys")]
		bool SortKeys { get; set; }

		[Export ("sortKeysComparator", ArgumentSemantic.Copy)]
		NSComparator SortKeysComparator { get; set; }

		[Export ("stringWithObject:")]
		string StringWithObject (NSObject value);

		[Export ("dataWithObject:")]
		NSData DataWithObject (NSObject value);

		[Export ("stringWithObject:error:")]
		string StringWithObject (NSObject value, out NSError error);
	}

	[Model]
	public partial interface AGSSBJsonStreamParserDelegate {

		[Export ("parserFoundObjectStart:")]
		void  (AGSSBJsonStreamParser parser);

		[Export ("parser:foundObjectKey:")]
		void FoundObjectKey (AGSSBJsonStreamParser parser, string key);

		[Export ("parserFoundObjectEnd:")]
		void  (AGSSBJsonStreamParser parser);

		[Export ("parserFoundArrayStart:")]
		void  (AGSSBJsonStreamParser parser);

		[Export ("parserFoundArrayEnd:")]
		void  (AGSSBJsonStreamParser parser);

		[Export ("parser:foundBoolean:")]
		void FoundBoolean (AGSSBJsonStreamParser parser, bool x);

		[Export ("parserFoundNull:")]
		void  (AGSSBJsonStreamParser parser);

		[Export ("parser:foundNumber:")]
		void FoundNumber (AGSSBJsonStreamParser parser, NSNumber num);

		[Export ("parser:foundString:")]
		void FoundString (AGSSBJsonStreamParser parser, string string);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSSBJsonStreamParser {

		[Export ("state", ArgumentSemantic.Assign)]
		AGSSBJsonStreamParserState State { get; set; }

		[Export ("stateStack", ArgumentSemantic.Retain)]
		NSMutableArray StateStack { get; }

		[Export ("supportMultipleDocuments")]
		bool SupportMultipleDocuments { get; set; }

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSSBJsonStreamParserDelegate Delegate { get; set; }

		[Export ("maxDepth")]
		uint MaxDepth { get; set; }

		[Export ("error", ArgumentSemantic.Copy)]
		string Error { get; set; }

		[Export ("parse:")]
		AGSSBJsonStreamParserStatus Parse (NSData data);
	}

	[Model]
	public partial interface AGSSBJsonStreamParserAdapterDelegate {

		[Export ("parser:foundArray:")]
		void FoundArray (AGSSBJsonStreamParser parser, NSObject [] array);

		[Export ("parser:foundObject:")]
		void FoundObject (AGSSBJsonStreamParser parser, NSDictionary dict);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSSBJsonStreamParserAdapter : AGSSBJsonStreamParserDelegate {

		[Export ("levelsToSkip")]
		uint LevelsToSkip { get; set; }

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSSBJsonStreamParserAdapterDelegate Delegate { get; set; }
	}

	[Category, BaseType (typeof (NSObject))]
	public partial interface AGSSBProxyForJson_NSObject {

		NSObject Ags_proxyForJson { [Bind ("ags_proxyForJson")]get; }
	}

	[Model]
	public partial interface AGSSBJsonStreamWriterDelegate {

		[Export ("writer:appendBytes:length:")]
		void AppendBytes (AGSSBJsonStreamWriter writer, byte[] bytes, uint length);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSSBJsonStreamWriter {

		[Export ("state", ArgumentSemantic.Assign)]
		AGSSBJsonStreamWriterState State { get; set; }

		[Export ("stateStack", ArgumentSemantic.Retain)]
		NSMutableArray StateStack { get; }

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSSBJsonStreamWriterDelegate Delegate { get; set; }

		[Export ("maxDepth")]
		uint MaxDepth { get; set; }

		[Export ("humanReadable")]
		bool HumanReadable { get; set; }

		[Export ("sortKeys")]
		bool SortKeys { get; set; }

		[Export ("sortKeysComparator", ArgumentSemantic.Copy)]
		NSComparator SortKeysComparator { get; set; }

		[Export ("error", ArgumentSemantic.Copy)]
		string Error { get; set; }

		[Export ("writeObject:")]
		bool WriteObject (NSDictionary dict);

		[Export ("writeArray:")]
		bool WriteArray (NSObject [] array);

		[Export ("writeObjectOpen")]
		bool WriteObjectOpen ();

		[Export ("writeObjectClose")]
		bool WriteObjectClose ();

		[Export ("writeArrayOpen")]
		bool WriteArrayOpen ();

		[Export ("writeArrayClose")]
		bool WriteArrayClose ();

		[Export ("writeNull")]
		bool WriteNull ();

		[Export ("writeBool:")]
		bool WriteBool (bool x);

		[Export ("writeNumber:")]
		bool WriteNumber (NSNumber n);

		[Export ("writeString:")]
		bool WriteString (string s);
	}

	[Category, BaseType (typeof (AGSSBJsonStreamWriter))]
	public partial interface AGSPrivate_AGSSBJsonStreamWriter {

		[Export ("writeValue:")]
		bool WriteValue (NSObject v);

		[Export ("appendBytes:length:")]
		void AppendBytes (byte[] bytes, uint length);
	}

	[Category, BaseType (typeof (NSObject))]
	public partial interface NSObject_AGSSBJsonWriting_NSObject {

		string JSONRepresentation { [Bind ("ags_JSONRepresentation")]get; }
	}

	[Category, BaseType (typeof (NSString))]
	public partial interface NSString_AGSSBJsonParsing_NSString {

		NSObject JSONValue { [[Bind ("ags_JSONValue")]]get; }
	}

	[Category, BaseType (typeof (NSData))]
	public partial interface NSData_AGSSBJsonParsing_NSData {

		NSObject Ags_JSONValue { [Bind ("ags_JSONValue")]get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSGraphic : AGSCoding {

		[Notification, Field ("AGSSymbolReadyToDrawNotification")]
		NSString AGSSymbolReadyToDrawNotification { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSSymbol : AGSCoding {

		[Export ("color", ArgumentSemantic.Copy)]
		UIColor Color { get; set; }

		[Export ("swatchForGeometryType:size:")]
		UIImage SwatchForGeometryType (AGSGeometryType geometryType, SizeF size);
	}

	[BaseType (typeof (AGSLayer))]
	public partial interface AGSGraphicsLayer {

		[Export ("initWithFullEnvelope:")]
		IntPtr Constructor (AGSEnvelope fullEnv);

		[Export ("initWithSpatialReference:")]
		IntPtr Constructor (AGSSpatialReference sr);

		[Export ("graphics", ArgumentSemantic.Copy)]
		AGSGraphic [] Graphics { get; }

		[Export ("graphicsCount")]
		uint GraphicsCount { get; }

		[Export ("renderer", ArgumentSemantic.Retain)]
		AGSRenderer Renderer { get; set; }

		[Export ("startTimeField", ArgumentSemantic.Copy)]
		string StartTimeField { get; set; }

		[Export ("endTimeField", ArgumentSemantic.Copy)]
		string EndTimeField { get; set; }

		[Export ("timeOffset")]
		double TimeOffset { get; set; }

		[Export ("timeOffsetUnits")]
		AGSTimeIntervalUnits TimeOffsetUnits { get; set; }

		[Static, Export ("graphicsLayer")]
		AGSGraphicsLayer GraphicsLayer ();

		[Export ("addGraphic:")]
		void AddGraphic (AGSGraphic graphic);

		[Export ("addGraphics:")]
		void AddGraphics (AGSGraphic [] graphics);

		[Export ("removeGraphic:")]
		void RemoveGraphic (AGSGraphic graphic);

		[Export ("removeAllGraphics")]
		void RemoveAllGraphics ();

		[Export ("removeGraphics:")]
		void RemoveGraphics (AGSGraphic [] objects);

		[Export ("selectionSymbol", ArgumentSemantic.Retain)]
		AGSSymbol SelectionSymbol { get; set; }

		[Export ("selectionColor", ArgumentSemantic.Copy)]
		UIColor SelectionColor { get; set; }

		[Export ("setSelected:forGraphic:")]
		void SetSelected (bool selected, AGSGraphic graphic);

		[Export ("isGraphicSelected:")]
		bool IsGraphicSelected (AGSGraphic graphic);

		[Export ("clearSelection")]
		void ClearSelection ();

		[Export ("selectedGraphics")]
		AGSGraphic [] SelectedGraphics { get; }

		[Export ("refresh")]
		void Refresh ();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSRenderer : AGSCoding {

		[Export ("layer", ArgumentSemantic.Assign)]
		AGSGraphicsLayer Layer { get; }

		[Export ("symbolForGraphic:timeExtent:")]
		AGSSymbol SymbolForGraphic (AGSGraphic graphic, AGSTimeExtent timeExtent);

		[Export ("swatchForGraphic:size:")]
		UIImage SwatchForGraphic (AGSGraphic graphic, SizeF size);

		[Export ("swatchForGraphic:geometryType:size:")]
		UIImage SwatchForGraphic (AGSGraphic graphic, AGSGeometryType geometryType, SizeF size);
	}

	[BaseType (typeof (AGSRenderer))]
	public partial interface AGSSimpleRenderer {

		[Export ("symbol", ArgumentSemantic.Retain)]
		AGSSymbol Symbol { get; }

		[Export ("label", ArgumentSemantic.Copy)]
		string Label { get; }

		[Export ("rendererDescription", ArgumentSemantic.Copy)]
		string RendererDescription { get; }

		[Export ("initWithSymbol:")]
		IntPtr Constructor (AGSSymbol symbol);

		[Static, Export ("simpleRendererWithSymbol:")]
		NSObject SimpleRendererWithSymbol (AGSSymbol symbol);
	}

	[BaseType (typeof (AGSSymbol))]
	public partial interface AGSFillSymbol {

		[Export ("outline", ArgumentSemantic.Retain)]
		AGSSimpleLineSymbol Outline { get; set; }
	}

	[BaseType (typeof (AGSFillSymbol))]
	public partial interface AGSPictureFillSymbol {

		[Export ("size")]
		SizeF Size { get; set; }

		[Export ("image", ArgumentSemantic.Copy)]
		UIImage Image { get; }

		[Export ("angle")]
		double Angle { get; set; }

		[Export ("offset", ArgumentSemantic.Assign)]
		PointF Offset { get; set; }

		[Export ("scale", ArgumentSemantic.Assign)]
		SizeF Scale { get; set; }

		[Export ("initWithImage:")]
		IntPtr Constructor (UIImage image);

		[Static, Export ("pictureFillSymbolWithImage:")]
		NSObject PictureFillSymbolWithImage (UIImage image);

		[Export ("initWithImageNamed:")]
		IntPtr Constructor (string imageName);

		[Static, Export ("pictureFillSymbolWithImageNamed:")]
		NSObject PictureFillSymbolWithImageNamed (string imageName);

		[Export ("initWithContentsOfFile:")]
		IntPtr Constructor (string imagePath);
	}

	[BaseType (typeof (AGSSymbol))]
	public partial interface AGSMarkerSymbol {

		[Export ("angle")]
		double Angle { get; set; }

		[Export ("offset", ArgumentSemantic.Assign)]
		PointF Offset { get; set; }

		[Export ("leaderPoint", ArgumentSemantic.Assign)]
		PointF LeaderPoint { get; set; }

		[Export ("size", ArgumentSemantic.Assign)]
		SizeF Size { get; set; }
	}

	[BaseType (typeof (AGSFillSymbol))]
	public partial interface AGSSimpleFillSymbol {

		[Export ("style")]
		AGSSimpleFillSymbolStyle Style { get; set; }

		[Static, Export ("simpleFillSymbol")]
		AGSSimpleFillSymbol ();

		[Export ("initWithColor:outlineColor:")]
		IntPtr Constructor (UIColor fillColor, UIColor outlineColor);

		[Static, Export ("simpleFillSymbolWithColor:outlineColor:")]
		AGSSimpleFillSymbol SimpleFillSymbolWithColor (UIColor fillColor, UIColor outlineColor);
	}

	[BaseType (typeof (AGSSymbol))]
	public partial interface AGSSimpleLineSymbol {

		[Export ("style")]
		AGSSimpleLineSymbolStyle Style { get; set; }

		[Export ("width")]
		float Width { get; set; }

		[Static, Export ("simpleLineSymbol")]
		AGSSimpleLineSymbol SimpleLineSymbol ();

		[Export ("initWithColor:")]
		IntPtr Constructor (UIColor color);

		[Export ("initWithColor:width:")]
		IntPtr Constructor (UIColor color, float width);

		[Static, Export ("simpleLineSymbolWithColor:")]
		AGSSimpleLineSymbol SimpleLineSymbolWithColor (UIColor color);

		[Static, Export ("simpleLineSymbolWithColor:width:")]
		AGSSimpleLineSymbol SimpleLineSymbolWithColor (UIColor color, float width);
	}

	[BaseType (typeof (AGSMarkerSymbol))]
	public partial interface AGSSimpleMarkerSymbol {

		[Export ("style")]
		AGSSimpleMarkerSymbolStyle Style { get; set; }

		[Export ("outline", ArgumentSemantic.Retain)]
		AGSSimpleLineSymbol Outline { get; set; }

		[Static, Export ("simpleMarkerSymbol")]
		AGSSimpleMarkerSymbol SimpleMarkerSymbol ();

		[Export ("initWithColor:")]
		IntPtr Constructor (UIColor color);

		[Static, Export ("simpleMarkerSymbolWithColor:")]
		AGSSimpleMarkerSymbol SimpleMarkerSymbolWithColor (UIColor color);
	}

	[BaseType (typeof (AGSMarkerSymbol))]
	public partial interface AGSPictureMarkerSymbol {

		[Export ("image", ArgumentSemantic.Copy)]
		UIImage Image { get; set; }

		[Export ("error", ArgumentSemantic.Retain)]
		NSError Error { get; }

		[Export ("setImageWithData:")]
		void SetImageWithData (NSData data);

		[Export ("setImageWithName:")]
		void SetImageWithName (string name);

		[Export ("setImageWithContentsOfFile:")]
		void SetImageWithContentsOfFile (string path);

		[Export ("initWithImage:")]
		IntPtr Constructor (UIImage image);

		[Static, Export ("pictureMarkerSymbolWithImage:")]
		AGSPictureMarkerSymbol PictureMarkerSymbolWithImage (UIImage image);

		[Export ("initWithImageNamed:")]
		IntPtr Constructor (string imageName);

		[Export ("initWithContentsOfFile:")]
		IntPtr Constructor (string imagePath);

		[Static, Export ("pictureMarkerSymbolWithImageNamed:")]
		AGSPictureMarkerSymbol PictureMarkerSymbolWithImageNamed (string imageName);
	}

	[BaseType (typeof (AGSSymbol))]
	public partial interface AGSCompositeSymbol {

		[Export ("symbols", ArgumentSemantic.Copy)]
		AGSSymbol [] Symbols { get; }

		[Static, Export ("compositeSymbol")]
		NSObject CompositeSymbol ();

		[Export ("addSymbol:")]
		void AddSymbol (AGSSymbol symbol);

		[Export ("addSymbols:")]
		void AddSymbols (AGSSymbol [] symbols);

		[Export ("removeSymbol:")]
		void RemoveSymbol (AGSSymbol symbol);

		[Export ("removeAllSymbols")]
		void RemoveAllSymbols ();
	}

	[BaseType (typeof (AGSMarkerSymbol))]
	public partial interface AGSTextSymbol {

		[Export ("backgroundColor", ArgumentSemantic.Copy)]
		UIColor BackgroundColor { get; set; }

		[Export ("borderLineColor", ArgumentSemantic.Copy)]
		UIColor BorderLineColor { get; set; }

		[Export ("borderLineWidth")]
		float BorderLineWidth { get; set; }

		[Export ("vAlignment")]
		AGSTextSymbolVAlignment VAlignment { get; set; }

		[Export ("hAlignment")]
		AGSTextSymbolHAlignment HAlignment { get; set; }

		[Export ("fontFamily", ArgumentSemantic.Copy)]
		string FontFamily { get; set; }

		[Export ("fontSize")]
		float FontSize { get; set; }

		[Export ("text", ArgumentSemantic.Copy)]
		string Text { get; set; }

		[Export ("bold")]
		bool Bold { get; set; }

		[Export ("italic")]
		bool Italic { get; set; }

		[Export ("underline")]
		bool Underline { get; set; }

		[Export ("strikeThru")]
		bool StrikeThru { get; set; }

		[Export ("initWithText:color:")]
		IntPtr Constructor (string text, UIColor color);

		[Static, Export ("textSymbolWithText:color:")]
		AGSTextSymbol TextSymbolWithText (string text, UIColor color);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSUniqueValue : AGSCoding {

		[Export ("value", ArgumentSemantic.Copy)]
		string Value { get; }

		[Export ("label", ArgumentSemantic.Copy)]
		string Label { get; }

		[Export ("valueDescription", ArgumentSemantic.Copy)]
		string ValueDescription { get; }

		[Export ("symbol", ArgumentSemantic.Retain)]
		AGSSymbol Symbol { get; }

		[Static, Export ("uniqueValueWithValue:symbol:")]
		NSObject UniqueValueWithValue (string value, AGSSymbol symbol);

		[Export ("initWithValue:label:description:symbol:")]
		IntPtr Constructor (string value, string label, string description, AGSSymbol symbol);
	}

	[BaseType (typeof (AGSRenderer))]
	public partial interface AGSUniqueValueRenderer {

		[Export ("defaultSymbol", ArgumentSemantic.Retain)]
		AGSSymbol DefaultSymbol { get; set; }

		[Export ("fields", ArgumentSemantic.Copy)]
		string [] Fields { get; set; }

		[Export ("fieldDelimiter", ArgumentSemantic.Copy)]
		string FieldDelimiter { get; set; }

		[Export ("defaultLabel", ArgumentSemantic.Copy)]
		string DefaultLabel { get; set; }

		[Export ("uniqueValues", ArgumentSemantic.Copy)]
		AGSUniqueValue [] UniqueValues { get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSClassBreak : AGSCoding {

		[Export ("label", ArgumentSemantic.Copy)]
		string Label { get; set; }

		[Export ("breakDescription", ArgumentSemantic.Copy)]
		string BreakDescription { get; set; }

		[Export ("maxValue")]
		double MaxValue { get; set; }

		[Export ("symbol", ArgumentSemantic.Retain)]
		AGSSymbol Symbol { get; set; }

		[Export ("initWithLabel:description:maxValue:symbol:")]
		IntPtr Constructor (string label, string description, double maxValue, AGSSymbol symbol);

		[Static, Export ("classBreakInfoWithLabel:description:maxValue:symbol:")]
		NSObject ClassBreakInfoWithLabel (string label, string description, double maxValue, AGSSymbol symbol);

		[Export ("compare:")]
		NSComparisonResult Compare (AGSClassBreak anotherClassBreak);
	}

	[BaseType (typeof (AGSRenderer))]
	public partial interface AGSClassBreaksRenderer {

		[Export ("field", ArgumentSemantic.Copy)]
		string Field { get; set; }

		[Export ("classBreaks", ArgumentSemantic.Copy)]
		AGSClassBreak [] ClassBreaks { get; set; }

		[Export ("minValue")]
		double MinValue { get; set; }

		[Export ("defaultSymbol", ArgumentSemantic.Retain)]
		AGSSymbol DefaultSymbol { get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSEditResult : AGSCoding {

		[Export ("objectId")]
		int ObjectId { get; }

		[Export ("globalId", ArgumentSemantic.Copy)]
		string GlobalId { get; }

		[Export ("success")]
		bool Success { get; }

		[Export ("error", ArgumentSemantic.Retain)]
		AGSEditResultError Error { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSEditResultError : AGSCoding {

		[Export ("code")]
		int Code { get; }

		[Export ("errorDescription", ArgumentSemantic.Copy)]
		string ErrorDescription { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSEditFieldsInfo : AGSCoding {

		[Export ("creationDateField", ArgumentSemantic.Copy)]
		string CreationDateField { get; }

		[Export ("creatorField", ArgumentSemantic.Copy)]
		string CreatorField { get; }

		[Export ("editDateField", ArgumentSemantic.Copy)]
		string EditDateField { get; }

		[Export ("editorField", ArgumentSemantic.Copy)]
		string EditorField { get; }
	}

	[BaseType (typeof (AGSGraphicsLayer))]
	public partial interface AGSFeatureLayer : AGSCoding, AGSInfoTemplateDelegate, AGSSecuredResource {

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		[Export ("mode")]
		AGSFeatureLayerMode Mode { get; }

		[Export ("credential", ArgumentSemantic.Copy)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("requestCachePolicy")]
		NSURLRequestCachePolicy RequestCachePolicy { get; set; }

		[Export ("timeoutInterval")]
		double TimeoutInterval { get; set; }

		[Export ("layerId")]
		uint LayerId { get; }

		[Export ("serviceLayerName", ArgumentSemantic.Copy)]
		string ServiceLayerName { get; }

		[Export ("layerDescription", ArgumentSemantic.Copy)]
		string LayerDescription { get; }

		[Export ("type", ArgumentSemantic.Copy)]
		string Type { get; }

		[Export ("geometryType")]
		AGSGeometryType GeometryType { get; }

		[Export ("displayField", ArgumentSemantic.Copy)]
		string DisplayField { get; }

		[Export ("fields", ArgumentSemantic.Copy)]
		AGSField [] Fields { get; }

		[Export ("objectIdField", ArgumentSemantic.Copy)]
		string ObjectIdField { get; }

		[Export ("typeIdField", ArgumentSemantic.Copy)]
		string TypeIdField { get; }

		[Export ("defaultDefinitionExpression", ArgumentSemantic.Copy)]
		string DefaultDefinitionExpression { get; }

		[Export ("types", ArgumentSemantic.Copy)]
		AGSFeatureType [] Types { get; }

		[Export ("templates", ArgumentSemantic.Copy)]
		AGSFeatureTemplate [] Templates { get; }

		[Export ("relationships", ArgumentSemantic.Copy)]
		AGSRelationship [] Relationships { get; }

		[Export ("timeInfo", ArgumentSemantic.Retain)]
		AGSTimeInfo TimeInfo { get; }

		[Export ("attachments")]
		bool Attachments { [Bind ("hasAttachments")] get; }

		[Export ("definitionExpression", ArgumentSemantic.Copy)]
		string DefinitionExpression { get; set; }

		[Export ("editingDelegate", ArgumentSemantic.Assign)]
		AGSFeatureLayerEditingDelegate EditingDelegate { get; set; }

		[Export ("queryDelegate", ArgumentSemantic.Assign)]
		AGSFeatureLayerQueryDelegate QueryDelegate { get; set; }

		[Export ("outFields", ArgumentSemantic.Copy)]
		string [] OutFields { get; set; }

		[Export ("maxAllowableOffset")]
		double MaxAllowableOffset { get; set; }

		[Export ("queryable")]
		bool Queryable { [Bind ("isQueryable")] get; }

		[Export ("infoTemplateDelegate", ArgumentSemantic.Assign)]
		AGSInfoTemplateDelegate InfoTemplateDelegate { get; set; }

		[Export ("expirationInterval")]
		double ExpirationInterval { get; set; }

		[Export ("autoRefreshOnExpiration")]
		bool AutoRefreshOnExpiration { get; set; }

		[Export ("bufferFactor")]
		float BufferFactor { get; set; }

		[Export ("constraintFactor")]
		float ConstraintFactor { get; set; }

		[Export ("version")]
		float Version { get; }

		[Export ("serviceFullEnvelope", ArgumentSemantic.Retain)]
		AGSEnvelope ServiceFullEnvelope { get; }

		[Export ("labelingInfo", ArgumentSemantic.Copy)]
		AGSLabelClass [] LabelingInfo { get; }

		[Export ("timeDefinition", ArgumentSemantic.Retain)]
		AGSTimeExtent TimeDefinition { get; set; }

		[Export ("editFieldsInfo", ArgumentSemantic.Retain)]
		AGSEditFieldsInfo EditFieldsInfo { get; }

		[Export ("canUpdateGeometry")]
		bool CanUpdateGeometry { get; }

		[Export ("canCreate")]
		bool CanCreate { get; }

		[Export ("canUpdate")]
		bool CanUpdate { get; }

		[Export ("canDelete")]
		bool CanDelete { get; }

		[Export ("initWithURL:mode:")]
		IntPtr Constructor (NSUrl url, AGSFeatureLayerMode mode);

		[Export ("initWithURL:mode:credential:")]
		IntPtr Constructor (NSUrl url, AGSFeatureLayerMode mode, AGSCredential cred);

		[Export ("initWithURL:mode:error:")]
		IntPtr Constructor (NSUrl url, AGSFeatureLayerMode mode, out NSError error);

		[Export ("initWithURL:mode:credential:error:")]
		IntPtr Constructor (NSUrl url, AGSFeatureLayerMode mode, AGSCredential cred, out NSError error);

		[Static, Export ("featureServiceLayerWithURL:mode:")]
		NSObject FeatureServiceLayerWithURL (NSUrl url, AGSFeatureLayerMode mode);

		[Static, Export ("featureServiceLayerWithURL:mode:credential:")]
		NSObject FeatureServiceLayerWithURL (NSUrl url, AGSFeatureLayerMode mode, AGSCredential cred);

		[Export ("initWithLayerDefinitionJSON:featureSetJSON:")]
		IntPtr Constructor (NSDictionary layerDefinitionJSON, NSDictionary featureSetJSON);

		[Export ("initWithLayerDefinitionJSON:featureSet:")]
		IntPtr Constructor (NSDictionary layerDefinitionJSON, AGSFeatureSet featureSet);

		[Export ("queryFeatures:")]
		NSOperation QueryFeatures (AGSQuery query);

		[Export ("queryIds:")]
		NSOperation QueryIds (AGSQuery query);

		[Export ("queryFeatureCount:")]
		NSOperation QueryFeatureCount (AGSQuery query);

		[Export ("queryRelatedFeatures:")]
		NSOperation QueryRelatedFeatures (AGSRelationshipQuery query);

		[Export ("selectFeaturesWithQuery:selectionMethod:")]
		NSOperation SelectFeaturesWithQuery (AGSQuery query, AGSFeatureLayerSelectionMethod selectionMethod);

		[Export ("selectFeature:withSelectionMethod:")]
		void SelectFeature (AGSGraphic feature, AGSFeatureLayerSelectionMethod selectionMethod);

		[Export ("clearSelection")]
		void ClearSelection ();

		[Export ("lookupFeatureWithObjectId:")]
		AGSGraphic LookupFeatureWithObjectId (int objectId);

		[Export ("refresh")]
		void Refresh ();

		[Export ("objectIdForFeature:")]
		int ObjectIdForFeature (AGSGraphic feature);

		[Export ("resubmit")]
		void Resubmit ();

		[Export ("resubmitWithURL:credential:")]
		void ResubmitWithURL (NSUrl url, AGSCredential cred);

		[Export ("templateForFeature:type:")]
		AGSFeatureTemplate TemplateForFeature (AGSGraphic feature, out AGSFeatureType type);

		[Export ("findFieldWithName:")]
		AGSField FindFieldWithName (string fieldName);

		[Export ("attachmentManagerForFeature:")]
		AGSAttachmentManager AttachmentManagerForFeature (AGSGraphic feature);

		[Export ("clearAttachmentManagers")]
		void ClearAttachmentManagers ();

		[Export ("clearAttachmentManagerForFeatureWithObjectId:")]
		void ClearAttachmentManagerForFeatureWithObjectId (int objectId);

		[Export ("canUpdateFeature:")]
		bool CanUpdateFeature (AGSGraphic feature);

		[Export ("canDeleteFeature:")]
		bool CanDeleteFeature (AGSGraphic feature);

		[Export ("editSummaryForFeature:")]
		string EditSummaryForFeature (AGSGraphic feature);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSFeatureLayerQueryDelegate {

		[Export ("featureLayer:operation:didQueryFeaturesWithFeatureSet:")]
		void DidQueryFeaturesWithFeatureSet (AGSFeatureLayer featureLayer, NSOperation op, AGSFeatureSet featureSet);

		[Export ("featureLayer:operation:didFailQueryFeaturesWithError:")]
		void DidFailQueryFeaturesWithError (AGSFeatureLayer featureLayer, NSOperation op, NSError error);

		[Export ("featureLayer:operation:didQueryObjectIdsWithResults:")]
		void DidQueryObjectIdsWithResults (AGSFeatureLayer featureLayer, NSOperation op, int [] objectIds);

		[Export ("featureLayer:operation:didFailQueryObjectIdsWithError:")]
		void DidFailQueryObjectIdsWithError (AGSFeatureLayer featureLayer, NSOperation op, NSError error);

		[Export ("featureLayer:operation:didQueryFeatureCountWithResult:")]
		void DidQueryFeatureCountWithResult (AGSFeatureLayer featureLayer, NSOperation op, int count);

		[Export ("featureLayer:operation:didFailQueryFeatureCountWithError:")]
		void DidFailQueryFeatureCountWithError (AGSFeatureLayer featureLayer, NSOperation op, NSError error);

		[Export ("featureLayer:operation:didQueryRelatedFeaturesWithResults:")]
		void DidQueryRelatedFeaturesWithResults (AGSFeatureLayer featureLayer, NSOperation op, NSDictionary relatedFeatures);

		[Export ("featureLayer:operation:didFailQueryRelatedFeaturesWithError:")]
		void DidFailQueryRelatedFeaturesWithError (AGSFeatureLayer featureLayer, NSOperation op, NSError error);

		[Export ("featureLayer:operation:didSelectFeaturesWithFeatureSet:")]
		void DidSelectFeaturesWithFeatureSet (AGSFeatureLayer featureLayer, NSOperation op, AGSFeatureSet featureSet);

		[Export ("featureLayer:operation:didFailSelectFeaturesWithError:")]
		void DidFailSelectFeaturesWithError (AGSFeatureLayer featureLayer, NSOperation op, NSError error);
	}

	[Category, BaseType (typeof (AGSFeatureLayer))]
	public partial interface Editing_AGSFeatureLayer {

		[Export ("featureWithTemplate:")]
		AGSGraphic FeatureWithTemplate (AGSFeatureTemplate featureTemplate);

		[Export ("featureWithType:")]
		AGSGraphic FeatureWithType (AGSFeatureType featureType);

		[Export ("addFeatures:")]
		NSOperation AddFeatures (AGSGraphic [] features);

		[Export ("updateFeatures:")]
		NSOperation UpdateFeatures (AGSGraphic [] features);

		[Export ("deleteFeaturesWithObjectIds:")]
		NSOperation DeleteFeaturesWithObjectIds (int [] objectIds);

		[Export ("deleteFeaturesWithWhereClause:geometry:spatialRelation:")]
		NSOperation DeleteFeaturesWithWhereClause (string where, AGSGeometry geometry, AGSSpatialRelationship spatialRelation);

		[Export ("applyEditsWithFeaturesToAdd:toUpdate:toDelete:")]
		NSOperation ApplyEditsWithFeaturesToAdd (AGSGraphic [] addFeatures, AGSGraphic [] updateFeatures, int [] objectIds);

		[Export ("addAttachment:data:filename:contentType:")]
		NSOperation AddAttachment (uint objectId, NSData data, string filename, string contentType);

		[Export ("addAttachment:data:filename:")]
		NSOperation AddAttachment (uint objectId, NSData data, string filename);

		[Export ("addAttachment:filepath:contentType:")]
		NSOperation AddAttachment (uint objectId, string filepath, string contentType);

		[Export ("addAttachment:filepath:")]
		NSOperation AddAttachment (uint objectId, string filepath);

		[Export ("updateAttachment:data:filename:contentType:attachmentId:")]
		NSOperation UpdateAttachment (uint objectId, NSData data, string filename, string contentType, int attachmentId);

		[Export ("updateAttachment:data:filename:attachmentId:")]
		NSOperation UpdateAttachment (uint objectId, NSData data, string filename, int attachmentId);

		[Export ("deleteAttachmentsForObjectId:attachmentIds:")]
		NSOperation DeleteAttachmentsForObjectId (uint objectId, int [] attachmentIds);

		[Export ("queryAttachmentInfosForObjectId:")]
		NSOperation QueryAttachmentInfosForObjectId (uint objectId);

		[Export ("retrieveAttachmentForObjectId:attachmentId:")]
		NSOperation RetrieveAttachmentForObjectId (uint objectId, int attachmentId);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSFeatureLayerEditingDelegate {

		[Export ("featureLayer:operation:didFeatureEditsWithResults:")]
		void Operation (AGSFeatureLayer featureLayer, NSOperation op, AGSFeatureLayerEditResults editResults);

		[Export ("featureLayer:operation:didFailFeatureEditsWithError:")]
		void Operation (AGSFeatureLayer featureLayer, NSOperation op, NSError error);

		[Export ("featureLayer:operation:didAttachmentEditsWithResults:")]
		void Operation (AGSFeatureLayer featureLayer, NSOperation op, AGSFeatureLayerAttachmentResults attachmentResults);

		[Export ("featureLayer:operation:didFailAttachmentEditsWithError:")]
		void Operation (AGSFeatureLayer featureLayer, NSOperation op, NSError error);

		[Export ("featureLayer:operation:didQueryAttachmentInfosWithResults:")]
		void Operation (AGSFeatureLayer featureLayer, NSOperation op, [Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSFeatureLayer+Editing.h", Line = 342)] NSObject [] attachmentInfos);

		[Export ("featureLayer:operation:didFailQueryAttachmentInfosWithError:")]
		void Operation (AGSFeatureLayer featureLayer, NSOperation op, NSError error);

		[Export ("featureLayer:operation:didRetrieveAttachmentWithData:")]
		void Operation (AGSFeatureLayer featureLayer, NSOperation op, NSData attachmentData);

		[Export ("featureLayer:operation:didFailRetrieveAttachmentWithError:")]
		void Operation (AGSFeatureLayer featureLayer, NSOperation op, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSFeatureLayerEditResults {

		[Export ("addResults", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSFeatureLayerEditResults.h", Line = 36)]
		NSObject [] AddResults { get; }

		[Export ("updateResults", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSFeatureLayerEditResults.h", Line = 41)]
		NSObject [] UpdateResults { get; }

		[Export ("deleteResults", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSFeatureLayerEditResults.h", Line = 46)]
		NSObject [] DeleteResults { get; }

		[Export ("deleteWithQuerySuccess")]
		bool DeleteWithQuerySuccess { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSFeatureLayerAttachmentResults {

		[Export ("addResult", ArgumentSemantic.Retain)]
		AGSEditResult AddResult { get; }

		[Export ("updateResult", ArgumentSemantic.Retain)]
		AGSEditResult UpdateResult { get; }

		[Export ("deleteResults", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSFeatureLayerAttachmentResults.h", Line = 45)]
		NSObject [] DeleteResults { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSAttachment {

		[Export ("attachmentInfo", ArgumentSemantic.Retain)]
		AGSAttachmentInfo AttachmentInfo { get; }

		[Export ("filepath", ArgumentSemantic.Copy)]
		string Filepath { get; }

		[Export ("editState")]
		AGSAttachmentEditState EditState { get; }

		[Export ("editResultError", ArgumentSemantic.Retain)]
		AGSEditResultError EditResultError { get; }

		[Export ("networkError", ArgumentSemantic.Retain)]
		NSError NetworkError { get; }

		[Export ("isDownloading")]
		bool IsDownloading { get; }

		[Export ("markForDeletion:")]
		void MarkForDeletion (bool del);

		[Export ("existsOnServer"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSAttachment.h", Line = 88)]
		bool ExistsOnServer { get; }

		[Export ("isLocal"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSAttachment.h", Line = 93)]
		bool IsLocal { get; }

		[Export ("thumbnail"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSAttachment.h", Line = 98)]
		UIImage Thumbnail { get; }

		[Export ("data"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSAttachment.h", Line = 104)]
		NSData Data { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSAttachmentManager : AGSFeatureLayerEditingDelegate {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSAttachmentManagerDelegate Delegate { get; set; }

		[Export ("featureLayer", ArgumentSemantic.Assign)]
		AGSFeatureLayer FeatureLayer { get; }

		[Export ("featureObjectId")]
		int FeatureObjectId { get; }

		[Export ("downloadAttachmentInfosError", ArgumentSemantic.Retain)]
		NSError DownloadAttachmentInfosError { get; }

		[Export ("postingLocalEdits")]
		bool PostingLocalEdits { get; }

		[Export ("attachments", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSAttachmentManager.h", Line = 72)]
		NSObject [] Attachments { get; }

		[Export ("attachmentForId:")]
		AGSAttachment AttachmentForId (int attachmentId);

		[Export ("hasLocalEdits"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSAttachmentManager.h", Line = 83)]
		bool HasLocalEdits { get; }

		[Export ("cancelLocalEdits")]
		void CancelLocalEdits ();

		[Export ("addAttachmentAsJpgWithImage:name:")]
		AGSAttachment AddAttachmentAsJpgWithImage (UIImage image, string name);

		[Export ("addAttachmentWithUIImagePickerControllerInfoDictionary:")]
		AGSAttachment AddAttachmentWithUIImagePickerControllerInfoDictionary (NSDictionary info);

		[Export ("addAttachmentWithData:name:contentType:")]
		AGSAttachment AddAttachmentWithData (NSData data, string name, string contentType);

		[Export ("markAttachment:forDeletion:")]
		void MarkAttachment (AGSAttachment attachment, bool del);

		[Export ("downloadAttachmentInfos")]
		void DownloadAttachmentInfos ();

		[Export ("downloadAttachmentDataForId:")]
		void DownloadAttachmentDataForId (int attachmentId);

		[Export ("postLocalEditsToServer")]
		void PostLocalEditsToServer ();

		[Export ("cancelPostLocalEditsToServer")]
		void CancelPostLocalEditsToServer ();

		[Export ("cancelDownloadDataForId:")]
		void CancelDownloadDataForId (int attachmentId);

		[Export ("cancelAllDownloadDataOperations")]
		void CancelAllDownloadDataOperations ();

		[Export ("cancelDownloadAttachmentInfos")]
		void CancelDownloadAttachmentInfos ();
	}

	[Model]
	public partial interface AGSAttachmentManagerDelegate {

		[Export ("attachmentManager:didDownloadAttachmentInfos:")]
		void DidDownloadAttachmentInfos (AGSAttachmentManager attachmentManager, [Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSAttachmentManager.h", Line = 199)] NSObject [] attachmentInfos);

		[Export ("attachmentManager:didDownloadDataForAttachment:")]
		void DidDownloadDataForAttachment (AGSAttachmentManager attachmentManager, AGSAttachment attachment);

		[Export ("attachmentManager:didPostLocalEditsToServer:")]
		void DidPostLocalEditsToServer (AGSAttachmentManager attachmentManager, [Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSAttachmentManager.h", Line = 229)] NSObject [] attachmentsPosted);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSAttachmentInfo : AGSCoding {

		[Export ("attachmentId")]
		int AttachmentId { get; }

		[Export ("contentType", ArgumentSemantic.Copy)]
		string ContentType { get; }

		[Export ("size")]
		int Size { get; }

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("isEqualToAttachmentInfo:")]
		bool IsEqualToAttachmentInfo (AGSAttachmentInfo other);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSFeatureTemplate : AGSCoding {

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("featureDescription", ArgumentSemantic.Copy)]
		string FeatureDescription { get; }

		[Export ("prototype", ArgumentSemantic.Retain)]
		AGSGraphic Prototype { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSFeatureType : AGSCoding {

		[Export ("typeId", ArgumentSemantic.Copy)]
		NSObject TypeId { get; }

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("templates", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSFeatureType.h", Line = 45)]
		NSObject [] Templates { get; }

		[Export ("domains", ArgumentSemantic.Copy)]
		NSDictionary Domains { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSLabelClass : AGSCoding {

		[Export ("placement")]
		AGSLabelPlacement Placement { get; }

		[Export ("labelExpression", ArgumentSemantic.Copy)]
		string LabelExpression { get; }

		[Export ("useCodedValues")]
		bool UseCodedValues { get; }

		[Export ("symbol", ArgumentSemantic.Retain)]
		AGSTextSymbol Symbol { get; }

		[Export ("minScale")]
		float MinScale { get; }

		[Export ("maxScale")]
		float MaxScale { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSRelationship : AGSCoding {

		[Export ("relationshipId")]
		int RelationshipId { get; }

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("relatedTableId")]
		int RelatedTableId { get; }
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSMapViewTouchDelegate {

		[Notification, Field ("AGSSketchGraphicsLayerGeometryDidChangeNotification")]
		NSString AGSSketchGraphicsLayerGeometryDidChangeNotification { get; }
	}

	[BaseType (typeof (AGSGraphicsLayer))]
	public partial interface AGSSketchGraphicsLayer : AGSMapViewTouchDelegate {

		[Export ("geometry", ArgumentSemantic.Retain)]
		AGSGeometry Geometry { get; set; }

		[Export ("mainSymbol", ArgumentSemantic.Retain)]
		AGSCompositeSymbol MainSymbol { get; set; }

		[Export ("selectedVertexSymbol", ArgumentSemantic.Retain)]
		AGSMarkerSymbol SelectedVertexSymbol { get; set; }

		[Export ("vertexSymbol", ArgumentSemantic.Retain)]
		AGSMarkerSymbol VertexSymbol { get; set; }

		[Export ("midVertexSymbol", ArgumentSemantic.Retain)]
		AGSMarkerSymbol MidVertexSymbol { get; set; }

		[Export ("undoManager", ArgumentSemantic.Retain)]
		NSUndoManager UndoManager { get; }

		[Export ("initWithGeometry:")]
		IntPtr Constructor (AGSGeometry geometry);

		[Export ("removeSelectedVertex"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSSketchGraphicsLayer.h", Line = 93)]
		bool RemoveSelectedVertex { get; }

		[Export ("removeVertexInPart:atIndex:")]
		void RemoveVertexInPart (int partIndex, int coordinateIndex);

		[Export ("addPart")]
		void AddPart ();

		[Export ("removePartAtIndex:")]
		void RemovePartAtIndex (int partIndex);

		[Export ("removeSelectedPart"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSSketchGraphicsLayer.h", Line = 117)]
		bool RemoveSelectedPart { get; }

		[Export ("clear")]
		void Clear ();

		[Export ("applyGeometry:")]
		void ApplyGeometry (AGSGeometry geometry);

		[Export ("insertVertex:inPart:atIndex:")]
		void InsertVertex (AGSPoint point, int partIndex, int coordinateIndex);

		[Export ("moveVertexInPart:atIndex:toPoint:")]
		void MoveVertexInPart (int partIndex, int coordinateIndex, AGSPoint point);

		[Export ("selectLastVertex")]
		void SelectLastVertex ();

		[Export ("mapView:didClickAtPoint:mapPoint:graphics:")]
		void MapView (AGSMapView mapView, PointF screen, AGSPoint mappoint, NSDictionary graphics);

		[Export ("mapView:didEndTapAndHoldAtPoint:mapPoint:graphics:")]
		void MapView (AGSMapView mapView, PointF screen, AGSPoint mappoint, NSDictionary graphics);

		[Static, Export ("defaultMainSymbol"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSSketchGraphicsLayer.h", Line = 164)]
		AGSCompositeSymbol DefaultMainSymbol { get; }

		[Static, Export ("defaultSelectedVertexSymbol"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSSketchGraphicsLayer.h", Line = 169)]
		AGSMarkerSymbol DefaultSelectedVertexSymbol { get; }

		[Static, Export ("defaultVertexSymbol"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSSketchGraphicsLayer.h", Line = 174)]
		AGSMarkerSymbol DefaultVertexSymbol { get; }

		[Static, Export ("defaultMidVertexSymbol"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSSketchGraphicsLayer.h", Line = 179)]
		AGSMarkerSymbol DefaultMidVertexSymbol { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSPortal : AGSSecuredResource {

		[Export ("URL", ArgumentSemantic.Retain)]
		NSUrl URL { get; }

		[Export ("credential", ArgumentSemantic.Copy)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSPortalDelegate Delegate { get; set; }

		[Export ("portalInfo", ArgumentSemantic.Retain)]
		AGSPortalInfo PortalInfo { get; }

		[Export ("user", ArgumentSemantic.Retain)]
		AGSPortalUser User { get; }

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSUrl url, AGSCredential cred);

		[Export ("resubmit")]
		void Resubmit ();

		[Export ("resubmitWithURL:credential:")]
		void ResubmitWithURL (NSUrl url, AGSCredential cred);

		[Export ("findItemsWithQueryParams:")]
		NSOperation FindItemsWithQueryParams (AGSPortalQueryParams queryParams);

		[Export ("findGroupsWithQueryParams:")]
		NSOperation FindGroupsWithQueryParams (AGSPortalQueryParams queryParams);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSPortalDelegate {

		[Export ("portalDidLoad:")]
		void  (AGSPortal portal);

		[Export ("portal:didFailToLoadWithError:")]
		void DidFailToLoadWithError (AGSPortal portal, NSError error);

		[Export ("portal:operation:didFindItems:")]
		void Operation (AGSPortal portal, NSOperation op, AGSPortalQueryResultSet resultSet);

		[Export ("portal:operation:didFailToFindItemsForQueryParams:withError:")]
		void Operation (AGSPortal portal, NSOperation op, AGSPortalQueryParams queryParams, NSError error);

		[Export ("portal:operation:didFindGroups:")]
		void Operation (AGSPortal portal, NSOperation op, AGSPortalQueryResultSet resultSet);

		[Export ("portal:operation:didFailToFindGroupsForQueryParams:withError:")]
		void Operation (AGSPortal portal, NSOperation op, AGSPortalQueryParams queryParams, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSPortalFolder : AGSCoding {

		[Export ("folderId", ArgumentSemantic.Copy)]
		string FolderId { get; }

		[Export ("title", ArgumentSemantic.Copy)]
		string Title { get; }

		[Export ("created", ArgumentSemantic.Retain)]
		NSDate Created { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSPortalGroup : AGSCoding {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSPortalGroupDelegate Delegate { get; set; }

		[Export ("portal", ArgumentSemantic.Assign)]
		AGSPortal Portal { get; }

		[Export ("groupId", ArgumentSemantic.Copy)]
		string GroupId { get; }

		[Export ("title", ArgumentSemantic.Copy)]
		string Title { get; }

		[Export ("owner", ArgumentSemantic.Copy)]
		string Owner { get; }

		[Export ("groupDescription", ArgumentSemantic.Copy)]
		string GroupDescription { get; }

		[Export ("snippet", ArgumentSemantic.Copy)]
		string Snippet { get; }

		[Export ("thumbnailFileName", ArgumentSemantic.Copy)]
		string ThumbnailFileName { get; }

		[Export ("tags", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalGroup.h", Line = 80)]
		NSObject [] Tags { get; }

		[Export ("created", ArgumentSemantic.Retain)]
		NSDate Created { get; }

		[Export ("modified", ArgumentSemantic.Retain)]
		NSDate Modified { get; }

		[Export ("access")]
		AGSPortalAccess Access { get; }

		[Export ("isInvitationOnly")]
		bool IsInvitationOnly { get; }

		[Export ("thumbnail", ArgumentSemantic.Retain)]
		UIImage Thumbnail { get; }

		[Export ("users", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalGroup.h", Line = 113)]
		NSObject [] Users { get; }

		[Export ("admins", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalGroup.h", Line = 118)]
		NSObject [] Admins { get; }

		[Export ("fetchThumbnail"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalGroup.h", Line = 124)]
		NSOperation FetchThumbnail { get; }

		[Export ("fetchUsers"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalGroup.h", Line = 130)]
		NSOperation FetchUsers { get; }
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSPortalGroupDelegate {

		[Export ("portalGroup:operation:didFetchThumbnail:")]
		void Operation (AGSPortalGroup portalGroup, NSOperation op, UIImage thumbnail);

		[Export ("portalGroup:operation:didFailToFetchThumbnailWithError:")]
		void Operation (AGSPortalGroup portalGroup, NSOperation op, NSError error);

		[Export ("portalGroup:operation:didFetchUsers:admins:")]
		void Operation (AGSPortalGroup portalGroup, NSOperation op, [Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalGroup.h", Line = 170)] NSObject [] users, [Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalGroup.h", Line = 170)] NSObject [] admins);

		[Export ("portalGroup:operation:didFailToFetchUsersWithError:")]
		void Operation (AGSPortalGroup portalGroup, NSOperation op, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSPortalInfo : AGSCoding {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSPortalInfoDelegate Delegate { get; set; }

		[Export ("portal", ArgumentSemantic.Assign)]
		AGSPortal Portal { get; }

		[Export ("organizationId", ArgumentSemantic.Copy)]
		string OrganizationId { get; }

		[Export ("organizationName", ArgumentSemantic.Copy)]
		string OrganizationName { get; }

		[Export ("organizationDescription", ArgumentSemantic.Copy)]
		string OrganizationDescription { get; }

		[Export ("portalName", ArgumentSemantic.Copy)]
		string PortalName { get; }

		[Export ("featuredItemsGroupQuery", ArgumentSemantic.Copy)]
		string FeaturedItemsGroupQuery { get; }

		[Export ("canSharePublic")]
		bool CanSharePublic { get; }

		[Export ("canSearchPublic")]
		bool CanSearchPublic { get; }

		[Export ("organizationThumbnailFileName", ArgumentSemantic.Copy)]
		string OrganizationThumbnailFileName { get; }

		[Export ("portalThumbnailFileName", ArgumentSemantic.Copy)]
		string PortalThumbnailFileName { get; }

		[Export ("basemapGalleryGroupQuery", ArgumentSemantic.Copy)]
		string BasemapGalleryGroupQuery { get; }

		[Export ("defaultBasemap", ArgumentSemantic.Retain)]
		AGSWebMapBaseMap DefaultBasemap { get; }

		[Export ("defaultExtent", ArgumentSemantic.Retain)]
		AGSEnvelope DefaultExtent { get; }

		[Export ("homepageFeaturedContentGroupQuery", ArgumentSemantic.Copy)]
		string HomepageFeaturedContentGroupQuery { get; }

		[Export ("featuredGroupsQueries", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalInfo.h", Line = 120)]
		NSObject [] FeaturedGroupsQueries { get; }

		[Export ("portalThumbnail", ArgumentSemantic.Retain)]
		UIImage PortalThumbnail { get; }

		[Export ("organizationThumbnail", ArgumentSemantic.Retain)]
		UIImage OrganizationThumbnail { get; }

		[Export ("access")]
		AGSPortalAccess Access { get; }

		[Export ("portalMode")]
		AGSPortalMode PortalMode { get; }

		[Export ("customBaseUrl", ArgumentSemantic.Copy)]
		string CustomBaseUrl { get; }

		[Export ("urlKey", ArgumentSemantic.Copy)]
		string UrlKey { get; }

		[Export ("geocodeServiceUrls", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalInfo.h", Line = 164)]
		NSObject [] GeocodeServiceUrls { get; }

		[Export ("routeServiceUrl", ArgumentSemantic.Retain)]
		NSUrl RouteServiceUrl { get; }

		[Export ("geometryServiceUrl", ArgumentSemantic.Retain)]
		NSUrl GeometryServiceUrl { get; }

		[Export ("printTaskUrl", ArgumentSemantic.Retain)]
		NSUrl PrintTaskUrl { get; }

		[Export ("fetchPortalThumbnail"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalInfo.h", Line = 185)]
		NSOperation FetchPortalThumbnail { get; }

		[Export ("fetchOrganizationThumbnail"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalInfo.h", Line = 190)]
		NSOperation FetchOrganizationThumbnail { get; }
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSPortalInfoDelegate {

		[Export ("portalInfo:operation:didFetchPortalThumbnail:")]
		void Operation (AGSPortalInfo portalInfo, NSOperation op, UIImage thumbnail);

		[Export ("portalInfo:operation:didFailToFetchPortalThumbnailWithError:")]
		void Operation (AGSPortalInfo portalInfo, NSOperation op, NSError error);

		[Export ("portalInfo:operation:didFetchOrganizationThumbnail:")]
		void Operation (AGSPortalInfo portalInfo, NSOperation op, UIImage thumbnail);

		[Export ("portalInfo:operation:didFailToFetchOrganizationThumbnailWithError:")]
		void Operation (AGSPortalInfo portalInfo, NSOperation op, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSPortalItem : AGSCoding {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSPortalItemDelegate Delegate { get; set; }

		[Export ("portal", ArgumentSemantic.Retain)]
		AGSPortal Portal { get; }

		[Export ("itemId", ArgumentSemantic.Copy)]
		string ItemId { get; }

		[Export ("owner", ArgumentSemantic.Copy)]
		string Owner { get; }

		[Export ("title", ArgumentSemantic.Copy)]
		string Title { get; }

		[Export ("type")]
		AGSPortalItemType Type { get; }

		[Export ("itemDescription", ArgumentSemantic.Copy)]
		string ItemDescription { get; }

		[Export ("snippet", ArgumentSemantic.Copy)]
		string Snippet { get; }

		[Export ("credits", ArgumentSemantic.Copy)]
		string Credits { get; }

		[Export ("license", ArgumentSemantic.Copy)]
		string License { get; }

		[Export ("thumbnailFileName", ArgumentSemantic.Copy)]
		string ThumbnailFileName { get; }

		[Export ("locale", ArgumentSemantic.Retain)]
		NSLocale Locale { get; }

		[Export ("tags", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalItem.h", Line = 104)]
		NSObject [] Tags { get; }

		[Export ("created", ArgumentSemantic.Retain)]
		NSDate Created { get; }

		[Export ("modified", ArgumentSemantic.Retain)]
		NSDate Modified { get; }

		[Export ("extent", ArgumentSemantic.Retain)]
		AGSEnvelope Extent { get; }

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; }

		[Export ("size")]
		int Size { get; }

		[Export ("numComments")]
		int NumComments { get; }

		[Export ("numRatings")]
		int NumRatings { get; }

		[Export ("avgRating")]
		float AvgRating { get; }

		[Export ("numViews")]
		int NumViews { get; }

		[Export ("access")]
		AGSPortalAccess Access { get; }

		[Export ("thumbnail", ArgumentSemantic.Retain)]
		UIImage Thumbnail { get; }

		[Export ("comments", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalItem.h", Line = 168)]
		NSObject [] Comments { get; }

		[Export ("initWithPortal:itemId:")]
		IntPtr Constructor (AGSPortal portal, string itemId);

		[Export ("fetchData"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalItem.h", Line = 180)]
		NSOperation FetchData { get; }

		[Export ("fetchThumbnail"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalItem.h", Line = 185)]
		NSOperation FetchThumbnail { get; }

		[Export ("fetchComments"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalItem.h", Line = 190)]
		NSOperation FetchComments { get; }
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSPortalItemDelegate {

		[Export ("portalItemDidLoad:")]
		void  (AGSPortalItem portalItem);

		[Export ("portalItem:didFailToLoadWithError:")]
		void DidFailToLoadWithError (AGSPortalItem portalItem, NSError error);

		[Export ("portalItem:operation:didFetchData:")]
		void Operation (AGSPortalItem portalItem, NSOperation op, NSData data);

		[Export ("portalItem:operation:didFailToFetchDataWithError:")]
		void Operation (AGSPortalItem portalItem, NSOperation op, NSError error);

		[Export ("portalItem:operation:didFetchThumbnail:")]
		void Operation (AGSPortalItem portalItem, NSOperation op, UIImage thumbnail);

		[Export ("portalItem:operation:didFailToFetchThumbnailWithError:")]
		void Operation (AGSPortalItem portalItem, NSOperation op, NSError error);

		[Export ("portalItem:operation:didFetchComments:")]
		void Operation (AGSPortalItem portalItem, NSOperation op, [Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalItem.h", Line = 258)] NSObject [] comments);

		[Export ("portalItem:operation:didFailToFetchCommentsWithError:")]
		void Operation (AGSPortalItem portalItem, NSOperation op, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSPortalItemComment : AGSCoding {

		[Export ("owner", ArgumentSemantic.Copy)]
		string Owner { get; }

		[Export ("commentId", ArgumentSemantic.Copy)]
		string CommentId { get; }

		[Export ("comment", ArgumentSemantic.Copy)]
		string Comment { get; }

		[Export ("created", ArgumentSemantic.Retain)]
		NSDate Created { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSPortalQueryParams : AGSCoding {

		[Export ("query", ArgumentSemantic.Copy)]
		string Query { get; set; }

		[Export ("sortField", ArgumentSemantic.Copy)]
		string SortField { get; set; }

		[Export ("sortOrder")]
		AGSPortalQuerySortOrder SortOrder { get; set; }

		[Export ("startIndex")]
		int StartIndex { get; set; }

		[Export ("limit")]
		int Limit { get; set; }

		[Export ("initWithQuery:")]
		IntPtr Constructor (string query);

		[Static, Export ("queryParamsWithQuery:")]
		AGSPortalQueryParams QueryParamsWithQuery (string query);

		[Export ("initWithQuery:limit:")]
		IntPtr Constructor (string query, int limit);

		[Static, Export ("queryParamsWithQuery:limit:")]
		AGSPortalQueryParams QueryParamsWithQuery (string query, int limit);

		[Static, Export ("queryParamsForGroupsWithOwner:title:")]
		AGSPortalQueryParams QueryParamsForGroupsWithOwner (string username, string title);

		[Static, Export ("queryParamsForItemsOfType:withSearchString:")]
		AGSPortalQueryParams QueryParamsForItemsOfType (AGSPortalItemType type, string searchString);

		[Static, Export ("queryParamsForItemsOfType:inGroup:withSearchString:")]
		AGSPortalQueryParams QueryParamsForItemsOfType (AGSPortalItemType type, string groupId, string searchString);

		[Static, Export ("queryParamsForItemsOfType:inGroup:")]
		AGSPortalQueryParams QueryParamsForItemsOfType (AGSPortalItemType type, string groupId);

		[Static, Export ("queryParamsForItemsInGroup:")]
		AGSPortalQueryParams QueryParamsForItemsInGroup (string groupId);

		[Static, Export ("queryParamsForItemWithId:")]
		AGSPortalQueryParams QueryParamsForItemWithId (string itemId);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSPortalQueryResultSet {

		[Export ("queryParams", ArgumentSemantic.Retain)]
		AGSPortalQueryParams QueryParams { get; }

		[Export ("nextQueryParams", ArgumentSemantic.Retain)]
		AGSPortalQueryParams NextQueryParams { get; }

		[Export ("totalResults")]
		int TotalResults { get; }

		[Export ("results", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalQueryResultSet.h", Line = 52)]
		NSObject [] Results { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSPortalUser : AGSCoding {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSPortalUserDelegate Delegate { get; set; }

		[Export ("portal", ArgumentSemantic.Assign)]
		AGSPortal Portal { get; }

		[Export ("username", ArgumentSemantic.Copy)]
		string Username { get; }

		[Export ("fullName", ArgumentSemantic.Copy)]
		string FullName { get; }

		[Export ("userDescription", ArgumentSemantic.Copy)]
		string UserDescription { get; }

		[Export ("email", ArgumentSemantic.Copy)]
		string Email { get; }

		[Export ("organizationId", ArgumentSemantic.Copy)]
		string OrganizationId { get; }

		[Export ("thumbnailFileName", ArgumentSemantic.Copy)]
		string ThumbnailFileName { get; }

		[Export ("tags", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalUser.h", Line = 85)]
		NSObject [] Tags { get; }

		[Export ("groups", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalUser.h", Line = 90)]
		NSObject [] Groups { get; }

		[Export ("access")]
		AGSPortalAccess Access { get; }

		[Export ("created", ArgumentSemantic.Retain)]
		NSDate Created { get; }

		[Export ("modified", ArgumentSemantic.Retain)]
		NSDate Modified { get; }

		[Export ("thumbnail", ArgumentSemantic.Retain)]
		UIImage Thumbnail { get; }

		[Export ("role")]
		AGSPortalUserRole Role { get; }

		[Export ("fetchContent"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalUser.h", Line = 123)]
		NSOperation FetchContent { get; }

		[Export ("fetchContentInFolder:")]
		NSOperation FetchContentInFolder (string folderId);

		[Export ("fetchThumbnail"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalUser.h", Line = 134)]
		NSOperation FetchThumbnail { get; }

		[Export ("initWithPortal:username:")]
		IntPtr Constructor (AGSPortal portal, string username);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSPortalUserDelegate {

		[Export ("portalUserDidLoad:")]
		void  (AGSPortalUser portalUser);

		[Export ("portalUser:didFailToLoadWithError:")]
		void DidFailToLoadWithError (AGSPortalUser portalUser, NSError error);

		[Export ("portalUser:operation:didFetchContent:folders:inFolder:")]
		void Operation (AGSPortalUser portalUser, NSOperation op, [Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalUser.h", Line = 178)] NSObject [] items, [Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPortalUser.h", Line = 178)] NSObject [] folders, string folderId);

		[Export ("portalUser:operation:didFailToFetchContentInFolder:withError:")]
		void Operation (AGSPortalUser portalUser, NSOperation op, string folderId, NSError error);

		[Export ("portalUser:operation:didFetchThumbnail:")]
		void Operation (AGSPortalUser portalUser, NSOperation op, UIImage thumbnail);

		[Export ("portalUser:operation:didFailToFetchThumbnailWithError:")]
		void Operation (AGSPortalUser portalUser, NSOperation op, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSWebMap : AGSCoding, AGSSecuredResource {

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSUrl url, AGSCredential cred);

		[Static, Export ("webMapWithURL:credential:")]
		AGSWebMap WebMapWithURL (NSUrl url, AGSCredential cred);

		[Static, Export ("webMapWithItemId:credential:")]
		AGSWebMap WebMapWithItemId (string itemId, AGSCredential cred);

		[Export ("initWithItemId:credential:")]
		IntPtr Constructor (string itemId, AGSCredential cred);

		[Static, Export ("webMapWithItemId:sharingEndPoint:credential:")]
		AGSWebMap WebMapWithItemId (string itemId, NSUrl sharingEndPoint, AGSCredential cred);

		[Export ("initWithItemId:sharingEndPoint:credential:")]
		IntPtr Constructor (string itemId, NSUrl sharingEndPoint, AGSCredential cred);

		[Export ("initWithPortalItem:")]
		IntPtr Constructor (AGSPortalItem item);

		[Static, Export ("webMapWithPortalItem:")]
		AGSWebMap WebMapWithPortalItem (AGSPortalItem item);

		[Static, Export ("webMapWithItemId:portal:")]
		AGSWebMap WebMapWithItemId (string itemId, AGSPortal portal);

		[Export ("initWithItemId:portal:")]
		IntPtr Constructor (string itemId, AGSPortal portal);

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		[Export ("credential", ArgumentSemantic.Copy)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSWebMapDelegate Delegate { get; set; }

		[Export ("zoomToDefaultExtentOnOpen")]
		bool ZoomToDefaultExtentOnOpen { get; set; }

		[Export ("bookmarks", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWebMap.h", Line = 211)]
		NSObject [] Bookmarks { get; }

		[Export ("loaded")]
		bool Loaded { [Bind ("isLoaded")] get; }

		[Export ("version")]
		float Version { get; }

		[Export ("operationalLayers", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWebMap.h", Line = 226)]
		NSObject [] OperationalLayers { get; }

		[Export ("baseMap", ArgumentSemantic.Retain)]
		AGSWebMapBaseMap BaseMap { get; }

		[Export ("portalItem", ArgumentSemantic.Retain)]
		AGSPortalItem PortalItem { get; }

		[Export ("queries", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWebMap.h", Line = 241)]
		NSObject [] Queries { get; }

		[Export ("openIntoMapView:")]
		void OpenIntoMapView (AGSMapView mapView);

		[Export ("openIntoMapView:withAlternateBaseMap:")]
		void OpenIntoMapView (AGSMapView mapView, AGSWebMapBaseMap baseMap);

		[Export ("openIntoMapView:withAlternateBaseMap:resetMapView:")]
		void OpenIntoMapView (AGSMapView mapView, AGSWebMapBaseMap baseMap, bool reset);

		[Export ("continueOpenWithCredential:")]
		void ContinueOpenWithCredential (AGSCredential credential);

		[Export ("continueOpenAndSkipCurrentLayer")]
		void ContinueOpenAndSkipCurrentLayer ();

		[Export ("cancelOpen")]
		void CancelOpen ();

		[Export ("popupInfoForMapServiceLayerWithURL:sublayerId:")]
		AGSPopupInfo PopupInfoForMapServiceLayerWithURL (NSUrl url, int sublayerId);

		[Export ("popupInfoForDynamicMapServiceLayer:sublayerId:")]
		AGSPopupInfo PopupInfoForDynamicMapServiceLayer (AGSDynamicMapServiceLayer dmsl, int sublayerId);

		[Export ("popupInfoForTiledMapServiceLayer:sublayerId:")]
		AGSPopupInfo PopupInfoForTiledMapServiceLayer (AGSTiledMapServiceLayer tmsl, int sublayerId);

		[Export ("popupInfoForFeatureLayer:")]
		AGSPopupInfo PopupInfoForFeatureLayer (AGSFeatureLayer featureLayer);

		[Export ("webMapLayerInfoForLayer:subLayerInfo:")]
		AGSWebMapLayerInfo WebMapLayerInfoForLayer (AGSLayer layer, out AGSWebMapSubLayerInfo subLayerInfo);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSWebMapDelegate {

		[Export ("webMapDidLoad:")]
		void  (AGSWebMap webMap);

		[Export ("webMap:didFailToLoadWithError:")]
		void DidFailToLoadWithError (AGSWebMap webMap, NSError error);

		[Export ("didOpenWebMap:intoMapView:")]
		void IntoMapView (AGSWebMap webMap, AGSMapView mapView);

		[Export ("didFailToLoadLayer:url:baseLayer:withError:")]
		void Url (string layerTitle, NSUrl url, bool baseLayer, NSError error);

		[Export ("webMap:didFailToLoadLayer:baseLayer:federated:withError:")]
		void DidFailToLoadLayer (AGSWebMap webMap, AGSWebMapLayerInfo layerInfo, bool baseLayer, bool federated, NSError error);

		[Export ("didLoadLayer:")]
		void  (AGSLayer layer);

		[Export ("webMap:didLoadLayer:")]
		void DidLoadLayer (AGSWebMap webMap, AGSLayer layer);

		[Export ("bingAppId"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWebMap.h", Line = 401)]
		string BingAppId { get; }

		[Export ("bingAppIdForWebMap:")]
		string  (AGSWebMap webMap);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSWebMapBaseMap : AGSCoding {

		[Export ("title", ArgumentSemantic.Copy)]
		string Title { get; }

		[Export ("baseMapLayers", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWebMapBaseMap.h", Line = 40)]
		NSObject [] BaseMapLayers { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSWebMapBookmark : AGSCoding {

		[Export ("extent", ArgumentSemantic.Retain)]
		AGSEnvelope Extent { get; }

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSWebMapFeatureCollection : AGSCoding {

		[Export ("layers", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWebMapFeatureCollection.h", Line = 33)]
		NSObject [] Layers { get; }

		[Export ("showLegend")]
		bool ShowLegend { get; }

		[Export ("initWithJSON:")]
		IntPtr Constructor (NSDictionary json);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSWebMapLayerInfo : AGSCoding {

		[Export ("layerId", ArgumentSemantic.Copy)]
		string LayerId { get; }

		[Export ("itemId", ArgumentSemantic.Copy)]
		string ItemId { get; }

		[Export ("title", ArgumentSemantic.Copy)]
		string Title { get; }

		[Export ("URL", ArgumentSemantic.Retain)]
		NSUrl URL { get; }

		[Export ("opacity")]
		float Opacity { get; }

		[Export ("layerType", ArgumentSemantic.Copy)]
		string LayerType { get; }

		[Export ("visibility")]
		bool Visibility { get; }

		[Export ("isReference")]
		bool IsReference { get; }

		[Export ("featureCollection", ArgumentSemantic.Retain)]
		AGSWebMapFeatureCollection FeatureCollection { get; }

		[Export ("mode")]
		int Mode { get; }

		[Export ("popupInfo", ArgumentSemantic.Retain)]
		AGSPopupInfo PopupInfo { get; }

		[Export ("layers", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWebMapLayerInfo.h", Line = 92)]
		NSObject [] Layers { get; }

		[Export ("visibleLayers", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWebMapLayerInfo.h", Line = 97)]
		NSObject [] VisibleLayers { get; }

		[Export ("layerDefinition", ArgumentSemantic.Copy)]
		NSDictionary LayerDefinition { get; }

		[Export ("showLegend")]
		bool ShowLegend { get; }

		[Export ("bandIds", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWebMapLayerInfo.h", Line = 112)]
		NSObject [] BandIds { get; }

		[Export ("minScale")]
		double MinScale { get; }

		[Export ("maxScale")]
		double MaxScale { get; }

		[Export ("isEditingDisabled")]
		bool IsEditingDisabled { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSWebMapQuery : AGSCoding {

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("displayField", ArgumentSemantic.Copy)]
		string DisplayField { get; }

		[Export ("URL", ArgumentSemantic.Retain)]
		NSUrl URL { get; }

		[Export ("whereClause", ArgumentSemantic.Copy)]
		string WhereClause { get; }

		[Export ("parameters", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWebMapQuery.h", Line = 53)]
		NSObject [] Parameters { get; }

		[Export ("visibleFields", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWebMapQuery.h", Line = 60)]
		NSObject [] VisibleFields { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSWebMapQueryParameter : AGSCoding {

		[Export ("defaultValue", ArgumentSemantic.Copy)]
		string DefaultValue { get; }

		[Export ("field", ArgumentSemantic.Copy)]
		string Field { get; }

		[Export ("paramOperator", ArgumentSemantic.Copy)]
		string ParamOperator { get; }

		[Export ("prompt", ArgumentSemantic.Copy)]
		string Prompt { get; }

		[Export ("helpTip", ArgumentSemantic.Copy)]
		string HelpTip { get; }

		[Export ("initWithPrompt:field:defaultValue:paramOperator:helpTip:")]
		IntPtr Constructor (string p, string f, string dv, string op, string h);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSWebMapSubLayerInfo : AGSCoding {

		[Export ("layerId")]
		uint LayerId { get; }

		[Export ("popupInfo", ArgumentSemantic.Retain)]
		AGSPopupInfo PopupInfo { get; }

		[Export ("featureSet", ArgumentSemantic.Copy)]
		NSDictionary FeatureSet { get; }

		[Export ("layerDefinition", ArgumentSemantic.Copy)]
		NSDictionary LayerDefinition { get; }

		[Export ("layerURL", ArgumentSemantic.Retain)]
		NSUrl LayerURL { get; }

		[Export ("showLegend")]
		bool ShowLegend { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSPopup {

		[Export ("graphic", ArgumentSemantic.Retain)]
		AGSGraphic Graphic { get; }

		[Export ("popupInfo", ArgumentSemantic.Retain)]
		AGSPopupInfo PopupInfo { get; }

		[Export ("featureLayer", ArgumentSemantic.Retain)]
		AGSFeatureLayer FeatureLayer { get; }

		[Export ("allowEdit")]
		bool AllowEdit { get; set; }

		[Export ("allowEditGeometry")]
		bool AllowEditGeometry { get; set; }

		[Export ("allowDelete")]
		bool AllowDelete { get; set; }

		[Export ("initWithGraphic:popupInfo:")]
		IntPtr Constructor (AGSGraphic graphic, AGSPopupInfo popupInfo);

		[Export ("initWithGraphic:popupInfo:featureLayer:")]
		IntPtr Constructor (AGSGraphic graphic, AGSPopupInfo popupInfo, AGSFeatureLayer featureLayer);

		[Static, Export ("popupWithGraphic:popupInfo:")]
		AGSPopup PopupWithGraphic (AGSGraphic graphic, AGSPopupInfo popupInfo);

		[Static, Export ("popupWithGraphic:popupInfo:featureLayer:")]
		AGSPopup PopupWithGraphic (AGSGraphic graphic, AGSPopupInfo popupInfo, AGSFeatureLayer featureLayer);

		[Export ("attributeForPopupFieldInfo:")]
		string AttributeForPopupFieldInfo (AGSPopupFieldInfo popupFieldInfo);

		[Export ("stringForTemplatedString:")]
		string StringForTemplatedString (string aString);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSPopupFieldInfo : AGSCoding {

		[Export ("fieldName", ArgumentSemantic.Copy)]
		string FieldName { get; set; }

		[Export ("label", ArgumentSemantic.Copy)]
		string Label { get; set; }

		[Export ("tooltip", ArgumentSemantic.Copy)]
		string Tooltip { get; set; }

		[Export ("numDecimalPlaces")]
		int NumDecimalPlaces { get; set; }

		[Export ("showDigitSeparator")]
		bool ShowDigitSeparator { get; set; }

		[Export ("dateFormat")]
		AGSPopupFieldInfoDateFormat DateFormat { get; set; }

		[Export ("editable")]
		bool Editable { [Bind ("isEditable")] get; set; }

		[Export ("visible")]
		bool Visible { [Bind ("isVisible")] get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSPopupInfo : AGSCoding {

		[Export ("title", ArgumentSemantic.Copy)]
		string Title { get; set; }

		[Export ("customDescription", ArgumentSemantic.Copy)]
		string CustomDescription { get; set; }

		[Export ("fieldInfos", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPopupInfo.h", Line = 56)]
		NSObject [] FieldInfos { get; set; }

		[Export ("mediaInfos", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPopupInfo.h", Line = 61)]
		NSObject [] MediaInfos { get; set; }

		[Export ("showAttachments")]
		bool ShowAttachments { get; set; }

		[Static, Export ("popupInfoForGraphic:")]
		AGSPopupInfo PopupInfoForGraphic (AGSGraphic graphic);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSPopupMediaInfo : AGSCoding {

		[Export ("caption", ArgumentSemantic.Copy)]
		string Caption { get; set; }

		[Export ("title", ArgumentSemantic.Copy)]
		string Title { get; set; }

		[Export ("type")]
		AGSPopupMediaInfoType Type { get; set; }

		[Export ("value", ArgumentSemantic.Copy)]
		NSDictionary Value { get; set; }

		[Export ("initWithTitle:caption:type:value:")]
		IntPtr Constructor (string title, string caption, AGSPopupMediaInfoType type, NSDictionary value);

		[Static, Export ("popupMediaInfoWithTitle:caption:type:value:")]
		AGSPopupMediaInfo PopupMediaInfoWithTitle (string title, string caption, AGSPopupMediaInfoType type, NSDictionary value);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSPopupsContainer {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSPopupsContainerDelegate Delegate { get; set; }

		[Export ("popups", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPopupsContainer.h", Line = 47)]
		NSObject [] Popups { get; set; }

		[Export ("inEditingMode")]
		bool InEditingMode { get; }

		[Export ("style")]
		AGSPopupsContainerStyle Style { get; set; }

		[Export ("styleColor", ArgumentSemantic.Retain)]
		UIColor StyleColor { get; set; }

		[Export ("currentEditingGeometry", ArgumentSemantic.Retain)]
		AGSGeometry CurrentEditingGeometry { get; }

		[Export ("currentPopup", ArgumentSemantic.Retain)]
		AGSPopup CurrentPopup { get; }

		[Export ("editingStyle")]
		AGSPopupsContainerEditingStyle EditingStyle { get; set; }

		[Export ("doneButton", ArgumentSemantic.Retain)]
		UIBarButtonItem DoneButton { get; set; }

		[Export ("actionButton", ArgumentSemantic.Retain)]
		UIBarButtonItem ActionButton { get; set; }

		[Export ("defaultActionButton", ArgumentSemantic.Retain)]
		UIBarButtonItem DefaultActionButton { get; }

		[Export ("defaultDoneButton", ArgumentSemantic.Retain)]
		UIBarButtonItem DefaultDoneButton { get; }

		[Export ("modalPresenter", ArgumentSemantic.Retain)]
		UIViewController ModalPresenter { get; set; }

		[Export ("showAdditionalPopups:")]
		void ShowAdditionalPopups ([Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPopupsContainer.h", Line = 116)] NSObject [] popupInfos);

		[Export ("startEditingCurrentPopup")]
		void StartEditingCurrentPopup ();

		[Export ("clearAllPopups")]
		void ClearAllPopups ();
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSPopupsContainerDelegate {

		[Export ("popupsContainer:wantsNewMutableGeometryForPopup:")]
		AGSGeometry WantsNewMutableGeometryForPopup (AGSPopupsContainer popupsContainer, AGSPopup popup);

		[Export ("popupsContainer:readyToEditGraphicGeometry:forPopup:")]
		void ReadyToEditGraphicGeometry (AGSPopupsContainer popupsContainer, AGSGeometry geometry, AGSPopup popup);

		[Export ("popupsContainer:didStartEditingGraphicForPopup:")]
		void DidStartEditingGraphicForPopup (AGSPopupsContainer popupsContainer, AGSPopup popup);

		[Export ("popupsContainer:didFinishEditingGraphicForPopup:")]
		void DidFinishEditingGraphicForPopup (AGSPopupsContainer popupsContainer, AGSPopup popup);

		[Export ("popupsContainer:didCancelEditingGraphicForPopup:")]
		void DidCancelEditingGraphicForPopup (AGSPopupsContainer popupsContainer, AGSPopup popup);

		[Export ("popupsContainer:wantsToDeleteGraphicForPopup:")]
		void WantsToDeleteGraphicForPopup (AGSPopupsContainer popupsContainer, AGSPopup popup);

		[Export ("popupsContainerDidFinishViewingPopups:")]
		void  (AGSPopupsContainer popupsContainer);

		[Export ("popupsContainer:wantsToShowViewController:ofType:fromViewController:atRect:")]
		void WantsToShowViewController (AGSPopupsContainer popupsContainer, UIViewController svc, AGSPopupViewType viewType, UIViewController fvc, RectangleF rect);

		[Export ("popupsContainer:wantsToHideViewController:ofType:")]
		void WantsToHideViewController (AGSPopupsContainer popupsContainer, UIViewController vc, AGSPopupViewType viewType);

		[Export ("popupsContainer:shouldAutorotateToInterfaceOrientation:forViewController:ofType:")]
		bool ShouldAutorotateToInterfaceOrientation (AGSPopupsContainer popupsContainer, UIInterfaceOrientation interfaceOrientation, UIViewController vc, AGSPopupViewType viewType);

		[Export ("popupsContainer:didChangeToCurrentPopup:")]
		void DidChangeToCurrentPopup (AGSPopupsContainer popupsContainer, AGSPopup popup);

		[Export ("popupsContainer:wantsToPreviewDocumentAtURL:fromViewController:atRect:")]
		void WantsToPreviewDocumentAtURL (AGSPopupsContainer popupsContainer, NSUrl documentURL, UIViewController fvc, RectangleF rect);

		[Export ("popupsContainer:didChangeFeatureTypeForPopup:")]
		void DidChangeFeatureTypeForPopup (AGSPopupsContainer popupsContainer, AGSPopup popup);
	}

	[BaseType (typeof (UIViewController))]
	public partial interface AGSPopupsContainerViewController : UIScrollViewDelegate, AGSPopupsContainer, UIActionSheetDelegate {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSPopupsContainerDelegate Delegate { get; set; }

		[Export ("popups", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPopupsContainerViewController.h", Line = 59)]
		NSObject [] Popups { get; set; }

		[Export ("inEditingMode")]
		bool InEditingMode { get; }

		[Export ("style")]
		AGSPopupsContainerStyle Style { get; set; }

		[Export ("styleColor", ArgumentSemantic.Retain)]
		UIColor StyleColor { get; set; }

		[Export ("currentEditingGeometry", ArgumentSemantic.Retain)]
		AGSGeometry CurrentEditingGeometry { get; }

		[Export ("currentPopup", ArgumentSemantic.Retain)]
		AGSPopup CurrentPopup { get; }

		[Export ("editingStyle")]
		AGSPopupsContainerEditingStyle EditingStyle { get; set; }

		[Export ("pagingStyle")]
		AGSPopupsContainerPagingStyle PagingStyle { get; set; }

		[Export ("actionSheetContainerView", ArgumentSemantic.Assign)]
		UIView ActionSheetContainerView { get; set; }

		[Export ("doneButton", ArgumentSemantic.Retain)]
		UIBarButtonItem DoneButton { get; set; }

		[Export ("actionButton", ArgumentSemantic.Retain)]
		UIBarButtonItem ActionButton { get; set; }

		[Export ("defaultActionButton", ArgumentSemantic.Retain)]
		UIBarButtonItem DefaultActionButton { get; }

		[Export ("defaultDoneButton", ArgumentSemantic.Retain)]
		UIBarButtonItem DefaultDoneButton { get; }

		[Export ("modalPresenter", ArgumentSemantic.Retain)]
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
		void ShowAdditionalPopups ([Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSPopupsContainerViewController.h", Line = 177)] NSObject [] popupInfos);

		[Export ("startEditingCurrentPopup")]
		void StartEditingCurrentPopup ();

		[Export ("clearAllPopups")]
		void ClearAllPopups ();
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSLocationDisplayDataSourceDelegate {

		[Export ("locationDisplayDataSource:didUpdateWithLocation:")]
		void DidUpdateWithLocation (AGSLocationDisplayDataSource dataSource, AGSLocation location);

		[Export ("locationDisplayDataSource:didUpdateWithHeading:")]
		void DidUpdateWithHeading (AGSLocationDisplayDataSource dataSource, double heading);

		[Export ("locationDisplayDataSource:didFailWithError:")]
		void DidFailWithError (AGSLocationDisplayDataSource dataSource, NSError error);

		[Export ("locationDisplayDataSourceStopped:")]
		void  (AGSLocationDisplayDataSource dataSource);

		[Export ("locationDisplayDataSourceStarted:")]
		void  (AGSLocationDisplayDataSource dataSource);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSLocationDisplayDataSource {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSLocationDisplayDataSourceDelegate Delegate { get; set; }

		[Export ("start")]
		void Start ();

		[Export ("stop")]
		void Stop ();

		[Export ("started")]
		bool Started { [Bind ("isStarted")] get; }

		[Export ("error", ArgumentSemantic.Retain)]
		NSError Error { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSLocationDisplay : AGSLocationDisplayDataSourceDelegate {

		[Export ("dataSource", ArgumentSemantic.Retain)]
		AGSLocationDisplayDataSource DataSource { get; set; }

		[Export ("location", ArgumentSemantic.Retain)]
		AGSLocation Location { get; }

		[Export ("dataSourceError", ArgumentSemantic.Retain)]
		NSError DataSourceError { get; }

		[Export ("autoPanMode")]
		AGSLocationDisplayAutoPanMode AutoPanMode { get; set; }

		[Export ("wanderExtentFactor")]
		float WanderExtentFactor { get; set; }

		[Export ("infoTemplateDelegate", ArgumentSemantic.Assign)]
		AGSLocationDisplayInfoTemplateDelegate InfoTemplateDelegate { get; set; }

		[Export ("zoomScale")]
		double ZoomScale { get; set; }

		[Export ("dataSourceStarted")]
		bool DataSourceStarted { [Bind ("isDataSourceStarted")] get; }

		[Export ("interfaceOrientation")]
		UIInterfaceOrientation InterfaceOrientation { get; set; }

		[Export ("mapLocation"), Verify ("ObjC method massaged into getter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSLocationDisplay.h", Line = 123)]
		AGSPoint MapLocation { get; }

		[Export ("startDataSource")]
		void StartDataSource ();

		[Export ("stopDataSource")]
		void StopDataSource ();

		[Export ("navigationPointHeightFactor")]
		float NavigationPointHeightFactor { get; set; }

		[Export ("alpha")]
		float Alpha { get; set; }
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSLocationDisplayInfoTemplateDelegate {

		[Export ("titleForLocationDisplay:screenPoint:")]
		string ScreenPoint (AGSLocationDisplay ld, PointF screen);

		[Export ("detailForLocationDisplay:screenPoint:")]
		string ScreenPoint (AGSLocationDisplay ld, PointF screen);

		[Export ("imageForLocationDisplay:screenPoint:")]
		UIImage ScreenPoint (AGSLocationDisplay ld, PointF screen);

		[Export ("customViewForLocationDisplay:screenPoint:")]
		UIView ScreenPoint (AGSLocationDisplay ld, PointF screen);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSLocation {

		[Export ("point", ArgumentSemantic.Retain)]
		AGSPoint Point { get; set; }

		[Export ("accuracy")]
		double Accuracy { get; set; }

		[Export ("course")]
		double Course { get; set; }

		[Export ("velocity")]
		double Velocity { get; set; }

		[Static, Export ("locationWithCLLocation:")]
		AGSLocation LocationWithCLLocation (CLLocation cllocation);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSSimulatedLocationDisplayDataSource : AGSLocationDisplayDataSource {

		[Export ("locations", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSSimulatedLocationDisplayDataSource.h", Line = 40)]
		NSObject [] Locations { get; set; }

		[Export ("locationsFromPolyline"), Verify ("ObjC method massaged into setter property", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSSimulatedLocationDisplayDataSource.h", Line = 47)]
		AGSPolyline LocationsFromPolyline { set; }
	}

	[BaseType (typeof (AGSSimulatedLocationDisplayDataSource))]
	public partial interface AGSGPXLocationDisplayDataSource {

		[Export ("initWithPath:")]
		IntPtr Constructor (string path);

		[Export ("initWithGPXData:")]
		IntPtr Constructor (NSData gpxData);

		[Export ("initWithURL:")]
		IntPtr Constructor (NSUrl gpxUrl);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSCLLocationManagerLocationDisplayDataSource : AGSLocationDisplayDataSource {

		[Export ("locationManager", ArgumentSemantic.Retain)]
		CLLocationManager LocationManager { get; }
	}

	[BaseType (typeof (AGSTiledServiceLayer))]
	public partial interface AGSWMTSLayer : AGSSecuredResource {

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		[Export ("version", ArgumentSemantic.Copy)]
		string Version { get; }

		[Export ("copyright", ArgumentSemantic.Copy)]
		string Copyright { get; }

		[Export ("spatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference SpatialReference { get; }

		[Export ("credential", ArgumentSemantic.Copy)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("imageFormat")]
		AGSImageFormat ImageFormat { get; set; }

		[Export ("layerDescription", ArgumentSemantic.Copy)]
		string LayerDescription { get; }

		[Export ("title", ArgumentSemantic.Copy)]
		string Title { get; }

		[Export ("style", ArgumentSemantic.Assign)]
		AGSWMTSStyle Style { get; set; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSWMTSLayerInfo {

		[Export ("title", ArgumentSemantic.Copy)]
		string Title { get; }

		[Export ("imageFormats", ArgumentSemantic.Copy)]
		NSSet ImageFormats { get; }

		[Export ("tileMatrixSet", ArgumentSemantic.Copy)]
		string TileMatrixSet { get; set; }

		[Export ("tileMatrixSetIds", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWMTSLayerInfo.h", Line = 61)]
		NSObject [] TileMatrixSetIds { get; }

		[Export ("style", ArgumentSemantic.Retain)]
		AGSWMTSStyle Style { get; set; }

		[Export ("styles", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWMTSLayerInfo.h", Line = 71)]
		NSObject [] Styles { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSWMTSInfo : AGSSecuredResource {

		[Export ("delegate", ArgumentSemantic.Assign)]
		AGSWMTSInfoDelegate Delegate { get; set; }

		[Export ("layerInfos", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSWMTSInfo.h", Line = 53)]
		NSObject [] LayerInfos { get; }

		[Export ("credential", ArgumentSemantic.Copy)]
		AGSCredential Credential { get; set; }

		[Export ("credentialCache", ArgumentSemantic.Retain)]
		AGSCredentialCache CredentialCache { get; set; }

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSUrl url);

		[Export ("initWithURL:credential:")]
		IntPtr Constructor (NSUrl url, AGSCredential credential);

		[Static, Export ("wmtsInfoWithURL:")]
		NSObject WmtsInfoWithURL (NSUrl url);

		[Static, Export ("wmtsInfoWithURL:credential:")]
		NSObject WmtsInfoWithURL (NSUrl url, AGSCredential credential);

		[Export ("wmtsLayerWithLayerInfo:andSpatialReference:")]
		AGSWMTSLayer WmtsLayerWithLayerInfo (AGSWMTSLayerInfo layerInfo, AGSSpatialReference sr);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSWMTSInfoDelegate {

		[Export ("wmtsInfoDidLoad:")]
		void  (AGSWMTSInfo wmtsInfo);

		[Export ("wmtsInfo:DidFailToLoad:")]
		void DidFailToLoad (AGSWMTSInfo wmtsInfo, NSError error);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSWMTSStyle {

		[Export ("identifier", ArgumentSemantic.Copy)]
		string Identifier { get; }

		[Export ("title", ArgumentSemantic.Copy)]
		string Title { get; }

		[Export ("abstract", ArgumentSemantic.Copy)]
		string Abstract { get; }

		[Export ("isDefault")]
		bool IsDefault { get; }
	}

	[BaseType (typeof (AGSLayer))]
	public partial interface AGSGroupLayer {

		[Export ("layers", ArgumentSemantic.Copy), Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSGroupLayer.h", Line = 39)]
		NSObject [] Layers { get; }

		[Export ("layerAtIndex:")]
		AGSLayer LayerAtIndex (uint index);
	}

	[BaseType (typeof (AGSRenderer))]
	public partial interface AGSMPDictionaryRenderer {

		[Export ("dictionaryRendererDescription", ArgumentSemantic.Copy)]
		string DictionaryRendererDescription { get; set; }

		[Export ("dictionaryType", ArgumentSemantic.Copy)]
		string DictionaryType { get; }

		[Export ("fieldName", ArgumentSemantic.Copy)]
		string FieldName { get; set; }

		[Export ("labelMaxScale")]
		double LabelMaxScale { get; set; }

		[Export ("labelMinScale")]
		double LabelMinScale { get; set; }

		[Export ("labelsVisible")]
		bool LabelsVisible { get; set; }

		[Export ("symbolScaleFactor")]
		double SymbolScaleFactor { get; }
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSMPMessageProcessor {

		[Export ("defaultMessageSpatialReference", ArgumentSemantic.Retain)]
		AGSSpatialReference DefaultMessageSpatialReference { get; set; }

		[Export ("dictionaryType")]
		AGSMPSymbolDictionaryType DictionaryType { get; }

		[Export ("messageTypes", ArgumentSemantic.Copy)]
		NSSet MessageTypes { get; }

		[Export ("symbolDictionary", ArgumentSemantic.Copy)]
		AGSMPSymbolDictionary SymbolDictionary { get; }

		[Export ("groupLayer", ArgumentSemantic.Retain)]
		AGSGroupLayer GroupLayer { get; }

		[Export ("initWithSymbolDictionaryType:groupLayer:")]
		IntPtr Constructor (AGSMPSymbolDictionaryType type, AGSGroupLayer layer);

		[Export ("initWithSymbolDictionaryType:groupLayer:symbolDictionaryPath:")]
		IntPtr Constructor (AGSMPSymbolDictionaryType type, AGSGroupLayer layer, string path);

		[Export ("messageFromGraphic:")]
		AGSMPMessage MessageFromGraphic (AGSGraphic graphic);

		[Export ("messageFromId:")]
		AGSMPMessage MessageFromId (string messageId);

		[Export ("processMessage:")]
		bool ProcessMessage (AGSMPMessage message);

		[Export ("graphicForId:")]
		AGSGraphic GraphicForId (string messageId);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSMPMessage : AGSCoding {

		[Export ("messageId", ArgumentSemantic.Copy)]
		string MessageId { get; set; }

		[Export ("properties", ArgumentSemantic.Copy)]
		NSDictionary Properties { get; set; }

		[Export ("initWithMessage:")]
		IntPtr Constructor (AGSMPMessage message);

		[Export ("propertyForKey:")]
		NSObject PropertyForKey (string key);

		[Export ("setProperty:forKey:")]
		void SetProperty (NSObject value, string key);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSMPMessageHelper {

		[Static, Export ("mil2525CRemoveMessageWithId:messageType:")]
		AGSMPMessage Mil2525CRemoveMessageWithId (string messageId, string messageType);

		[Static, Export ("mil2525CUpdateMessageWithId:messageType:controlPoints:properties:")]
		AGSMPMessage Mil2525CUpdateMessageWithId (string messageId, string messageType, [Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSMPMessageHelper.h", Line = 52)] NSObject [] controlPoints, NSDictionary properties);

		[Static, Export ("mil2525CUpdateMessageWithId:properties:")]
		AGSMPMessage Mil2525CUpdateMessageWithId (string messageId, NSDictionary properties);

		[Static, Export ("mil2525CUpdateMessageWithId:messageType:controlPoints:properties:spatialReference:")]
		AGSMPMessage Mil2525CUpdateMessageWithId (string messageId, string messageType, [Verify ("NSArray may be reliably typed, check the documentation", "/Volumes/Projects/MonoTouch.ArcGIS/Headers/AGSMPMessageHelper.h", Line = 77)] NSObject [] controlPoints, NSDictionary properties, AGSSpatialReference spatialReference);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSMPSymbolDictionary {

		[Export ("filterNames", ArgumentSemantic.Copy)]
		NSSet FilterNames { get; }

		[Export ("keywords", ArgumentSemantic.Copy)]
		NSSet Keywords { get; }

		[Export ("initWithSymbolDictionaryType:")]
		IntPtr Constructor (AGSMPSymbolDictionaryType type);

		[Export ("initWithSymbolDictionaryType:resourcePath:")]
		IntPtr Constructor (AGSMPSymbolDictionaryType type, string path);

		[Export ("valuesForFilter:")]
		NSSet ValuesForFilter (string filterName);

		[Export ("swatchForSymbol:")]
		UIImage SwatchForSymbol (string symbolName);

		[Export ("keywordsForSymbol:")]
		NSSet KeywordsForSymbol (string symbolName);

		[Export ("namesForQuery:")]
		NSSet NamesForQuery (AGSMPSymbolDictionaryQuery query);

		[Export ("valuesForSymbol:")]
		NSDictionary ValuesForSymbol (string symbolName);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSMPSymbolDictionaryQuery {

		[Export ("filters", ArgumentSemantic.Copy)]
		NSSet Filters { get; }

		[Export ("keywords", ArgumentSemantic.Copy)]
		NSSet Keywords { get; }

		[Export ("addFilter:")]
		void AddFilter (AGSMPSymbolDictionaryFilter filter);

		[Export ("addKeyword:")]
		void AddKeyword (string keyword);

		[Export ("removeAll")]
		void RemoveAll ();

		[Export ("removeFilter:")]
		void RemoveFilter (AGSMPSymbolDictionaryFilter filter);

		[Export ("removeKeyword:")]
		void RemoveKeyword (string keyword);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSMPSymbolDictionaryFilter {

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; set; }

		[Export ("value", ArgumentSemantic.Copy)]
		string Value { get; set; }

		[Export ("initWithValue:forName:")]
		IntPtr Constructor (string value, string name);

		[Static, Export ("filterWithValue:forName:")]
		NSObject FilterWithValue (string value, string name);
	}
}
