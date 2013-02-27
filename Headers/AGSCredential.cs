[BaseType(typeof(NSObject))]
public interface AGSCredential {

	[Export("username", ArgumentSemantic.Copy)]
	string Username { get; set; }

	[Export("password", ArgumentSemantic.Copy)]
	string Password { get; set; }

	[Export("tokenUrl", ArgumentSemantic.Copy)]
	Url TokenUrl { get; set; }

	[Export("authType", ArgumentSemantic.Assign)]
	AGSAuthenticationType { get; set; }

	[Export("referer", ArgumentSemantic.Copy)]
	string Referer { get; set; }

	[Export("token", ArgumentSemantic.Copy)]
	string Token { get; set; }

	[Export("sslRequired", ArgumentSemantic.Assign)]
	bool SslRequired { get; set; }

	[Export("identity")]
	SecIdentityRef Identity();

	[Export("initWithUser:password:")]
	IntPtr Constructor(string username, string password);

	[Export("initWithUser:password:authenticationType:")]
	IntPtr Constructor(string username, string password, AGSAuthenticationType authType);

	[Export("initWithUser:password:authenticationType:tokenUrl:")]
	IntPtr Constructor(string username, string password, AGSAuthenticationType authType, Url tokenUrl);

	[Export("initWithToken:")]
	IntPtr Constructor(string token);

	[Export("initWithIdentityRef:")]
	IntPtr Constructor(SecIdentityRef identityRef);

	[Export("initWithToken:referer:")]
	IntPtr Constructor(string token, string referer);

	[Static, Export("getTokenServiceUrl:error:")]
	Url GetTokenServiceUrl(Url url, NSError error);

	[Static, Export("isServiceSecured:error:")]
	AGSAuthenticationType IsServiceSecured(Url url, NSError error);

	[Static, Export("identitiesForProtectionSpace:")]
	SecIdentityRef[] IdentitiesForProtectionSpace(NSURLProtectionSpace protectionSpace);

	[Static, Export("importCertificateData:password:overwrite:error:")]
	SecIdentityRef ImportCertificateData(NSData data, string password, bool overwrite, NSError error);

	[Static, Export("removeIdentityFromKeychain:")]
	OSStatus RemoveIdentityFromKeychain(SecIdentityRef identityRef);

	[Export("authenticatingHost")]
	string AuthenticatingHost();

}

[Model, BaseType(typeof(NSObject))]
public interface AGSSecuredResource {

	[Export("credential", ArgumentSemantic.Copy)]
	AGSCredential Credential { get; set; }

	[Export("credentialCache", ArgumentSemantic.Retain)]
	AGSCredentialCache CredentialCache { get; set; }

}