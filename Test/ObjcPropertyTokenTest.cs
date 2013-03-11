using System.Linq;
using NUnit.Framework;
using Parser;

namespace Test {

	[TestFixture]
	public class ObjcPropertyTokenTest {

		[Test]
		public void TestReadOnlySemantic() {
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

		[Test]
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
		public void TestGetterSetter() {
			var token = new ObjcPropertyToken("@property (nonatomic, assign, getter=isAccessoryButtonHidden) BOOL accessoryButtonHidden;");

			Assert.AreEqual("isAccessoryButtonHidden", token.Getter);

			Assert.IsNullOrEmpty(token.Setter);
		}
	}
}