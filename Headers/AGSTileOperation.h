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

@class AGSTile;

/** @brief A protocol that must be adopted by operations that retrieve tiles.
 
 A protocol that must be adopted by operations that retrieve tiles.
 This protocol allows one to retrieve specific tile information from an operation.
 
 @define{AGSTileOperation.h, ArcGIS}
 @since 1.0
 */

@protocol AGSTileOperation <NSObject>

/** Property holding information about a specific tile
 @since 1.0
 */
@property (nonatomic, retain) AGSTile *tile;

@end

//Excluding from API ref doc
//## @cond
@protocol AGSBatchTileOperation <NSObject>

@property (nonatomic, retain) NSArray *tiles;

@end
//## @endcond
