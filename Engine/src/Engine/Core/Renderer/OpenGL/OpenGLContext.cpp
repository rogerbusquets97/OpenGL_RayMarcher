#include "OpenGLContext.h"
#include "../../../Log/Log.h"

namespace Engine
{
	OpenGLContext::OpenGLContext(GLWindow* aWindow) : mWindowHandle(aWindow)
	{
	}
	OpenGLContext::~OpenGLContext()
	{
	}
	void OpenGLContext::Init()
	{
		if (mWindowHandle != nullptr)
		{
			glfwMakeContextCurrent(mWindowHandle->GetGLFWwindow());
		}
		else
		{
			ENGINE_CORE_ERROR("NULL WINDOW HANDLE!");
		}
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(mWindowHandle->GetGLFWwindow());
	}
}
