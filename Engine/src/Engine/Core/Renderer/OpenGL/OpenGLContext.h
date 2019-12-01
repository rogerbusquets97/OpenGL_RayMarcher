#pragma once
#include "../../Core.h"
#include "../GraphicsContext.h"
#include "../../Window/GLWindow.h"

namespace Engine
{
	class ENGINE_API OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLWindow* aWindow);
		virtual ~OpenGLContext();
		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLWindow* mWindowHandle;
	};
}

