#include "ModuleEditor.h"
#include <IMGUI/IMGUI.h>
#include <Editor/MainMenuBar.h>
#include <Window/ModuleWindow.h>

namespace rubEngine
{
	rubEngine::ModuleEditor::ModuleEditor() : Module(), mElements(), mOpen(true)
	{
	}

	rubEngine::ModuleEditor::~ModuleEditor()
	{
		for (auto& Element : mElements)
		{
			delete Element;
		}
	}

	bool rubEngine::ModuleEditor::Init()
	{
		IMGUI::Init();
		mElements.push_back(new MainMenuBar());
		return true;
	}

	bool rubEngine::ModuleEditor::Update(float aDeltaTime)
	{
		return true;
	}

	bool rubEngine::ModuleEditor::CleanUp()
	{
		for (auto& Element : mElements)
		{
			Element->CleanUp();
		}

		IMGUI::CleanUp();

		return true;
	}

	bool rubEngine::ModuleEditor::Awake()
	{
		return true;
	}

	bool rubEngine::ModuleEditor::PreUpdate(float aDeltaTime)
	{
		IMGUI::BeginFrame();
		return true;
	}

	bool rubEngine::ModuleEditor::PostUpdate(float aDeltaTime)
	{
		IMGUI::EndFrame();
		return true;
	}

	void ModuleEditor::OnGUI()
	{	
		ImGuiDockNodeFlags DockingFlags = ImGuiDockNodeFlags_None;
		DockingFlags ^= ImGuiDockNodeFlags_PassthruCentralNode;
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->Pos);
		ImGui::SetNextWindowSize(viewport->Size);
		ImGui::SetNextWindowViewport(viewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

		if (!ImGui::Begin("Renderer", &mOpen, IMGUI::GetMainWindowFlags()))
		{
			ImGui::End();
		}
		
		ImGui::PopStyleVar();
		ImGui::PopStyleVar(2);

		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), DockingFlags);
		}

		ImGui::End();

		for (auto& Element : mElements)
		{
			Element->Draw();
		}
	}
}
