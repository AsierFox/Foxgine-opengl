-- COMMANDS
-- Generate project
-- vendor\premake-5.0.0-alpha15\premake5.exe vs2019

workspace "Foxgine"
	architecture "x64"
	startproject "Sandbox"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

spdlogIncludeDir = "spdlog-1.5.0/include"

project "Foxgine"
	location "Foxgine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediate/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		("%{prj.name}/vendor/" .. spdlogIncludeDir)
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		-- Visual studio project properties -> General -> Windows SDK Version
		systemversion "latest"
		
		defines
		{
			"FOXGINE_PLATFORM_WINDOWS",
			"FOXGINE_BUILD_DLL"
		}
		
		-- Copy Foxgine.dll file to Sandbox
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
		filter "configurations:Debug"
			defines "FOXGINE_DEBUG"
			symbols "On"
			
		filter "configurations:Release"
			defines "FOXGINE_RELEASE"
			optimize "On"
			
		filter "configurations:Dist"
			defines "FOXGINE_DIST"
			optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediate/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		("Foxgine/vendor/" .. spdlogIncludeDir),
		"Foxgine/src"
	}

	links
	{
		"Foxgine"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		-- Visual studio project properties -> General -> Windows SDK Version
		systemversion "latest"
		
		defines
		{
			"FOXGINE_PLATFORM_WINDOWS"
		}
		
		filter "configurations:Debug"
			defines "FOXGINE_DEBUG"
			symbols "On"
			
		filter "configurations:Release"
			defines "FOXGINE_RELEASE"
			optimize "On"
			
		filter "configurations:Dist"
			defines "FOXGINE_DIST"
			optimize "On"
