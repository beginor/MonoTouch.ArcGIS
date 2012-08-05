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
@protocol AGSCoding;

/** @file AGSUniqueValueRenderer.h */ //Required for Globals API doc

#pragma mark -

/** @brief A renderer based on unique values.
 
 A unique value renderer symbolizes groups of graphics that have matching
 attributes. This is most common with nominal, or string data. 
 
 For example, you could use a unique value renderer to symbolize zoning 
 designations: yellow for "Residential", purple for "Industrial", red for 
 "Commercial", and so on. You can also use unique value renderers on numeric 
 fields that are coded values, or on ordinal attributes such as "First", "Second", 
 "Third", and so on.
 
 Typically features are rendered based on the unique values of one attribute 
 field. However, up to three fields can be combined to generate a unique value. 
 
 @define{AGSUniqueValueRenderer.h, ArcGIS}
 @since 1.0
 */

@interface AGSUniqueValueRenderer : AGSRenderer {
 @private
    AGSSymbol *_defaultSymbol;
	NSString *_field1;
	NSString *_field2;
	NSString *_field3;
	NSString *_fieldDelimiter;
	NSString *_defaultLabel;
	NSMutableArray *_uniqueValues;
}

/** Default symbol for the renderer. This symbol is used for any unmatched values.
 @since 1.0
 */
@property (nonatomic, retain, readwrite) AGSSymbol *defaultSymbol;

/** The name of the attribute field the renderer uses to match values against.
 @since 1.0
 */
@property (nonatomic, retain, readwrite) NSString *field1;

/** If @em needed , specifies an additional attribute field the renderer uses to 
 match values.
 @since 1.0
 */
@property (nonatomic, retain, readwrite) NSString *field2;

/** If @em needed , specifies an additional attribute field the renderer uses to 
 match values.
 @since 1.0
 */
@property (nonatomic, retain, readwrite) NSString *field3;

/** String inserted between the values if multiple attribute fields are specified.
 @since 1.0
 */
@property (nonatomic, retain, readwrite) NSString *fieldDelimiter;

/** Label for the default symbol used to draw unspecified values.
 @since 1.0
 */
@property (nonatomic, retain, readwrite) NSString *defaultLabel;

/** An array of @c AGSUniqueValue objects defined for the renderer.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSMutableArray *uniqueValues;


@end



