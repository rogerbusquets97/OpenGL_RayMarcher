#ifndef ENGINE_PERSPECTIVE_CAMERA
#define ENGINE_PERSPECTIVE_CAMERA

#include "Core.h"
#include "Camera.h"

namespace ENGINE_API Engine
{
	class ENGINE_API PerspectiveCamera : public Camera
	{
	public:
		PerspectiveCamera(float aFOV = 45.0f);
		PerspectiveCamera(const glm::vec3& aPosition, const glm::vec3& aUpDirection, float aNear, float aFar, float aFOV = 45.0f);
		~PerspectiveCamera();

		const float GetFOV() const;
		void SetFOV(float aFOV);

	protected:
		virtual void RecalculateProjectionMatrix() override;

	private:
		float			mFOV;

	};
}

#endif