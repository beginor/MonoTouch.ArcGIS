using System;
using System.Collections.Generic;

namespace Parser {

	public class ObjcEnumToken : ObjcToken {

		public string Name {
			get;
			private set;
		}

		public IList<string> Fields {
			get;
			private set;
		}

		public ObjcEnumToken(string code) : base(code) {
			this.Fields = new List<string>();
		}

		public override ObjcConverter CreateConverter() {
			return new ObjcEnumConverter(this);
		}

	}

}