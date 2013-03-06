using System;

namespace Parser {

	public abstract class ObjcToken {

		public string Code {
			get;
			private set;
		}

		protected ObjcToken(string code) {
			this.Code = code;
		}

		public abstract ObjcConverter CreateConverter();

		public override string ToString() {
			return string.Format("[ObjcToken: Code={0}]", Code);
		}
	}
}

