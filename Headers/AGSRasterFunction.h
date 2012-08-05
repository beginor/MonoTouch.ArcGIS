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

#import <Foundation/Foundation.h>

/** @file AGSRasterFunction.h */

/** Supported raster function types. These types correspond to the names of
 raster functions.
 @since 1.8
 */
typedef enum {
	AGSRasterFunctionTypeAspect = 0,		/*!<  */
	AGSRasterFunctionTypeColormap,			/*!<  */
	AGSRasterFunctionTypeHillshade,			/*!<  */
	AGSRasterFunctionTypeNDVI,				/*!<  */
	AGSRasterFunctionTypeShadedRelief,		/*!<  */
	AGSRasterFunctionTypeSlope,				/*!<  */
	AGSRasterFunctionTypeStatistics,		/*!<  */
	AGSRasterFunctionTypeStretch,			/*!<  */
} AGSRasterFunctionType;

/** @brief The rendering rule to be used for an image service's export image
 operation.
 
 Specifies the processing to be done to the image service.
 @define{AGSRasterFunction.h, ArcGIS}
 @since 1.8
 */
@interface AGSRasterFunction : NSObject <AGSCoding> {
 @private
	AGSRasterFunctionType _type;
	NSMutableDictionary *_arguments;
}

/** The raster function type.
 @since 1.8
 */
@property (nonatomic, assign) AGSRasterFunctionType type;

/** The input arguments to the raster function, in the form of an NSDictionary.
 The dictionary must be based on the JSON syntax of the arguments. Refer to the
 <a href="http://help.arcgis.com/en/arcgisserver/10.0/apis/rest/index.html?israsterfunctions.html">REST API</a> 
 for the JSON syntax.
 @since 1.8
 */
@property (nonatomic, retain) NSMutableDictionary *arguments;
	
@end
