#pragma once
#include <string>
#include "Core.h"
#include "Window/Inputs.h"
#include <vector>

namespace Engine
{
	class Application;

	class ENGINE_API Module
	{
	public:

		Module()
		{
		}

		virtual ~Module() {}
		virtual bool Awake() = 0;
		virtual bool Init() = 0;
		virtual bool CleanUp() = 0;
		virtual bool PreUpdate(float aDeltaTime) = 0;
		virtual bool Update(float aDeltaTime) = 0;
		virtual bool PostUpdate(float aDeltaTime) = 0;
		virtual void OnGUI() {};

		virtual void OnCursorMovedEvent(float aXPos, float aYPos) {}
		virtual void OnMouseButtonEvent(MouseButton aMouseButton, InputAction aInputAction) {}
		virtual void OnResizeWindowEvent(unsigned int aWidth, unsigned int aHeight) {}
		virtual void OnKeyWindowEvent(KeyId aKeyId, InputAction aInputAction) {}
		virtual void OnFileDropped(const std::string& aPath) {}
	};
}

