#pragma once
#include "Core.h"
#include "../Modules/Module.h"
#include <list>

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
		void OnEvent(const EventData& aData);
	private:
		std::list<Module*> mModules;
	};

	Application* CreateApplication();
}

