//
//  MainViewController.h
//  AGSTest
//
//  Created by zhangzhimin on 7/24/13.
//  Copyright (c) 2013 gdeic. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ArcGIS/ArcGIS.h>

@interface MainViewController : UIViewController <AGSMapViewLayerDelegate>

@property (weak, nonatomic) IBOutlet AGSMapView *mapView;

@end
