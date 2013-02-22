[BaseType(typeof(AGSDomain))]
public interface AGSCodedValueDomain {

	[Export("codedValues", ArgumentSemantic.Copy)]
	AGSCodedValue[] CodedValues { get; }
	
}