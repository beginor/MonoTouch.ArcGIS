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

/** @file AGSRangeDomain.h */ //Required for Globals API doc

/** @brief An object representing a range domain.
 
 Instances of this class represent a range domain. Range domains specify a 
 valid range of values for an attribute. For example, Gas Pipe features may have 
 a @em pressure attributethat can only have values between 5 and 10 psi.
 @since 1.0
 */
@interface AGSRangeDomain : AGSDomain

/** The lower limit for the valid range of values.
 @since 1.0
 */
@property (nonatomic, strong, readonly) NSNumber *minValue;

/** The upper limit for the valid range of values.
 @since 1.0
 */
@property (nonatomic, strong, readonly) NSNumber *maxValue;

@end
