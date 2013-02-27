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

/** @file AGSLayerTimeOptions.h */
/** @brief Options pertaining to time-aware layers
 
 Instances of this class represent options for time-aware layers.
 
 @define{AGSLayerTimeOptions.h, ArcGIS}
 @since 1.8
 */
@interface AGSLayerTimeOptions : NSObject <AGSCoding>

/** Specifies whether the layer should be time aware. If a layer is time aware,
 it honours the map's time extent and only displays features that belong to
 that time period/instant.
 @since 1.8
 */
@property (nonatomic) BOOL useTime;

/** Specifies whether the layer should treat the map's time extent cumulatively. 
 If true, the layer will draw all features from the beginning of the data's time extent.
 @since 1.8
 */
@property (nonatomic) BOOL timeDataCumulative;

/** Specifies an offset that will be applied to the time information
 of all features in the layer. The offset it applied on-the-fly, it does not
 change the actual data of the layer.
 @since 1.8
 */
@property (nonatomic) double timeOffset;

/** Specifies the units of @c #timeOffset
 @since 1.8
 */
@property (nonatomic) AGSTimeIntervalUnits timeOffsetUnits;

/** The ID of the layer 
 @since 1.8
 */
@property (nonatomic) NSUInteger layerId;

@end
