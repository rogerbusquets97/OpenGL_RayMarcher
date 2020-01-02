#ifndef ENGINE_ECS_COMPONENT_MANAGER
#define ENGINE_ECS_COMPONENT_MANAGER

#include "Core.h"
#include <array>
#include <unordered_map>
#include "ECS/Entity/Entity.h"

namespace Engine
{
	namespace ECS
	{
		class ENGINE_API IComponentManager
		{
		};

		template<typename TComponentType>
		class ENGINE_API ComponentManager : public IComponentManager
		{
		public:
			
			TComponentType&  GetEntityComponent(Entity aEntityId);

			void AddComponent(Entity aEntityId, TComponentType aComponent);
			
			void RemoveComponent(Entity aEntityId);

		private:
			typedef std::unordered_map<Entity, TComponentType*>		tEntitiesLookUp;

			std::array<TComponentType, 1024>		mComponents;//TODO use custom dynamic allocators? this allocators should be multiple of cache line size somehow to really benefit from ECS
			tEntitiesLookUp					mEntitiesLookUp;
		};
	}
}

#endif
