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

/** @file AGSPopupViewType.h */ //Required for Globals API doc

/** The type of view within @c AGSPopupsContainerViewController
 @since 2.0
 */
typedef enum{
	AGSPopupViewTypeContainer = 0,  /*!< The default starting view */
	AGSPopupViewTypeUIImagePicker,  /*!< View that displays the UIImagePicker */
	AGSPopupViewTypeFullMedia,      /*!< View that displays a single media item (image/chart)  */
	AGSPopupViewTypeWeb,            /*!< View that displays an embedded UIWebView */
	AGSPopupViewTypeAttachments,    /*!< View that displays attachments */
	AGSPopupViewTypeMovie,          /*!< View that displays movies */
	AGSPopupViewTypeAttribute       /*!< View that displays attributes */
}AGSPopupViewType;

