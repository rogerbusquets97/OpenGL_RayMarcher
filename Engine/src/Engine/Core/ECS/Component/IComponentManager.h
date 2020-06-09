#ifndef ENGINE_ECS_I_COMPONENT_MANAGER
#define ENGINE_ECS_I_COMPONENT_MANAGER

#include "Core.h"

namespace rubEngine
{
	namespace ECS
	{
		class Entity;

		class ENGINE_API IComponentManager
		{
		public:
			IComponentManager() {};
			virtual ~IComponentManager() {};
			IComponentManager(const IComponentManager&) = default;
			IComponentManager& operator=(const IComponentManager&) = default;

			virtual void RemoveComponent(Entity* apEntity) = 0;
		};
	}
}

#endif