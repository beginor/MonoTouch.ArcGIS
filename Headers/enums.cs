using System;
using System.Collections;
using System.Drawing;

using MonoTouch.ObjCRuntime;
using MonoTouch.Foundation;
using MonoTouch.UIKit;

namespace MonoTouch.ArcGIS {

	public enum AGSAttachmentEditState {
		Original = 0,		
		Added,			
		MarkedForDeletion,
		DeletedFromServer 
	}
}