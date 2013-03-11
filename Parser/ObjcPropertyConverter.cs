using System;
using System.CodeDom;
using System.Text;

namespace Parser {

	public class ObjcPropertyConverter : ObjcConverter {

		public ObjcPropertyConverter(ObjcPropertyToken token) : base(token) { }

		public override string Convert() {
			var propToken = (ObjcPropertyToken)this.Token;

			var sb = new StringBuilder();
			var comment = string.Format("/// <summary>{0}</summary>", propToken.Code);
			sb.AppendLine(comment);
			// export attr for prop
			var expor = string.Format("[Export(\"{0}\"), ArgumentSemantic.{1}]", propToken.PropertyName, ToCsharpPropertyName(propToken.Semantic));
			sb.AppendLine(expor);
			sb.Append(propToken.PropertyType + " ");
			sb.Append(" { ");
			if (propToken.Getter.IsNotNullOrWhiteSpace()) {
				sb.AppendFormat("[Export(\"{0}\")]", propToken.Getter);
			}
			sb.Append("get; ");
			if (!propToken.IsReadOnly) {
				if (propToken.Setter.IsNotNullOrWhiteSpace()) {
					sb.AppendFormat("[Export(\"{0}\")]", propToken.Setter);
				}
				sb.Append("set; ");
			}
			sb.AppendLine(" } ");
			return sb.ToString();
		}

		static string ToCsharpPropertyName(string objcPropName) {
			return objcPropName.Substring(0, 1).ToUpperInvariant() + objcPropName.Substring(1);
		}
	}

}

