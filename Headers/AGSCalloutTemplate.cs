[BaseType(typeof(NSObject))]
public interface AGSCalloutTemplate : AGSInfoTemplateDelegate  {

	[Export("titleTemplate", ArgumentSemantic.Copy)]
	string TitleTemplate { get; set; }

	[Export("detailTemplate", ArgumentSemantic.Copy)]
	string DetailTemplate { get; set; }
	
}