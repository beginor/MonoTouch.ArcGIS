using System;
using System.Collections.Generic;
using System.IO;

namespace Parser {

	public class ObjcReader {

		private readonly string _path;

		private ObjcReaderState _state;

		public ObjcReader(string path) {
			if (!File.Exists(path)) {
				throw new FileNotFoundException("Objc file not found!", path);
			}
			this._path = path;
		}

		public IEnumerable<ObjcToken> ReadFile() {
			var objcTokens = new List<ObjcToken>();

			using(var fileReader = new StreamReader(this._path, true)) {
				var line = string.Empty;
				while ((line = fileReader.ReadLine()) != null) {
					line = line.TrimTabAndWhitespace();

					if (line.StartsWith("//")) {
						this._state = ObjcReaderState.Comment;
						continue;
					}
					if (line.StartsWith("/*")) {
						if (!line.Contains("*/")) {
							fileReader.ReadTo("*/");
						}
						continue;
					}
					if (line.StartsWith("@protocol") && line.EndsWith(";")) {
						this._state = ObjcReaderState.ProtocolAlias;
						continue;
					}
					if (line.StartsWith("@class") && line.EndsWith(";")) {
						this._state = ObjcReaderState.ClassAlias;
						continue;
					}
					// interface def
					if (line.StartsWith("@interface") && !line.Contains("(")) {
						this._state = ObjcReaderState.InterfaceDefineBlock;
						var interfaceToken = new ObjcInterfaceToken(line);
						objcTokens.Add(interfaceToken);
						// skip inter face fields?
						if (line.EndsWith("{")) {
							fileReader.ReadTo("}");
						}
						while ((line = fileReader.ReadLine().TrimTabAndWhitespace()) != "@end") {
							if (line.StartsWith("//")) {
								continue;
							}
							if (line.StartsWith("/*")) {
								if (!line.Contains("*/")) {
									fileReader.ReadTo("*/");
								}
								continue;
							}
							if (string.IsNullOrEmpty(line)) {
								continue;
							}
							interfaceToken.AddMember(line);
						}
					}
					// enum
					if (line.StartsWith("typedef enum")) {
						this._state = ObjcReaderState.EnumStart;
						var enumToken = new ObjcEnumToken(line);
						objcTokens.Add(enumToken);
						while(!(line = fileReader.ReadLine().TrimTabAndWhitespace()).StartsWith("}")) {
							if (line.StartsWith("//")) {
								continue;
							}
							if (line.StartsWith("/*")) {
								if (!line.Contains("*/")) {
									fileReader.ReadTo("*/");
								}
								continue;
							}
							if (string.IsNullOrEmpty(line)) {
								continue;
							}
							enumToken.AddField(line);
						}
						enumToken.Name = line;
					}
					// categori
					if (line.StartsWith("@interface") && line.Contains("(") && line.Contains(")")) {

					}
					// protocol
					if (line.StartsWith("@protocol") && !line.EndsWith(";")) {

					}
				}
			}

			return objcTokens;
		}

		private static bool IsLineComment(string code) {
			if (code.StartsWith("//")) {
				return true;
			}
			if (code.StartsWith("/*") && code.Contains("*/")) {
				return true;
			}
			return false;
		}

		private static bool IsCommentBlockStart(string code) {
			if (code.StartsWith("/*") && !code.Contains("*/")) {
				return true;
			}
			return false;
		}

		public override string ToString() {
			return "ObjcReader: " + this._path;
		}
	}

	public static class TextExtensions {
		
		public static void ReadTo(this TextReader reader, string expected) {
			string line;
			var founded = false;
			while ((line = reader.ReadLine()) != null) {
				line = line.TrimTabAndWhitespace();
				if (line != expected && !line.EndsWith(expected)) {
					continue;
				}
				founded = true;
				break;
			}
			if (!founded) {
				throw new Exception(string.Format("Expected string \"{0}\" not found in reader!", expected)); 
			}
		}
	}
}

