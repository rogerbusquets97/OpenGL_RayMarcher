#pragma once
#include <Core.h>
#include <Window/Window.h>
#include <Module.h>

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
		virtual bool Awake() override;
		virtual bool PreUpdate() override;
		virtual bool PostUpdate() override;
		virtual void OnEvent(MemoryBuffer& aData) override;
		virtual void SetEventCallback(const EventHandler& aCallback);

		static uint32_t GetWidth();
		static uint32_t GetHeight();
		static void* GetNativeWindow();

	private:
		static std::shared_ptr<Window> mWindow;
	};
}

