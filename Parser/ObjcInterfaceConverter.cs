using System.CodeDom;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Parser {

	public class ObjcInterfaceConverter : ObjcConverter {

		public ObjcInterfaceConverter(ObjcToken token)
			: base(token) {
		}

		public override string Convert() {
			var result = new StringBuilder();
			var token = (ObjcInterfaceToken)this.Token;
			var baseType = string.Format("[BaseType(typeof({0}))]", token.Parent);
			result.AppendLine(baseType);
			result.AppendFormat("public interface {0} ", token.Name);
			if (token.Protocols.Length > 0) {
				result.Append(": ");
				result.Append(string.Join(", ", token.Protocols));
			}
			result.AppendLine(" {");
			//result.Add(string.Format("public interface "));
			//var result = new CodeTypeDeclaration {
			//	IsInterface = true
			//};

			//foreach (var methodToken in token.Members) {
			//	var methodConverter = methodToken.CreateConverter();
			//	var method = (CodeTypeMember)methodConverter.Convert();
			//	result.Members.Add(method);
			//}
			//return result;
			foreach (var member in token.Members) {
				var memberCode = member.CreateConverter().Convert();
				result.Append(memberCode);
			}
			result.AppendLine("}");
			return result.ToString();
		}
	}
}