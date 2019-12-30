#ifndef ENGINE_ORTHOGONAL_CAMERA
#define ENGINE_ORTHOGONAL_CAMERA

#include "Core.h"
#include "Camera.h"

namespace ENGINE_API Engine
{
	class ENGINE_API OrthogonalCamera : public Camera
	{
	public:
		OrthogonalCamera();
		OrthogonalCamera(const glm::vec3& aPosition, const glm::vec3& aUpDirection, float aNear, float aFar);
		~OrthogonalCamera();

		const glm::vec2& GetCenter() const;
		void SetCenter(glm::vec2 aCenter);

	protected:
		virtual void RecalculateProjectionMatrix() override;

	private:
		glm::vec2			mCenter;

	};
}

#endif