#include "IMGUI.h"
#include <Renderer/RenderAPI.h>
#include <Window/ModuleWindow.h>

namespace Engine
{
	std::shared_ptr<ImGuiPlatformHandler> IMGUI::mHandler = nullptr;

	void Engine::IMGUI::Init()
	{
		mHandler = ImGuiPlatformHandler::Create();
		mHandler->Init();
	}

	void Engine::IMGUI::CleanUp()
	{
		mHandler->CleanUp();
	}

	void Engine::IMGUI::BeginFrame()
	{
		mHandler->BeginFrame();
	}

	void Engine::IMGUI::EndFrame()
	{
		mHandler->EndFrame();
	}
	void IMGUI::BeginWindow(const char* aName, bool* aOpen)
	{
		mHandler->BeginWindow(aName, aOpen);
	}
	void IMGUI::EndWindow()
	{
		mHandler->EndWindow();
	}
}
