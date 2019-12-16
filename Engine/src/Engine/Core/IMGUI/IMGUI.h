#pragma once
#include <Core.h>
#include <imgui.h>
#include <IMGUI/ImGuiPlatformHandler.h>

namespace Engine
{
	class ENGINE_API IMGUI
	{
	public:
		static void Init();
		static void CleanUp();
		static void Begin();
		static void End();

	private:
		static std::shared_ptr<ImGuiPlatformHandler> mHandler;
	};
}