[BaseType(typeof(NSObject))]
public interface AGSClosestFacilityResult {

	[Export("directions", ArgumentSemantic.Retain)]
	AGSDirectionSet Directions { get; }

	[Export("routeGraphic", ArgumentSemantic.Retain)]
	AGSGraphic RouteGraphic { get; }

	[Export("routeName", ArgumentSemantic.Copy)]
	string RouteName { get; }
	
}