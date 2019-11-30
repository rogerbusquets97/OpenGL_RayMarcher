#pragma once
#include "Window.h"
#include "../Core.h"
namespace Engine
{
	class ENGINE_API GLFWWindow : public Window
	{
	public:
		GLFWWindow(const WindowData& aData);
		virtual ~GLFWWindow();
		virtual void Update() override;
		virtual unsigned int GetWidth() override;
		virtual unsigned int GetHeight() override;
		virtual void SetEventCallback(EventHandler aCallback) override;
		virtual void SetVSync(const bool aEnabled) override;
		virtual bool IsVSyncEnabled() override;

	private:
		EventHandler mEventCallback;
	};
}

