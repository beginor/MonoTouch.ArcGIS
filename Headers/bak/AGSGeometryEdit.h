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

@class AGSPoint;
@class AGSGeometry;

/** Specifies the type of geometry edit.
 @since 1.8
 */
typedef enum{
	AGSGeometryEditTypeMoveVertex = 0,
	AGSGeometryEditTypeDeleteVertex,
	AGSGeometryEditTypeInsertVertex,
	AGSGeometryEditTypeClear,
	AGSGeometryEditTypeApplyGeometry,
	AGSGeometryEditTypeInsertPart,
	AGSGeometryEditTypeRemovePart
}AGSGeometryEditType;

/** @brief An object that encapsulates properties of a geometry edit.
 
 @define{AGSGeometryEdit.h, ArcGIS}
 @since 1.8
 */
@interface AGSGeometryEdit : NSObject{
@private
	AGSGeometryEditType _type;
	int _coordinateIndex;
	int _partIndex;
	AGSPoint *_vertexBefore;
	AGSPoint *_vertexAfter;
	NSArray *_partVertices;
	AGSGeometry *_geometryBefore;
	AGSGeometry *_geometryAfter;
	
	AGSPoint *_selectedVertexBefore;
	AGSPoint *_selectedVertexAfter;
}

/** The type of geometry edit.
 @since 1.8
 */
@property (nonatomic, assign, readonly) AGSGeometryEditType type;

/** The index of the coordinate affected by the geometry edit, if applicable.
 @since 1.8
 */
@property (nonatomic, assign, readonly) int coordinateIndex;

/** The index of the part affected by the geometry edit, if applicable.
 @since 1.8
 */
@property (nonatomic, assign, readonly) int partIndex;

/** The vertex before the edit, if applicable.
 @since 1.8
 */
@property (nonatomic, retain, readonly) AGSPoint *vertexBefore;

/** The vertex after the edit, if applicable.
 @since 1.8
 */
@property (nonatomic, retain, readonly) AGSPoint *vertexAfter;

/** The part before it was removed, or the part that was inserted. Only applicable for the 
 remove part edit type and insert part edit type.
 @since 1.8
 */
@property (nonatomic, retain, readonly) NSArray *partVertices;

/** The geometry before it was cleared, or new geometry was applied.
 Only applicable for the clear geometry edit type and apply geometry edit type.
 @since 1.8
 */
@property (nonatomic, copy, readonly) AGSGeometry *geometryBefore;

/** The geometry after a new geometry was applied.
 Only applicable for the apply geometry edit type.
 @since 1.8
 */
@property (nonatomic, copy, readonly) AGSGeometry *geometryAfter;

/** The vertex that was selected before the edit.
 @since 1.8
 */
@property (nonatomic, retain, readonly) AGSPoint *selectedVertexBefore;

/** The vertex that was selected after the edit.
 @since 1.8
 */
@property (nonatomic, retain, readonly) AGSPoint *selectedVertexAfter;

/** Returns the opposite edit, used for undo/redo.
 @since 1.8
 */
-(AGSGeometryEdit*)oppositeEdit;

/** Returns an action name for the geometry edit type. Used for undo/redo.
 @since 1.8
 */
-(NSString*)actionName;
@end
