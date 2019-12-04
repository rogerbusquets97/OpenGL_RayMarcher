#include "ModuleWindow.h"
#include <Application.h>
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
		mWindow->SetEventCallback(EventHandler(std::bind(&Application::OnEvent, mApplication, std::placeholders::_1)));
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

	void ModuleWindow::OnEvent(MemoryBuffer& aData)
	{
	}
	void ModuleWindow::SetEventCallback(const EventHandler & aCallback)
	{
		mWindow->SetEventCallback(aCallback);
	}
}
