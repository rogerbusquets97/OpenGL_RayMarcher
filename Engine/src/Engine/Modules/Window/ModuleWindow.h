#pragma once
#include <Core.h>
#include <Window/Window.h>
#include <Module.h>

namespace Engine
{
	class ENGINE_API ModuleWindow : public Module
	{
	public:
		ModuleWindow();
		virtual ~ModuleWindow();

		virtual bool Init() override;
		virtual bool Update(float aDeltaTime) override;
		virtual bool CleanUp() override;
		virtual bool Awake() override;
		virtual bool PreUpdate(float aDeltaTime) override;
		virtual bool PostUpdate(float aDeltaTime) override;

		virtual void OnKeyWindowEvent(KeyId aKeyId, InputAction aInputAction) override;

		static uint32_t GetWidth();
		static uint32_t GetHeight();
		static void* GetNativeWindow();

	private:
		static std::shared_ptr<Window> mWindow;
		bool mMustClose;
	};
}

