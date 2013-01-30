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

/** @file AGSMapServiceTableInfo.h */ //Required for Globals API doc

/** @brief Information about a table in an ArcGIS Server service

 Instances of this class represent information about a non-spatial table in an ArcGIS Server map or feature service.
 
 @since 1.8
 */
@interface AGSMapServiceTableInfo : NSObject <AGSCoding>

/** The id of the table.
 @since 1.8
 */
@property (nonatomic, assign, readonly) NSUInteger tableId;

/**
 The name of the table.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *name;

@end
