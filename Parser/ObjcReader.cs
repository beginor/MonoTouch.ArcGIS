using System;
using System.IO;

namespace Parser {

	public class ObjcReader {

		public ObjcReader(string path) {
			var reader = new StreamReader(path, true);
		}

		public bool Read() {
			return false;
		}

		public ObjcToken CurrentToken {
			get;
			private set;
		}

	}

	public enum ObjcReaderState {
		CommentStart,
		Comment,
		CommentEnd
	}
}

