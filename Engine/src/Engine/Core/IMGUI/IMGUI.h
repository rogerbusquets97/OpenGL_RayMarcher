#pragma once
#include <Core.h>
#include <IMGUI/ImGuiPlatformHandler.h>

namespace Engine
{
	class ENGINE_API IMGUI
	{
	public:
		static void Init();
		static void CleanUp();
		static void BeginFrame();
		static void EndFrame();
		static void BeginWindow(const char* aName, bool* aOpen);
		static void EndWindow();

	private:
		static std::shared_ptr<ImGuiPlatformHandler> mHandler;
	};
}