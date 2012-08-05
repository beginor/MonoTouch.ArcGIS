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

@class AGSCoding;
@class AGSGeometry;
@class AGSEnvelope;
@class AGSPoint;
@class AGSGraphic;

/** @file AGSSymbol.h */ //Required for Globals API doc

#pragma mark -

/** @brief A symbol used to display a graphic.
 
 A base class to represent symbols.  Symbols describe how graphics look on the map. 
 Different symbols are used for graphics with different geometry types. Marker 
 symbols are used for point and multipoint graphics, Fill symbols are used for 
 polygon graphics, and Line symbols are used for polyline graphics.
 
 @define{AGSSymbol.h, ArcGIS}
 @since 1.0
 */
@interface AGSSymbol : NSObject <AGSCoding, NSCopying> {
 @private
    UIColor *_color;
    BOOL _readyToDraw;
	/*
	CGContextRef _hitTestBitmapContext;
	uint8_t _byte[8];
	 */
}

/** Symbol color.
 @since 1.0
 */
@property (nonatomic, retain) UIColor *color;

/** Returns an image that represents a swatch for a particular geometry type.
 @param geometryType The type of the geometry determines what kind of swatch is drawn.
 @param size Size of the output swatch.
 @return UIImage of the drawn swatch.
 */
- (UIImage *)swatchForGeometryType:(AGSGeometryType)geometryType size:(CGSize)size;

@end

/** Return an <code>AGSSymbol</code> from JSON representation.
 @param json The JSON representation of the symbol.
 @since 1.0
 */
extern AGSSymbol *AGSSymbolWithJSON(NSDictionary *json);
