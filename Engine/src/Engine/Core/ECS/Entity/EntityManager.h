#ifndef ENGINE_ECS_ENTITY_MANAGER
#define ENGINE_ECS_ENTITY_MANAGER

#include "Core.h"
#include <memory>
#include "Utilities/BitMask.h"
#include "ECS/ECSCommon.h"

namespace rubEngine
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

			void GetEntityComponentsMask(const Entity& aEntity, BitMask& aComponentsMask) const;
			void GetEntityComponentsMask(const tComponentFamilyIds& aEntityComponentFamilies, BitMask& aComponentsMask) const;

		private:
			unsigned int mNextEntityId;
		};
	}
}

#endif
