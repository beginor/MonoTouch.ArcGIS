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

/** @file AGSMapServiceLayerInfo.h */ //Required for Globals API doc

#pragma mark -

/** @brief Information about a layer in an ArcGIS Server service.
 
 Instances of this class represent information about a layer in an ArcGIS Server 
 map or feature service.

 @define{AGSMapServiceLayerInfo.h, ArcGIS}
 @since 1.0
 */
@interface AGSMapServiceLayerInfo : NSObject <AGSCoding> {
@private
    BOOL _defaultVisibility;
    NSUInteger _layerId;
    NSString *_name;
    NSInteger _parentLayerID;
    NSArray *_subLayerIDs;
	double _minScale;
	double _maxScale;
	
	NSArray *_legendImages;
	NSArray *_legendLabels;
}

/** Default visibility of the layer, as defined by the service.
 @since 1.8
 */
@property (nonatomic, readonly) BOOL defaultVisibility;

/** ID of the layer. The topmost layer is usually 0, and each layer follows 
 sequentially. If a layer is added or removed from the source map document, 
 the ID values will shift accordingly.
 @since 1.8
 */
@property (nonatomic, readonly) NSUInteger layerId;

/** User-friendly name of the layer.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSString *name;

/** ID of the parent layer if this layer is part of a group layer. Otherwise, 
 the value is -1. 
 @since 1.0
 */
@property (nonatomic, readonly) NSInteger parentLayerID;

/** An array of IDs of descendant layers if this layer is a parent layer. 
 Otherwise, the value is <code>nil</code>. 
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSArray *subLayerIDs;

/** The minimum scale at which this layer is visible. If map's scale is lower
 than this scale, the layer won't be visible.
 @since 1.8
 */
@property (nonatomic, assign, readonly) double minScale;


/** The maximum scale at which this layer is visible. If map's scale is higher
 than this scale, the layer won't be visible.
 @since 1.8
 */
@property (nonatomic, assign, readonly) double maxScale;

/** An array of @c UIImage object representing legend swatches (images)
 for this layer. You need to invoke the @c retrieveLegendInfo method on 
 @c AGSMapServiceInfo for this property to be populated.
 @since 1.8
 */
@property (nonatomic, retain, readonly) NSArray *legendImages;

/** An array of strings representing the text for each legend swatch
 of this layer. You need to invoke the @c retrieveLegendInfo method on 
 @c AGSMapServiceInfo for this property to be populated.
 @since 1.8
 */
@property (nonatomic, retain, readonly) NSArray *legendLabels;

@end
