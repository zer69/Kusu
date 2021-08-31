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

#ifdef KS_DEBUG
	#define KS_ENABLE_ASSERTS
#endif

#ifdef KS_ENABLE_ASSERTS
	#define KS_ASSERT(x, ...) { if(!(x)) { KS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define KS_CORE_ASSERT(x, ...) { if(!(x)) { KS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define KS_ASSERT(x, ...)
	#define KS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define KS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
