#pragma once
#include "../../Core/Core.h"
#include "../../Core/Window/Window.h"
#include "../Module.h"

namespace Engine
{
	class ENGINE_API ModuleWindow : public Module
	{
	public:
		ModuleWindow(Application* aApplication);
		virtual ~ModuleWindow();

		virtual bool Init() override;
		virtual bool Update() override;
		virtual bool CleanUp() override;
		virtual void OnEvent(EventData& aData) override;
		void SetEventCallback(const EventHandler& aCallback);

	private:
		Window* mWindow;
	};
}

