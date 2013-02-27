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



/** @file AGSPopupMediaInfo.h */ //Required for Globals API doc

/** Enumeration that specifies different types of media in an AGSPopup.
 @since 2.0
 */
typedef enum{
	AGSPopupMediaInfoTypeImage = 0, /*!< Image */
	AGSPopupMediaInfoTypeLineChart, /*!< Line Chart */
	AGSPopupMediaInfoTypeBarChart,  /*!< Bar Chart */
	AGSPopupMediaInfoTypePieChart,  /*!< Pie Chart */
	AGSPopupMediaInfoTypeColumnChart    /*!< Column Chart */
} AGSPopupMediaInfoType;

/** @brief Information about a single media in a popup
 
 Instances of this class represents media that is displayed in a popup for a graphic.
 @since 2.0
 */
@interface AGSPopupMediaInfo : NSObject <AGSCoding>

/** The caption that is displayed for the media.
 This can contain a literal value, or a placeholder for value from the graphic's attribute for which the popup is displayed. The placeholder needs to be of the form {field_name}
 where <i>field_name</i> is a key in the graphic's attributes.
 @since 2.0
 */
@property (nonatomic, copy) NSString *caption;

/** The title that is displayed for the media. 
 This can contain a literal value, or a placeholder for value from the graphic's attribute 
 for which the popup is displayed. The placeholder needs to be of the form {field_name}
 where <i>field_name</i> is a key in the graphic's attributes.
 @since 2.0
 */
@property (nonatomic, copy) NSString *title;

/** The type of media. 
 @since 2.0
 */
@property (nonatomic, assign) AGSPopupMediaInfoType type;

/** The value for the media. This will be of a different format depending on what the media type is. 
 
 If the media Is of type @c AGSPopupMediaInfoTypeImage,  then the value dictionary can have the following keys: 
 1.       linkURL   -  what the image should link to.
 2.       sourceURL -   where to pull the image from. 
 
 Both <code>linkURL</code> and <code>sourceURL</code> are strings. 
 
 If the media is any type of chart, then the value dictionary will have the following:
 1.       fields – an array of field names to build the chart from.
 2.       normalizeField -  the field to normalize all values to. (only applicable to line, bar, and column charts.)
 
 @since 2.0
 */
@property (nonatomic, copy) NSDictionary *value;

/** Initializes an AGSPopupMediaInfo.
 @param title See #title
 @param caption See #caption
 @param type See #type
 @param value See #value
 @return An @c AGSPopupMediaInfo
 @since 2.0
 */
-(id)initWithTitle:(NSString*)title caption:(NSString*)caption type:(AGSPopupMediaInfoType)type value:(NSDictionary*)value;

/** Returns an autoreleased AGSPopupMediaInfo.
 @param title See #title
 @param caption See #caption
 @param type See #type
 @param value See #value
 @return An autoreleased @c AGSPopupMediaInfo @since 2.0
 */
+(AGSPopupMediaInfo*)popupMediaInfoWithTitle:(NSString*)title caption:(NSString*)caption type:(AGSPopupMediaInfoType)type value:(NSDictionary*)value;


@end
