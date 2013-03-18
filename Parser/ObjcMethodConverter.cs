using System;
using System.Linq;
using System.Text;

namespace Parser {

	public class ObjcMethodConverter : ObjcConverter {

		public ObjcMethodConverter(ObjcToken token) : base(token) {
		}

		public override string Convert() {
			var cs = new StringBuilder();

			var token = (ObjcMethodToken)this.Token;

			var summary = string.Format("///<summary>{0}</summary>", token.Code);
			cs.AppendLine(summary);
			var export = string.Format("[Export(\"{0}\")]", token.Name);
			// return type
			cs.AppendFormat("{0} {1}", TypeMap.GetTypeFor(token.ReturnType), ToCsharpMethodName(token.Name));
			cs.Append("(");
			if (token.Parameters.Count > 0) {
				var param = token.Parameters.Aggregate("", (curr, next) => curr + TypeMap.GetTypeFor(next.Key) + " " + next.Value + ",");
				cs.Append(param.Substring(0, param.Length - 1));
			}
			cs.AppendLine(");");

			return cs.ToString();
		}

		private static string ToCsharpMethodName(string ocMethodName) {
			var parts = ocMethodName.Split(new [] { ':' }, StringSplitOptions.RemoveEmptyEntries);
			return parts.Aggregate("", (current, part) => current + (part.Substring(0, 1).ToUpperInvariant() + part.Substring(1)));
		}
	}
}