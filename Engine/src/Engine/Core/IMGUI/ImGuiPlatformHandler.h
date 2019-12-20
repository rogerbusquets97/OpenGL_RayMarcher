#pragma once
#include <memory>

namespace Engine
{
	class ImGuiPlatformHandler
	{
	public:
		virtual void Init() = 0;
		virtual void CleanUp() = 0;
		virtual void BeginFrame() = 0;
		virtual void EndFrame() = 0;

		static std::shared_ptr<ImGuiPlatformHandler> Create();
	};
}