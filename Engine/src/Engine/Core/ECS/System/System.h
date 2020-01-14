#ifndef ENGINE_ECS_SYSTEM
#define ENGINE_ECS_SYSTEM

#include "Core.h"
#include <vector>

namespace Engine
{
	namespace ECS
	{
		class ECSManager;
		class Entity;

		class ENGINE_API System
		{
		public:

			System();
			virtual ~System();

			virtual void PreUpdate(float aDeltaTime) = 0;
			virtual void Update(float aDeltaTime) = 0;
			virtual void PostUpdate(float aDeltaTime) = 0;

			void AddEntity(Entity& aEntity);
			void RemoveEntity(Entity& aEntity);

		private:
			typedef std::vector<Entity*>	tEntitiesContainer;

			tEntitiesContainer		mEntities;
			ECSManager*				mECSManager;
			//TODO  system components
		};
	}
}

#endif
