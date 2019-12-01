#pragma once
#include "Core.h"
#include <vector>
#include "Events/Event.h"
#include "../Modules/Module.h"

namespace Engine
{
	class ModuleWindow;

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
		void OnEvent(EventData& aData);
	private:
		std::vector<Module*> mModules;
		ModuleWindow* mWindow;
	};

	Application* CreateApplication();
}

