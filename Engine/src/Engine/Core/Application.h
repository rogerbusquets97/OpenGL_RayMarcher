#pragma once
#include "Core.h"
#include <vector>
#include <Module.h>
#include "Window/Inputs.h"

namespace Engine
{
	class ResourceManager;

	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		bool Run(float aDeltaTime);
		bool Init();
		bool CleanUp();
		void AddModule(Module* aModule);
		void RemoveModule(Module* aModule);
		
		void OnCursorMovedEvent(float aXPos, float aYPos);
		void OnMouseButtonEvent(MouseButton aMouseButton, InputAction aInputAction);
		void OnResizeWindowEvent(unsigned int aWidth, unsigned int aHeight);
		void OnKeyWindowEvent(KeyId aKeyId, InputAction aInputAction);
		void OnFileDropped(const std::string& aPath);
		ResourceManager* GetResourceManager();
	
	private:		
		std::vector<Module*> mModules;
		ResourceManager* mResourceManager;
		
	};

	Application* CreateApplication();
}



