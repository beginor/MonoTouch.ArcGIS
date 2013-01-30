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

@class AGSField;

/** @file AGSDomain.h */ //Required for Globals API doc

/** @brief An attribute domain.
 
 Instances of this class represent attribute domains. Domains are a set of 
 rules that describe the legal values for a field. Domains provide a way to 
 constrain attribute values and enforce data integrity.
 
 @since 1.0
 */
@interface AGSDomain : NSObject <AGSCoding>

/** Name of the domain.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Initialize an <code>AGSDomain</code> with JSON representation and a parent
 field. The parent field is important in cases where properties
 are inherited from the parent field.
 @param json The JSON representation of a domain.
 @param parentField @c AGSField corresponding to one of <code>AGSFeatureLayer</code>'s 
 <code>fields</code>.
 @return A new, autoreleased, domain.
 @since 1.0
 */
+(id)domainWithJSON:(NSDictionary*)json parentField:(AGSField*)parentField;

@end
