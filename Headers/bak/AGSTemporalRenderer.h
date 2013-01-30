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
@class AGSRenderer;
@class AGSSymbolInterpolator;

/** @file AGSTemporalRenderer.h */ //Required for Globals API doc

/** @brief A renderer well suited for temporal data
 
 Instances of this class represent temporal renderers. A temporal renderer is useful in visualizing changes to features over time. 
 It can only be used with a feature layer that is time aware.
 It symbolizes features based on the time information contained in the features.
 Time information can either be an instant of time, or a period of time.
 Information representing an instant of time is stored in a single attribute of the feature.
 Information representing a period of time is stored in two attributes representing the start time and the end time. 
  
 
 A temporal renderer consists of two elements - An observation renderer, and an interpolator.
 The observation renderer specifies the symbols to be used when features don't contain any time information, 
 or when the map does not have a time extent. The observation renderer can be a simple, class breaks, or unique value renderer.
 
 An interpolator "ages" the symbols specified by the observation renderer for
 features that have time information. Aging refers to modifying properties of a symbol such
 as its size or color. Two types of interpolators are supported : ramp interpolator and time class breaks ager.
 
 @see @concept{Viewing_Temporal_data/00pw00000051000000/, Viewing Temporal Data}
 @see @concept{Working_with_Symbols_and_Renderers/00pw00000021000000/ESRI_SECTION1_8D6A170C36C24DFD961879D3D8DCA30E/, Working with Symbol & Renderers}
 @see @sample{5603382f9f77482098398e01c8d276cc, Temporal}
 @since 1.8
 */
@interface AGSTemporalRenderer : AGSRenderer {
@private
	AGSRenderer *_observationRenderer;
	AGSSymbolInterpolator *_observationAger;
	AGSFeatureLayer *_featureLayer;
}

/** The renderer to use for the observations.
 @since 1.8
 */
@property (nonatomic, retain, readwrite) AGSRenderer *observationRenderer;

/** The interpolator which is used to age the symbols.
 @since 1.8
 */
@property (nonatomic, retain, readwrite) AGSSymbolInterpolator *observationAger;

/** The feature layer for which this renderer is applied.
 */
@property (nonatomic, assign, readwrite) AGSFeatureLayer *featureLayer;

/** Initializes a temporal renderer
 @param observationRenderer The observation renderer specifying the default symbols
 @param observationAger The interpolator used to age the symbols
 @param featureLayer The feature layer this renderer works with
 @return A temporal renderer
 */
-(id)initWithObservationRenderer:(AGSRenderer*)observationRenderer observationAger:(AGSSymbolInterpolator*)observationAger featureLayer:(AGSFeatureLayer*)featureLayer;

@end
