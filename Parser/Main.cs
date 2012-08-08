using System;
using System.CodeDom;
using System.CodeDom.Compiler;

namespace Parser {

	class MainClass {

		static CodeCompileUnit CreateCompileUnit() {
			var unit = new CodeCompileUnit();

			var ns = new CodeNamespace("MonoTouch.ArcGIS");
			ns.Imports.Add(new CodeNamespaceImport("System"));
			ns.Imports.Add(new CodeNamespaceImport("System.Drawing"));
			ns.Imports.Add(new CodeNamespaceImport("MonoTouch.ObjCRuntime"));
			ns.Imports.Add(new CodeNamespaceImport("MonoTouch.Foundation"));
			ns.Imports.Add(new CodeNamespaceImport("MonoTouch.UIKit"));

			var type = new CodeTypeDeclaration("AGSAttachment");
			type.IsInterface = true;
			var baseTypeAttr = new CodeAttributeDeclaration("BaseType");
			var baseTypeAttrArg = new CodeAttributeArgument(new CodeTypeOfExpression("NSObject"));
			baseTypeAttr.Arguments.Add(baseTypeAttrArg);
			type.CustomAttributes.Add(baseTypeAttr);
			type.Comments.Add(new CodeCommentStatement("@interface AGSAttachment : NSObject"));

			var prop = new CodeMemberProperty();
			prop.Name = "AttachmentInfo";
			prop.Type = new CodeTypeReference("AGSAttachmentInfo");
			prop.HasGet = true;
			prop.HasSet = false;
			var exportAttr = new CodeAttributeDeclaration("Export");
			exportAttr.Arguments.Add(new CodeAttributeArgument(new CodePrimitiveExpression("attachmentInfo")));
			exportAttr.Arguments.Add(new CodeAttributeArgument(new CodeSnippetExpression("ArgumentSemantic.Retain")));
			prop.CustomAttributes.Add(exportAttr);
			prop.Comments.Add(new CodeCommentStatement("@property (nonatomic, retain, readonly) AGSAttachmentInfo *attachmentInfo;"));
			type.Members.Add(prop);

			var method = new CodeMemberMethod();
			method.Name = "MarkForDeletion";
			//method.ReturnType = new CodeTypeReference(typeof(Void));
			method.Parameters.Add(new CodeParameterDeclarationExpression("AGSMap", "del"));
			exportAttr = new CodeAttributeDeclaration("Export");
			exportAttr.Arguments.Add(new CodeAttributeArgument(new CodePrimitiveExpression("markForDeletion:")));
			method.CustomAttributes.Add(exportAttr);
			type.Members.Add(method);

			ns.Types.Add(type);
			unit.Namespaces.Add(ns);
			return unit;
		}

		public static void Main(string[] args) {
			var unit = CreateCompileUnit();

			var provider = CodeDomProvider.CreateProvider("c#");
			var genOpts = new CodeGeneratorOptions {
				BlankLinesBetweenMembers = true,
				IndentString = "\t", 
			};

			provider.GenerateCodeFromCompileUnit(unit, Console.Out, genOpts);
		}
	}

}
