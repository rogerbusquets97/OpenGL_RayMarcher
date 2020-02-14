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

		void EntityManager::GetEntityComponentsMask(const Entity& aEntity, BitMask& aComponentsMask) const
		{
			tComponentFamilyIds EntityComponentFamilies;
			aEntity.ObtainComponentFamilies(EntityComponentFamilies);
			GetEntityComponentsMask(EntityComponentFamilies, aComponentsMask);
		}

		void EntityManager::GetEntityComponentsMask(const tComponentFamilyIds& aEntityComponentFamilies, BitMask& aComponentsMask) const
		{
			for (tComponentFamilyId ComponentId : aEntityComponentFamilies)
			{
				aComponentsMask.SetBit(ComponentId);
			}
		}

	}
}
