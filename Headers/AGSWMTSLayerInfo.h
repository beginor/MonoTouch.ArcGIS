/*
 COPYRIGHT 2012 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and 
 Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */



@class AGSWMTSStyle;

/** @file AGSWMTSLayerInfo.h */ //Required for Globals API doc

/** @brief The information for a layer based on a WMTS Server map service.
 
 An instance of this class provides information on a layer availiable
 from a WMTS map service.
 @define {AGSWMTSLayerInfo.h, ArcGIS}
 @since 10.1.1
*/

@interface AGSWMTSLayerInfo : NSObject

/** The title of the layer.
 @since 10.1.1
*/
@property (nonatomic, copy, readonly) NSString *title;

/** The supported imageFormats of the layer.  Possible values contained in the set are
// @li @c AGSImageFormatPNG32
// @li @c AGSImageFormatPNG24
// @li @c AGSImageFormatPNG8
// @li @c AGSImageFormatPNG
// @li @c AGSImageFormatJPG
// @li @c AGSImageFormatGIF
// @li @c AGSImageFormatPNGJPG
@since 10.1.1
*/
@property (nonatomic, copy, readonly) NSSet *imageFormats;

/** A String representing the Tiling scheme for the layer.
 @since 10.1.1
 */
@property (nonatomic, copy) NSString *tileMatrixSet;

/** An array of strings representing Tiling scheme options for the layer.
@since 10.1.1
*/
@property(nonatomic, copy, readonly) NSArray *tileMatrixSetIds;

/** Style for the layer, must be a supported style.
 @since 10.1.1
 */
@property (nonatomic, strong) AGSWMTSStyle *style;

/** An array of supported @c AGSWMTSStyle objects representing style options for the layer.
@since 10.1.1
 */
@property (nonatomic, copy, readonly) NSArray *styles;

@end
