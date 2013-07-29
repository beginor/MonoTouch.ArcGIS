// WARNING
//
// This file has been generated automatically by Xamarin Studio to store outlets and
// actions made in the UI designer. If it is removed, they will be lost.
// Manual changes to this file may not be handled correctly.
//
using MonoTouch.Foundation;
using System.CodeDom.Compiler;

namespace AGSTestCS
{
	[Register ("ViewController")]
	partial class ViewController
	{
		[Outlet]
		MonoTouch.UIKit.UISegmentedControl BaseLayerSegment { get; set; }

		[Outlet]
		MonoTouch.UIKit.UISegmentedControl FeatureLayerSegment { get; set; }

		[Outlet]
		MonoTouch.ArcGIS.AGSMapView MapView { get; set; }

		[Outlet]
		MonoTouch.UIKit.UIToolbar Toolbar { get; set; }
		
		void ReleaseDesignerOutlets ()
		{
			if (BaseLayerSegment != null) {
				BaseLayerSegment.Dispose ();
				BaseLayerSegment = null;
			}

			if (MapView != null) {
				MapView.Dispose ();
				MapView = null;
			}

			if (Toolbar != null) {
				Toolbar.Dispose ();
				Toolbar = null;
			}

			if (FeatureLayerSegment != null) {
				FeatureLayerSegment.Dispose ();
				FeatureLayerSegment = null;
			}
		}
	}
}
