#include "GLFWWindow.h"

namespace Engine
{
	GLFWWindow::GLFWWindow(const WindowData& aData) : Window(aData)
	{
	}


	GLFWWindow::~GLFWWindow()
	{
	}

	Window* Window::Create(const WindowData& aData)
	{
		return new GLFWWindow(aData);
	}

}
