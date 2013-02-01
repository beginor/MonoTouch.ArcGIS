/// <summary>A protocol to convert objects to and from JSON.</summary>
[Model, BaseType(typeof(NSObject))]
public interface AGSCoding {

	/// <summary>Initialize and return object from JSON representation.</summary>
	[Export("initWithJSON:")]
	IntPtr Constructor(Dictionary json);

	/// <summary>Decode object from JSON representation.</summary>
	[Export("decodeWithJSON:")]
	void DecodeWithJson(Dictionary json);

	/// <summary>Encode and return JSON representation for object.</summary>
	[Export("encodeToJSON")]
	Dictionary EncodeToJson();
}