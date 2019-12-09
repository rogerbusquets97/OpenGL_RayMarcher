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
		//I know sending a buffer is kinda dangerous ... It's the simplest solution right now. (Will properly implement events in the future).
		void OnEvent(MemoryBuffer& aData);
	private:		
		std::vector<Module*> mModules;
	};

	Application* CreateApplication();
}



