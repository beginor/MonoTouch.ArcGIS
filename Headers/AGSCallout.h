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

#import <UIKit/UIKit.h>

@protocol AGSCalloutDelegate;

@class AGSMapView;
@class AGSPoint;

/** Supported positions of the callout's leader. The position is relative
 to the callout itself.
 @since 2.1
 */
typedef enum {
    AGSCalloutLeaderPositionBottom = 1UL << 0,          /*!< Leader is placed on the bottom edge of the callout  */
    AGSCalloutLeaderPositionTop = 1UL << 1,             /*!< Leader is placed on the top edge of the callout */
    AGSCalloutLeaderPositionLeft = 1UL << 2,            /*!< Leader is placed on the left edge of the callout */
    AGSCalloutLeaderPositionRight = 1UL << 3,           /*!< Leader is placed on the right edge of the callout */
    AGSCalloutLeaderPositionAny = AGSCalloutLeaderPositionBottom | AGSCalloutLeaderPositionTop | AGSCalloutLeaderPositionLeft | AGSCalloutLeaderPositionRight                   /*!< Best leader position such that the callout is completely visible on the map without panning the map. For iPad, precedence is based on the order - Left, Right, Top, Bottom. For other devices precedence is based on the order - Bottom, Top, Left, Right. */
} AGSCalloutLeaderPosition;

/** @file AGSCallout.h */ //Required for Globals API doc

/** @brief A callout window.
 
 Instances of this class represent a callout window. A callout can be used to 
 display information on a map. The callout displays a title and a detail string. 
 It also contains an accessory button that can be used to display a secondary 
 view with more details.
 
 By default, the  map's callout shows information about a graphic when a user 
 taps on the graphic. The map's callout also shows information for each location 
 update provided by the GPS.
  
 You can programatically display a callout using the <code>showCalloutAtPoint:</code>
 method from @c AGSMapView.
 
 To hide the callout, you can set it's <code>hidden</code> property.
 
 @extends UIView
 @see @concept{Displaying_a_Callout/00pw0000004t000000/, Displaying a Callout}
 @since 1.0
 */
@interface AGSCallout : UIView {
@private
    AGSPoint *_mapLocation;
	CGPoint _pixelOffset;
    CGPoint _screenPoint; // only used by moveToScreenPoint and showAtScreenPoint
    CGFloat _width;
	CGFloat _height;
	CGFloat _dx;
    CGFloat _dy;
	
    NSString *_title;
    NSString *_detail;
    
    UILabel *_titleLabel;
    UILabel *_detailLabel;
    UIButton *_accessoryButton;
    
    UIColor *_color;
    UIColor *_highlight;
    
    id<AGSCalloutDelegate> _calloutDelegate;
	
	AGSMapView *_mapView;
	
	UIView *_customView;
	CGRect _bubbleRect;
	CGRect _insetRect;
	
	CGSize _defaultMargin;
	CGSize _margin;
	float _maxWidth;
	UIButtonType _accessoryButtonType;
	UIColor *_titleColor;
	UIColor *_detailColor;
	BOOL _accessoryButtonHidden;
	UIImage *_accessoryButtonImage;
	UIImage *_image;
	UIImageView *_imageView;
	BOOL _autoAdjustWidth;
	
	CGFloat _cornerRadius;
    
    AGSCalloutLeaderPosition _leaderPositionFlags;
    AGSCalloutLeaderPosition _bestLeaderPosition;
}

/** The map that will display the callout.
 @since 1.0
 */
@property (nonatomic, assign, readonly) AGSMapView *mapView;

/** Location in map coordinates where the callout's leader should point to. If 
 the callout is shown in response to a user tap, this property contains the 
 tapped location. If the callout is shown in response to a GPS location update, 
 this property contains that location. 
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSPoint *mapLocation;

/** Pixels offset in screen coordinates from the map location that the callout 
 leader should point to. This is generally used with Marker symbols that have 
 offsets so that the callout will display in the correct location as the map is 
 scaled (zoomed in or out). A positive x-value adjust the callout to the right. 
 A positive y-value adjusts the callout down.
 @since 1.0
 */
@property (nonatomic, readonly) CGPoint pixelOffset;

/** Callout width. This property is ignored if using a custom view.
 @since 1.0
 */
@property (nonatomic) CGFloat width;

/** Text for title label. The title for a graphic is provided by 
 @p infoTemplateDelegate on @c AGSGraphic. The title for a GPS location is 
 provided by @p infoTemplateDelegate on @c AGSGPS. 
 @since 1.0
 */
@property (nonatomic, copy) NSString *title;

