[BaseType(typeof(AGSTask))]
public interface AGSClosestFacilityTask {

	[Export("delegate", ArgumentSemantic.None)]
	NSObject WeakDelegate { get; set; }

	[Wrap("WeakDelegate")]
	AGSClosestFacilityTaskDelegate Delegate { get; set; }

	[Static, Export("closestFacilityTaskWithURL:")]
	AGSClosestFacilityTask FromUrl(Url url);

	[Static, Export("closestFacilityTaskWithURL:credential:")]
	AGSClosestFacilityTask FromUrl(Url url, AGSCredential cred);

	[Export("solveClosestFacilityWithParameters:")]
	NSOperation SolveClosestFacilityWithParameters(AGSClosestFacilityTaskParameters closestFacilityParams);
}

[Model, BaseType(typeof(NSObject))]
public interface AGSClosestFacilityTaskDelegate {

	[Abstract, Export("closestFacilityTask:operation:didSolveClosestFacilityWithResult:")]
	void DidSolveClosestFacilityWithResult(AGSClosestFacilityTask closestFacilityTask, NSOperation op, AGSClosestFacilityTaskResult closestFacilityTaskResult);

	[Export("closestFacilityTask:operation:didFailSolveWithError:")]
	void DidFailSolveWithError(AGSClosestFacilityTask closestFacilityTask, NSOperation op, NSError error);

	[Export("closestFacilityTask:operation:didRetrieveDefaultClosestFacilityTaskParameters:")]
	void DidRetrieveDefaultClosestFacilityTaskParameters(AGSClosestFacilityTask closestFacilityTask, NSOperation op, AGSClosestFacilityTaskParameters closestFacilityParams);

	[Export("closestFacilityTask:operation:didFailToRetrieveDefaultClosestFacilityTaskParametersWithError")]
	void DidFailToRetrieveDefaultClosestFacilityTaskParametersWithError(AGSClosestFacilityTask closestFacilityTadidFailToRetrieveDefaultClosestFacilityTaskParametersWithErrorsk, NSOperation op, NSError error);
}