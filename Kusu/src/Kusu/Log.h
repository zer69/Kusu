#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Kusu
{
	class KUSU_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//----Core log macros----
#define KS_CORE_TRACE(...)		::Kusu::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KS_CORE_INFO(...)		::Kusu::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KS_CORE_WARN(...)		::Kusu::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KS_CORE_ERROR(...)		::Kusu::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KS_CORE_FATAL(...)		::Kusu::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//-----------------------

//----Client log macros----
#define KS_TRACE(...)			::Kusu::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KS_INFO(...)			::Kusu::Log::GetClientLogger()->info(__VA_ARGS__)
#define KS_WARN(...)			::Kusu::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KS_ERROR(...)			::Kusu::Log::GetClientLogger()->error(__VA_ARGS__)
#define KS_FATAL(...)			::Kusu::Log::GetClientLogger()->fatal(__VA_ARGS__)
//-------------------------