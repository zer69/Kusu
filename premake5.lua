workspace "Kusu"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
      "%{prj.name}/vendor/spdlog/include"
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
      symbols "On"

    filter "configurations:Release"
      defines "KS_Release"
      optimize "On"

    filter "configurations:Dist"
      defines "KS_DIST"
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

    defines
    {
      "KS_PLATFORM_WINDOWS",
    }

    filter "configurations:Debug"
      defines "KS_DEBUG"
      symbols "On"

    filter "configurations:Release"
      defines "KS_Release"
      optimize "On"

    filter "configurations:Dist"
      defines "KS_DIST"
      optimize "On"