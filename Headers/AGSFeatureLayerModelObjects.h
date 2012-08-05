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

#import <Foundation/Foundation.h>

@protocol AGSCoding;
@protocol AGSQueryTaskDelegate;
@protocol AGSFeatureLayerEditingDelegate;
@protocol AGSFeatureLayerQueryDelegate;
@protocol AGSInfoTemplateDelegate;

@class AGSLayer;
@class AGSDynamicLayer;
@class AGSGraphicsLayer;

@class AGSField;
@class AGSQueryTask;
@class AGSQuery;
@class AGSGraphic;
@class AGSSymbol;
@class AGSFeatureType;
@class AGSFeatureTemplate;
@class AGSFeatureLayer;
@class AGSFeatureLayerModeModule;

/** @file AGSFeatureLayerModelObjects.h */ //Required for Globals API doc

#pragma mark -

/** @brief Encapsulates properties of types of features in a feature layer.

 Instances of this class represent a feature type. A feature type describes the
 various types of features that can belong to a feature layer.
 @since 1.0
 @see <a href="http://help.arcgis.com/en/arcgisdesktop/10.0/help/index.html#//005r00000001000000.htm"> A quick
 tour of subtypes</a>
 */
@interface AGSFeatureType : NSObject <AGSCoding> {
 @private
    id _typeId;
    NSString *_name;
    NSArray *_templates;
    NSDictionary *_domains;
	NSArray *_parentFields;
}

/** The ID of this type.
 @since 1.0
 */
@property (nonatomic, copy, readonly) id typeId;

/** The name of this type.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSString *name;

/** Temlates that can be used for creating new features of this type.
 This property is an array of @c AGSFeatureTemplate objects.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSArray *templates;

/** Domains describing permissible attribute values for features of this type.
 This property is a dictionary containing key-value pairs of field name and a 
 corresponding @c AGSDomain object for this type.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSDictionary *domains;

/** Initialize an <code>AGSFeatureType</code> with json representation and an
 array of parent fields. The parent fields are important in cases where properties
 are inherited from the parent field.
 @param json The JSON representation of an <code>AGSFeatureType</code>.
 @param parentFields Array of @c AGSField objects corresponding to
 @c AGSFeatureLayer 's <code>fields</code>.
 @return The feature type object.
 @since 1.0
 */
-(id)initWithJSON:(NSDictionary *)json parentFields:(NSArray*)parentFields;

@end



#pragma mark -

/** @brief An object representing the relationship between two layers/tables.
 
 Instances of this class represent a relationship between a @em source and a 
 @em target. The source could either be a layer or a table. The target could 
 also be either a layer or a table.
 @since 1.0
 */
@interface AGSRelationship : NSObject <AGSCoding> {
 @private
    NSInteger _relationshipId;
    NSString *_name;
    NSInteger _relatedTableId;
}

/** ID of the relationship.
 @since 1.0
 */
@property (nonatomic, readonly) NSInteger relationshipId;

/** Name of the relationship. Usually describes how the source and target are 
 related.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSString *name;

/** The ID of the layer/table which is the target of this relationship.
 @since 1.0
 */
@property (nonatomic, readonly) NSInteger relatedTableId;

@end




#pragma mark -

/** @brief Represents all of the information needed to create a feature.
 
 Instances of this class represent a feature template. A feature template
 defines all the information required to create a feature: the layer where a
 feature will be stored and the attributes a feature is created with.
 
 @since 1.0
 */
@interface AGSFeatureTemplate : NSObject <AGSCoding> {
 @private
    NSString *_name;
    NSString *_featureDescription;
    AGSGraphic *_prototype;
}

/** Name of the template.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSString *name;

/** Description of the template.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSString *featureDescription;

/** A prototypical feature associated with the template which can be used to 
 easily create new features. The prototype specifies default values for the 
 feature's attributes, however, it does not contain a geometry.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSGraphic *prototype;

@end



#pragma mark -

/** @brief An attribute domain.
 
 Instances of this class represent attribute domains. Domains are a set of 
 rules that describe the legal values for a field. Domains provide a way to 
 constrain attribute values and enforce data integrity.
 
 @since 1.0
 */
@interface AGSDomain : NSObject <AGSCoding> {
 @private
    NSString *_name;
}

