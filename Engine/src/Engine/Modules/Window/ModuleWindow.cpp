#include "ModuleWindow.h"
#include <Application.h>
#include <memory>

namespace Engine
{
	std::shared_ptr<Window> ModuleWindow::mWindow = nullptr;

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
		bool ReturnValue(false);
		mWindow = Window::Create();
		if (mWindow != nullptr)
		{
			mWindow->AddMouseEventCallback(EventHandler<int, int>(std::bind(&Application::OnMouseEvent, mApplication, std::placeholders::_1, std::placeholders::_2)));
			mWindow->AddResizeWindowEventCallback(EventHandler<int, int>(std::bind(&Application::OnResizeWindowEvent, mApplication, std::placeholders::_1, std::placeholders::_2)));
			ReturnValue = true;
		}
		return ReturnValue;
	}

	bool ModuleWindow::PreUpdate()
	{
		return true;
	}

	bool ModuleWindow::PostUpdate()
	{
		return true;
	}

	void ModuleWindow::OnMouseEvent(int aButton, int aAction)
	{

	}

	uint32_t ModuleWindow::GetWidth()
	{
		uint32_t Return(0U);

		if (mWindow != nullptr)
		{
			Return = mWindow->GetWidth();
		}

		return Return;
	}
	uint32_t ModuleWindow::GetHeight()
	{
		uint32_t Return(0U);

		if (mWindow != nullptr)
		{
			Return = mWindow->GetHeight();
		}

		return Return;
	}
	void* ModuleWindow::GetNativeWindow()
	{
		return mWindow->GetNativeWindow();
	}

}
