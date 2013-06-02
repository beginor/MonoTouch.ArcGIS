using System;
using System.Collections.Generic;

namespace Parser {

	public class ObjcProtocolToken : ObjcToken {

		public IList<ObjcMemberToken> Members { get; private set; }

		public string[] Parents { get; private set; }

		public string Name { get; private set; }

		public ObjcProtocolToken(string code) : base(code) {
		}

		public override ObjcConverter CreateConverter() {
			throw new NotImplementedException();
		}

	}

}