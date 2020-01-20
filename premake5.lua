workspace "RayMarcher"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	IncludeDir = {}
	IncludeDir["GLFW"] = "Engine/ThirdParty/GLFW/include"
	IncludeDir["GLAD"] = "Engine/ThirdParty/GLAD/include"
	IncludeDir["GLM"] = "Engine/ThirdParty/glm/glm"
	IncludeDir["IMGUI"] = "Engine/ThirdParty/IMGUI"


	group "Dependencies"
	include "Engine/ThirdParty/GLFW"
	include "Engine/ThirdParty/GLAD"
	include "Engine/ThirdParty/IMGUI"
	group ""

project "Engine"
	location "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/ThirdParty/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/ThirdParty/spdlog/include",
		"%{prj.name}/src/Engine/Core",
		"%{prj.name}/src/Engine/Modules",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.GLM}",
		"%{IncludeDir.IMGUI}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"ImGui"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE"
		optimize "on"


function useEngineLib()
	includedirs 
	{
		"Engine/ThirdParty/spdlog/include",
		"Engine/ThirdParty/glm/glm",
		"Engine/ThirdParty/IMGUI",
		"Engine/src",
		"Engine/src/Engine/Core",
		"Engine/src/Engine/Modules",
	}
	
	links 
	{
		"Engine"
	}

	filter "system:windows"
	systemversion "latest"

	defines
	{
		"PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE"
		optimize "on"
end

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	staticruntime "on"

	language "C++"
	cppdialect "C++17"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	useEngineLib()

	
project "Test"
	location "Test"
	kind "ConsoleApp"
	staticruntime "on"

	language "C++"
	cppdialect "C++17"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"Test/googletest/googletest/src/gtest-all.cc",
		"%{prj.name}/Tests/**.h",
		"%{prj.name}/Tests/**.cpp"
	}

	includedirs
	{
		"Test/googletest/googletest/include", "Test/googletest/googletest"
	}

	useEngineLib()