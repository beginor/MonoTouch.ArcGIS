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



/** @file AGSWebMapFeatureCollection.h */ //Required for Globals API doc

/** @brief A feature collection in a web map
 
 Instances of this class represent feature collections. A feature collection is a representation of one or more feature layers, where each layer contains the definition of that layer and the features that belong to that layer. In other words, the feaure layer contains all the information it needs to display map contents, and it does not rely on a backing map or feature service.
 @since 2.2
 */
@interface AGSWebMapFeatureCollection : NSObject <AGSCoding>

/** An array of @c AGSWebMapSubLayerInfo objects representing the individual feature layers in this feature collection.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSArray *layers;

/** Whether to show legend for the feature collection.
 @since 2.2
 */
@property (nonatomic, assign, readonly) BOOL showLegend;

/**
 @since 2.2
 */
-(id)initWithJSON:(NSDictionary*)json;

@end
