#include "GLWindow.h"
#include <Log/Log.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine
{
	glm::vec2 Window::mResolution = glm::vec2();

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
		mData.EventCallback += aCallback;
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

					MemoryBuffer Buffer;
					Buffer.Write(EVENT_TYPE::MOUSE_BUTTON_PRESSED);
					Buffer.Write(aButton);
					Buffer.Write(aAction);

					Data.EventCallback(Buffer);
				});

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
		Window::mResolution = glm::vec2(aSettings.Width, aSettings.Height);
		return new GLWindow(aSettings);
	}
}
