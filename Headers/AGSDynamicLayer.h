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

@class AGSLayer;

/** @file AGSDynamicLayer.h */ //Required for Globals API doc

/** @brief A base class for dynamic layers.
 
 A base class for dynamic layers. You would typically work with concrete dynamic 
 layers represented by the sub-classes of this class, for instance, 
 @c AGSDynamicMapServiceLayer.
 
 
 @define{AGSDynamicLayer.h,ArcGIS}
 @since 1.0
 */
@interface AGSDynamicLayer : AGSLayer

/** The time interval in seconds that will cause the layer to auto-refresh.
 If 0 or less is specified, the layer will not auto-refresh itself.
 @since 10.1.1
 */
@property (nonatomic, assign) double autoRefreshInterval;

@end
