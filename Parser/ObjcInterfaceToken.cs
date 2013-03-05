using System.Collections.Generic;

namespace Parser {

	public class ObjcInterfaceToken : ObjcToken {

		public IList<ObjcPropertyToken> Properties { get; private set; }

		public IList<ObjcMethodToken> Methods { get; private set; }

		public ObjcInterfaceToken(string code) : base(code) {
			this.Properties = new List<ObjcPropertyToken>();
			this.Methods = new List<ObjcMethodToken>();
		}

		public void AddProperty(string propertyDefineCode) {
			this.Properties.Add(new ObjcPropertyToken(propertyDefineCode));
		}

		public void AddMethod(string methodDefineCode) {
			this.Methods.Add(new ObjcMethodToken(methodDefineCode));
		}

		public override ObjcConverter CreateConverter() {
			return new ObjcInterfaceConverter(this);
		}
	}
}