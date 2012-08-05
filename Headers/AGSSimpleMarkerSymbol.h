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
#import <pthread.h>

@class AGSSymbol;
@class AGSSimpleLineSymbol;

/** @file AGSSimpleMarkerSymbol.h */ //Required for Globals API doc

#pragma mark -

/** Supported marker styles.
 @since 1.0
 */
typedef enum {
    AGSSimpleMarkerSymbolStyleCircle = 0,	/*!< */
    AGSSimpleMarkerSymbolStyleCross,		/*!< */
    AGSSimpleMarkerSymbolStyleDiamond,		/*!< */			
    AGSSimpleMarkerSymbolStyleSquare,		/*!< */
    AGSSimpleMarkerSymbolStyleX				/*!< */
} AGSSimpleMarkerSymbolStyle;



#pragma mark -

/** @brief A marker symbol based on simple shapes.
 
 Instances of this class represent simple marker symbols. Symbols describe how 
 graphics look on the map. Different symbols are used for graphics with different 
 geometry types. Marker symbols are used to display those graphics which are 
 based on point or multipoint geometry. Simple marker symbols display graphics 
 using simple, predefined markers such as circle, cross, etc. In addition, the 
 markers can have an optional outline, which is defined by a line symbol.
 
 @define{AGSMarkerSymbol.h, ArcGIS}
 @since 1.0
 */
@interface AGSSimpleMarkerSymbol : AGSMarkerSymbol {
 @private
    AGSSimpleMarkerSymbolStyle _style;
    AGSSimpleLineSymbol *_outline;
    CGFloat _size;
}

/** Size of the marker.
 @since 1.0
 */
@property (nonatomic, assign) CGFloat size;

/** The marker style. Possible values include 
 
 @li @c AGSSimpleMarkerSymbolStyleCircle
 @li @c AGSSimpleMarkerSymbolStyleCross
 @li @c AGSSimpleMarkerSymbolStyleDiamond
 @li @c AGSSimpleMarkerSymbolStyleSquare
 @li @c AGSSimpleMarkerSymbolStyleX
 
 Default is AGSSimpleMarkerSymbolStyleCircle.
 @since 1.0
 */
@property (nonatomic) AGSSimpleMarkerSymbolStyle style;

/** Outline of the marker.
 @since 1.0
 */
@property (nonatomic, retain) AGSSimpleLineSymbol *outline;

/** Get autoreleased symbol initialized with default values.
 @return A new, autoreleased, marker symbol object.
 @since 1.0
 */
+ (id)simpleMarkerSymbol;

/** Initializes with a color.
 @param color The color to initialize the marker symbol with.
 @since 1.0
 */
-(id)initWithColor:(UIColor*)color;

/** Get autoreleased simple marker symbol with a color.
 @param color The color to initialize the marker symbol with.
 @since 1.0
 */
+(id)simpleMarkerSymbolWithColor:(UIColor*)color;

@end
