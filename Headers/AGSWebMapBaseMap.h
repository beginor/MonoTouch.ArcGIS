/*
 COPYRIGHT 2011 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */

#import <Foundation/Foundation.h>

/** @file AGSWebMapBaseMap.h */ //Required for Globals API doc

/** @brief The basemap layer(s) of a webmap.
 
 Instances of this class represent the basemap layer(s) of a webmap.
 @since 2.2
 */

@interface AGSWebMapBaseMap : NSObject <AGSCoding> {
@private
	NSString *_title;
	NSArray *_baseMapLayers;
}

/** The title of the basemap layer(s)
 @since 2.2
 */
@property (nonatomic, retain, readonly) NSString *title;

/**
 An array of @c AGSWebMapLayerInfo objects representing the basemap layer(s) of a webmap.
 @since 2.2
 */
@property (nonatomic, retain, readonly) NSArray *baseMapLayers;

@end
