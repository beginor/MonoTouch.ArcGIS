[BaseType(typeof(NSObject))]
public interface AGSAttachmentInfo : AGSCoding {

	[Export("attachmentId", ArgumentSemantic.Assign)]
	int AttachmentId { get; }

	[Export("contentType", ArgumentSemantic.Copy)]
	string ContentType { get; }

	[Export("size", ArgumentSemantic.Assign)]
	int Size { get; }

	[Export("name", ArgumentSemantic.Copy)]
	string Name { get; }

	[Export("isEqualToAttachmentInfo:")]
	bool IsEqualToAttachmentInfo(AGSAttachmentInfo other);
}