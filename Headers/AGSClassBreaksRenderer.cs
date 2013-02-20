[BaseType(typeof(AGSRenderer))]
public interface AGSClassBreaksRenderer  {

	[Export("field", ArgumentSemantic.Copy)]
	string Field { get; set; }

	[Export("classBreaks", ArgumentSemantic.Copy)]
	AGSClassBreak[] ClassBreaks { get; set; }

	[Export("minValue", ArgumentSemantic.Assign)]
	double MinValue { get; set; }

	[Export("defaultSymbol", ArgumentSemantic.Retain)]
	AGSSymbol DefaultSymbol { get; set; }
}