#include "Camera.h"

namespace Engine
{
	Camera::Camera(const glm::vec3& aPosition, const glm::vec3& aVRP, const glm::vec3& aUp, float aNear, float aFar) :
		mPosition(aPosition),
		mVRP(aVRP),
		mUp(aUp),
		mNear(aNear),
		mFar(aFar)
	{

	}
	
	Camera::~Camera()
	{

	}

	const glm::vec3& Camera::GetPosition()
	{

	}

	void Camera::SetPosition(const glm::vec3& aPosition)
	{

	}

	const glm::vec3& Camera::GetVRP()
	{

	}

	void Camera::SetVRP(const glm::vec3& aVRP)
	{

	}

	const glm::vec3& Camera::GetUp()
	{

	}

	void Camera::SetUp(const glm::vec3& aUp)
	{

	}

	const float Camera::GetNear()
	{

	}

	void Camera::SetNear(float aNear)
	{

	}

	const float Camera::GetFar()
	{

	}

	void Camera::SetFar(float aFar)
	{

	}

	const glm::mat4& Camera::GetViewMatrix()
	{
		//return glm::lookAt(mPosition, mVRP, mUp);
	}

	const glm::mat4& Camera::GetProjectionMatrix()
	{

	}
}