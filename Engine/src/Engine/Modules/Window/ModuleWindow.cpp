#include "ModuleWindow.h"
#include <Application.h>
#include <memory>
#include <functional>
#include "Events/Event.h"

namespace Engine
{
	std::shared_ptr<Window> ModuleWindow::mWindow = nullptr;

	ModuleWindow::ModuleWindow(Application* aApplication) : Module("Window", aApplication), mMustClose(false)
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
		return !mMustClose && mWindow->Update();
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
			WindowEventsContainer& WindowEvents = mWindow->GetWindowEvents();
			(*WindowEvents.mMouseEvent) += std::bind(&Application::OnMouseEvent, mApplication, std::placeholders::_1, std::placeholders::_2);
			(*WindowEvents.mResizeWindowsEvent) += std::bind(&Application::OnResizeWindowEvent, mApplication, std::placeholders::_1, std::placeholders::_2);
			(*WindowEvents.mKeyEvent) += std::bind(&Application::OnKeyWindowEvent, mApplication, std::placeholders::_1, std::placeholders::_2);
			
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

	void ModuleWindow::OnKeyWindowEvent(KeyId aKeyId, KeyAction aKeyAction)
	{
		if (aKeyId == KeyId::Escape)
		{
			mMustClose = true;
		}
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
