[BaseType(typeof(AGSTiledServiceLayer))]
public interface AGSBingMapLayer {

	[Export("spatialReference", ArgumentSemantic.Retain)]
	AGSSpatialReference SpatialReference { get; }

	[Export("fullEnvelope", ArgumentSemantic.Retain)]
	AGSEnvelope FullEnvelop { get; }

	[Export("tileInfo", ArgumentSemantic.Retain)]
	AGSTileInfo TileInfo { get; }

	[Export("appID", ArgumentSemantic.Copy)]
	string AppId { get; }

	[Export("style", ArgumentSemantic.Assign)]
	AGSBingMapLayerStyle Style { get; set; }

	[Export("locale", ArgumentSemantic.Retain)]
	NSLocale Locale { get; set; }

	[Export("initWithAppID:style:")]
	IntPtr Constructor(string appId, AGSBingMapLayerStyle style);

}