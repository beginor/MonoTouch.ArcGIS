using System;
using System.Drawing;
using MonoTouch.Foundation;
using MonoTouch.UIKit;
using MonoTouch.ArcGIS;

namespace AGSTestCS {

	public partial class ViewController : UIViewController {

		public ViewController() : base ("ViewController", null) {
		}

		public override void DidReceiveMemoryWarning() {
			// Releases the view if it doesn't have a superview.
			base.DidReceiveMemoryWarning();
			
			// Release any cached data, images, etc that aren't in use.
		}

		public override void ViewDidLoad() {
			base.ViewDidLoad();
			
			// Perform any additional setup after loading the view, typically from a nib.
			var mapView = new AGSMapView();
			mapView.Frame = this.View.Frame;
			this.View.AddSubview(mapView);

			var layer = AGSTiledMapServiceLayer.TiledMapServiceLayerWithURL(NSUrl.FromString("http://server.arcgisonline.com/ArcGIS/rest/services/ESRI_StreetMap_World_2D/MapServer"));
			mapView.AddMapLayer(layer, "Tiled Layer");

			var envelop = AGSEnvelope.EnvelopeWithXmin(-124, 30, -113, 44, AGSSpatialReference.Wgs84SpatialReference());

			mapView.ZoomToEnvelope(envelop, false);
		}

		public override UIInterfaceOrientationMask GetSupportedInterfaceOrientations() {
			return UIInterfaceOrientationMask.All;
		}
	}
}

