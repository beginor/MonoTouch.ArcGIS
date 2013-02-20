[BaseType(typeof(NSObject))]
public interface AGSClassBreak : AGSCoding {

	[Export("label", ArgumentSemantic.Copy)]
	string Label { get; set; }

	[Export("breakDescription", ArgumentSemantic.Copy)]
	string BreakDescription { get; set; }

	[Export("maxValue", ArgumentSemantic.None)]
	double MaxValue { get; set; }

	[Export("symbol", ArgumentSemantic.Retain)]
	AGSSymbol Symbol { get; set; }

	[Export("initWithLabel:description:maxValue:")]
	IntPtr Constructor(string label, string description, double maxValue);

	[Static, Export("classBreakInfoWithLabel:description:maxValue:")]
	AGSClassBreak Create(string label, string description, double maxValue);

	[Export("compare:")]
	NSComparisonResult Compare(AGSClassBreak another);
}