#include "IMGUI.h"
#include <Renderer/RenderAPI.h>
#include <Window/ModuleWindow.h>

namespace rubEngine
{
	std::shared_ptr<ImGuiPlatformHandler> IMGUI::mHandler = nullptr;
	int IMGUI::mWindowFlags = 0;
	bool IMGUI::mFrameClosed = true;

	void rubEngine::IMGUI::Init()
	{
		mHandler = ImGuiPlatformHandler::Create();
		mHandler->Init();

		mWindowFlags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		mWindowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		mWindowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		mWindowFlags ^= ImGuiDockNodeFlags_PassthruCentralNode;
		mWindowFlags |= ImGuiWindowFlags_NoBackground;
	}

	void rubEngine::IMGUI::CleanUp()
	{
		if (!mFrameClosed)
		{
			EndFrame();
		}

		mHandler->CleanUp();
	}

	void rubEngine::IMGUI::BeginFrame()
	{
		if (mFrameClosed)
		{
			mHandler->BeginFrame();
			mFrameClosed = false;
		}
	}

	void rubEngine::IMGUI::EndFrame()
	{
		mHandler->EndFrame();
		mFrameClosed = true;
	}
	bool IMGUI::BeginWindow(const char* aName, bool* aOpen, int aFlags)
	{
		return ImGui::Begin(aName, aOpen, aFlags);
	}
	void IMGUI::EndWindow()
	{
		return ImGui::End();
	}
	bool IMGUI::BeginMainMenuBar()
	{
		return ImGui::BeginMainMenuBar();
	}
	void IMGUI::EndMainMenuBar()
	{
		ImGui::EndMainMenuBar();
	}
	bool IMGUI::BeginMenuBar()
	{
		return ImGui::BeginMenuBar();
	}
	void IMGUI::BeginDockSpace()
	{
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MainDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}
	}
	bool IMGUI::BeginMenu(const char* aLabel, bool aEnabled)
	{
		return ImGui::BeginMenu(aLabel, aEnabled);
	}
	void IMGUI::EndMenu()
	{
		ImGui::EndMenu();
	}
	void IMGUI::SetNextWindowSize(unsigned int aWidth, unsigned int aHeight)
	{
		ImGui::SetNextWindowSize(ImVec2(aWidth, aHeight));
	}
	void IMGUI::EndMenuBar()
	{
		return ImGui::EndMenuBar();
	}
	bool IMGUI::AddMenuItem(const char* aLabel, const char* aShortcut, bool aSelected, bool aEnabled)
	{
		return ImGui::MenuItem(aLabel, aShortcut, aSelected, aEnabled);
	}
	bool IMGUI::AddMenuItem(const char* aLabel, const char* aShortcut, bool* apSelected, bool aEnabled)
	{
		return ImGui::MenuItem(aLabel, aShortcut, apSelected, aEnabled);
	}

	int IMGUI::GetMainWindowFlags()
	{
		return mWindowFlags;
	}
}
