#pragma once
#include <Core.h>

namespace Engine
{
	class ImGuiPlatformHandler
	{
	public:
		virtual void Init() = 0;
		virtual void CleanUp() = 0;
		virtual void Begin() = 0;
		virtual void End() = 0;

		static std::shared_ptr<ImGuiPlatformHandler> Create();
	};
}