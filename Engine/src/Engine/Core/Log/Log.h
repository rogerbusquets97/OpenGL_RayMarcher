#pragma once

#include <Core.h>
#include <memory>
#include "spdlog/spdlog.h"

namespace Engine
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

#define ENGINE_CORE_ERROR(...)	::Engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ENGINE_CORE_WARN(...)	::Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ENGINE_CORE_INFO(...)	::Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ENGINE_CORE_TRACE(...)	::Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define CLIENT_CORE_ERROR(...)	::Engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_CORE_WARN(...)	::Engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_CORE_INFO(...)	::Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_CORE_TRACE(...)	::Engine::Log::GetClientLogger()->trace(__VA_ARGS__)



