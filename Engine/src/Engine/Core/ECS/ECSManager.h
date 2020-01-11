#ifndef ENGINE_ECS_HANDLER
#define ENGINE_ECS_HANDLER

#include "Core.h"
#include <vector>
#include <memory>

namespace Engine
{
	namespace ECS
	{
		class ISystem;
		class IComponentManager;
		class Entity;
		class Component;

		class ENGINE_API ECSManager
		{
		public:

			typedef std::vector< std::unique_ptr<IComponentManager>>	tComponentManagerContainer;


			Entity* CreateEntity();
			void RemoveEntity(Entity* apEntity);

			void AddComponent(Component* aComponent);
			void RemoveComponent(Component* aComponent);

			void AddSystem(ISystem* apSystem);
			void RemoveSystem(ISystem* apSystem); //really necessary?

			template<typename ...TComponentType>
			void GetEntityComponentManagers(Entity* apEntity, TComponentType&... aComponentManagers);

		private:
			typedef std::vector<std::unique_ptr<ISystem>>				tSystemContainer;
			typedef std::vector< std::unique_ptr<Entity>>				tEntityContainer;

			tSystemContainer				mSystems;
			tComponentManagerContainer		mComponentManagers;
			tEntityContainer				mEntities;
		};
	}
}

#endif