/*
 COPYRIGHT 2011 ESRI
 
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

/** @file AGSRouteResult.h */

@class AGSDirectionSet;
@class AGSGraphic;

/** @brief The result of the @c AGSRouteTask. 
 
 The result of the @c AGSRouteTask. This object should not be created manually.
 An array of @c AGSRouteResult objects will be returned within an @c AGSRouteTaskResult.
 @since 1.8
 */
@interface AGSRouteResult : NSObject {
 @private
	AGSDirectionSet *_directions;
	AGSGraphic *_routeGraphic;
	NSString *_routeName;
	NSArray *_stopGraphics;
}

/** Route directions are returned if @c AGSRouteTaskParameters <code>returnDirections</code>
 property is set to <code>true</code>.
 @since 1.8
 */
@property (nonatomic, retain, readonly) AGSDirectionSet *directions;

/** The route graphic that is returned if @c AGSRouteTaskParameters 
 <code>returnRouteGraphics</code> property is <code>true</code>.
 @since 1.8
 */
@property (nonatomic, retain, readonly) AGSGraphic *routeGraphic;

/** The name of the route.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *routeName;

/** Array of @c AGSStopGraphic objects. Returned only if @c AGSRouteTaskParameters 
 <code>returnStopGraphics</code> property is <code>true</code>.
 @since 1.8
 */
@property (nonatomic, retain, readonly) NSArray *stopGraphics;

@end
