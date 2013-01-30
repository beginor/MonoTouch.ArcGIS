/*
 COPYRIGHT 2009 ESRI
 
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



/** @file AGSWebMapQueryParameter.h */ //Required for Globals API doc

/** @brief A predicate in the where clause of a web map query
 
 Instances of this class can be used to construct a predicate for @c AGSWebMapQuery#whereClause. The application should provide UI to capture input from the user for each @c AGSWebMapQueryParameter object in @c AGSWebMapQuery#parameters. This input can then be combined with the remaining information in the object to construct a predicate. 
 
 For example, suppose the value of @c #field is "Magnitude", @c #paramOperator is "=", and the value entered by a user is 2. This information can be combined into a string "Magnitude = 2" which can then be used in a whereClause to query for earthqukes with a magnitude of 2.
 
 @since 2.2
 */
@interface AGSWebMapQueryParameter : NSObject <AGSCoding>

/** The default value to compare with the field's value in the event that a user does not provide another value.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *defaultValue;

/** The name of the field (attribute) on which the query will be executed.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *field;

/** The operator (<, >, =, etc) to be used to compare the field's value. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *paramOperator;

/** The message to be displayed to the user to indicate what the user input represents. For example, "Earthquake Magnitude:".  This message should usually be displayed adjacent to the textfield.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *prompt;

/** A tip explaining what input would be valid. For example, "A value between 0 and 10".
  @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *helpTip;

/**
 @since 2.2
 */
- (id)initWithPrompt:(NSString *) p
			   field:(NSString *)f
		defaultValue:(NSString *) dv
	   paramOperator:(NSString *)op
			 helpTip:(NSString *) h;

@end
