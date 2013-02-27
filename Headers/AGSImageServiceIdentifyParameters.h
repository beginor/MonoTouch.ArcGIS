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

@protocol AGSCoding;

@class AGSGeometry;
@class AGSMosaicRule;
@class AGSImageServiceIdentifyParameters;

/** @brief Input parameters for the Image Service Identify Task.
 
 Input parameters for an @c AGSImageServiceIdentifyTask.
 @define{AGSImageServiceIdentifyParameters.h, ArcGIS}
 @since 1.8
 */
@interface AGSImageServiceIdentifyParameters : NSObject <AGSCoding>

/** The geometry according to which features should be identified. @c AGSPoint 
 is most commonly used for identifying features at a location, but @c AGSPolygon 
 may also be used for searching within an area.
 @since 1.8
 */
@property (nonatomic, strong) AGSGeometry *geometry;

/** Specifies the mosaic rule defining the image sorting order. When mosaic rule 
 is not specified, mosaic rule will default to AGSMosaicMethodCenter. 
 @since 1.8
 */
@property (nonatomic, strong) AGSMosaicRule *mosaicRule;

/** The pixel level being identified (or the resolution being looked at). If pixel 
 size is not specified, then @p pixelSizeX will default to the x-value of the base 
 resolution of the dataset. The raster at the specified pixel size in the mosaic 
 dataset will be used for identify.
 @since 1.8
 */
@property (nonatomic, assign) double pixelSizeX;

/** The pixel level being identified (or the resolution being looked at). If pixel 
 size is not specified, then @p pixelSizeY will default to the y-value of the base 
 resolution of the dataset. The raster at the specified pixel size in the mosaic 
 dataset will be used for identify.
 @since 1.8
 */
@property (nonatomic, assign) double pixelSizeY;

/** Initialize an autoreleased <code>AGSImageServiceIdentifyParameters</code> object.
 @since 1.8
 */
+(id)imageServiceIdentifyParameters;

@end

