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

/** @file AGSMPMessage.h */ //Required for Globals API doc

/** @brief A message object.
 
 Message contains properties which can be processed by @c AGSMessageProcessor.
 Apart from the ID, all other properties are name-value pairs which should
 be recognizable to the target message processor.
 
 @define{AGSMPMessage.h, ArcGIS}
 @since 10.1.1
 @see @c AGSMPMessageProcessor
 */
@interface AGSMPMessage : NSObject <AGSCoding> {
}

/** Id for the message.
 @since 10.1.1
 */
@property (nonatomic, copy) NSString* messageId;

/** all properties of the message
  @since 10.1.1
  */
@property (nonatomic, copy, readwrite) NSDictionary* properties;

/** Initializes a message from @p message.
 @since 10.1.1
 */
- (id)initWithMessage:(AGSMPMessage *)message;

/** Retrieve the message property for @p key.
 @param key The property key.
 @return The message property for @p key.
 @since 10.1.1
 */
- (id)propertyForKey:(NSString*)key;

/** Set the message property to @p value for @p key.
 @param value The value to set.
 @param key The key to use for @p value.
 @since 10.1.1
 */
- (void)setProperty:(id)value forKey:(NSString*)key;

@end
