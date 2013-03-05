using System.CodeDom;

namespace Parser {

	public class ObjcInterfaceConverter : ObjcConverter {

		public ObjcInterfaceConverter(ObjcToken token)
			: base(token) {
		}

		public override CodeObject Convert() {
			var token = (ObjcInterfaceToken)this.Token;
			var result = new CodeTypeDeclaration {
				IsInterface = true
			};

			foreach (var propertyToken in token.Properties) {
				var propertyConverter = propertyToken.CreateConverter();
				var property = (CodeTypeMember)propertyConverter.Convert();
				result.Members.Add(property);
			}

			foreach (var methodToken in token.Methods) {
				var methodConverter = methodToken.CreateConverter();
				var method = (CodeTypeMember)methodConverter.Convert();
				result.Members.Add(method);
			}
			return result;
		}
	}
}