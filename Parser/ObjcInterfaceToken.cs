using System.Collections.Generic;

namespace Parser {

	public class ObjcInterfaceToken : ObjcToken {

		public IList<ObjcMemberToken> Members { get; private set; }

		public ObjcInterfaceToken(string code) : base(code) {
			this.Members = new List<ObjcMemberToken>();
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