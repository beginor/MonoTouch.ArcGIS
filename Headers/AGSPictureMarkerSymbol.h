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

@class AGSMarkerSymbol;

/** @file AGSPictureMarkerSymbol.h */ //Required for Globals API doc

/** @brief A marker symbol based on an image
 
 Instances of this class represent picture marker symbols. Symbols describe how 
 graphics look on the map. Different symbols are used for graphics with different 
 geometry types.  Marker symbols are used to display those graphics which are 
 based on point or multipoint geometry. Picture marker symbols display graphics 
 using a picture image.
 
 @define{AGSPictureMarkerSymbol.h, ArcGIS}
 @since 1.0
 */
@interface AGSPictureMarkerSymbol : AGSMarkerSymbol

/** Image used as the marker.
 @since 1.0
 */
@property (nonatomic, copy) AGSImage *image;

/** Contains the error that occurred (if any) when this picture marker symbol
 requests an image from a URL.
 @since 2.2
 */
@property (nonatomic, strong, readonly) NSError *error;

/** Changes the image of this symbol using the image data provided
 @param data of the new image for the symbol
 @since 10.1.1
 */
- (void)setImageWithData:(NSData*)data;

/** Changes the image of this symbol using the image specified by name
 @param name of the new image for the symbol
 @since 10.1.1
 */
- (void)setImageWithName:(NSString*)name;

/** Changes the image of this symbol using the image specified by the file path
 @param path to the new image for the symbol
 @since 10.1.1
 */
- (void)setImageWithContentsOfFile:(NSString*)path;

/** Initialize symbol with marker image.
 @param image The image for the marker.
 @since 1.0
 */
- (id)initWithImage:(AGSImage *)image;

/** Initialize autoreleased symbol with marker image.
 @param image The image for the marker.
 @since 1.0
 */
+ (id)pictureMarkerSymbolWithImage:(AGSImage *)image;

/** Initialize symbol with name of image to draw marker.
 @param imageName The name of the image to draw the marker.
 @since 1.0
 */
- (id)initWithImageNamed:(NSString *)imageName;

/** Initialize symbol with a path to the image file on the device.
 @param imagePath The path to the image file.
 @since 10.1.1
 */
- (id)initWithContentsOfFile:(NSString *)imagePath;

/** Initialize autoreleased symbol with name of image to draw marker.
 @param imageName The name of the image to draw the marker.
 @since 1.0
 */
+ (id)pictureMarkerSymbolWithImageNamed:(NSString *)imageName;

@end