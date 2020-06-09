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
	
	void Application::OnCursorMovedEvent(float aXPos, float aYPos)
	{
		for (auto& Module : mModules)
		{
			Module.second->OnCursorMovedEvent(aXPos, aYPos);
		}
	}

	void Application::OnMouseButtonEvent(MouseButton aMouseButton, InputAction aInputAction)
	{
		for (auto& Module : mModules)
		{
			Module.second->OnMouseButtonEvent(aMouseButton, aInputAction);
		}
	}
	
	void Application::OnResizeWindowEvent(unsigned int aWidth, unsigned int aHeight)
	{
		for (auto& Module : mModules)
		{
			Module.second->OnResizeWindowEvent(aWidth, aHeight);
		}
	}
	
	void Application::OnKeyWindowEvent(KeyId aKeyId, InputAction aInputAction)
	{
		for (auto& Module : mModules)
		{
			Module.second->OnKeyWindowEvent(aKeyId, aInputAction);
		}
	}
	void Application::OnFileDropped(const std::string& aPath)
	{
		for (auto& Module : mModules)
		{
			Module.second->OnFileDropped(aPath);
		}
	}
	/*ResourceManager* Application::GetResourceManager()
	{
		return mResourceManager;
	}*/
}
