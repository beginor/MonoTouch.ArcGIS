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

		private static readonly string[] FeatureLayerUrls = new [] {
			"http://sampleserver1.arcgisonline.com/ArcGIS/rest/services/Specialty/ESRI_StatesCitiesRivers_USA/MapServer/0"
		};

		private static readonly string BaseLayerName = "Base Map Layer";
		private static readonly string TestFeatureLayerName = "Test Feature Layer";

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

			var envelop = AGSEnvelope.EnvelopeWith(-20459599, 2391609, -6833470, 11289636, AGSSpatialReference.WebMercatorSpatialReference());

			this.MapView.ZoomToEnvelope(envelop, false);

			this.BaseLayerSegment.ValueChanged += BaseLayerSegment_ValueChanged;
			this.FeatureLayerSegment.ValueChanged += FeatureLayerSegment_ValueChanged;
		}

		void BaseLayerSegment_ValueChanged (object sender, EventArgs e) {
			var selectedIndex = this.BaseLayerSegment.SelectedSegment;
			SetBaseLayer(selectedIndex);
		}

		void FeatureLayerSegment_ValueChanged(object sender, EventArgs e) {
			var index = this.FeatureLayerSegment.SelectedSegment;
			this.SetTestFeatureLayer(index);
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

		void SetTestFeatureLayer(int index) {
			this.MapView.RemoveMapLayerWithName(TestFeatureLayerName);
			var url = NSUrl.FromString(FeatureLayerUrls[0]);
			var testFeatureLayer = AGSFeatureLayer.FeatureServiceLayerWithURL(url, AGSFeatureLayerMode.OnDemand);
			testFeatureLayer.OutFields = new string[] { "*" };


			var testSymbol = new AGSSimpleMarkerSymbol(UIColor.Red) {
				Size = new SizeF(30, 30),
				Style = AGSSimpleMarkerSymbolStyle.Circle
			};
			testFeatureLayer.Renderer = new AGSSimpleRenderer(testSymbol);

			//testFeatureLayer.WeakInfoTemplateDelegate = new TestInfoTemplateDelegate();
			var testInfoTemplateDelegate = new TestInfoTemplateDelegate();
			testFeatureLayer.InfoTemplateDelegate = testInfoTemplateDelegate;

			this.MapView.AddMapLayer(testFeatureLayer, TestFeatureLayerName);
		}

		public override UIInterfaceOrientationMask GetSupportedInterfaceOrientations() {
			return UIInterfaceOrientationMask.All;
		}
		
	}

	public class TestInfoTemplateDelegate : AGSInfoTemplateDelegate {

		public override string TitleForGraphic(AGSGraphic graphic, PointF screen, AGSPoint mapPoint) {
			var cityName = graphic.AttributeForKey("CITY_NAME");
			return cityName.ToString();
		}

		public override string DetailForGraphic(AGSGraphic graphic, PointF screen, AGSPoint mapPoint) {
			var cityFips = graphic.AttributeAsStringForKey("CITY_FIPS");
			var cityName = graphic.AttributeAsStringForKey("CITY_NAME");
			var stateFips = graphic.AttributeAsStringForKey("STATE_FIPS");
			var stateName = graphic.AttributeAsStringForKey("STATE_NAME");
			return string.Format(
				"{0}, {1}, {2}, {3}",
				cityFips,
				cityName,
				stateFips,
				stateName
			);
		}
		
	}
}

