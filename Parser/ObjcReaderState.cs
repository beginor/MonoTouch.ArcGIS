namespace Parser {

	public enum ObjcReaderState {
		CommentStart,
		Comment,
		CommentEnd,
		ProtocolAlias,
		ClassAlias,
		InterfaceDefineBlock,
		PropertyDefine,
		MethodDefine,
		EnumStart,
		EnumEnd
	}
}