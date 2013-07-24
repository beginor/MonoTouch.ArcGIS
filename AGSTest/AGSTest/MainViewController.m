//
//  MainViewController.m
//  AGSTest
//
//  Created by zhangzhimin on 7/24/13.
//  Copyright (c) 2013 gdeic. All rights reserved.
//

#import "MainViewController.h"

@interface MainViewController ()

@end

@implementation MainViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.mapView.layerDelegate = self;
	
	NSURL *url = [NSURL URLWithString:@"http://agserver.gdepb.gov.cn/arcgis/rest/services/BaseMap/MRoad/MapServer"];
    AGSTiledMapServiceLayer *layer = [AGSTiledMapServiceLayer tiledMapServiceLayerWithURL:url];
    
    [self.mapView addMapLayer:layer withName:@"TiledLayer"];
    
    AGSEnvelope *envelope = [AGSEnvelope envelopeWithXmin:12178333 ymin:2973103 xmax:13088239 ymax:2255207 spatialReference:[AGSSpatialReference webMercatorSpatialReference]];
    [self.mapView zoomToEnvelope:envelope animated:YES];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    //self supportedInterfaceOrientations
}

- (UIInterfaceOrientationMask) supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskAll;
}

- (void) mapViewDidLoad:(AGSMapView *)mapView {
	//[self.mapView.locationDisplay startDataSource];
}
@end
