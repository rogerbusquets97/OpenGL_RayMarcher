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

		Camera(const glm::vec3& aPosition = {0.f, 0.f, 0.f}, const glm::vec3& aVRP = {0.f, 0.f, 0.f}, const glm::vec3& aUp = { 0.f, 1.f, 0.f}, float aNear =  0.1f, float aFar = 50.f);
		~Camera();

		const glm::vec3& GetPosition() const;
		void SetPosition(const glm::vec3& aPosition);

		const glm::vec3& GetVRP() const;
		void SetVRP(const glm::vec3& aVRP);

		const glm::vec3& GetUp() const;
		void SetUp(const glm::vec3& aUp);

		const float GetNear() const;
		void SetNear(float aNear);

		const float GetFar() const;
		void SetFar(float aFar);

		const glm::mat4& GetViewMatrix() const;

		const glm::mat4& GetProjectionMatrix() const;

	private:
		glm::vec3		mPosition;
		glm::vec3		mVRP;
		glm::vec3		mUp;
		float			mNear;
		float			mFar;


	/*private:
		void UpdateVectors();
		void OnKeyPressed(int aKey, int aAction);
		void OnMouseMove(float aXoffset, float aYoffset, bool aConstrainPitch = true);
		void OnMouseScroll(float aYoffset);
	private:
		glm::vec3 mPosition;
		glm::vec3 mFront;
		glm::vec3 mUp;
		glm::vec3 mRight;
		glm::vec3 mWorldUp;

		float mYaw;
		float mPitch;

		float mSpeed;
		float mSensitivity;
		float mZoom;*/
	};
}

#endif

