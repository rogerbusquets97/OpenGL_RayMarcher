#pragma once
#include <Core.h>
#include <string>
#include <Events/Event.h>
#include <vec2.hpp>

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
		virtual ~Window() = default;

		virtual void Update() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		//virtual void SetEventCallback(const EventHandler& aCallback) = 0;
		virtual void SetVSync(const bool aEnabled) = 0;
		virtual bool IsVSyncEnabled() const = 0;
		virtual void* GetNativeWindow() const = 0;
		static std::shared_ptr<Window> Create(const WindowSettings& aData = WindowSettings());
	};
}

