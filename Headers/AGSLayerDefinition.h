/*
 COPYRIGHT 2010 ESRI
 
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

@protocol AGSCoding;

/** @file AGSLayerDefinition.h */ //Required for Globals API doc

/** @brief Represents a layer definition.
 
 Instances of this class represent a layer definition by which to filter features of
 individual layers.
 
 @define{AGSLayerDefinition.h, ArcGIS}
 @since 1.0
 */
@interface AGSLayerDefinition : NSObject

/** Particular layer id the definition belongs to.
 @since 1.0
 */
@property (nonatomic, assign) NSInteger layerId;

/** The definition by which to filter features.
 @since 1.0
 */
@property (nonatomic, copy) NSString *definition;

/** Initializes the layer definition.
 @since 1.0
 */
-(id)init;

/** Initializes an <code>AGSLayerDefinition</code> with a given @p layerId and 
 @p definition.
 @param layerId The layer ID on which to set definition expression.
 @param definition The definition expression to filter the features in the layer.
 @since 1.0
 */
-(id)initWithLayerId:(NSInteger)layerId definition:(NSString*)definition;

/** Initialize an autoreleased <code>AGSLayerDefinition</code> with a given 
 @p layerId and @p definition.
 @param layerId The layer ID on which to set definition expression.
 @param definition The definition expression to filter the features in the layer.
 @return An autoreleased <code>AGSLayerDefinition</code>.
 @since 1.0
 */
+(id)layerDefinitionWithLayerId:(NSInteger)layerId definition:(NSString*)definition;

/** Encode an array of layer definitions to JSON representation.
 @param array The array of layer definitions to encode. 
 @return json The JSON representation of the layer definitions.
 @since 1.0
 */
+(NSDictionary*)encodeToJSON:(NSArray*)array;

/** Decode @p json into an array of <code>AGSLayerDefinition</code> objects.
 @param json The JSON representation of layer definitions.
 @return An array of <code>AGSLayerDefinition</code> objects.
 @since 1.0
 */
+(NSArray*)decodeWithJSON:(NSDictionary*)json;

@end
