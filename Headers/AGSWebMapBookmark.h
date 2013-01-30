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

@class AGSEnvelope;

/** @brief A spatial bookmark in a web map
 
 Instances of this class represent spatial bookmarks in a web map.
 @since 2.0
 */
@interface AGSWebMapBookmark : NSObject <AGSCoding>

/** The geographic location of the bookmark.
 @since 2.0
 */
@property (nonatomic, strong, readonly) AGSEnvelope *extent;

/** The name of the bookmark.
 @since 2.0
 */
@property (nonatomic, copy, readonly) NSString *name;

@end
