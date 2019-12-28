#include "Camera.h"
#include <gtc/matrix_transform.hpp>

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

	const glm::vec3& Camera::GetPosition() const
	{
		return mPosition;
	}

	void Camera::SetPosition(const glm::vec3& aPosition)
	{
		mPosition = aPosition;
	}

	const glm::vec3& Camera::GetVRP() const
	{
		return mVRP;
	}

	void Camera::SetVRP(const glm::vec3& aVRP)
	{
		mVRP = aVRP;
	}

	const glm::vec3& Camera::GetUp() const
	{
		return mUp;
	}

	void Camera::SetUp(const glm::vec3& aUp)
	{
		mUp = aUp;
	}

	const float Camera::GetNear() const
	{
		return mNear;
	}

	void Camera::SetNear(float aNear)
	{
		mNear = aNear;
	}

	const float Camera::GetFar() const
	{
		return mFar;
	}

	void Camera::SetFar(float aFar)
	{
		mFar = aFar;
	}

	const glm::mat4& Camera::GetViewMatrix() const
	{
		return glm::lookAt(mPosition, mVRP, mUp);
	}

	const glm::mat4& Camera::GetProjectionMatrix() const
	{
		//TODO
		return glm::mat4();
	}
}