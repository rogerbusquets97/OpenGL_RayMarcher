#pragma once
#include "Window.h"
#include <Core.h>
#include <Renderer/GraphicsContext.h>
#include <Events/EventTypes.h>

struct GLFWwindow;

namespace Engine
{
	struct WindowData
	{
		std::string Title;
		unsigned int Width, Height;
		bool VSync;
		tMouseEvent EventCallback;
	};

	class ENGINE_API GLWindow : public Window
	{
	public:
		GLWindow(const WindowSettings& aSettings);
		virtual ~GLWindow();
		virtual void Update() override;
		virtual unsigned int GetWidth() const override;
		virtual unsigned int GetHeight() const override;
		//virtual void SetEventCallback(const EventHandler& aCallback) override;
		virtual void SetVSync(const bool aEnabled) override;
		virtual bool IsVSyncEnabled() const override;
		virtual void* GetNativeWindow() const override;

	private:
		virtual void Init(const WindowSettings& aSettings);
		virtual void CleanUp();

	private:
		GLFWwindow* mWindow;
		WindowData mData;
		std::shared_ptr<GraphicsContext> mContext;
	};
}

