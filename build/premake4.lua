solution "Heatwave"
	configurations { "Debug", "Release" }

	project "Heatwave"
		kind "ConsoleApp"
		language "C++"
		files { "../src/**.h", "../src/**.cpp" }
		includedirs "../src"
		debugdir ".."
		flags { "Symbols", "EnableSSE2", "FatalWarnings", "FloatFast", "NoExceptions", "NoRTTI", "Unicode" }

		configuration "Debug"
			defines { "_DEBUG", "DEBUG" }

		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize" }
