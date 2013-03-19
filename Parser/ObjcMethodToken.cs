using System.Collections.Generic;

namespace Parser {

	public class ObjcMethodToken : ObjcMemberToken {

		public string Name {
			get;
			private set;
		}

		public string ReturnType {
			get;
			private set;
		}

		public IList<KeyValuePair<string,string>> Parameters {
			get;
			private set;
		}

		public bool IsStatic {
			get;
			private set;
		}

		public bool IsConstructor {
			get {
				return (!this.IsStatic) && this.ReturnType == "id" && this.Name.StartsWith("init");
			}
		}

		public ObjcMethodToken(string code) : base(code) {
			this.AnalysisCode();
		}

		private void AnalysisCode() {
			//+ (id)closestFacilityTaskWithURL:(NSURL *)url credential:(AGSCredential*)cred;
			var code = base.Code.Trim('\t', ' ');
			if (!(code.StartsWith("+") || code.StartsWith("-")) && !code.EndsWith(";")) {
				throw new ObjcTokenException("Invalid Method code " + code);
			}
			code = code.Substring(0, code.Length - 1);

			this.IsStatic = code.StartsWith("+");

			// return type
			var startIndex = code.IndexOf('(') + 1;
			var endIndex = code.IndexOf(')');
			this.ReturnType = code.Substring(startIndex, endIndex - startIndex);

			//method name and params
			//closestFacilityTaskWithURL:(NSURL *)url credential:(AGSCredential*)cred;
			this.Parameters = new List<KeyValuePair<string, string>>();
			this.Name = string.Empty;

			code = code.Substring(endIndex + 1);
			if (code.IndexOf(':') > 0) {
				this.GetMethodNameAndParameters(code);
			}
			else {
				this.Name = code;
			}
		}

		private void GetMethodNameAndParameters(string code) {
			var namePartEndIndex = code.IndexOf(':') + 1;
			this.Name += code.Substring(0, namePartEndIndex);

			code = code.Substring(namePartEndIndex).Trim(new[] { ' ', '\t' });
			var paramStartIndex = code.IndexOf('(') + 1;
			var paramEndIndex = code.IndexOf(')');
			var parameterType = code.Substring(paramStartIndex, paramEndIndex - paramStartIndex);
			if (parameterType.EndsWith("*")) {
				parameterType = parameterType.Substring(0, parameterType.Length - 1).Trim();
			}

			code = code.Substring(paramEndIndex + 1).Trim(new[] { ' ', '\t' });
			var paramNameEndIndex = code.IndexOf(' ');
			var paramName = paramNameEndIndex > 0 ? code.Substring(0, paramNameEndIndex) : code;

			this.Parameters.Add(new KeyValuePair<string, string>(parameterType, paramName));

			code = code.Substring(paramNameEndIndex + 1).Trim(new[] { ' ', '*' });

			if (code.IndexOf(':') > 0) {
				this.GetMethodNameAndParameters(code);
			}
		}

		public override ObjcConverter CreateConverter() {
			return new ObjcMethodConverter(this);
		}

	}
}

