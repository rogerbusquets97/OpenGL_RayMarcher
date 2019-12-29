#include "PerspectiveCamera.h"
#include <gtc/matrix_transform.hpp>

namespace Engine
{
	PerspectiveCamera::PerspectiveCamera(float aFOV) :
		Camera(),
		mFOV(aFOV)
	{
	}
	
	PerspectiveCamera::PerspectiveCamera(const glm::vec3& aPosition, const glm::vec3& aUpDirection, float aNear, float aFar, float aFOV) :
		Camera(aPosition, aUpDirection, aNear, aFar),
		mFOV(aFOV)
	{
	}

	PerspectiveCamera::~PerspectiveCamera()
	{

	}

	const float PerspectiveCamera::GetFOV() const
	{
		return mFOV;
	}

	void PerspectiveCamera::SetFOV(float aFOV)
	{
		mFOV = aFOV;
		RecalculateProjectionMatrix();
	}

	void PerspectiveCamera::RecalculateProjectionMatrix()
	{
		mProjectionMatrix = glm::perspective(glm::radians(mFOV), mWidth / mHeight, mNear, mFar);
	}
}