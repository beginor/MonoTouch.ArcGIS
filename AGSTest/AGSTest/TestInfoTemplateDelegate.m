//
//  TestInfoTemplateDelegate.m
//  AGSTest
//
//  Created by gdeic on 8/6/13.
//  Copyright (c) 2013 gdeic. All rights reserved.
//

#import "TestInfoTemplateDelegate.h"

@implementation TestInfoTemplateDelegate

- (NSString *) titleForGraphic:(AGSGraphic *)graphic screenPoint:(CGPoint)screen mapPoint:(AGSPoint *)mapPoint {
	NSString *title = [graphic attributeAsStringForKey:@"CITY_NAME"];
	return title;
}

- (NSString *) detailForGraphic:(AGSGraphic *)graphic screenPoint:(CGPoint)screen mapPoint:(AGSPoint *)mapPoint {
	NSString *detail = [graphic attributeAsStringForKey:@"CITY_NAME"];
	return detail;
}
@end
