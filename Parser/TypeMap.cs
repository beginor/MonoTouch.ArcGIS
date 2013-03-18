using System;
using System.Collections.Generic;
using System.IO;

namespace Parser {

	public static class TypeMap {

		private static Dictionary<string, string> _types = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);

		static TypeMap() {
			LoadConfig();
		}

		public static void LoadConfig() {
			var typeConfs = File.ReadAllLines("TypeMap.conf");
			foreach (var typeConf in typeConfs) {
				var conf = typeConf.Trim();
				if (conf.StartsWith("#")) {
					continue;
				}
				var arr = conf.Split('=');
				var ocType = arr[0].Trim();
				var csType = arr[1].Trim();
				_types[ocType] = csType;
			}
		}

		public static string GetTypeFor(string objcType) {
			if (_types.ContainsKey(objcType)) {
				return _types[objcType];
			}
			return objcType;
		}
	}
}

