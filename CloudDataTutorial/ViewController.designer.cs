// WARNING
//
// This file has been generated automatically by Xamarin Studio to store outlets and
// actions made in the UI designer. If it is removed, they will be lost.
// Manual changes to this file may not be handled correctly.
//
using MonoTouch.Foundation;
using System.CodeDom.Compiler;

namespace CloudDataTutorial
{
	[Register ("ViewController")]
	partial class ViewController
	{
		[Outlet]
		MonoTouch.ArcGIS.AGSMapView MapView { get; set; }

		[Action ("ShowCountryPicker:")]
		partial void ShowCountryPicker (MonoTouch.UIKit.UIButton sender);
		
		void ReleaseDesignerOutlets ()
		{
			if (MapView != null) {
				MapView.Dispose ();
				MapView = null;
			}
		}
	}
}
