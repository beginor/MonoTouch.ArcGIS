using System;
using System.Linq;
using NUnit.Framework;
using Parser;

namespace Test {

	[TestFixture]
	public class ObjcMethodTokenTest {

		[Test]
		public void TestMethod() {
			var method = new ObjcMethodToken("+ (id)closestFacilityTaskWithURL:(NSURL *)url credential:(AGSCredential*)cred;");

			Assert.IsTrue(method.IsStatic);
			Assert.IsFalse(method.IsConstructor);

			Assert.AreEqual("id", method.ReturnType);
			Assert.AreEqual("closestFacilityTaskWithURL:credential:", method.Name);

			var parameters = method.Parameters.ToArray();
			Assert.AreEqual(2, parameters.Length);
			Assert.AreEqual("NSURL", parameters[0].Key);
			Assert.AreEqual("url", parameters[0].Value);
			Assert.AreEqual("AGSCredential", parameters[1].Key);
			Assert.AreEqual("cred", parameters[1].Value);
		}

		[Test]
		public void TestMethodConstructor() {
			var method = new ObjcMethodToken("-(id)initWithURL:(NSURL *)url credential:(AGSCredential*)cred;");

			Assert.IsTrue(method.IsConstructor);

			Assert.AreEqual("initWithURL:credential:", method.Name);

			var parameters = method.Parameters.ToArray();
			Assert.AreEqual(2, parameters.Length);
			Assert.AreEqual("NSURL", parameters[0].Key);
			Assert.AreEqual("url", parameters[0].Value);
			Assert.AreEqual("AGSCredential", parameters[1].Key);
			Assert.AreEqual("cred", parameters[1].Value);
		}

		
	}
}

