/*
 COPYRIGHT 2009 ESRI
 
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
#import <pthread.h>

@class AGSSymbol;
@class AGSSimpleLineSymbol;

/** @file AGSMarkerSymbol.h */ //Required for Globals API doc

/** @brief A base class for marker symbols. 
 
 Instances of this class represent marker symbols. Symbols describe how graphics 
 look on the map. Different symbols are used for graphics with different geometry 
 types.  Marker symbols are used to display those graphics which are based on 
 point or multipoint geometry.
 
 @define{AGSMarkerSymbol.h, ArcGIS}
 @since 1.0
 */
@interface AGSMarkerSymbol : AGSSymbol {
@private
    CGFloat _angle;
    CGFloat _xoffset;
    CGFloat _yoffset;  
	CGPoint _hotspot;
    BOOL _rotateAroundOffset;
    CGPoint _rotatedHotspot;
    
    CGLayerRef _layer;
    pthread_mutex_t _layerCreationMutex;
    
    BOOL _shouldCacheSymbol;
}

/** The rotation angle (in degrees) of the marker. The marker is rotated in a counter-clockwise direction by the amount specified. 
 @since 1.0
 */
@property (nonatomic) CGFloat angle;

// @todo : Add image to illustrate

/** The offset on the x-axis in points, relative to the center of the marker. Default is 0.0
 For example, a value of -5 will shift the marker left by 5 points.
 
 This is useful when the marker needs to be offset to properly coincide with a 
 location on the map. 
 
 For example, consider an @c AGSPictureMarkerSymbol using the image of a pushpin.  
 By default, the center of the image will be used as the anchor to center the 
 image at the map location. However, if you wanted the needle of the pushpin to 
 end at the map location, you would need to specify an #xoffset and a #yoffset 
 to shift the image appropriately. 
 
 @since 1.0
 */
@property (nonatomic) CGFloat xoffset;

/** The offset on the y-axis in points, relative to the center of the marker. Default is 0.0
 For example, a value of -5 will shift the marker down by 5 points.
 
 This is useful when the marker needs to be offset to properly conicide with a 
 location on the map. 
 
 For example, consider an @c AGSPictureMarkerSymbol using the  image of a pushpin.  
 By default, the center of the image will be used as the anchor to center the 
 image at the map location. However, if you wanted the needle of the pushpin to 
 end at the map location, you would need to specify an #xoffset and a #yoffset 
 to shift the image appropriately. 
 
 @since 1.0
 */
@property (nonatomic) CGFloat yoffset;

// @todo Add image to illustrate

/** The location in pixels that defines whether a user tapped on this symbol or not.
 
 For example, consider an @c AGSPictureMarkerSymbol using the image of a pushpin. 
 By default, the hotspot would be in the center of the image and so a tap would 
 be registered only if a user tapped in the middle of the pushpin. To allow the 
 user to tap on the head of the pin to show a callout, you would need to specify the corresponding 
 location's hotspot. Furthermore, the callout’s leader will be anchored to this hotspot location.
 
 @since 1.0
 */
@property (nonatomic) CGPoint hotspot;


/** If <code>true</code>, the symbol will rotate around the offset location as opposed
 to the center of the symbol.
 @since 1.8
 */
@property (nonatomic, assign) BOOL rotateAroundOffset;


/** This property determines whether or not the symbol can be cached for better performance.
 Default is YES. Set to NO if you have a symbol that changes often, or if it is a temporary symbol
 that you only use to draw once. For most cases this should be YES.
 @since 2.2
 */
@property (nonatomic, assign) BOOL shouldCacheSymbol;

@end