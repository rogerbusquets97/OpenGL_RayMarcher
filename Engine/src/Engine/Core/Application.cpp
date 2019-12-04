#include "Application.h"
#include "Window/ModuleWindow.h"
#include <Log/Log.h>

namespace Engine
{
	Application::Application()
	{
		AddModule(new ModuleWindow(this));
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
		aData.Reset();
		EVENT_TYPE Type;
		aData.Read(Type);

		switch (Type)
		{
			case EVENT_TYPE::MOUSE_BUTTON_PRESSED:
				ENGINE_CORE_ERROR("Mouse Button Pressed!");
			break;	
		}

		for (auto& Module : mModules)
		{
			Module->OnEvent(aData);
		}
	}
}
