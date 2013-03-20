using System;
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
		public void TestReadSingleInterfaceFile() {
			var objcReader = new ObjcReader(@"..\..\..\Headers\AGSAttachment.h");
			var tokens = objcReader.ReadFile();
			Assert.AreEqual(1, tokens.Count());
			var token = tokens.First() as ObjcInterfaceToken;
			Assert.IsNotNull(token);
			var csCode = token.CreateConverter().Convert();
			Console.Write(csCode);
		}

		[Test]
		public void TestTrim() {
			var str = "	  sss ss  	";
			str = str.TrimTabAndWhitespace();
			Assert.AreEqual("sss ss", str);
		}
	}
}