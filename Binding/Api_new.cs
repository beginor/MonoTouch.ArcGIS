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
		NSObject SpatialReferenceWithWKID (uint wkid);

		[Static, Export ("spatialReferenceWithWKT:")]
		NSObject SpatialReferenceWithWKT (string wkt);

		[Export ("initWithWKID:WKT:")]
		IntPtr Constructor (uint wkid, string wkt);

		[Static, Export ("spatialReferenceWithWKID:WKT:")]
		NSObject SpatialReferenceWithWKID (uint wkid, string wkt);

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
		AGSEnvelope EnvelopeWithXmin (double xmin, double ymin, double xmax, double ymax, AGSSpatialReference spatialReference);

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
		NSObject PointWithX (double x, double y, AGSSpatialReference spatialReference);

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
		AGSTimeExtent TimeExtentWithStart (NSDate start, NSDate end);

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

		//		[Export ("credential", ArgumentSemantic.Copy)]
		//		AGSCredential Credential { get; set; }

		//		[Export ("credentialCache", ArgumentSemantic.Retain)]
		//		AGSCredentialCache CredentialCache { get; set; }

		[Export ("renderNativeResolution")]
		bool RenderNativeResolution { get; set; }

		[Export ("initWithURL:")]
		IntPtr Constructor (NSUrl url);

		//[Export ("initWithURL:credential:")]
		//IntPtr Constructor (NSUrl url, AGSCredential cred);

		//[Export ("initWithMapServiceInfo:")]
		//IntPtr Constructor (AGSMapServiceInfo info);

		[Static, Export ("tiledMapServiceLayerWithURL:")]
		NSObject TiledMapServiceLayerWithURL (NSUrl url);

		//[Static, Export ("tiledMapServiceLayerWithURL:credential:")]
		//AGSTiledMapServiceLayer TiledMapServiceLayerWithURL (NSUrl url, AGSCredential cred);

		//[Static, Export ("tiledMapServiceLayerWithMapServiceInfo:")]
		//AGSTiledMapServiceLayer TiledMapServiceLayerWithMapServiceInfo (AGSMapServiceInfo info);

		//[Export ("initWithJSON:URL:credential:")]
		//IntPtr Constructor (NSDictionary json, NSUrl url, AGSCredential cred);

		//[Export ("resubmit")]
		//void Resubmit ();

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

		//[Export ("locationDisplay", ArgumentSemantic.Retain)]
		//AGSLocationDisplay LocationDisplay { get; }

		//[Export ("callout", ArgumentSemantic.Retain)]
		//AGSCallout Callout { get; }

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

		//[Export ("mapView:shouldFindGraphicsInLayer:atPoint:mapPoint:")]
		//bool ShouldFindGraphicsInLayer (AGSMapView mapView, AGSGraphicsLayer graphicsLayer, PointF screen, AGSPoint mappoint);
	}

	[Model, BaseType (typeof (NSObject))]
	public partial interface AGSMapViewCalloutDelegate {

		//[Export ("mapView:shouldShowCalloutForLocationDisplay:")]
		//bool ShouldShowCalloutForLocationDisplay (AGSMapView mapView, AGSLocationDisplay ld);

		//[Export ("mapView:didShowCalloutForLocationDisplay:")]
		//void DidShowCalloutForLocationDisplay (AGSMapView mapView, AGSLocationDisplay ld);

		//[Export ("mapView:shouldShowCalloutForGraphic:")]
		//bool ShouldShowCalloutForGraphic (AGSMapView mapView, AGSGraphic graphic);

		//[Export ("mapView:didShowCalloutForGraphic:")]
		//void DidShowCalloutForGraphic (AGSMapView mapView, AGSGraphic graphic);

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
		NSObject PolygonWithJSON (NSDictionary json);

		[Export ("containsPoint:")]
		bool ContainsPoint (AGSPoint point);

		[Export ("isEqualToPolygon:")]
		bool IsEqualToPolygon (AGSPolygon other);
	}
}