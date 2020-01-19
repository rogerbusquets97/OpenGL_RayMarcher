#ifndef ENGINE_ECS_ENTITY_MANAGER
#define ENGINE_ECS_ENTITY_MANAGER

#include "Core.h"
#include <memory>

namespace Engine
{
	namespace ECS
	{
		class Entity;

		class ENGINE_API EntityManager
		{
		public:
			EntityManager();

			std::shared_ptr<Entity> CreateEntity();

			void RemoveEntity();

		private:
			unsigned int mNextEntityId;
		};
	}
}

#endif
