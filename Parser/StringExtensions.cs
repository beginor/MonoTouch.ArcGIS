namespace Parser {
	
	public static class StringExtensions {

		public static bool IsNotNullOrEmpty(this string str) {
			return !string.IsNullOrEmpty(str);
		}

		public static bool IsNullOrEmpty(this string str) {
			return string.IsNullOrEmpty(str);
		}

		public static bool IsNullOrWhiteSpace(this string str) {
			return string.IsNullOrWhiteSpace(str);
		}

		public static bool IsNotNullOrWhiteSpace(this string str) {
			return !string.IsNullOrWhiteSpace(str);
		}

		public static string TrimTabAndWhitespace(this string str) {
			return str.Trim('\t', ' ');
		}
	}
}