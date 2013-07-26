using System;
using System.Drawing;
using System.Linq;
using MonoTouch.Foundation;
using MonoTouch.UIKit;
using MonoTouch.ArcGIS;

namespace AGSTestCS {

	public partial class ViewController : UIViewController {

		private static readonly string[] BaseLayerUrls = new [] {
			"http://services.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer",
			"http://services.arcgisonline.com/ArcGIS/rest/services/World_Street_Map/MapServer",
			"http://services.arcgisonline.com/ArcGIS/rest/services/World_Topo_Map/MapServer"
		};

		private static readonly string BaseLayerName = "Base Map Layer";

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

			this.SetBaseLayer(this.BaseLayerSegment.SelectedSegment);

			var envelop = AGSEnvelope.EnvelopeWith(12178333, 2973103, 13088239, 2255207, AGSSpatialReference.WebMercatorSpatialReference());

			this.MapView.ZoomToEnvelope(envelop, false);

			this.BaseLayerSegment.ValueChanged += BaseLayerSegment_ValueChanged;
		}

		void BaseLayerSegment_ValueChanged (object sender, EventArgs e) {
			var selectedIndex = this.BaseLayerSegment.SelectedSegment;
			SetBaseLayer(selectedIndex);
		}

		void SetBaseLayer(int selectedIndex) {
			if (this.MapView.MapLayers.Any(l => l.Name == BaseLayerName)) {
				this.MapView.RemoveMapLayerWithName(BaseLayerName);
			}
			var url = NSUrl.FromString(BaseLayerUrls[selectedIndex]);
			var baseLayer = new AGSTiledMapServiceLayer(url) {
				Name = BaseLayerName
			};
			this.MapView.AddMapLayer(baseLayer, BaseLayerName);
		}

		public override UIInterfaceOrientationMask GetSupportedInterfaceOrientations() {
			return UIInterfaceOrientationMask.All;
		}
	}
}

