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

@class AGSRenderer;
@class AGSSymbol;

/** @file AGSSimpleRenderer.h */ //Required for Globals API doc

#pragma mark -


/** @brief A simple renderer.
 
 Instances of this class represent simple renderers. Renderers symbolize all 
 graphics in a graphics layer according to a given scheme. This is easier than 
 symbolizing each graphic individually.
 
 Simple renderers use a simple scheme - the same symbol is used for all graphics.
 
 @define{AGSSimpleRenderer.h, ArcGIS}
 @since 1.0
 */
@interface AGSSimpleRenderer : AGSRenderer {
 @private
    AGSSymbol *_symbol;
	NSString *_label;
	NSString *_description;
}

/** The symbol for the renderer.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSSymbol *symbol;

/** The label for the renderer.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSString *label;

/** The description for the renderer.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSString *description;

/** Initialize renderer with desired symbol.
 @param symbol The symbol to be used to render all graphics.
 @return A new simple renderer object.
 @since 1.0
 */
- (id)initWithSymbol:(AGSSymbol *)symbol;

/** Initialize autoreleased renderer with desired symbol.
 @param symbol The symbol to be used to render all graphics.
 @return A new, autoreleased, simple renderer object.
 @since 1.0
 */
+ (id)simpleRendererWithSymbol:(AGSSymbol *)symbol;

@end
