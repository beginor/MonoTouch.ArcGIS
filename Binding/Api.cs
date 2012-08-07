using System;
using System.Drawing;

using MonoTouch.ObjCRuntime;
using MonoTouch.Foundation;
using MonoTouch.UIKit;

namespace MonoTouch.ArcGIS {
	// For more information, see http://docs.xamarin.com/ios/advanced_topics/binding_objective-c_types

	//@interface AGSAttachment : NSObject
	[BaseType(typeof(NSObject))]
	public interface AGSAttachment {

		[Export("attachmentInfo", ArgumentSemantic.Retain)]
		AGSAttachmentInfo AttachmentInfo { get; }

		[Export("filepath", ArgumentSemantic.Retain)]
		string FilePath { get; }

		[Export("editState", ArgumentSemantic.Assign)]
		AGSAttachmentEditState EditState { get; }

		[Export("editResultError", ArgumentSemantic.Retain)]
		AGSEditResultError EditResultError { get; }

		[Export("networkError", ArgumentSemantic.Retain)]
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
		UIImage Thumbnail();

		[Export("data")]
		NSData Data();
	}
}

