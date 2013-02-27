[BaseType(typeof(AGSView))]
public interface AGSCallout  {

	[Export("mapView", ArgumentSemantic.None)]
	AGSMapView MapView { get; }

	[Export("mapLocation", ArgumentSemantic.Retain)]
	AGSPoint MapLocation { get; }

	[Export("pixelOffset", ArgumentSemantic.None)]
	Point PixelOffset { get; }

	[Export("width", ArgumentSemantic.None)]
	float Width { get; set; }

	[Export("title", ArgumentSemantic.Copy)]
	string Title { get; set; }

	[Export("detail", ArgumentSemantic.Copy)]
	string Detail { get; set; }

	[Export("color", ArgumentSemantic.Retain)]
	AGSColor Color { get; set; }

	[Export("highlight", ArgumentSemantic.Retain)]
	AGSColor Highlight { get; set; }

	[Export("titleColor", ArgumentSemantic.Retain)]
	AGSColor TitleColor { get; set; }

	[Export("detailColor", ArgumentSemantic.Retain)]
	AGSColor DetailColor { get; set; }

	[Export("accessoryButtonHidden", ArgumentSemantic.Assign)]
	bool AccessoryButtonHidden { [Export("isAccessoryButtonHidden")]get; set; }

	[Export("leaderPositionFlags", ArgumentSemantic.Assign)]
	AGSCalloutLeaderPosition LeaderPosition { get; set; }

	[Export("hidden", ArgumentSemantic.Assign)]
	bool Hidden { [Export("isHidden")]get; set; }

	[Export("delegate", ArgumentSemantic.None)]
	NSObject WeakDelegate { get; set; }

	[Wrap("WeakDelegate")]
	AGSCalloutDelegate Delegate { get; set; }

	[Export("moveCalloutTo:pixelOffset:animated:")]
	void MoveCallout(AGSPoint mapLocation, Point pixelOffset, bool animated);

	[Export("showCalloutAt:pixelOffset:animated:")]
	void ShowCallout(AGSPoint mapLocation, Point pixelOffset, bool animated);

	[Export("customView", ArgumentSemantic.Retain)]
	AGSView CustomView { get; set; }

	[Export("margin", ArgumentSemantic.None)]
	Size Margin { get; set; }

	[Export("cornorRadius", ArgumentSemantic.None)]
	float CornorRadius { get; set; }

	[Export("maxWidth", ArgumentSemantic.None)]
	float MaxWidth { get; set; }

	[Export("accessoryButtonType", ArgumentSemantic.None)]
	UIButtonType AccessoryButtonType { get; set; }

	[Export("accessoryButtonImage", ArgumentSemantic.Retain)]
	UIImage AccessoryButtonImage { get; set; }

	[Export("image", ArgumentSemantic.Retain)]
	AGSImage Image { get; set; }

	[Export("autoAdjustWidth", ArgumentSemantic.None)]
	bool AutoAdjustWidth { get; set; }

	[Export("representedObject", ArgumentSemantic.Retain)]
	object RepresentedObject { get; }

	[Export("showCalloutAtPoint:forGraphic:animated:")]
	void ShowCallout(AGSPoint mapPoint, AGSGraphic graphic, bool animated);

	[Export("showCalloutForLocationDisplay")]
	void ShowCalloutForLocationDisplay()

	[Export("showCalloutAt:pixelOffset:rotateOffsetWithMap:animated:")]
	void ShowCallout(AGSPoint mapLocation, Point pixelOffset, bool rotateOffsetWithMap, bool animated);

	[Export("moveCalloutTo:pixelOffset:rotateOffsetWithMap:animated:")]
	void MoveCallout(AGSPoint mapLocation, Point pixelOffset, bool rotateOffsetWithMap, bool animated);

	[Export("dismiss")]
	void Dismiss()

}

[Model, BaseType(typeof(NSObject))]
public interface AGSCalloutDelegate {

	[Export("didClickAccessoryButtonForCallout:")]
	void DidClickAccessoryButtonForCallout(AGSCallout callout);
}