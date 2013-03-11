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
			result.AppendFormat("");
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
			return result.ToString();
		}
	}
}