#include "Application.h"
#include "../Modules/Window/ModuleWindow.h"

namespace Engine
{
	Application::Application() : mWindow(nullptr)
	{
		mWindow = new ModuleWindow(this);
		AddModule(mWindow);
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
			ReturnValue = Module->Update();
		}

		return ReturnValue;
	}
	bool Application::Init()
	{
		bool ReturnValue(true);

		for (auto& Module : mModules)
		{
			ReturnValue = Module->Init();
		}

		mWindow->SetEventCallback(EventHandler(BIND_EVENT_FN(Application::OnEvent)));
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
	void Application::OnEvent(EventData & aData)
	{
		for (auto& Module : mModules)
		{
			Module->OnEvent(aData);
		}
	}
}
