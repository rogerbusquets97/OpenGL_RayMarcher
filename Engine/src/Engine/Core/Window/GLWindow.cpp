#include "GLWindow.h"
#include <Log/Log.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Events/Event.h"

namespace Engine
{
	static void ErrorCallback(int aError, const char* aDescription)
	{
		ENGINE_CORE_ERROR("GLFW Error ({0}) : {1}", aError, aDescription);
	}

	GLWindow::GLWindow(const WindowSettings& aSettings) : Window(), mWindow(nullptr), mContext()
	{
		Init(aSettings);
	}

	GLWindow::~GLWindow()
	{
		CleanUp();
	}

	bool GLWindow::Update()
	{
		bool ReturnValue(false);

		if (!glfwWindowShouldClose(mWindow))
		{
			glfwPollEvents();
			mContext->SwapBuffers();
			ReturnValue = true;
		}

		return ReturnValue;
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

	void * GLWindow::GetNativeWindow() const
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
				mContext = GraphicsContext::Create(GetNativeWindow());
				mContext->Init();
				int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

				if (!status)
				{
					ENGINE_CORE_ERROR("Couldn't initialize GLAD");
				}

				glfwSetWindowUserPointer(mWindow, &mData);
				SetVSync(true);

				//Callbacks

				glfwSetMouseButtonCallback(mWindow, [](GLFWwindow* aWindow, int aButton, int aAction, int aMods)
					{
						WindowData& Data = *(WindowData*)glfwGetWindowUserPointer(aWindow);

						(*Data.WindowEvents.mMouseEvent)(aButton, aAction);
					});

				glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* aWindow, int aWidth, int aHeight)
					{
						WindowData& Data = *(WindowData*)glfwGetWindowUserPointer(aWindow);
						
						Data.Width = aWidth;
						Data.Height	= aWidth;
						
						(*Data.WindowEvents.mResizeWindowsEvent)(aWidth, aHeight);
					});
			}
		}
	}

	void GLWindow::CleanUp()
	{
		glfwDestroyWindow(mWindow);
		glfwTerminate();
	}

	std::shared_ptr<Window> Window::Create(const WindowSettings& aSettings)
	{
		return std::make_shared<GLWindow>(aSettings);
	}
}
