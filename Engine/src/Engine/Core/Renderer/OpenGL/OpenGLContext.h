#pragma once
#include <Core.h>
#include "../GraphicsContext.h"
#include <Window/GLWindow.h>

namespace rubEngine
{
	class ENGINE_API OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* aWindow);
		virtual ~OpenGLContext();
		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* mWindowHandle;
	};
}

