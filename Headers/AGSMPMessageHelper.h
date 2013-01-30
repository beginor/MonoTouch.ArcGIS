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
@class AGSSpatialReference;

/** @file AGSMessageHelper.h */ //Required for Globals API doc

/** @brief A message helper object.
 
 Helper class which provides user-friendly property names
 and convenient methods to create messages.
 
 @define{AGSMPMessageHelper.h, ArcGIS}
 @since 10.1.1
  @see @c AGSMPMessageProcessor
 */
@interface AGSMPMessageHelper : NSObject

/** Creates a 2525C message to remove the symbol.
 @param messageId The message id.
 @param messageType The message type.
 @return A new, autoreleased, message object.
 @since 10.1.1
 */
+ (AGSMPMessage*)mil2525CRemoveMessageWithId:(NSString *)messageId
                                 messageType:(NSString *)messageType;

/** Creates a 2525C message to update the symbol.
 @param messageId The message id.
 @param messageType The message type.
 @param controlPoints The array of AGSPoint control points.
 @param attributes The attributes for the message.
 @return A new, autoreleased, message object.
 @since 10.1.1
 */
+ (AGSMPMessage*)mil2525CUpdateMessageWithId:(NSString *)messageId
                                 messageType:(NSString *)messageType
                               controlPoints:(NSArray*)controlPoints
                                  properties:(NSDictionary*)properties;

/** Creates a 2525C message to update the symbol with specified properties.
 @param messageId The message id.
 @param attributes The attributes for the message.
 @return A new, autoreleased, message object.
 @since 10.1.1
 */
+ (AGSMPMessage*)mil2525CUpdateMessageWithId:(NSString *)messageId
                                  properties:(NSDictionary *)properties;

/** Creates a 2525C message to create or update the symbol.
 This method is useful for a message aiming to display the
 symbol very first time.
 @param messageId The message id.
 @param messageType The message type.
 @param controlPoints The array of AGSPoint control points.
 @param attributes The attributes for the message.
 @param WKID The well-known ID of the spatial reference for the message.
 @return A new, autoreleased, message object.
 @since 10.1.1
 */
+ (AGSMPMessage*)mil2525CUpdateMessageWithId:(NSString *)messageId
                                 messageType:(NSString *)messageType
                               controlPoints:(NSArray*)controlPoints
                                  properties:(NSDictionary*)properties
                            spatialReference:(AGSSpatialReference*)spatialReference;

@end
