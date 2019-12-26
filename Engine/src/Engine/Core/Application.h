#pragma once
#include "Core.h"
#include <vector>
#include <Module.h>
#include "Window/Keys.h"

namespace Engine
{
	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		bool Run();
		bool Init();
		bool CleanUp();
		void AddModule(Module* aModule);
		void RemoveModule(Module* aModule);
		
		void OnMouseEvent(int aButton, int aAction);
		void OnResizeWindowEvent(unsigned int aWidth, unsigned int aHeight);
		void OnKeyWindowEvent(KeyId aKeyId, KeyAction aKeyAction);
	
	private:		
		std::vector<Module*> mModules;
	};

	Application* CreateApplication();
}



