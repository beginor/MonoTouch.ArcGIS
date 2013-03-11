using NUnit.Framework;
using Parser;

namespace Test {

	[TestFixture]
	public class ObjcInterfaceTokenTest {

		[Test]
		public void TestWithParent() {
			var token = new ObjcInterfaceToken("@interface AGSAttachment : NSObject ");
			Assert.AreEqual("AGSAttachment", token.Name);
			Assert.AreEqual("NSObject", token.Parent);
			Assert.IsNull(token.Protocols);
		}

		[Test]
		public void TestWithParentAndProtocol() {
			var token = new ObjcInterfaceToken("@interface AGSAddressCandidate : NSObject <AGSCoding>");
			Assert.AreEqual("AGSAddressCandidate", token.Name);
			Assert.AreEqual("NSObject", token.Parent);
			Assert.AreEqual(token.Protocols.Length, 1);
			Assert.AreEqual("AGSCoding", token.Protocols[0]);
		}

		[Test]
		public void TestWithParentAndProtocols() {
			var token = new ObjcInterfaceToken("@interface AGSClassBreak : NSObject <AGSCoding, NSCopying> {");
			Assert.AreEqual("AGSClassBreak", token.Name);
			Assert.AreEqual("NSObject", token.Parent);
			Assert.AreEqual(token.Protocols.Length, 2);
			Assert.AreEqual("AGSCoding", token.Protocols[0]);
			Assert.AreEqual("NSCopying", token.Protocols[1]);
		}

	}
}