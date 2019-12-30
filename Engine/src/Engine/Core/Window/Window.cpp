#include "Window.h"

namespace Engine
{
	Window::Window() : mData()
	{

	}

	Window::~Window()
	{

	}

	void Window::Init(const WindowSettings& aSettings)
	{
		GenerateInputActionMapping();
		GenerateMouseButtonMapping();
		GenerateKeyIdMapping();

		mData.Width = aSettings.Width;
		mData.Height = aSettings.Height;
		mData.Title = aSettings.Title;
	}

	unsigned int Window::GetWidth() const
	{
		return mData.Width;
	}

	unsigned int Window::GetHeight() const
	{
		return mData.Height;
	}

	WindowEventsContainer& Window::GetWindowEvents()
	{
		return mData.WindowEvents;
	}
}