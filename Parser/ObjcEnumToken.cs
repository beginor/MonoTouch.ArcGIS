using System;
using System.Collections.Generic;

namespace Parser {

	public class ObjcEnumToken : ObjcToken {

		string _name;

		public string Name {
			get {
				return _name;
			}
			set {
				var val = value;
				if (val.StartsWith("}")) {
					val = val.Substring(1);
				}
				if (val.EndsWith(";")) {
					val = val.Substring(0, val.Length - 1);
				}
				val = val.TrimTabAndWhitespace();
				_name = val;
			}
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

		public void AddField(string field) {
			var f = field.TrimTabAndWhitespace();
			this.Fields.Add(f);
		}

	}

}