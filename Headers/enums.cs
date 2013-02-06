
public enum AGSAttachmentEditState {
	Original = 0,		
	Added,			
	MarkedForDeletion,
	DeletedFromServer 
}

public enum AGSBingMapLayerStyle {
	Aerial,
	AerialWithLabels,
	Road
}

[Flag]
public enum AGSCalloutLeaderPosition {
	Bottom = 1UL << 0,
	Top = 1UL << 1,
	Left = 1UL << 2,
	Right = 1UL << 3,
	Any = Bottom | Top | Left | Right
}