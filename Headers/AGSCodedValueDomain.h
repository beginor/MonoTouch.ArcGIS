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

@class AGSDomain;

/** @file AGSCodedValueDomain.h */ //Required for Globals API doc

/** @brief Represents a coded-value domain.
 
 Instances of this class represent a coded-value domain. Coded-value domains 
 specify a valid set of values for an attribute. For example, Airport features 
 may have a @em category attribute that can only have "international", 
 "domestic", or "military" values.
 @since 1.0
 */
@interface AGSCodedValueDomain : AGSDomain
/** The valid set of values permitted by this domain. This property is an array 
 of @c AGSCodedValue objects.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *codedValues;

@end