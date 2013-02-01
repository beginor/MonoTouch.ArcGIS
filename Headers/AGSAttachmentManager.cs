[BaseType(typeof(NSObject))]
public interface AGSAttachmentManager : AGSFeatureLayerEditingDelegate {


	[Export("delegate", NullAllowed)]
	NSObject WeakDelegate { get; set; }

	[Wrap("WeakDelegate")]
	AGSAttachmentManagerDelegate Delegate { get; set; }


	[Export("featureLayer", ArgumentSemantic.Weak)]
	AGSFeatureLayer FeatureLayer { get; }

	[Export("featureObjectId", ArgumentSemantic.Assign)]
	int FeatureObjectId { get; }

	[Export("downloadAttachmentInfosError", ArgumentSemantic.Strong)]
	NSError DownloadAttachmentInfosError { get; }

	[Export("postingLocalEdits", ArgumentSemantic.Assign)]
	bool PostingLocalEdits { get; }

	[Export("attachments", ArgumentSemantic.Copy)]
	AGSAttachment[] Attachments { get; }

	[Export("attachmentForId:")]
	AGSAttachment AttachmentForId(int attachmentId);

	[Export("hasLocalEdits")]
	bool HasLocalEdits();

	[Export("cancelLocalEdits")]
	void CancelLocalEdits();

	[Export("addAttachmentAsJpgWithImage:name:")]
	AGSAttachment AddAttachment(AGSImage mage, string name);

	[Export("addAttachmentWithUIImagePickerControllerInfoDictionary:")]
	AGSAttachment AddAttachmentWithUIImagePickerControllerInfoDictionary(Dictionary info);

	[Export("addAttachmentWithData:name:contentType:")]
	AGSAttachment AddAttachmentWithData(NSData data, string name, string contentType);

	[Export("markAttachment:forDeletion:")]
	void MarkAttachmentForDeletion(AGSAttachment attachment, bool del);

	[Export("downloadAttachmentInfos")]
	void DownloadAttachmentInfos();

	[Export("downloadAttachmentDataForId:")]
	void DownloadAttachmentDataForId(int attachmentId);

	[Export("postLocalEditsToServer")]
	void PostLocalEditsToServer();

	[Export("cancelPostLocalEditsToServer")]
	void CancelPostLocalEditsToServer();

	[Export("cancelDownloadDataForId:")]
	void CancelDownloadDataForId(int attachmentId);

	[Export("cancelAllDownloadDataOperations")]
	void CancelAllDownloadDataOperations();

	[Export("cancelDownloadAttachmentInfos")]
	void CancelDownloadAttachmentInfos();

}

[Model]
public interface AGSAttachmentManagerDelegate {

	[Export("attachmentManager:didDownloadAttachmentInfos:")]
	void DidDownloadAttachmentInfos(AGSAttachmentManager manager, AGSAttachmentInfo[] infos);

	[Export("attachmentManager:didDownloadDataForAttachment:")]
	void DidDownloadDataForAttachment(AGSAttachmentManager manager, AGSAttachment attachment);

	[Export("attachmentManager:didPostLocalEditsToServer:")]
	void DidPostLocalEditsToServer(AGSAttachmentManager manager, AGSAttachment[] attachments);

}