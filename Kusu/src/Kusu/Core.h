#pragma once

#ifdef KS_PLATFORM_WINDOWS
	#ifdef KS_BUILD_DLL
		#define KUSU_API __declspec(dllexport)
	#else
		#define KUSU_API __declspec(dllimport)
	#endif
#else
	#error Kusu only supports Windows!
#endif
