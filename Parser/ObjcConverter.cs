using System;
using System.CodeDom;

namespace Parser {

	public abstract class ObjcConverter {

		public ObjcToken Token {
			get;
			private set;
		}

		protected ObjcConverter(ObjcToken token) {
			this.Token = token;
		}

		public abstract string Convert();

	}
}

