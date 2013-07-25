using System;
using MonoTouch.ObjCRuntime;

[assembly: LinkWith ("libArcGIS.a", LinkTarget.ArmV6 | LinkTarget.ArmV7 | LinkTarget.Simulator, IsCxx = true, ForceLoad = true)]
