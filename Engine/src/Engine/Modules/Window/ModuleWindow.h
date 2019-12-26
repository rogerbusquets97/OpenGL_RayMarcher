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

		virtual void OnMouseEvent(int aButton, int aAction) override;
		virtual void OnKeyWindowEvent(KeyId aKeyId, KeyAction aKeyAction) override;

		static uint32_t GetWidth();
		static uint32_t GetHeight();
		static void* GetNativeWindow();

	private:
		static std::shared_ptr<Window> mWindow;
		bool mMustClose;
	};
}

