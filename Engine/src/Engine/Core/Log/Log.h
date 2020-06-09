#pragma once

#include <Core.h>
#include <memory>
#include "spdlog/spdlog.h"

namespace rubEngine
{
	class ENGINE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return mCoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return mClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> mCoreLogger;
		static std::shared_ptr<spdlog::logger> mClientLogger;
	};
}

#define ENGINE_CORE_ERROR(...)	::rubEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ENGINE_CORE_WARN(...)	::rubEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ENGINE_CORE_INFO(...)	::rubEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ENGINE_CORE_TRACE(...)	::rubEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define CLIENT_CORE_ERROR(...)	::rubEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_CORE_WARN(...)	::rubEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_CORE_INFO(...)	::rubEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_CORE_TRACE(...)	::rubEngine::Log::GetClientLogger()->trace(__VA_ARGS__)



