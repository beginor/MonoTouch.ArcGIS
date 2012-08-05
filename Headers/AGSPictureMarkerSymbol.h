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
@class AGSSymbol;
@class AGSMarkerSymbol;

/** @file AGSPictureMarkerSymbol.h */ //Required for Globals API doc

/** @brief A marker symbol based on an image
 
 Instances of this class represent picture marker symbols. Symbols describe how 
 graphics look on the map. Different symbols are used for graphics with different 
 geometry types.  Marker symbols are used to display those graphics which are 
 based on point or multipoint geometry. Picture marker symbols display graphics 
 using a picture image.
 
 @define{AGSMarkerSymbol.h, ArcGIS}
 @since 1.0
 */
@interface AGSPictureMarkerSymbol : AGSMarkerSymbol {
 @private
    NSString *_imageName;
    UIImage *_image;
    CGSize _size;
    AGSImageRequestOperation *_imageRequestOp;
    NSError *_error;
}

/** The size of the symbol.
 @since 1.0
 */
@property (nonatomic, assign) CGSize size;

/** Name of the image to be used as the marker.
 @since 1.0
 */
@property (nonatomic, copy) NSString *imageName;

/** Image used as the marker.
 @since 1.0
 */
@property (nonatomic, retain, readonly) UIImage *image;

/** Contains the error that occurred (if any) when this picture marker symbol
 requests an image from a URL.
 @since 2.2
 */
@property (nonatomic, retain, readonly) NSError *error;

/** Initialize symbol with marker image.
 @param image The image for the marker.
 @since 1.0
 */
- (id)initWithImage:(UIImage *)image;

/** Initialize autoreleased symbol with marker image.
 @param image The image for the marker.
 @since 1.0
 */
+ (id)pictureMarkerSymbolWithImage:(UIImage *)image;

/** Initialize symbol with name of image to draw marker.
 @param imageName The name of the image to draw the marker.
 @since 1.0
 */
- (id)initWithImageNamed:(NSString *)imageName;

/** Initialize autoreleased symbol with name of image to draw marker.
 @param imageName The name of the image to draw the marker.
 @since 1.0
 */
+ (id)pictureMarkerSymbolWithImageNamed:(NSString *)imageName;

@end