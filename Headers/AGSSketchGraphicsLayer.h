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

/** @file AGSSketchGraphicsLayer.h */ //Required for Globals API doc

@class AGSGeometry;
@class AGSGraphic;
@class AGSCompositeSymbol;
@class AGSMarkerSymbol;
@class AGSGraphicsLayer;
@class AGSPoint;
@class AGSMapView;
@protocol AGSMapViewTouchDelegate;

/** Notification that indicates that the geometry of @c AGSSketchGraphicsLayer changed.
 @since 10.1.1
 */
AGS_EXTERN NSString *const AGSSketchGraphicsLayerGeometryDidChangeNotification;

/** @brief A layer that allows the user to sketch geometries on the map.
 
 A layer that allows the user to interactively sketch geometries on the map.
 You can skech point, polygon, and polyline geometries from scratch,
 modify existing geometries, insert and remove vertices, undo and redo changes, and so on.
 
 <h3>Notifications</h3>
 The layer posts @c #AGSSketchGraphicsLayerGeometryDidChangeNotification when its geometry changes.
 
 @see @concept{Sketch_Layer/00pw00000052000000/, Using a Sketch Layer}
 @see @sample{5106817cf79f44c99f8045e2d705f279, Sketch Layer}
 @since 1.8
 */
@interface AGSSketchGraphicsLayer : AGSGraphicsLayer <AGSMapViewTouchDelegate>

/** The geometry that is populated as the user sketches.
 Must be a mutable geometry because it will be modified by the layer
 while the user is sketching.
 @since 1.8
 */
@property (nonatomic, strong) AGSGeometry *geometry;

/** Composite symbol that contains the symbology for drawing the lines
 and fills for what the user sketches.
 @since 1.8
 */
@property (nonatomic, strong, readwrite) AGSCompositeSymbol *mainSymbol;

/** Symbol used to display the selected vertex.
 @since 1.8
 */
@property (nonatomic, strong, readwrite) AGSMarkerSymbol *selectedVertexSymbol;

/** Symbol used to display the vertices.
 @since 1.8
 */
@property (nonatomic, strong, readwrite) AGSMarkerSymbol *vertexSymbol;

/** Symbol to display the mid vertices.
 @since 1.8
 */
@property (nonatomic, strong, readwrite) AGSMarkerSymbol *midVertexSymbol;

/** The undo manager.
 @since 1.8
 */
@property (nonatomic, strong, readonly) NSUndoManager *undoManager;

/** Initializes an AGSSketchGraphicsLayer.
 @param geometry The geometry that will be modified as the user sketches. This geometry must be mutable.
 @since 1.8
 */
-(id)initWithGeometry:(AGSGeometry*)geometry;

/** Removes the selected vertex.
 @return Boolean value that specifies if the remove succeeded.
 @since 1.8
 */
-(BOOL)removeSelectedVertex;

/** Remove a vertex in a specified part and index.
 @param partIndex The index of the part to remove the vertex.
 @param coordinateIndex The index of the coordinate to remove.
 @since 1.8
 */
-(void)removeVertexInPart:(NSInteger)partIndex atIndex:(NSInteger)coordinateIndex;

/** Add a part to the geometry
 @since 1.8
 */
-(void)addPart;

/** Removes a part at a specified index.
 @param partIndex Index of the part to remove.
 @since 1.8
 */
-(void)removePartAtIndex:(NSInteger)partIndex;

/** Removes the selected part.
 @return Boolean value that specifies if the remove succeeded.
 @since 1.8
 */
-(BOOL)removeSelectedPart;

/** Clears the current geometry.
 @since 1.8
 */
-(void)clear;

/** Applies the passed in geometry to the current geometry. These
 geometries must be matching in type.
 @since 1.8
 */
-(void)applyGeometry:(AGSGeometry*)geometry;

/** Inserts a vertex in a specfied part and index.
 @param point The vertex to insert.
 @param partIndex The index of the part to insert the point.
 @param coordinateIndex The index of the coordinate at which to insert the point.
 @since 1.8
 */
-(void)insertVertex:(AGSPoint*)point inPart:(NSInteger)partIndex atIndex:(NSInteger)coordinateIndex;

/** Moves a vertex to a specified location.
 @param partIndex The index of the part to insert the point.
 @param coordinateIndex The index of the coordinate at which to insert the point.
 @param point The location to move the point to.
 @since 1.8
 */
-(void)moveVertexInPart:(NSInteger)partIndex atIndex:(NSInteger)coordinateIndex toPoint:(AGSPoint*)point;

/** Selects the last vertex in the geometry.
 @since 1.8
 */
-(void)selectLastVertex;

/** The method that is called when a user clicks on the map.
 @since 1.8
 */
-(void)mapView:(AGSMapView *)mapView didClickAtPoint:(CGPoint)screen mapPoint:(AGSPoint *)mappoint graphics:(NSDictionary *)graphics;

/** The method that is called when a user ends a tap and hold on the map.
 @since 1.8
 */
-(void)mapView:(AGSMapView *)mapView didEndTapAndHoldAtPoint:(CGPoint)screen mapPoint:(AGSPoint *)mappoint graphics:(NSDictionary *)graphics;	

/** The default main symbol for sketch graphics layers, this symbol is used for the lines and fills.
 @since 1.8
 */
+(AGSCompositeSymbol*)defaultMainSymbol;

/** The default selected vertex symbol for sketch graphics layers.
 @since 1.8
 */
+(AGSMarkerSymbol*)defaultSelectedVertexSymbol;

/** The default symbol used to display the vertices for sketch graphics layers.
 @since 1.8
 */
+(AGSMarkerSymbol*)defaultVertexSymbol;

/** The default symbol to display the mid vertices for sketch graphics layers.
 @since 1.8
 */
+(AGSMarkerSymbol*)defaultMidVertexSymbol;

@end
