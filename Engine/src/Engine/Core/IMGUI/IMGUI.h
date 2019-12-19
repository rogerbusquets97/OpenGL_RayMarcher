#pragma once
#include <Core.h>
#include <IMGUI/ImGuiPlatformHandler.h>
#include <imgui.h>

namespace Engine
{
	class ENGINE_API IMGUI
	{
	public:
		static void Init();
		static void CleanUp();
		static void BeginFrame();
		static void EndFrame();
		static bool BeginWindow(const char* aName, bool* aOpen, int aFlags = 0);
		static void EndWindow();
		static bool BeginMainMenuBar();
		static void EndMainMenuBar();
		static bool BeginMenuBar();
		static void BeginDockSpace();
		static bool BeginMenu(const char* aLabel, bool aEnabled = true);
		static void EndMenu();
		static void SetNextWindowSize(unsigned int aWidth, unsigned int aHeight);
		static void EndMenuBar();
		static bool AddMenuItem(const char* aLabel, const char* aShortcut = NULL, bool aSelected = false, bool aEnabled = true);
		static bool AddMenuItem(const char* aLabel, const char* aShortcut, bool* apSelected, bool aEnabled = true);
		static int GetMainWindowFlags();
	private:
		static std::shared_ptr<ImGuiPlatformHandler> mHandler;
		static int mWindowFlags;
	};
}