#include "MainMenuBar.h"
#include <IMGUI/IMGUI.h>
#include <imgui.h>
namespace rubEngine
{
	void rubEngine::MainMenuBar::Init()
	{
	}

	void rubEngine::MainMenuBar::CleanUp()
	{
	}

	void rubEngine::MainMenuBar::Draw()
	{
		if (IMGUI::BeginMainMenuBar())
		{
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
		}
	}
}
