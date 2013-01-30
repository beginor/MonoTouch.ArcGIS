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

/** @file AGSBingMapLayerMetadata.h */ //Required for Globals API doc

/** @brief Metadata for Bing Maps layer
 
 Instances of this class represent metadata for AGSBingMapsLayer
 
 @define{AGSBingMapLayerMetadata.h, ArcGIS}
 @since 2.3
 */
@interface AGSBingMapLayerMetadata : NSObject <AGSCoding>

/** The URL of bing maps tiles
 @since 2.3
 */
@property (nonatomic, copy, readonly) NSString* imageUri;

/** Subdomains where bing maps tiles may be hosted.
 @since 2.3
 */
@property (nonatomic, copy, readonly) NSArray* subDomains;

/** Starting scale range for bing maps tiles
 @since 2.3
 */
@property (nonatomic, assign, readonly) NSInteger zoomRangeFrom;

/** Ending scale range for bing maps tiles
 @since 2.3
 */
@property (nonatomic, assign, readonly) NSInteger zoomRangeTo;
@end
