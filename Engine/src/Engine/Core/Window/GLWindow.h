#pragma once
#include "Window.h"
#include <Core.h>
#include <Renderer/GraphicsContext.h>

struct GLFWwindow;

namespace Engine
{
	class ENGINE_API GLWindow : public Window
	{
	public:
		GLWindow(const WindowSettings& aSettings);
		virtual ~GLWindow();
		virtual bool Update() override;
		virtual void SetVSync(const bool aEnabled) override;
		virtual bool IsVSyncEnabled() const override;
		virtual void* GetNativeWindow() const override;

	private:
		virtual void Init(const WindowSettings& aSettings);
		virtual void CleanUp();

	private:
		GLFWwindow* mWindow;
		std::shared_ptr<GraphicsContext> mContext;
	};
}

