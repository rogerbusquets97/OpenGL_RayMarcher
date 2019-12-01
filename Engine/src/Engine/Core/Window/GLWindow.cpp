#include "GLWindow.h"
#include "../../Log/Log.h"

namespace Engine
{
	static void ErrorCallback(int aError, const char* aDescription)
	{
		ENGINE_CORE_ERROR("GLFW Error ({0}) : {1}", aError, aDescription);
	}

	GLWindow::GLWindow(const WindowSettings& aSettings) : Window(aSettings)
	{
		Init(aSettings);
	}


	GLWindow::~GLWindow()
	{
		CleanUp();
	}

	void GLWindow::Update()
	{
		glfwPollEvents();
		mContext->SwapBuffers();
	}

	unsigned int GLWindow::GetWidth() const
	{
		return mData.Width;
	}

	unsigned int GLWindow::GetHeight() const
	{
		return mData.Height;
	}

	void GLWindow::SetEventCallback(const EventHandler& aCallback)
	{
		mData.EventCallback = aCallback;
	}

	void GLWindow::SetVSync(const bool aEnabled)
	{
		if(aEnabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		mData.VSync = aEnabled;
	}

	bool GLWindow::IsVSyncEnabled() const
	{
		return mData.VSync;
	}

	GLFWwindow * GLWindow::GetGLFWwindow() const
	{
		return mWindow;
	}

	void GLWindow::Init(const WindowSettings & aSettings)
	{
		mData.Width = aSettings.Width;
		mData.Height = aSettings.Height;
		mData.Title = aSettings.Title;

		int success = glfwInit();
		if (!success)
			ENGINE_CORE_ERROR("Could not initialize GLFW");
		else
		{
			glfwSetErrorCallback(ErrorCallback);
			mWindow = glfwCreateWindow(mData.Width, mData.Height, mData.Title.c_str(), NULL, NULL);
			if (!mWindow)
			{
				glfwTerminate();
				ENGINE_CORE_ERROR("Could not create GLFW Window");
			}
			else
			{
				mContext = GraphicsContext::Create(this);
				mContext->Init();

				glfwSetWindowUserPointer(mWindow, &mData);
				SetVSync(true);

				//Callbacks
			}
		}
	}

	void GLWindow::CleanUp()
	{
		glfwDestroyWindow(mWindow);
		glfwTerminate();
	}

	Window* Window::Create(const WindowSettings& aSettings)
	{
		return new GLWindow(aSettings);
	}

	static void MouseButtonCallback(GLFWwindow* aWindow, int button, int action, int mods)
	{
		const WindowData& Data = *(WindowData*)glfwGetWindowUserPointer(aWindow);
		
		switch (action)
		{
			case GLFW_PRESS:
			{
				break;
			}
			case GLFW_RELEASE:
			{
				break;
			}
		}
	}

}
