#pragma once
#include <string>
#include "Core.h"
#include "Window/Inputs.h"

namespace Engine
{
	class Application;

	class ENGINE_API Module
	{
	public:

		Module(const std::string& aName, Application* aApplication)
		{
			mName = aName;
			mApplication = aApplication;
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

		inline const std::string& GetName() const { return mName; }

	protected:
		std::string mName;
		Application* mApplication;
	};
}

