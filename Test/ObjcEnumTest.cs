
using NUnit.Framework;
using System;
using Parser;

namespace Test {

	[TestFixture]
	public class ObjcEnumTest {

		[Test]
		public void TestObjcEnumConverter() {
			var token = new ObjcEnumToken("");
			token.AddField("AGSAuthenticationTypeUnknown = 0,           /*!<  */");
			token.AddField("AGSAuthenticationTypeNone,                  /*!<  */");
			token.AddField("AGSAuthenticationTypeToken,                 /*!<  */");
			token.AddField("AGSAuthenticationTypeHTTP,                  /*!<  */");
			token.AddField("AGSAuthenticationTypeClientCertificate,     /*!<  */");
			token.Name = "} AGSAuthenticationType;";

			var converter = token.CreateConverter();
			var cs = converter.Convert();
			Console.Write(cs);
		}
	}
}

