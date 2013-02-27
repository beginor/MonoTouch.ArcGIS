/*
 COPYRIGHT 2010 ESRI
 
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

@protocol AGSCoding;

@class AGSEnvelope;
@class AGSTimeInfo;

/** @file AGSImageServiceInfo.h */ //Required for Globals API doc

/** @brief Information about an ArcGIS Server image service.
 
 Instances of this class represent information about an ArcGIS Server image service.
 
 @define{AGSImageServiceInfo.h, ArcGIS}
 @since 1.0
 */
@interface AGSImageServiceInfo : NSObject <AGSCoding>

/** The image service description.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *serviceDescription;

/** The name of raster image or data.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *name;

/** The extent of the image service.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSEnvelope *extent;

/** The pixel size along X-axis.
 @since 1.0
 */
@property (nonatomic, assign, readonly) double pixelSizeX;

/** The pixel size along Y-axis.
 @since 1.0
 */
@property (nonatomic, assign, readonly) double pixelSizeY;

/** The number of bands in the image service.
 @since 1.0
 */
@property (nonatomic, assign, readonly) NSInteger bandCount;

/** The type of data at each pixel.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *pixelType;

/** The minimum pixel size.
 @since 1.0
 */
@property (nonatomic, assign, readonly) double minPixelSize;

/** The maximum pixel size.
 @since 1.0
 */
@property (nonatomic, assign, readonly) double maxPixelSize;

/** Copyright text of the image service.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *copyrightText;

/** The data type of the image service.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *serviceDataType;

/** Minumum value in each image band.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *minValues;

/** Maximum value in each image band.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *maxValues;

/** Mean value in each image band.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *meanValues;

/** Standard deviation value in each image band.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *stdvValues;

/** The version of ArcGIS Server the image service is published to, e.g. 9.3, 
 9.3.1, 10.
 @since 1.8
 */
@property (nonatomic, readonly) float version;

/** Temporal information for the layer, such as time extent. If this property is
 null or not specified, then the layer does not support time-related operations.
 @since 1.8
 */
@property (nonatomic, strong, readonly) AGSTimeInfo *timeInfo;

/** The name of the object ID field.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *objectIdField;

/** The fields of the image service as specified in the Service Directory.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *fields;



@end







