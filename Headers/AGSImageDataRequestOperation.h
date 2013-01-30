/*
 COPYRIGHT 2012 ESRI
 
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


@class AGSRequestOperation;


/** @file AGSImageDataRequestOperation.h */ //Required for Globals API doc

/** @brief An operation to request data for an image from a resource.
 
 Instances of this object represent an operation to obtain the data 
 associated with an image, such as an exported map image, from some 
 specified resource. The only difference between this and @c AGSRequestOperation
 is that it checks that the content type is an image.
 
 @define{AGSImageDataRequestOperation.h, ArcGIS}
 @since 10.1.1
 */
@interface AGSImageDataRequestOperation : AGSRequestOperation

@end
