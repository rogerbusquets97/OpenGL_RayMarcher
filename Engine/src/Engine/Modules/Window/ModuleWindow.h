#pragma once
#include <Core.h>
#include <Window/Window.h>
#include <Module.h>

namespace rubEngine
{
	class CInput;

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

		uint32_t GetWidth() const noexcept;
		uint32_t GetHeight() const noexcept;
		void* GetNativeWindow() const noexcept;

		const std::shared_ptr<Window>& GetWindow() const noexcept;

	private:
		std::shared_ptr<Window> mWindow;
		bool mMustClose;
	};
}

