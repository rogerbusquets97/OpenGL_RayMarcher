#ifndef ENGINE_ECS_ENTITY_HANDLE
#define ENGINE_ECS_ENTITY_HANDLE

#include "Core.h"

namespace Engine
{
	namespace ECS 
	{
		class Entity;
		class ECSManager;

		class ENGINE_API EntityHandle
		{
		public:

			Entity*		mpEntity;
			ECSManager* mpECSManager;
		};
	}
}

#endif