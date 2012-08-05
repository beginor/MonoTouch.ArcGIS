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

@protocol AGSCoding;
@protocol AGSInfoTemplateDelegate;

@class AGSGeometry;
@class AGSSymbol;

/** @file AGSGraphic.h */ //Required for Globals API doc

#pragma mark -

/** @brief A graphic on the map.
 
 Instances of this class represent graphics. Graphics can be displayed on the 
 map through an @c AGSGraphicsLayer. Graphics can be used as input to a task, or 
 they can be used to display output from a task, or in response to user interaction.
  
 Each graphic must contain an @c AGSGeometry describing the location and the shape 
 of the graphic. The geometry must have the same spatial reference as the map. 
 
 A graphic can be associated with an @c AGSSymbol which determines how the graphic 
 looks. Alternatively, the graphics layer can be assgined an @c AGSRenderer which 
 determines the appearance of all graphics in the layer. Note, symbols associated 
 with individual graphics take precedence over the symbols chosen by the renderer. 
 The #symbol used depends upon the geometry type associated with the graphic. 
 An @c AGSMarkerSymbol is used for point and multipoint geometries, 
 @c AGSSimpleLineSymbol for polyline geometries, and @c AGSSimpleFillSymbol
 for polygon geometries.
 
 A graphic can contain a set of #attributes (key-value paris) providing more 
 information about the graphic. This information is displayed in an @c AGSCallout 
 when a user taps on the graphic.
 
 A graphic can also contain an #infoTemplateDelegate that describes how attribute 
 information should be displayed in the callout.
 
 @define{AGSGraphic.h, ArcGIS}
 @since 1.0
 @see AGSMapViewDelegate for events related to tapping on graphics and showing the 
 callout window.
 */
@interface AGSGraphic : NSObject <AGSCoding, NSCopying> {
 @private
    AGSGeometry *_geometry;
    AGSSymbol *_symbol;
    NSMutableDictionary *_attributes;
    id<AGSInfoTemplateDelegate> _infoTemplateDelegate;
	AGSGraphicsLayer *_layer;
    BOOL _visible;
}

/** The geometry that defines the graphic's shape and location.
 @since 1.0
 */
@property (nonatomic, retain) AGSGeometry *geometry;

/** The symbol for the graphic.
 @since 1.0
 */
@property (nonatomic, retain) AGSSymbol *symbol;

/** Attributes representing additional information about this graphic. Consists of 
 key-value pairs of field names and field values.
 @since 1.0
 */
@property (nonatomic, retain) NSMutableDictionary *attributes;


/** Template describing how the callout should display this graphic's attributes.
 @see AGSCalloutTemplate
 @since 1.0
 */
@property (nonatomic, assign) id<AGSInfoTemplateDelegate> infoTemplateDelegate;

/** The graphics layer that this graphic belongs to, if any.
 @since 1.8
 */
@property (nonatomic, assign, readonly) AGSGraphicsLayer *layer;

/** Whether or not the graphic is visible in the layer.
 @since 2.1
 */
@property (nonatomic, assign, getter=isVisible) BOOL visible;

/** Initialize the graphic object. Only the @p geometry argument is mandatory.
 @param geometry The geometry defining the graphic.
 @param symbol The symbol used to draw the graphic. Can be nil.
 @param attributes Name-value pairs of fields and field values associated with 
 the graphic.
 @param infoTemplateDelegate The template describing how to display @p attributes 
 in the callout. Can be nil.
 @return A new graphic object.
 @since 1.0
 */
- (id)initWithGeometry:(AGSGeometry *)geometry symbol:(AGSSymbol *)symbol attributes:(NSMutableDictionary *)attributes infoTemplateDelegate:(id<AGSInfoTemplateDelegate>)infoTemplateDelegate;

/** Returns autoreleased graphic object. Only the @p geometry argument is mandatory.
 @param geometry The geometry defining the graphic.
 @param symbol The symbol used to draw the graphic. Can be nil.
 @param attributes Name-value pairs of fields and field values associated with 
 the graphic.
 @param infoTemplateDelegate The template describing how to display @p attributes 
 in the callout. Can be nil.
 @return A new, autoreleased, graphic object.
 @since 1.0
 */
+ (id)graphicWithGeometry:(AGSGeometry *)geometry symbol:(AGSSymbol *)symbol attributes:(NSMutableDictionary *)attributes infoTemplateDelegate:(id<AGSInfoTemplateDelegate>)infoTemplateDelegate;

@end
