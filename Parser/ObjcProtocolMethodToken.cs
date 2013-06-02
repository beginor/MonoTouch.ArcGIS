using System;
using System.Collections.Generic;

namespace Parser {

	public class ObjcProtocolMethodToken : ObjcMemberToken {

		public ObjcProtocolMethodToken(string code) : base(code) {
		}

		public override ObjcConverter CreateConverter() {
			throw new NotImplementedException();
		}

	}
	
}