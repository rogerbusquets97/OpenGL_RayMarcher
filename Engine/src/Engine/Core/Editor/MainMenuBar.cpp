#include "MainMenuBar.h"
#include <IMGUI/IMGUI.h>
#include <imgui.h>
namespace Engine
{
	void Engine::MainMenuBar::Init()
	{
	}

	void Engine::MainMenuBar::CleanUp()
	{
	}

	void Engine::MainMenuBar::Draw()
	{
		IMGUI::BeginMainMenuBar();

		if (IMGUI::BeginMenu("File"))
		{
			if (IMGUI::AddMenuItem("Open"))
			{

			}

			if (IMGUI::AddMenuItem("Save"))
			{

			}

			if (IMGUI::AddMenuItem("Close"))
			{

			}

			IMGUI::EndMenu();
		}
		if (IMGUI::BeginMenu("Edit"))
		{
			IMGUI::EndMenu();
		}
		if (IMGUI::BeginMenu("About"))
		{
			IMGUI::EndMenu();
		}
		if (IMGUI::BeginMenu("Help"))
		{
			IMGUI::EndMenu();
		}
		IMGUI::EndMainMenuBar();

		bool opened = true;
		if (IMGUI::BeginWindow("Test Window", &opened))
		{
			IMGUI::EndWindow();
		}
	}
}
