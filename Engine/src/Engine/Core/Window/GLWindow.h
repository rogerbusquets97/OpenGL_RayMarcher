#ifndef ENGINE_GL_WINDOW
#define ENGINE_GL_WINDOW

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
		virtual void Init(const WindowSettings& aSettings) override;
		virtual void CleanUp();
		virtual void GenerateKeyActionMapping() override;
		virtual void GenerateKeyIdMapping() override;

	private:
		GLFWwindow* mWindow;
		std::shared_ptr<GraphicsContext> mContext;
	};
}

#endif