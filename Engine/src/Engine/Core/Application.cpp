#include "Application.h"

namespace Engine
{
	Application::Application()
	{
	}


	Application::~Application()
	{
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
	void Application::AddModule(Module * aModule)
	{
		mModules.push_back(aModule);
	}
	void Application::RemoveModule(Module * aModule)
	{
		mModules.remove(aModule);
	}
	void Application::OnEvent(const EventData & aData)
	{
	}
}
