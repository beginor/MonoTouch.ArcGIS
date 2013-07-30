using System;
using System.Collections.Generic;
using System.Drawing;

using MonoTouch.ObjCRuntime;
using MonoTouch.Foundation;
using MonoTouch.UIKit;
using MonoTouch.CoreLocation;
using MonoTouch.Security;

using OSStatus = System.Int32;

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
		AGSSpatialReference SpatialReference (uint wkid);

		[Static, Export ("spatialReferenceWithWKT:")]
		AGSSpatialReference SpatialReference (string wkt);

		[Export ("initWithWKID:WKT:")]
		IntPtr Constructor (uint wkid, string wkt);

		[Static, Export ("spatialReferenceWithWKID:WKT:")]
		AGSSpatialReference SpatialReference (uint wkid, string wkt);

		[Export ("isAnyWebMercator")]
		bool IsAnyWebMercator ();

		[Export ("isWGS84")]
		bool IsWGS84 ();

		[Export ("isEqualToSpatialReference:")]
		bool IsEqualToSpatialReference (AGSSpatialReference sr);

		[Export ("isEqualToWKID:")]
		bool IsEqualToWKID (uint wkid);

		[Export ("encodeToJSON:forKey:")]
		void EncodeToJSON (NSMutableDictionary json, string key);

		[Export ("unit")]
		AGSSRUnit Unit ();

		[Static, Export ("webMercatorSpatialReference")]
		AGSSpatialReference WebMercatorSpatialReference ();

		[Static, Export ("wgs84SpatialReference")]
		AGSSpatialReference Wgs84SpatialReference ();

		[Export ("convertValue:toUnit:")]
		double ConvertValueToUnit (double val, AGSSRUnit unit);

		[Export ("convertValue:fromUnit:")]
		double ConvertValueFromUnit (double val, AGSSRUnit fromUnit);

		[Export ("isSupported")]
		bool IsSupported ();
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSGeometry : AGSCoding {

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

		[Export ("isEmpty")]
		bool IsEmpty ();

		[Export ("isValid")]
		bool IsValid ();
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
		AGSEnvelope EnvelopeWith (double xmin, double ymin, double xmax, double ymax, AGSSpatialReference spatialReference);

		[Export ("containsPoint:")]
		bool ContainsPoint (AGSPoint point);

		[Export ("containsEnvelope:")]
		bool ContainsEnvelope (AGSEnvelope env);

		[Export ("simpleRepresentation")]
		string SimpleRepresentation ();

		[Export ("intersectsWithEnvelope:")]
		bool IntersectsWithEnvelope (AGSEnvelope envelope);

		[Export ("intersectionWithEnvelope:")]
		AGSEnvelope IntersectionWithEnvelope (AGSEnvelope envelope);

		[Export ("isEmpty")]
		bool IsEmpty ();

		[Export ("isEqualToEnvelope:")]
		bool IsEqualToEnvelope (AGSEnvelope other);
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
		AGSPoint PointWith (double x, double y, AGSSpatialReference spatialReference);

		[Export ("isEqualToPoint:")]
		bool IsEqualToPoint (AGSPoint other);

		[Export ("distanceToPoint:")]
		double DistanceToPoint (AGSPoint other);
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

		[Export ("timeAware")]
		bool TimeAware { [Bind ("isTimeAware")]get; set;}

		[Export ("visible")]
		bool Visible { [Bind ("isVisible")]get; set; }

		[Export ("isInScale")]
		bool IsInScale ();

	}

	[BaseType (typeof (AGSLayer))]
	public partial interface AGSDynamicLayer {

		[Export ("autoRefreshInterval")]
		double AutoRefreshInterval { get; set; }
	}

	[/*Category, */BaseType (typeof (AGSDynamicLayer))]
	public partial interface ForSubclassEyesOnly_AGSDynamicLayer {

		[Export ("requestImageWithWidth:height:envelope:timeExtent:")]
		void RequestImageWithWidth ([Target]AGSDynamicLayer layer, int width, int height, AGSEnvelope env, AGSTimeExtent timeExtent);

		[Export ("setImageData:forEnvelope:")]
		void SetImageData ([Target]AGSDynamicLayer layer, NSData data, AGSEnvelope env);

		//[Export ("queue", ArgumentSemantic.Retain)]
		//NSOperationQueue Queue { get; }
		[Export("getQueue")]
		NSOperationQueue GetQueue([Target]AGSDynamicLayer layer);

		//[Export ("wrapAroundSupported")]
		//bool WrapAroundSupported { get; set; }
		[Export("getWrapAroundSupported")]
		bool GetWrapAroundSupported ([Target]AGSDynamicLayer layer);

		[Export("setWrapAroundSupported:")]
		void SetWrapAroundSupported([Target]AGSDynamicLayer layer, bool supported);
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
		AGSTimeExtent TimeExtentWith (NSDate start, NSDate end);

		[Static, Export ("dateByOffsettingDate:offset:units:")]
		NSDate DateByOffsettingDate (NSDate date, int offsetValue, AGSTimeIntervalUnits units);
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
		IntPtr Constructor (uint dpi, string format, AGSLOD [] lods, AGSPoint origin, AGSSpatialReference spatialReference, SizeF tileSize);
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

	[BaseType (typeof (AGSTiledLayer))]
	public partial interface AGSTiledServiceLayer {
	}

	[BaseType (typeof (AGSTiledServiceLayer))]
	public partial interface AGSTiledMapServiceLayer : AGSCoding/*, AGSSecuredResource*/ {

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		//[Export ("mapServiceInfo", ArgumentSemantic.Retain)]
		//AGSMapServiceInfo MapServiceInfo { get; }

		//[Export ("credential", ArgumentSemantic.Copy)]
		//AGSCredential Credential { get; set; }

		//[Export ("credentialCache", ArgumentSemantic.Retain)]
		//AGSCredentialCache CredentialCache { get; set; }

		[Export ("renderNativeResolution")]
		bool RenderNativeResolution { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSUrl url);

		//[Export ("initWithURL:credential:")]
		//IntPtr Constructor (NSUrl url, AGSCredential cred);

		//[Export ("initWithMapServiceInfo:")]
		//IntPtr Constructor (AGSMapServiceInfo info);

		[Static, Export ("tiledMapServiceLayerWithURL:")]
		AGSTiledMapServiceLayer TiledMapServiceLayerWithURL (NSUrl url);

		//[Static, Export ("tiledMapServiceLayerWithURL:credential:")]
		//AGSTiledMapServiceLayer TiledMapServiceLayerWithURL (NSUrl url, AGSCredential cred);

		//[Static, Export ("tiledMapServiceLayerWithMapServiceInfo:")]
		//AGSTiledMapServiceLayer TiledMapServiceLayerWithMapServiceInfo (AGSMapServiceInfo info);

		//[Export ("initWithJSON:URL:credential:")]
		//IntPtr Constructor (NSDictionary json, NSUrl url, AGSCredential cred);

		[Export ("resubmit")]
		void Resubmit ();

		//[Export ("resubmitWithURL:credential:")]
		//void ResubmitWithURL (NSUrl url, AGSCredential cred);

		//[Export ("checkCurrentScaleVisibilityForSubLayer:")]
		//bool CheckCurrentScaleVisibilityForSubLayer (AGSMapServiceLayerInfo msli);
	}

	[BaseType (typeof (AGSDynamicLayer))]
	public partial interface AGSDynamicMapServiceLayer : AGSCoding/*, AGSSecuredResource*/ {

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		//[Export ("mapServiceInfo", ArgumentSemantic.Retain)]
		//AGSMapServiceInfo MapServiceInfo { get; }

		//[Export ("credential", ArgumentSemantic.Copy)]
		//AGSCredential Credential { get; set; }
		//
		//[Export ("credentialCache", ArgumentSemantic.Retain)]
		//AGSCredentialCache CredentialCache { get; set; }

		[Export ("dpi")]
		uint Dpi { get; set; }

		[Export ("imageFormat")]
		AGSImageFormat ImageFormat { get; set; }

		[Export ("transparent")]
		bool Transparent { get; set; }

		//[Export ("layerDefinitions", ArgumentSemantic.Copy)]
		//AGSLayerDefinition [] LayerDefinitions { get; set; }

		//[Export ("visibleLayers", ArgumentSemantic.Copy)]
		//AGSMapServiceLayerInfo [] VisibleLayers { get; set; }

		//[Export ("layerTimeOptions", ArgumentSemantic.Copy)]
		//AGSLayerTimeOptions [] LayerTimeOptions { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSUrl url);

		//[Export ("initWithURL:credential:")]
		//IntPtr Constructor (NSUrl url, AGSCredential cred);

		//[Export ("initWithMapServiceInfo:")]
		//IntPtr Constructor (AGSMapServiceInfo info);

		[Static, Export ("dynamicMapServiceLayerWithURL:")]
		AGSDynamicMapServiceLayer DynamicMapServiceLayerWithURL (NSUrl url);

		//[Static, Export ("dynamicMapServiceLayerWithURL:credential:")]
		//AGSDynamicMapServiceLayer DynamicMapServiceLayerWithURL (NSUrl url, AGSCredential cred);

		//[Static, Export ("dynamicMapServiceLayerWithMapServiceInfo:")]
		//AGSDynamicMapServiceLayer DynamicMapServiceLayerWithMapServiceInfo (AGSMapServiceInfo info);

		//[Export ("initWithJSON:URL:credential:")]
		//IntPtr Constructor (NSDictionary json, NSUrl url, AGSCredential cred);

		//[Export ("resubmit")]
		//void Resubmit ();

		//[Export ("resubmitWithURL:credential:")]
		//void ResubmitWithURL (NSUrl url, AGSCredential cred);

		//[Export ("checkCurrentScaleVisibilityForSubLayer:")]
		//bool CheckCurrentScaleVisibilityForSubLayer (AGSMapServiceLayerInfo msli);
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

		[Export ("visibleArea")]
		AGSPolygon VisibleArea ();

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

		[Export ("wrapAroundStatus")]
		AGSMapViewWrapAroundStatus WrapAroundStatus ();

		[Export ("releaseHardwareResourcesWhenBackgrounded")]
		bool ReleaseHardwareResourcesWhenBackgrounded { get; set; }
	}

	[BaseType (typeof(AGSMapViewBase))]
	public partial interface AGSMapView {
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

	[BaseType (typeof (AGSGeometry))]
	public partial interface AGSPolygon {

		[Export ("numRings")]
		int NumRings { get; }

		[Export ("numPointsInRing:")]
		int NumPointsInRing (int ring);

		[Export ("numPoints")]
		int NumPoints ();

		[Export ("pointOnRing:atIndex:")]
		AGSPoint PointOnRing (int ring, int index);

		[Static, Export ("polygonWithJSON:")]
		AGSPolygon PolygonWithJSON (NSDictionary json);

		[Export ("containsPoint:")]
		bool ContainsPoint (AGSPoint point);

		[Export ("isEqualToPolygon:")]
		bool IsEqualToPolygon (AGSPolygon other);
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
		void DidClickAccessoryButtonForCallout (AGSCallout callout);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSSymbol : AGSCoding {

		[Export ("color", ArgumentSemantic.Copy)]
		UIColor Color { get; set; }

		[Export ("swatchForGeometryType:size:")]
		UIImage SwatchForGeometryType (AGSGeometryType geometryType, SizeF size);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSGraphic : AGSCoding {

		[Export ("allAttributes")]
		NSDictionary AllAttributes ();

		[Bind ("setAllAttributes:")]
		void SetAllAttributes (NSDictionary attrs);

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
		double AttributeAsDoubleForKey (string key, ref bool exists);

		[Export ("attributeAsIntForKey:exists:")]
		int AttributeAsIntForKey (string key, ref bool exists);

		[Export ("attributeAsUnsignedIntForKey:exists:")]
		uint AttributeAsUnsignedIntForKey (string key, ref bool exists);

		[Export ("attributeAsFloatForKey:exists:")]
		float AttributeAsFloatForKey (string key, ref bool exists);

		[Export ("attributeAsBoolForKey:exists:")]
		bool AttributeAsBoolForKey (string key, ref bool exists);

		[Export ("attributeAsLongForKey:exists:")]
		int AttributeAsLongForKey (string key, ref bool exists);

		[Export ("attributeAsIntegerForKey:exists:")]
		int AttributeAsIntegerForKey (string key, ref bool exists);

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
		AGSGraphic GraphicWithGeometry (AGSGeometry geometry, AGSSymbol symbol, NSDictionary attributes, AGSInfoTemplateDelegate infoTemplateDelegate);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSInfoTemplateDelegate {

		[Export ("titleForGraphic:screenPoint:mapPoint:")]
		string TitleForGraphic (AGSGraphic graphic, PointF screen, AGSPoint mapPoint);

		[Export ("detailForGraphic:screenPoint:mapPoint:")]
		string DetailForGraphic (AGSGraphic graphic, PointF screen, AGSPoint mapPoint);

		[Export ("imageForGraphic:screenPoint:mapPoint:")]
		UIImage ImageForGraphic (AGSGraphic graphic, PointF screen, AGSPoint mapPoint);

		[Export ("customViewForGraphic:screenPoint:mapPoint:")]
		UIView CustomViewForGraphic (AGSGraphic graphic, PointF screen, AGSPoint mapPoint);
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

	[BaseType (typeof (AGSGeometry))]
	public partial interface AGSPolyline {

		[Export ("numPaths")]
		int NumPaths { get; }

		[Export ("numPointsInPath:")]
		int NumPointsInPath (int path);

		[Export ("numPoints")]
		int NumPoints ();

		[Export ("pointOnPath:atIndex:")]
		AGSPoint PointOnPath (int path, int index);

		[Static, Export ("polylineWithJSON:")]
		AGSPolyline PolylineWithJSON (NSDictionary json);

		[Export ("isEqualToPolyline:")]
		bool IsEqualToPolyline (AGSPolyline other);
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

		[Export ("mapLocation")]
		AGSPoint MapLocation ();

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
	public partial interface AGSLocationDisplayDataSourceDelegate {

		[Export ("locationDisplayDataSource:didUpdateWithLocation:")]
		void DidUpdateWithLocation (AGSLocationDisplayDataSource dataSource, AGSLocation location);

		[Export ("locationDisplayDataSource:didUpdateWithHeading:")]
		void DidUpdateWithHeading (AGSLocationDisplayDataSource dataSource, double heading);

		[Export ("locationDisplayDataSource:didFailWithError:")]
		void DidFailWithError (AGSLocationDisplayDataSource dataSource, NSError error);

		[Export ("locationDisplayDataSourceStopped:")]
		void LocationDisplayDataSourceStopped (AGSLocationDisplayDataSource dataSource);

		[Export ("locationDisplayDataSourceStarted:")]
		void LocationDisplayDataSourceStarted (AGSLocationDisplayDataSource dataSource);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSLocationDisplayInfoTemplateDelegate {

		[Export ("titleForLocationDisplay:screenPoint:")]
		string TitleForLocationDisplay (AGSLocationDisplay ld, PointF screen);

		[Export ("detailForLocationDisplay:screenPoint:")]
		string DetailForLocationDisplay (AGSLocationDisplay ld, PointF screen);

		[Export ("imageForLocationDisplay:screenPoint:")]
		UIImage ImageForLocationDisplay (AGSLocationDisplay ld, PointF screen);

		[Export ("customViewForLocationDisplay:screenPoint:")]
		UIView CustomViewForLocationDisplay (AGSLocationDisplay ld, PointF screen);
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
		AGSSimpleLineSymbol SimpleLineSymbol (UIColor color);

		[Static, Export ("simpleLineSymbolWithColor:width:")]
		AGSSimpleLineSymbol SimpleLineSymbol (UIColor color, float width);
	}

	[BaseType (typeof (AGSSymbol))]
	public partial interface AGSCompositeSymbol {

		[Export ("symbols", ArgumentSemantic.Copy)]
		AGSSymbol [] Symbols { get; }

		[Static, Export ("compositeSymbol")]
		AGSCompositeSymbol CompositeSymbol ();

		[Export ("addSymbol:")]
		void AddSymbol (AGSSymbol symbol);

		[Export ("addSymbols:")]
		void AddSymbols (AGSSymbol [] symbols);

		[Export ("removeSymbol:")]
		void RemoveSymbol (AGSSymbol symbol);

		[Export ("removeAllSymbols")]
		void RemoveAllSymbols ();
	}

	[BaseType (typeof (AGSSymbol))]
	public partial interface AGSFillSymbol {

		[Export ("outline", ArgumentSemantic.Retain)]
		AGSSimpleLineSymbol Outline { get; set; }
	}

	[BaseType (typeof (AGSFillSymbol))]
	public partial interface AGSSimpleFillSymbol {

		[Export ("style")]
		AGSSimpleFillSymbolStyle Style { get; set; }

		[Static, Export ("simpleFillSymbol")]
		AGSSimpleFillSymbol SimpleFillSymbol ();

		[Export ("initWithColor:outlineColor:")]
		IntPtr Constructor (UIColor fillColor, UIColor outlineColor);

		[Static, Export ("simpleFillSymbolWithColor:outlineColor:")]
		AGSSimpleFillSymbol SimpleFillSymbol (UIColor fillColor, UIColor outlineColor);
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

		//[Export ("initWithContentsOfFile:")]
		//IntPtr Constructor (string imagePath);
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
		AGSTextSymbol TextSymbol (string text, UIColor color);
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

		//[Export ("initWithContentsOfFile:")]
		//IntPtr Constructor (string imagePath);

		[Static, Export ("pictureMarkerSymbolWithImageNamed:")]
		AGSPictureMarkerSymbol PictureMarkerSymbolWithImageNamed (string imageName);
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
		AGSUniqueValue UniqueValueWithValue (string value, AGSSymbol symbol);

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
		AGSClassBreak ClassBreak(string label, string description, double maxValue, AGSSymbol symbol);

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
		AGSSimpleRenderer SimpleRendererWithSymbol (AGSSymbol symbol);
	}

	[BaseType (typeof (AGSGraphicsLayer))]
	public partial interface AGSFeatureLayer : AGSCoding, AGSInfoTemplateDelegate/*, AGSSecuredResource*/ {

		[Export ("URL", ArgumentSemantic.Copy)]
		NSUrl URL { get; }

		[Export ("mode")]
		AGSFeatureLayerMode Mode { get; }

		//[Export ("credential", ArgumentSemantic.Copy)]
		//AGSCredential Credential { get; set; }

		//[Export ("credentialCache", ArgumentSemantic.Retain)]
		//AGSCredentialCache CredentialCache { get; set; }

		[Export ("requestCachePolicy")]
		NSUrlRequestCachePolicy RequestCachePolicy { get; set; }

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

		//[Export ("editingDelegate", ArgumentSemantic.Assign)]
		//AGSFeatureLayerEditingDelegate EditingDelegate { get; set; }

		[Export ("queryDelegate", ArgumentSemantic.Assign)]
		AGSFeatureLayerQueryDelegate QueryDelegate { get; set; }

		[Export ("outFields", ArgumentSemantic.Copy)]
		string [] OutFields { get; set; }

		[Export ("maxAllowableOffset")]
		double MaxAllowableOffset { get; set; }

		[Export ("queryable")]
		bool Queryable { [Bind ("isQueryable")] get; }


		[Export ("infoTemplateDelegate", ArgumentSemantic.Assign), NullAllowed]
		NSObject WeakInfoTemplateDelegate { get; set; }

		[Wrap ("WeakInfoTemplateDelegate"), NullAllowed]
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

		//[Export ("editFieldsInfo", ArgumentSemantic.Retain)]
		//AGSEditFieldsInfo EditFieldsInfo { get; }

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

		//[Export ("initWithURL:mode:credential:")]
		//IntPtr Constructor (NSUrl url, AGSFeatureLayerMode mode, AGSCredential cred);

		[Export ("initWithURL:mode:error:")]
		IntPtr Constructor (NSUrl url, AGSFeatureLayerMode mode, out NSError error);

		//[Export ("initWithURL:mode:credential:error:")]
		//IntPtr Constructor (NSUrl url, AGSFeatureLayerMode mode, AGSCredential cred, out NSError error);

		[Static, Export ("featureServiceLayerWithURL:mode:")]
		AGSFeatureLayer FeatureServiceLayerWithURL (NSUrl url, AGSFeatureLayerMode mode);

		//[Static, Export ("featureServiceLayerWithURL:mode:credential:")]
		//AGSFeatureLayer FeatureServiceLayerWithURL (NSUrl url, AGSFeatureLayerMode mode, AGSCredential cred);

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

		//[Export ("resubmitWithURL:credential:")]
		//void ResubmitWithURL (NSUrl url, AGSCredential cred);

		[Export ("templateForFeature:type:")]
		AGSFeatureTemplate TemplateForFeature (AGSGraphic feature, out AGSFeatureType type);

		[Export ("findFieldWithName:")]
		AGSField FindFieldWithName (string fieldName);

		//[Export ("attachmentManagerForFeature:")]
		//AGSAttachmentManager AttachmentManagerForFeature (AGSGraphic feature);

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

	[BaseType (typeof (NSObject))]
	public partial interface AGSRelationshipQuery : AGSCoding {

		[Export ("relationshipId")]
		int RelationshipId { get; set; }

		[Export ("objectIds", ArgumentSemantic.Copy)]
		NSNumber [] ObjectIds { get; set; }

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
		NSNumber [] ObjectIds { get; set; }

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
		IntPtr Constructor (string displayFieldName, AGSGraphic [] features, NSDictionary fieldAliases, AGSSpatialReference spatialReference, AGSGeometryType geometryType);

		[Export ("initWithFeatures:")]
		IntPtr Constructor (NSObject [] features);

		[Static, Export ("featureSetWithFeatures:")]
		AGSFeatureSet FeatureSetWithFeatures ( AGSGraphic [] features);
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
	public partial interface AGSDomain : AGSCoding {

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Static, Export ("domainWithJSON:parentField:")]
		NSObject DomainWithJSON (NSDictionary json, AGSField parentField);
	}

	[BaseType (typeof (NSObject))]
	public partial interface AGSFeatureType : AGSCoding {

		[Export ("typeId", ArgumentSemantic.Copy)]
		NSObject TypeId { get; }

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("templates", ArgumentSemantic.Copy)]
		AGSFeatureTemplate [] Templates { get; }

		[Export ("domains", ArgumentSemantic.Copy)]
		NSDictionary Domains { get; }
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
	public partial interface AGSRelationship : AGSCoding {

		[Export ("relationshipId")]
		int RelationshipId { get; }

		[Export ("name", ArgumentSemantic.Copy)]
		string Name { get; }

		[Export ("relatedTableId")]
		int RelatedTableId { get; }
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

}