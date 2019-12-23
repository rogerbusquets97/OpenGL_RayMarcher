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
		if (aEnabled)
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
		Window::Init(aSettings);

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

				glfwSetKeyCallback(mWindow, [](GLFWwindow* aWindow, int aKey, int aScancode, int aAction, int aMods)
				{
					WindowData& Data = *(WindowData*)glfwGetWindowUserPointer(aWindow);

					const KeyAction &Action = Data.WindowEvents.GetKeyAction(aAction);
					const KeyId& Id = Data.WindowEvents.GetKeyId(aKey);
					(*Data.WindowEvents.mKeyEvent)(Id, Action);
				});
			}
		}
	}

	void GLWindow::CleanUp()
	{
		glfwDestroyWindow(mWindow);
		glfwTerminate();
	}

	void GLWindow::GenerateKeyActionMapping()
	{
		WindowEventsContainer::KeyActionContainer Mapping;

		Mapping.emplace(GLFW_RELEASE, KeyAction::Released);
		Mapping.emplace(GLFW_PRESS, KeyAction::Pressed);
		Mapping.emplace(GLFW_REPEAT, KeyAction::Repeat);

		mData.WindowEvents.SetKeyActionContainer(std::move(Mapping));
	}

	void GLWindow::GenerateKeyIdMapping()
	{
		WindowEventsContainer::KeyIdContainer Mapping;

		Mapping.emplace(GLFW_KEY_A, KeyId::A);
		Mapping.emplace(GLFW_KEY_ESCAPE, KeyId::Escape);
		//TODO add more keys...

		mData.WindowEvents.SetKeyIdContainer(std::move(Mapping));
	}

	std::shared_ptr<Window> Window::Create(const WindowSettings& aSettings)
	{
		return std::make_shared<GLWindow>(aSettings);
	}

}
