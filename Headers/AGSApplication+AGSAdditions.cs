[BaseType(typeof(UIApplication))]
public interface AGSApplication {

	[Export("ags_setNetworkActivityDelegate:")]
	void SetNetworkActivityDelegate(AGSNetworkActivityDelegate agsNetworkActivityDelegate);

	[Export("ags_showNetworkActivityIndicator:")]
	void ShowNetworkActivityIndicator(bool show);
}

[Model, BaseType(typeof(NSObject))]
public interface AGSNetworkActivityDelegate {

	[Export("networkActivityInProgress")]
	void NetworkActivityInProgress();

	[Export("networkActivityEnded")]
	void NetworkActivityEnded();
	
}