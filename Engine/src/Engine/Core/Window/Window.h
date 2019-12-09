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
		Window(const WindowSettings& aSettings) : mSettings(aSettings) {}
		virtual ~Window() {};

		virtual void Update() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual void SetEventCallback(const EventHandler& aCallback) = 0;
		virtual void SetVSync(const bool aEnabled) = 0;
		virtual bool IsVSyncEnabled() const = 0;

		static Window* Create(const WindowSettings& aData = WindowSettings());
		inline static glm::vec2 GetResolution() { return mResolution; }
	private:

		WindowSettings mSettings;
		static glm::vec2 mResolution;
	};
}

