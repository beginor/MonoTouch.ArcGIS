using System;
using System.Collections.Generic;
using System.IO;

namespace Parser {

	public class ObjcReader {

		public ObjcReader(string path) {
			//var reader = new StreamReader(path, true);
		}

		public IEnumerable<ObjcToken> ReadFile() {
			var objcTokens = new List<ObjcToken>();
			return objcTokens;
		}
	}

	public enum ObjcReaderState {
		CommentStart,
		Comment,
		CommentEnd
	}
}

