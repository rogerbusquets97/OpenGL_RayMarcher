#ifndef ENGINE_MODULE_CAMERA
#define ENGINE_MODULE_CAMERA

#include <Core.h>
#include "Module.h"

namespace Engine
{
	class Camera;

	class ENGINE_API ModuleCamera : public Module
	{
	public:

		ModuleCamera(Application* aApplication);
		~ModuleCamera();
		virtual bool Init() override;
		virtual bool Update(float aDeltaTime) override;
		virtual bool CleanUp() override;
		virtual bool Awake() override;
		virtual bool PreUpdate(float aDeltaTime) override;
		virtual bool PostUpdate(float aDeltaTime) override;

		virtual void OnCursorMovedEvent(float aXPos, float aYPos) override;
		virtual void OnMouseButtonEvent(MouseButton aMouseButton, InputAction aInputAction) override;
		virtual void OnKeyWindowEvent(KeyId aKeyId, InputAction aInputAction) override;
		virtual void OnResizeWindowEvent(unsigned int aWidth, unsigned int aHeight) override;

		static const std::shared_ptr<Camera> GetCamera();

	private:
		static std::shared_ptr<Camera>			mCamera;

		bool									mRotateCamera;
		float									mPreviousCursorX;
		float									mPreviousCursorY;
	};
}

#endif