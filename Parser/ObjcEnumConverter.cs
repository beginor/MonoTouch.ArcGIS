
using System;
using System.Text;

namespace Parser {

	public class ObjcEnumConverter : ObjcConverter {

		public ObjcEnumConverter(ObjcEnumToken token) : base(token) {
		}

		public override string Convert() {
			var enumToken = (ObjcEnumToken)this.Token;
			var cs = new StringBuilder();
			var enumStart = "public enum " + enumToken.Name + " {";
			cs.AppendLine(enumStart);
			foreach (var field in enumToken.Fields) {
				var csField = field.TrimTabAndWhitespace();
				if (csField.StartsWith(enumToken.Name)) {
					csField = csField.Replace(enumToken.Name, string.Empty);
				}
				cs.AppendLine(csField);
			}
			var enummEnd = "}";
			cs.AppendLine(enummEnd);
			return cs.ToString();
		}

	}
}
