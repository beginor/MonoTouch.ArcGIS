using System.Linq;
using NUnit.Framework;
using Parser;

namespace Test {

	[TestFixture]
	public class ObjcReaderTest {

		[Test]
		public void TestReadObjcInterface() {
			var objcReader = new ObjcReader(@"..\..\..\Headers\AGSClassBreak.h");
			var tokens = objcReader.ReadFile();
			Assert.Greater(tokens.Count(), 0);
		}

		[Test]
		public void TestTrim() {
			var str = "	  sss ss  	";
			str = str.Trim(' ', '\t');
			Assert.AreEqual("sss ss", str);
		}
	}
}