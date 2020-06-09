#ifndef ENGINE_CAMERA
#define ENGINE_CAMERA

#include "Core.h"
#include <vec3.hpp>
#include <mat4x4.hpp>

namespace ENGINE_API rubEngine
{
	class ENGINE_API Camera
	{
	public:

		Camera(const glm::vec3& aPosition = {0.f, 0.f, 0.f}, const glm::vec3& aUpDirection = { 0.f, 1.f, 0.f}, float aNear =  0.1f, float aFar = 50.f);
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

		const float GetYaw() const;
		void SetYaw(float aYaw);

		const float GetPitch() const;
		void SetPitch(float aPitch);

		void SetSize(float aWidth, float aHeight);

		const glm::mat4& GetViewMatrix() const;

		const glm::mat4& GetProjectionMatrix() const;

	protected:
		virtual void RecalculateProjectionMatrix() = 0;

	private:
		void RecalculateViewDirection();
		void RecalculateViewMatrix();

	protected:
		float			mNear;
		float			mFar;

		float			mWidth;
		float			mHeight;

		glm::mat4		mProjectionMatrix;

	private:
		glm::vec3		mPosition;

		glm::vec3		mViewDirection;
		glm::vec3		mUpDirection;
		glm::vec3		mRightDirection;

		float			mYaw;
		float			mPitch;

		glm::mat4		mViewMatrix;
	};
}

#endif

