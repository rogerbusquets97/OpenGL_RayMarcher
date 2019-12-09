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

	bool ModuleWindow::Awake()
	{
		mWindow = Window::Create();
		mWindow->SetEventCallback(EventHandler(std::bind(&Application::OnEvent, mApplication, std::placeholders::_1)));
		return true;
	}

	bool ModuleWindow::PreUpdate()
	{
		return true;
	}

	bool ModuleWindow::PostUpdate()
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
