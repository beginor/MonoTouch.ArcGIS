using System;
using System.Linq;
using NUnit.Framework;
using Parser;

namespace Test {

	[TestFixture()]
	public class ObjcTokenTest {

		[Test()]
		public void TestPropertyToken() {
			var token = new ObjcPropertyToken("@property (nonatomic, retain) NSString *token;");

			Assert.AreEqual("NSString", token.PropertyType);
			Assert.AreEqual("*token", token.PropertyName);
			Assert.AreEqual(2, token.Attributes.Count());
			Assert.IsTrue(token.Attributes.Contains("nonatomic"));
			Assert.IsTrue(token.Attributes.Contains("retain"));

			token = new ObjcPropertyToken("@property (nonatomic, assign, readonly) BOOL sslRequired;");
			Assert.AreEqual("BOOL", token.PropertyType);
			Assert.AreEqual("sslRequired", token.PropertyName);
			Assert.AreEqual(3, token.Attributes.Count());
			Assert.IsTrue(token.Attributes.Contains("nonatomic"));
			Assert.IsTrue(token.Attributes.Contains("assign"));
			Assert.IsTrue(token.Attributes.Contains("readonly"));
		}
	}
}

