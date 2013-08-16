
using System;
using System.Drawing;
using MonoTouch.Foundation;
using MonoTouch.UIKit;
using MonoTouch.ArcGIS;

namespace CloudDataTutorial {

	public partial class ViewController : UIViewController {

		public string[] Countries {
			get;
			set;
		}

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
			featureLayer.OutFields = new string[] { "*" };
			this.MapView.AddMapLayer(featureLayer, "CloudData");

			// symbology
			AGSSimpleMarkerSymbol featureSymbol = AGSSimpleMarkerSymbol.SimpleMarkerSymbolWithColor(UIColor.FromRGBA(0f, 0.46f, 0.68f, 1f));
			featureSymbol.Size = new SizeF(7, 7);
			featureSymbol.Style = AGSSimpleMarkerSymbolStyle.Circle;
			//featureSymbol.Outline
			featureLayer.Renderer = AGSSimpleRenderer.SimpleRendererWithSymbol(featureSymbol);
		}

		partial void ShowCountryPicker(UIButton sender) {
			if (this.Countries == null) {
				this.Countries = new string[] { @"None",@"US",@"Canada",@"France",@"Australia",@"Brazil" };
			}

			var pickerSheet = new UIActionSheet(new RectangleF(0, 0, 320, 410));
			pickerSheet.ShowInView(this.View);
			pickerSheet.Bounds = new RectangleF(0, 0, 320, 410);

			var countryPicker = new UIPickerView(pickerSheet.Bounds);
			countryPicker.WeakDelegate = this;
			countryPicker.DataSource = this;
			countryPicker.ShowSelectionIndicator = true;

			pickerSheet.AddSubview(countryPicker);
		}

		#region "UIPickerview DataSource Part"
		[Export("numberOfComponentsInPickerView:")]
		public int GetComponentCount(UIPickerView picker) {
			return 1;
		}

		[Export("pickerView:numberOfRowsInComponent:")]
		public virtual int GetRowsInComponent(UIPickerView picker, int component) {
			return this.Countries.Length;
		}

		[Export("pickerView:titleForRow:forComponent:")]
		public virtual string GetTitle(UIPickerView picker, int row, int component) {
			return this.Countries[row];
		}
		#endregion

		#region "UIPickerview Delegate Part"
		[Export("pickerView:didSelectRow:inComponent:")]
		public virtual void Selected(UIPickerView picker, int row, int component) {
			var countryName = this.Countries[row];
			var featureLayer = (AGSFeatureLayer)this.MapView.MapLayerForName("CloudData");

			if (featureLayer.SelectionSymbol == null) {
				// SYMBOLOGY FOR WHERE CLAUSE SELECTION
				var selectedFeatureSymbol = AGSSimpleMarkerSymbol.SimpleMarkerSymbolWithColor(UIColor.FromRGBA(0.78f, 0.3f, 0.19f, 1f));
				selectedFeatureSymbol.Style = AGSSimpleMarkerSymbolStyle.Circle;
				selectedFeatureSymbol.Size = new SizeF(10, 10);
				featureLayer.SelectionSymbol = selectedFeatureSymbol;
			}

			if (featureLayer.QueryDelegate == null) {
				featureLayer.QueryDelegate = new FeatureLayerQueryDelegate();
			}

			if (countryName == "None") {
				// CLEAR SELECTION
				featureLayer.ClearSelection();
			}
			else {
				var selectQuery = AGSQuery.Query();
				selectQuery.Where = string.Format("COUNTRY = {0}", countryName);
				featureLayer.SelectFeaturesWithQuery(selectQuery, AGSFeatureLayerSelectionMethod.New);
			}

			// Dismiss action sheet
			var pickerSheet = (UIActionSheet)picker.Superview;
			pickerSheet.DismissWithClickedButtonIndex(0, true);
		}
		#endregion

	}

	public class FeatureLayerQueryDelegate : AGSFeatureLayerQueryDelegate {

		public override void DidSelectFeaturesWithFeatureSet(AGSFeatureLayer featureLayer, NSOperation op, AGSFeatureSet featureSet) {
			int a = 2;
		}

		public override void DidFailSelectFeaturesWithError(AGSFeatureLayer featureLayer, NSOperation op, NSError error) {
			int a = 1;
		}
	}
}

