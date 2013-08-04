using System;
using MonoTouch.ObjCRuntime;

[assembly: LinkWith (
	"libArcGIS.a",
	LinkTarget.ArmV7 | LinkTarget.Simulator,
	IsCxx = true,
	ForceLoad = true,
	Frameworks = "CoreGraphics CoreLocation CoreText Foundation QuartzCore MediaPlayer MobileCoreServices OpenGLES Security UIKit",
	LinkerFlags = "-lz -lc++"
	)]