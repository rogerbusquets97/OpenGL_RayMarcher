#include "Camera.h"
#include <gtc/matrix_transform.hpp>

namespace Engine
{
	Camera::Camera(const glm::vec3& aPosition, const glm::vec3& aUpDirection, float aNear, float aFar, float aFOV) :
		mPosition(aPosition),
		mViewDirection(),
		mUpDirection(aUpDirection),
		mRightDirection(),
		mNear(aNear),
		mFar(aFar),
		mFOV(aFOV),
		mYaw(-90.f),
		mPitch(0.f),
		mWidth(),
		mHeight()
	{
		RecalculateViewDirection();
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

	const glm::vec3& Camera::GetViewDirection() const
	{
		return mViewDirection;
	}
	
	const glm::vec3& Camera::GetRightDirection() const
	{
		return mRightDirection;
	}

	const glm::vec3& Camera::GetUpDirection() const
	{
		return mUpDirection;
	}

	void Camera::SetUpDirection(const glm::vec3& aUpDirection)
	{
		mUpDirection = aUpDirection;
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

	const float Camera::GetFOV() const
	{
		return mFOV;
	}

	void Camera::SetFOV(float aFOV)
	{
		mFOV = aFOV;
	}

	const float Camera::GetYaw() const
	{
		return mYaw;
	}

	void Camera::SetYaw(float aYaw)
	{
		mYaw = aYaw;
		RecalculateViewDirection();
	}

	const float Camera::GetPitch() const
	{
		return mPitch;
	}

	void Camera::SetPitch(float aPitch)
	{
		mPitch = aPitch;
		RecalculateViewDirection();
	}

	void Camera::SetWidth(float aWidth)
	{
		mWidth = aWidth;
	}

	void Camera::SetHeight(float aHeight)
	{
		mHeight = aHeight;
	}

	const glm::mat4& Camera::GetViewMatrix() const
	{
		//TODO save to avoid calculation each frame?
		std::cout << "Look at from popsition " << mPosition.x << " " << mPosition.y << " " << mPosition.z <<
			" and direction " << mViewDirection.x << " " << mViewDirection.y << " " << mViewDirection.z << std::endl;
		return glm::lookAt(mPosition, mPosition + mViewDirection, mUpDirection);
	}

	const glm::mat4& Camera::GetProjectionMatrix() const
	{
		//TODO save to avoid calculation each frame?

		return glm::perspective(glm::radians(mFOV), mWidth / mHeight, mNear, mFar);
	}

	void Camera::RecalculateViewDirection()
	{
		mViewDirection.x = cos(glm::radians(mPitch)) * cos(glm::radians(mYaw));
		mViewDirection.y = sin(glm::radians(mPitch));
		mViewDirection.z = cos(glm::radians(mPitch)) * sin(glm::radians(mYaw));
		mViewDirection = glm::normalize(mViewDirection);

		mRightDirection = glm::normalize(glm::cross(mViewDirection, mUpDirection));
	}

}