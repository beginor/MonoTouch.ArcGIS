using System;
using System.Text;

namespace Parser {

	public class ObjcPropertyConverter : ObjcConverter {

		public ObjcPropertyConverter(ObjcPropertyToken token) : base(token) {
		}

		public override string Convert() {
			var propToken = (ObjcPropertyToken)this.Token;

			var csBuilder = new StringBuilder();
			var comment = string.Format("/// <summary>{0}</summary>", propToken.Code);
			csBuilder.AppendLine(comment);
			// export attr for prop
			var expor = string.Format("[Export(\"{0}\"), ArgumentSemantic.{1}]", propToken.PropertyName, ToCsharpPropertyName(propToken.Semantic));
			csBuilder.AppendLine(expor);
			csBuilder.Append(TypeMap.GetTypeFor(propToken.PropertyType) + " ");
			csBuilder.Append(" { ");
			if (propToken.Getter.IsNotNullOrWhiteSpace()) {
				csBuilder.AppendFormat("[Export(\"{0}\")]", propToken.Getter);
			}
			csBuilder.Append("get; ");
			if (!propToken.IsReadOnly) {
				if (propToken.Setter.IsNotNullOrWhiteSpace()) {
					csBuilder.AppendFormat("[Export(\"{0}\")]", propToken.Setter);
				}
				csBuilder.Append("set; ");
			}
			csBuilder.AppendLine(" } ");
			return csBuilder.ToString();
		}

		static string ToCsharpPropertyName(string objcPropName) {
			return objcPropName.Substring(0, 1).ToUpperInvariant() + objcPropName.Substring(1);
		}
	}

}

