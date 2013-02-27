/*
 COPYRIGHT 2012 ESRI
 
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
@class AGSEnvelope;
@class AGSGraphic;

/** @brief Results from a find operation on a @c AGSLocator
 
 Instances of this class represent individual results returned by @c AGSLocator#findWithParameters:
 
 @since 10.1.1
 */
@interface AGSLocatorFindResult : NSObject

/** The area covered by the result. Useful if you want to zoom into the result.
 @since 10.1.1
 */
@property (nonatomic, retain, readonly) AGSEnvelope *extent;

/** Information about the result as a graphic.
 You can add the graphic directly to the graphics layer.
 The graphic contains attributes providing more information about the result.
 @since 10.1.1
 */
@property (nonatomic, retain, readonly) AGSGraphic *graphic;

/** The name of the result
 @since 10.1.1
 */
@property (nonatomic, copy, readonly) NSString *name;

@end
