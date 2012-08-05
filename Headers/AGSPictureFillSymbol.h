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
@class AGSFillSymbol;
@class AGSSimpleLineSymbol;

/** @file AGSPictureFillSymbol.h */ //Required for Globals API doc

/** @brief A fill symbol based on an image
 
 Instances of this class represent picture fill symbols. Symbols describe how 
 graphics look on the map. Different symbols are used for graphics with different 
 geometry types. Fill symbols are used to display those graphics which are based 
 on a polygon geometry. The symbol can fill the interior of a polygon graphic
 by repeating a given picture. In addition, the symbol can have 
 an optional outline which is defined by a line symbol.
 
 @define{AGSPictureFillSymbol.h, ArcGIS}
 @since 1.8
 */
@interface AGSPictureFillSymbol : AGSFillSymbol {
 @private
    CGSize _size;
    NSString *_imageName;
    UIImage *_image;
	float _angle;
	float _xoffset;
	float _yoffset;
	float _xscale;
	float _yscale;
}

/** Size in pixels. Default is 12x12.
 @since 1.8
 */
@property (nonatomic) CGSize size;

/** Name of the image to be used as the fill.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *imageName;

/** Image used as the fill.
 @since 1.8
 */
@property (nonatomic, retain, readonly) UIImage *image;

/** The rotation angle (in degrees) of the picture. The picture is rotated in a counter-clockwise direction by the amount specified. 
 @since 1.8
 */
@property (nonatomic, assign) float angle;

/** The offset on the x-axis in points, relative to the center of the image. Default is 0.0.
 For example, a value of -5 will shift the image left by 5 points.
 @since 1.8
 */
@property (nonatomic, assign) float xoffset;

/** The offset on the y-axis in points, relative to the center of the image. Default is 0.0.
 For example, a value of -5 will shift the image down by 5 points.
 @since 1.8
 */
@property (nonatomic, assign) float yoffset;

/** Amount to scale the image along x-axis
 @since 1.8
 */
@property (nonatomic, assign) float xscale;

/** Amount to scale the image along y-axis
 @since 1.8
 */
@property (nonatomic, assign) float yscale;

/** Initialize symbol with image.
 @param image The image for the fill.
 @since 1.8
 */
- (id)initWithImage:(UIImage *)image;

/** Initialize autoreleased symbol with image.
 @param image The image for the fill.
 @since 1.8
 */
+ (id)pictureFillSymbolWithImage:(UIImage *)image;

/** Initialize symbol with name of image to draw in the fill.
 @param imageName The name of the image to draw in the fill.
 @since 1.8
 */
- (id)initWithImageNamed:(NSString *)imageName;

/** Initialize autoreleased symbol with name of image to draw.
 @param imageName The name of the image to draw in the fill.
 @since 1.8
 */
+ (id)pictureFillSymbolWithImageNamed:(NSString *)imageName;

@end