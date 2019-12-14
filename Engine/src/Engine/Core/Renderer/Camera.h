#pragma once
#include <Core.h>
#include <glm.hpp>
#include <Memory/MemoryBuffer.h>

namespace Engine
{
	class ENGINE_API Camera
	{
	public:
		Camera();
		virtual ~Camera();

		glm::mat4 GetViewMatrix();
		glm::mat4 GetProjectionMatrix();
		void ProcessEvents(MemoryBuffer& aData);

	private:
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
		float mZoom;
	};
}

