namespace Parser {

	public class ObjcInterfaceToken : ObjcToken {

		public ObjcInterfaceToken(string code) : base(code) {
		}

		public override ObjcConverter CreateConverter() {
			return new ObjcInterfaceConverter(this);
		}
	}
}