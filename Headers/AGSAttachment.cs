[BaseType(typeof(NSObject))]
public interface AGSAttachment {

	[Export("attachmentInfo", ArgumentSemantic.Strong)]
	AGSAttachmentInfo AttachmentInfo { get; }

	[Export("filepath", ArgumentSemantic.Copy)]
	string FilePath { get; set; }

	[Export("editState", ArgumentSemantic.Assign)]	
	AGSAttachmentEditState EditState { get; }

	[Export("editResultError", ArgumentSemantic.Strong)]
	AGSEditResultError EditResultError { get; }

	[Export("networkError", ArgumentSemantic.Strong)]
	NSError NetworkError { get; }

	[Export("isDownloading", ArgumentSemantic.Assign)]
	bool IsDownloading { get; }

	[Export("markForDeletion:")]
	void MarkForDeletion(bool del);

	[Export("existsOnServer")]
	bool ExistsOnServer();

	[Export("isLocal")]
	bool IsLocal();

	[Export("thumbnail")]
	AGSImage GetThumbnail();

	[Export("data")]
	NSData GetData();
}