[BaseType(typeof(NSObject))]
public interface AGSAreasAndLengthsParameters : AGSCoding {

	[Export("polygons", ArgumentSemantic.Copy)]
	AGSPolygon[] Polygons { get; set; }

	[Export("lengthUnit", ArgumentSemantic.Assign)]
	AGSSRUnit LengthUnit { get; set; }

	[Export("areaUnit", ArgumentSemantic.Assign)]
	AGSAreaUnits AreaUnit { get; set; }

	[Export("areasAndLengthsParameters"), Static]
	AGSAreasAndLengthsParameters AreasAndLengthsParameters();
}