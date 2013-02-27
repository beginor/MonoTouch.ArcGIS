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



@protocol AGSCoding;

/** @brief Represents a message from a network analyst task.
 
 Instances of this class represent messages generated during the execution of a network analyst task.
 Messages provide information about warnings or errors encountered while performing analysis and 
 could be very helpful in troublshooting any problems. It is always a good idea to inspect the messages
 to ensure that the analysis is performed correctly.

 @since 1.8
 */
@interface AGSNAMessage : NSObject <AGSCoding>

/** A description of the network analyst message.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *messageDescription;

/** The network analyst message type, see constants table for a list of values.
 @since 1.8
 */
@property (nonatomic, assign, readonly) AGSNAMessageType type;

@end
