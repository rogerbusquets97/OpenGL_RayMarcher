#include "ModuleCamera.h"

namespace Engine
{
	ModuleCamera::ModuleCamera(Application* aApplication) : 
		Module("Camera", aApplication),
		mCamera() //TODO read params from config file
	{
	}

	ModuleCamera::~ModuleCamera()
	{
	}

	bool ModuleCamera::Init()
	{
		return true;
	}

	bool ModuleCamera::Update(float aDeltaTime)
	{
		return true;
	}

	bool ModuleCamera::CleanUp()
	{
		return true;
	}

	bool ModuleCamera::Awake()
	{
		return true;
	}

	bool ModuleCamera::PreUpdate(float aDeltaTime)
	{
		return true;
	}

	bool ModuleCamera::PostUpdate(float aDeltaTime)
	{
		return true;
	}

	void ModuleCamera::OnMouseEvent(int aButton, int aAction)
	{

	}

	void ModuleCamera::OnKeyWindowEvent(KeyId aKeyId, KeyAction aKeyAction)
	{
		
	}

}