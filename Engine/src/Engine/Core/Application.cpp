#include "Application.h"
#include "Window/ModuleWindow.h"
#include <Log/Log.h>
#include <Editor/ModuleEditor.h>
#include <Resources/ResourceManager.h>
#include <Renderer/ModuleRenderer.h>

std::unique_ptr<rubEngine::Application> rubEngine::CSingleton<rubEngine::Application>::mInstance = nullptr;

namespace rubEngine
{
	Application::Application() : mModules()
	{
		AddModule<ModuleEditor>();
		AddModule<ModuleWindow>();
		AddModule<ModuleRenderer>();
	}
	
	Application::~Application()
	{
	}

	bool Application::Run(float aDeltaTime)
	{
		for (const auto& Module : mModules)
		{
			if (!Module.second->PreUpdate(aDeltaTime))
			{
				return false;
			}
		}

		for (const auto& Module : mModules)
		{
			if (!Module.second->Update(aDeltaTime))
			{
				return false;
			}
		}

		for (const auto& Module : mModules)
		{
			Module.second->OnGUI();
		}

		for (const auto& Module : mModules)
		{
			if (!Module.second->PostUpdate(aDeltaTime))
			{
				return false;
			}
		}

		return true;
	}
	bool Application::Init()
	{
		bool ReturnValue(true);

		for (const auto& Module : mModules)
		{
			ReturnValue = Module.second->Awake();
		}

		for (const auto& Module : mModules)
		{
			ReturnValue = Module.second->Init();
		}

		return ReturnValue;
	}
	bool Application::CleanUp()
	{
		bool ReturnValue(true);

		for (const auto& Module : mModules)
		{
			ReturnValue = Module.second->CleanUp();
		}

		return ReturnValue;
	}
}
