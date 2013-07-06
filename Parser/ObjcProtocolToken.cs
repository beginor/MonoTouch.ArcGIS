using System;
using System.Collections.Generic;

namespace Parser {

	public class ObjcProtocolToken : ObjcToken {

		public IList<ObjcMemberToken> Members { get; private set; }

		public string[] Parents { get; private set; }

		public string Name { get; private set; }

		public ObjcProtocolToken(string code) : base(code) {
			//@protocol AGSNetworkActivityDelegate <NSObject>
			this.Members = new List<ObjcProtocolMethodToken>();
			this.AnalysisCode();
		}

		void AnalysisCode() {
			var code = this.Code.TrimTabAndWhitespace();
			var start = "@protocol".Length;
			code = code.Substring(start).TrimTabAndWhitespace();
			var ltIndex = code.IndexOf('<');
			if (ltIndex > 0) {
				this.Name = code.Substring(0, ltIndex);
			}
			else {
				this.Name = code.Trim();
			}
		}

		public override ObjcConverter CreateConverter() {
			return new ObjcProtocolConverter(this);
		}

	}

}