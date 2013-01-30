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

/** @file AGSBase64.h */ //Required for Globals API doc

/** @brief Utility to help encode/decode strings in base 64.
 
 Represents an object to encode/decode in Base64.
 
 @define{AGSBase64.h, ArcGIS}
 @since 1.0
 */
@interface AGSBase64 : NSObject {

}

/** Setup the base64 decoding table.
 @since 1.0
 */
+ (void) initialize;

/** Returns the input of a given length as a base64-encoded <code>NSString</code>.
 @param input to be encoded 
 @param length of input
 @return base64 encoded string
 @since 1.0
 */
+ (NSString*) encode:(const uint8_t*) input length:(NSInteger) length;

/** Returns an <code>NSData</code> object as a base64-encoded <code>NSString</code>.
 @param rawBytes The raw bytes to be encoded.
 @return base64 The base64-encoded string.
 @since 1.0
 */
+ (NSString*) encode:(NSData*) rawBytes;

/** Returns a decoded <code>NSData</code> object from input of a given length.
 @param string The string to be decoded
 @param inputLength The length of the string to be decoded.
 @return decoded The decoded <code>NSData</code> object.
 @since 1.0
 */
+ (NSData*) decode:(const char*) string length:(NSInteger) inputLength;

/** Returns a decoded <code>NSData</code> object from a base64-encoded 
 <code>NSString</code>.
 @param string The string to be decoded.
 @return decoded The decoded <code>NSData</code> object.
 @since 1.0
 */
+ (NSData*) decode:(NSString*) string;

@end