/** Text for detail string. The detail for a graphic is provided by 
 @p infoTemplateDelegate on @c AGSGraphic. The detail for a GPS location is 
 provided by @p infoTemplateDelegate on @c AGSGPS.
 @since 1.0
 */
@property (nonatomic, copy) NSString *detail;

/** Background color of callout. Default is black with .8 alpha.
 @since 1.0
 */
@property (nonatomic, retain) UIColor *color;

/** Highlight color of callout. Default is white with .15 alpha.
 @since 1.0
 */
@property (nonatomic, retain) UIColor *highlight;

/** Text color. Default is white.
 @since 1.0
 */
@property (nonatomic, retain) UIColor *titleColor;

/** Detail text color. Default is white.
 @since 1.0
 */
@property (nonatomic, retain) UIColor *detailColor;

/** Shows or hides the accessory button.
 @since 1.0
 */
@property (nonatomic, assign, getter=isAccessoryButtonHidden) BOOL accessoryButtonHidden;

/** Flags specifying the possible leader locations when showing the callout. Possible values include:
 
 @li @c AGSCalloutLeaderPositionLeft
 @li @c AGSCalloutLeaderPositionRight
 @li @c AGSCalloutLeaderPositionTop
 @li @c AGSCalloutLeaderPositionBottom
 @li @c AGSCalloutLeaderPositionAny
 
 
 These values can be combined with the bitwise OR operator. The default value
 is  @c AGSCalloutLeaderPositionBottom . 
 
 <code>AGSCalloutLeaderPositionAny</code> will attempt to find the best location for the given
 point. On the iPad, precedence is given based on the following sequence - left, right, bottom, top. On all other iOS devices, 
 it is - bottom, top, left, right. 
 
 @since 2.1
 */
@property (nonatomic, assign) AGSCalloutLeaderPosition leaderPositionFlags;

/** Moves the callout to the specified map location and pixel offset.
 @param mapLocation The location on the map to move to. 
 @param pixelOffset The offset from the map location to place the callout. 
 @param animated Flag to determine if action should be animated.
 @since 1.0
*/
-(void)moveCalloutTo:(AGSPoint*)mapLocation pixelOffset:(CGPoint)pixelOffset animated:(BOOL)animated;

/**
 @since 2.1
 */
-(void)showCalloutAt:(AGSPoint*)mapLocation pixelOffset:(CGPoint)pixelOffset animated:(BOOL)animated;

/** The custom view to display in the callout. If this property is specified,
 the developer is responsible for the content displayed in the callout. The callout will expand
 to fit the dimensions of the custom view. Most of the other properties related to the look
 of the callout will be ignored.
 @since 1.8
 */
@property (nonatomic, retain) UIView *customView;

/** The margin in points around the customView.
 This property is ignored if not using a custom view.
 @since 1.8
 */
@property (nonatomic) CGSize margin;

/** The corner radius in points for the rounded corners.
 This property is ignored if not using a custom view.
 @since 1.8
 */
@property (nonatomic) CGFloat cornerRadius;

/** The maximum width of the callout if the callout is autosizing to the text. 
 To autosize to the text width, set the autoAdjustWidth property to YES. This property is ignored
 if using a custom view.
 @since 1.8
 */
@property (nonatomic) CGFloat maxWidth;

/** The type of button for the accessory button.
 @since 1.8
 */
@property (nonatomic) UIButtonType accessoryButtonType;

/** The optional image used for the accessory button. 
 @since 1.8
 */
@property (nonatomic, retain) UIImage *accessoryButtonImage;

/** The optional image used for displaying content to the left of the text labels.
 The image will be scaled to 40x40 points.
 @since 1.8
 */
@property (nonatomic, retain) UIImage *image;

/** This is a parameter than specifies that the width of the callout should adjust to the size
 of the text. This parameter is ignored if using a custom view.
 @since 1.8
 */
@property (nonatomic) BOOL autoAdjustWidth;

@end



#pragma mark -

/** @brief A delegate of @c AGSCallout.

 A protocol which must be adopted by a class wishing to be notified when a user 
 interacts with the callout window. An instance of the class must then be set as 
 the delegate of @c AGSCallout.

 All of the methods of this protocol are optional.
 
 @define{AGSCallout.h, ArcGIS}
 @since 1.0
 @see AGSMapViewCalloutDelegate for events related to showing the callout.
 */
@protocol AGSCalloutDelegate <NSObject>

@optional

/** Tells the delegate the user tapped on the accessory button in the callout
 @param callout containing accessory button.
 @since 1.0
 */
- (void)calloutDidClickAccessoryButton:(AGSCallout *)callout;

@end
