using System;
using MonoTouch.ObjCRuntime;

[assembly: LinkWith ("libArcGIS.a", LinkTarget.ArmV7 | LinkTarget.Simulator, IsCxx = true, ForceLoad = true)]
