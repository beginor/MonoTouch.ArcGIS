//
//  AGSLabelClass.h
//  ArcGIS
//
//  Created by ryan3374 on 12/21/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
@class AGSTextSymbol;

/** The placement of a label.
 @since 1.8
 */
typedef enum {
	AGSLabelPlacementPointAboveCenter = 0,	/*!<  */
	AGSLabelPlacementPointBelowCenter,		/*!<  */
	AGSLabelPlacementPointCenterCenter,		/*!<  */
	AGSLabelPlacementPointAboveLeft,		/*!<  */
	AGSLabelPlacementPointBelowLeft,		/*!<  */
	AGSLabelPlacementPointCenterLeft,		/*!<  */
	AGSLabelPlacementPointAboveRight,		/*!<  */
	AGSLabelPlacementPointBelowRight,		/*!<  */
	AGSLabelPlacementPointCenterRight,		/*!<  */
	
	AGSLabelPlacementLineAboveAfter,		/*!<  */
	AGSLabelPlacementLineAboveStart,		/*!<  */
	AGSLabelPlacementLineBelowAfter,		/*!<  */
	AGSLabelPlacementLineBelowStart,		/*!<  */
	AGSLabelPlacementLineCenterAfter,		/*!<  */
	AGSLabelPlacementLineCenterStart,		/*!<  */
	
	AGSLabelPlacementLineAboveAlong,		/*!<  */
	AGSLabelPlacementLineAboveEnd,			/*!<  */
	AGSLabelPlacementLineBelowAlong,		/*!<  */
	AGSLabelPlacementLineBelowEnd,			/*!<  */
	AGSLabelPlacementLineCenterAlong,		/*!<  */
	AGSLabelPlacementLineCenterEnd,			/*!<  */
	
	AGSLabelPlacementLineAboveBefore,		/*!<  */
	AGSLabelPlacementLineBelowBefore,		/*!<  */
	AGSLabelPlacementLineCenterBefore,		/*!<  */
	
	AGSLabelPlacementPolygonAlwaysHorizontal		/*!<  */
	
} AGSLabelPlacement;

/** @brief Represents labelling properties 
 
 Represents the properties of how a service should be labelled.
 @since 1.8
 */
@interface AGSLabelClass : NSObject <AGSCoding>{
@private
	AGSLabelPlacement _placement;
	NSString *_labelExpression;
	BOOL _useCodedValues;
	AGSTextSymbol *_symbol;
	float _minScale;
	float _maxScale;
}

/** The placement of the label.
 @since 1.8
 */
@property (nonatomic, assign, readonly) AGSLabelPlacement placement;

/** The expression that specifies what text is drawn in the label.
 @since 1.8
 */
@property (nonatomic, retain, readonly) NSString *labelExpression;

/** Specifies whether or not the labelling should use coded values.
 @since 1.8
 */
@property (nonatomic, assign, readonly) BOOL useCodedValues;

/** The symbol that is used for this label class.
 @since 1.8
 */
@property (nonatomic, retain, readonly) AGSTextSymbol *symbol;

/** The min scale that this label class should be used.
 @since 1.8
 */
@property (nonatomic, assign, readonly) float minScale;

/** The max scale that this label class should be used.
 @since 1.8
 */
@property (nonatomic, assign, readonly) float maxScale;

@end










