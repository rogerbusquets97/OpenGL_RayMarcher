#ifndef ENGINE_CAMERA
#define ENGINE_CAMERA

#include "Core.h"
#include <vec3.hpp>
#include <mat4x4.hpp>

namespace ENGINE_API Engine
{
	class Camera
	{
	public:

		Camera(const glm::vec3& aPosition = {0.f, 0.f, 0.f}, const glm::vec3& aUpDirection = { 0.f, 1.f, 0.f}, float aNear =  0.1f, float aFar = 50.f, float aFOV = 45.0f);
		~Camera();

		const glm::vec3& GetPosition() const;
		void SetPosition(const glm::vec3& aPosition);

		const glm::vec3& GetViewDirection() const;
		
		const glm::vec3& GetRightDirection() const;

		const glm::vec3& GetUpDirection() const;
		void SetUpDirection(const glm::vec3& aUpDirection);

		const float GetNear() const;
		void SetNear(float aNear);

		const float GetFar() const;
		void SetFar(float aFar);
		
		const float GetFOV() const;
		void SetFOV(float aFOV);

		const float GetYaw() const;
		void SetYaw(float aYaw);

		const float GetPitch() const;
		void SetPitch(float aPitch);

		void SetSize(float aWidth, float aHeight);

		const glm::mat4& GetViewMatrix() const;

		const glm::mat4& GetProjectionMatrix() const;

	private:
		void RecalculateViewDirection();
		void RecalculateViewMatrix();
		void RecalculateProjectionMatrix();

	private:
		glm::vec3		mPosition;

		glm::vec3		mViewDirection;
		glm::vec3		mUpDirection;
		glm::vec3		mRightDirection;

		float			mNear;
		float			mFar;
		float			mFOV;

		float			mYaw;
		float			mPitch;

		float			mWidth;
		float			mHeight;

		glm::mat4		mViewMatrix;
		glm::mat4		mProjectionMatrix;
	};
}

#endif

