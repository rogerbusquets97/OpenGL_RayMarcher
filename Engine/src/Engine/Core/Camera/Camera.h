#ifndef ENGINE_CAMERA
#define ENGINE_CAMERA

#include "Core.h"
#include <glm.hpp>

namespace ENGINE_API Engine
{
	class Camera
	{
	public:

		Camera(const glm::vec3& aPosition = {0.f, 0.f, 0.f}, const glm::vec3& aVRP = {0.f, 0.f, 0.f}, const glm::vec3& aUp = { 0.f, 1.f, 0.f}, float aNear =  0.1f, float aFar = 50.f);
		~Camera();

		const glm::vec3& GetPosition();
		void SetPosition(const glm::vec3& aPosition);

		const glm::vec3& GetVRP();
		void SetVRP(const glm::vec3& aVRP);

		const glm::vec3& GetUp();
		void SetUp(const glm::vec3& aUp);

		const float GetNear();
		void SetNear(float aNear);

		const float GetFar();
		void SetFar(float aFar);

		const glm::mat4& GetViewMatrix();

		const glm::mat4& GetProjectionMatrix();

	private:
		glm::vec3		mPosition;
		glm::vec3		mVRP;
		glm::vec3		mUp;
		float			mNear;
		float			mFar;
	};
}

#endif

