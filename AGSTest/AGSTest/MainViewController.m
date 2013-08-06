//
//  MainViewController.m
//  AGSTest
//
//  Created by zhangzhimin on 7/24/13.
//  Copyright (c) 2013 gdeic. All rights reserved.
//

#import "MainViewController.h"
#import "TestInfoTemplateDelegate.h"

#define BASE_Layer_Name @"Base Map Layer"

@interface MainViewController ()

@property NSArray *baseLayerUrls;

@end

@implementation MainViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
		 self.baseLayerUrls = @[@"http://services.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer", @"http://services.arcgisonline.com/ArcGIS/rest/services/World_Street_Map/MapServer", @"http://services.arcgisonline.com/ArcGIS/rest/services/World_Topo_Map/MapServer"];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.mapView.layerDelegate = self;
	
	[self setBaseLayer:self.baseLayerSegment.selectedSegmentIndex];
    
    AGSEnvelope *envelope = [AGSEnvelope envelopeWithXmin:12178333 ymin:2973103 xmax:13088239 ymax:2255207 spatialReference:[AGSSpatialReference webMercatorSpatialReference]];
    [self.mapView zoomToEnvelope:envelope animated:YES];
	
	NSURL* featureLayerUrl = [NSURL URLWithString:@"http://sampleserver1.arcgisonline.com/ArcGIS/rest/services/Specialty/ESRI_StatesCitiesRivers_USA/MapServer/0"];
	AGSFeatureLayer *featureLayer = [AGSFeatureLayer featureServiceLayerWithURL:featureLayerUrl mode:AGSFeatureLayerModeOnDemand];
	
	AGSSimpleMarkerSymbol* symbol = [AGSSimpleMarkerSymbol simpleMarkerSymbolWithColor:[UIColor redColor]];
	symbol.size = CGSizeMake(10, 10);
	
	featureLayer.renderer = [AGSSimpleRenderer simpleRendererWithSymbol:symbol];
	TestInfoTemplateDelegate *infoTemplateDelegate = [[TestInfoTemplateDelegate alloc] init];
	featureLayer.infoTemplateDelegate = infoTemplateDelegate;
	
	
	[self.mapView addMapLayer:featureLayer withName:@"Test Feature Layer"];
}

- (void) setBaseLayer:(NSInteger)selectedIndex {
	
	for (AGSLayer *layer in self.mapView.mapLayers) {
		if ([layer.name isEqualToString:BASE_Layer_Name]) {
			[self.mapView removeMapLayer:layer];
			break;
		}
	}

	NSString *url = self.baseLayerUrls[selectedIndex];
	NSURL *layerUrl = [NSURL URLWithString:url];
	AGSTiledMapServiceLayer *layer = [AGSTiledMapServiceLayer tiledMapServiceLayerWithURL:layerUrl];

	[self.mapView addMapLayer:layer withName:BASE_Layer_Name];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (UIInterfaceOrientationMask) supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskAll;
}

- (void) mapViewDidLoad:(AGSMapView *)mapView {
	//[self.mapView.locationDisplay startDataSource];
}

- (IBAction)baseLayerSegmentValueChanged:(id)sender {
	NSInteger index = self.baseLayerSegment.selectedSegmentIndex;
	[self setBaseLayer:index];
}

- (NSString*) titleForGraphic:(AGSGraphic *)graphic screenPoint:(CGPoint)screen mapPoint:(AGSPoint *)mapPoint {
	return [graphic attributeAsStringForKey:@"CITY_NAME"];
}
@end
