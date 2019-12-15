#include "Camera.h"

namespace Engine
{
	Camera::Camera()
	{
	}


	Camera::~Camera()
	{
	}
	glm::mat4 Camera::GetViewMatrix()
	{
		return glm::mat4();
	}
	glm::mat4 Camera::GetProjectionMatrix()
	{
		return glm::mat4();
	}
	void Camera::ProcessEvents(MemoryBuffer & aData)
	{
	}
	void Camera::UpdateVectors()
	{
	}
	void Camera::OnKeyPressed(int aKey, int aAction)
	{
	}
	void Camera::OnMouseMove(float aXoffset, float aYoffset, bool aConstrainPitch)
	{
	}
	void Camera::OnMouseScroll(float aYoffset)
	{
	}
}
