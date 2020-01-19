#include "ECS/Entity/EntityManager.h"
#include "ECS/Entity/Entity.h"

namespace Engine
{
	namespace ECS
	{
		EntityManager::EntityManager()
		{

		}

		std::shared_ptr<Entity> EntityManager::CreateEntity()
		{
			return std::make_shared<Entity>(mNextEntityId++);
		}

		void EntityManager::RemoveEntity()
		{

		}
	}
}
