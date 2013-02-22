[BaseType(typeof(NSObject))]
public interface AGSCodedValue : AGSCoding {

	[Export("name", ArgumentSemantic.Copy)]
	string name { get; }

	[Export("code", ArgumentSemantic.Retain)]
	object Code { get; }
	
}