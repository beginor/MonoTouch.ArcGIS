[BaseType(typeof(NSObject))]
public interface AGSAddressCandidate : AGSCoding {

	[Export("addressString"), ArgumentSemantic.Copy]
	string AddressString { get; }

	[Export("address", ArgumentSemantic.Copy)]
	Dictionary Address { get; }

	[Export("attributes", ArgumentSemantic.Copy)]
	Dictionary Attributes { get; }

	[Export("location", ArgumentSemantic.Strong)]
	AGSPoint Location { get; }

	[Export("score")]
	double Score { get; }
}