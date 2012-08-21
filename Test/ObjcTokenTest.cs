using System;
using System.Linq;
using NUnit.Framework;
using Parser;

namespace Test {

	[TestFixture()]
	public class ObjcTokenTest {

		[Test]
		public void TestPropertyReadOnlySemantic() {
			var token = new ObjcPropertyToken("@property (nonatomic, assign, readonly) BOOL sslRequired;");
			Assert.AreEqual("BOOL", token.PropertyType);
			Assert.AreEqual("sslRequired", token.PropertyName);
			Assert.AreEqual(3, token.Attributes.Count());
			Assert.IsTrue(token.Attributes.Contains("nonatomic"));
			Assert.IsTrue(token.Attributes.Contains("assign"));
			Assert.IsTrue(token.Attributes.Contains("readonly"));
			Assert.IsTrue(token.IsReadOnly);
			Assert.AreEqual("Assign", token.Semantic);
		}

		[Test()]
		public void TestProperty() {
			var token = new ObjcPropertyToken("@property (nonatomic, retain) NSString *token;");

			Assert.AreEqual("NSString", token.PropertyType);
			Assert.AreEqual("token", token.PropertyName);
			Assert.AreEqual(2, token.Attributes.Count());
			Assert.IsTrue(token.Attributes.Contains("nonatomic"));
			Assert.IsTrue(token.Attributes.Contains("retain"));
			Assert.IsFalse(token.IsReadOnly);
		}

		[Test]
		public void TestPropertyGetterSetterProperty() {
			var token = new ObjcPropertyToken("@property (nonatomic, assign, getter=isAccessoryButtonHidden) BOOL accessoryButtonHidden;");

			Assert.AreEqual("isAccessoryButtonHidden", token.Getter);

			Assert.IsNullOrEmpty(token.Setter);
		}

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

