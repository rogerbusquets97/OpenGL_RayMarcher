#pragma once
#include "../Core.h"
#include <string>
#include "../Events/Event.h"

namespace Engine
{
	struct WindowData
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		
		WindowData(const std::string& aTitle = "RayMarcher", unsigned int aWidth = 1280, unsigned int aHeight = 720) :
			Title(aTitle),
			Width(aWidth),
			Height(aHeight)
		{
		}
	};

	class ENGINE_API Window
	{
	public:
		Window(const WindowData& aData) : mData(aData) {}
		virtual ~Window() {};

		virtual void Update() = 0;
		virtual unsigned int GetWidth() = 0;
		virtual unsigned int GetHeight() = 0;
		virtual void SetEventCallback(EventHandler aCallback) = 0;
		virtual void SetVSync(const bool aEnabled) = 0;
		virtual bool IsVSyncEnabled() = 0;

		static Window* Create(const WindowData& aData = WindowData());

	private:

		WindowData mData;
	};
}

