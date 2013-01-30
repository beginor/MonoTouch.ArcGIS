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

/** @file AGSGPParameterValue.h */ //Required for Globals API doc

/** Supported parameter types for the @c AGSGeoprocessor.
 @since 1.0
 */
typedef enum {
    AGSGPParameterTypeBoolean = 0,				/*!< Parameter must be of type @c NSValue					*/
    AGSGPParameterTypeDouble,					/*!< Parameter must be of type @c NSNumber					*/
    AGSGPParameterTypeLong,						/*!< Parameter must be of type @c NSNumber					*/
    AGSGPParameterTypeString,					/*!< Parameter must be of type @c NSString					*/
    AGSGPParameterTypeLinearUnit,				/*!< Parameter must be of type @c AGSGPLinearUnit */
    AGSGPParameterTypeFeatureRecordSetLayer,	/*!< Parameter must be of type @c AGSFeatureSet				*/
    AGSGPParameterTypeRecordSet,				/*!< Parameter must be of type @c AGSFeatureSet				*/
    AGSGPParameterTypeDataFile,					/*!< Parameter must be of type @c NSURL						*/
    AGSGPParameterTypeDate,						/*!< Parameter must be of type @c NSDate					*/
    AGSGPParameterTypeRasterData,				/*!< Parameter must be of type @c AGSGPRasterData */
    AGSGPParameterTypeRasterDataLayer,			/*!< Parameter must be of type @c AGSGPRasterData */
	AGSGPParameterTypeMultiValue				/*!< Parameter must be of type @c NSArray					*/
} AGSGPParameterType;

#pragma mark -

/** @brief An input/ouptut parameter of a geoprocessing task. 
 
 Instances of this class respresent input/output parameters of a geoprocessing 
 task. 
 
 @define{AGSGPParameterValue.h, ArcGIS}
 @since 1.0
 */
@interface AGSGPParameterValue : NSObject <AGSCoding>

/** Data type of the parameter. Possible types include
 
 @li @c AGSGPParameterTypeBoolean
 @li @c AGSGPParameterTypeDouble 
 @li @c AGSGPParameterTypeLong 
 @li @c AGSGPParameterTypeString 
 @li @c AGSGPParameterTypeLinearUnit 
 @li @c AGSGPParameterTypeFeatureRecordSetLayer
 @li @c AGSGPParameterTypeRecordSet
 @li @c AGSGPParameterTypeDataFile 
 @li @c AGSGPParameterTypeDate 
 @li @c AGSGPParameterTypeRasterData 
 @li @c AGSGPParameterTypeRasterDataLayer
 @li @c AGSGPParameterTypeMultiValue
 
 @since 1.0
 */
@property (nonatomic, readonly) AGSGPParameterType type;

/** Name of the parameter.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Value of the parameter. The data structure of this value depends on the #type.
 
 <table style="border-width:2px; border-style:solid; border-color: #84B0C7">
 <tr><td class="indexkey">Type</td> <td class="indexkey">Value</td></tr>
 <tr><td>@li @c AGSGPParameterTypeBoolean </td><td>@c NSValue</td></tr>
 <tr><td>@li @c AGSGPParameterTypeDouble  </td><td>@c NSNumber</td></tr>
 <tr><td>@li @c AGSGPParameterTypeLong  </td><td>@c NSNumber</td></tr>
 <tr><td>@li @c AGSGPParameterTypeString  </td><td>@c NSString</td></tr>
 <tr><td>@li @c AGSGPParameterTypeLinearUnit  </td><td>@c AGSGPLinearUnit</td></tr>
 <tr><td>@li @c AGSGPParameterTypeFeatureRecordSetLayer </td><td>@c AGSFeatureSet</td></tr>
 <tr><td>@li @c AGSGPParameterTypeRecordSet </td><td>@c AGSFeatureSet</td></tr>
 <tr><td>@li @c AGSGPParameterTypeDataFile  </td><td>@c NSURL</td></tr>
 <tr><td>@li @c AGSGPParameterTypeDate  </td><td>@c NSDate</td></tr>
 <tr><td>@li @c AGSGPParameterTypeRasterData  </td><td>@c AGSGPRasterData</td></tr>
 <tr><td>@li @c AGSGPParameterTypeRasterDataLayer </td><td>@c AGSGPRasterData</td></tr>
 <tr><td>@li @c AGSGPParameterTypeMultiValue </td><td>@c NSArray</td></tr>
 </table>
 
 */
@property (nonatomic, strong, readonly) id value;

/** Initialize an <code>AGSGPParameterValue</code> object.
 @param name The name of the parameter.
 @param type The type of the parameter.
 @param value The value of the parameter.
 @return A new geoprocessing parameter object.
 @since 1.0
 */
- (id)initWithName:(NSString*)name type:(AGSGPParameterType)type value:(id)value;

/** Initialize an <code>AGSGPParameterValue</code> object.
 @param name The name of the parameter.
 @param type The type of the parameter.
 @param value The value of the parameter.
 @return A new, autoreleased, geoprocessing parameter object.
 @since 1.0
 */
+ (id)parameterWithName:(NSString*)name type:(AGSGPParameterType)type value:(id)value;

@end
