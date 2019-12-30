#include "Application.h"
#include "Window/ModuleWindow.h"
#include <Log/Log.h>
#include <Editor/ModuleEditor.h>

namespace Engine
{
	Application::Application() : mModules()
	{
		AddModule(new ModuleEditor(this));
	}
	
	Application::~Application()
	{
		for (std::vector<Module*>::reverse_iterator It = mModules.rbegin(); It != mModules.rend(); ++It)
		{
			delete (*It);
		}
	}

	bool Application::Run(float aDeltaTime)
	{
		for (auto& Module : mModules)
		{
			if (!Module->PreUpdate(aDeltaTime))
			{
				return false;
			}
		}

		for (auto& Module : mModules)
		{
			if (!Module->Update(aDeltaTime))
			{
				return false;
			}
		}

		for (auto& Module : mModules)
		{
			Module->OnGUI();
		}

		for (auto& Module : mModules)
		{
			if (!Module->PostUpdate(aDeltaTime))
			{
				return false;
			}
		}

		return true;
	}
	bool Application::Init()
	{
		bool ReturnValue(true);

		for (auto& Module : mModules)
		{
			ReturnValue = Module->Awake();
		}

		for (auto& Module : mModules)
		{
			ReturnValue = Module->Init();
		}

		return ReturnValue;
	}
	bool Application::CleanUp()
	{
		bool ReturnValue(true);

		for (auto& Module : mModules)
		{
			ReturnValue = Module->CleanUp();
		}

		return ReturnValue;
	}
	void Application::AddModule(Module* aModule)
	{
		mModules.push_back(aModule);
	}
	void Application::RemoveModule(Module* aModule)
	{
		mModules.erase(std::find(mModules.begin(), mModules.end(), aModule));
	}
	
	void Application::OnCursorMovedEvent(float aXPos, float aYPos)
	{
		for (auto& Module : mModules)
		{
			Module->OnCursorMovedEvent(aXPos, aYPos);
		}
	}

	void Application::OnMouseButtonEvent(MouseButton aMouseButton, InputAction aInputAction)
	{
		for (auto& Module : mModules)
		{
			Module->OnMouseButtonEvent(aMouseButton, aInputAction);
		}
	}
	
	void Application::OnResizeWindowEvent(unsigned int aWidth, unsigned int aHeight)
	{
		for (auto& Module : mModules)
		{
			Module->OnResizeWindowEvent(aWidth, aHeight);
		}
	}
	
	void Application::OnKeyWindowEvent(KeyId aKeyId, InputAction aInputAction)
	{
		for (auto& Module : mModules)
		{
			Module->OnKeyWindowEvent(aKeyId, aInputAction);
		}
	}
}
