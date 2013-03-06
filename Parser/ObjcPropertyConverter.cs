using System;
using System.CodeDom;

namespace Parser {

	public class ObjcPropertyConverter : ObjcConverter {

		public ObjcPropertyConverter(ObjcPropertyToken token) : base(token) {}

		public override CodeObject Convert() {
			CodeMemberProperty property = new CodeMemberProperty();
			return property;
		}

	}

}

