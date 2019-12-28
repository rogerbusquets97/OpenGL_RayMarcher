#ifndef ENGINE_MODULE_CAMERA
#define ENGINE_MODULE_CAMERA

#include <Core.h>
#include "Module.h"
#include "Camera/Camera.h"

namespace Engine
{
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

		virtual void OnMouseEvent(int aButton, int aAction) override;
		virtual void OnKeyWindowEvent(KeyId aKeyId, KeyAction aKeyAction) override;

		static const Camera& GetCamera();

	private:
		static Camera			mCamera;
	};
}

#endif