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
@interface AGSPictureFillSymbol : AGSFillSymbol

/** Size in points.
 @since 1.8
 */
@property (nonatomic) CGSize size;

/** Image used as the fill.
 @since 1.8
 */
@property (nonatomic, copy, readonly) AGSImage *image;

/** The rotation angle (in degrees) of the picture. The picture is rotated in a counter-clockwise direction by the amount specified. 
 @since 1.8
 */
@property (nonatomic, assign) double angle;

/** The offset on the x and y axises in points, relative to the center of the image. Default is 0.0.
 For example, an value of (-5, -5) will shift the image left by 5 points along x-asix, down by 5 points along y-axis.
 Similar to a cartesian coordinate system.
 @since 10.1.1
 */
@property (nonatomic, assign) CGPoint offset;

/** Amount to scale the image along x & y axis.
 For example, a value of (2,0.5) will make the image twice as big along the x-axis, but half the original size along y-axis.
 @since 10.1.1
 */
@property (nonatomic, assign) CGSize scale;

/** Initialize symbol with image.
 @param image The image for the fill.
 @since 1.8
 */
- (id)initWithImage:(AGSImage *)image;

/** Initialize autoreleased symbol with image.
 @param image The image for the fill.
 @since 1.8
 */
+ (id)pictureFillSymbolWithImage:(AGSImage *)image;

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

/** Initialize symbol with a path to the image file on the device.
 @param imagePath The path to the image file.
 @since 10.1.1
 */
- (id)initWithContentsOfFile:(NSString *)imagePath;

@end