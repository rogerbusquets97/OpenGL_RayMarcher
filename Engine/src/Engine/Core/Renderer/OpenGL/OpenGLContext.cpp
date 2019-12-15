#include "OpenGLContext.h"
#include <Log/Log.h>
#include <GLFW/glfw3.h>

namespace Engine
{
	OpenGLContext::OpenGLContext(GLFWwindow* aWindow) : mWindowHandle(aWindow)
	{
	}
	OpenGLContext::~OpenGLContext()
	{
	}
	void OpenGLContext::Init()
	{
		if (mWindowHandle != nullptr)
		{
			glfwMakeContextCurrent(mWindowHandle);
		}
		else
		{
			ENGINE_CORE_ERROR("NULL WINDOW HANDLE!");
		}
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(mWindowHandle);
	}
}
