workspace "Kusu"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

  -- Include directories relative to root folder (solution directory)
  IncludeDir = {}
  IncludeDir["GLFW"] = "Kusu/vendor/GLFW/include"

  include "Kusu/vendor/GLFW"

  project "Kusu"
    location "Kusu"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "kspch.h"
    pchsource "Kusu/src/kspch.cpp"

    files
    {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
      "%{prj.name}/src",
      "%{prj.name}/vendor/spdlog/include",
		  "%{IncludeDir.GLFW}"
	  }

	  links
	  {
		"GLFW",
		"opengl32.lib"
    }

    filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"

      defines
      {
        "KS_PLATFORM_WINDOWS",
        "KS_BUILD_DLL",
      }

      postbuildcommands
      {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
      }

    filter "configurations:Debug"
      defines "KS_DEBUG"
      buildoptions "/MDd"
      symbols "On"

    filter "configurations:Release"
      defines "KS_RELEASE"
      buildoptions "/MD"
      optimize "On"

    filter "configurations:Dist"
      defines "KS_DIST"
      buildoptions "/MD"
      optimize "On"

  project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
      "Kusu/vendor/spdlog/include",
      "Kusu/src"
    }

    links
    {
      "Kusu"
    }

    filter "system:windows"
		  cppdialect "C++17"
		   staticruntime "On"
		   systemversion "latest"

    defines
    {
      "KS_PLATFORM_WINDOWS",
    }

    filter "configurations:Debug"
      defines "KS_DEBUG"
      buildoptions "/MDd"
      symbols "On"

    filter "configurations:Release"
      defines "KS_RELEASE"
      buildoptions "/MD"
      optimize "On"

    filter "configurations:Dist"
      defines "KS_DIST"
      buildoptions "/MD"
      optimize "On"
