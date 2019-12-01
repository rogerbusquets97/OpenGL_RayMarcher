#include "ModuleWindow.h"
#include "../../Core/Application.h"
#include <memory>

namespace Engine
{
	ModuleWindow::ModuleWindow(Application* aApplication) : Module("Window", aApplication)
	{
	}


	ModuleWindow::~ModuleWindow()
	{
	}

	bool ModuleWindow::Init()
	{
		mWindow = Window::Create();

		return true;
	}

	bool ModuleWindow::Update()
	{
		mWindow->Update();
		return true;
	}

	bool ModuleWindow::CleanUp()
	{
		return true;
	}

	void ModuleWindow::OnEvent(EventData& aData)
	{
	}

	void ModuleWindow::SetEventCallback(const EventHandler & aCallback)
	{
		mWindow->SetEventCallback(aCallback);
	}


}
