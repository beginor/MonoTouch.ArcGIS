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

/** @file NSError+AGSAdditions.h */ //Required for Globals API doc

/** @brief A category on @c NSError to provide convenience methods
 
 This category provides a helper method to determine if a given <code>NSError</code>
 is an authentication error.
 
 This includes both token and basic authentication errors.
 
 @since 1.0
 */
@interface NSError (AGSAdditions)

/** Determines if the current error is an authentication error.
 @since 1.0
 */
-(BOOL)ags_isAuthenticationError;

@end
