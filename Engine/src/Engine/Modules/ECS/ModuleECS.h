#ifndef ENGINE_MODULE_ECS
#define ENGINE_MODULE_ECS

#include "Core.h"
#include "Module.h"
#include "ECS/ECSManager.h"

namespace rubEngine
{
	class ENGINE_API ModuleECS : public Module
	{
	public:
		ModuleECS();
		~ModuleECS();

		virtual bool Awake() override;
		virtual bool Init() override;
		virtual bool CleanUp() override;
		virtual bool PreUpdate(float aDeltaTime) override;
		virtual bool Update(float aDeltaTime) override;
		virtual bool PostUpdate(float aDeltaTime) override;

	private:
		ECS::ECSManager mECSManager;//TODO change this to ECSLayer
	};
}

#endif
