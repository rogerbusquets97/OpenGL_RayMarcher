#pragma once
#include "Core.h"
#include <vector>
#include "Events/Event.h"
#include <Module.h>

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
		void OnEvent(MemoryBuffer& aData);
	private:
		std::vector<Module*> mModules;
	};

	Application* CreateApplication();
}

