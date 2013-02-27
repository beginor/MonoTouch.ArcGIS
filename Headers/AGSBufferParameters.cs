[BaseType(typeof(NSObject))]
public interface AGSBufferParameters : AGSCoding {

	[Export("bufferSpatialReference", ArgumentSemantic.Retain)]
	AGSSpatialReference BufferSpatialReference { get; set; }

	[Export("distances", ArgumentSemantic.Copy)]
	float[] Distances { get; set; }

	[Export("geometries", ArgumentSemantic.Copy)]
	AGSGeometry[] Geometries { get; set; }

	[Export("outSpatialReference", ArgumentSemantic.Retain)]
	AGSSpatialReference outSpatialReference { get; set; }

	[Export("unionResults", ArgumentSemantic.None)]
	bool UnionResults { get; set; }

	[Static, Export("bufferParameters")]
	AGSBufferParameters BufferParameters();
	
}