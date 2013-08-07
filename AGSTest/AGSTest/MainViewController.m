//
//  MainViewController.m
//  AGSTest
//
//  Created by zhangzhimin on 7/24/13.
//  Copyright (c) 2013 gdeic. All rights reserved.
//

#import "MainViewController.h"
#import "TestInfoTemplateDelegate.h"

#define BASE_LAYER_NAME @"Base Map Layer"
#define FEATURE_LAYER_NAME @"Feature Layer"

@interface MainViewController ()

@property NSArray *baseLayerUrls;

@property NSArray *featureLayerUrls;

@end

@implementation MainViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
		 self.baseLayerUrls = @[@"http://services.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer", @"http://services.arcgisonline.com/ArcGIS/rest/services/World_Street_Map/MapServer", @"http://services.arcgisonline.com/ArcGIS/rest/services/World_Topo_Map/MapServer"];
		 
		 self.featureLayerUrls = @[@"http://sampleserver1.arcgisonline.com/ArcGIS/rest/services/Specialty/ESRI_StatesCitiesRivers_USA/MapServer/0"];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.mapView.layerDelegate = self;
	
	[self setBaseLayer:self.baseLayerSegment.selectedSegmentIndex];
    
    AGSEnvelope *envelope = [AGSEnvelope envelopeWithXmin:-20459599 ymin:2391609 xmax:-6833470 ymax:11289636 spatialReference:[AGSSpatialReference webMercatorSpatialReference]];
    [self.mapView zoomToEnvelope:envelope animated:YES];
}

- (void) setBaseLayer:(NSInteger)selectedIndex {
	
	[self.mapView removeMapLayerWithName:BASE_LAYER_NAME];

	if (selectedIndex < [self.baseLayerUrls count]) {
		NSString *url = self.baseLayerUrls[selectedIndex];
		NSURL *layerUrl = [NSURL URLWithString:url];
		AGSTiledMapServiceLayer *layer = [AGSTiledMapServiceLayer tiledMapServiceLayerWithURL:layerUrl];

		[self.mapView insertMapLayer:layer withName:BASE_LAYER_NAME atIndex:0];
	}
}

- (void)setPointFeatureLayer:(NSInteger)layerUrlIndex {
    NSURL *featureLayerUrl = [NSURL URLWithString:self.featureLayerUrls[layerUrlIndex]];
    AGSFeatureLayer *featureLayer = [AGSFeatureLayer featureServiceLayerWithURL:featureLayerUrl mode:AGSFeatureLayerModeSnapshot];
	
    AGSSimpleMarkerSymbol *symbol = [AGSSimpleMarkerSymbol simpleMarkerSymbolWithColor:[UIColor redColor]];
    symbol.size = CGSizeMake(30, 30);

    featureLayer.renderer = [AGSSimpleRenderer simpleRendererWithSymbol:symbol];
	
	featureLayer.outFields = @[@"*"];
    TestInfoTemplateDelegate *infoTemplateDelegate = [[TestInfoTemplateDelegate alloc] init];
    featureLayer.infoTemplateDelegate = infoTemplateDelegate;
	
	//AGSCalloutTemplate *template = [[AGSCalloutTemplate alloc] init];
	//template.titleTemplate = @"${CITY_NAME}";
	//template.detailTemplate = @"${POP1990}";
	//featureLayer.infoTemplateDelegate = template;
	//featureLayer.queryDelegate = nil;
	AGSQuery *query = [[AGSQuery alloc] init];
	query.where = @"POP1990 > 1000000";
	
	//[[featureLayer queryFeatures:query] start];
	
    [self.mapView insertMapLayer:featureLayer withName:FEATURE_LAYER_NAME atIndex:1];
}

- (void) setFeatureLayer:(NSInteger)selectedIndex {
	[self.mapView removeMapLayerWithName:FEATURE_LAYER_NAME];

	if (selectedIndex < [self.featureLayerUrls count]) {
		if (selectedIndex == 0) {
            [self setPointFeatureLayer:selectedIndex];
		}
	}
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

- (IBAction)featureLayerSegmentValueChanged:(id)sender {
	NSInteger selectedIndex = self.featureLayerSegment.selectedSegmentIndex;
	[self setFeatureLayer:selectedIndex];
}

@end
