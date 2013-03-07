using System;
using System.CodeDom;

namespace Parser {

	public class ObjcPropertyConverter : ObjcConverter {

		public ObjcPropertyConverter(ObjcPropertyToken token) : base(token) { }

		public override CodeObject Convert() {
			var propToken = (ObjcPropertyToken)this.Token;
			var property = new CodeMemberProperty {
				Name = ToCsharpPropertyName(propToken.PropertyName),
				Type = new CodeTypeReference(propToken.PropertyType),
				HasGet = true,
				HasSet = !propToken.IsReadOnly
			};

			var exportAttr = new CodeAttributeDeclaration("Export");
			exportAttr.Arguments.Add(new CodeAttributeArgument(new CodePrimitiveExpression(propToken.PropertyName)));
			exportAttr.Arguments.Add(new CodeAttributeArgument(new CodeSnippetExpression("ArgumentSemantic." + ToCsharpPropertyName(propToken.Semantic))));
			property.CustomAttributes.Add(exportAttr);
			// getter and setter export?
			//property.GetStatements.Add()
			property.Comments.Add(new CodeCommentStatement(propToken.Code));
			return property;
		}

		static string ToCsharpPropertyName(string objcPropName) {
			return objcPropName.Substring(0, 1).ToUpperInvariant() + objcPropName.Substring(1);
		}
	}

}

