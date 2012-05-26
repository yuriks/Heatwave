solution "Heatwave"
	configurations { "Debug", "Release" }

	project "Heatwave"
		kind "ConsoleApp"
		language "C++"
		files { "../src/**.cpp", "../src/**.hpp" }
		includedirs "../src"
		debugdir ".."
		flags { "Symbols", "EnableSSE2", "FatalWarnings", "FloatFast", "NoExceptions", "NoRTTI", "Unicode" }

		configuration "Debug"
			defines { "_DEBUG", "DEBUG" }

		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize" }
