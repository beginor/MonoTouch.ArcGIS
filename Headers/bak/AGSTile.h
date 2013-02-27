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

/** @file AGSTile.h */ //Required for Globals API doc

/** @brief An object representing a single cached tile of a cached map.
 
 Instances of this class represent a single cached tile of the cached map. The 
 tile contains a #level, #row, and #column that represent some distinct location
 within the map. The tile also contains the image for the specified location within
 the cached map.
 
 @define{AGSTile.h, ArcGIS}
 @since 1.0
 */
@interface AGSTile : NSObject {
@private
	int _level;
	int _row;
	int _column;
	NSString *_name;
	UIImage *_image;
	NSError *_error;
	AGSEnvelope *_envelope;
	CGRect _frame;
	BOOL _isNeededToCoverBG;
}

/** The level of detail of the specified tile. 
 @since 1.0
 */
@property (nonatomic, assign) int level;

/** The row at which the tile represents.
 @since 1.0
 */
@property (nonatomic, assign) int row;

/** The column at which the tile represents.
 @since 1.0
 */
@property (nonatomic, assign) int column;

/** The image associated with the tile at the given #level, #row, and #column.
 @since 1.0
 */
@property (nonatomic, retain) UIImage *image;

/** Represents the frame of the tile in map units.
 @since 1.0
 */
@property (nonatomic, retain) AGSEnvelope *envelope;

/** Represents the frame of the tile in screen units.
 @since 1.0
 */
@property (nonatomic, assign) CGRect frame;

/** The error associated with the tile's retrieval.
 @since 1.0
 */
@property (nonatomic, retain) NSError *error;

/** The name for the tile in the format "level/row/column".
 @since 1.0
 */
@property (nonatomic, retain) NSString *name;

/** Initializes a tile with the specified @p level, @p row, @p column, @p envelope,
 and @p frame.
 @param level The level in which this tile is from.
 @param row The row in which this tile represents.
 @param column The column in which this tile represents.
 @param envelope The envelope of the tile in map units.
 @param frame The frame of the tile in screen units.
 @param name The unique name of the tile.
 @return An initialized <code>%AGSTile</code> object.
 @since 1.8
 */
-(id)initWithLevel:(int)level row:(int)row column:(int)column envelope:(AGSEnvelope*)envelope frame:(CGRect)frame name:(NSString*)name;

/** Initializes a tile with the specified @p level, @p row, @p column, @p envelope,
 and @p frame.
 @param level The level in which this tile is from.
 @param row The row in which this tile represents.
 @param column The column in which this tile represents.
 @param envelope The envelope of the tile in map units.
 @param frame The frame of the tile in screen units.
 @param name The unique name of the tile.
 @return A new, autoreleased, <code>%AGSTile</code> object.
 @since 1.8
 */
+(id)tileWithLevel:(int)level row:(int)row column:(int)column envelope:(AGSEnvelope*)envelope frame:(CGRect)frame name:(NSString*)name;

/** Returns the name for the tile.
 @param level The level at which the tile is located.
 @param row The row at which the tile is located.
 @param column The column at which the tile is located.
 @return The name of the tile given the @p level, @p row, and @p column.
 @since 1.0
 */
+(NSString *)nameForLayerAtLevel:(int)level row:(int)row column:(int)column;

@end
