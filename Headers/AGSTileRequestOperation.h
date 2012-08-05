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
#import <UIKit/UIKit.h>

@class AGSTileOperation;
@class AGSRequestOperation;

/** @brief Requests a tile from a cached map resource.
 
 Instances of this class are used to request tiles from a cached map resource
 @define{AGSTileRequestOperation.h, ArcGIS}
 @since 1.0
 */
@interface AGSTileRequestOperation : AGSRequestOperation <AGSTileOperation> {
@private
	AGSTile *_tile;
    BOOL _noDataError;
}

/** The tile to be retrieved from the cached map resource.
 @since 1.0
 */
@property (nonatomic, retain) AGSTile *tile;

/** Deletes all existing tiles from the tile caches.
 @return Boolean indicating whether files were removed or not.
 @since 2.0
 @deprecated No direct replacement. Cache not managed by ArcGIS iOS SDK. Deprecated at 2.2.
 */
+ (BOOL)deleteAllTileCaches __attribute__((deprecated));

/** Use this function if you want the cache file name for tiles to be based
 on a unique identifier other than the url.
 @param url The URL to initialize the tile with.
 @param filePrefix The prefix used to uniquely identify tiles from different map resources.
 @return An initialized tile request operation.
 @since 1.0
 @deprecated Use initWithURL: instead. Deprecated at 2.2.
 */
- (id)initWithURL:(NSURL *)url layerFilePrefix:(NSString *)filePrefix  __attribute__((deprecated));

@end

