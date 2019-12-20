#pragma once
#include <Core.h>
#include <string>
#include "WindowEventsContainer.h"

namespace Engine
{
	struct WindowSettings
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		
		WindowSettings(const std::string& aTitle = "OpenGL Renderer", unsigned int aWidth = 720, unsigned int aHeight = 720) :
			Title(aTitle),
			Width(aWidth),
			Height(aHeight)
		{
		}
	};

	class ENGINE_API Window
	{
	public:
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			WindowEventsContainer WindowEvents;
		};

		Window() : mData() {};

		virtual ~Window() = default;

		virtual bool Update() = 0;

		unsigned int GetWidth() const
		{
			return mData.Width;
		}

		unsigned int GetHeight() const
		{
			return mData.Height;
		}
		
		WindowEventsContainer& GetWindowEvents()
		{
			return mData.WindowEvents;
		}

		virtual void SetVSync(const bool aEnabled) = 0;
		virtual bool IsVSyncEnabled() const = 0;
		virtual void* GetNativeWindow() const = 0;
		static std::shared_ptr<Window> Create(const WindowSettings& aData = WindowSettings());

	protected:
		WindowData mData;

	};
}

