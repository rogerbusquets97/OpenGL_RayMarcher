#include "ModuleEditor.h"
#include <IMGUI/IMGUI.h>

namespace Engine
{
	Engine::ModuleEditor::ModuleEditor(Application* aApplication) : Module("Editor", aApplication)
	{
	}

	Engine::ModuleEditor::~ModuleEditor()
	{
	}

	bool Engine::ModuleEditor::Init()
	{
		IMGUI::Init();
		return true;
	}

	bool Engine::ModuleEditor::Update()
	{
		return true;
	}

	bool Engine::ModuleEditor::CleanUp()
	{
		IMGUI::CleanUp();
		return true;
	}

	bool Engine::ModuleEditor::Awake()
	{
		return true;
	}

	bool Engine::ModuleEditor::PreUpdate()
	{
		IMGUI::BeginFrame();
		return true;
	}

	bool Engine::ModuleEditor::PostUpdate()
	{
		IMGUI::EndFrame();
		return true;
	}

	void Engine::ModuleEditor::OnEvent(MemoryBuffer& aData)
	{
	}
	void ModuleEditor::OnGUI()
	{
		IMGUI::BeginWindow("Test Window", &mWindowOpen);
		IMGUI::EndWindow();
	}
}
