/*
 COPYRIGHT 2012 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and 
 Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */

/** @file AGSWMTSStyle.h */

/** @brief A Style for a WMTS Server map service
 
 An instance of this class provides information on an availiable
 style of the tiles provided by a WMTS map service.
 
 @define {AGSWMTSStyle.h, ArcGIS}
 @since 10.1.1
*/


@interface AGSWMTSStyle : NSObject 

/** The style identifier.
 @since 10.1.1
 */
@property (nonatomic, copy, readonly) NSString *identifier;

/** The title of the style.
 @since 10.1.1
 */
@property (nonatomic, copy, readonly) NSString *title;

/** A brief summary of the style.
 @since 10.1.1
 */
@property (nonatomic, copy, readonly) NSString *abstract;


/** A Boolean denoting whether this is the default style.
 @since 10.1.1
*/
@property (readonly) BOOL isDefault;

@end
