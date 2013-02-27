[BaseType(typeof(NSobject))]
public interface AGSBase64 {

	[Static, Export("initialize")]
	void Itialize();

	[Static, Export("encode:length:")]
	string Encode(byte[] bytes input, int length);

	[Static, Export("encode:")]
	string Encode(NSData rawData);

	[Static, Export("decode:string:length:")]
	NSData Decode(string str, int length)

	[Static, Export("string")]
	NSData Decode(string);
}
