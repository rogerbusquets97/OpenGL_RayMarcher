#include "IMGUI.h"
#include <Renderer/RenderAPI.h>
#include <Window/ModuleWindow.h>

namespace Engine
{
	std::shared_ptr<ImGuiPlatformHandler> IMGUI::mHandler = nullptr;

	void Engine::IMGUI::Init()
	{
		mHandler = ImGuiPlatformHandler::Create();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;

		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

		ImGui::StyleColorsDark();
		ImGuiStyle& Style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			Style.WindowRounding = 0.0f;
			Style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		mHandler->Init();
	}

	void Engine::IMGUI::CleanUp()
	{
		mHandler->CleanUp();
		ImGui::DestroyContext();
	}

	void Engine::IMGUI::Begin()
	{
		mHandler->Begin();
		ImGui::NewFrame();
	}

	void Engine::IMGUI::End()
	{
		mHandler->End();
	}
}
