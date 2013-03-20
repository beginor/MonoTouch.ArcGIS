using System;
using System.Linq;
using System.Collections.Generic;

namespace Parser {

	public class ObjcPropertyToken : ObjcMemberToken {

		public string PropertyType {
			get;
			private set;
		}

		public string PropertyName {
			get;
			private set;
		}

		public bool IsReadOnly {
			get {
				return this.Attributes.Contains("readonly");
			}
		}

		public string Semantic {
			get {
				if (this.Attributes.Contains("assign") || this.Attributes.Contains("weak")) {
					return "Assign";
				}
				if (this.Attributes.Contains("copy")) {
					return "Copy";
				}
				if (this.Attributes.Contains("retain") || this.Attributes.Contains("strong")) {
					return "Retain";
				}
				return "None";
			}
		}

		public string Getter {
			get {
				return this.FindGetterOrSetterValue("getter=");
			}
		}

		public string Setter {
			get {
				return this.FindGetterOrSetterValue("setter=");
			}
		}

		public IEnumerable<string> Attributes {
			get;
			private set;
		}

		public ObjcPropertyToken(string code) : base(code) {
			this.AnalysisCode();
		}

		private void AnalysisCode() {
			// @property (nonatomic, assign, readonly) BOOL sslRequired;
			var code = base.Code.TrimTabAndWhitespace();
			if (!code.StartsWith("@property")) {
				throw new ObjcTokenException("Objc property must be starts width @property!");
			}
			if (!code.EndsWith(";")) {
				throw new ObjcTokenException("Objc property must be ends with ';'!");
			}

			// attribute between ( and );
			var attrStartIndex = code.IndexOf('(');
			var attrEndIndex = code.IndexOf(')');
			if (attrStartIndex == attrEndIndex) {
				this.Attributes = new string[0];
			} else {
				var attrStr = code.Substring(attrStartIndex + 1, attrEndIndex - (attrStartIndex + 1));
				var attrs = attrStr.Split(new[] { ',' }, StringSplitOptions.RemoveEmptyEntries);
				this.Attributes = attrs.Select(s => s.Trim()).ToArray();
			}

			var typeAndName = code.Substring(attrEndIndex + 1, code.Length - (attrEndIndex + 1) - 1).Trim()
				.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
			if (typeAndName.Length != 2) {
				throw new ObjcTokenException(string.Format("can not parse \"{0}\"", code));
			}
			this.PropertyType = typeAndName[0];
			this.PropertyName = typeAndName[1];
			if (this.PropertyName.StartsWith("*")) {
				this.PropertyName = this.PropertyName.Substring(1).Trim();
			}
		}

		private string FindGetterOrSetterValue(string name) {
			var val = string.Empty;
			var attr = this.Attributes.FirstOrDefault(a => a.StartsWith(name));
			if (attr != null) {
				val = attr.Substring(attr.IndexOf('=') + 1);
			}
			return val;
		}


		public override ObjcConverter CreateConverter() {
			return new ObjcPropertyConverter(this);
		}
	}
}

