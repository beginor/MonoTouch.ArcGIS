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



@class AGSRenderer;
@class AGSSymbol;

/** @file AGSClassBreaksRenderer.h */ //Required for Globals API doc

#pragma mark -

/** @brief A renderer based on class breaks.
 
 A class breaks renderer symbolizes each graphic based on the value of some
 numeric attribute. Graphics with similar values for the attribute get the same
 symbol. The "breaks" define the values at which the symbology changes.
 
 For example, suppose you have a "buildings" layer with an attribute that 
 defines the building age. You want to symbolize buildings constructed since
 the year 2000 in green, buildings constructed between 1980 and 2000 in yellow,
 and buildings built before 1980 with red. This would be a good scenario for
 class breaks renderer.
 
 Any value that is greater than or equal to the minimum will be included in the
 break. Any value that is less than the maximum will be included in the break.
 
 @define{AGSClassBreaksRenderer.h, ArcGIS}
 @since 1.0
 */
@interface AGSClassBreaksRenderer : AGSRenderer {
}

/** Attribute field used by renderer to match values. This must be a key from 
 the attributes collection of the graphic.
 @since 1.0
 */
@property (nonatomic, copy, readwrite) NSString *field;

/** A collection of class breaks defined for the renderer. The breaks are an 
 array of @c AGSClassBreak objects.
 @since 1.0
 */
@property (nonatomic, copy) NSArray *classBreaks;

/** The minimum value for this class breaks renderer.
 @since 1.0
 */
@property (nonatomic, assign, readwrite) double minValue;

/** The symbol to use if the value does not fall into any of the class breaks.
 @since 2.3
 */
@property (nonatomic, strong, readwrite) AGSSymbol *defaultSymbol;

@end


