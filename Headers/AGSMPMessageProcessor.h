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

@class AGSMPMessage;
@class AGSGroupLayer;
@class AGSGraphic;
@class AGSMPSymbolDictionary;
@class AGSSpatialReference;

/** @file AGSMPMessageProcessor.h */ //Required for Globals API doc

/** @brief A message processor object.
 
 A message processor allows you to process a @c AGSMPMessage from external resources.
 For example, display a military symbol by passing a 2525C message to a
 message processor. 
 
 Each message processor comes with a @c AGSMPSymbolDictionaryType
 which dictates the message format understood by the message processor, e.g. a message needs
 to have one or more properties from '_wkid', 'sic', '_Type', '_Action' and
 '_Control_Points' in order to be successfully processed by a 2525C message processor. Each dictionary type is backed by resources which include a dictionary data
 file and message type files. The path to the resource files needs to be specified
 when a message processor object is initialized. 
 
 A message processor is bound to a
 @c AGSGroupLayer, which is used to display, update and remove @c AGSMultiLayerSymbol
 associated with the message. The group layer has to be added into @c AGSMapView, otherwise
 the message processor will fail to process the message.
 
 @define{AGSMPMessageProcessor.h, ArcGIS}
 @see @sample{479cad9e55a641aa9f20a0386a64d86a, Military 2525c Message Sample}
 @since 10.1.1
 */

@interface AGSMPMessageProcessor : NSObject{
}

/** The default spatial reference for messages.
 @since 10.1.1
 */
@property (nonatomic, strong) AGSSpatialReference* defaultMessageSpatialReference;

/** The dictionary type.
 @since 10.1.1
 */
@property (nonatomic, assign, readonly) AGSMPSymbolDictionaryType dictionaryType;

/** The set of supported message types. A message requires a type property which
 describes how the message is processed. The message type is defined in the resource
 bundle as a configuration file in JSON format. A message type contains properties
 like type name, layer name and renderer.
 @since 10.1.1
 */
@property (nonatomic, copy, readonly) NSSet* messageTypes;

/** The symbol dictionary.
 @since 10.1.1
 */
@property (nonatomic, copy, readonly) AGSMPSymbolDictionary* symbolDictionary;

/** The group layer the messages will use to draw.
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) AGSGroupLayer* groupLayer;

/** Initialize the message processor object.
 @param type The symbol dictionary type of the message processor.
 @param layer The group layer used to display symbols.
 @return A new message processor object.
 @since 10.1.1
 */
- (id)initWithSymbolDictionaryType:(AGSMPSymbolDictionaryType)type groupLayer:(AGSGroupLayer*)layer;

/** Initialize the message processor object.
 @param type The symbol dictionary type of the message processor.
 @param layer The group layer used to display symbols.
 @param path The path to the symbol dictionary source bundle directory.
 @return A new message processor object.
 @since 10.1.1
 */
- (id)initWithSymbolDictionaryType:(AGSMPSymbolDictionaryType)type groupLayer:(AGSGroupLayer*)layer symbolDictionaryPath:(NSString*)path;

/** Creates a new @c AGSMPMessage from an @c AGSGraphic object. The message gets populated with
 properties understood by the message processor. If the specified graphic is
 created from a previous message, the returned message is the identical to the previous
 one except that '_Action' property is empty.
 @param graphic The graphic to create the message from.
 @return An autoreleased @c AGSMPMessage populated with attributes/geometry from the specified graphic.
 @since 10.1.1
 */
- (AGSMPMessage*)messageFromGraphic:(AGSGraphic*)graphic;

/** Creates a new @c AGSMPMessage from an existing message id. The message id must have
 been used previously to create or update a graphic. The returned message has the same
 attributes as the previous message with specified message id except that
 the '_Action' property is empty.
 @param messageId The id of the message to retrieve.
 @return An autoreleased @c AGSMPMessage populated with attributes/geometry from the previous message.
 @since 10.1.1
 */
- (AGSMPMessage*)messageFromId:(NSString*)messageId;

/** Processes the message which conforms to the format dictated by the dictionary type.
 The message processor uses message properties to create, update, delete or otherwise change
 the state of the graphic (geometry and attributes). The message processor determines which
 message properties should be persisted on graphic as attributes.
 @param message The message to process.
 @return YES if the message was processed successfully.
 @since 10.1.1
 */
- (BOOL)processMessage:(AGSMPMessage*)message;

/** Retrieves the @c AGSGraphic which originates from the message with specified id.
 @param messageId The id of the message to retrieve the graphic for.
 @return The graphic associated with the given message id.
 @since 10.1.1
 */
- (AGSGraphic*)graphicForId:(NSString*)messageId;

@end
