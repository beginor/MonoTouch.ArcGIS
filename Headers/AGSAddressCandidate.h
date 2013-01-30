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

@class AGSPoint;

/** @file AGSAddressCandidate.h */ //Required for Globals API doc

/** @brief Represents an address and its location.
 
 Instances of this class represent results returned by @c AGSLocator for 
 geocoding and reverse-geocoding operations. Each result is an address 
 candidate.
 
 @define{AGSLocator.h, ArcGIS}
 @since 1.0
 */
@interface AGSAddressCandidate : NSObject <AGSCoding>

/** A single line address of the candidate, if available.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *addressString;

/** Address of the candidate. The dictionary contains a key-value pair for each 
 address field defined by the geocode service. Each address field describes some 
 part of the address information for the candidate.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSDictionary *address;

/** A dictionary containing key-value pairs of address field name and value as 
 requested in the @p returnFields argument of 
 <code>locationsForAddress:returnFields:</code> on @c AGSLocator.  
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSDictionary *attributes;

/** x,y coordinates of the candidate.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSPoint *location;

/** Numeric score between 0 and 100 for the candidate. A score of 100 means a 
 perfect match, and 0 means no match.
 @since 1.0
 */
@property (nonatomic, readonly) double score;

@end