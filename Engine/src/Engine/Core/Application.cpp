#include "Application.h"
#include "Window/ModuleWindow.h"
#include <Log/Log.h>

namespace Engine
{
	Application::Application() : mModules()
	{
	}
	
	Application::~Application()
	{
		for (auto& Module : mModules)
		{
			delete Module;
		}
	}

	bool Application::Run()
	{
		bool ReturnValue(true);

		for (auto& Module : mModules)
		{
			ReturnValue = Module->PreUpdate();
		}

		for (auto& Module : mModules)
		{
			ReturnValue = Module->Update();
		}

		for (auto& Module : mModules)
		{
			ReturnValue = Module->PostUpdate();
		}

		return ReturnValue;
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
	
	void Application::OnEvent(MemoryBuffer & aData)
	{
		for (auto& Module : mModules)
		{
			Module->OnEvent(aData);
		}
	}
}
