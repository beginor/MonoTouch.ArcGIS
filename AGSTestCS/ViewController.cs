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

			var url = NSUrl.FromString("http://agserver.gdepb.gov.cn/arcgis/rest/services/BaseMap/MRoad/MapServer");
			var layer = AGSTiledMapServiceLayer.TiledMapServiceLayerWithURL(url);
			this.MapView.AddMapLayer(layer, "Tiled Layer");

			var envelop = AGSEnvelope.EnvelopeWith(12178333, 2973103, 13088239, 2255207, AGSSpatialReference.WebMercatorSpatialReference());

			this.MapView.ZoomToEnvelope(envelop, false);
		}

		public override UIInterfaceOrientationMask GetSupportedInterfaceOrientations() {
			return UIInterfaceOrientationMask.All;
		}
	}
}

