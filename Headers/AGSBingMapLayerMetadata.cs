[BaseType(typeof(NSObject))]
public interface AGSBingMapLayerMetadata : AGSCoding {

	[Export("imageUri", ArgumentSemantic.Copy)]
	string ImageUri { get; }

	[Export("subDomains", ArgumentSemantic.Copy)]
	string[] SubDomains { get; }

	[Export("zoomRangeFrom", ArgumentSemantic.Assign)]
	ing ZoomRangeFrom { get; }

	[Export("zoomRangeTo", ArgumentSemantic.Assign)]
	int ZoomRangeTo { get; }
}