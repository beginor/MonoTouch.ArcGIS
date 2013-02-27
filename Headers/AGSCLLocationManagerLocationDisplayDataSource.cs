[BaseType(typeof(NSObject))]
public interface AGSCLLocationManagerLocationDisplayDataSource :  AGSLocationDisplayDataSource {

	[Export("locationManager", ArgumentSemantic.Retain)]
	CLLocationManager LocationManager { get; }
	
}