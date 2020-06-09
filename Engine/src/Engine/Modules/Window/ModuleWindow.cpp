#include "ModuleWindow.h"
#include <Application.h>
#include <memory>
#include <functional>
#include "Events/Event.h"
#include <Input/CInput.h>

namespace rubEngine
{
	ModuleWindow::ModuleWindow() : Module(), mWindow(Window::Create()), mMustClose(false)
	{
	}


	ModuleWindow::~ModuleWindow()
	{
	}

	bool ModuleWindow::Init()
	{
		return true;
	}

	bool ModuleWindow::Update(float aDeltaTime)
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

		//First call to GetInstance, hence Input is created here.
		const std::unique_ptr<CInput>& pInput = CInput::GetInstance();

		if (mWindow != nullptr)
		{
			WindowEventsContainer& WindowEvents = mWindow->GetWindowEvents();
			//(*WindowEvents.mCursorMovedEvent) += std::bind(&Application::OnCursorMovedEvent, mApplication, std::placeholders::_1, std::placeholders::_2);
			//(*WindowEvents.mMouseButtonEvent) += std::bind(&Application::OnMouseButtonEvent, mApplication, std::placeholders::_1, std::placeholders::_2);
			//(*WindowEvents.mResizeWindowsEvent) += std::bind(&Application::OnResizeWindowEvent, mApplication, std::placeholders::_1, std::placeholders::_2);
			(*WindowEvents.mKeyEvent) += std::bind(&CInput::OnKeyEvent, pInput.get(), std::placeholders::_1, std::placeholders::_2);
			//(*WindowEvents.mDroppedFileEvent) += std::bind(&Application::OnFileDropped, mApplication, std::placeholders::_1);
			
			ReturnValue = true;
		}
		return ReturnValue;
	}

	bool ModuleWindow::PreUpdate(float aDeltaTime)
	{
		return true;
	}

	bool ModuleWindow::PostUpdate(float aDeltaTime)
	{
		return true;
	}

	const std::shared_ptr<Window>& ModuleWindow::GetWindow() const noexcept
	{
		return mWindow;
	}

	uint32_t ModuleWindow::GetWidth() const noexcept
	{
		uint32_t Return(0U);

		if (mWindow != nullptr)
		{
			Return = mWindow->GetWidth();
		}

		return Return;
	}
	uint32_t ModuleWindow::GetHeight() const noexcept
	{
		uint32_t Return(0U);

		if (mWindow != nullptr)
		{
			Return = mWindow->GetHeight();
		}

		return Return;
	}
	void* ModuleWindow::GetNativeWindow() const noexcept
	{
		return mWindow->GetNativeWindow();
	}

}
