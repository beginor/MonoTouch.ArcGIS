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

#import <Foundation/Foundation.h>

/** @file AGSPopupFieldInfo.h */ //Required for Globals API doc

/** Enumeration that specifies how date fields are formatted in an AGSPopup.
 @since 2.0
 */
typedef enum{
	AGSPopupFieldInfoDateFormatShortDate = 0,           /*!< Date with NSDateFormatterShortStyle */
	AGSPopupFieldInfoDateFormatLongMonthDayYear,        /*!< Date with  NSDateFormatterLongStyle */
	AGSPopupFieldInfoDateFormatShortMonthYear,          /*!< Date with MMM yyyy */
	AGSPopupFieldInfoDateFormatDayShortMonthYear,       /*!< Date with d, MMM yyyy */
	AGSPopupFieldInfoDateFormatLongDate,                /*!< Date with NSDateFormatterFullStyle */
	AGSPopupFieldInfoDateFormatShortDateShortTime,      /*!< Date & Time with NSDateFormatterShortStyle */
	AGSPopupFieldInfoDateFormatShortDateShortTime24,    /*!< Date with M/d/yyyy H:m */
	AGSPopupFieldInfoDateFormatLongMonthYear,           /*!< Date with MMMM yyyy */
	AGSPopupFieldInfoDateFormatYear,                    /*!< Date with yyyy */
}AGSPopupFieldInfoDateFormat;

/** @brief Information about a field in a popup.
 
 Instances of this class represent how a graphic's attribute (field) should be displayed in a popup.
 @since 2.0
 */
@interface AGSPopupFieldInfo : NSObject <AGSCoding> {
@private
    NSString *_fieldName;
    NSString *_label;
    NSString *_tooltip;
	NSInteger _numDecimalPlaces;
	BOOL _showDigitSeparator;
	AGSPopupFieldInfoDateFormat _dateFormat;
    BOOL _editable;
    BOOL _visible;
}

/** The name of the field.
 @since 2.0
 */
@property (nonatomic, retain) NSString *fieldName;

/** The label that is shown for this field in the popup.
 @since 2.0
 */
@property (nonatomic, retain) NSString *label;

/** The tool tip that is shown for this field in the popup.
 @since 2.0
 */
@property (nonatomic, retain) NSString *tooltip;

/** The number of decimal places that are shown for numeric values in this field.
 Applies to numeric fields only.
 @since 2.0
 */
@property (nonatomic, assign) NSInteger numDecimalPlaces;

/** Whether or not to show a digit separator for numeric values in this field.
 Applies to numeric fields only.
 @since 2.0
 */
@property (nonatomic, assign) BOOL showDigitSeparator;

/** The format in which to display dates for this field.
 Applies to date fields only.
 @since 2.0
 */
@property (nonatomic, assign) AGSPopupFieldInfoDateFormat dateFormat;

/** Whether or not the field is editable.
 @since 2.0
 */
@property (nonatomic, assign, getter=isEditable) BOOL editable;

/** Whether or not the field is visible.
 @since 2.0
 */
@property (nonatomic, assign, getter=isVisible) BOOL visible;

@end
