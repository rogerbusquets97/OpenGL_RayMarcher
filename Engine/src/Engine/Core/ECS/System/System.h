#ifndef ENGINE_ECS_SYSTEM
#define ENGINE_ECS_SYSTEM

#include "Core.h"
#include "ECS/Entity/Entity.h"
#include <vector>

namespace Engine
{
	namespace ECS
	{
		class ENGINE_API ISystem
		{

		};

		template<typename ...tComponents>
		class ENGINE_API System : public ISystem
		{
		public:

			virtual void PreUpdate(float aDeltaTime) = 0;
			
			virtual void Update(float aDeltaTime) = 0;
			
			virtual void PostUpdate(float aDeltaTime) = 0;

			void AddEntity(Entity& aEntity);
			void RemoveEntity(Entity& aEntity);

		private:
			typedef std::vector<Entity::tEntityId>	tEntitiesContainer;
			tEntitiesContainer		mEntities;
		};
	}
}

#endif
