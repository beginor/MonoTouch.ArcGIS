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

	public class ObjcProtocolMethodToken : ObjcMemberToken {

		public ObjcProtocolMethodToken(string code) : base(code) {
		}

		public override ObjcConverter CreateConverter() {
			throw new NotImplementedException();
		}

	}

	public class ObjcProtocolMethodConverter : ObjcConverter {

		public ObjcProtocolMethodConverter(ObjcToken token) : base(token) {
		}

		public override string Convert() {
			throw new NotImplementedException();
		}
	}

	public class ObjcProtocolConverter : ObjcConverter {

		public ObjcProtocolConverter(ObjcToken token) : base(token) {
		}

		public override string Convert() {
			throw new NotImplementedException();
		}
	}
}