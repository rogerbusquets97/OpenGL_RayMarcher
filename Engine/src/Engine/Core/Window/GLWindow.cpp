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

				glfwSetCursorPosCallback(mWindow, [](GLFWwindow* aWindow, double xPos, double yPos)
				{
					WindowData& Data = *(WindowData*)glfwGetWindowUserPointer(aWindow);

					(*Data.WindowEvents.mCursorMovedEvent)(static_cast<float>(xPos), static_cast<float>(yPos));
				});
				
				glfwSetMouseButtonCallback(mWindow, [](GLFWwindow* aWindow, int aButton, int aAction, int aMods)
				{
					WindowData& Data = *(WindowData*)glfwGetWindowUserPointer(aWindow);
					const MouseButton& MouseButton = Data.WindowEvents.GetMouseButton(aButton);
					const InputAction& Action = Data.WindowEvents.GetInputAction(aAction);

					(*Data.WindowEvents.mMouseButtonEvent)(MouseButton, Action);
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

					const InputAction &Action = Data.WindowEvents.GetInputAction(aAction);
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

	void GLWindow::GenerateMouseButtonMapping()
	{
		WindowEventsContainer::MouseButtonContainer Mapping;

		Mapping.emplace(GLFW_MOUSE_BUTTON_LAST, MouseButton::Last);
		Mapping.emplace(GLFW_MOUSE_BUTTON_LEFT, MouseButton::Left);
		Mapping.emplace(GLFW_MOUSE_BUTTON_RIGHT, MouseButton::Right);
		Mapping.emplace(GLFW_MOUSE_BUTTON_MIDDLE, MouseButton::Middle);
		
		mData.WindowEvents.SetMouseButtonContainer(Mapping);
	}

	void GLWindow::GenerateInputActionMapping()
	{
		WindowEventsContainer::InputActionContainer Mapping;

		Mapping.emplace(GLFW_RELEASE, InputAction::Released);
		Mapping.emplace(GLFW_PRESS, InputAction::Pressed);
		Mapping.emplace(GLFW_REPEAT, InputAction::Repeat);

		mData.WindowEvents.SetInputActionContainer(Mapping);
	}

	void GLWindow::GenerateKeyIdMapping()
	{
		WindowEventsContainer::KeyIdContainer Mapping;

		Mapping.emplace(GLFW_KEY_SPACE, KeyId::Space);
		Mapping.emplace(GLFW_KEY_COMMA, KeyId::Comma);
		Mapping.emplace(GLFW_KEY_SEMICOLON, KeyId::Semicolon);
		Mapping.emplace(GLFW_KEY_ENTER, KeyId::Enter);
		Mapping.emplace(GLFW_KEY_ESCAPE, KeyId::Escape);
		Mapping.emplace(GLFW_KEY_DELETE, KeyId::Delete);
		Mapping.emplace(GLFW_KEY_0, KeyId::Num_0);
		Mapping.emplace(GLFW_KEY_1, KeyId::Num_1);
		Mapping.emplace(GLFW_KEY_2, KeyId::Num_2);
		Mapping.emplace(GLFW_KEY_3, KeyId::Num_3);
		Mapping.emplace(GLFW_KEY_4, KeyId::Num_4);
		Mapping.emplace(GLFW_KEY_5, KeyId::Num_5);
		Mapping.emplace(GLFW_KEY_6, KeyId::Num_6);
		Mapping.emplace(GLFW_KEY_7, KeyId::Num_7);
		Mapping.emplace(GLFW_KEY_8, KeyId::Num_8);
		Mapping.emplace(GLFW_KEY_9, KeyId::Num_9);
		Mapping.emplace(GLFW_KEY_A, KeyId::A);
		Mapping.emplace(GLFW_KEY_B, KeyId::B);
		Mapping.emplace(GLFW_KEY_C, KeyId::C);
		Mapping.emplace(GLFW_KEY_D, KeyId::D);
		Mapping.emplace(GLFW_KEY_E, KeyId::E);
		Mapping.emplace(GLFW_KEY_F, KeyId::F);
		Mapping.emplace(GLFW_KEY_G, KeyId::G);
		Mapping.emplace(GLFW_KEY_H, KeyId::H);
		Mapping.emplace(GLFW_KEY_I, KeyId::I);
		Mapping.emplace(GLFW_KEY_J, KeyId::J);
		Mapping.emplace(GLFW_KEY_K, KeyId::K);
		Mapping.emplace(GLFW_KEY_L, KeyId::L);
		Mapping.emplace(GLFW_KEY_M, KeyId::M);
		Mapping.emplace(GLFW_KEY_N, KeyId::N);
		Mapping.emplace(GLFW_KEY_O, KeyId::O);
		Mapping.emplace(GLFW_KEY_P, KeyId::P);
		Mapping.emplace(GLFW_KEY_Q, KeyId::Q);
		Mapping.emplace(GLFW_KEY_R, KeyId::R);
		Mapping.emplace(GLFW_KEY_S, KeyId::S);
		Mapping.emplace(GLFW_KEY_T, KeyId::T);
		Mapping.emplace(GLFW_KEY_U, KeyId::U);
		Mapping.emplace(GLFW_KEY_V, KeyId::V);
		Mapping.emplace(GLFW_KEY_W, KeyId::W);
		Mapping.emplace(GLFW_KEY_X, KeyId::X);
		Mapping.emplace(GLFW_KEY_Y, KeyId::Y);
		Mapping.emplace(GLFW_KEY_Z, KeyId::Z);
		//TODO add more keys...

		mData.WindowEvents.SetKeyIdContainer(Mapping);
	}

	std::shared_ptr<Window> Window::Create(const WindowSettings& aSettings)
	{
		return std::make_shared<GLWindow>(aSettings);
	}

}
