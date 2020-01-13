#include "ModuleECS.h"

namespace Engine
{
	ModuleECS::ModuleECS(Application* aApplication) :
		Module("ECS", aApplication),
		mECSManager()
	{

	}

	ModuleECS::~ModuleECS()
	{

	}

	bool ModuleECS::Awake() 
	{
		return true;

	}

	bool ModuleECS::Init()
	{
		return true;
	}

	bool ModuleECS::CleanUp()
	{
		return true;

	}

	bool ModuleECS::PreUpdate(float aDeltaTime)
	{
		mECSManager.PreUpdate(aDeltaTime);
		return true;
	}

	bool ModuleECS::Update(float aDeltaTime)
	{
		mECSManager.Update(aDeltaTime);
		return true;
	}

	bool ModuleECS::PostUpdate(float aDeltaTime)
	{
		mECSManager.PostUpdate(aDeltaTime);
		return true;
	}
}