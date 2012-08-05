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
#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>


@protocol AGSTiledLayerTileDelegate;
@class AGSLayer;
@class AGSTileInfo;
@class AGSTileRequestOperation;
@class AGSTile;
@protocol AGSTileOperation;
@protocol AGSBatchTileOperation;

/** @file AGSTiledLayer.h */ //Required for Globals API doc

#pragma mark -

/**  @brief A base class for tiled layers.

 A base class for layers which displays cached maps. You would typically work 
 with one or more sub-classes of this class, for instance, @c AGSTiledMapServiceLayer.
 
 In a Model-View-Controller architecture, this object represents the Model. The 
 corresponding View object, @c AGSTiledLayerView, is created when subclasses, for 
 instance @c AGSTiledMapServiceLayer, are added to the map.
 
 @define{AGSTiledLayer.h,ArcGIS}
 @since 1.0
 */
@interface AGSTiledLayer : AGSLayer {
 @private
    id<AGSTiledLayerTileDelegate> _tileDelegate;
    NSOperationQueue *_operationQueue;
}

/** Delegate to be notified when a tile is retrieved asynchronously. When this 
 layer is loaded, a corresponding View object is automatically set as the 
 @p tileDelegate which should not be replaced.
 @since 1.0
 */
@property (nonatomic, assign) id<AGSTiledLayerTileDelegate> tileDelegate;

/** Operation queue used by tiled layer to make asynchronous requests.
 Default operation queue size is 4. 
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSOperationQueue *operationQueue;

/** Tiling scheme for the layer. This property must be implemented by subclasses.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSTileInfo *tileInfo;

/** Retrieve tile asynchronously. This method must be implemented by subclasses.
 @param tile The tile to get image for.
 @return <code>NSOperation</code> that implements the protocol <code>AGSTileOperation</code> 
 for current tile request.
 @since 1.0
 @see AGSTiledLayerTileDelegate
 */
- (NSOperation<AGSTileOperation>*)retrieveImageAsyncForTile:(AGSTile*)tile;

@end

#pragma mark -

/** @brief A tileDelegate of @c AGSTiledLayer.

 A protocol which must be adopted by a class wishing to be notified when 
 @c AGSTiledLayer retrieves a tile asynchronously. An instance of the class must 
 then be set as the tileDelegate of @c AGSTiledLayer.
 
 @define{AGSTiledLayer.h, ArcGIS}
 @since 1.0
 */
@protocol AGSTiledLayerTileDelegate <NSObject>

@required
/** Tells the delegate a tile was successfully retrieved.
 @param layer The layer retrieving the tile.
 @param op The operation that retrieved the tile.
 @since 1.0
 */
- (void)tiledLayer:(AGSTiledLayer *)layer operationDidGetTile:(NSOperation<AGSTileOperation>*)op;

@optional
/** Tells the delegate a tile was not retrieved.
 @param layer The layer retrieving the tile.
 @param op The operation that failed to retrieve tile.
 @since 1.0
 */
- (void)tiledLayer:(AGSTiledLayer *)layer operationDidFailToGetTile:(NSOperation<AGSTileOperation>*)op;


-(void)tiledLayer:(AGSTiledLayer*)layer operationDidGetTileBatch:(NSOperation<AGSBatchTileOperation>*)op;
-(void)tiledLayer:(AGSTiledLayer*)layer operationDidFailToGetTileBatch:(NSOperation<AGSBatchTileOperation>*)op;

@end

#pragma mark -

/** A protocol that a tiled layer can implement if it supports getting multiple tiles quickly at once.
 This is useful local layers that are so fast at retrieving the tiles that it doesn't make sense
 to kick off multiple operations when multiple tiles are needed.
 @since 2.0
 */
@protocol AGSLocalTiledLayerDataSource
@required
-(NSOperation<AGSBatchTileOperation>*)retrieveImagesForTiles:(NSArray*)tiles;
@end

