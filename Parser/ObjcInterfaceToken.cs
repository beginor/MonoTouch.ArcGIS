using System.Collections.Generic;

namespace Parser {

	public class ObjcInterfaceToken : ObjcToken {

		public string Name { get; private set; }

		public string Parent { get; private set; }

		public string[] Protocols { get; private set; }

		public IList<ObjcMemberToken> Members { get; private set; }

		public ObjcInterfaceToken(string code) : base(code) {
			this.Members = new List<ObjcMemberToken>();
			this.AnalysisCode();
		}

		private void AnalysisCode() {
			var code = this.Code;
			if (code.EndsWith("{")) {
				code = code.Substring(0, code.Length - 1);
				code = code.Trim();
			}
			// skip @interface
			var start = "@interface".Length;
			code = code.Substring(start).Trim();
			var colonIndex = code.IndexOf(':');
			this.Name = code.Substring(0, colonIndex).Trim();
			//@interface MyInterface : Base <Protos, Protos> {
			var ltIndex = code.IndexOf('<');
			if (ltIndex > -1) {
				this.Parent = code.Substring(colonIndex + 1, ltIndex - colonIndex - 1).Trim();
				var gtIndex = code.IndexOf('>');
				this.Protocols = code.Substring(ltIndex + 1, gtIndex - ltIndex - 1).Split(',');
				for (var index = 0; index < this.Protocols.Length; index++) {
					var protocol = this.Protocols[index];
					this.Protocols[index] = protocol.Trim();
				}
			}
			else {
				this.Parent = code.Substring(colonIndex + 1).Trim();
			}
		}

		public void AddMember(string memberDefine) {
			if (memberDefine.StartsWith("@property")) {
				this.Members.Add(new ObjcPropertyToken(memberDefine));
			}
			else {
				this.Members.Add(new ObjcMethodToken(memberDefine));
			}
		}

		public override ObjcConverter CreateConverter() {
			return new ObjcInterfaceConverter(this);
		}
	}
}