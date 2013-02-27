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

@class AGSSymbol;
@class AGSGraphic;
@class AGSGraphicsLayer;
@class AGSRenderer;
@class AGSTimeExtent;

/** @file AGSRenderer.h */ //Required for Globals API doc

/** Create an <code>%AGSRenderer</code> object from JSON representation
 @param json The JSON representation of the renderer to create.
 @since 1.0
 */
extern AGSRenderer *AGSRendererWithJSON(NSDictionary *json);

#pragma mark -

/** @brief A base class for renderers.
 
 Instances of this class represent renderers. Renderers symbolize all graphics in 
 a graphics layer according to a given scheme. This is easier than symbolizing 
 each graphic individually.
 
 @define{AGSRenderer.h, ArcGIS}
 @since 1.0
 */
@interface AGSRenderer : NSObject <AGSCoding, NSCopying>

/** The graphics layer that this renderer belongs to, if any.
 @since 2.2
 */
@property (nonatomic, weak, readonly) AGSGraphicsLayer *layer;

/** Return a symbol for the graphic based on the scheme used by this renderer.
 @param graphic The graphic to determine symbol.
 @param timeExtent The time extent to determine the symbol at.
 @return Symbol for graphic.
 @since 1.8
 */
-(AGSSymbol*)symbolForGraphic:(AGSGraphic*)graphic timeExtent:(AGSTimeExtent*)timeExtent;

/** Returns an image that represents a swatch for a particular graphic. The graphic must have a valid geometry.
 @param graphic Graphic for which the swatch should be drawn. This is used to determine what symbol in the renderer is used.
 @param size Size of the output swatch.
 @return AGSImage of the drawn swatch.
 */
- (AGSImage *)swatchForGraphic:(AGSGraphic *)graphic size:(CGSize)size;

/** Returns an image that represents a swatch for a particular graphic. This method can be used when your graphic does not have a geometry
 but you know the geometry type.
 @param graphic Graphic for which the swatch should be drawn. This is used to determine what symbol in the renderer is used.
 @param geometryType The type of the geometry determines what kind of swatch is drawn.
 @param size Size of the output swatch.
 @return AGSImage of the drawn swatch.
 */
- (AGSImage *)swatchForGraphic:(AGSGraphic *)graphic geometryType:(AGSGeometryType)geometryType size:(CGSize)size;

@end


