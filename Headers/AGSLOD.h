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

/** @file AGSLOD.h */ //Required for Globals API doc

/** @brief A scale level of a cached map service.
 
 A cached map service has a number of predefined scale levels (Levels of Detail). 
 <code>%AGSLOD</code> corresponds to a given scale level.
 @define{AGSLOD.h, ArcGIS}
 @since 1.0
 */
@interface AGSLOD : NSObject <AGSCoding> {}

/** ID for the scale level. The top most level is 0. This level represents the 
 finest level of detail.
 @since 1.0
 */
@property (nonatomic, readonly) NSUInteger level;

/** Resolution, in map units, of each pixel in a tile for the scale level.
 @since 1.0
 @see @c AGSTiledLayer#convertedResolutionForLodResolution: to convert LOD resolution to map resolution.
 @see @c AGSMapView#zoomToResolution:animated:
 */
@property (nonatomic, readonly) double resolution;

/** Scale for the level.
 @since 1.0
 @see @c AGSTiledLayer#convertedScaleForLodScale: to convert LOD scale to map scale.
 @see @c AGSMapView#zoomToScale:animated:
 */
@property (nonatomic, readonly) double scale;

/** Starting row index for a tile in the scale level.
 @since 1.0
 */
@property (nonatomic) NSUInteger startTileRow;

/** Ending row index for a tile in the scale level.
 @since 1.0
 */
@property (nonatomic) NSUInteger endTileRow;

/** Starting column index for a tile in the scale level.
 @since 1.0
 */
@property (nonatomic) NSUInteger startTileColumn;

/** Ending column index for a tile in the scale level.
 @since 1.0
 */
@property (nonatomic) NSUInteger endTileColumn;

/** Initializes an <code>%AGSLOD</code> object.
 @param level The level that represents desired level of detail.
 @param resolution The resolution of the desired @p level.
 @param scale The scale of the desired @p level.
 @return A new <code>%AGSLOD</code> object.
 @since 1.0
 */
- (id)initWithLevel: (NSUInteger)level
		 resolution: (double) resolution
			  scale: (double) scale;

@end