/** Name of the domain.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSString *name;

/** Initialize an <code>AGSDomain</code> with JSON representation and a parent
 field. The parent field is important in cases where properties
 are inherited from the parent field.
 @param json The JSON representation of a domain.
 @param parentField @c AGSField corresponding to one of <code>AGSFeatureLayer</code>'s 
 <code>fields</code>.
 @return A new, autoreleased, domain.
 @since 1.0
 */
+(id)domainWithJSON:(NSDictionary*)json parentField:(AGSField*)parentField;

@end

#pragma mark -

/** @brief Represents a coded-value domain.
 
 Instances of this class represent a coded-value domain. Coded-value domains 
 specify a valid set of values for an attribute. For example, Airport features 
 may have a @em category attribute that can only have "international", 
 "domestic", or "military" values.
 @since 1.0
 */
@interface AGSCodedValueDomain : AGSDomain {
 @private
    NSArray *_codedValues;
}

/** The valid set of values permitted by this domain. This property is an array 
 of @c AGSCodedValue objects.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSArray *codedValues;

@end

#pragma mark -

/** @brief Represents coded values of @c AGSCodedValueDomain. 
 
 Instances of this class represent coded values of @c AGSCodedValueDomain.
 @since 1.0
 */
@interface AGSCodedValue : NSObject <AGSCoding> {
 @private
    NSString *_name;
    id _code;
}

/** A user-friendly name of the coded value.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSString *name;

/** The actual value of the coded value. The data type of the value depends upon 
 the data type of the field it is associated with.
 @since 1.0
 */
@property (nonatomic, retain, readonly) id code;

@end

#pragma mark -

/** @brief An object representing a range domain.
 
 Instances of this class represent a range domain. Range domains specify a 
 valid range of values for an attribute. For example, Gas Pipe features may have 
 a @em pressure attributethat can only have values between 5 and 10 psi.
 @since 1.0
 */
@interface AGSRangeDomain : AGSDomain {
 @private
    NSNumber *_minValue;
    NSNumber *_maxValue;
}

/** The lower limit for the valid range of values.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSNumber *minValue;

/** The upper limit for the valid range of values.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSNumber *maxValue;

@end

#pragma mark _

/** List of supported <code>%AGSFieldType</code>'s
 @since 1.0
 */
typedef enum {
    AGSFieldTypeInteger = 0,        /*!<  */
    AGSFieldTypeSmallInteger,       /*!<  */
	AGSFieldTypeDouble,             /*!<  */
	AGSFieldTypeSingle,             /*!<  */
	AGSFieldTypeString,             /*!<  */
	AGSFieldTypeDate,               /*!<  */
	AGSFieldTypeGeometry,           /*!<  */
	AGSFieldTypeOID,                /*!<  */
	AGSFieldTypeBlob,               /*!<  */
	AGSFieldTypeGlobalID,           /*!<  */
	AGSFieldTypeRaster,             /*!<  */
	AGSFieldTypeGUID,               /*!<  */
	AGSFieldTypeXML                 /*!<  */
} AGSFieldType;


#pragma mark -

/** @brief An object that represents information about a layer.
 
 Instances of this class represent information about each field in a layer.
 @since 1.0
 */
@interface AGSField : NSObject <AGSCoding> {
 @private
    NSString *_name;
    AGSFieldType _type;
    NSString *_alias;
    AGSDomain *_domain;
	int _length;
	BOOL _editable;
}

/** Name of the field.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSString *name;

/** Type of values in the field. Possible field types include
 
 @li @c AGSFieldTypeInteger
 @li @c AGSFieldTypeSmallInteger
 @li @c AGSFieldTypeDouble
 @li @c AGSFieldTypeSingle
 @li @c AGSFieldTypeString
 @li @c AGSFieldTypeDate
 @li @c AGSFieldTypeGeometry
 @li @c AGSFieldTypeOID
 @li @c AGSFieldTypeBlob
 @li @c AGSFieldTypeGlobalID
 @li @c AGSFieldTypeRaster
 @li @c AGSFieldTypeGUID
 @li @c AGSFieldTypeXML
 
 @since 1.0
 */
@property (nonatomic, assign, readonly) AGSFieldType type;

/** Alias name of the field. Alias name is usually more user friendly than the 
 actual field name which may use underlying datasource naming conventions.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSString *alias;

/** The domain limiting values to a range or a set of codes for the field.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSDomain *domain;

/** Indicates whether the field is editable.
 @since 1.0
 */
@property (nonatomic, assign, readonly) BOOL editable;

/** The field length.
 @since 1.0
 */
@property (nonatomic, assign, readonly) int length;

@end