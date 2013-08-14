
using System;
using System.Drawing;
using MonoTouch.Foundation;
using MonoTouch.UIKit;
using MonoTouch.ArcGIS;

namespace CloudDataTutorial {

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
			// add a basemap tiled layer.
			var url = NSUrl.FromString("http://services.arcgisonline.com/ArcGIS/rest/services/Canvas/World_Light_Gray_Base/MapServer");
			var tiledLayer = AGSTiledMapServiceLayer.TiledMapServiceLayerWithURL(url);
			this.MapView.AddMapLayer(tiledLayer, "Basemap Tiled Layer");

			// cloud data
			var featureLayerUrl = NSUrl.FromString("http://services.arcgis.com/oKgs2tbjK6zwTdvi/arcgis/rest/services/Major_World_Cities/FeatureServer/0");
			var featureLayer = AGSFeatureLayer.FeatureServiceLayerWithURL(featureLayerUrl, AGSFeatureLayerMode.OnDemand);
			this.MapView.AddMapLayer(featureLayer, "CloudData");

			// symbology
			AGSSimpleMarkerSymbol featureSymbol = AGSSimpleMarkerSymbol.SimpleMarkerSymbolWithColor(UIColor.FromRGBA(0f, 0.46f, 0.68f, 1f));
			featureSymbol.Size = new SizeF(7, 7);
			featureSymbol.Style = AGSSimpleMarkerSymbolStyle.Circle;
			//featureSymbol.Outline
			featureLayer.Renderer = AGSSimpleRenderer.SimpleRendererWithSymbol(featureSymbol);
		}
	}
}

